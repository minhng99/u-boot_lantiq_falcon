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
 * This file contains the configuration parameters for the Falcon evaluation board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MIPS32		/* MIPS32 CPU compatible	*/
#define CONFIG_MIPS34KC		/* MIPS 34Kc CPU core		*/
#define CONFIG_FALCON		/*  in a FALCON Chip		*/

#ifndef BOARD_NAME_LINUX
#define BOARD_NAME_LINUX	EASY98000
#endif

/*
 * FALCON eval board has external PHY addon modules
 * This are some default settings for it.
 */
#ifdef CONFIG_EASY980X0
#define ENV_EXT_PHY \
	"extphy=1\0" \
	"rgmii0_phyaddr=4\0" \
	"rgmii1_phyaddr=5\0" \
	"sgmii_phyaddr=6\0" \
	"sgmii_inv=1\0"
#endif

#define ENV_ADDVOICE " vpe1_load_addr=0x81f00000 vpe1_mem=1M mem=63M"

#define CONFIG_USE_ASC0

#ifndef CONFIG_FLASH_CFI_DRIVER
/* for configs without nor flash (e.g. nand or spi!) */
#define CONFIG_SYS_NO_FLASH
#endif

#if !defined(CONFIG_ENV_SIZE)
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE			0x1000
#endif

#define CONFIG_SKIP_LOWLEVEL_INIT
//#define CONFIG_SYS_INIT_RAM_LOCK_MIPS

#define CONFIG_SYS_HUSH_PARSER		/* Use the HUSH parser */

//#define CONFIG_SYS_ALT_MEMTEST

/* memory is big enough for this range */
#define CONFIG_SYS_MEMTEST_START	0x80000000
#define CONFIG_SYS_MEMTEST_END		0x82000000

/*
 * Include common defines/options for all FALCON boards
 */
#include "falcon-common.h"

/*
 * define ddr hardware setup (board specific, same on all FALCON boards)
 */
#define DDR_CHIP_TYPE		2
#define DDR_CHIP_CAS_LATENCY	4

/*
 * define parameter (e.g. timing) of the ddr memory chip
 * -> Samsung K4T51163QG HCE6 (512Mb)
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
#define DDR_DEVICE_T_RC		60
#define DDR_DEVICE_T_FAW	50
#define DDR_DEVICE_T_MOD	12
#define DDR_DEVICE_T_RAS_MIN	45
#define DDR_DEVICE_T_RFC	105
#define DDR_DEVICE_T_RCD	15

/* following value is in us */
#define DDR_DEVICE_T_REF	7.8

/* other values */
#define DDR_DEVICE_APREBIT	10	/* A10 */
#define DDR_DEVICE_INITAREF	2

/*
 * enable watchdog support
 */
#define CONFIG_HW_WATCHDOG
#define CONFIG_LANTIQ_WATCHDOG

/*
 * enable/disable some additional features (e.g. net)
 */
#define CONFIG_NET_MULTI
#define CONFIG_FALCON_ETH

#ifdef CONFIG_OVERWRITE_ETHADDR_ONCE
#ifndef CONFIG_ETHADDR
/* define default mac and allow one overwrite */
#define CONFIG_ETHADDR				ac:9a:96:00:00:00
#endif
#endif
/* only one variable (ethaddr) for all interfaces */
#define CONFIG_SINGLE_ETHADDR

#define CONFIG_MII
#define CONFIG_CMD_MII

#ifdef CONFIG_DRIVER_DM9000
/* settings for DM9000 driver (for EBU Add-on Ethernet Controller Module) */
//#define CONFIG_DM9000_DEBUG
#define CONFIG_DM9000_SWAP16
#define CONFIG_DM9000_NO_SROM

#define CONFIG_DM9000_BASE		0xB4000000
#define DM9000_IO			(CONFIG_DM9000_BASE + 2)
#define DM9000_DATA			(CONFIG_DM9000_BASE + 0)
#endif

/*
 * LED setup for FALCON eval board
 */
#ifdef CONFIG_EASY980X0
#define CONFIG_BOARD_SPECIFIC_LED
#define CONFIG_GPIO_LED
#define CONFIG_STATUS_LED

#define CONFIG_SHOW_BOOT_PROGRESS
#define STATUS_LED_BOOT		0	/* LED 0 used for boot status */

#define FALCON_GPIO_LED_0	9
#define FALCON_GPIO_LED_1	10
#define FALCON_GPIO_LED_2	11
#define FALCON_GPIO_LED_3	12

#define STATUS_LED_BIT		FALCON_GPIO_LED_0
#define STATUS_LED_STATE	STATUS_LED_ON
#define STATUS_LED_PERIOD	(CONFIG_SYS_HZ / 10)

#define STATUS_LED_BIT1		FALCON_GPIO_LED_1
#define STATUS_LED_STATE1	STATUS_LED_OFF
#define STATUS_LED_PERIOD1	(CONFIG_SYS_HZ / 10)

#define STATUS_LED_BIT2		FALCON_GPIO_LED_2
#define STATUS_LED_STATE2	STATUS_LED_OFF
#define STATUS_LED_PERIOD2	(CONFIG_SYS_HZ / 10)

#define STATUS_LED_BIT3		FALCON_GPIO_LED_3
#define STATUS_LED_STATE3	STATUS_LED_OFF
#define STATUS_LED_PERIOD3	(CONFIG_SYS_HZ / 10)

#endif

#define CONFIG_SOFT_I2C
/* define GPIOs for soft_i2c */
#define CONFIG_SOFT_I2C_GPIO_SCL	108
#define CONFIG_SOFT_I2C_GPIO_SDA	107

/* enable i2c commands */
#define CONFIG_CMD_I2C

/* enable eeprom commands */
#define CONFIG_CMD_EEPROM
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN	1
/* allow to specify eeprom address on i2c bus */
#define CONFIG_SYS_I2C_MULTI_EEPROMS

#if 0
/*
  for environment in eeprom, the following settings must be provided
  and some others removed (more details in README)
 */
#define CONFIG_ENV_IS_IN_EEPROM
#define CONFIG_SYS_I2C_EEPROM_ADDR	0x50
#endif

#ifndef	CONFIG_SYS_I2C_SPEED
#define	CONFIG_SYS_I2C_SPEED	50000
#endif

#endif	/* __CONFIG_H */
