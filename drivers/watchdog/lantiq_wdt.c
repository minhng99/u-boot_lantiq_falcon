/*
 * [origin: Linux kernel 3.0, drivers/watchdog/lantiq_wdt.c]
 *
 * Watchdog driver for Infineon/Lantiq MIPS processors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Copyright (C) 2008 John Crispin <blogic@openwrt.org>
 * Based on EP93xx wdt driver
 */

#include <common.h>
#include <watchdog.h>
#include <asm/io.h>
#include <command.h>

#define wdt_writel(value,reg)	writel((value), &wdt->reg)

/* Section 3.4 of the datasheet
 * The password sequence protects the WDT control register from unintended
 * write actions, which might cause malfunction of the WDT.
 *
 * essentially the following two magic passwords need to be written to allow
 * IO access to the WDT core
 */
#define LTQ_WDT_PW1		0x00BE0000
#define LTQ_WDT_PW2		0x00DC0000

#ifndef WDT_REG_BASE
#define WDT_REG_BASE		(KSEG1 | 0x1F8803F0)
#endif

#define LTQ_WDT_SR_EN		(0x1 << 31)	/* enable bit */
#define LTQ_WDT_SR_DSEN		(0x1 << 30)	/* debug suspend enable bit */
#define LTQ_WDT_SR_PWL		(0x3 << 26)	/* set prewarning limit to 1/16 */
#define LTQ_WDT_SR_CLKDIV	(0x3 << 24)	/* turn on clock and set */
						/* divider to 0x40000 */
#define LTQ_WDT_DIVIDER		0x40000
#define LTQ_MAX_TIMEOUT		((1 << 16) - 1)	/* the reload field is 16 bit */

/** WDT register file */
typedef struct reg_wdt_s
{
	/** Watchdog Timer Control Register */
	unsigned int cr; /* 0x00000000 */
	/** Reserved */
	unsigned int res_0; /* 0x00000004 */
	/** Watchdog Timer Status Register */
	unsigned int sr; /* 0x00000008 */
	/** Reserved */
	unsigned int res_1; /* 0x0000000C */
} reg_wdt_t;

static reg_wdt_t * const wdt = (reg_wdt_t *)CKSEG1ADDR(WDT_REG_BASE);
static int wdt_timeout = 30;
static int wdt_disabled = 1; /* disabled per default! */

static int lantiq_wdt_enable(unsigned int timeout)
{
	u32 clk_rate;
	u32 new_timeout;

	if (wdt_disabled)
		return 0;

	clk_rate = get_bus_freq(0) * 2; // fixme
	new_timeout = timeout *
		(clk_rate / LTQ_WDT_DIVIDER);
	if (new_timeout > LTQ_MAX_TIMEOUT)
		new_timeout = LTQ_MAX_TIMEOUT;

	/* write the first password magic */
	wdt_writel(LTQ_WDT_PW1, cr);
	/* write the second magic plus the configuration and new timeout */
	wdt_writel(LTQ_WDT_SR_EN | LTQ_WDT_SR_DSEN | LTQ_WDT_SR_PWL |
		   LTQ_WDT_SR_CLKDIV | LTQ_WDT_PW2 | new_timeout, cr);
	return 0;
}

void hw_watchdog_reset(void)
{
	lantiq_wdt_enable(wdt_timeout);
}

static int do_wdoff(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	/* write the first password magic */
	wdt_writel(LTQ_WDT_PW1, cr);
	/*
	 * write the second password magic with no config
	 * this turns the watchdog off
	 */
	wdt_writel(LTQ_WDT_PW2, cr);
	wdt_disabled = 1;
	return 0;
}

U_BOOT_CMD(
	wdoff,	1,	0,	do_wdoff,
	"switch watchdog off", ""
);

static int do_wdtime(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int new_timeout;
	if (argc != 2)
		return cmd_usage(cmdtp);

	new_timeout = simple_strtol(argv[1], NULL, 10);
/*	if (new_timeout < 3) {
		printf("new timeout too small!\n");
		return 1;
	}
*/
	wdt_timeout = new_timeout;
	wdt_disabled = 0;
	return 0;
}

U_BOOT_CMD(
	wdtime,	2,	0,	do_wdtime,
	"set watchdog timeout",
	"N\n"
	"    - set watchdog timeout to N seconds and enable again (N is _decimal_ !!!)"
);


static int do_wdtest(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	/* endless loop to trigger watchdog */
	for (;;) {
	}
	return 0;
}

U_BOOT_CMD(
	wdtest,	1,	0,	do_wdtest,
	"watchdog test (endless loop!)", ""
);
