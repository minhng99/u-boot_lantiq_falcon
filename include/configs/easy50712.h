/*
 * (C) Copyright 2003-2005
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

/*
 * This file contains the configuration parameters for the Danube reference board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#ifndef BOARD_NAME_LINUX
#define BOARD_NAME_LINUX	EASY50712
#endif

#define CONFIG_MIPS32			/* MIPS32 CPU compatible		*/
#define CONFIG_MIPS24KEC		/* MIPS 24KEc CPU core			*/
#define CONFIG_DANUBE			/* in a Danube/Twinpass Chip		*/
#define CONFIG_EASY50712		/* on the Danube Reference Board	*/

#define CONFIG_SYS_MIPS_MULTI_CPU	/* This is a multi cpu system */

#define CONFIG_SYS_MAX_RAM	(32 << 20)
#define CONFIG_FLASH_CFI_DRIVER

#define CONFIG_SYS_INIT_RAM_LOCK_MIPS

#ifdef CONFIG_SYS_RAMBOOT
	#define CONFIG_SYS_TEXT_BASE		0xA0400000
	#define CONFIG_SKIP_LOWLEVEL_INIT
#else /* CONFIG_SYS_RAMBOOT */
	#define CONFIG_SYS_TEXT_BASE		0xB0000000
	#define CONFIG_SYS_EBU_BOOT
	#define INFINEON_EBU_BOOTCFG		0x688C688C
#endif /* CONFIG_SYS_RAMBOOT */

#define	CONFIG_SYS_PROMPT	"DANUBE => "	/* Monitor Command Prompt */

#ifdef CONFIG_TWO_IMAGES
#	define	CONFIG_SYS_HUSH_PARSER		/* Use the HUSH parser */
#else
#	undef	CONFIG_SYS_HUSH_PARSER
#endif

/*
 * Include common defines/options for all Infineon boards
 */
#include "ifx-common.h"

/*
 * Cache Configuration (cpu/chip specific, Danube)
 */
#define CONFIG_SYS_DCACHE_SIZE		(16 << 10)
#define CONFIG_SYS_ICACHE_SIZE		(16 << 10)
#define CONFIG_SYS_CACHELINE_SIZE	32
#define CONFIG_SYS_MIPS_CACHE_MODE	CONF_CM_CACHABLE_NO_WA

#define CONFIG_NET_MULTI

#define CONFIG_IFX_ETOP			/* lantiq ethernet cpe interface */
#define CLK_OUT2_25MHZ
#define CONFIG_EXTRA_SWITCH		/* search for external switches like tantos */
#define CONFIG_RMII			/* use interface in RMII mode */

/* enable MII commands */
#define CONFIG_MII
#define CONFIG_CMD_MII

#define CONFIG_LTQ_ASC			/* use lantiq ASC driver */
#ifdef CONFIG_USE_ASC0
#define CONFIG_SYS_LTQ_ASC_BASE		0x1E100400
#else
#define CONFIG_SYS_LTQ_ASC_BASE		0x1E100C00
#endif

#ifdef CONFIG_SYS_RAMBOOT
/* Configuration of EBU: */
/* starting address from 0xb0000000 */
/* make the flash available from RAM boot */
#	define CONFIG_EBU_ADDSEL0		0x10000031
#	define CONFIG_EBU_BUSCON0		0x0001D7FF
#endif

#ifndef CONFIG_SYS_RAMBOOT
#define CONFIG_CMD_HTTPD		/* enable upgrade via HTTPD */
#endif

#endif	/* __CONFIG_H */
