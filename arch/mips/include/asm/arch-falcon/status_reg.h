/******************************************************************************

                               Copyright (c) 2012
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _status_reg_h
#define _status_reg_h

/** \addtogroup STATUS_REGISTER
   @{
*/
/* access macros */
#define status_r32(reg) reg_r32(&status->reg)
#define status_w32(val, reg) reg_w32(val, &status->reg)
#define status_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &status->reg)
#define status_r32_table(reg, idx) reg_r32_table(status->reg, idx)
#define status_w32_table(val, reg, idx) reg_w32_table(val, status->reg, idx)
#define status_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, status->reg, idx)
#define status_adr_table(reg, idx) adr_table(status->reg, idx)


/** STATUS register structure */
struct gpon_reg_status
{
   /** Reserved */
   unsigned int res_0[3]; /* 0x00000000 */
   /** Chip Identification Register */
   unsigned int chipid; /* 0x0000000C */
   /** Chip Location Register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int chiploc; /* 0x00000010 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red0; /* 0x00000014 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red1; /* 0x00000018 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red2; /* 0x0000001C */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red3; /* 0x00000020 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red4; /* 0x00000024 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red5; /* 0x00000028 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red6; /* 0x0000002C */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red7; /* 0x00000030 */
   /** Redundancy register
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int red8; /* 0x00000034 */
   /** SPARE fuse register 0
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int fuse0; /* 0x00000038 */
   /** Fuses for Analog modules
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int analog; /* 0x0000003C */
   /** Configuration fuses for drivers and pll
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int config; /* 0x00000040 */
   /** SPARE fuse register 1
       Note: All fuse-bits have a default value of 0 that can be changed to 1 during production test (unfused = 0, fused = 1).The reset-values stated for these bits is 0 even though SW will never be able to read 0 if it was set to 1 during production test. */
   unsigned int fuse1; /* 0x00000044 */
   /** Configuration for sbs0 rambist */
   unsigned int mbcfg; /* 0x00000048 */
   /** sbs0 bist result and debug data */
   unsigned int mbdata; /* 0x0000004C */
   /** Reserved */
   unsigned int res_1[12]; /* 0x00000050 */
};


/* Fields of "Chip Identification Register" */
/** Chip Version Number
    Version number is a constant field and can be changed by Redesign only. The chip version is coded by 3 characters XvY while v is the version, X = A,B,C and Y = 1,2,3 they will be coded in the CONFIG register field SUBVERS). */
#define STATUS_CHIPID_VERSION_MASK 0xF0000000
/** field offset */
#define STATUS_CHIPID_VERSION_OFFSET 28
/** Part Number, Constant Part
    The Part Number is fixed to 016Bhex. */
#define STATUS_CHIPID_PARTNR_MASK 0x0FFFF000
/** field offset */
#define STATUS_CHIPID_PARTNR_OFFSET 12
/** Manufacturer ID
    The value of bit field MANID is fixed to 41hex as configured in the JTAG ID register. The JEDEC normalized manufacturer code for Infineon Technologies is C1hex */
#define STATUS_CHIPID_MANID_MASK 0x00000FFE
/** field offset */
#define STATUS_CHIPID_MANID_OFFSET 1
/** Constant bit
    The value of bit field CONST1 is fixed to 1hex */
#define STATUS_CHIPID_CONST1 0x00000001

/* Fields of "Chip Location Register" */
/** Chip Lot ID */
#define STATUS_CHIPLOC_CHIPLOT_MASK 0xFFFF0000
/** field offset */
#define STATUS_CHIPLOC_CHIPLOT_OFFSET 16
/** Chip X Coordinate */
#define STATUS_CHIPLOC_CHIPX_MASK 0x0000FF00
/** field offset */
#define STATUS_CHIPLOC_CHIPX_OFFSET 8
/** Chip Y Coordinate */
#define STATUS_CHIPLOC_CHIPY_MASK 0x000000FF
/** field offset */
#define STATUS_CHIPLOC_CHIPY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED0_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED0_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED1_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED1_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED2_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED2_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED3_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED3_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED4_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED4_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED5_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED5_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED6_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED6_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED7_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED7_REDUNDANCY_OFFSET 0

/* Fields of "Redundancy register" */
/** Redundancy
    redundancy information stored in eFuses. MSB + MEM_ADDR - MSB = 1 defines a valid address */
#define STATUS_RED8_REDUNDANCY_MASK 0x0003FFFF
/** field offset */
#define STATUS_RED8_REDUNDANCY_OFFSET 0

/* Fields of "SPARE fuse register 0" */
/** Soft fuse control
    Controls whether the status block is in its softfused state or not. In the softfused state the values written via software are active effective. */
#define STATUS_FUSE0_SFC 0x80000000
/* Not selected
#define STATUS_FUSE0_SFC_NSEL 0x00000000 */
/** Selected */
#define STATUS_FUSE0_SFC_SEL 0x80000000
/** Soft control MBCFG
    Controls whether mbist configuration can be overwritten or not from subsystem. If not selected jtag mbcfg register is source for software mbist configuration */
#define STATUS_FUSE0_SC_MBCFG 0x40000000
/* Not selected
#define STATUS_FUSE0_SC_MBCFG_NSEL 0x00000000 */
/** Selected */
#define STATUS_FUSE0_SC_MBCFG_SEL 0x40000000
/** Device Type
    different device types are coded in this fuse field */
#define STATUS_FUSE0_F0_MASK 0x3C000000
/** field offset */
#define STATUS_FUSE0_F0_OFFSET 26
/** FALCOND */
#define STATUS_FUSE0_F0_FALCOND 0x00000000
/** FALCONV */
#define STATUS_FUSE0_F0_FALCONV 0x04000000
/** FALCONM */
#define STATUS_FUSE0_F0_FALCONM 0x08000000
/** SFP */
#define STATUS_FUSE0_F0_FALCONS 0x0C000000
/** all other codes reserved for future applications */
#define STATUS_FUSE0_F0_reserved 0x10000000
/** VCALMM20 Voltage Reference
    Voltage Reference for calibration via R and constant current (20 uA) */
#define STATUS_FUSE0_VCALMM20_MASK 0x03F00000
/** field offset */
#define STATUS_FUSE0_VCALMM20_OFFSET 20
/** VCALMM100 Voltage Reference
    Voltage Reference for calibration via R and constant current (100 uA) */
#define STATUS_FUSE0_VCALMM100_MASK 0x000FC000
/** field offset */
#define STATUS_FUSE0_VCALMM100_OFFSET 14
/** VCALMM400 Voltage Reference
    Voltage Reference for calibration via R and constant current (400 uA) */
#define STATUS_FUSE0_VCALMM400_MASK 0x00003F00
/** field offset */
#define STATUS_FUSE0_VCALMM400_OFFSET 8
/** RCALMM R error correction
    The resistance deviation from ideal R (1000 Ohm) */
#define STATUS_FUSE0_RCALMM_MASK 0x000000FF
/** field offset */
#define STATUS_FUSE0_RCALMM_OFFSET 0

/* Fields of "Fuses for Analog modules" */
/** Status of written FUSES
    Defines which Fuses are activated */
#define STATUS_ANALOG_FS_MASK 0xE0000000
/** field offset */
#define STATUS_ANALOG_FS_OFFSET 29
/** A11 format, only VBGP and IREFBGP fused, DRIVE and BIAS DAC - 4 bit */
#define STATUS_ANALOG_FS_FS0 0x00000000
/** new format, VBGP, IREFBGP, DRIVE dac (5bit) and BIAS dac (5bit) fused */
#define STATUS_ANALOG_FS_FS1 0x20000000
/** All other codes reserved for future applications */
#define STATUS_ANALOG_FS_FS2 0x40000000
/** reserved Analog eFuses
    Reserved Register contains information stored in eFuses needed for the analog modules */
#define STATUS_ANALOG_A0_MASK 0x1C000000
/** field offset */
#define STATUS_ANALOG_A0_OFFSET 26
/** Absolut Temperature
    Temperature ERROR */
#define STATUS_ANALOG_TEMPMM_MASK 0x03F00000
/** field offset */
#define STATUS_ANALOG_TEMPMM_OFFSET 20
/** Drive DAC Gain */
#define STATUS_ANALOG_GAINDRIVEDAC_MASK 0x000F8000
/** field offset */
#define STATUS_ANALOG_GAINDRIVEDAC_OFFSET 15
/** Bias Voltage Generation
    voltage dependency */
#define STATUS_ANALOG_VBGP_MASK 0x00007000
/** field offset */
#define STATUS_ANALOG_VBGP_OFFSET 12
/** Bias Current Generation */
#define STATUS_ANALOG_IREFBGP_MASK 0x00000F00
/** field offset */
#define STATUS_ANALOG_IREFBGP_OFFSET 8
/** Bias Voltage Generation
    temperature dependency */
#define STATUS_ANALOG_TBGP_MASK 0x000000E0
/** field offset */
#define STATUS_ANALOG_TBGP_OFFSET 5
/** BIAS DAC Gain */
#define STATUS_ANALOG_GAINBIASDAC_MASK 0x0000001F
/** field offset */
#define STATUS_ANALOG_GAINBIASDAC_OFFSET 0

/* Fields of "Configuration fuses for drivers and pll" */
/** ddr PU driver
    ddr pullup driver strength adjustment */
#define STATUS_CONFIG_DDRPU_MASK 0xC0000000
/** field offset */
#define STATUS_CONFIG_DDRPU_OFFSET 30
/** ddr PD driver
    ddr pulldown driver strength adjustment */
#define STATUS_CONFIG_DDRPD_MASK 0x30000000
/** field offset */
#define STATUS_CONFIG_DDRPD_OFFSET 28
/** Authentification Unit enable
    This bit can only be set via eFuse and enables the authentification unit. */
#define STATUS_CONFIG_SHA1EN 0x08000000
/* Not selected
#define STATUS_CONFIG_SHA1EN_NSEL 0x00000000 */
/** Selected */
#define STATUS_CONFIG_SHA1EN_SEL 0x08000000
/** Encryption Unit enable
    This bit can only be set via eFuse and enables the encryption unit. */
#define STATUS_CONFIG_AESEN 0x04000000
/* Not selected
#define STATUS_CONFIG_AESEN_NSEL 0x00000000 */
/** Selected */
#define STATUS_CONFIG_AESEN_SEL 0x04000000
/** Subversion Number
    The subversion number has no direct effect on hardware functions. It is used to provide another chip version number that is fixed in hardware and can be read out by software. The chip version is coded by 3 characters XvY; while v is the version coded in CHIPID Register field VERSION. Following codes are defined: */
#define STATUS_CONFIG_SUBVERS_MASK 0x03C00000
/** field offset */
#define STATUS_CONFIG_SUBVERS_OFFSET 22
/** 1. Design Version */
#define STATUS_CONFIG_SUBVERS_Av1 0x00000000
/** Av2 */
#define STATUS_CONFIG_SUBVERS_Av2 0x00400000
/** Av3 */
#define STATUS_CONFIG_SUBVERS_Av3 0x00800000
/** Av4 */
#define STATUS_CONFIG_SUBVERS_Av4 0x00C00000
/** Bv1 */
#define STATUS_CONFIG_SUBVERS_Bv1 0x01000000
/** PLL settings
    PLL settings for infrastructure block */
#define STATUS_CONFIG_PLLINFRA_MASK 0x003FF000
/** field offset */
#define STATUS_CONFIG_PLLINFRA_OFFSET 12
/** GPE frequency selection
    frequency selection of the GPE primary clock. 00 = 769.2MHz, 01 = 625MHz, 10 = 555.6MHz, 11 = 500MHz */
#define STATUS_CONFIG_GPEFREQ_MASK 0x00000C00
/** field offset */
#define STATUS_CONFIG_GPEFREQ_OFFSET 10
/** RM enable
    Activates the Read Margin Settings defined in the RM Field, for all VIRAGE Memories except GPE */
#define STATUS_CONFIG_RME 0x00000200
/* Not selected
#define STATUS_CONFIG_RME_NSEL 0x00000000 */
/** Selected */
#define STATUS_CONFIG_RME_SEL 0x00000200
/** RM settings
    Read Marging Settings for all VIRAGE Memories except GPE */
#define STATUS_CONFIG_RM_MASK 0x000001E0
/** field offset */
#define STATUS_CONFIG_RM_OFFSET 5
/** RM enable for GPE Memories
    Activates the Read Margin Settings defined in the RM Field */
#define STATUS_CONFIG_RMEGPE 0x00000010
/* Not selected
#define STATUS_CONFIG_RMEGPE_NSEL 0x00000000 */
/** Selected */
#define STATUS_CONFIG_RMEGPE_SEL 0x00000010
/** RM settings for GPE Memories
    Read Marging Settings for VIRAGE Memories in GPE module */
#define STATUS_CONFIG_RMGPE_MASK 0x0000000F
/** field offset */
#define STATUS_CONFIG_RMGPE_OFFSET 0

/* Fields of "SPARE fuse register 1" */
/** spare fuse1
    eFuses not assigned to hw/sw, at the moment reserved for TE */
#define STATUS_FUSE1_F1_MASK 0xFFF00000
/** field offset */
#define STATUS_FUSE1_F1_OFFSET 20
/** FREE_1
    used for future application */
#define STATUS_FUSE1_FR1_MASK 0x000F0000
/** field offset */
#define STATUS_FUSE1_FR1_OFFSET 16
/** DCDC 1V0 OFFSET
    offset error sense path */
#define STATUS_FUSE1_OFFSET1V0DCDC_MASK 0x0000F800
/** field offset */
#define STATUS_FUSE1_OFFSET1V0DCDC_OFFSET 11
/** DCDC APD OFFSET
    offset error sense path */
#define STATUS_FUSE1_OFFSETAPDDCDC_MASK 0x000007C0
/** field offset */
#define STATUS_FUSE1_OFFSETAPDDCDC_OFFSET 6
/** DCDC APD GAIN
    gain error sense path */
#define STATUS_FUSE1_GAINAPDDCDC_MASK 0x0000003F
/** field offset */
#define STATUS_FUSE1_GAINAPDDCDC_OFFSET 0

/* Fields of "Configuration for sbs0 rambist" */
/** do not use only for debugging on testsystem
    the GPE SW bist will be shorten to 32 memory locations when it would be enabled by bootmode config */
#define STATUS_MBCFG_MB_DBG 0x02000000
/* Disable
#define STATUS_MBCFG_MB_DBG_DIS 0x00000000 */
/** Enable */
#define STATUS_MBCFG_MB_DBG_EN 0x02000000
/** Disable asc monitoring during boot-up
    Bit is used to avoid asc output for reducing pattern count on testsystem */
#define STATUS_MBCFG_ASC_DBGDIS 0x01000000
/* Disable
#define STATUS_MBCFG_ASC_DBGDIS_DIS 0x00000000 */
/** Enable */
#define STATUS_MBCFG_ASC_DBGDIS_EN 0x01000000
/** Descrambling Enable/Disable
    Enables Address and Data Descrambling for internal Memory Test */
#define STATUS_MBCFG_DSC 0x00800000
/* Disable
#define STATUS_MBCFG_DSC_DIS 0x00000000 */
/** Enable */
#define STATUS_MBCFG_DSC_EN 0x00800000
/** Enable repair mode
    When bit is set redundancy repair mode is activated */
#define STATUS_MBCFG_REPAIR 0x00400000
/* Disable
#define STATUS_MBCFG_REPAIR_DIS 0x00000000 */
/** Enable */
#define STATUS_MBCFG_REPAIR_EN 0x00400000
/** DEBUG Mode */
#define STATUS_MBCFG_DBG 0x00200000
/* Disable
#define STATUS_MBCFG_DBG_DIS 0x00000000 */
/** Enable */
#define STATUS_MBCFG_DBG_EN 0x00200000
/** Retention Time
    Length oft the Retention Time */
#define STATUS_MBCFG_RTIME_MASK 0x001C0000
/** field offset */
#define STATUS_MBCFG_RTIME_OFFSET 18
/** retention mode is switched off */
#define STATUS_MBCFG_RTIME_RET0 0x00000000
/** Retention time 50 ms */
#define STATUS_MBCFG_RTIME_RET50 0x00040000
/** Retention time 60 ms */
#define STATUS_MBCFG_RTIME_RET60 0x00080000
/** Retention time 70 ms */
#define STATUS_MBCFG_RTIME_RET70 0x000C0000
/** Retention time 80 ms */
#define STATUS_MBCFG_RTIME_RET80 0x00100000
/** Retention time 90 ms */
#define STATUS_MBCFG_RTIME_RET90 0x00140000
/** Retention time 1000 ms */
#define STATUS_MBCFG_RTIME_RET1000 0x00180000
/** Test ID
    Defines the test to execute. In which order the tests are executed can be defined via TID_n (TID_1 1st execution, TID_2 2nd execution ..) */
#define STATUS_MBCFG_TID_5_MASK 0x00038000
/** field offset */
#define STATUS_MBCFG_TID_5_OFFSET 15
/** No test is performed */
#define STATUS_MBCFG_TID_5_NONE 0x00000000
/** March test */
#define STATUS_MBCFG_TID_5_MARCH 0x00008000
/** Checkerboard test */
#define STATUS_MBCFG_TID_5_CHCK 0x00010000
/** Hammer test */
#define STATUS_MBCFG_TID_5_HAM 0x00018000
/** Address decoder test */
#define STATUS_MBCFG_TID_5_ADEC 0x00020000
/** Write mask byte test */
#define STATUS_MBCFG_TID_5_WMBYTE 0x00028000
/** Reserved */
#define STATUS_MBCFG_TID_5_RES 0x00030000
/** Test ID
    Defines the test to execute. In which order the tests are executed can be defined via TID_n (TID_1 1st execution, TID_2 2nd execution ..) */
#define STATUS_MBCFG_TID_4_MASK 0x00007000
/** field offset */
#define STATUS_MBCFG_TID_4_OFFSET 12
/** No test is performed */
#define STATUS_MBCFG_TID_4_NONE 0x00000000
/** March test */
#define STATUS_MBCFG_TID_4_MARCH 0x00001000
/** Checkerboard test */
#define STATUS_MBCFG_TID_4_CHCK 0x00002000
/** Hammer test */
#define STATUS_MBCFG_TID_4_HAM 0x00003000
/** Address decoder test */
#define STATUS_MBCFG_TID_4_ADEC 0x00004000
/** Write mask byte test */
#define STATUS_MBCFG_TID_4_WMBYTE 0x00005000
/** Reserved */
#define STATUS_MBCFG_TID_4_RES 0x00006000
/** Test ID
    Defines the test to execute. In which order the tests are executed can be defined via TID_n (TID_1 1st execution, TID_2 2nd execution ..) */
#define STATUS_MBCFG_TID_3_MASK 0x00000E00
/** field offset */
#define STATUS_MBCFG_TID_3_OFFSET 9
/** No test is performed */
#define STATUS_MBCFG_TID_3_NONE 0x00000000
/** March test */
#define STATUS_MBCFG_TID_3_MARCH 0x00000200
/** Checkerboard test */
#define STATUS_MBCFG_TID_3_CHCK 0x00000400
/** Hammer test */
#define STATUS_MBCFG_TID_3_HAM 0x00000600
/** Address decoder test */
#define STATUS_MBCFG_TID_3_ADEC 0x00000800
/** Write mask byte test */
#define STATUS_MBCFG_TID_3_WMBYTE 0x00000A00
/** Reserved */
#define STATUS_MBCFG_TID_3_RES 0x00000C00
/** Test ID
    Defines the test to execute. In which order the tests are executed can be defined via TID_n (TID_1 1st execution, TID_2 2nd execution ..) */
#define STATUS_MBCFG_TID_2_MASK 0x000001C0
/** field offset */
#define STATUS_MBCFG_TID_2_OFFSET 6
/** No test is performed */
#define STATUS_MBCFG_TID_2_NONE 0x00000000
/** March test */
#define STATUS_MBCFG_TID_2_MARCH 0x00000040
/** Checkerboard test */
#define STATUS_MBCFG_TID_2_CHCK 0x00000080
/** Hammer test */
#define STATUS_MBCFG_TID_2_HAM 0x000000C0
/** Address decoder test */
#define STATUS_MBCFG_TID_2_ADEC 0x00000100
/** Write mask byte test */
#define STATUS_MBCFG_TID_2_WMBYTE 0x00000140
/** Reserved */
#define STATUS_MBCFG_TID_2_RES 0x00000180
/** Test ID
    Defines the test to execute. In which order the tests are executed can be defined via TID_n (TID_1 1st execution, TID_2 2nd execution ..) */
#define STATUS_MBCFG_TID_1_MASK 0x00000038
/** field offset */
#define STATUS_MBCFG_TID_1_OFFSET 3
/** No test is performed */
#define STATUS_MBCFG_TID_1_NONE 0x00000000
/** March test */
#define STATUS_MBCFG_TID_1_MARCH 0x00000008
/** Checkerboard test */
#define STATUS_MBCFG_TID_1_CHCK 0x00000010
/** Hammer test */
#define STATUS_MBCFG_TID_1_HAM 0x00000018
/** Address decoder test */
#define STATUS_MBCFG_TID_1_ADEC 0x00000020
/** Write mask byte test */
#define STATUS_MBCFG_TID_1_WMBYTE 0x00000028
/** Reserved */
#define STATUS_MBCFG_TID_1_RES 0x00000030
/** Test ID
    Defines the test to execute. In which order the tests are executed can be defined via TID_n (TID_1 1st execution, TID_2 2nd execution ..) */
#define STATUS_MBCFG_TID_0_MASK 0x00000007
/** field offset */
#define STATUS_MBCFG_TID_0_OFFSET 0
/** No test is performed */
#define STATUS_MBCFG_TID_0_NONE 0x00000000
/** March test */
#define STATUS_MBCFG_TID_0_MARCH 0x00000001
/** Checkerboard test */
#define STATUS_MBCFG_TID_0_CHCK 0x00000002
/** Hammer test */
#define STATUS_MBCFG_TID_0_HAM 0x00000003
/** Address decoder test */
#define STATUS_MBCFG_TID_0_ADEC 0x00000004
/** Write mask byte test */
#define STATUS_MBCFG_TID_0_WMBYTE 0x00000005
/** Reserved */
#define STATUS_MBCFG_TID_0_RES 0x00000006

/* Fields of "sbs0 bist result and debug data" */
/** BIST result and debug data
    Stores additional debug information */
#define STATUS_MBDATA_DATA_MASK 0xFFFC0000
/** field offset */
#define STATUS_MBDATA_DATA_OFFSET 18
/** MBIST NOGO
    The BIST failed and cannot be repaired due to many failure locations, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_5_NOGO 0x00020000
/** MBIST FAILED
    The BIST failed but can be repaired, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_5_FAIL 0x00010000
/** MBIST PASSED
    The BIST passed without any Failures, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_5_PASS 0x00008000
/** MBIST NOGO
    The BIST failed and cannot be repaired due to many failure locations, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_4_NOGO 0x00004000
/** MBIST FAILED
    The BIST failed but can be repaired, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_4_FAIL 0x00002000
/** MBIST PASSED
    The BIST passed without any Failures, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_4_PASS 0x00001000
/** MBIST NOGO
    The BIST failed and cannot be repaired due to many failure locations, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_3_NOGO 0x00000800
/** MBIST FAILED
    The BIST failed but can be repaired, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_3_FAIL 0x00000400
/** MBIST PASSED
    The BIST passed without any Failures, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_3_PASS 0x00000200
/** MBIST NOGO
    The BIST failed and cannot be repaired due to many failure locations, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_2_NOGO 0x00000100
/** MBIST FAILED
    The BIST failed but can be repaired, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_2_FAIL 0x00000080
/** MBIST PASSED
    The BIST passed without any Failures, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_2_PASS 0x00000040
/** MBIST NOGO
    The BIST failed and cannot be repaired due to many failure locations, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_1_NOGO 0x00000020
/** MBIST FAILED
    The BIST failed but can be repaired, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_1_FAIL 0x00000010
/** MBIST PASSED
    The BIST passed without any Failures, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_1_PASS 0x00000008
/** MBIST NOGO
    The BIST failed and cannot be repaired due to many failure locations, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_0_NOGO 0x00000004
/** MBIST FAILED
    The BIST failed but can be repaired, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_0_FAIL 0x00000002
/** MBIST PASSED
    The BIST passed without any Failures, depends on the TID setting in the MBCFG register this bit will be set or not */
#define STATUS_MBDATA_TID_0_PASS 0x00000001

/*! @} */ /* STATUS_REGISTER */

#endif /* _status_reg_h */
