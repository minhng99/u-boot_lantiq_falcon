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

/* select flash type */
#define CONFIG_SPI_FLASH

/* enable support for all possible flashes */
#define CONFIG_SPI_FLASH_ATMEL
#define CONFIG_SPI_FLASH_MACRONIX
#define CONFIG_SPI_FLASH_SPANSION
#define CONFIG_SPI_FLASH_SST
#define CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SPI_FLASH_STMICRO

#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_SYS_REDUNDAND_ENVIRONMENT

#define CONFIG_SF_DEFAULT_SPEED		50000000
#define CONFIG_ENV_SPI_MAX_HZ		50000000

#define CONFIG_ENV_SIZE			0x10000
#define CONFIG_ENV_SECT_SIZE		0x40000
#define CONFIG_ENV_OFFSET		0x40000
#define CONFIG_ENV_OFFSET_REDUND	CONFIG_ENV_OFFSET + CONFIG_ENV_SECT_SIZE

#define ENV_UPDATE_UBOOT \
	"load_uboot=tftp ${ram_addr} ${tftppath}u-boot.img\0" \
	"save_uboot=sf probe 0;" \
		"sf erase 0 40000;" \
		"sf write ${ram_addr} 0 ${filesize}\0" \
	"update_uboot=run load_uboot save_uboot\0" \
	"reset_uboot_env=sf probe 0;sf erase 40000 80000\0"

#define IMAGE0_ADDR    0xB00C0000
#define KERNEL0_OFFS   0xC0000
#define IMAGE0_SIZE    7424

#define IMAGE1_ADDR    0xB0800000
#define KERNEL1_OFFS   0x800000
#define IMAGE1_SIZE    8192

#define ENV_TWO_IMAGES \
	"image0_addr=" MK_STR(IMAGE0_ADDR) "\0" \
	"image1_addr=" MK_STR(IMAGE1_ADDR) "\0" \
	"kernel0_offs=" MK_STR(KERNEL0_OFFS) "\0" \
	"kernel1_offs=" MK_STR(KERNEL1_OFFS) "\0" \
	"max_kernel_size=180000\0" \
	"kernel0_from_sf=sf probe 0;" \
		"sf read ${ram_addr} ${kernel0_offs} ${max_kernel_size}\0" \
	"kernel1_from_sf=sf probe 0;" \
		"sf read ${ram_addr} ${kernel1_offs} ${max_kernel_size}\0" \
	"boot_image0=" \
		"run kernel0_from_sf flashargs addip addmtdparts0 addmisc && " \
		"bootm ${ram_addr}\0" \
	"boot_image1=" \
		"run kernel1_from_sf flashargs addip addmtdparts1 addmisc && " \
		"bootm ${ram_addr}\0" \
	"boot_image_err=" \
		"setenv kernel_offs ${kernel0_offs};" \
		"httpd && setenv image0_is_valid 1\0" \
	"boot_image=run boot_image${c_img};\0"

#define ENV_UPDATE_IMAGE \
	"update_image0=tftp ${ram_addr} ${tftppath}${image_name}-squashfs.image;" \
		"sf probe 0;" \
		"sf erase ${kernel0_offs} +${filesize};" \
		"sf write ${ram_addr} ${kernel0_offs} ${filesize}\0" \
	"update_image1=tftp ${ram_addr} ${tftppath}${image_name}-squashfs.image;" \
		"sf probe 0;" \
		"sf erase ${kernel1_offs} +${filesize};" \
		"sf write ${ram_addr} ${kernel1_offs} ${filesize}\0"

#define ENV_MTDPARTS \
	"addmtdparts0=setenv mtdparts " \
		"mtdparts=sflash:" \
		"256k(uboot)ro," \
		"512k(uboot_env)," \
		MK_STR(IMAGE0_SIZE)	"k(linux)," \
		MK_STR(IMAGE1_SIZE)	"k(image1)\0" \
	"addmtdparts1=setenv mtdparts " \
		"mtdparts=sflash:" \
		"256k(uboot)ro," \
		"512k(uboot_env)," \
		MK_STR(IMAGE0_SIZE)	"k(image0)," \
		MK_STR(IMAGE1_SIZE)	"k(linux)\0"

#define ENV_FLASH_BOOT \
	"flash_flash=run select_image boot_image\0"

#define ENV_ETHROTATE ""

#define CONFIG_OVERWRITE_ETHADDR_ONCE

#define ENV_EXT_PHY \
	"extphy=1\0" \
	"rgmii0_phyaddr=5\0" \
	"rgmii1_phyaddr=6\0"

#define CONFIG_FALCON_NET_PORT_MASK \
	(FALCON_NET_PORT_MASK_GPHY | FALCON_NET_PORT_MASK_RGMII)

#define BOARD_NAME_LINUX	EASY98020

/* Falcon Reference Board */
#define CONFIG_EASY98020

#define CONFIG_CMD_HTTPD	/* enable upgrade via HTTPD */

#define CONFIG_HTTP_RECOVER_GPIO	1
#define CONFIG_HTTP_RECOVER_GPIO_LEVEL	0

/*
 * LED setup for FALCON reference board
 */
#define CONFIG_BOARD_SPECIFIC_LED
#define CONFIG_GPIO_LED
#define CONFIG_STATUS_LED

#define FALCON_GPIO_LED_0	9
#define FALCON_GPIO_LED_1	10
#define FALCON_GPIO_LED_2	11
#define FALCON_GPIO_LED_3	12

#define STATUS_LED_BIT		FALCON_GPIO_LED_0
#define STATUS_LED_STATE	STATUS_LED_OFF
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

#include "configs/easy980x0.h"
