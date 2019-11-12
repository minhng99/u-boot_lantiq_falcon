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

/* Falcon Evaluation Board */
#define CONFIG_EASY98000

/*
 * environment definitions for automatic boot per network
 */
#define ENV_IMAGENAME "image_name=falcon-sysimage\0"

#define ENV_LOAD_KERNEL "load_kernel=tftp ${ram_addr} ${tftppath}${image_name}.img\0"

#define CONFIG_PREBOOT "dhcp"

#define ENV_NET_BOOT \
	"autoload=no\0" \
	"netboot=run load_kernel addmisc;bootm ${ram_addr}\0"

#define CONFIG_BOOTCOMMAND "run netboot"

/* only one second for autoboot */
#define CONFIG_BOOTDELAY	1

#include "configs/easy980x0.h"
