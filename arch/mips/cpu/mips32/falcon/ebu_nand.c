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
#include <config.h>
#include <nand.h>

#include <asm/io.h>
#include <asm/arch/hardware.h>

/* Register access macros */
#define ebu_readl(reg)				\
	readl(&ebu->reg)
#define ebu_writel(reg,value)			\
	writel((value), &ebu->reg)

/* address lines used for NAND control signals */
#define NAND_ADDR_ALE		(1<<16)
#define NAND_ADDR_CLE		(1<<17)

/*
 *	hardware specific access to control-lines
 */
static void falcon_hwcontrol(struct mtd_info *mtd,
				int cmd, unsigned int ctrl)
{
	struct nand_chip *this = mtd->priv;

	if (ctrl & NAND_CTRL_CHANGE) {
		ulong IO_ADDR_W = (ulong) this->IO_ADDR_W;
		IO_ADDR_W &= ~(NAND_ADDR_ALE | NAND_ADDR_CLE);

		if (ctrl & NAND_CLE)
			IO_ADDR_W |= NAND_ADDR_CLE;
		if (ctrl & NAND_ALE)
			IO_ADDR_W |= NAND_ADDR_ALE;

		this->IO_ADDR_W = (void *) IO_ADDR_W;
	}

	if (cmd != NAND_CMD_NONE)
		writeb(cmd, this->IO_ADDR_W);
}

static int falcon_nand_ready(struct mtd_info *mtd)
{
	return (((ebu_readl(modcon) & (MODCON_STS|MODCON_STSEDGE)) ==
		(MODCON_STS|MODCON_STSEDGE)));
}

int falcon_nand_init(struct nand_chip *nand)
{
	/* set EBU (cs 0) to NAND mode */
	ebu_writel(busrcon0,
		BUSRCON0_AGEN_NAND_FLASH |
		BUSRCON0_PORTW_8_BIT_MUX |
		BUSRCON1_NANDAMAP_NAND_A17_16);
	ebu_writel(buswcon0,
		BUSWCON0_AGEN_NAND_FLASH |
		BUSWCON1_NANDAMAP_NAND_A17_16);

	/* set EBU clock to 100 MHz */
	sys1_w32_mask(0, EBUCC_EBUDIV_SELF100, ebucc);
	/* FIXME: optimize these timings: */
/*	const u32
		addrc = 7,
		adholc = 7,
		cmddelay = 7,
		extdata = (BUSRP0_EXTDATA_FOUR >> BUSRP0_EXTDATA_OFFSET),
		extclock = (BUSRP0_EXTCLOCK_ONE_TO_THREE >> BUSRP0_EXTCLOCK_OFFSET),
		datac = 7,
		waitrdc = 7,
		waitwdc = 7,
		recovc = 3,
		dtacs = 7;

	ebu_writel(busrp0,
		((addrc << BUSRP0_ADDRC_OFFSET) & BUSRP0_ADDRC_MASK) |
		((adholc << BUSRP0_ADHOLC_OFFSET) & BUSRP0_ADHOLC_MASK) |
		((cmddelay << BUSRP0_CMDDELAY_OFFSET) & BUSRP0_CMDDELAY_MASK) |
		((extdata << BUSRP0_EXTDATA_OFFSET) & BUSRP0_EXTDATA_MASK) |
		((extclock << BUSRP0_EXTCLOCK_OFFSET) & BUSRP0_EXTCLOCK_MASK) |
		((datac << BUSRP0_DATAC_OFFSET) & BUSRP0_DATAC_MASK) |
		((waitrdc << BUSRP0_WAITRDC_OFFSET) & BUSRP0_WAITRDC_MASK) |
		((recovc << BUSRP0_RECOVC_OFFSET) & BUSRP0_RECOVC_MASK) |
		((dtacs << BUSRP0_DTACS_OFFSET) & BUSRP0_DTACS_MASK) );
	ebu_writel(buswp0,
		((addrc << BUSWP0_ADDRC_OFFSET) & BUSWP0_ADDRC_MASK) |
		((adholc << BUSWP0_ADHOLC_OFFSET) & BUSWP0_ADHOLC_MASK) |
		((cmddelay << BUSWP0_CMDDELAY_OFFSET) & BUSWP0_CMDDELAY_MASK) |
		((extdata << BUSWP0_EXTDATA_OFFSET) & BUSWP0_EXTDATA_MASK) |
		((extclock << BUSWP0_EXTCLOCK_OFFSET) & BUSWP0_EXTCLOCK_MASK) |
		((datac << BUSWP0_DATAC_OFFSET) & BUSWP0_DATAC_MASK) |
		((waitwdc << BUSWP0_WAITWDC_OFFSET) & BUSWP0_WAITWDC_MASK) |
		((recovc << BUSWP0_RECOVC_OFFSET) & BUSWP0_RECOVC_MASK) |
		((dtacs << BUSWP0_DTACS_OFFSET) & BUSWP0_DTACS_MASK) );
*/
	/* Set address of hardware control function */
	nand->cmd_ctrl = falcon_hwcontrol;
	nand->dev_ready = falcon_nand_ready;
	nand->options = NAND_USE_FLASH_BBT;
	nand->ecc.mode = NAND_ECC_SOFT;

	/* Return happy */
	return 0;
}

/*
 * Main initialization routine
 */
int board_nand_init(struct nand_chip *nand)
{
	return falcon_nand_init(nand);
}
