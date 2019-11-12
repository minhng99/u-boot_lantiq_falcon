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

#ifndef __FALCON_HW_H
#define __FALCON_HW_H

#include <asm/arch/gpon_reg_base.h>
#include <asm/arch/ebu_reg.h>
#include <asm/arch/sys1_reg.h>
#include <asm/arch/sys_eth_reg.h>
#include <asm/arch/sys_gpe_reg.h>
#include <asm/arch/status_reg.h>
#include <asm/arch/xbar_reg.h>

/* mapping to u-boot hw-accessor routines */
#define reg_r32(reg) readl(reg)
#define reg_w32(val, reg) writel(val, reg)
#define reg_w32_mask(clear, set, reg) reg_w32((reg_r32(reg) & ~(clear)) | (set), reg)

static struct gpon_reg_ebu * const ebu =
	(struct gpon_reg_ebu *)GPON_EBU_BASE;
static struct gpon_reg_sys1 * const sys1 =
	(struct gpon_reg_sys1 *)GPON_SYS1_BASE;
static struct gpon_reg_sys_eth * const sys_eth =
	(struct gpon_reg_sys_eth *)GPON_SYS_ETH_BASE;
static struct gpon_reg_sys_gpe * const sys_gpe =
	(struct gpon_reg_sys_gpe *)GPON_SYS_GPE_BASE;
static struct gpon_reg_status * const status =
	(struct gpon_reg_status *)GPON_STATUS_BASE;
static struct gpon_reg_xbar * const xbar =
	(struct gpon_reg_xbar *)GPON_XBAR_BASE;

static struct gpon_reg_boot {
	/* bootrom related virtual registers */
	unsigned int rvec;
	unsigned int nvec;
	unsigned int evec;
	unsigned int cp0_status;
	unsigned int cp0_epc;
	unsigned int cp0_eepc;
	unsigned int size;
	unsigned int cfg_stat;
	/* additional virtual registers */
	unsigned int magic0; /* magic for valid reboot */
	unsigned int magic1; /*  -"-  */
	unsigned int bcount; /* reboot counter, used by u-boot */
} * const boot_reg = (struct gpon_reg_boot *)GPON_SBS0RAM_BASE;

#if defined(CONFIG_FALCON_A1x) && defined(CONFIG_FALCON_A2x)
__attribute__((always_inline))
static inline const int falcon_version(void)
{
	return (status->chipid & STATUS_CHIPID_VERSION_MASK)
		>> STATUS_CHIPID_VERSION_OFFSET;
}
__attribute__((always_inline))
static inline const int is_falcon_chip_a1x(void) { return falcon_version() == 1; }
__attribute__((always_inline))
static inline const int is_falcon_chip_a2x(void) { return falcon_version() == 2; }
#else
#ifdef CONFIG_FALCON_A2x
static inline int is_falcon_chip_a1x(void) { return 0; }
static inline int is_falcon_chip_a2x(void) { return 1; }
#else
static inline int is_falcon_chip_a1x(void) { return 1; }
static inline int is_falcon_chip_a2x(void) { return 0; }
#endif
#endif

#define FALCON_D	(1<<0)
#define FALCON_V	(1<<1)
#define FALCON_M	(1<<2)
#define FALCON_S	(1<<3)

__attribute__((always_inline))
static inline u32 falcon_type(void)
{
	u32 fuse0 = status_r32(fuse0);
	u32 fuse0_f0 = (fuse0 & STATUS_FUSE0_F0_MASK)
		>> STATUS_FUSE0_F0_OFFSET;
	return 1 << fuse0_f0;
}

__attribute__((always_inline))
static inline int support_falcon_type(u32 type)
{
	return !!(falcon_type() & type);
}

#define IS_FALCON(func,def) \
__attribute__((always_inline)) static inline int func(void) \
				{ return support_falcon_type(def); }

IS_FALCON(is_falcon_d,FALCON_D)
IS_FALCON(is_falcon_v,FALCON_V)
IS_FALCON(is_falcon_m,FALCON_M)
IS_FALCON(is_falcon_s,FALCON_S)

#endif /* __FALCON_HW_H */
