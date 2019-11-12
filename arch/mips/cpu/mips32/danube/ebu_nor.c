/*
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH, http://www.lantiq.com
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

#include <common.h>
#include <config.h>

#include <asm/io.h>

static inline void *flash_fixup_addr(void *addr)
{
	void *fix_addr = ((void *)((ulong) (addr) ^ 2));
	return fix_addr;
}

/*
 * Accessor functions replacing the "weak" functions in
 * drivers/mtd/cfi_flash.c
 */
void flash_write8(u8 value, void *addr)
{
	__raw_writeb(value, flash_fixup_addr(addr));
}
void flash_write8_data(u8 value, void *addr)
{
	__raw_writeb(value, addr);
}
void flash_write16(u16 value, void *addr)
{
	__raw_writew(value, flash_fixup_addr(addr));
}
void flash_write16_data(u16 value, void *addr)
{
	__raw_writew(value, addr);
}
u8 flash_read8(void *addr)
{
	return __raw_readb(flash_fixup_addr(addr));
}
u8 flash_read8_data(void *addr)
{
	return __raw_readb(addr);
}
u16 flash_read16(void *addr)
{
	return __raw_readw(flash_fixup_addr(addr));
}
u16 flash_read16_data(void *addr)
{
	return __raw_readw(addr);
}
