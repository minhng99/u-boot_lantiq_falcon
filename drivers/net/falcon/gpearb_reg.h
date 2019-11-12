/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _gpearb_reg_h
#define _gpearb_reg_h

/** \addtogroup GPEARB_REGISTER
   @{
*/
/* access macros */
#define gpearb_r32(reg) reg_r32(&gpearb->reg)
#define gpearb_w32(val, reg) reg_w32(val, &gpearb->reg)
#define gpearb_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &gpearb->reg)
#define gpearb_r32_table(reg, idx) reg_r32_table(gpearb->reg, idx)
#define gpearb_w32_table(val, reg, idx) reg_w32_table(val, gpearb->reg, idx)
#define gpearb_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, gpearb->reg, idx)
#define gpearb_adr_table(reg, idx) adr_table(gpearb->reg, idx)


/** GPEARB register structure */
struct gpon_reg_gpearb
{
   /** Counter Period Register
       The TDM Arbiter is counting continuously from 0 up to the programmed PERIOD value. */
   unsigned int cntr; /* 0x00000000 */
   /** Port ID Registers
       Within the 16 PID Register the bandwidth is assigned to the connected modules. */
   unsigned int pid[16]; /* 0x00000004 */
   /** Downstream Counter Control Register
       Downstream: Arbiter - MEM */
   unsigned int dscntctrl; /* 0x00000044 */
   /** Total Downstream Counter
       The Counter is metering the total number of downstream accesses. */
   unsigned int dstcnt; /* 0x00000048 */
   /** Downstream Counter for selected ID
       The Counter is metering the downstream accesses for DSCNTCTRL.DSCNTID. */
   unsigned int dscnt; /* 0x0000004C */
   /** Upstream Counter Control Register
       Upstream: MEM - Arbiter */
   unsigned int uscntctrl; /* 0x00000050 */
   /** Total Upstream Counter
       The Counter is metering the total number of upstream accesses. */
   unsigned int ustcnt; /* 0x00000054 */
   /** Upstream Counter for selected ID
       The Counter is metering the upstream accesses for USCNTCTRL.USCNTID. */
   unsigned int uscnt; /* 0x00000058 */
   /** Reserved */
   unsigned int res_0[41]; /* 0x0000005C */
};


/* Fields of "Counter Period Register" */
/** TDM Arbiter Counter Period
    This is the period for the TDM arbitration. */
#define GPEARB_CNTR_PERIOD_MASK 0x0000003F
/** field offset */
#define GPEARB_CNTR_PERIOD_OFFSET 0

/* Fields of "Port ID Register 0" */
/** ID for TDM timeslot 3
    This ID defines the Module which is arbitrated in timeslot 3. */
#define GPEARB_PID0_ID3_MASK 0x0F000000
/** field offset */
#define GPEARB_PID0_ID3_OFFSET 24
/** ID for TDM timeslot 2
    This ID defines the Module which is arbitrated in timeslot 2. */
#define GPEARB_PID0_ID2_MASK 0x000F0000
/** field offset */
#define GPEARB_PID0_ID2_OFFSET 16
/** ID for TDM timeslot 1
    This ID defines the Module which is arbitrated in timeslot 1. */
#define GPEARB_PID0_ID1_MASK 0x00000F00
/** field offset */
#define GPEARB_PID0_ID1_OFFSET 8
/** ID for TDM timeslot 0
    This ID defines the Module which is arbitrated in timeslot 0. */
#define GPEARB_PID0_ID0_MASK 0x0000000F
/** field offset */
#define GPEARB_PID0_ID0_OFFSET 0

/* Fields of "Port ID Register 1" */
/** ID for TDM timeslot 7
    This ID defines the Module which is arbitrated in timeslot 7. */
#define GPEARB_PID1_ID7_MASK 0x0F000000
/** field offset */
#define GPEARB_PID1_ID7_OFFSET 24
/** ID for TDM timeslot 6
    This ID defines the Module which is arbitrated in timeslot 6. */
#define GPEARB_PID1_ID6_MASK 0x000F0000
/** field offset */
#define GPEARB_PID1_ID6_OFFSET 16
/** ID for TDM timeslot 5
    This ID defines the Module which is arbitrated in timeslot 5. */
#define GPEARB_PID1_ID5_MASK 0x00000F00
/** field offset */
#define GPEARB_PID1_ID5_OFFSET 8
/** ID for TDM timeslot 4
    This ID defines the Module which is arbitrated in timeslot 4. */
#define GPEARB_PID1_ID4_MASK 0x0000000F
/** field offset */
#define GPEARB_PID1_ID4_OFFSET 0

/* Fields of "Port ID Register 2" */
/** ID for TDM timeslot 11
    This ID defines the Module which is arbitrated in timeslot 11. */
#define GPEARB_PID2_ID11_MASK 0x0F000000
/** field offset */
#define GPEARB_PID2_ID11_OFFSET 24
/** ID for TDM timeslot 10
    This ID defines the Module which is arbitrated in timeslot 10. */
#define GPEARB_PID2_ID10_MASK 0x000F0000
/** field offset */
#define GPEARB_PID2_ID10_OFFSET 16
/** ID for TDM timeslot 9
    This ID defines the Module which is arbitrated in timeslot 9. */
#define GPEARB_PID2_ID9_MASK 0x00000F00
/** field offset */
#define GPEARB_PID2_ID9_OFFSET 8
/** ID for TDM timeslot 8
    This ID defines the Module which is arbitrated in timeslot 8. */
#define GPEARB_PID2_ID8_MASK 0x0000000F
/** field offset */
#define GPEARB_PID2_ID8_OFFSET 0

/* Fields of "Port ID Register 3" */
/** ID for TDM timeslot 15
    This ID defines the Module which is arbitrated in timeslot 15. */
#define GPEARB_PID3_ID15_MASK 0x0F000000
/** field offset */
#define GPEARB_PID3_ID15_OFFSET 24
/** ID for TDM timeslot 14
    This ID defines the Module which is arbitrated in timeslot 14. */
#define GPEARB_PID3_ID14_MASK 0x000F0000
/** field offset */
#define GPEARB_PID3_ID14_OFFSET 16
/** ID for TDM timeslot 13
    This ID defines the Module which is arbitrated in timeslot 13. */
#define GPEARB_PID3_ID13_MASK 0x00000F00
/** field offset */
#define GPEARB_PID3_ID13_OFFSET 8
/** ID for TDM timeslot 12
    This ID defines the Module which is arbitrated in timeslot 12. */
#define GPEARB_PID3_ID12_MASK 0x0000000F
/** field offset */
#define GPEARB_PID3_ID12_OFFSET 0

/* Fields of "Port ID Register 4" */
/** ID for TDM timeslot 19
    This ID defines the Module which is arbitrated in timeslot 19. */
#define GPEARB_PID4_ID19_MASK 0x0F000000
/** field offset */
#define GPEARB_PID4_ID19_OFFSET 24
/** ID for TDM timeslot 18
    This ID defines the Module which is arbitrated in timeslot 18. */
#define GPEARB_PID4_ID18_MASK 0x000F0000
/** field offset */
#define GPEARB_PID4_ID18_OFFSET 16
/** ID for TDM timeslot 17
    This ID defines the Module which is arbitrated in timeslot 17. */
#define GPEARB_PID4_ID17_MASK 0x00000F00
/** field offset */
#define GPEARB_PID4_ID17_OFFSET 8
/** ID for TDM timeslot 16
    This ID defines the Module which is arbitrated in timeslot 16. */
#define GPEARB_PID4_ID16_MASK 0x0000000F
/** field offset */
#define GPEARB_PID4_ID16_OFFSET 0

/* Fields of "Port ID Register 5" */
/** ID for TDM timeslot 23
    This ID defines the Module which is arbitrated in timeslot 23. */
#define GPEARB_PID5_ID23_MASK 0x0F000000
/** field offset */
#define GPEARB_PID5_ID23_OFFSET 24
/** ID for TDM timeslot 22
    This ID defines the Module which is arbitrated in timeslot 22. */
#define GPEARB_PID5_ID22_MASK 0x000F0000
/** field offset */
#define GPEARB_PID5_ID22_OFFSET 16
/** ID for TDM timeslot 21
    This ID defines the Module which is arbitrated in timeslot 21. */
#define GPEARB_PID5_ID21_MASK 0x00000F00
/** field offset */
#define GPEARB_PID5_ID21_OFFSET 8
/** ID for TDM timeslot 20
    This ID defines the Module which is arbitrated in timeslot 20. */
#define GPEARB_PID5_ID20_MASK 0x0000000F
/** field offset */
#define GPEARB_PID5_ID20_OFFSET 0

/* Fields of "Port ID Register 6" */
/** ID for TDM timeslot 27
    This ID defines the Module which is arbitrated in timeslot 27. */
#define GPEARB_PID6_ID27_MASK 0x0F000000
/** field offset */
#define GPEARB_PID6_ID27_OFFSET 24
/** ID for TDM timeslot 26
    This ID defines the Module which is arbitrated in timeslot 26. */
#define GPEARB_PID6_ID26_MASK 0x000F0000
/** field offset */
#define GPEARB_PID6_ID26_OFFSET 16
/** ID for TDM timeslot 25
    This ID defines the Module which is arbitrated in timeslot 25. */
#define GPEARB_PID6_ID25_MASK 0x00000F00
/** field offset */
#define GPEARB_PID6_ID25_OFFSET 8
/** ID for TDM timeslot 24
    This ID defines the Module which is arbitrated in timeslot 24. */
#define GPEARB_PID6_ID24_MASK 0x0000000F
/** field offset */
#define GPEARB_PID6_ID24_OFFSET 0

/* Fields of "Port ID Register 7" */
/** ID for TDM timeslot 31
    This ID defines the Module which is arbitrated in timeslot 31. */
#define GPEARB_PID7_ID31_MASK 0x0F000000
/** field offset */
#define GPEARB_PID7_ID31_OFFSET 24
/** ID for TDM timeslot 30
    This ID defines the Module which is arbitrated in timeslot 30. */
#define GPEARB_PID7_ID30_MASK 0x000F0000
/** field offset */
#define GPEARB_PID7_ID30_OFFSET 16
/** ID for TDM timeslot 29
    This ID defines the Module which is arbitrated in timeslot 29. */
#define GPEARB_PID7_ID29_MASK 0x00000F00
/** field offset */
#define GPEARB_PID7_ID29_OFFSET 8
/** ID for TDM timeslot 28
    This ID defines the Module which is arbitrated in timeslot 28. */
#define GPEARB_PID7_ID28_MASK 0x0000000F
/** field offset */
#define GPEARB_PID7_ID28_OFFSET 0

/* Fields of "Port ID Register 8" */
/** ID for TDM timeslot 35
    This ID defines the Module which is arbitrated in timeslot 35. */
#define GPEARB_PID8_ID35_MASK 0x0F000000
/** field offset */
#define GPEARB_PID8_ID35_OFFSET 24
/** ID for TDM timeslot 34
    This ID defines the Module which is arbitrated in timeslot 34. */
#define GPEARB_PID8_ID34_MASK 0x000F0000
/** field offset */
#define GPEARB_PID8_ID34_OFFSET 16
/** ID for TDM timeslot 33
    This ID defines the Module which is arbitrated in timeslot 33. */
#define GPEARB_PID8_ID33_MASK 0x00000F00
/** field offset */
#define GPEARB_PID8_ID33_OFFSET 8
/** ID for TDM timeslot 32
    This ID defines the Module which is arbitrated in timeslot 32. */
#define GPEARB_PID8_ID32_MASK 0x0000000F
/** field offset */
#define GPEARB_PID8_ID32_OFFSET 0

/* Fields of "Port ID Register 9" */
/** ID for TDM timeslot 39
    This ID defines the Module which is arbitrated in timeslot 39. */
#define GPEARB_PID9_ID39_MASK 0x0F000000
/** field offset */
#define GPEARB_PID9_ID39_OFFSET 24
/** ID for TDM timeslot 38
    This ID defines the Module which is arbitrated in timeslot 38. */
#define GPEARB_PID9_ID38_MASK 0x000F0000
/** field offset */
#define GPEARB_PID9_ID38_OFFSET 16
/** ID for TDM timeslot 37
    This ID defines the Module which is arbitrated in timeslot 37. */
#define GPEARB_PID9_ID37_MASK 0x00000F00
/** field offset */
#define GPEARB_PID9_ID37_OFFSET 8
/** ID for TDM timeslot 36
    This ID defines the Module which is arbitrated in timeslot 36. */
#define GPEARB_PID9_ID36_MASK 0x0000000F
/** field offset */
#define GPEARB_PID9_ID36_OFFSET 0

/* Fields of "Port ID Register 10" */
/** ID for TDM timeslot 43
    This ID defines the Module which is arbitrated in timeslot 43. */
#define GPEARB_PID10_ID43_MASK 0x0F000000
/** field offset */
#define GPEARB_PID10_ID43_OFFSET 24
/** ID for TDM timeslot 42
    This ID defines the Module which is arbitrated in timeslot 42. */
#define GPEARB_PID10_ID42_MASK 0x000F0000
/** field offset */
#define GPEARB_PID10_ID42_OFFSET 16
/** ID for TDM timeslot 41
    This ID defines the Module which is arbitrated in timeslot 41. */
#define GPEARB_PID10_ID41_MASK 0x00000F00
/** field offset */
#define GPEARB_PID10_ID41_OFFSET 8
/** ID for TDM timeslot 40
    This ID defines the Module which is arbitrated in timeslot 40. */
#define GPEARB_PID10_ID40_MASK 0x0000000F
/** field offset */
#define GPEARB_PID10_ID40_OFFSET 0

/* Fields of "Port ID Register 11" */
/** ID for TDM timeslot 47
    This ID defines the Module which is arbitrated in timeslot 47. */
#define GPEARB_PID11_ID47_MASK 0x0F000000
/** field offset */
#define GPEARB_PID11_ID47_OFFSET 24
/** ID for TDM timeslot 46
    This ID defines the Module which is arbitrated in timeslot 46. */
#define GPEARB_PID11_ID46_MASK 0x000F0000
/** field offset */
#define GPEARB_PID11_ID46_OFFSET 16
/** ID for TDM timeslot 45
    This ID defines the Module which is arbitrated in timeslot 45. */
#define GPEARB_PID11_ID45_MASK 0x00000F00
/** field offset */
#define GPEARB_PID11_ID45_OFFSET 8
/** ID for TDM timeslot 44
    This ID defines the Module which is arbitrated in timeslot 44. */
#define GPEARB_PID11_ID44_MASK 0x0000000F
/** field offset */
#define GPEARB_PID11_ID44_OFFSET 0

/* Fields of "Port ID Register 12" */
/** ID for TDM timeslot 51
    This ID defines the Module which is arbitrated in timeslot 51. */
#define GPEARB_PID12_ID51_MASK 0x0F000000
/** field offset */
#define GPEARB_PID12_ID51_OFFSET 24
/** ID for TDM timeslot 50
    This ID defines the Module which is arbitrated in timeslot 50. */
#define GPEARB_PID12_ID50_MASK 0x000F0000
/** field offset */
#define GPEARB_PID12_ID50_OFFSET 16
/** ID for TDM timeslot 49
    This ID defines the Module which is arbitrated in timeslot 49. */
#define GPEARB_PID12_ID49_MASK 0x00000F00
/** field offset */
#define GPEARB_PID12_ID49_OFFSET 8
/** ID for TDM timeslot 48
    This ID defines the Module which is arbitrated in timeslot 48. */
#define GPEARB_PID12_ID48_MASK 0x0000000F
/** field offset */
#define GPEARB_PID12_ID48_OFFSET 0

/* Fields of "Port ID Register 13" */
/** ID for TDM timeslot 55
    This ID defines the Module which is arbitrated in timeslot 55. */
#define GPEARB_PID13_ID55_MASK 0x0F000000
/** field offset */
#define GPEARB_PID13_ID55_OFFSET 24
/** ID for TDM timeslot 54
    This ID defines the Module which is arbitrated in timeslot 54. */
#define GPEARB_PID13_ID54_MASK 0x000F0000
/** field offset */
#define GPEARB_PID13_ID54_OFFSET 16
/** ID for TDM timeslot 53
    This ID defines the Module which is arbitrated in timeslot 53. */
#define GPEARB_PID13_ID53_MASK 0x00000F00
/** field offset */
#define GPEARB_PID13_ID53_OFFSET 8
/** ID for TDM timeslot 52
    This ID defines the Module which is arbitrated in timeslot 52. */
#define GPEARB_PID13_ID52_MASK 0x0000000F
/** field offset */
#define GPEARB_PID13_ID52_OFFSET 0

/* Fields of "Port ID Register 14" */
/** ID for TDM timeslot 59
    This ID defines the Module which is arbitrated in timeslot 59. */
#define GPEARB_PID14_ID59_MASK 0x0F000000
/** field offset */
#define GPEARB_PID14_ID59_OFFSET 24
/** ID for TDM timeslot 58
    This ID defines the Module which is arbitrated in timeslot 58. */
#define GPEARB_PID14_ID58_MASK 0x000F0000
/** field offset */
#define GPEARB_PID14_ID58_OFFSET 16
/** ID for TDM timeslot 57
    This ID defines the Module which is arbitrated in timeslot 57. */
#define GPEARB_PID14_ID57_MASK 0x00000F00
/** field offset */
#define GPEARB_PID14_ID57_OFFSET 8
/** ID for TDM timeslot 56
    This ID defines the Module which is arbitrated in timeslot 56. */
#define GPEARB_PID14_ID56_MASK 0x0000000F
/** field offset */
#define GPEARB_PID14_ID56_OFFSET 0

/* Fields of "Port ID Register 15" */
/** ID for TDM timeslot 63
    This ID defines the Module which is arbitrated in timeslot 63. */
#define GPEARB_PID15_ID63_MASK 0x0F000000
/** field offset */
#define GPEARB_PID15_ID63_OFFSET 24
/** ID for TDM timeslot 62
    This ID defines the Module which is arbitrated in timeslot 62. */
#define GPEARB_PID15_ID62_MASK 0x000F0000
/** field offset */
#define GPEARB_PID15_ID62_OFFSET 16
/** ID for TDM timeslot 61
    This ID defines the Module which is arbitrated in timeslot 61. */
#define GPEARB_PID15_ID61_MASK 0x00000F00
/** field offset */
#define GPEARB_PID15_ID61_OFFSET 8
/** ID for TDM timeslot 60
    This ID defines the Module which is arbitrated in timeslot 60. */
#define GPEARB_PID15_ID60_MASK 0x0000000F
/** field offset */
#define GPEARB_PID15_ID60_OFFSET 0

/* Fields of "Downstream Counter Control Register" */
/** ID for DSCNT
    This ID defines the Module for DSCNT. */
#define GPEARB_DSCNTCTRL_DSCNTID_MASK 0x000F0000
/** field offset */
#define GPEARB_DSCNTCTRL_DSCNTID_OFFSET 16
/** DSCNT Enable
    Enable Downstream Counter for DSCNTID. */
#define GPEARB_DSCNTCTRL_DSCNTEN 0x00000002
/* Disable
#define GPEARB_DSCNTCTRL_DSCNTEN_DIS 0x00000000 */
/** Enable */
#define GPEARB_DSCNTCTRL_DSCNTEN_EN 0x00000002
/** DSTCNT Enable
    Total Downstream Counter enable. */
#define GPEARB_DSCNTCTRL_DSTCNTEN 0x00000001
/* Disable
#define GPEARB_DSCNTCTRL_DSTCNTEN_DIS 0x00000000 */
/** Enable */
#define GPEARB_DSCNTCTRL_DSTCNTEN_EN 0x00000001

/* Fields of "Total Downstream Counter" */
/** Counter Value */
#define GPEARB_DSTCNT_CNT_MASK 0x0000FFFF
/** field offset */
#define GPEARB_DSTCNT_CNT_OFFSET 0

/* Fields of "Downstream Counter for selected ID" */
/** Counter Value */
#define GPEARB_DSCNT_CNT_MASK 0x0000FFFF
/** field offset */
#define GPEARB_DSCNT_CNT_OFFSET 0

/* Fields of "Upstream Counter Control Register" */
/** ID for USCNT
    This ID defines the Module for USCNT. */
#define GPEARB_USCNTCTRL_USCNTID_MASK 0x000F0000
/** field offset */
#define GPEARB_USCNTCTRL_USCNTID_OFFSET 16
/** USCNT Enable
    Enable Upstream Counter for USCNTID */
#define GPEARB_USCNTCTRL_USCNTEN 0x00000002
/* Disable
#define GPEARB_USCNTCTRL_USCNTEN_DIS 0x00000000 */
/** Enable */
#define GPEARB_USCNTCTRL_USCNTEN_EN 0x00000002
/** USTCNT Enabel
    Total Upstream Counter enable. */
#define GPEARB_USCNTCTRL_USTCNTEN 0x00000001
/* Disable
#define GPEARB_USCNTCTRL_USTCNTEN_DIS 0x00000000 */
/** Enable */
#define GPEARB_USCNTCTRL_USTCNTEN_EN 0x00000001

/* Fields of "Total Upstream Counter" */
/** Counter Value */
#define GPEARB_USTCNT_CNT_MASK 0x0000FFFF
/** field offset */
#define GPEARB_USTCNT_CNT_OFFSET 0

/* Fields of "Upstream Counter for selected ID" */
/** Counter Value */
#define GPEARB_USCNT_CNT_MASK 0x0000FFFF
/** field offset */
#define GPEARB_USCNT_CNT_OFFSET 0

/*! @} */ /* GPEARB_REGISTER */

#endif /* _gpearb_reg_h */
