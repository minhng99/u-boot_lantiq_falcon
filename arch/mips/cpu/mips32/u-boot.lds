/*
 * (C) Copyright 2003
 * Wolfgang Denk Engineering, <wd@denx.de>
 *
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH, <thomas.langer@lantiq.com>
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
OUTPUT_FORMAT("elf32-bigmips", "elf32-bigmips", "elf32-bigmips")
*/
OUTPUT_FORMAT("elf32-tradbigmips", "elf32-tradbigmips", "elf32-tradlittlemips")
OUTPUT_ARCH(mips)
ENTRY(_start)
SECTIONS
{
	. = 0x00000000;

	. = ALIGN(4);
	.text       :
	{
	  *(.text*)
	}

	. = ALIGN(4);
	.rodata : {
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*)))
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(.data.rel.ro.*)))
	}

	. = ALIGN(4);
	.data :
	{
		*(SORT_BY_ALIGNMENT(.data*))
		*(SORT_BY_ALIGNMENT(.sdata*))
	}

	. = .;
	_gp = ALIGN(16);

	.got : {
	  __got_start = .;
	  *(.got)
	  __got_end = .;
	}
	num_got_entries = (__got_end - __got_start) >> 2;

	. = ALIGN(4);

	.u_boot_cmd : {
	  __u_boot_cmd_start = .;
	  *(.u_boot_cmd)
	  __u_boot_cmd_end = .;
	}

	uboot_end_data = .;

	. = ALIGN(4);
	.rel.dyn : {
		__rel_dyn_start = .;
		*(.rel*)
		__rel_dyn_end = .;
	}

	.dynsym : {
		__dynsym_start = .;
		*(.dynsym)
	}

	.bss __rel_dyn_start (OVERLAY)  : {
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(.sbss*)))
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(.bss*)))
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(.scommon*)))
		*(SORT_BY_ALIGNMENT(SORT_BY_NAME(COMMON*)))
	}

	. = ALIGN(4);
	uboot_end = .;

	/DISCARD/ : { *(.dynstr*) }
	/DISCARD/ : { *(.dynamic*) }
	/DISCARD/ : { *(.hash*) }
	/DISCARD/ : { *(.plt*) }
	/DISCARD/ : { *(.interp*) }
	/DISCARD/ : { *(.gnu*) }
	/DISCARD/ : { *(.reginfo*) }
}
