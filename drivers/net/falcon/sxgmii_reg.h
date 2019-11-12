/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _sxgmii_reg_h
#define _sxgmii_reg_h

/** \addtogroup SXGMII_REGISTER
   @{
*/
/* access macros */
#define sxgmii_r32(reg) reg_r32(&sxgmii->reg)
#define sxgmii_w32(val, reg) reg_w32(val, &sxgmii->reg)
#define sxgmii_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &sxgmii->reg)
#define sxgmii_r32_table(reg, idx) reg_r32_table(sxgmii->reg, idx)
#define sxgmii_w32_table(val, reg, idx) reg_w32_table(val, sxgmii->reg, idx)
#define sxgmii_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, sxgmii->reg, idx)
#define sxgmii_adr_table(reg, idx) adr_table(sxgmii->reg, idx)


/** SXGMII register structure */
struct gpon_reg_sxgmii
{
   /** TBI_PDI: TBI Submodule PDI Register File */
   /** Transmit Register Autonegotiation Bit(15:8)
       Not Specified */
   unsigned int tbi_pdi_txanegh; /* 0x00000000 */
   /** Transmit Register Autonegotiation Bit(7:0)
       Not Specified */
   unsigned int tbi_pdi_txanegl; /* 0x00000004 */
   /** Receive Register Autonegotioation Bit(15:8)
       Not Specified */
   unsigned int tbi_pdi_rxanegh; /* 0x00000008 */
   /** Receive Register Autonegotioation Bit(7:0)
       Not Specified */
   unsigned int tbi_pdi_rxanegl; /* 0x0000000C */
   /** Autonegotioation Control Bits of TBI
       Not Specified */
   unsigned int tbi_pdi_anegctl; /* 0x00000010 */
   /** TBI Control Bits
       Not Specified */
   unsigned int tbi_pdi_tbictl; /* 0x00000014 */
   /** TBI Control Bits TX
       Not Specified */
   unsigned int tbi_pdi_tbictlt; /* 0x00000018 */
   /** TBI TEST Control Bits
       Not Specified */
   unsigned int tbi_pdi_tbitest; /* 0x0000001C */
   /** RX Error Counter
       Not Specified */
   unsigned int tbi_pdi_rxerr; /* 0x00000020 */
   /** TBI Status Register
       Not Specified */
   unsigned int tbi_pdi_tbistat; /* 0x00000024 */
   /** Link Partner Status Register
       Not Specified */
   unsigned int tbi_pdi_lpstat; /* 0x00000028 */
   /** Interrupt Status Register
       Not Specified */
   unsigned int tbi_pdi_istat; /* 0x0000002C */
   /** Interrupt Mask Register
       Not Specified */
   unsigned int tbi_pdi_imask; /* 0x00000030 */
   /** S_SGMII_PCS_PDI: SGMII PCS PDI Register File */
   /** Configuration Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_cfg; /* 0x00000034 */
   /** Receive Buffer Control Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_rxbctrl; /* 0x00000038 */
   /** Receive Buffer Configuration Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_rxbcfg; /* 0x0000003C */
   /** Receive Buffer Status Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_rxbstat; /* 0x00000040 */
   /** Transmit Buffer Control Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_txbctrl; /* 0x00000044 */
   /** Transmit Buffer Configuration Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_txbcfg; /* 0x00000048 */
   /** Transmit Buffer Status Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_txbstat; /* 0x0000004C */
   /** Debug Control Register
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_dbgctl; /* 0x00000050 */
   /** SCR1 LSFR Feeback Bit Select
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_scr1bs[4]; /* 0x00000054 */
   /** SCR2 LSFR Feeback Bit Select
       Not Specified */
   unsigned int s_sgmii_pcs_pdi_scr2bs[39]; /* 0x00000064 */
};


/* Fields of "Transmit Register Autonegotiation Bit(15:8)" */
/** Next Page
    The NP bit is used by the Next Page function to indicate whether or not this is the last page to be transmitted */
#define TXANEGH_NP 0x00000080
/* Last Page
#define TXANEGH_NP_LAST 0x00000000 */
/** Additional next page to follow */
#define TXANEGH_NP_NEXT 0x00000080
/** Higher Data or Control Bits for Autonegotiation */
#define TXANEGH_DATAH_MASK 0x0000003F
/** field offset */
#define TXANEGH_DATAH_OFFSET 0

/* Fields of "Transmit Register Autonegotiation Bit(7:0)" */
/** Lower Data or Control Bits for Autonegotiation
    The TXANEGL must be written after TXANEGH. Writing to that register updates the TX Transmit Register. If Next Page is supported the Controler must write to that Register to go to NEXT_PAGE_WAIT state in ANEG FSM after ANEG Interrupt; */
#define TXANEGL_DATAL_MASK 0x000000FF
/** field offset */
#define TXANEGL_DATAL_OFFSET 0

/* Fields of "Receive Register Autonegotioation Bit(15:8)" */
/** Next Page
    The NP bit is used by the Next Page function to indicate whether or not this is the last page to be transmitted */
#define RXANEGH_NP 0x00000080
/* Last Page
#define RXANEGH_NP_LAST 0x00000000 */
/** Additional next page to follow */
#define RXANEGH_NP_NEXT 0x00000080
/** Acknowledge */
#define RXANEGH_ACK 0x00000040
/* No Acknowlegde received
#define RXANEGH_ACK_NAK 0x00000000 */
/** Higher Data or Control Bits for Autonegotiation */
#define RXANEGH_DATAH_MASK 0x0000003F
/** field offset */
#define RXANEGH_DATAH_OFFSET 0

/* Fields of "Receive Register Autonegotioation Bit(7:0)" */
/** Lower Data or Control Bits for Autonegotiation */
#define RXANEGL_DATAL_MASK 0x000000FF
/** field offset */
#define RXANEGL_DATAL_OFFSET 0

/* Fields of "Autonegotioation Control Bits of TBI" */
/** Override Ability */
#define ANEGCTL_OVRANEG 0x00000020
/* ANEGEN, RAENG are taken from Hardware Interface
#define ANEGCTL_OVRANEG_HW_INT 0x00000000 */
/** Override, ANEGEN RANEG are taken from Registerbits ANEGEN, RANEG */
#define ANEGCTL_OVRANEG_OVERRIDE 0x00000020
/** Override Ability
    If OVRAB is 1 the TX values are taken from Register TXANEGH and TXANEGL */
#define ANEGCTL_OVRABL 0x00000010
/* Ability Values are taken from Hardware Interface
#define ANEGCTL_OVRABL_HW_INT 0x00000000 */
/** Override, Ability Values are taken from Registers TXANEGH and TXANEGL */
#define ANEGCTL_OVRABL_OVERRIDE 0x00000010
/** Restart Autonegotiation Process
    Bit is cleared by Hardware after FSM Restarts */
#define ANEGCTL_RANEG 0x00000008
/* Normal Operation
#define ANEGCTL_RANEG_NORMAL 0x00000000 */
/** Restart Autonegotiation Process */
#define ANEGCTL_RANEG_RESTART 0x00000008
/** Auto-Negotiation Enable
    Enable Autonegotiation for TBI Interface */
#define ANEGCTL_ANEGEN 0x00000004
/* Autonegotiation is disabled
#define ANEGCTL_ANEGEN_DISABLE 0x00000000 */
/** Autonegotiation is enabled */
#define ANEGCTL_ANEGEN_ENABLE 0x00000004
/** Link Timer Value
    Link Timer Values for TBI ANEG FSM. Required Value for Standard TBI is 10 ms */
#define ANEGCTL_LT_MASK 0x00000003
/** field offset */
#define ANEGCTL_LT_OFFSET 0
/** Timer Delay is 10 us (Simulation) */
#define ANEGCTL_LT_T_10US 0x00000000
/** Timer Delay is 1.6 ms (SGMII) */
#define ANEGCTL_LT_T_1_6MS 0x00000001
/** Timer Delay is 5 ms */
#define ANEGCTL_LT_T_5MS 0x00000002
/** Timer Delay is 10 ms (TBI) */
#define ANEGCTL_LT_T_10MS 0x00000003

/* Fields of "TBI Control Bits" */
/** Reverse Bit Order Output
    Output of 10 Bit encoder is (9:0) or (0:9) */
#define TBICTL_RVBO 0x00000080
/* 10 Bit Output according to Standard
#define TBICTL_RVBO_NORMAL 0x00000000 */
/** 10 Bit Output with reversed Bit Order */
#define TBICTL_RVBO_REVERS 0x00000080
/** Reverse Bit Order Input
    Input for 10 Bit decoder is (9:0) or (0:9) */
#define TBICTL_RVBI 0x00000040
/* 10 Bit Input according to Standard
#define TBICTL_RVBI_NORMAL 0x00000000 */
/** 10 Bit Input with reversed Bit Order */
#define TBICTL_RVBI_REVERS 0x00000040
/** Carrier Sense OFF
    CRS Generation can be switched off especially for device which habe trouble with that in Half Duplex mode */
#define TBICTL_CRSOFF 0x00000020
/* Carrier Sense is always generated in HD and FD
#define TBICTL_CRSOFF_ON 0x00000000 */
/** Carrier Sense is never generated, forced to 0 */
#define TBICTL_CRSOFF_OFF 0x00000020
/** Carrier Sense Extension for Sequence T/R/R/
    Select Generation of Carrier Extension in Case of TBI Sequence /T/R/R/K28.5 according to Figure 36-7b of IEEE Std 802.3 */
#define TBICTL_CRSTRR 0x00000010
/* No Generate Carrier Extension
#define TBICTL_CRSTRR_NO 0x00000000 */
/** Generate Carrier Extension */
#define TBICTL_CRSTRR_YES 0x00000010
/** Repeater Mode of TBI
    Enable Repeater Operation for TBI Interface */
#define TBICTL_RPM 0x00000008
/* normal operation
#define TBICTL_RPM_NORMAL 0x00000000 */
/** repeater mode enabled */
#define TBICTL_RPM_REPEATER 0x00000008
/** Loopback Mode of TBI
    Enable Loopback Operation for TBI Interface */
#define TBICTL_LPB 0x00000004
/* normal operation
#define TBICTL_LPB_NORMAL 0x00000000 */
/** loopback enabled */
#define TBICTL_LPB_LOOPBACK 0x00000004
/** Enable of TBI Interface
    Set to 1 for normal operation, if DISABLE the interface clock is disabled */
#define TBICTL_ENTBI 0x00000002
/* TBI Interface is disabled
#define TBICTL_ENTBI_DISABLE 0x00000000 */
/** TBI Interface is enabled */
#define TBICTL_ENTBI_ENABLE 0x00000002
/** Reset of TBI FSM's
    Reset TBI Interface */
#define TBICTL_INITTBI 0x00000001
/* normal operation
#define TBICTL_INITTBI_NORMAL 0x00000000 */
/** Initialisation of TBI */
#define TBICTL_INITTBI_INIT 0x00000001

/* Fields of "TBI Control Bits TX" */
/** Transmit False Carrier Insertion
    Select False Carrier Insertion in Case of Transmit according to Figure 36-5 of IEEE Std 802.3 in state XMI_DATA */
#define TBICTLT_TXFS 0x00000001
/* No False Carrier Insertion
#define TBICTLT_TXFS_NO 0x00000000 */
/** False Carrier Insertion */
#define TBICTLT_TXFS_YES 0x00000001

/* Fields of "TBI TEST Control Bits" */
/** Enable RX Error Counter
    IF enabled the errors from 8b10b Decoder are counted */
#define TBITEST_RXEREN 0x00000004
/* RX Error Counter is disabled
#define TBITEST_RXEREN_DSIABLE 0x00000000 */
/** RX Error Counter is enabled */
#define TBITEST_RXEREN_ENABLE 0x00000004
/** Jitter Test pattern for Transmit
    IF set the tespattern according to IEEE Std 802.3 chapter 36 A are transmitted */
#define TBITEST_JITE_MASK 0x00000003
/** field offset */
#define TBITEST_JITE_OFFSET 0
/** Normal Function */
#define TBITEST_JITE_NO 0x00000000
/** Transmit High Freuency test pattern 36A.1 */
#define TBITEST_JITE_HIGH 0x00000001
/** Transmit Low Freuency test pattern 36A.2 */
#define TBITEST_JITE_LOW 0x00000002
/** Transmit Low Freuency test pattern 36A.2 */
#define TBITEST_JITE_MIXED 0x00000003

/* Fields of "RX Error Counter" */
/** RX Error Counter
    If enabled the recieve errors detected by the 8b10b Decoder are counted. The register is cleared by READ */
#define RXERR_RXERRC_MASK 0x000000FF
/** field offset */
#define RXERR_RXERRC_OFFSET 0

/* Fields of "TBI Status Register" */
/** Sync Status of TBI
    Sync status of TBI */
#define TBISTAT_SSTAT 0x00000008
/* Sync Status of TBI is not OK
#define TBISTAT_SSTAT_NOK 0x00000000 */
/** SYnc Status of TBI is OK */
#define TBISTAT_SSTAT_OK 0x00000008
/** Autonegotiation Error
    Error Bit set if Abilities of local device and link partner do not match and connot be resolved this bit is set during Autonegotioation, if Autonegotiation is enabled */
#define TBISTAT_ANEGERR 0x00000004
/* No Autonegotiation Error
#define TBISTAT_ANEGERR_NO_ERROR 0x00000000 */
/** Autonegotiation Error */
#define TBISTAT_ANEGERR_ERROR 0x00000004
/** Link Status of TBI
    ability match status, if Autonegotiation is enabled */
#define TBISTAT_ABMSTAT 0x00000002
/* Autonegotiation State Machine ability does not match
#define TBISTAT_ABMSTAT_NOK 0x00000000 */
/** Autonegotiation State Machine ability match */
#define TBISTAT_ABMSTAT_OK 0x00000002
/** Link Status of TBI
    Autonegotiation State of TBI, if Autonegotiation is enabled */
#define TBISTAT_LSTAT 0x00000001
/* Autonegotiation State Machine is not in link_ok state
#define TBISTAT_LSTAT_NOK 0x00000000 */
/** Autonegotiation State Machine is in link_ok state */
#define TBISTAT_LSTAT_OK 0x00000001

/* Fields of "Link Partner Status Register" */
/** SGMII DATA RATE
    SGMII Data Rate at link partner, set by HW if OVRABL is DISABLED and ANEG is enabled by HW or SW, only valid in SGMII Mode */
#define LPSTAT_DR_MASK 0x00000060
/** field offset */
#define LPSTAT_DR_OFFSET 5
/** Data Rate is 10 Mb/s */
#define LPSTAT_DR_DR10 0x00000000
/** Data Rate is 100 Mb/s */
#define LPSTAT_DR_DR100 0x00000020
/** Data Rate is 1000 Mb/s */
#define LPSTAT_DR_DR1000 0x00000040
/** Not SGMII Mode */
#define LPSTAT_DR_INVALID 0x00000060
/** Remote Fault
    Remote Fault Status at link partner, set by HW if OVRABL is DISABLED and ANEG is enabled by HW or SW */
#define LPSTAT_RF_MASK 0x00000018
/** field offset */
#define LPSTAT_RF_OFFSET 3
/** No Error, link OK */
#define LPSTAT_RF_LINK_OK 0x00000000
/** Link Failure, Link Down in SGMII Mode */
#define LPSTAT_RF_LINK_FAIL 0x00000008
/** Offline, not used in SGMII Mode */
#define LPSTAT_RF_OFFLINE 0x00000010
/** Autonegotiation_Error, not used in SGMII Mode */
#define LPSTAT_RF_ANEG_ERROR 0x00000018
/** Pause
    Pause Status after Autonegotiation Priority Resolution at link partner,set by HW if OVRABL is DISABLED and ANEG is enabled by HW or SW */
#define LPSTAT_PS_MASK 0x00000006
/** field offset */
#define LPSTAT_PS_OFFSET 1
/** No Pause */
#define LPSTAT_PS_NO 0x00000000
/** Receive PAUSE */
#define LPSTAT_PS_RECEIVE 0x00000002
/** Transmit PAUSE */
#define LPSTAT_PS_TRANSMIT 0x00000004
/** Receive and Transmit PAUSE */
#define LPSTAT_PS_BOTH 0x00000006
/** Duplex Status
    Duplex Status after Autonegotiation Priority Resolution, set by HW if OVRABL is DISABLED and ANEG is enabled by HW or SW */
#define LPSTAT_DPX 0x00000001
/* Half Duplex Mode
#define LPSTAT_DPX_HD 0x00000000 */
/** Full Duplex Mode */
#define LPSTAT_DPX_FD 0x00000001

/* Fields of "Interrupt Status Register" */
/** Link Status Change
    The current status of the link has changed either from OK to NOK or vice versa. The value in TBISTAT.LSTAT has been updated. */
#define ISTAT_LKSC 0x00000004
/** Autonegotiation Interrupt Next Page
    Interrupt generated from Autonegotiation when in COMPLETE_ACKNOWLEDGE state and a next page has been transferred */
#define ISTAT_ANEG_NP 0x00000002
/** Autonegotiation Interrupt Base Page
    Interrupt generated from Autonegotiation when in COMPLETE_ACKNOWLEDGE state and the base page has been transferred */
#define ISTAT_ANEG_BP 0x00000001

/* Fields of "Interrupt Mask Register" */
/** Link Statsu change */
#define IMASK_MLKSC 0x00000004
/* Unmask LKSC Interrupt
#define IMASK_MLKSC_UMASK 0x00000000 */
/** Mask LKSC Interrupt */
#define IMASK_MLKSC_MASK 0x00000004
/** Mask Autonegotiation Next Page */
#define IMASK_MANEG_NP 0x00000002
/* Unmask Autonegotiation Interrupt
#define IMASK_MANEG_NP_UMASK 0x00000000 */
/** Mask Autonegotiation Interrupt */
#define IMASK_MANEG_NP_MASK 0x00000002
/** Mask Autonegotiation Base Page */
#define IMASK_MANEG_BP 0x00000001
/* Unmask Autonegotiation Interrupt
#define IMASK_MANEG_BP_UMASK 0x00000000 */
/** Mask Autonegotiation Interrupt */
#define IMASK_MANEG_BP_MASK 0x00000001

/* Fields of "Configuration Register" */
/** Loop Back RX to TX PATH
    Not Specified */
#define CFG_LPB 0x00000040
/* Normal Operation TX
#define CFG_LPB_NORMAL 0x00000000 */
/** Loop Back RX to TX Path */
#define CFG_LPB_LOOP 0x00000040
/** INIT SGMII RX PATH
    Not Specified */
#define CFG_INITRX 0x00000020
/* Normal Operation TX
#define CFG_INITRX_NORMAL 0x00000000 */
/** Reset RX Path */
#define CFG_INITRX_INIT 0x00000020
/** INIT SGMII TX PATH
    Not Specified */
#define CFG_INITTX 0x00000010
/* Normal Operation TX
#define CFG_INITTX_NORMAL 0x00000000 */
/** Reset TX Path */
#define CFG_INITTX_INIT 0x00000010
/** RTE Enable
    Not Specified */
#define CFG_RTE_EN 0x00000008
/* Disable RTE
#define CFG_RTE_EN_DISABLE 0x00000000 */
/** Enable RTE */
#define CFG_RTE_EN_ENABLE 0x00000008
/** Disable LVDS pair O_N, O_P
    Not Specified */
#define CFG_D_DIS 0x00000004
/* Enable LVDS pair
#define CFG_D_DIS_ENABLE 0x00000000 */
/** Disable LVDS pair */
#define CFG_D_DIS_DISABLE 0x00000004
/** Disable LVDS pair C_N, C_P
    Not Specified */
#define CFG_C_DIS 0x00000002
/* Enable LVDS pair
#define CFG_C_DIS_ENABLE 0x00000000 */
/** Disable LVDS pair */
#define CFG_C_DIS_DISABLE 0x00000002
/** Clock Selection
    Not Specified */
#define CFG_CLKSEL 0x00000001
/* Select TXC_LFCLK
#define CFG_CLKSEL_TXC_LFCLK 0x00000000 */
/** Select TXD_LFCLK */
#define CFG_CLKSEL_TXD_LFCLK 0x00000001

/* Fields of "Receive Buffer Control Register" */
/** Initialize TXB
    Not Specified */
#define RXBCTRL_INIT 0x00000002
/* TXB is normally operating
#define RXBCTRL_INIT_NORMAL 0x00000000 */
/** TXB is initialized */
#define RXBCTRL_INIT_ACTIVE 0x00000002
/** Enable RXB
    If this control bit is disabled the RX Buffer will be disabled. */
#define RXBCTRL_ENAB 0x00000001
/* RXB is disabled
#define RXBCTRL_ENAB_DISABLE 0x00000000 */
/** RXB is enabled */
#define RXBCTRL_ENAB_ENABLE 0x00000001

/* Fields of "Receive Buffer Configuration Register" */
/** Delay
    This register is used to configure the initial delay of the READ POINTER in the RXB. */
#define RXBCFG_DLY_RP_MASK 0x00000038
/** field offset */
#define RXBCFG_DLY_RP_OFFSET 3
/** Delay
    This register is used to configure the initial delay of the WRITE POINTER pointer in the RXB. */
#define RXBCFG_DLY_WP_MASK 0x00000007
/** field offset */
#define RXBCFG_DLY_WP_OFFSET 0

/* Fields of "Receive Buffer Status Register" */
/** Underflow Indicator
    Not Specified */
#define RXBSTAT_UNFL 0x00000002
/* Underflow never detected
#define RXBSTAT_UNFL_NONE 0x00000000 */
/** Underflow occurred at least once */
#define RXBSTAT_UNFL_ONCE 0x00000002
/** Overflow Indicator
    Not Specified */
#define RXBSTAT_OVFL 0x00000001
/* Overflow never detected
#define RXBSTAT_OVFL_NONE 0x00000000 */
/** Overflow occurred at least once */
#define RXBSTAT_OVFL_ONCE 0x00000001

/* Fields of "Transmit Buffer Control Register" */
/** Initialize TXB
    Not Specified */
#define TXBCTRL_INIT 0x00000002
/* TXB is normally operating
#define TXBCTRL_INIT_NORMAL 0x00000000 */
/** TXB is initialized */
#define TXBCTRL_INIT_ACTIVE 0x00000002
/** Enable TXB
    If this control bit is disabled the TX Buffer will be disabled. */
#define TXBCTRL_ENAB 0x00000001
/* TXB is disabled
#define TXBCTRL_ENAB_DISABLE 0x00000000 */
/** TXB is enabled */
#define TXBCTRL_ENAB_ENABLE 0x00000001

/* Fields of "Transmit Buffer Configuration Register" */
/** Delay
    This register is used to configure the initial delay of the READ POINTER in the TXB. */
#define TXBCFG_DLY_RP_MASK 0x00000038
/** field offset */
#define TXBCFG_DLY_RP_OFFSET 3
/** Delay
    This register is used to configure the initial delay of the WRITE POINTER in the TXB. */
#define TXBCFG_DLY_WP_MASK 0x00000007
/** field offset */
#define TXBCFG_DLY_WP_OFFSET 0

/* Fields of "Transmit Buffer Status Register" */
/** Underflow Indicator
    Not Specified */
#define TXBSTAT_UNFL 0x00000002
/* Underflow never detected
#define TXBSTAT_UNFL_NONE 0x00000000 */
/** Underflow occurred at least once */
#define TXBSTAT_UNFL_ONCE 0x00000002
/** Overflow Indicator
    Not Specified */
#define TXBSTAT_OVFL 0x00000001
/* Overflow never detected
#define TXBSTAT_OVFL_NONE 0x00000000 */
/** Overflow occurred at least once */
#define TXBSTAT_OVFL_ONCE 0x00000001

/* Fields of "Debug Control Register" */
/** SRC1 Enable
    Enable of SRC2 */
#define DBGCTL_SRC2EN 0x00000004
/* Disable SCR2 Mode
#define DBGCTL_SRC2EN_DISABLE 0x00000000 */
/** Enable SCR2 Mode */
#define DBGCTL_SRC2EN_ENABLE 0x00000004
/** SRC1 Enable
    Enable of SRC1 */
#define DBGCTL_SRC1EN 0x00000002
/* Disable SCR1 Mode
#define DBGCTL_SRC1EN_DISABLE 0x00000000 */
/** Enable SCR1 Mode */
#define DBGCTL_SRC1EN_ENABLE 0x00000002
/** Debug Enable
    Enable of DEBUG Mode */
#define DBGCTL_DBGEN 0x00000001
/* Disable Debug Mode
#define DBGCTL_DBGEN_DISABLE 0x00000000 */
/** Enable Debug Mode */
#define DBGCTL_DBGEN_ENABLE 0x00000001

/* Fields of "SCR1 LSFR Feeback Bit Select" */
/** Bit Selection of Feedback Bit
    Select of LSFR Feedback Bit between 10 to 32 for the 4 EXOR Gates */
#define SCR1BS_BS_MASK 0x0000001F
/** field offset */
#define SCR1BS_BS_OFFSET 0

/* Fields of "SCR2 LSFR Feeback Bit Select" */
/** Bit Selection of Feedback Bit
    Select of LSFR Feedback Bit between 10 to 32 for the 4 EXOR Gates */
#define SCR2BS_BS_MASK 0x0000001F
/** field offset */
#define SCR2BS_BS_OFFSET 0

/*! @} */ /* SXGMII_REGISTER */

#endif /* _sxgmii_reg_h */
