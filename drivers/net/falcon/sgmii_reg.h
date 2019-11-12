/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _sgmii_reg_h
#define _sgmii_reg_h

/** \addtogroup SGMII_REGISTER
   @{
*/
/* access macros */
#define sgmii_r32(reg) reg_r32(&sgmii->reg)
#define sgmii_w32(val, reg) reg_w32(val, &sgmii->reg)
#define sgmii_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &sgmii->reg)
#define sgmii_r32_table(reg, idx) reg_r32_table(sgmii->reg, idx)
#define sgmii_w32_table(val, reg, idx) reg_w32_table(val, sgmii->reg, idx)
#define sgmii_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, sgmii->reg, idx)
#define sgmii_adr_table(reg, idx) adr_table(sgmii->reg, idx)


/** SGMII register structure */
struct gpon_reg_sgmii
{
   /** GLP_REGFILE: GLP Common Registers */
   /** BIST Control Register
       This Register is the BIST's control register. */
   unsigned int glp_regfile_bist_ctrl; /* 0x00000000 */
   /** BIST status Register
       This Register is the BIST's status register. */
   unsigned int glp_regfile_bist_status; /* 0x00000004 */
   /** BIST Time Out control Register
       This Register is the BIST's timeout control register. */
   unsigned int glp_regfile_bist_timectrl; /* 0x00000008 */
   /** Phase Lock Count Register
       This Register is the BIST's phase lock count register. */
   unsigned int glp_regfile_bist_phlock; /* 0x0000000C */
   /** Bist Endcount Register
       This Register is the BIST's word count register. */
   unsigned int glp_regfile_bist_end; /* 0x00000010 */
   /** BERT Termination Count Register
       This Register is the BERT's termination count register. */
   unsigned int glp_regfile_bert_term; /* 0x00000014 */
   /** BERT Error Count Register
       This Register is the BERT's Error count register. */
   unsigned int glp_regfile_bert_err; /* 0x00000018 */
   /** BERT Reset Control Register
       This Register is the BERTs' control register. */
   unsigned int glp_regfile_bert_rst; /* 0x0000001C */
   /** BERT Control Register
       This Register is the BERTs' control register. */
   unsigned int glp_regfile_bert_ctrl; /* 0x00000020 */
   /** 3GLP Control Register
       This register is used for general control in the 3GLP. */
   unsigned int glp_regfile_glp_ctrl; /* 0x00000024 */
   /** 3GLP Miscellaneous Register
       This register is used for miscellaneous control or reading bits. */
   unsigned int glp_regfile_glp_misc; /* 0x00000028 */
   /** PMA_REGFILE: PMA Registers */
   /** Start Up Control Register
       PMA Start Up Register */
   unsigned int pma_regfile_startup_ctrl; /* 0x0000002C */
   /** State Register
       PMA Start Up State Register */
   unsigned int pma_regfile_state; /* 0x00000030 */
   /** PLL_REGFILE: PLL Slice Registers */
   /** Control 1 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl1; /* 0x00000034 */
   /** Control 2 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl2; /* 0x00000038 */
   /** Control 3 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl3; /* 0x0000003C */
   /** Control 4 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl4; /* 0x00000040 */
   /** Control 5 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl5; /* 0x00000044 */
   /** Control 6 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl6; /* 0x00000048 */
   /** Control 7 Register
       This Register is for controlling the PMA portion of PLL SLICE behavior. */
   unsigned int pll_regfile_ctrl7; /* 0x0000004C */
   /** Analog Control 1 Register
       This Register is for controlling of analog PLL SLICE behavior. */
   unsigned int pll_regfile_a_ctrl1; /* 0x00000050 */
   /** Analog Control 2 Register
       This Register is for controlling of analog PLL SLICE behavior. */
   unsigned int pll_regfile_a_ctrl2; /* 0x00000054 */
   /** Analog Control 3 Register
       This Register is for controlling of analog PLL SLICE behavior. */
   unsigned int pll_regfile_a_ctrl3; /* 0x00000058 */
   /** Analog Control 4 Register
       This Register is for controlling of analog PLL SLICE behavior. */
   unsigned int pll_regfile_a_ctrl4; /* 0x0000005C */
   /** PLL Status Register
       This Register is for reading PLL status. */
   unsigned int pll_regfile_status; /* 0x00000060 */
   /** TX_REGFILE_0: TX Slice Registers */
   /** Control 1 Register
       This Register is for controlling of TX SLICE behavior. */
   unsigned int tx_regfile_0_ctrl1; /* 0x00000064 */
   /** TX Control 2 Register
       This Register is for controlling of TX SLICE behavior. */
   unsigned int tx_regfile_0_ctrl2; /* 0x00000068 */
   /** Control 3 Register
       This Register is for controlling of TX SLICE behavior. */
   unsigned int tx_regfile_0_ctrl3; /* 0x0000006C */
   /** Analog Control 1 Register
       This Register is for controlling of analog TX SLICE behavior. */
   unsigned int tx_regfile_0_a_ctrl1; /* 0x00000070 */
   /** Analog Control 2 Register
       This Register is for controlling of analog TX SLICE behavior. */
   unsigned int tx_regfile_0_a_ctrl2; /* 0x00000074 */
   /** Modulation Configuration 1 Register
       This Register is the configuration of the Modulation. */
   unsigned int tx_regfile_0_mod1; /* 0x00000078 */
   /** Modulation Configuration 2 Register
       This Register is the configuration of the Modulation. */
   unsigned int tx_regfile_0_mod2; /* 0x0000007C */
   /** Modulation Configuration 3 Register
       This Register is the configuration of the Modulation. */
   unsigned int tx_regfile_0_mod3; /* 0x00000080 */
   /** TX_REGFILE_1: TX Slice Registers */
   /** Control 1 Register
       This Register is for controlling of TX SLICE behavior. */
   unsigned int tx_regfile_1_ctrl1; /* 0x00000084 */
   /** TX Control 2 Register
       This Register is for controlling of TX SLICE behavior. */
   unsigned int tx_regfile_1_ctrl2; /* 0x00000088 */
   /** Control 3 Register
       This Register is for controlling of TX SLICE behavior. */
   unsigned int tx_regfile_1_ctrl3; /* 0x0000008C */
   /** Analog Control 1 Register
       This Register is for controlling of analog TX SLICE behavior. */
   unsigned int tx_regfile_1_a_ctrl1; /* 0x00000090 */
   /** Analog Control 2 Register
       This Register is for controlling of analog TX SLICE behavior. */
   unsigned int tx_regfile_1_a_ctrl2; /* 0x00000094 */
   /** Modulation Configuration 1 Register
       This Register is the configuration of the Modulation. */
   unsigned int tx_regfile_1_mod1; /* 0x00000098 */
   /** Modulation Configuration 2 Register
       This Register is the configuration of the Modulation. */
   unsigned int tx_regfile_1_mod2; /* 0x0000009C */
   /** Modulation Configuration 3 Register
       This Register is the configuration of the Modulation. */
   unsigned int tx_regfile_1_mod3; /* 0x000000A0 */
   /** RX_REGFILE: RX Slice Registers */
   /** RX Control 1 Register
       This Register is for controlling of RX SLICE behavior. */
   unsigned int rx_regfile_ctrl1; /* 0x000000A4 */
   /** RX Control 2 Register
       This Register is for controlling of RX SLICE behavior. */
   unsigned int rx_regfile_ctrl2; /* 0x000000A8 */
   /** CDR Configuration Register
       This Register is for Configuration of CDR CTRL. */
   unsigned int rx_regfile_cdr; /* 0x000000AC */
   /** EI Register
       This Register is for Configuration of EI detect. */
   unsigned int rx_regfile_ei; /* 0x000000B0 */
   /** CAL Register
       This Register is for Configuration of CAL. */
   unsigned int rx_regfile_cal; /* 0x000000B4 */
   /** Analog Control Register
       This Register is for controlling of analog RX SLICE behavior. */
   unsigned int rx_regfile_a_ctrl; /* 0x000000B8 */
   /** Test Control Register
       This Register is for Test control of RX SLICE. */
   unsigned int rx_regfile_test_ctrl; /* 0x000000BC */
   /** Reserved */
   unsigned int rx_regfile_res_0[16]; /* 0x000000C0 */
};


/* Fields of "BIST Control Register" */
/** Enable Bist
    Override of BIST enable when OVR_EN is OVR. */
#define GLP_REGFILE_BIST_CTRL_EN 0x00000400
/** Disable */
#define GLP_REGFILE_BIST_CTRL_EN_DIS 0x00000400
/** Enable Override of Bist Enable
    Controls override of BIST enable. */
#define GLP_REGFILE_BIST_CTRL_OVR_EN 0x00000200
/* No override
#define GLP_REGFILE_BIST_CTRL_OVR_EN_NO_OVR 0x00000000 */
/** Override */
#define GLP_REGFILE_BIST_CTRL_OVR_EN_OVR 0x00000200
/** RX Enables
    Enables for RX Lanes for BIST loop. */
#define GLP_REGFILE_BIST_CTRL_RX_EN_MASK 0x000001E0
/** field offset */
#define GLP_REGFILE_BIST_CTRL_RX_EN_OFFSET 5
/** RX BIST disabled */
#define GLP_REGFILE_BIST_CTRL_RX_EN_RX_BIST_EN_NONE 0x00000000
/** Enable RX BIST 1 */
#define GLP_REGFILE_BIST_CTRL_RX_EN_RX_BIST_EN_1 0x00000020
/** Enable RX BIST 2 */
#define GLP_REGFILE_BIST_CTRL_RX_EN_RX_BIST_EN_2 0x00000040
/** Enable RX BIST 3 */
#define GLP_REGFILE_BIST_CTRL_RX_EN_RX_BIST_EN_3 0x00000080
/** Enable RX BIST 4 */
#define GLP_REGFILE_BIST_CTRL_RX_EN_RX_BIST_EN_4 0x00000100
/** TX Enables
    Enables for TX Lanes for BIST loop. */
#define GLP_REGFILE_BIST_CTRL_TX_EN_MASK 0x0000001E
/** field offset */
#define GLP_REGFILE_BIST_CTRL_TX_EN_OFFSET 1
/** TX BIST disabled */
#define GLP_REGFILE_BIST_CTRL_TX_EN_TX_BIST_EN_NONE 0x00000000
/** Enable TX BIST 1 */
#define GLP_REGFILE_BIST_CTRL_TX_EN_TX_BIST_EN_1 0x00000002
/** Enable TX BIST 2 */
#define GLP_REGFILE_BIST_CTRL_TX_EN_TX_BIST_EN_2 0x00000004
/** Enable TX BIST 3 */
#define GLP_REGFILE_BIST_CTRL_TX_EN_TX_BIST_EN_3 0x00000008
/** Enable TX BIST 4 */
#define GLP_REGFILE_BIST_CTRL_TX_EN_TX_BIST_EN_4 0x00000010
/** Bypass
    TX_EN and RX_EN will select the respective slices for BIST when BYPASS is EN. */
#define GLP_REGFILE_BIST_CTRL_BYPASS 0x00000001
/* Disable Bypass
#define GLP_REGFILE_BIST_CTRL_BYPASS_DIS 0x00000000 */
/** Enable Bypass */
#define GLP_REGFILE_BIST_CTRL_BYPASS_EN 0x00000001

/* Fields of "BIST status Register" */
/** Timeout Status
    Timeout on waiting for PHY ready. */
#define GLP_REGFILE_BIST_STATUS_TIMEOUT 0x00000040
/** Loop Fail Status
    Indicates which BIST loop fails. */
#define GLP_REGFILE_BIST_STATUS_LOOP_FAIL_MASK 0x0000003C
/** field offset */
#define GLP_REGFILE_BIST_STATUS_LOOP_FAIL_OFFSET 2
/** DONE Status
    Overall BIST done status. */
#define GLP_REGFILE_BIST_STATUS_DONE 0x00000002
/** Fail Status
    Overall BIST fail status. */
#define GLP_REGFILE_BIST_STATUS_FAIL 0x00000001

/* Fields of "BIST Time Out control Register" */
/** Enable Timeout monitor
    Enable timeout monitor when BIST starts to enable PHY. */
#define GLP_REGFILE_BIST_TIMECTRL_TIMEOUT_EN 0x00000100
/* Disable
#define GLP_REGFILE_BIST_TIMECTRL_TIMEOUT_EN_DIS 0x00000000 */
/** Enable */
#define GLP_REGFILE_BIST_TIMECTRL_TIMEOUT_EN_EN 0x00000100
/** Timeout counter value
    Programs the counter value for the BIST to timeout on waiting for PHY ready. */
#define GLP_REGFILE_BIST_TIMECTRL_TIMEOUTVAL_MASK 0x000000FF
/** field offset */
#define GLP_REGFILE_BIST_TIMECTRL_TIMEOUTVAL_OFFSET 0

/* Fields of "Phase Lock Count Register" */
/** Phase Lock Count
    Programs the counter value for the BIST to achieve phase lock. */
#define GLP_REGFILE_BIST_PHLOCK_COUNT_MASK 0x000003FF
/** field offset */
#define GLP_REGFILE_BIST_PHLOCK_COUNT_OFFSET 0

/* Fields of "Bist Endcount Register" */
/** Word Count
    Programs the number of words for the BIST to check for errors. */
#define GLP_REGFILE_BIST_END_COUNT_MASK 0x000003FF
/** field offset */
#define GLP_REGFILE_BIST_END_COUNT_OFFSET 0

/* Fields of "BERT Termination Count Register" */
/** Word Count
    Read the number of words BERT receives at termination. */
#define GLP_REGFILE_BERT_TERM_COUNT_MASK 0x000003FF
/** field offset */
#define GLP_REGFILE_BERT_TERM_COUNT_OFFSET 0

/* Fields of "BERT Error Count Register" */
/** Word Count
    Read the number of accumulated bit errors. */
#define GLP_REGFILE_BERT_ERR_COUNT_MASK 0x000003FF
/** field offset */
#define GLP_REGFILE_BERT_ERR_COUNT_OFFSET 0

/* Fields of "BERT Reset Control Register" */
/** BERT Error Count reset
    Resets the BERT Error Count Register of the enabled BERT. */
#define GLP_REGFILE_BERT_RST_ERR_RST 0x00000200
/* No Reset
#define GLP_REGFILE_BERT_RST_ERR_RST_NO_RST 0x00000000 */
/** Reset */
#define GLP_REGFILE_BERT_RST_ERR_RST_RST 0x00000200
/** BERT Word Count reset
    Resets the BERT Termination Count Register of the enabled BERT. */
#define GLP_REGFILE_BERT_RST_WRD_RST 0x00000100
/* No Reset
#define GLP_REGFILE_BERT_RST_WRD_RST_NO_RST 0x00000000 */
/** Reset */
#define GLP_REGFILE_BERT_RST_WRD_RST_RST 0x00000100
/** BERT RX Resets
    Reset Bits (Active low) for each BERT RX. */
#define GLP_REGFILE_BERT_RST_RX_RST_MASK 0x000000F0
/** field offset */
#define GLP_REGFILE_BERT_RST_RX_RST_OFFSET 4
/** Reset */
#define GLP_REGFILE_BERT_RST_RX_RST_RST 0x00000000
/** No Reset */
#define GLP_REGFILE_BERT_RST_RX_RST_NO_RST 0x00000010
/** BERT TX Resets
    Reset Bits (Active low) for each BERT TX. */
#define GLP_REGFILE_BERT_RST_TX_RST_MASK 0x0000000F
/** field offset */
#define GLP_REGFILE_BERT_RST_TX_RST_OFFSET 0
/** Reset */
#define GLP_REGFILE_BERT_RST_TX_RST_RST 0x00000000
/** No Reset */
#define GLP_REGFILE_BERT_RST_TX_RST_NO_RST 0x00000001

/* Fields of "BERT Control Register" */
/** Scramble Enable
    Data from BERTs will be used for scrambling data to PHY if enabled. */
#define GLP_REGFILE_BERT_CTRL_SCR_EN 0x00000100
/* Disable
#define GLP_REGFILE_BERT_CTRL_SCR_EN_DIS 0x00000000 */
/** Enable */
#define GLP_REGFILE_BERT_CTRL_SCR_EN_EN 0x00000100
/** Loopback Enables
    Loopback enables for respective BERTs. */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_MASK 0x000000F0
/** field offset */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_OFFSET 4
/** BERTs loopback disabled */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_BERT_EN_NONE 0x00000000
/** Enable Loopback in BERT 1 */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_BERT1_EN 0x00000010
/** Enable Loopback in BERT 2 */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_BERT2_EN 0x00000020
/** Enable Loopback in BERT 3 */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_BERT3_EN 0x00000040
/** Enable Loopback in BERT 4 */
#define GLP_REGFILE_BERT_CTRL_LOOPEN_BERT4_EN 0x00000080
/** LFSR Enable
    LSFR Data from BERTs will be used for scrambling data from PHY if enabled. */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_MASK 0x0000000F
/** field offset */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_OFFSET 0
/** BERTs Self Sync disabled */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_BERT_EN_NONE 0x00000000
/** Enable Self Sync in BERT 1 */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_BERT1_EN 0x00000001
/** Enable Self Sync in BERT 2 */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_BERT2_EN 0x00000002
/** Enable Self Sync in BERT 3 */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_BERT3_EN 0x00000004
/** Enable Self Sync in BERT 4 */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_BERT4_EN 0x00000008
/** Reset value */
#define GLP_REGFILE_BERT_CTRL_SELFSYNC_EN_RESET 0x0000000F

/* Fields of "3GLP Control Register" */
/** CRC value sent
    This CRC value will be transmitted to core when 3GLP is not ready and MSK_EN is enabled. */
#define GLP_REGFILE_GLP_CTRL_CRC_VAL 0x00000040
/** Data masking enable
    Enables data masking at core interface. A all-zeros data word will be transmitted when 3GLP is not ready. */
#define GLP_REGFILE_GLP_CTRL_MSK_EN 0x00000020
/* Disable
#define GLP_REGFILE_GLP_CTRL_MSK_EN_DIS 0x00000000 */
/** Enable */
#define GLP_REGFILE_GLP_CTRL_MSK_EN_EN 0x00000020
/** Clock switching enable
    Enables clock switching at core interface. A 144MHz clock will be transmitted when 3GLP is not ready. */
#define GLP_REGFILE_GLP_CTRL_CLK_SW 0x00000010
/* Disable
#define GLP_REGFILE_GLP_CTRL_CLK_SW_DIS 0x00000000 */
/** Enable */
#define GLP_REGFILE_GLP_CTRL_CLK_SW_EN 0x00000010
/** Control
    Selects Inband bits mapping to TX 2 CDR control. */
#define GLP_REGFILE_GLP_CTRL_TX2_CDR_SEL_MASK 0x0000000C
/** field offset */
#define GLP_REGFILE_GLP_CTRL_TX2_CDR_SEL_OFFSET 2
/** Selects RX1 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX2_CDR_SEL_SEL_1 0x00000000
/** Selects RX2 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX2_CDR_SEL_SEL_2 0x00000004
/** Selects RX3 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX2_CDR_SEL_SEL_3 0x00000008
/** Selects RX4 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX2_CDR_SEL_SEL_4 0x0000000C
/** Control
    Selects Inband bits mapping to TX 1 CDR control. */
#define GLP_REGFILE_GLP_CTRL_TX1_CDR_SEL_MASK 0x00000003
/** field offset */
#define GLP_REGFILE_GLP_CTRL_TX1_CDR_SEL_OFFSET 0
/** Selects RX1 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX1_CDR_SEL_SEL_1 0x00000000
/** Selects RX2 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX1_CDR_SEL_SEL_2 0x00000001
/** Selects RX3 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX1_CDR_SEL_SEL_3 0x00000002
/** Selects RX4 Inband Control */
#define GLP_REGFILE_GLP_CTRL_TX1_CDR_SEL_SEL_4 0x00000003

/* Fields of "3GLP Miscellaneous Register" */
/** Status
    Miscellaneous Status bits. */
#define GLP_REGFILE_GLP_MISC_STATUS_2_MASK 0x0000F000
/** field offset */
#define GLP_REGFILE_GLP_MISC_STATUS_2_OFFSET 12
/** Status
    Miscellaneous Status bits. */
#define GLP_REGFILE_GLP_MISC_STATUS_1_MASK 0x00000F00
/** field offset */
#define GLP_REGFILE_GLP_MISC_STATUS_1_OFFSET 8
/** Control
    Miscellaneous Control bits. */
#define GLP_REGFILE_GLP_MISC_CTRL_MASK 0x000000FF
/** field offset */
#define GLP_REGFILE_GLP_MISC_CTRL_OFFSET 0

/* Fields of "Start Up Control Register" */
/** Skip Calibration
    Skip Calibration bit. */
#define PMA_REGFILE_STARTUP_CTRL_SKIP_CAL 0x00000400
/** Startup Ready
    Start up Ready bit. The PHY ready status is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_STARTUP_RDY 0x00000200
/** CAL Enable
    The Calibration Enable is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_CAL_EN 0x00000100
/** CDR Enable
    CDR Enable. The is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_CDR_EN 0x00000080
/** Clock Enable
    High Speed Clock Enable is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_CLK_EN 0x00000040
/** Powerdown
    Powerdown bit is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_PD 0x00000020
/** Reset PMD
    The PMD reset is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_RSTN_PMD 0x00000010
/** Reset Digital
    Digital reset to all blocks in PMA slices is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_RSTN_DIG 0x00000008
/** PLL Powerdown
    PLL powerdown is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_PLL_PD 0x00000004
/** PLL reset
    PLL reset bit. The PLL reset is overridden by this value when bypass is enabled. */
#define PMA_REGFILE_STARTUP_CTRL_PLL_RSTN 0x00000002
/** Bypass
    Register Bypass bit. Start-up state machine control outputs will be overridden by register values when enabled. */
#define PMA_REGFILE_STARTUP_CTRL_BYPASS 0x00000001
/* Disable
#define PMA_REGFILE_STARTUP_CTRL_BYPASS_DIS 0x00000000 */
/** Enable */
#define PMA_REGFILE_STARTUP_CTRL_BYPASS_EN 0x00000001

/* Fields of "State Register" */
/** Start Up SM State
    PMA Start-Up State Machine. */
#define PMA_REGFILE_STATE_STATE_MASK 0x00000007
/** field offset */
#define PMA_REGFILE_STATE_STATE_OFFSET 0
/** Power Up PLL */
#define PMA_REGFILE_STATE_STATE_ST_POWERUP_PLL 0x00000000
/** Release High Freqency Reset */
#define PMA_REGFILE_STATE_STATE_ST_RELEASE_HF_RESET 0x00000001
/** Release High Freqency Clocks */
#define PMA_REGFILE_STATE_STATE_ST_RELEASE_HF_CLOCKS 0x00000002
/** Release Digital Reset */
#define PMA_REGFILE_STATE_STATE_ST_RELEASE_DIG_RESET 0x00000003
/** Enable Calibration */
#define PMA_REGFILE_STATE_STATE_ST_EN_CAL 0x00000004
/** Finish */
#define PMA_REGFILE_STATE_STATE_FINISH 0x00000005

/* Fields of "Control 1 Register" */
/** 16 LSBs of the CONST_SDM. */
#define PLL_REGFILE_CTRL1_CONST_SDM_MASK 0x0000FFFF
/** field offset */
#define PLL_REGFILE_CTRL1_CONST_SDM_OFFSET 0

/* Fields of "Control 2 Register" */
/** plldigtest_r */
#define PLL_REGFILE_CTRL2_PLLDIGTEST_MASK 0x0000F800
/** field offset */
#define PLL_REGFILE_CTRL2_PLLDIGTEST_OFFSET 11
/** pll_enwavegen_r */
#define PLL_REGFILE_CTRL2_PLL_ENWAVEGEN 0x00000400
/* Disable
#define PLL_REGFILE_CTRL2_PLL_ENWAVEGEN_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL2_PLL_ENWAVEGEN_EN 0x00000400
/** pll_ensdm_r */
#define PLL_REGFILE_CTRL2_PLL_ENSDM 0x00000200
/* Disable
#define PLL_REGFILE_CTRL2_PLL_ENSDM_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL2_PLL_ENSDM_EN 0x00000200
/** en_const_sdm_r */
#define PLL_REGFILE_CTRL2_EN_CONST_SDM 0x00000100
/* Disable
#define PLL_REGFILE_CTRL2_EN_CONST_SDM_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL2_EN_CONST_SDM_EN 0x00000100
/** 8 MSBs of the CONST_SDM. */
#define PLL_REGFILE_CTRL2_CONST_SDM_MASK 0x000000FF
/** field offset */
#define PLL_REGFILE_CTRL2_CONST_SDM_OFFSET 0

/* Fields of "Control 3 Register" */
/** en_ext_selvco_r */
#define PLL_REGFILE_CTRL3_EXT_SELVCO_MASK 0x00003E00
/** field offset */
#define PLL_REGFILE_CTRL3_EXT_SELVCO_OFFSET 9
/** ext_VCO_vctrl_mux_r */
#define PLL_REGFILE_CTRL3_EXT_VCO_VCTRL_MUX_MASK 0x00000180
/** field offset */
#define PLL_REGFILE_CTRL3_EXT_VCO_VCTRL_MUX_OFFSET 7
/** ext_MMD_div_ratio_r */
#define PLL_REGFILE_CTRL3_EXT_MMD_DIV_RATIO_MASK 0x00000070
/** field offset */
#define PLL_REGFILE_CTRL3_EXT_MMD_DIV_RATIO_OFFSET 4
/** en_ext_selvco_r */
#define PLL_REGFILE_CTRL3_EN_EXT_SELVCO 0x00000008
/* Disable
#define PLL_REGFILE_CTRL3_EN_EXT_SELVCO_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL3_EN_EXT_SELVCO_EN 0x00000008
/** en_ext_VCO_vctrl_mux_r */
#define PLL_REGFILE_CTRL3_EN_EXT_VCO_VCTRL_MUX 0x00000004
/* Disable
#define PLL_REGFILE_CTRL3_EN_EXT_VCO_VCTRL_MUX_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL3_EN_EXT_VCO_VCTRL_MUX_EN 0x00000004
/** en_ext_MMD_div_ratio_r */
#define PLL_REGFILE_CTRL3_EN_EXT_MMD_DIV_RATIO 0x00000002
/* Disable
#define PLL_REGFILE_CTRL3_EN_EXT_MMD_DIV_RATIO_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL3_EN_EXT_MMD_DIV_RATIO_EN 0x00000002
/** en_binary_cal_r */
#define PLL_REGFILE_CTRL3_EN_BIN_CAL 0x00000001
/* Disable
#define PLL_REGFILE_CTRL3_EN_BIN_CAL_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_CTRL3_EN_BIN_CAL_EN 0x00000001

/* Fields of "Control 4 Register" */
/** pllmod_r
    First (Least Significant) word of the PLLMOD. */
#define PLL_REGFILE_CTRL4_PLLMOD_MASK 0x0000FFFF
/** field offset */
#define PLL_REGFILE_CTRL4_PLLMOD_OFFSET 0

/* Fields of "Control 5 Register" */
/** pllmod_r
    Second word of the PLLMOD. */
#define PLL_REGFILE_CTRL5_PLLMOD_MASK 0x0000FFFF
/** field offset */
#define PLL_REGFILE_CTRL5_PLLMOD_OFFSET 0

/* Fields of "Control 6 Register" */
/** pllmod_r
    Third word of the PLLMOD. */
#define PLL_REGFILE_CTRL6_PLLMOD_MASK 0x0000FFFF
/** field offset */
#define PLL_REGFILE_CTRL6_PLLMOD_OFFSET 0

/* Fields of "Control 7 Register" */
/** pllmod_r
    Fourth (Most significant) word of the PLLMOD. */
#define PLL_REGFILE_CTRL7_PLLMOD_MASK 0x0000FFFF
/** field offset */
#define PLL_REGFILE_CTRL7_PLLMOD_OFFSET 0

/* Fields of "Analog Control 1 Register" */
/** pfd_force_up_r */
#define PLL_REGFILE_A_CTRL1_PFD_FORCE_UP 0x00008000
/** pfd_force_dw_r */
#define PLL_REGFILE_A_CTRL1_PFD_FORCE_DW 0x00004000
/** cp_sel_r */
#define PLL_REGFILE_A_CTRL1_CP_SEL_MASK 0x00003800
/** field offset */
#define PLL_REGFILE_A_CTRL1_CP_SEL_OFFSET 11
/** cp_ref_sel_r */
#define PLL_REGFILE_A_CTRL1_CP_REF_SEL_MASK 0x00000600
/** field offset */
#define PLL_REGFILE_A_CTRL1_CP_REF_SEL_OFFSET 9
/** cp_force_fix_p_bias_r */
#define PLL_REGFILE_A_CTRL1_CP_FORCE_FIX_P_BIAS 0x00000100
/** biastrim */
#define PLL_REGFILE_A_CTRL1_BIASTRIM_MASK 0x000000FF
/** field offset */
#define PLL_REGFILE_A_CTRL1_BIASTRIM_OFFSET 0

/* Fields of "Analog Control 2 Register" */
/** lf_mode_r */
#define PLL_REGFILE_A_CTRL2_LF_MODE 0x00004000
/** ldo_vref_sel_r */
#define PLL_REGFILE_A_CTRL2_LDO_VREF_SEL_MASK 0x00003800
/** field offset */
#define PLL_REGFILE_A_CTRL2_LDO_VREF_SEL_OFFSET 11
/** div_clk_o_mtr_en_r */
#define PLL_REGFILE_A_CTRL2_DIV_CLK_O_MTR_EN 0x00000400
/* Disable
#define PLL_REGFILE_A_CTRL2_DIV_CLK_O_MTR_EN_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_A_CTRL2_DIV_CLK_O_MTR_EN_EN 0x00000400
/** current_sel_ref_mux_r */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_REF_MUX_MASK 0x00000300
/** field offset */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_REF_MUX_OFFSET 8
/** current_sel_pi_r */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_PI_MASK 0x000000C0
/** field offset */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_PI_OFFSET 6
/** current_sel_lf_r */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_LF_MASK 0x00000030
/** field offset */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_LF_OFFSET 4
/** current_sel_ldo_r */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_LDO_MASK 0x0000000C
/** field offset */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_LDO_OFFSET 2
/** current_sel_div2_r */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_DIV2_MASK 0x00000003
/** field offset */
#define PLL_REGFILE_A_CTRL2_CURR_SEL_DIV2_OFFSET 0

/* Fields of "Analog Control 3 Register" */
/** vco_sel_r */
#define PLL_REGFILE_A_CTRL3_VCO_SEL 0x00002000
/** vco_vctrl_when_ct_r */
#define PLL_REGFILE_A_CTRL3_VCO_VCTRL_WHEN_CT_MASK 0x00001800
/** field offset */
#define PLL_REGFILE_A_CTRL3_VCO_VCTRL_WHEN_CT_OFFSET 11
/** test_ext_fd_in_en_r */
#define PLL_REGFILE_A_CTRL3_TEST_EXT_FD_IN_EN 0x00000400
/* Disable
#define PLL_REGFILE_A_CTRL3_TEST_EXT_FD_IN_EN_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_A_CTRL3_TEST_EXT_FD_IN_EN_EN 0x00000400
/** refclk_sel_r */
#define PLL_REGFILE_A_CTRL3_REFCLK_SEL 0x00000200
/** refclk_o_en_r */
#define PLL_REGFILE_A_CTRL3_REFCLK_O_EN 0x00000100
/* Disable
#define PLL_REGFILE_A_CTRL3_REFCLK_O_EN_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_A_CTRL3_REFCLK_O_EN_EN 0x00000100
/** ref_clk_o_mtr_en_r */
#define PLL_REGFILE_A_CTRL3_REF_CLK_O_MTR_EN 0x00000080
/* Disable
#define PLL_REGFILE_A_CTRL3_REF_CLK_O_MTR_EN_DIS 0x00000000 */
/** Enable */
#define PLL_REGFILE_A_CTRL3_REF_CLK_O_MTR_EN_EN 0x00000080
/** pwd_vrefs_r */
#define PLL_REGFILE_A_CTRL3_PWD_VREFS 0x00000040
/** pwd_lf_r */
#define PLL_REGFILE_A_CTRL3_PWD_LF 0x00000020
/** pwd_ldo_vco_r */
#define PLL_REGFILE_A_CTRL3_PWD_LDO_VCO 0x00000010
/** pwd_fd_in_buffer_r */
#define PLL_REGFILE_A_CTRL3_PWD_FD_IN_BUFFER 0x00000008
/** pwd_div2_r */
#define PLL_REGFILE_A_CTRL3_PWD_DIV2 0x00000004
/** pwd_cp_r */
#define PLL_REGFILE_A_CTRL3_PWD_CP 0x00000002
/** pwd_bias_r */
#define PLL_REGFILE_A_CTRL3_PWD_BIAS 0x00000001

/* Fields of "Analog Control 4 Register" */
/** pwd_out_div8_r */
#define PLL_REGFILE_A_CTRL4_PWD_OUT_DIV8 0x00002000
/** pwd_out_div5_r */
#define PLL_REGFILE_A_CTRL4_PWD_OUT_DIV5 0x00001000
/** pwd_out_div_r */
#define PLL_REGFILE_A_CTRL4_PWD_OUT_DIV 0x00000800
/** pwd_fix_ph_core_f_r */
#define PLL_REGFILE_A_CTRL4_PWD_FIX_PH_CORE_F 0x00000400
/** current_sel_fixph_buf_r */
#define PLL_REGFILE_A_CTRL4_CUR_SEL_FIXPH_BUF_MASK 0x00000300
/** field offset */
#define PLL_REGFILE_A_CTRL4_CUR_SEL_FIXPH_BUF_OFFSET 8
/** current_sel_fd_prebuf_r */
#define PLL_REGFILE_A_CTRL4_CUR_SEL_FD_PREBUF_MASK 0x000000C0
/** field offset */
#define PLL_REGFILE_A_CTRL4_CUR_SEL_FD_PREBUF_OFFSET 6
/** mmd_r */
#define PLL_REGFILE_A_CTRL4_MMD_MASK 0x0000003F
/** field offset */
#define PLL_REGFILE_A_CTRL4_MMD_OFFSET 0

/* Fields of "PLL Status Register" */
/** Startup Ready */
#define PLL_REGFILE_STATUS_STARTUP_RDY 0x00000040
/** Lock */
#define PLL_REGFILE_STATUS_LOCK 0x00000020
/** Ready */
#define PLL_REGFILE_STATUS_READY 0x00000010
/** Force Start */
#define PLL_REGFILE_STATUS_FORCE_START 0x00000002
/** Force Lock */
#define PLL_REGFILE_STATUS_FORCE_LOCK 0x00000001

/* Fields of "Control 1 Register" */
/** ei_ovr_r
    Override enable bit for EI_EN and EIN_EN. */
#define TX_REGFILE_0_CTRL1_EI_OVR 0x00004000
/* Override Disable
#define TX_REGFILE_0_CTRL1_EI_OVR_DIS 0x00000000 */
/** Override Enable */
#define TX_REGFILE_0_CTRL1_EI_OVR_EN 0x00004000
/** pi_ctrl_r
    For pi_ctrl. */
#define TX_REGFILE_0_CTRL1_PI_CTRL_MASK 0x00003F00
/** field offset */
#define TX_REGFILE_0_CTRL1_PI_CTRL_OFFSET 8
/** ein_en_r
    Used to select the sign of the SERIALIZER outputs when EI_EN is high. Pay attention that the signal of the serializer output is inverted into the offchip. */
#define TX_REGFILE_0_CTRL1_EIN_EN 0x00000080
/* Disable
#define TX_REGFILE_0_CTRL1_EIN_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_CTRL1_EIN_EN_EN 0x00000080
/** halfrate_r
    Enable half rate data transmission. */
#define TX_REGFILE_0_CTRL1_HALFRATE 0x00000040
/** flip_r
    Flip the data. */
#define TX_REGFILE_0_CTRL1_FLIP 0x00000020
/** load_r
    For PI control circuit's loading of PI_CTRL value. */
#define TX_REGFILE_0_CTRL1_LOAD 0x00000010
/** force_r
    Force farend detection. */
#define TX_REGFILE_0_CTRL1_FORCE 0x00000008
/** ei_en_r
    Forces the ouptut of the SERIALIZER either to High or to Low depending on the value of the EIN_EN. */
#define TX_REGFILE_0_CTRL1_EI_EN 0x00000004
/* Disable
#define TX_REGFILE_0_CTRL1_EI_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_CTRL1_EI_EN_EN 0x00000004
/** Invert Enable
    Enables the inversion of data. */
#define TX_REGFILE_0_CTRL1_INV_EN 0x00000002
/* Disable
#define TX_REGFILE_0_CTRL1_INV_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_CTRL1_INV_EN_EN 0x00000002
/** Enable
    Enable bit. */
#define TX_REGFILE_0_CTRL1_EN 0x00000001
/* Disable
#define TX_REGFILE_0_CTRL1_EN_DIS 0x00000000 */

/* Fields of "TX Control 2 Register" */
/** rterm_r
    Configures termination resistors in PHY. */
#define TX_REGFILE_0_CTRL2_RTERM_MASK 0x00003E00
/** field offset */
#define TX_REGFILE_0_CTRL2_RTERM_OFFSET 9
/** Enable Programmable TX Data
    Enable Programmable Data for TX. */
#define TX_REGFILE_0_CTRL2_PRG_EN 0x00000100
/* Disable
#define TX_REGFILE_0_CTRL2_PRG_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_CTRL2_PRG_EN_EN 0x00000100
/** Programmable TX Data
    Programmable Data for TX to PHY. */
#define TX_REGFILE_0_CTRL2_PRG_DATA_MASK 0x000000FF
/** field offset */
#define TX_REGFILE_0_CTRL2_PRG_DATA_OFFSET 0

/* Fields of "Control 3 Register" */
/** counter_limit_r
    Counter limit for farend detection. */
#define TX_REGFILE_0_CTRL3_CNTR_LIM_MASK 0x0000FFFF
/** field offset */
#define TX_REGFILE_0_CTRL3_CNTR_LIM_OFFSET 0

/* Fields of "Analog Control 1 Register" */
/** control_r
    Control bits for TX slice. */
#define TX_REGFILE_0_A_CTRL1_CTRL_MASK 0x0000FF00
/** field offset */
#define TX_REGFILE_0_A_CTRL1_CTRL_OFFSET 8
/** diffout_en_r
    Connects the drain of the differential input stage in the off-chip driver to the outputs tx_p_o and tx_n_o. */
#define TX_REGFILE_0_A_CTRL1_DIFFOUT_EN 0x00000010
/* Disable
#define TX_REGFILE_0_A_CTRL1_DIFFOUT_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_A_CTRL1_DIFFOUT_EN_EN 0x00000010
/** deemph_en_r
    Activates the De-Emphasis Mode in the SERIALIZER. */
#define TX_REGFILE_0_A_CTRL1_DEEMPH_EN 0x00000008
/* Disable
#define TX_REGFILE_0_A_CTRL1_DEEMPH_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_A_CTRL1_DEEMPH_EN_EN 0x00000008
/** clkmode_en_r
    Clock mode enable for PHY. */
#define TX_REGFILE_0_A_CTRL1_CLKMODE_EN 0x00000004
/* Disable
#define TX_REGFILE_0_A_CTRL1_CLKMODE_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_A_CTRL1_CLKMODE_EN_EN 0x00000004
/** clk_edge_sel_r
    Clock edge select for PHY. */
#define TX_REGFILE_0_A_CTRL1_CLK_EDGE_SEL 0x00000002
/** clk_byp_en_r
    Clock bypass enable for PHY. */
#define TX_REGFILE_0_A_CTRL1_CLK_BYP_EN 0x00000001
/* Disable
#define TX_REGFILE_0_A_CTRL1_CLK_BYP_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_A_CTRL1_CLK_BYP_EN_EN 0x00000001

/* Fields of "Analog Control 2 Register" */
/** ser_en_r
    Enables the SERIALIZER, Active High. */
#define TX_REGFILE_0_A_CTRL2_SER_EN 0x00008000
/** predrv_ser_en_r
    Selects total width of NMOS FETs in series to PMOS in the the predriver outputs. They are used to regulate the high level of the predriver output signals. Numbers of activated fingers (each finger = 210n/50n). */
#define TX_REGFILE_0_A_CTRL2_PREDRV_SER_EN_MASK 0x00007F00
/** field offset */
#define TX_REGFILE_0_A_CTRL2_PREDRV_SER_EN_OFFSET 8
/** predrv_par_en_r
    Selects total width of pull down NMOS FETs in parallel to the predriver outputs. Numbers of activated fingers (each finger = 110n/50n). */
#define TX_REGFILE_0_A_CTRL2_PREDRV_PAR_EN_MASK 0x000000F0
/** field offset */
#define TX_REGFILE_0_A_CTRL2_PREDRV_PAR_EN_OFFSET 4
/** iout_r
    Programs the current value in the off-chip driver. */
#define TX_REGFILE_0_A_CTRL2_IOUT_MASK 0x0000000F
/** field offset */
#define TX_REGFILE_0_A_CTRL2_IOUT_OFFSET 0

/* Fields of "Modulation Configuration 1 Register" */
/** skew_period_flip
    if mod_out_flip_i = 0, skew_period_flip_i = 0 will add skew to down */
#define TX_REGFILE_0_MOD1_SKEW_PERIOD_FLIP 0x00002000
/** Mod_out_skew_en
    Enable skew to CDR CTRL */
#define TX_REGFILE_0_MOD1_SKEW_EN 0x00001000
/** Mod_flip
    Bit to flip the CDR CTRL to start modulation pulses with up or down */
#define TX_REGFILE_0_MOD1_FLIP 0x00000800
/** Modulation Period */
#define TX_REGFILE_0_MOD1_PERIOD_MASK 0x000007FF
/** field offset */
#define TX_REGFILE_0_MOD1_PERIOD_OFFSET 0

/* Fields of "Modulation Configuration 2 Register" */
/** Skew Period
    The user defined occurance period for skew. */
#define TX_REGFILE_0_MOD2_SKEW_PERIOD_MASK 0x0000FFFF
/** field offset */
#define TX_REGFILE_0_MOD2_SKEW_PERIOD_OFFSET 0

/* Fields of "Modulation Configuration 3 Register" */
/** mod_en_r
    Modulation enable for PHY. */
#define TX_REGFILE_0_MOD3_MOD_EN 0x00000400
/* Disable
#define TX_REGFILE_0_MOD3_MOD_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_MOD3_MOD_EN_EN 0x00000400
/** Modulation Override
    Modulation override enable for PHY. */
#define TX_REGFILE_0_MOD3_MOD_OVR 0x00000200
/** BIST Modulation Enable
    Bist modulation enable for PHY. */
#define TX_REGFILE_0_MOD3_BIST_MOD_EN 0x00000100
/* Disable
#define TX_REGFILE_0_MOD3_BIST_MOD_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_0_MOD3_BIST_MOD_EN_EN 0x00000100
/** Testbus Bist Enable
    Enables the BIST loop in PMD. */
#define TX_REGFILE_0_MOD3_TESTBUS_BIST_EN 0x00000080
/** Testbus Enable
    Enables Test bus in PMD. */
#define TX_REGFILE_0_MOD3_TESTBUS_EN 0x00000040
/** Modulation pulses
    The number of up or down modulation pulses. */
#define TX_REGFILE_0_MOD3_AMP_MASK 0x0000003F
/** field offset */
#define TX_REGFILE_0_MOD3_AMP_OFFSET 0

/* Fields of "Control 1 Register" */
/** ei_ovr_r
    Override enable bit for EI_EN and EIN_EN. */
#define TX_REGFILE_1_CTRL1_EI_OVR 0x00004000
/* Override Disable
#define TX_REGFILE_1_CTRL1_EI_OVR_DIS 0x00000000 */
/** Override Enable */
#define TX_REGFILE_1_CTRL1_EI_OVR_EN 0x00004000
/** pi_ctrl_r
    For pi_ctrl. */
#define TX_REGFILE_1_CTRL1_PI_CTRL_MASK 0x00003F00
/** field offset */
#define TX_REGFILE_1_CTRL1_PI_CTRL_OFFSET 8
/** ein_en_r
    Used to select the sign of the SERIALIZER outputs when EI_EN is high. Pay attention that the signal of the serializer output is inverted into the offchip. */
#define TX_REGFILE_1_CTRL1_EIN_EN 0x00000080
/* Disable
#define TX_REGFILE_1_CTRL1_EIN_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_CTRL1_EIN_EN_EN 0x00000080
/** halfrate_r
    Enable half rate data transmission. */
#define TX_REGFILE_1_CTRL1_HALFRATE 0x00000040
/** flip_r
    Flip the data. */
#define TX_REGFILE_1_CTRL1_FLIP 0x00000020
/** load_r
    For PI control circuit's loading of PI_CTRL value. */
#define TX_REGFILE_1_CTRL1_LOAD 0x00000010
/** force_r
    Force farend detection. */
#define TX_REGFILE_1_CTRL1_FORCE 0x00000008
/** ei_en_r
    Forces the ouptut of the SERIALIZER either to High or to Low depending on the value of the EIN_EN. */
#define TX_REGFILE_1_CTRL1_EI_EN 0x00000004
/* Disable
#define TX_REGFILE_1_CTRL1_EI_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_CTRL1_EI_EN_EN 0x00000004
/** Invert Enable
    Enables the inversion of data. */
#define TX_REGFILE_1_CTRL1_INV_EN 0x00000002
/* Disable
#define TX_REGFILE_1_CTRL1_INV_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_CTRL1_INV_EN_EN 0x00000002
/** Enable
    Enable bit. */
#define TX_REGFILE_1_CTRL1_EN 0x00000001
/* Disable
#define TX_REGFILE_1_CTRL1_EN_DIS 0x00000000 */

/* Fields of "TX Control 2 Register" */
/** rterm_r
    Configures termination resistors in PHY. */
#define TX_REGFILE_1_CTRL2_RTERM_MASK 0x00003E00
/** field offset */
#define TX_REGFILE_1_CTRL2_RTERM_OFFSET 9
/** Enable Programmable TX Data
    Enable Programmable Data for TX. */
#define TX_REGFILE_1_CTRL2_PRG_EN 0x00000100
/* Disable
#define TX_REGFILE_1_CTRL2_PRG_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_CTRL2_PRG_EN_EN 0x00000100
/** Programmable TX Data
    Programmable Data for TX to PHY. */
#define TX_REGFILE_1_CTRL2_PRG_DATA_MASK 0x000000FF
/** field offset */
#define TX_REGFILE_1_CTRL2_PRG_DATA_OFFSET 0

/* Fields of "Control 3 Register" */
/** counter_limit_r
    Counter limit for farend detection. */
#define TX_REGFILE_1_CTRL3_CNTR_LIM_MASK 0x0000FFFF
/** field offset */
#define TX_REGFILE_1_CTRL3_CNTR_LIM_OFFSET 0

/* Fields of "Analog Control 1 Register" */
/** control_r
    Control bits for TX slice. */
#define TX_REGFILE_1_A_CTRL1_CTRL_MASK 0x0000FF00
/** field offset */
#define TX_REGFILE_1_A_CTRL1_CTRL_OFFSET 8
/** diffout_en_r
    Connects the drain of the differential input stage in the off-chip driver to the outputs tx_p_o and tx_n_o. */
#define TX_REGFILE_1_A_CTRL1_DIFFOUT_EN 0x00000010
/* Disable
#define TX_REGFILE_1_A_CTRL1_DIFFOUT_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_A_CTRL1_DIFFOUT_EN_EN 0x00000010
/** deemph_en_r
    Activates the De-Emphasis Mode in the SERIALIZER. */
#define TX_REGFILE_1_A_CTRL1_DEEMPH_EN 0x00000008
/* Disable
#define TX_REGFILE_1_A_CTRL1_DEEMPH_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_A_CTRL1_DEEMPH_EN_EN 0x00000008
/** clkmode_en_r
    Clock mode enable for PHY. */
#define TX_REGFILE_1_A_CTRL1_CLKMODE_EN 0x00000004
/* Disable
#define TX_REGFILE_1_A_CTRL1_CLKMODE_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_A_CTRL1_CLKMODE_EN_EN 0x00000004
/** clk_edge_sel_r
    Clock edge select for PHY. */
#define TX_REGFILE_1_A_CTRL1_CLK_EDGE_SEL 0x00000002
/** clk_byp_en_r
    Clock bypass enable for PHY. */
#define TX_REGFILE_1_A_CTRL1_CLK_BYP_EN 0x00000001
/* Disable
#define TX_REGFILE_1_A_CTRL1_CLK_BYP_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_A_CTRL1_CLK_BYP_EN_EN 0x00000001

/* Fields of "Analog Control 2 Register" */
/** ser_en_r
    Enables the SERIALIZER, Active High. */
#define TX_REGFILE_1_A_CTRL2_SER_EN 0x00008000
/** predrv_ser_en_r
    Selects total width of NMOS FETs in series to PMOS in the the predriver outputs. They are used to regulate the high level of the predriver output signals. Numbers of activated fingers (each finger = 210n/50n). */
#define TX_REGFILE_1_A_CTRL2_PREDRV_SER_EN_MASK 0x00007F00
/** field offset */
#define TX_REGFILE_1_A_CTRL2_PREDRV_SER_EN_OFFSET 8
/** predrv_par_en_r
    Selects total width of pull down NMOS FETs in parallel to the predriver outputs. Numbers of activated fingers (each finger = 110n/50n). */
#define TX_REGFILE_1_A_CTRL2_PREDRV_PAR_EN_MASK 0x000000F0
/** field offset */
#define TX_REGFILE_1_A_CTRL2_PREDRV_PAR_EN_OFFSET 4
/** iout_r
    Programs the current value in the off-chip driver. */
#define TX_REGFILE_1_A_CTRL2_IOUT_MASK 0x0000000F
/** field offset */
#define TX_REGFILE_1_A_CTRL2_IOUT_OFFSET 0

/* Fields of "Modulation Configuration 1 Register" */
/** skew_period_flip
    if mod_out_flip_i = 0, skew_period_flip_i = 0 will add skew to down */
#define TX_REGFILE_1_MOD1_SKEW_PERIOD_FLIP 0x00002000
/** Mod_out_skew_en
    Enable skew to CDR CTRL */
#define TX_REGFILE_1_MOD1_SKEW_EN 0x00001000
/** Mod_flip
    Bit to flip the CDR CTRL to start modulation pulses with up or down */
#define TX_REGFILE_1_MOD1_FLIP 0x00000800
/** Modulation Period */
#define TX_REGFILE_1_MOD1_PERIOD_MASK 0x000007FF
/** field offset */
#define TX_REGFILE_1_MOD1_PERIOD_OFFSET 0

/* Fields of "Modulation Configuration 2 Register" */
/** Skew Period
    The user defined occurance period for skew. */
#define TX_REGFILE_1_MOD2_SKEW_PERIOD_MASK 0x0000FFFF
/** field offset */
#define TX_REGFILE_1_MOD2_SKEW_PERIOD_OFFSET 0

/* Fields of "Modulation Configuration 3 Register" */
/** mod_en_r
    Modulation enable for PHY. */
#define TX_REGFILE_1_MOD3_MOD_EN 0x00000400
/* Disable
#define TX_REGFILE_1_MOD3_MOD_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_MOD3_MOD_EN_EN 0x00000400
/** Modulation Override
    Modulation override enable for PHY. */
#define TX_REGFILE_1_MOD3_MOD_OVR 0x00000200
/** BIST Modulation Enable
    Bist modulation enable for PHY. */
#define TX_REGFILE_1_MOD3_BIST_MOD_EN 0x00000100
/* Disable
#define TX_REGFILE_1_MOD3_BIST_MOD_EN_DIS 0x00000000 */
/** Enable */
#define TX_REGFILE_1_MOD3_BIST_MOD_EN_EN 0x00000100
/** Testbus Bist Enable
    Enables the BIST loop in PMD. */
#define TX_REGFILE_1_MOD3_TESTBUS_BIST_EN 0x00000080
/** Testbus Enable
    Enables Test bus in PMD. */
#define TX_REGFILE_1_MOD3_TESTBUS_EN 0x00000040
/** Modulation pulses
    The number of up or down modulation pulses. */
#define TX_REGFILE_1_MOD3_AMP_MASK 0x0000003F
/** field offset */
#define TX_REGFILE_1_MOD3_AMP_OFFSET 0

/* Fields of "RX Control 1 Register" */
/** halfrate_r
    Enable half rate data transmission. */
#define RX_REGFILE_CTRL1_HALFRATE 0x00008000
/** flip_r
    Flip the data. */
#define RX_REGFILE_CTRL1_FLIP 0x00004000
/** pi_ctrl_r
    PI control value for loading. */
#define RX_REGFILE_CTRL1_PI_CTRL_MASK 0x00003F00
/** field offset */
#define RX_REGFILE_CTRL1_PI_CTRL_OFFSET 8
/** sel_offset_r
    Control bits for CML offset calibration. */
#define RX_REGFILE_CTRL1_SEL_OFFSET_MASK 0x000000F0
/** field offset */
#define RX_REGFILE_CTRL1_SEL_OFFSET_OFFSET 4
/** For bypassing SEL_OFFSET. */
#define RX_REGFILE_CTRL1_BYPASS 0x00000008
/* Disable
#define RX_REGFILE_CTRL1_BYPASS_DIS 0x00000000 */
/** Enable */
#define RX_REGFILE_CTRL1_BYPASS_EN 0x00000008
/** Invert Enable
    Enables the inversion of RX data. */
#define RX_REGFILE_CTRL1_INV_EN 0x00000004
/** load_r
    For PI control circuit's loading of PI_CTRL value. */
#define RX_REGFILE_CTRL1_LOAD 0x00000002
/** Enable
    Enable bit. */
#define RX_REGFILE_CTRL1_EN 0x00000001
/* Disable
#define RX_REGFILE_CTRL1_EN_DIS 0x00000000 */

/* Fields of "RX Control 2 Register" */
/** rterm_r
    Configures termination resistors in PHY. */
#define RX_REGFILE_CTRL2_RTERM_MASK 0x00003E00
/** field offset */
#define RX_REGFILE_CTRL2_RTERM_OFFSET 9
/** Enable Programmable RX Data
    Enable Programmable Data for RX. */
#define RX_REGFILE_CTRL2_PRG_EN 0x00000100
/* Disable
#define RX_REGFILE_CTRL2_PRG_EN_DIS 0x00000000 */
/** Enable */
#define RX_REGFILE_CTRL2_PRG_EN_EN 0x00000100
/** Programmable RX Data
    Programmable Data for RX. */
#define RX_REGFILE_CTRL2_DATA_MASK 0x000000FF
/** field offset */
#define RX_REGFILE_CTRL2_DATA_OFFSET 0

/* Fields of "CDR Configuration Register" */
/** sum_int
    SUM_INT. */
#define RX_REGFILE_CDR_SUM_INT 0x00000200
/** xor_inv
    XOR_INV. */
#define RX_REGFILE_CDR_XOR_INV 0x00000100
/** dumpint
    dumpint. */
#define RX_REGFILE_CDR_DUMPINT_MASK 0x00000070
/** field offset */
#define RX_REGFILE_CDR_DUMPINT_OFFSET 4
/** comp
    Comp. */
#define RX_REGFILE_CDR_COMP_MASK 0x00000007
/** field offset */
#define RX_REGFILE_CDR_COMP_OFFSET 0

/* Fields of "EI Register" */
/** ei_endcount_r
    End count for EI detection timeout. */
#define RX_REGFILE_EI_ENDCNT_MASK 0x0000FFFF
/** field offset */
#define RX_REGFILE_EI_ENDCNT_OFFSET 0

/* Fields of "CAL Register" */
/** cal_fail_r
    Status bit for calibration failure. */
#define RX_REGFILE_CAL_CAL_FAIL 0x00000200
/** inv_dir_r
    For inverting direction of calibration (when data is inverted). */
#define RX_REGFILE_CAL_INV_DIR 0x00000100
/** comp_count_r
    Limit for comparison -> hysteresis. */
#define RX_REGFILE_CAL_COMP_CNT_MASK 0x000000F0
/** field offset */
#define RX_REGFILE_CAL_COMP_CNT_OFFSET 4
/** smp_count_r
    Number of samples to count. */
#define RX_REGFILE_CAL_SMP_CNT_MASK 0x0000000F
/** field offset */
#define RX_REGFILE_CAL_SMP_CNT_OFFSET 0

/* Fields of "Analog Control Register" */
/** output_cm_sel_r
    Set common mode level of levelshifter output. */
#define RX_REGFILE_A_CTRL_OUTPUT_CM_SEL_MASK 0x00007000
/** field offset */
#define RX_REGFILE_A_CTRL_OUTPUT_CM_SEL_OFFSET 12
/** RX Data Deemphasis Control. */
#define RX_REGFILE_A_CTRL_EMP_MASK 0x00000C00
/** field offset */
#define RX_REGFILE_A_CTRL_EMP_OFFSET 10
/** double_tailcur_r
    Use double tailcurrent in cml amplifier. */
#define RX_REGFILE_A_CTRL_DB_TAILCUR 0x00000200
/** cdr_on_n_r
    Edge detector control. */
#define RX_REGFILE_A_CTRL_CDR_ON_N 0x00000100
/** control_r
    Control bits for RX slice. */
#define RX_REGFILE_A_CTRL_CTRL_MASK 0x000000FF
/** field offset */
#define RX_REGFILE_A_CTRL_CTRL_OFFSET 0

/* Fields of "Test Control Register" */
/** Testbus Bist Enable
    Enables the BIST loop in PMD. */
#define RX_REGFILE_TEST_CTRL_TESTBUS_BIST_EN 0x00000002
/* Disable
#define RX_REGFILE_TEST_CTRL_TESTBUS_BIST_EN_DIS 0x00000000 */
/** Enable */
#define RX_REGFILE_TEST_CTRL_TESTBUS_BIST_EN_EN 0x00000002
/** Testbus Enable
    Enables Test bus in PMD. */
#define RX_REGFILE_TEST_CTRL_TESTBUS_EN 0x00000001
/* Disable
#define RX_REGFILE_TEST_CTRL_TESTBUS_EN_DIS 0x00000000 */
/** Enable */
#define RX_REGFILE_TEST_CTRL_TESTBUS_EN_EN 0x00000001

/*! @} */ /* SGMII_REGISTER */

#endif /* _sgmii_reg_h */
