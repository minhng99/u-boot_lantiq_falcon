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
#define CONFIG_FLASH_CFI_DRIVER

/*-----------------------------------------------------------------------
 * FLASH and environment organization (NOR Flash)
 */

#if 0
#define CONFIG_SYS_FLASH_QUIET_TEST
#define CONFIG_SYS_FLASH_EMPTY_INFO
#endif

#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CONFIG_SYS_MAX_FLASH_SECT	(512)	/* max number of sectors on one chip */

#define CONFIG_ENV_IS_IN_FLASH
/* offset and size of environment storage */
#define CONFIG_ENV_OFFSET		0x40000
#define CONFIG_ENV_OFFSET_REDUND	0x60000
#define CONFIG_ENV_SECT_SIZE		0x20000
#define CONFIG_ENV_SIZE			0x10000

/* protect u-boot range */
#define CONFIG_SYS_FLASH_AUTOPROTECT_LIST	{{CONFIG_SYS_FLASH_BASE, CONFIG_SYS_MONITOR_LEN}}

#define xstr(s)	str(s)
#define str(s)	#s

#define UBOOT_ADDR		0xB0000000
#define UBOOT_SIZE		256

#define UBOOTENV_ADDR		0xB0040000
#define UBOOTENV_SIZE		256

#define ENV_UPDATE_UBOOT \
	"load_uboot=tftp ${ram_addr} ${tftppath}u-boot.img\0" \
	"save_uboot=protect off " MK_STR(UBOOT_ADDR) " +${filesize};" \
		"erase " MK_STR(UBOOT_ADDR) " +${filesize};" \
		"cp.b ${ram_addr} " MK_STR(UBOOT_ADDR) " ${filesize};" \
		"protect on " MK_STR(UBOOT_ADDR) " +${filesize}\0" \
	"update_uboot=run load_uboot save_uboot\0" \
	"reset_uboot_env=protect off " MK_STR(UBOOTENV_ADDR) " +40000;" \
		"erase " MK_STR(UBOOTENV_ADDR) " +40000;" \
		"protect on " MK_STR(UBOOTENV_ADDR) " +40000\0"

#define IMAGE0_ADDR		0xB0080000
#define IMAGE0_SIZE		7936

#define IMAGE1_ADDR		0xB0840000
#define IMAGE1_SIZE		7936

#define ENV_TWO_IMAGES \
	"image0_addr=" MK_STR(IMAGE0_ADDR) "\0" \
	"image1_addr=" MK_STR(IMAGE1_ADDR) "\0" \
	"boot_image0=" \
		"run flashargs addip addmtdparts0 addmisc && " \
		"bootm $image0_addr\0" \
	"boot_image1=" \
		"run flashargs addip addmtdparts1 addmisc && " \
		"bootm $image1_addr\0" \
	"boot_image_err=" \
		"setenv kernel_addr ${image0_addr};" \
		"httpd && setenv image0_is_valid 1\0" \
	"boot_image=run boot_image${c_img};\0"

#define ENV_UPDATE_IMAGE \
	"update_image0=" \
		"tftp ${ram_addr} ${tftppath}${image_name}-squashfs.image && " \
		"protect off all && " \
		"era ${image0_addr} +${filesize} && " \
		"cp.b ${ram_addr} ${image0_addr} ${filesize}\0" \
	"update_image1=" \
		"tftp ${ram_addr} ${tftppath}${image_name}-squashfs.image && " \
		"protect off all && " \
		"era ${image1_addr} +${filesize} && " \
		"cp.b ${ram_addr} ${image1_addr} ${filesize}\0"

#define ENV_MTDPARTS \
	"addmtdparts0=setenv mtdparts " \
		"mtdparts=ltq_nor:" \
		MK_STR(UBOOT_SIZE)	"k(uboot)ro," \
		MK_STR(UBOOTENV_SIZE)	"k(uboot_env)," \
		MK_STR(IMAGE0_SIZE)	"k(linux)," \
		MK_STR(IMAGE1_SIZE)	"k(image1)\0" \
	"addmtdparts1=setenv mtdparts " \
		"mtdparts=ltq_nor:" \
		MK_STR(UBOOT_SIZE)	"k(uboot)ro," \
		MK_STR(UBOOTENV_SIZE)	"k(uboot_env)," \
		MK_STR(IMAGE0_SIZE)	"k(image0)," \
		MK_STR(IMAGE1_SIZE)	"k(linux)\0"

#define ENV_FLASH_BOOT \
	"flash_flash=run select_image boot_image\0"

/* DM9000 driver for EBU Add-on Ethernet Controller Module */
#define CONFIG_DRIVER_DM9000

/* Falcon Evaluation Board */
#define CONFIG_EASY980X0

#define CONFIG_CMD_HTTPD	/* enable upgrade via HTTPD */

#define CONFIG_OVERWRITE_ETHADDR_ONCE

#include "configs/easy980x0.h"
