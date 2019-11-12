/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _sbs0ctrl_reg_h
#define _sbs0ctrl_reg_h

/** \addtogroup SBS0CTRL_REGISTER
   @{
*/
/* access macros */
#define sbs0ctrl_r32(reg) reg_r32(&sbs0ctrl->reg)
#define sbs0ctrl_w32(val, reg) reg_w32(val, &sbs0ctrl->reg)
#define sbs0ctrl_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &sbs0ctrl->reg)
#define sbs0ctrl_r32_table(reg, idx) reg_r32_table(sbs0ctrl->reg, idx)
#define sbs0ctrl_w32_table(val, reg, idx) reg_w32_table(val, sbs0ctrl->reg, idx)
#define sbs0ctrl_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, sbs0ctrl->reg, idx)
#define sbs0ctrl_adr_table(reg, idx) adr_table(sbs0ctrl->reg, idx)


/** SBS0CTRL register structure */
struct gpon_reg_sbs0ctrl
{
   /** Border Address Register 0
       The border address defines the first RAM address of master port 1. Master port 0 reaches to this border address - 1. */
   unsigned int bar0; /* 0x00000000 */
   /** Reserved */
   unsigned int res_0; /* 0x00000004 */
   /** Border Address Register 1
       The border address defines the first RAM address of master port 2. Master port 1 reaches to this border address - 1. */
   unsigned int bar1; /* 0x00000008 */
   /** Reserved */
   unsigned int res_1; /* 0x0000000C */
   /** GPHY0 Image Start Address */
   unsigned int gphy0img; /* 0x00000010 */
   /** Reserved */
   unsigned int res_2; /* 0x00000014 */
   /** GPHY1 Image Start Address */
   unsigned int gphy1img; /* 0x00000018 */
   /** Reserved */
   unsigned int res_3; /* 0x0000001C */
   /** Control bits for memory access modes */
   unsigned int mctrl; /* 0x00000020 */
   /** Reserved */
   unsigned int res_4[119]; /* 0x00000024 */
};


/* Fields of "Border Address Register 0" */
/** Border Address 0 Invariant MSBs
    The invariant MSBs of the Border Address 0. */
#define SBS0CTRL_BAR0_BA0IH_MASK 0x00380000
/** field offset */
#define SBS0CTRL_BAR0_BA0IH_OFFSET 19
/** Border Address 0 Variable MSBs
    The variable MSBs of the Border Address 0. Values larger than 8 are limited to 8. */
#define SBS0CTRL_BAR0_BA0V_MASK 0x00078000
/** field offset */
#define SBS0CTRL_BAR0_BA0V_OFFSET 15
/** Border Address 0 Invariant LSBs
    The invariant LSBs of the Border Address 0. The width matches the physical size of the RAM. */
#define SBS0CTRL_BAR0_BA0IL_MASK 0x00007FFF
/** field offset */
#define SBS0CTRL_BAR0_BA0IL_OFFSET 0

/* Fields of "Border Address Register 1" */
/** Border Address 1 Invariant MSBs
    The invariant MSBs of the Border Address 1. */
#define SBS0CTRL_BAR1_BA1IH_MASK 0x00380000
/** field offset */
#define SBS0CTRL_BAR1_BA1IH_OFFSET 19
/** Border Address 1 Variable MSBs
    The variable MSBs of the Border Address 1. Values larger than 8 are limited to 8. */
#define SBS0CTRL_BAR1_BA1V_MASK 0x00078000
/** field offset */
#define SBS0CTRL_BAR1_BA1V_OFFSET 15
/** Border Address 1 Invariant LSBs
    The invariant LSBs of the Border Address 1. The width matches the physical size of the RAM. */
#define SBS0CTRL_BAR1_BA1IL_MASK 0x00007FFF
/** field offset */
#define SBS0CTRL_BAR1_BA1IL_OFFSET 0

/* Fields of "GPHY0 Image Start Address" */
/** GPHY Image Start Address Variable MSBs
    The image for the GPHY starts at this memory address (variable part). */
#define SBS0CTRL_GPHY0IMG_ADDRV_MASK 0x003FC000
/** field offset */
#define SBS0CTRL_GPHY0IMG_ADDRV_OFFSET 14
/** GPHY Image Start Address Invariant LSBs
    The image for the GPHY starts at this memory address (invariant part). */
#define SBS0CTRL_GPHY0IMG_ADDRI_MASK 0x00003FFF
/** field offset */
#define SBS0CTRL_GPHY0IMG_ADDRI_OFFSET 0

/* Fields of "GPHY1 Image Start Address" */
/** GPHY Image Start Address Variable MSBs
    The image for the GPHY starts at this memory address (variable part). */
#define SBS0CTRL_GPHY1IMG_ADDRV_MASK 0x003FC000
/** field offset */
#define SBS0CTRL_GPHY1IMG_ADDRV_OFFSET 14
/** GPHY Image Start Address Invariant LSBs
    The image for the GPHY starts at this memory address (invariant part). */
#define SBS0CTRL_GPHY1IMG_ADDRI_MASK 0x00003FFF
/** field offset */
#define SBS0CTRL_GPHY1IMG_ADDRI_OFFSET 0

/* Fields of "Control bits for memory access modes" */
/** Descrambling enable/disable
    control of address and data descrambling for internal memory test. */
#define SBS0CTRL_MCTRL_DSC 0x00000001
/* Disable
#define SBS0CTRL_MCTRL_DSC_DIS 0x00000000 */
/** Enable */
#define SBS0CTRL_MCTRL_DSC_EN 0x00000001

/*! @} */ /* SBS0CTRL_REGISTER */

#endif /* _sbs0ctrl_reg_h */
