/*
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
 *
 * Copyright (C) 2011 Thomas Langer, Lantiq Deutschland
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>

#ifdef CONFIG_EMULATION
/* some variables used during emulation for external configuration */
static u32 * const _emu_on  = (u32*)0xBF017FF0;
static u32 * const _emu_spd = (u32*)0xBF017FF4;
#endif

ulong get_cpuclk(void)
{
#ifdef CONFIG_EMULATION
#warning "include emulation support"
	if (*_emu_on != 0) {
		return *_emu_spd;
	} else
#endif
	{
		if ((sys1_r32(cpu0cc) & CPU0CC_CPUDIV) == CPU0CC_CPUDIV_SELFHALF)
			return 200000000; /* 200 MHz */
		else
			return 400000000; /* 400 MHz */
	}
}

ulong get_bus_freq(ulong dummy)
{
#ifdef CONFIG_EMULATION
	if (*_emu_on != 0) {
		return *_emu_spd/4;
	}
	else
#endif
	{
		/* FPI bus clock is fixed to 100 MHz */
		return 100000000;
	}
}

