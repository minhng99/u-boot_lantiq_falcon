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

#define BOARD_NAME_LINUX	EASY98000NAND

/* select flash type */
#define CONFIG_NAND
#define CONFIG_CMD_NAND

/*
 * for compatibility to the bootrom ECC code,
 * we don't define CONFIG_MTD_NAND_ECC_SMC
 */

/* define hardware flash organization for bootrom image */
#define CONFIG_SYS_NAND_PAGESIZE		0x00000800
#define CONFIG_SYS_NAND_BYTES_PER_COLADDR	0x00000002

//#define CONFIG_SYS_NAND_QUIET_TEST		/* don't warn upon unknown NAND flash   */
//#define CONFIG_SYS_NAND_QUIET			/* FIXME: enable later */

#define CONFIG_CMD_NAND_LOCK_UNLOCK
#define CONFIG_MTD_NAND_VERIFY_WRITE

#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_SIZE			0x10000
/* (erase-)sector size: */
#define CONFIG_ENV_RANGE		0x20000
#define CONFIG_ENV_OFFSET		0x80000
#define CONFIG_ENV_OFFSET_REDUND	0xC0000

#define ENV_UPDATE_UBOOT \
	"load_uboot=tftp ${ram_addr} ${tftppath}u-boot.img\0" \
	"save_uboot=nand erase 0 80000;" \
		"nand write ${ram_addr} 0 40000\0" \
	"update_uboot=run load_uboot save_uboot\0" \
	"reset_uboot_env=nand erase 80000 80000\0"

#define IMAGE0_ADDR    0xB0100000
#define KERNEL0_OFFS   0x100000
#define IMAGE0_SIZE    7168

#define IMAGE1_ADDR    0xB0800000
#define KERNEL1_OFFS   0x800000
#define IMAGE1_SIZE    8192

#define ENV_TWO_IMAGES \
	"image0_addr=" MK_STR(IMAGE0_ADDR) "\0" \
	"image1_addr=" MK_STR(IMAGE1_ADDR) "\0" \
	"kernel0_offs=" MK_STR(KERNEL0_OFFS) "\0" \
	"kernel1_offs=" MK_STR(KERNEL1_OFFS) "\0" \
	"boot_image0=" \
		"run flashargs addip addmtdparts0 addmisc;" \
		"nboot ${ram_addr} 0 ${kernel0_offs};" \
		"bootm ${ram_addr}\0" \
	"boot_image1=" \
		"run flashargs addip addmtdparts1 addmisc;" \
		"nboot ${ram_addr} 0 ${kernel1_offs};" \
		"bootm ${ram_addr}\0" \
	"boot_image_err=" \
		"setenv kernel_offs ${kernel0_offs};" \
		"httpd && setenv image0_is_valid 1\0" \
	"boot_image=run boot_image${c_img};\0"

#define ENV_UPDATE_IMAGE \
	"update_image0=tftp ${ram_addr} " \
		"${tftppath}${image_name}-squashfs.image;" \
		"nand erase.spread ${kernel0_offs} ${filesize};" \
		"nand write ${ram_addr} ${kernel0_offs} ${filesize}\0" \
	"update_image1=tftp ${ram_addr} " \
		"${tftppath}${image_name}-squashfs.image;" \
		"nand erase.spread ${kernel1_offs} ${filesize};" \
		"nand write ${ram_addr} ${kernel1_offs} ${filesize}\0"

#define ENV_MTDPARTS \
	"addmtdparts0=setenv mtdparts " \
		"mtdparts=gen_nand:" \
		"512k(uboot)ro," \
		"512k(uboot_env)," \
		MK_STR(IMAGE0_SIZE)	"k(linux)," \
		MK_STR(IMAGE1_SIZE)	"k(image1)\0" \
	"addmtdparts1=setenv mtdparts " \
		"mtdparts=gen_nand:" \
		"512k(uboot)ro," \
		"512k(uboot_env)," \
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
