/*
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH, http://www.lantiq.com
 *
 * based on board/tqc/tqm8xx/load_sernum_ethaddr.c
 * (C) Copyright 2000, 2001, 2002
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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

/*#define DEBUG*/
#include <common.h>
#include <net.h>
#include <asm/io.h>
#include <asm/falcon.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>
#include <asm/gpio.h>

#define DEFAULT_MAC { 0xAC, 0x9A, 0x96, 0xFF, 0xFF, 0xFF }

void load_default_ethaddr(void)
{
	u8 ethaddr[6] = DEFAULT_MAC;
	u32 chiploc;

	/* set ethaddr if not yet defined */
	if (getenv("ethaddr") == NULL) {
		chiploc = status_r32(chiploc);
		ethaddr[3] = chiploc>>16 & 0xFF;
		ethaddr[4] = chiploc>>8 & 0xFF;
		ethaddr[5] = chiploc>>0 & 0xFF;

		eth_setenv_enetaddr("ethaddr", ethaddr);
	}
}

void print_chip_info(void)
{
	char buf[32];
	u32 chipid, chipid_partnr, chipid_version;
	u32 config, config_subvers;
	u32 fuse0_f0;
	u32 bootmode = sys1_r32(bmc) & BMC_BM_MASK;
	u32 cause;

	chipid = status_r32(chipid);
	if ((chipid & STATUS_CHIPID_CONST1) != STATUS_CHIPID_CONST1)
		printf("ChipID invalid??? val=0x%08X\n", chipid);
	else {
		chipid_partnr = (chipid & STATUS_CHIPID_PARTNR_MASK)
			>> STATUS_CHIPID_PARTNR_OFFSET;
		chipid_version = (chipid & STATUS_CHIPID_VERSION_MASK)
			>> STATUS_CHIPID_VERSION_OFFSET;
		config = status_r32(config);
		config_subvers = (config & STATUS_CONFIG_SUBVERS_MASK)
			>> STATUS_CONFIG_SUBVERS_OFFSET;
		fuse0_f0 = status_r32(fuse0) & STATUS_FUSE0_F0_MASK;

		puts("Chip:  ");
		if (chipid_partnr != 0x01B8) {
			printf("UNKNOWN Chipid 0x%08X", chipid);
		} else {
			char *type = &buf[0];
			if (is_falcon_d())
				type = "D";
			else if (is_falcon_v())
				type = "V";
			else if (is_falcon_m())
				type = "M";
			else if (is_falcon_s())
				type = "S";
			else
				sprintf(buf, "?(f0=%X)",
					fuse0_f0 >> STATUS_FUSE0_F0_OFFSET);

			printf("FALCON-%s (%c%d%d)\n",
				type, 'A'+(config_subvers>>2),
				chipid_version, (config_subvers & 3)+1);
		}
	}
	printf("Bootmode: 0x%02X\n", bootmode);

	if (is_falcon_chip_a1x())
		cause = sys1_r32(cpu0rs) & 0x03;
	else
		cause = sys1_r32(cpu0rs) & CPU0RS_HWRS_MASK;
	puts("Reset cause: ");
	switch (cause) {
	case CPU0RS_HWRS_POR:
		puts("Power-On Reset\n");
		break;
	case CPU0RS_HWRS_RST:
		puts("RST Pin\n");
		break;
	case CPU0RS_HWRS_WDT:
		if ((boot_reg->magic0 == 0x4C545100) && 
		    (boot_reg->magic1 == 0x0051544C)) {
			puts("Software\n");
		} else
			puts("Watchdog\n");
		break;
	case CPU0RS_HWRS_OLT:
		puts("PLOAM message\n");
		break;
	case CPU0RS_HWRS_SYS1:
		puts("Software via SYS1\n");
		break;
	default:
		puts("Unknown!\n");
		break;
	}
	/* reset magics and reset/nmi/ejtag vectors */
	boot_reg->magic0 = 0;
	boot_reg->magic1 = 0;
	boot_reg->rvec = 0;
	boot_reg->nvec = 0;
	boot_reg->evec = 0;

	printf("CPU Clock: %s MHz\n", strmhz(buf, get_cpuclk()));
}

#define DEFAULT_TEMPMM		0
#define DEFAULT_TBGP		4
#define DEFAULT_VBGP		4
#define DEFAULT_IREFBGP		8
#define DEFAULT_GAINDRIVEDAC	8
#define DEFAULT_GAINBIASDAC	8

#define PRINT_FUSE(f) debug("status %7s 0x%08X\n", #f, f)

/* check and initialize some fuse status registers */
static void falcon_fuse_init(void)
{
	u32 fuse0, fuse1, analog, config, chiploc;
	u32 format;

	/* disable "soft fuse control" (SFC) to read real fuse values */
	status_w32_mask(STATUS_FUSE0_SFC_SEL, 0, fuse0);

	fuse0 = status_r32(fuse0);
	fuse1 = status_r32(fuse1);
	analog = status_r32(analog);
	config = status_r32(config);
	chiploc = status_r32(chiploc);

	format = ((analog & STATUS_ANALOG_FS_MASK) >> STATUS_ANALOG_FS_OFFSET);

	debug("fuse format %d\n", format);
	PRINT_FUSE(fuse0);
	PRINT_FUSE(fuse1);
	PRINT_FUSE(analog);
	PRINT_FUSE(config);
	PRINT_FUSE(chiploc);

	/* activate SFC */
	fuse0 |= STATUS_FUSE0_SFC_SEL;
	if ((fuse0 & STATUS_FUSE0_RCALMM_MASK) == 0)
		fuse0 |= 0x80;
	if ((fuse0 & STATUS_FUSE0_VCALMM400_MASK) == 0)
		fuse0 |= (0x20 << STATUS_FUSE0_VCALMM400_OFFSET);
	if ((fuse0 & STATUS_FUSE0_VCALMM100_MASK) == 0)
		fuse0 |= (0x20 << STATUS_FUSE0_VCALMM100_OFFSET);
	if ((fuse0 & STATUS_FUSE0_VCALMM20_MASK) == 0)
		fuse0 |= (0x20 << STATUS_FUSE0_VCALMM20_OFFSET);

	if ((fuse1 & ~STATUS_FUSE1_F1_MASK) == 0)
		fuse1 |= 0x00000020;

	switch (format) {
	case 0:
		/* no valid values for format "0", set defaults and format "1"*/
		analog = STATUS_ANALOG_FS_FS1;
		analog |= (DEFAULT_GAINBIASDAC <<
					STATUS_ANALOG_GAINBIASDAC_OFFSET);
		analog |= (DEFAULT_GAINDRIVEDAC <<
					STATUS_ANALOG_GAINDRIVEDAC_OFFSET);
		analog |= (DEFAULT_IREFBGP << STATUS_ANALOG_IREFBGP_OFFSET);
		analog |= (DEFAULT_VBGP << STATUS_ANALOG_VBGP_OFFSET);
		analog |= (DEFAULT_TBGP << STATUS_ANALOG_TBGP_OFFSET);
		analog |= (DEFAULT_TEMPMM << STATUS_ANALOG_TEMPMM_OFFSET);
		fuse0 = (fuse0 & ~STATUS_FUSE0_F0_MASK) | 0x04000000;
		break;
	case 1: 
		{
			uint8_t offset_fuse;
			int8_t offset;

			offset_fuse = (fuse1 & STATUS_FUSE1_OFFSET1V0DCDC_MASK)
				>> STATUS_FUSE1_OFFSET1V0DCDC_OFFSET;
			/* let the cpu convert the 5bit signed value */
			offset = (int8_t)(offset_fuse<<3) / 8;

			/* ignore all negative values, set to 0 */
			if (offset < 0)
				fuse1 &= ~STATUS_FUSE1_OFFSET1V0DCDC_MASK;
		}
		break;
	default:
		break;
	}

	debug("\nupdated fuses\n");
	PRINT_FUSE(fuse0);
	PRINT_FUSE(fuse1);
	PRINT_FUSE(analog);
	PRINT_FUSE(config);
	PRINT_FUSE(chiploc);

	status_w32(fuse0, fuse0);
	status_w32(fuse1, fuse1);
	status_w32(analog, analog);
	/*
	 * we also need to write the following registers, even if not modified,
	 * otherwise they have wrong contents with SFC activated (SHA1EN and
	 * AESEN cannot be written, so we will not see the real status here
	 * with SFC, but these hw-blocks are directly connected to the fuses)
	 */
	status_w32(config, config);
	status_w32(chiploc, chiploc);
}

void falcon_early_init_f(void)
{
#ifdef CONFIG_USE_ASC0
	#define ACTS_ASC ACTS_ASC0
#else
	#define ACTS_ASC ACTS_ASC1
#endif
	/* activate some basic hardware modules */
	sys1_hw_activate(ACTS_ASC | ACTS_STATUS | ACTS_EBU);
	falcon_fuse_init();
	if (is_falcon_chip_a1x())
		falcon_dcdc_core_init(1050);
	else
		falcon_dcdc_core_init(1000);
	/*
	 * clear unconditional all pending NMIs,
	 * otherwise the cpu reset will not work
	 */
	sys1_w32(sys1_r32(nmis), nmiclr);
}

void falcon_misc_init_r(void)
{
	long m, n;
	char *s = getenv("dcdc_core_voltage");
	if (s) {
		long voltage = simple_strtoul(s, NULL, 10);
		n = DIV_ROUND(voltage, 1000);
		m = voltage-n*1000L;
		if ((voltage <= 950) || (voltage > 1150)) {
			printf("Invalid value for core voltage %ld.%03ldV\n",
				n, m);
		} else {
			printf("Change core voltage to %ld.%03ldV\n",
				n, m);
			falcon_dcdc_core_set_voltage(voltage);
		}
	}
}

void falcon_extphy_enable(int enable)
{
	gpio_request(3, "phy reset");

	if (enable) {
		gpio_direction_output(3, 0);
		/* enable 25 MHz clock for external Phys */
		sys_eth_w32_mask(SYS_ETH_EXTPHYC_CLKSEL_MASK,
			SYS_ETH_EXTPHYC_CLKEN_EN | SYS_ETH_EXTPHYC_CLKSEL_F25,
			extphyc);
		udelay(10);

		/* remove reset to external Phy module */
		gpio_set_value(3, 1);
	} else {
		/* disable clock output */
		sys_eth_w32_mask(SYS_ETH_EXTPHYC_CLKEN_EN, 0, extphyc);

		/* activate reset to external Phy module */
		gpio_direction_output(3, 0);
	}
}

static int do_extphy( cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	if (argc < 2)
		return cmd_usage(cmdtp);

	if (strcmp(argv[1],"en") >= 0x0) {
		printf("Enable external phy clock, remove reset\n");
		falcon_extphy_enable(1);
	} else if (strcmp(argv[1],"dis") >= 0x0) {
		printf("Disable external phy clock, activate reset\n");
		falcon_extphy_enable(0);
	} else {
		return cmd_usage(cmdtp);
	}
	return 0;
}

U_BOOT_CMD(
	extphy,	2,	0,	do_extphy,
	"external PHY enable (clock and reset)",
	"en[able]/dis[able]"
);
