/*
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH, http://www.lantiq.com
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <malloc.h>
#include <spi.h>

#include <asm/io.h>
#include <asm/arch/hardware.h>

/* Register access macros */

#if 1
#define ebu_readl(reg)				\
	readl(&ebu->reg)
#define ebu_writel(reg,value)			\
	writel((value), &ebu->reg)
#else
static inline u32 ebu_readreg(const char* name, u32 *addr)
{
	u32 val;
	debug("%s > ", name);
	val = readl(addr);
	debug("0x%08X\n", val);
	return val;
}
#define ebu_readl(reg)				\
	ebu_readreg(#reg, &ebu->reg)
static inline void ebu_writereg(const char* name, u32 val, u32 *addr)
{
	debug("%s < 0x%08X\n", name, val);
	writel(val, addr);
}
#define ebu_writel(reg,value)			\
	ebu_writereg(#reg, (value), &ebu->reg)
#endif
#define ebu_maskl(reg,clear,set) ebu_writel(reg,(ebu_readl(reg)& ~(clear))|(set))

struct ebu_spi_slave {
	struct spi_slave slave;	/* must be first!!! */
	u32 sfcmd;	/* for caching of opcode, direction, ... */
};
#define to_ebu_spi_slave(s) container_of(s, struct ebu_spi_slave, slave)

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode)
{
	struct ebu_spi_slave *ebuspi;
	const u32 ebuclk = 100*1000*1000;
	unsigned int i;

	debug("spi_setup_slave: slave %u:%u max_hz %d mode %d\n",
		bus, cs, max_hz, mode);

	if ((bus>0) || (cs>0))
		return NULL;

	ebuspi = malloc(sizeof(struct ebu_spi_slave));
	if (!ebuspi)
		return NULL;

	ebuspi->slave.bus = bus;
	ebuspi->slave.cs = cs;

	if (ebuclk < max_hz) {
		/* set EBU clock to 100 MHz */
		sys1_w32_mask(0, EBUCC_EBUDIV_SELF100, ebucc);
		i = 1; /* divider */
	} else {
		/* set EBU clock to 50 MHz */
		sys1_w32_mask(EBUCC_EBUDIV_SELF100, 0, ebucc);

		/* search for suitable divider */
		for (i=1; i<7; i++) {
			if (ebuclk/i <= max_hz)
				break;
		}
	}
	/* setup period of serial clock */
	ebu_maskl(sftime,
		SFTIME_SCKF_POS_MASK | SFTIME_SCKR_POS_MASK | SFTIME_SCK_PER_MASK,
		(i<<SFTIME_SCKR_POS_OFFSET) | (i<<(SFTIME_SCK_PER_OFFSET+1)));

	/* set some bits of unused_wd, to not trigger HOLD/WP signals on non QUAD flashes */
	ebu_writel(sfio, (SFIO_UNUSED_WD_MASK & (0x8|0x4)));

	return &ebuspi->slave;
}

void spi_free_slave(struct spi_slave *slave)
{
	free(slave);
}

int spi_claim_bus(struct spi_slave *slave)
{
	struct ebu_spi_slave *ebuspi = to_ebu_spi_slave(slave);
	ebu_writel(busrcon0, BUSRCON0_AGEN_SERIAL_FLASH | BUSRCON0_PORTW_8_BIT_MUX);
	ebu_writel(buswcon0, BUSWCON0_AGEN_SERIAL_FLASH);
	/* set address wrap around to maximum for 24-bit addresses */
	ebu_maskl(sfcon,
		SFCON_DEV_SIZE_MASK,
		SFCON_DEV_SIZE_A23_0);
	ebuspi->sfcmd = 0;
	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
}

enum states_e {
	state_init,
	state_command_prepare,
	state_write,
	state_read,
	state_disable_cs,
	state_end
};

int spi_xfer(struct spi_slave *slave, unsigned int bitlen, const void *dout,
		void *din, unsigned long flags)
{
	struct ebu_spi_slave *ebuspi = to_ebu_spi_slave(slave);
	const u8 *txp = dout;
	u8 *rxp = din;
	unsigned int bytelen = ((bitlen + 7) / 8);
	unsigned int len, alen, dumlen;
	u32 val;
	enum states_e state = state_init;

#if 0
	debug("spi_xfer: slave %u:%u dout %p din %p bytelen %d/0x%X %s%s\n",
		ebuspi->slave.bus, ebuspi->slave.cs, dout, din, bytelen, bytelen,
		(flags & SPI_XFER_BEGIN)?" BEGIN":"", (flags & SPI_XFER_END)?" END":"");
#endif

	do {
		switch (state) {
		case state_init: /* detect phase of upper layer sequence */
		{
			/* initial write ? */
			if (flags & SPI_XFER_BEGIN) {
				if (!txp) {
					printf("SPI Error: BEGIN without tx data!\n");
					return -1;
				}
				/*
				 * Prepare the parts of the sfcmd register, which should not
				 * change during a sequence!
				 * Only exception are the length fields, especially alen and dumlen.
				 */
				ebuspi->sfcmd = ((ebuspi->slave.cs << SFCMD_CS_OFFSET) & SFCMD_CS_MASK);
				ebuspi->sfcmd |= SFCMD_KEEP_CS_KEEP_SELECTED;
				ebuspi->sfcmd |= *txp;
				txp++;
				bytelen--;
				if (bytelen) {
					/* more data: maybe address and/or dummy */
					state = state_command_prepare;
					break;
				} else {
					debug("SPI: write cmd %02X\n",
						ebuspi->sfcmd & SFCMD_OPC_MASK);
				}
			}
			/* continued write ? */
			if (txp && bytelen) {
				state = state_write;
				break;
			}
			/* read data? */
			if (rxp && bytelen) {
				state = state_read;
				break;
			}
			/* end of sequence? */
			if (flags & SPI_XFER_END)
				state = state_disable_cs;
			else
				state = state_end;
			break;
		}
		case state_command_prepare: /* collect tx data for address and dummy phase */
		{
			/* txp is valid, already checked */
			val = 0;
			alen = 0;
			dumlen = 0;
			while (bytelen > 0) {
				if (alen < 3) {
					val = (val<<8)|(*txp++);
					alen++;
				} else if ((dumlen < 15) && (*txp == 0)) {
					/*
					 * assume dummy bytes are set to 0
					 * from upper layer
					 */
					dumlen++;
					txp++;
				} else
					break;
				bytelen--;
			}
			ebuspi->sfcmd &= ~(SFCMD_ALEN_MASK | SFCMD_DUMLEN_MASK);
			ebuspi->sfcmd |= (alen << SFCMD_ALEN_OFFSET) |
					 (dumlen << SFCMD_DUMLEN_OFFSET);
			if (alen > 0)
				ebu_writel(sfaddr, val);
			debug("SPI: write cmd %02X, alen=%d (addr=%06X) dumlen=%d\n",
				ebuspi->sfcmd & SFCMD_OPC_MASK, alen, val, dumlen);
			if (bytelen > 0) {
				/* continue with write */
				state = state_write;
			} else if (flags & SPI_XFER_END) {
				/* end of sequence? */
				state = state_disable_cs;
			} else {
				/* go to end and expect another call (read or write) */
				state = state_end;
			}
			break;
		}
		case state_write:
		{
			/* txp still valid */
			ebuspi->sfcmd |= SFCMD_DIR_WRITE;
			len = 0;
			val = 0;
			do {
				if (bytelen--)
					val |= (*txp++)<<(8*len++);
				if ((flags & SPI_XFER_END) && (bytelen==0)) {
					//debug("disable CS\n");
					ebuspi->sfcmd &= ~SFCMD_KEEP_CS_KEEP_SELECTED;
				}
				if ((len==4) || (bytelen==0)) {
					ebu_writel(sfdata, val);
					ebu_writel(sfcmd, ebuspi->sfcmd | (len<<SFCMD_DLEN_OFFSET));
					len = 0;
					val = 0;
					ebuspi->sfcmd &= ~(SFCMD_ALEN_MASK | SFCMD_DUMLEN_MASK);
				}
			} while (bytelen);
			state = state_end;
			break;
		}
		case state_read:
		{
			/* read data */
			ebuspi->sfcmd &= ~SFCMD_DIR_WRITE;
			do {
				if ((flags & SPI_XFER_END) && (bytelen<=4)) {
					//debug("disable CS\n");
					ebuspi->sfcmd &= ~SFCMD_KEEP_CS_KEEP_SELECTED;
				}
				len = (bytelen>4) ? 4 : bytelen;
				bytelen -= len;
				ebu_writel(sfcmd, ebuspi->sfcmd | (len<<SFCMD_DLEN_OFFSET));
				ebuspi->sfcmd &= ~(SFCMD_ALEN_MASK | SFCMD_DUMLEN_MASK);
				do {
					val = ebu_readl(sfstat);
					if (val & SFSTAT_CMD_ERR) {
						/* reset error status */
						debug("SFSTAT: CMD_ERR (%x)\n", val);
						ebu_writel(sfstat, SFSTAT_CMD_ERR);
						return -1;
					}
				} while (val & SFSTAT_CMD_PEND);
				val = ebu_readl(sfdata);
				do {
					*rxp = (val & 0xFF);
					rxp++;
					val >>= 8;
					len--;
				} while (len);
			} while (bytelen);
			state = state_end;
			break;
		}
		case state_disable_cs:
		{
			//debug("disable CS\n");
			ebuspi->sfcmd &= ~SFCMD_KEEP_CS_KEEP_SELECTED;
			ebu_writel(sfcmd, ebuspi->sfcmd | (0<<SFCMD_DLEN_OFFSET));
			val = ebu_readl(sfstat);
			if (val & SFSTAT_CMD_ERR) {
				/* reset error status */
				printf("SFSTAT: CMD_ERR (%x)\n", val);
				ebu_writel(sfstat, SFSTAT_CMD_ERR);
				return -1;
			}
			state = state_end;
			break;
		}
		case state_end:
			break;
		}
	} while (state != state_end);

	return 0;
}
