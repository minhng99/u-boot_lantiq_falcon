/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#ifndef _falcon_register_h
#define _falcon_register_h

/* exclude some parts from SWIG generation */
#ifndef SWIG

EXTERN_C_BEGIN

/** \addtogroup MAPI_REFERENCE_INTERNAL
   @{
*/

/*! \defgroup ONU_REGISTER_INTERNAL Device Register Access
   @{
*/

#include <asm/io.h>

#include "falcon_std_defs.h"
#include <asm/arch/gpon_reg_base.h>
#include <asm/arch/sys_eth_reg.h>

#include "fsqm_reg.h"
#include "gpearb_reg.h"
#include "iqm_reg.h"
#include "eim_reg.h"
#include "ictrll_reg.h"
#include "octrll_reg.h"
#include "sbs0ctrl_reg.h"
#include "sgmii_reg.h"
#include "sxgmii_reg.h"

/** Read value of register

   \param reg  register address
   \return register contents
*/
#define reg_r32(reg) readl(reg)

/** Write value to register

   \param val  register value
   \param reg  register address
*/
#define reg_w32(val, reg) writel(val, reg)

/** Clear / set bits within a register

   \param clear   clear mask
   \param set     set mask
   \param reg     register address
*/
#define reg_w32_mask(clear, set, reg) reg_w32((reg_r32(reg) & ~(clear)) | (set), reg)


#define set_val(reg, val, mask, offset) do {(reg) |= (((val) << (offset)) & (mask)); } while(0)

/*! @} */
/*! @} */

EXTERN_C_END

#endif /* SWIG */

#endif
