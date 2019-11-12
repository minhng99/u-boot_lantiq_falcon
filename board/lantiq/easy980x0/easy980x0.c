/*
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH, http://www.lantiq.com
 *
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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
#include <netdev.h>
#include <asm/addrspace.h>
#include <asm/reboot.h>
#include <asm/io.h>
#include <asm/falcon.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>
#include <asm/arch/net.h>
#if defined(CONFIG_CMD_HTTPD)
#include <httpd.h>
#endif

struct easy98000_reg_cpld {
	u16 cmdreg1;		/* 0x1 */
	u16 cmdreg0;		/* 0x0 */
	u16 idreg0;		/* 0x3 */
	u16 resreg;		/* 0x2 */
	u16 intreg;		/* 0x5 */
	u16 idreg1;		/* 0x4 */
	u16 ledreg;		/* 0x7 */
	u16 pcmconconfig;	/* 0x6 */
	u16 res0;		/* 0x9 */
	u16 ethledreg;		/* 0x8 */
	u16 res1[4];		/* 0xa-0xd */
	u16 cpld1v;		/* 0xf */
	u16 cpld2v;		/* 0xe */
};
static struct easy98000_reg_cpld * const cpld = (struct easy98000_reg_cpld *)(KSEG1 | 0x17c00000);
#define cpld_r8(reg)	\
		(readw(&cpld->reg) & 0xFF)
#define cpld_w8(val, reg)	\
		writew((val) & 0xFF, &cpld->reg)
#define cpld_w8_mask(clear, set, reg)	\
		cpld_w8((cpld_r8(reg) & ~(clear)) | (set), reg)

#define XMK_STR(x)	#x
#define MK_STR(x)	XMK_STR(x)

DECLARE_GLOBAL_DATA_PTR;

static int dm9000_found;
/* as default, use configured net port mask */
static unsigned int falcon_net_mask = CONFIG_FALCON_NET_PORT_MASK;

static int check_for_cpld(void)
{
	int ret = 0;
#ifdef CONFIG_EASY980X0
	u8 cmdreg1 = cpld_r8(cmdreg1);
	cpld_w8(7, cmdreg1);

	if ( (cpld_r8(cmdreg1) == 7) &&
	     (cpld_r8(cpld1v) < 20) &&
	     (cpld_r8(cpld2v) < 10) ) {
		/* cpld available */
		ret = 1;
	}

	/* restore reg val */
	cpld_w8(cmdreg1, cmdreg1);
#endif
	return ret;
}

phys_size_t initdram(int board_type)
{
#ifdef CONFIG_SYS_IN_INTERNAL_RAM
	puts("(internal) ");
	return CONFIG_SYS_MAX_INTERNAL_RAM;
#else
	return falcon_ddr_init();
#endif /* CONFIG_SYS_IN_INTERNAL_RAM */
}

int checkboard (void)
{
	char buf[64];
	int i = getenv_f("serial#", buf, sizeof(buf));

	puts ("Board: " MK_STR(BOARD_NAME_LINUX));
	if (i > 0) {
		puts(", serial# ");
		puts(buf);
	}
	putc('\n');

	print_chip_info();

	if (check_for_cpld()) {
		printf("CPLD1: V%d\n", cpld_r8(cpld1v));
		printf("CPLD2: V%d\n", cpld_r8(cpld2v));
	}

	return 0;
}

int board_early_init_f(void)
{
	/* activate some basic hardware modules */
	falcon_early_init_f();

	if (check_for_cpld()) {
#ifdef CONFIG_FLASH_CFI_DRIVER
		/* NOR flash based config */
		cpld_w8(0x01, cmdreg1);
#elif defined (CONFIG_SPI_FLASH)
		/* SPI flash based config */
		cpld_w8(0x04, cmdreg1);
#elif defined (CONFIG_NAND)
		/* NAND flash based config */
		cpld_w8(0x02, cmdreg1);
#else
		/* "no flash" config */
#endif
	}

	return 0;
}

int misc_init_r(void)
{
	u8 addon_id;
	char *s = NULL;
	int need_1V5 = 0;

	load_default_ethaddr();

	if (check_for_cpld()) {
		addon_id = cpld_r8(idreg0) & 0xF;
		switch (addon_id) {
		case 0xF: /* nothing connected */
			break;
		case 1:
			puts("EBU:   Ethernet Controller module (dm9000) connected\n");
			dm9000_found = 1;
			break;
		default:
			printf("EBU:   unknown module (EBU_ID=0x%02X) found\n", addon_id);
			break;
		}
		addon_id = cpld_r8(idreg1) & 0xF;
		falcon_net_mask = FALCON_NET_PORT_MASK_GPHY;
		switch (addon_id) {
		case 0xF:
			s = "no module";
			break;
		case 0x1:
			s = "RGMII module";
			falcon_net_mask |= FALCON_NET_PORT_MASK_RGMII;
			break;
		case 0x4:
			s = "GMII MAC Mode (XWAY TANTOS-3G)";
			need_1V5 = 1;
			falcon_net_mask |= FALCON_NET_PORT_MASK_GMII;
			break;
		case 0x5:
			s = "MII MAC Mode (XWAY TANTOS-3G)";
			need_1V5 = 1;
			falcon_net_mask |= FALCON_NET_PORT_MASK_MII;
			break;
		case 0x6:
			s = "TMII MAC Mode (XWAY TANTOS-3G)";
			need_1V5 = 1;
			falcon_net_mask |= FALCON_NET_PORT_MASK_MII;
			break;
		case 0x8:
			s = "GMII PHY module";
			falcon_net_mask |= FALCON_NET_PORT_MASK_GMII_MAC;
			break;
		case 0x9:
			s = "MII PHY module";
			falcon_net_mask |= FALCON_NET_PORT_MASK_MII_MAC;
			break;
		case 0xA:
			s = "RMII PHY module";
			falcon_net_mask |= FALCON_NET_PORT_MASK_MII_MAC;
			break;
		default:
			s = NULL;
			break;
		}
		if (addon_id != 0xF) {
			if (s)
				printf("xMII:  %s connected\n", s);
			else
				printf("xMII:  unknown module (xMII_ID=0x%X) found\n", addon_id);
		}

		addon_id = cpld_r8(idreg1)>>4 & 0xF;
		switch (addon_id) {
		case 0xF:
			s = "no module";
			break;
		case 0x1:
			s = "SGMII module";
			falcon_net_mask |= FALCON_NET_PORT_MASK_SGMII;
			break;
		default:
			s = NULL;
			break;
		}
		/*if (addon_id != 0xF) */{
			if (s)
				printf("SGMII: %s connected\n", s);
			else
				printf("SGMII: unknown module (SGMII_ID=0x%X) found\n", addon_id);
		}

		if (need_1V5) {
			/* enable 1.5 V */
			sys1_w32_mask (INFRAC_LIN1V5EN | INFRAC_LIN1V5C_MASK,
				INFRAC_LIN1V5EN_EN | (3 << INFRAC_LIN1V5C_OFFSET),
				infrac);
		}
	}

	/* misc settings on SoC level */
	falcon_misc_init_r();

#ifndef CONFIG_SYS_NO_DDR_INIT

#ifdef CONFIG_SYS_IN_INTERNAL_RAM
	/* we are running from internal ram and delay ddr init to this point */
	puts ("DDR:  ");
	/* size of external DDR memory in bytes */
#ifdef DDR_STATIC_INIT
	gd->bd->bi_memsize = falcon_ddr_static_init();
#else
	gd->bd->bi_memsize = falcon_ddr_init();
#endif
	/* start of external DDR memory */
	gd->bd->bi_memstart = CONFIG_SYS_DDR_BASE;
	print_size (gd->bd->bi_memsize, "\n");
#endif /* CONFIG_SYS_IN_INTERNAL_RAM */

#endif /* CONFIG_SYS_NO_DDR_INIT */

#if defined(CONFIG_STATUS_LED) && defined(STATUS_LED_BOOT)
	status_led_set(STATUS_LED_BOOT, STATUS_LED_BLINKING);
#endif

	return 0;
}

int board_eth_init(bd_t *bis)
{
	int ret = 0;
#if defined(CONFIG_FALCON_ETH)
	ret += falcon_net_register(falcon_net_mask);

	if (check_for_cpld()) {
		/* remove reset from SGMII module
		   after clock-out is active! */
		if (cpld_r8(cpld1v) < 9)
			cpld_w8_mask(0, 0x40, resreg);
		else
			cpld_w8_mask(0x40, 0, resreg);
	}
#endif
#ifdef CONFIG_DRIVER_DM9000
	if (dm9000_found) {
		ret += dm9000_initialize(bis);
		/* always enable on eval-board without further settings */
		falcon_extphy_enable(1);
	}
#endif
	return ret;
}

#ifdef CONFIG_SHOW_BOOT_PROGRESS
# if defined(STATUS_LED_BOOT)
static void set_all_led(int state)
{
	int i;
	for (i=0; i<4; i++) {
		status_led_set (i, state);
	}
}
#endif

void show_boot_progress (int status)
{
	debug("boot_progress: %i\n", status);
#if defined(CONFIG_STATUS_LED)
# if defined(STATUS_LED_BOOT)
	unsigned int i;
	switch (status) {
	case 15: /* before jumping to OS */
		status_led_set (STATUS_LED_BOOT, STATUS_LED_ON);
		break;
	case 70: /* (automatic) httpd start */
		/* activate all LEDs */
		set_all_led (STATUS_LED_ON);
		break;
	case -70: /* http upgrade failed */
		/* blink all LEDs */
		for (i=0; i<20; i++) {
			set_all_led (STATUS_LED_ON);
			udelay(250000);
			set_all_led (STATUS_LED_OFF);
			udelay(250000);
		}
		break;
	case 71: /* http upgrade success */
		set_all_led (STATUS_LED_OFF);
		break;
	default:
		break;
	}
# endif	/* STATUS_LED_BOOT */
#endif /* CONFIG_STATUS_LED */
}
#endif /* CONFIG_SHOW_BOOT_PROGRESS */

#if defined(CONFIG_CMD_HTTPD)
int do_http_upgrade(const unsigned char *data, const ulong size)
{
	char buf[128];

	if (getenv ("ram_addr") == NULL)
		return -1;
#if defined(CONFIG_NAND) || defined(CONFIG_SPI_FLASH)
	if (getenv ("kernel_offs") == NULL)
		return -1;
#else
	if (getenv ("kernel_addr") == NULL)
		return -1;
#endif
	/* check the image */
	if (run_command("imi ${ram_addr}", 0) < 0)
		return -1;

	/* write the image to the flash */
	puts("http upgrade ...\n");

#if defined(CONFIG_NAND)
	sprintf(buf, "nand erase.spread ${kernel_offs} 0x%lx;"
		"nand write ${ram_addr} ${kernel_offs} 0x%lx", size, size);
#elif defined(CONFIG_SPI_FLASH)
	sprintf(buf,
		"sf probe 0;"
		"sf erase ${kernel_offs} 0x%lx;"
		"sf write ${ram_addr} ${kernel_offs} 0x%lx", size, size);
#else
	sprintf(buf,
		"era ${kernel_addr} +0x%lx;"
		"cp.b ${ram_addr} ${kernel_addr} 0x%lx", size, size);
#endif

	return run_command(buf, 0) < 0;
}

int do_http_progress(const int state)
{
	/* toggle LED's here */
	switch (state) {
	case HTTP_PROGRESS_START:
		puts("http start\n");
		break;
	case HTTP_PROGRESS_TIMEOUT:
		puts(".");
		break;
	case HTTP_PROGRESS_UPLOAD_READY:
		puts("http upload ready\n");
		break;
	case HTTP_PROGRESS_UGRADE_READY:
		puts("http upgrade ready\n");
		show_boot_progress(71);
		break;
	case HTTP_PROGRESS_UGRADE_FAILED:
		puts("http upgrade failed\n");
		show_boot_progress(-70);
		break;
	}
	return 0;
}

unsigned long do_http_tmp_address(void)
{
	char *s = getenv ("ram_addr");
	if (s) {
		ulong tmp = simple_strtoul (s, NULL, 16);
		return tmp;
	}
	return 0 /*0x80a00000*/;
}

#endif
