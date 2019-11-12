/*
 * (C) Copyright 2008
 * Stefan Roese, DENX Software Engineering, sr@denx.de.
 *
 * Common configuration options for all AMCC boards
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

#ifndef __IFX_COMMON_H
#define __IFX_COMMON_H

#define CONFIG_BOOTDELAY	5	/* autoboot after 5 seconds	*/

#ifndef ENV_MACHTYPE
#ifdef BOARD_NAME_LINUX
#define ENV_MACHTYPE "machtype=" MK_STR(BOARD_NAME_LINUX) "\0"
#else
#define ENV_MACHTYPE
#endif
#endif

#ifdef CONFIG_EMULATION
#define CONFIG_BAUDRATE		600
/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 600, 1200, 2400, 9600, 19200, 38400, 57600, 115200, 230400 }
#else
#define CONFIG_BAUDRATE		115200
/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, 230400 }
#endif


#define CONFIG_TIMESTAMP		/* Print image info with timestamp */

#define CONFIG_PREBOOT	"echo;"	\
	"echo Type \\\"run flash_nfs\\\" to mount root filesystem over NFS;" \
	"echo"

#undef	CONFIG_BOOTARGS

#ifndef ENV_IMAGENAME
#define ENV_IMAGENAME "image_name=openwrt-lantiq-xway-" MK_STR(BOARD_NAME_LINUX) "\0"
#endif

#ifdef CONFIG_TWO_IMAGES
#define UBOOT_FILENAME		"u-boot.bin"
#define UBOOT_ADDR		PHYS_FLASH_1
#define UBOOT_SIZE		256

#define UBOOTENV_ADDR		CONFIG_ENV_ADDR
#define UBOOTENV_SIZE		64

#define BOOTSCRIPT_FILENAME	"bootscript.img"
#define BOOTSCRIPT_ADDR		0xB0050000
#define BOOTSCRIPT_SIZE		64

#define IMAGE0_FILENAME		"image0.img"
#define IMAGE0_ADDR		0xB0060000
#define IMAGE0_SIZE		3904

#define IMAGE1_FILENAME		"image1.img"
#define IMAGE1_ADDR		0xB0430000
#define IMAGE1_SIZE		3904

#define CONFIG_EXTRA_ENV_SETTINGS					\
	"ram_addr=0x80500000\0"						\
	"image0_addr=" MK_STR(IMAGE0_ADDR) "\0"				\
	"image1_addr=" MK_STR(IMAGE1_ADDR) "\0"				\
	ENV_MACHTYPE                                                       \
	ENV_IMAGENAME                                                   \
	"bootscript_addr=" MK_STR(BOOTSCRIPT_ADDR) "\0"			\
	"activate_image=-1\0"						\
	"committed_image=0\0"						\
	"image0_is_valid=1\0"						\
	"image1_is_valid=0\0"						\
	"flashargs=setenv bootargs rootfstype=squashfs,jffs2\0"		\
	"nfsargs=setenv bootargs root=/dev/nfs rw "			\
		"nfsroot=${serverip}:${rootpath} \0"			\
	"addip=setenv bootargs ${bootargs} "				\
		"ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}"	\
		":${hostname}:${netdev}:off\0"				\
	"addmisc=setenv bootargs ${bootargs} init=/etc/preinit "	\
		"console=ttyS1,115200 ethaddr=${ethaddr} \0"		\
	"addmtdparts0=setenv bootargs ${bootargs} "			\
		"mtdparts=lq_nor:"					\
		MK_STR(UBOOT_SIZE)	"k(uboot)ro,"			\
		MK_STR(UBOOTENV_SIZE)	"k(uboot_env),"			\
		MK_STR(BOOTSCRIPT_SIZE)	"k(bootscript),"		\
		"64k(kernel)ro,"					\
		MK_STR(IMAGE0_SIZE)	"k(rootfs)ro,"			\
		"-(image1)\0"						\
	"addmtdparts1=setenv bootargs ${bootargs} "			\
		"mtdparts=lq_nor:"					\
		MK_STR(UBOOT_SIZE)	"k(uboot)ro,"			\
		MK_STR(UBOOTENV_SIZE)	"k(uboot_env),"			\
		MK_STR(BOOTSCRIPT_SIZE)	"k(bootscript),"		\
		MK_STR(IMAGE0_SIZE)	"k(image0),"			\
		"64k(kernel)ro,"					\
		"-(rootfs)ro\0"						\
	"flash_flash=run flashargs addip addmisc && "			\
		"source ${bootscript_addr}\0"				\
	"flash_nfs=run nfsargs addip addmisc addmtdparts0 && "		\
		"bootm ${image0_addr}\0"				\
	"net_flash=run load_kernel flashargs addip addmisc "		\
		"addmtdparts0 && bootm ${ram_addr}\0"			\
	"net_nfs=run load_kernel nfsargs addip addmisc addmtdparts0 && "\
		"bootm ${ram_addr}\0"					\
	"load_kernel=tftp ${ram_addr} "					\
		"${tftppath}${image_name}-uImage\0"		        \
	"update_uboot="							\
		"tftp ${ram_addr} ${tftppath}" UBOOT_FILENAME " && "	\
		"protect off all && "					\
		"era " MK_STR(UBOOT_ADDR) " +${filesize} && "		\
		"era " MK_STR(UBOOT_ADDR) " +65535 && "			\
		"cp.b ${ram_addr} " MK_STR(UBOOT_ADDR) " ${filesize}\0"	\
	"update_bootscript=tftp ${ram_addr} ${tftppath}"		\
			BOOTSCRIPT_FILENAME " && "			\
		"protect off all && "					\
		"era ${bootscript_addr} +${filesize} && "		\
		"cp.b ${ram_addr} ${bootscript_addr} ${filesize}\0"	\
	"update_openwrt=tftp ${ram_addr} "				\
		"${tftppath}${image_name}-squashfs.image && "	        \
		"protect off all && "					\
		"era ${image0_addr} +${filesize} && "			\
		"cp.b ${ram_addr} ${image0_addr} ${filesize}\0"		\
	"update_image0="						\
		"tftp ${ram_addr} ${tftppath}" IMAGE0_FILENAME " && "	\
		"protect off all && "					\
		"era ${image0_addr} +${filesize} && "			\
		"cp.b ${ram_addr} ${image0_addr} ${filesize}\0"		\
	"update_image1="						\
		"tftp ${ram_addr} ${tftppath}" IMAGE1_FILENAME " && "	\
		"protect off all && "					\
		"era ${image1_addr} +${filesize} && "			\
		"cp.b ${ram_addr} ${image1_addr} ${filesize}\0"		\
	"boot_image0="							\
		"run flashargs addip addmisc addmtdparts0 && "		\
		"bootm $image0_addr\0"					\
	"boot_image1="							\
		"run flashargs addip addmisc addmtdparts1 && "		\
		"bootm $image1_addr\0"
#else
#define CONFIG_EXTRA_ENV_SETTINGS					\
	"ram_addr=0x80500000\0"						\
	"kernel_addr=0xb0050000\0"					\
	ENV_MACHTYPE                                                       \
	ENV_IMAGENAME                                                   \
	"mtdparts=mtdparts=lq_nor:256k(uboot)ro,64k(uboot_env)ro,-(linux)\0" \
	"flashargs=setenv bootargs rootfstype=squashfs,jffs2\0"		\
	"nfsargs=setenv bootargs root=/dev/nfs rw "			\
		"nfsroot=${serverip}:${rootpath} \0"			\
	"addip=setenv bootargs ${bootargs} "				\
		"ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}"	\
		":${hostname}:${netdev}:off\0"				\
	"addmisc=setenv bootargs ${bootargs} "	                        \
		"console=ttyS1,115200 ethaddr=${ethaddr} "              \
		"machtype=${machtype} ${mtdparts}\0"                    \
	"flash_flash=run flashargs addip addmisc;"			\
		"bootm ${kernel_addr}\0"				\
	"flash_nfs=run nfsargs addip addmisc;bootm ${kernel_addr}\0"	\
	"net_flash=run load_kernel flashargs addip addmisc;"		\
		"bootm ${ram_addr}\0"					\
	"net_nfs=run load_kernel nfsargs addip addmisc;"		\
		"bootm ${ram_addr}\0"					\
	"load_kernel=tftp ${ram_addr} "					\
		"${tftppath}${image_name}-uImage\0"		        \
	"update_uboot=tftp 0x80500000 ${tftppath}u-boot.bin;era 0xb0000000 +${filesize};" \
		"cp.b 0x80500000 0xb0000000 ${filesize}\0"              \
	"update_openwrt=tftp ${ram_addr} "				\
		"${tftppath}${image_name}-squashfs.image;"              \
		"era ${kernel_addr} +${filesize};"			\
		"cp.b ${ram_addr} ${kernel_addr} ${filesize}\0"
#endif

#define CONFIG_BOOTCOMMAND	"run flash_flash"

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
#undef CONFIG_CMD_LOADB
#undef CONFIG_CMD_LOADS
#undef CONFIG_CMD_NFS
#undef CONFIG_CMD_XIMG

//#define CONFIG_CMD_ASKENV
//#define CONFIG_CMD_DHCP
//#define CONFIG_CMD_ELF
#define CONFIG_CMD_PING
//#define CONFIG_CMD_JFFS2
//#define CONFIG_CMD_SNTP


/*
 * Miscellaneous configurable options
 */

#define CONFIG_LZMA

#define CONFIG_SYS_LONGHELP				/* undef to save memory */
#ifndef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT		"=> "		/* Monitor Command Prompt */
#endif
#define CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)  /* Print Buffer Size */
#define CONFIG_SYS_MAXARGS		16		/* max number of command args */

#define CONFIG_SYS_MALLOC_LEN		(1 << 20)
#define CONFIG_SYS_BOOTPARAMS_LEN	(128 << 10)

#define CONFIG_SYS_MIPS_TIMER_FREQ	(get_cpuclk()/2)
#define CONFIG_SYS_HZ			1000

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_LOAD_ADDR		0x80100000	/* default load address	*/
#define CONFIG_SYS_MEMTEST_START	0x80100000
#define CONFIG_SYS_MEMTEST_END		0x80800000

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

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CONFIG_SYS_MAX_FLASH_SECT	(140)	/* max number of sectors on one chip */

#define PHYS_FLASH_1			0xB0000000 /* Flash Bank #1 */
#define PHYS_FLASH_2			0xB0800000 /* Flash Bank #2 */

/* The following #defines are needed to get flash environment right */
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_MONITOR_LEN		(192 << 10)

#define CONFIG_SYS_INIT_SP_OFFSET	0x400000

#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_IS_IN_FLASH

/* Address and size of Primary Environment Sector	*/
#define CONFIG_ENV_ADDR			0xB0040000
#ifdef CONFIG_EMULATION
#define CONFIG_ENV_SIZE			0x10
#else
#define CONFIG_ENV_SIZE			0x10000
#endif

#ifdef CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#define CONFIG_FLASH_SHOW_PROGRESS	45
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT
#define CONFIG_CFI_FLASH_USE_WEAK_ACCESSORS
#endif

#ifdef CONFIG_SYS_EBU_BOOT
#ifndef INFINEON_EBU_BOOTCFG
#error Please define INFINEON_EBU_BOOTCFG
#endif
#endif

#endif /* __IFX_COMMON_H */
