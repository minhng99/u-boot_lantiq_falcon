/*
 * (C) Copyright 2011
 * Lantiq Deutschland GmbH, http://www.lantiq.com
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
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>

#define WDT_PW1			0x00BE0000
#define WDT_PW2			0x00DC0000
#define WDT_REG_BASE		(KSEG1 | 0x1F8803F0)

/**
 * Trigger the Soft-Reset of the CPU
 */
void _machine_restart(void)
{
	/* write magic to signal a valid restart */
	writel(0x4C545100, &boot_reg->magic0); /* 'LTQ\0' */
	writel(0x0051544C, &boot_reg->magic1); /* '\0QTL' */
	writel(0, &boot_reg->rvec); /* reset Bootreg RVEC */

	/* reset via watchdog timer, to ensure reset of all hardware components */
	writel(WDT_PW1, WDT_REG_BASE);
	writel(WDT_PW2 |
		(0x3 << 26) | /* PWL */
		(0x1 << 24) | /* CLKDIV */
		(0x1 << 31) | /* enable */
		(1), /* reload */
		WDT_REG_BASE);
	for(;;)
		__asm__ volatile ("nop");
}

/**
 * Activate the selected module(s)
 * Enables the clock of the module and activates the module itself.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS1.ACT
 * \return void
 */
void sys1_hw_activate(u32 mask)
{
	sys1_w32(mask, clken);
	sys1_w32(mask, act);

	while ( (sys1_r32(acts) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Deactivate the selected module(s)
 * Disables the clock of the module and deactivates the module itself.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS1.DEACT
 * \return void
 */
void sys1_hw_deactivate(u32 mask)
{
	sys1_w32(mask, clkclr);
	sys1_w32(mask, deact);

	while ( (sys1_r32(acts) & mask) != 0) {
		/*NOP;*/
	};
}

/**
 * Clock enable for the selected module(s)
 * Enables the clock of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS1.CLKEN
 * \return void
 */
void sys1_hw_clk_enable(u32 mask)
{
	sys1_w32(mask, clken);

	while ( (sys1_r32(clks) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Clock disable for the selected module(s)
 * disables the clock of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS1.CLKCLR
 * \return void
 */
void sys1_hw_clk_disable(u32 mask)
{
	sys1_w32(mask, clkclr);

	while ( (sys1_r32(clks) & mask) != 0) {
		/*NOP;*/
	};
}

/**
 * Reboots the selected module(s)
 * Triggers the reboot of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS1.RBT
 * \return void
 */
void sys1_hw_activate_or_reboot(u32 mask)
{
	u32 acts = sys1_r32(acts);
	/* is not already active? */
	if ((~acts & mask) != 0)
		sys1_hw_activate(~acts & mask);
	sys1_w32(acts & mask, rbt);
	while ( (sys1_r32(acts) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Activate the selected module(s)
 * Enables the clock of the module and activates the module itself.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_ETH.ACT
 * \return void
 */
void sys_eth_hw_activate(u32 mask)
{
	sys_eth_w32(mask, clken);
	sys_eth_w32(mask, act);

	while ( (sys_eth_r32(acts) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Deactivate the selected module(s)
 * Disables the clock of the module and deactivates the module itself.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_ETH.DEACT
 * \return void
 */
void sys_eth_hw_deactivate(u32 mask)
{
	sys_eth_w32(mask, clkclr);
	sys_eth_w32(mask, deact);

	while ( (sys_eth_r32(acts) & mask) != 0) {
		/*NOP;*/
	};
}

/**
 * Clock enable for the selected module(s)
 * Enables the clock of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_ETH.CLKEN
 * \return void
 */
void sys_eth_hw_clk_enable(u32 mask)
{
	sys_eth_w32(mask, clken);

	while ( (sys_eth_r32(clks) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Clock disable for the selected module(s)
 * disables the clock of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_ETH.CLKCLR
 * \return void
 */
void sys_eth_hw_clk_disable(u32 mask)
{
	sys_eth_w32(mask, clkclr);

	while ( (sys_eth_r32(clks) & mask) != 0) {
		/*NOP;*/
	};
}

/**
 * Reboots the selected module(s)
 * Triggers the reboot of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_ETH.RBT
 * \return void
 */
void sys_eth_hw_activate_or_reboot(u32 mask)
{
	u32 acts = sys_eth_r32(acts);
	/* is not already active? */
	if ((~acts & mask) != 0)
		sys_eth_hw_activate(~acts & mask);
	sys_eth_w32(acts & mask, rbt);
	while ( (sys_eth_r32(acts) & mask) != mask) {
		/*NOP;*/
	};
}

static int gpe_clk_is_enabled(void)
{
	u32 rd_data;

	rd_data = sys1_r32(infrac);
	if (rd_data & (1<<(INFRAC_GP_OFFSET+1)))
		/* clock already active, no need to change here*/
		return 1;
	return 0;
}

static void enable_gpe_clk(void)
{
	u32 aeFreq;
	u32 rd_data;
	u32 rd_data_to_keep;
	int i;

	if (gpe_clk_is_enabled())
		/* clock already active, no need to change here */
		return;

	aeFreq = (status_r32(config) & STATUS_CONFIG_GPEFREQ_MASK) >> STATUS_CONFIG_GPEFREQ_OFFSET;
	if (aeFreq == 0)
		aeFreq = 1; /* use 625MHz on invalid value 0 */
	rd_data = sys1_r32(infrac);
	/* clear gpe-fsel and enable bits */
	rd_data_to_keep = rd_data & ~(7<<(INFRAC_GP_OFFSET+1));

	/* set new fsel */
	sys1_w32(rd_data_to_keep | (aeFreq<<(INFRAC_GP_OFFSET+2)), infrac);

	for (i = 0; i <10; i++) /* wait 10 cycles */
		{}

	/* keep new fsel and enable */
	sys1_w32(rd_data_to_keep | (aeFreq<<(INFRAC_GP_OFFSET+2)) |
		(1<<(INFRAC_GP_OFFSET+1)), infrac);
	for (i = 0; i <100; i++) /* wait 100 cycles */
		{}
}

/**
 * Activate the selected module(s)
 * Enables the clock of the module and activates the module itself.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_GPE.ACT
 * \return void
 */
void sys_gpe_hw_activate(u32 mask)
{
	enable_gpe_clk();
	sys_gpe_w32(mask, clken);
	sys_gpe_w32(mask, act);

	while ( (sys_gpe_r32(acts) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Deactivate the selected module(s)
 * Disables the clock of the module and deactivates the module itself.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_GPE.DEACT
 * \return void
 */
void sys_gpe_hw_deactivate(u32 mask)
{
	enable_gpe_clk();
	sys_gpe_w32(mask, clkclr);
	sys_gpe_w32(mask, deact);

	while ( (sys_gpe_r32(acts) & mask) != 0) {
		/*NOP;*/
	};
}

/**
 * Clock enable for the selected module(s)
 * Enables the clock of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_GPE.CLKEN
 * \return void
 */
void sys_gpe_hw_clk_enable(u32 mask)
{
	enable_gpe_clk();
	sys_gpe_w32(mask, clken);

	while ( (sys_gpe_r32(clks) & mask) != mask) {
		/*NOP;*/
	};
}

/**
 * Clock disable for the selected module(s)
 * disables the clock of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_GPE.CLKCLR
 * \return void
 */
void sys_gpe_hw_clk_disable(u32 mask)
{
	enable_gpe_clk();
	sys_gpe_w32(mask, clkclr);

	while ( (sys_gpe_r32(clks) & mask) != 0) {
		/*NOP;*/
	};
}

/**
 * Reboots the selected module(s)
 * Triggers the reboot of the module.
 *
 * \param[in]   mask    bitmask of module(s), as for registers SYS_GPE.RBT
 * \return void
 */
void sys_gpe_hw_activate_or_reboot(u32 mask)
{
	u32 acts;
	enable_gpe_clk();
	acts = sys_gpe_r32(acts);
	/* is not already active? */
	if ((~acts & mask) != 0)
		sys_gpe_hw_activate(~acts & mask);
	sys_gpe_w32(acts & mask, rbt);
	while ( (sys_gpe_r32(acts) & mask) != mask) {
		/*NOP;*/
	};
}
