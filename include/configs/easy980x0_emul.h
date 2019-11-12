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

/*
 * This file contains the configuration parameters for the Falcon on emulator.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MIPS32			/* MIPS32 CPU compatible	*/
#define CONFIG_MIPS34KC			/* MIPS 34Kc CPU core		*/
#define CONFIG_FALCON			/*  in a FALCON Chip		*/
#define CONFIG_EASY980X0		/*   on the Evaluation Board	*/
#define CONFIG_EMULATION		/* include support for running in emulation */

#define BOARD_NAME_LINUX	EASY98000

#define CONFIG_USE_ASC0

//#define DEBUG

//#define CONFIG_SYS_ALT_MEMTEST

/* for emulation without nor flash */
#define CONFIG_SYS_NO_FLASH

#if !defined(CONFIG_ENV_IS_IN_NAND) && !defined(CONFIG_ENV_IS_IN_SPI_FLASH)
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE			0x1000
#endif

#define CONFIG_SYS_IN_INTERNAL_RAM

#define CONFIG_SKIP_LOWLEVEL_INIT
//#define CONFIG_SYS_INIT_RAM_LOCK_MIPS

#undef CONFIG_SYS_HUSH_PARSER		/* Use the HUSH parser		*/

#ifdef CONFIG_NAND
#define CONFIG_CMD_NAND
//#define CONFIG_SYS_NAND_QUIET_TEST		/* don't warn upon unknown NAND flash   */
//#define CONFIG_SYS_NAND_QUIET			/* FIXME: enable later */
#define CONFIG_CMD_NAND_LOCK_UNLOCK
#endif

#ifdef CONFIG_SPI_FLASH
/* enable support for all possible flashes in emulation */
#define CONFIG_SPI_FLASH_ATMEL
#define CONFIG_SPI_FLASH_MACRONIX
#define CONFIG_SPI_FLASH_SPANSION
#define CONFIG_SPI_FLASH_SST
#define CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SPI_FLASH_STMICRO
#endif

#ifdef CONFIG_VENUS
/* some extra environment settings for emulation: load and start sce firmware */
#define CONFIG_EXTRA_ENV_EMULATION	"fw=tftp 80000000 default.fw;sce init"
#endif

/*
 * Include common defines/options for all FALCON boards
 */
#include "falcon-common.h"

/*
 * define ddr hardware setup (board specific)
 */
#define DDR_CHIP_TYPE		2
#define DDR_CHIP_SIZE_MBIT	256
#define DDR_CHIP_CAS_LATENCY	3

#define DDR_CHIP_ROW_ADDR	12


/*
 * define parameter (e.g. timing) of the ddr memory chip
 */
 /* timings in ticks */
#define DDR_DEVICE_T_CKE	3
#define DDR_DEVICE_T_MRD	2
#define DDR_DEVICE_T_DLL	200

/* following timings are in ns */
#define DDR_DEVICE_T_RRD	10
#define DDR_DEVICE_T_RTP	7.5
#define DDR_DEVICE_T_RP		15
#define DDR_DEVICE_T_WR		16
#define DDR_DEVICE_T_WTR	10
#define DDR_DEVICE_T_RC		55
#define DDR_DEVICE_T_FAW	50
#define DDR_DEVICE_T_MOD	12
#define DDR_DEVICE_T_RAS_MIN	40
#define DDR_DEVICE_T_DAL	10
#define DDR_DEVICE_T_RFC	75
#define DDR_DEVICE_T_RCD	15

/* following value is in us */
#define DDR_DEVICE_T_REF	7.8

/* other values */
#define DDR_DEVICE_APREBIT	10	/* A10 */
#define DDR_DEVICE_INITAREF	2

/*
 * enable/disable some additional features (e.g. net)
 */

#if 1
#define CONFIG_NET_MULTI
#define CONFIG_FALCON_ETH

#define CONFIG_MII
#define CONFIG_CMD_MII
#else
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_PING
#endif

//#define CONFIG_CMD_HTTPD		/* enable upgrade via HTTPD */
//#define CONFIG_CMD_DTI		/* enable DTI agent support */

#define CONFIG_SF_DEFAULT_SPEED		50000000

#if 0
#define CONFIG_HW_WATCHDOG
#endif

/* only for testing in emulation (Palladium/Venus) environment: */
#ifdef CONFIG_VENUS
#define CONFIG_IPADDR			192.168.152.171
#define CONFIG_SERVERIP			192.168.152.150
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_GATEWAYIP		192.168.152.150
#else
#define CONFIG_IPADDR			192.168.152.170
#define CONFIG_SERVERIP			192.168.153.10
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_GATEWAYIP		192.168.152.150
#endif

/* optimize some timeouts for emulation */
#define CONFIG_ARP_TIMEOUT		5000UL
#define CONFIG_NET_RETRY_COUNT		50


#endif	/* __CONFIG_H */
