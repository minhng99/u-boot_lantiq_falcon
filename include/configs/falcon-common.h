/*
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH
 *
 * Common configuration options for all FALCON boards
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

#ifndef __FALCON_COMMON_H
#define __FALCON_COMMON_H

/* support all chip versions as default */
#define CONFIG_FALCON_A1x
#define CONFIG_FALCON_A2x

#ifndef CONFIG_BOOTDELAY
#define CONFIG_BOOTDELAY	5	/* autoboot after 5 seconds	*/
#endif

/* default baudrate and valid baudrates */
#ifdef CONFIG_EMULATION
#ifdef CONFIG_VENUS
#define CONFIG_BAUDRATE			38400
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }
#else
#define CONFIG_BAUDRATE			600
#define CONFIG_SYS_BAUDRATE_TABLE	{ 600, 1200, 2400 }
#endif
#else
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, 230400 }
#endif

#define CONFIG_TIMESTAMP		/* Print image info with timestamp */

/*
 * TFTP is using fragmented packets
 */
#define CONFIG_IP_DEFRAG

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#undef CONFIG_CMD_CONSOLE
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_NFS
#undef CONFIG_CMD_XIMG


#if defined(CONFIG_EMULATION) || defined(CONFIG_SYS_IN_INTERNAL_RAM)
#undef CONFIG_CMD_LOADB
#undef CONFIG_CMD_LOADS
#else
/* some options for full system */
#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_SNTP
#endif

#define CONFIG_CMD_PING

/* some "nice to have" or debugging options */
//#define CONFIG_CMD_ELF
//#define CONFIG_CMD_JFFS2

/* Falcon has support for Gigabit PHYs */
#define CONFIG_PHY_GIGE

/* falcon network driver can be configured with hwconfig */
#define CONFIG_HWCONFIG					/* enable hwconfig */

/*
 * Miscellaneous configurable options
 */

#ifndef CONFIG_SYS_IN_INTERNAL_RAM
#define CONFIG_LZMA
#define CONFIG_SYS_LONGHELP				/* undef to save memory */
#endif

#ifndef CONFIG_SYS_PROMPT
#define	CONFIG_SYS_PROMPT		"FALCON => "	/* Monitor Command Prompt */
#endif
#define CONFIG_SYS_CBSIZE		512		/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)  /* Print Buffer Size */
#define CONFIG_SYS_MAXARGS		16		/* max number of command args */

#ifndef CONFIG_SYS_MALLOC_LEN
#define CONFIG_SYS_MALLOC_LEN		(512 << 10)
#endif
#define CONFIG_SYS_BOOTPARAMS_LEN	(64 << 10)

#define CONFIG_SYS_MIPS_TIMER_FREQ	(get_cpuclk()/2)
#define CONFIG_SYS_HZ			1000

#define CONFIG_CMDLINE_EDITING		/* add command line history	*/
#define CONFIG_AUTO_COMPLETE		/* add autocompletion support	*/

#define CONFIG_ZERO_BOOTDELAY_CHECK	/* check for keypress on bootdelay==0 */
#define CONFIG_VERSION_VARIABLE		/* include version env variable */

#define CONFIG_SYS_CONSOLE_INFO_QUIET	/* don't print console @ startup*/

#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

#define CONFIG_LOADS_ECHO		/* echo on for serial download	*/
#define CONFIG_SYS_LOADS_BAUD_CHANGE	/* allow baudrate change	*/

#define CONFIG_MISC_INIT_R		/* have misc_init_r() function */

/* standard settings for NOR flash */
#ifdef CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_CFI_FLASH_USE_WEAK_ACCESSORS
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT

#define CONFIG_FLASH_SHOW_PROGRESS	45
/* as the jffs2 FS is marking unused sectors as "empty" with an own magic,
   this empty info here will not work and slows down the "flinfo" command
#define CONFIG_SYS_FLASH_EMPTY_INFO */

#define CONFIG_SYS_CFI_FLASH_STATUS_POLL

#endif /* CONFIG_FLASH_CFI_DRIVER */

/*
 * memory-map related definitions
 */
#define CONFIG_SYS_FLASH_BASE		0xB0000000
#define CONFIG_SYS_MEMTEST_SCRATCH	0xBF200020

/* definitions for internal (SBS0) RAM */
#define CONFIG_SYS_MAX_INTERNAL_RAM	(32*1024)*31	/* 31 blocks of 32kBytes */
#define CONFIG_SYS_INTERNAL_RAM_BASE	0x9F208000	/* base of usable internal ram */

#define CONFIG_SYS_MAX_RAM		(128 << 20)	/* maximum of external RAM which can be mapped */
#define CONFIG_SYS_DDR_BASE		0x80000000
#define CONFIG_SYS_LOAD_ADDR		0x80800000	/* default load address	*/

#ifndef CONFIG_SYS_MEMTEST_START
#define CONFIG_SYS_MEMTEST_START	0x80000000
#endif
#ifndef CONFIG_SYS_MEMTEST_END
#define CONFIG_SYS_MEMTEST_END		0x80800000
#endif

#ifdef CONFIG_SYS_IN_INTERNAL_RAM
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_INTERNAL_RAM_BASE
#else
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_DDR_BASE
#endif

/* location of initial stack (highest address) */
#define CONFIG_SYS_INIT_SP_OFFSET	(0xBF201000 - CONFIG_SYS_SDRAM_BASE)

/*
 * location of code before relocation
 */
/* Standard: boot from SSB0RAM */
#ifndef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE		0xBF201000
#endif
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE

/*
 * FIXME: following definition is mainly used for NOR flash based targets
 * -> update size if config is more settled
 */
#define CONFIG_SYS_MONITOR_LEN		(256 << 10)

/*
 * Cache Configuration (cpu/chip specific)
 */
#define CONFIG_SYS_DCACHE_SIZE		(16 << 10)
#define CONFIG_SYS_ICACHE_SIZE		(16 << 10)
#define CONFIG_SYS_CACHELINE_SIZE	32
#define CONFIG_SYS_MIPS_CACHE_MODE	CONF_CM_CACHABLE_NO_WA

#define CONFIG_SYS_MIPS_CACHE_INDEX_BASE	KSEG0ADDR(0x1F201000)

/*
 * Falcon network driver needs only one rx buffer
 */
#define CONFIG_SYS_RX_ETH_BUFFER	1

/*
 * Standard peripherals
 */
#define CONFIG_LTQ_ASC
#ifdef CONFIG_USE_ASC0
#  define CONFIG_SYS_LTQ_ASC_BASE		0x1E100C00
#else
#  define CONFIG_SYS_LTQ_ASC_BASE		0x1E100B00
#endif

#if defined (CONFIG_HW_WATCHDOG)
#define CONFIG_LANTIQ_WATCHDOG
#endif

#ifdef CONFIG_SPI_FLASH
#define CONFIG_CMD_SF
#if 	!defined(CONFIG_SPI_FLASH_ATMEL) && \
	!defined(CONFIG_SPI_FLASH_MACRONIX) && \
	!defined(CONFIG_SPI_FLASH_SPANSION) && \
	!defined(CONFIG_SPI_FLASH_SST) && \
	!defined(CONFIG_SPI_FLASH_WINBOND) && \
	!defined(CONFIG_SPI_FLASH_STMICRO)
#error "No CONFIG_SPI_FLASH_manufacturer defined"
#endif
#endif

#ifdef CONFIG_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0xB0000000
#endif

/*
 * default environment setup
 */

#ifndef CONFIG_PREBOOT
#define CONFIG_PREBOOT \
	"echo;" \
	"echo Type \\\"run flash_nfs\\\" to mount root filesystem over NFS;" \
	"echo"
#endif

#undef	CONFIG_BOOTARGS

#ifdef CONFIG_FLASH_CFI_DRIVER
/* NOR flash based config */

#elif defined (CONFIG_SPI_FLASH)
/* SPI flash based config */

#ifndef ENV_FLASH_BOOT
/* max_kernel_size is set to 1.5 MiB = 0x180000 */
#define ENV_FLASH_BOOT \
	"max_kernel_size=180000\0" \
	"kernel_from_sf=sf probe 0;" \
		"sf read ${ram_addr} ${kernel_offs} ${max_kernel_size}\0" \
	"flash_flash=" \
		"run kernel_from_sf flashargs addip addmisc;" \
		"bootm ${ram_addr}\0"
#endif

#elif defined (CONFIG_NAND)
/* NAND flash based config */
#ifndef ENV_FLASH_BOOT
#define ENV_FLASH_BOOT \
	"flash_flash=" \
		"run flashargs addip addmisc;" \
		"nboot ${ram_addr} 0 ${kernel_offs};" \
		"bootm ${ram_addr}\0"
#endif
#else
/* "no flash" config */
#define ENV_IMAGE_SELECT_SCRIPT
#define ENV_UPDATE_OPENWRT

#endif

#ifndef ENV_MACHTYPE
#ifdef BOARD_NAME_LINUX
#define ENV_MACHTYPE "machtype=" MK_STR(BOARD_NAME_LINUX) "\0"
#else
#define ENV_MACHTYPE
#endif
#endif

#ifndef ENV_ADDVOICE
#define ENV_ADDVOICE ""
#endif

#ifndef ENV_MTDPARTS
#define ENV_MTDPARTS
#endif

#ifndef ENV_FLASH_BOOT
#define ENV_FLASH_BOOT
#endif

#ifndef ENV_IMAGENAME
/* always use "-NONE" image, otherwise required settings from commandline are missing! */
#if defined(BOARD_NAME_LINUX) && 0
#define ENV_IMAGENAME "image_name=openwrt-lantiq-falcon-" MK_STR(BOARD_NAME_LINUX) "\0"
#else
#define ENV_IMAGENAME "image_name=openwrt-lantiq-falcon-NONE\0"
#endif
#endif

#ifndef ENV_LOAD_KERNEL
#define ENV_LOAD_KERNEL "load_kernel=tftp ${ram_addr} ${tftppath}${image_name}-uImage\0"
#endif

#ifndef ENV_UPDATE_UBOOT
#define ENV_UPDATE_UBOOT
#endif

#ifndef ENV_UPDATE_IMAGE
#define ENV_UPDATE_IMAGE
#endif

#ifndef CONFIG_EXTRA_ENV_EMULATION
#define CONFIG_EXTRA_ENV_EMULATION
#endif

#ifndef ENV_ETHROTATE
#define ENV_ETHROTATE "ethrotate=no\0"
#endif

#ifndef ENV_EXT_PHY
#define ENV_EXT_PHY
#endif

#ifndef ENV_TWO_IMAGES
#define ENV_TWO_IMAGES
#endif

#ifndef ENV_IMAGE_SELECT_SCRIPT
#define MAGIC_ADDR     0xBF200038
#define MAGIC_VAL      0xDEADBEEF
#define ACT_IMG_ADDR   0xBF20003C

#define ENV_IMAGE_SELECT_SCRIPT \
	"select_image=" \
		"setenv activate_image -1;" \
		"if itest *${magic_addr} == ${magic_val} ; then " \
			"if itest *${act_img_addr} == 0 ; then " \
				"setenv activate_image 0;" \
			"fi;" \
			"if itest *${act_img_addr} == 1 ; then " \
				"setenv activate_image 1;" \
			"fi;" \
			"mw ${magic_addr} 0x0;" \
			"mw ${act_img_addr} 0x0;" \
		"fi;" \
		"if test $activate_image = -1 ; then " \
			"setenv c_img $committed_image;" \
		"else " \
			"setenv c_img $activate_image;" \
			"setenv activate_image -1;" \
		"fi;" \
		"if test $c_img = 0 && test image0_is_valid = 0 ; then " \
			"setenv c_img 1;" \
		"fi;" \
		"if test $c_img = 1 && test image1_is_valid = 0 ; then " \
			"setenv c_img 0;" \
		"fi;" \
		"if test image0_is_valid = 0 && test image1_is_valid = 0 ; then " \
			"setenv c_img _err;" \
		"fi;" \
		"exit 0\0" \
	"committed_image=0\0" \
	"image0_is_valid=1\0" \
	"image1_is_valid=0\0" \
	"magic_addr=" MK_STR(MAGIC_ADDR) "\0" \
	"magic_val=" MK_STR(MAGIC_VAL) "\0" \
	"act_img_addr=" MK_STR(ACT_IMG_ADDR) "\0"
#endif

#ifndef ENV_UPDATE_OPENWRT
#define ENV_UPDATE_OPENWRT \
	"update_openwrt=run update_image0 && " \
		"setenv committed_image 0 && " \
		"setenv image0_is_valid 1\0"
#endif

#ifndef ENV_NET_BOOT
#define ENV_NET_BOOT \
	"nfsargs=setenv bootargs root=/dev/nfs rw " \
		"nfsroot=${serverip}:${rootpath},${nfsoptions}\0"\
	"nfsoptions=rsize=1024,wsize=1024\0"\
	"net_nfs=run load_kernel nfsargs addip addmtdparts0 addmisc;" \
		"bootm ${ram_addr}\0"
#endif

#define CONFIG_EXTRA_ENV_SETTINGS \
	"ram_addr=80F00000\0" \
	ENV_IMAGE_SELECT_SCRIPT \
	ENV_TWO_IMAGES \
	"flashargs=setenv bootargs rootfstype=squashfs,jffs2\0" \
	"addip=setenv bootargs ${bootargs} " \
		"ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}" \
		":${hostname}:${netdev}:off\0" \
	ENV_MACHTYPE \
	"addmisc=setenv bootargs ${bootargs} ethaddr=${ethaddr} " \
		"machtype=${machtype} ignore_loglevel" ENV_ADDVOICE \
		" ${mtdparts}\0" \
	ENV_MTDPARTS \
	ENV_FLASH_BOOT \
	ENV_NET_BOOT \
	ENV_IMAGENAME \
	ENV_LOAD_KERNEL \
	ENV_UPDATE_UBOOT \
	ENV_UPDATE_IMAGE \
	ENV_UPDATE_OPENWRT \
	ENV_ETHROTATE \
	"gphy0_phyaddr=0\0" \
	"gphy1_phyaddr=1\0" \
	ENV_EXT_PHY \
	CONFIG_EXTRA_ENV_EMULATION

#ifndef CONFIG_EMULATION
#ifndef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND	"run flash_flash"
#endif
#endif

/* disable some default config settings */
#undef CONFIG_BOOTM_NETBSD
#undef CONFIG_BOOTM_RTEMS
#undef CONFIG_GZIP
#undef CONFIG_ZLIB

#endif /* __FALCON_COMMON_H */
