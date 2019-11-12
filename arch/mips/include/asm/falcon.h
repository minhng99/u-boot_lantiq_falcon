/*
 * (C) Copyright 2011 Lantiq Deutschland GmbH, http://www.lantiq.com
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

extern phys_size_t falcon_ddr_init(void);
extern void print_chip_info(void);
extern void falcon_early_init_f(void);
extern void falcon_misc_init_r(void);
extern void falcon_extphy_enable(int enable);
extern void load_default_ethaddr(void);
extern void falcon_dcdc_core_set_voltage(unsigned int voltage);
extern int falcon_dcdc_core_init(unsigned int voltage);
extern int falcon_dcdc_ddr_init(unsigned int voltage);

