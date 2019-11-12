/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file "LICENSE" in the root folder of
  this software module.

******************************************************************************/
/**
   \file falcon_resource.h
*/
#ifndef _falcon_resource_h
#define _falcon_resource_h

/** \defgroup GPON_IMPLEMENTATION GPON Modem Implementation
    This chapter provides details of the hardware-related implementation.
@{
*/

/** \defgroup GPON_RESOURCE FALCON Gpon Modem Hardware and Software Resources
    This chapter defines values that are related to the FALCON hardware and
    software.
@{
*/

/**
   This file holds the definitions that are provided to reflect the available
   resources and other limit values that are related to the implementation.
   \remark Changing of any of these values will lead to system malfunction if
           the hardware does not support the assigned value(s)!
*/

/** Number of Ethernet UNI ports */
#define ONU_GPE_MAX_ETH_UNI                  4

/** Maximum Ethernet frame size that is supported by hardware.
    The value is given in number of bytes.
    9990 byte is the hardware limit of the on-chip PHYs.
    A smaller value (such as 1518) may be defined instead. */
#define FALCON_MAX_ETHERNET_FRAME_LENGTH 2047

/*! @} */

/* end ONU_RESOURCE */

/*! @} */

#endif
