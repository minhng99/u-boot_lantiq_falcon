/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _octrll_reg_h
#define _octrll_reg_h

/** \addtogroup OCTRLL_REGISTER
   @{
*/
/* access macros */
#define octrll0_r32(reg) reg_r32(&octrll0->reg)
#define octrll0_w32(val, reg) reg_w32(val, &octrll0->reg)
#define octrll0_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &octrll0->reg)
#define octrll0_r32_table(reg, idx) reg_r32_table(octrll0->reg, idx)
#define octrll0_w32_table(val, reg, idx) reg_w32_table(val, octrll0->reg, idx)
#define octrll0_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, octrll0->reg, idx)
#define octrll0_adr_table(reg, idx) adr_table(octrll0->reg, idx)

#define octrll1_r32(reg) reg_r32(&octrll1->reg)
#define octrll1_w32(val, reg) reg_w32(val, &octrll1->reg)
#define octrll1_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &octrll1->reg)
#define octrll1_r32_table(reg, idx) reg_r32_table(octrll1->reg, idx)
#define octrll1_w32_table(val, reg, idx) reg_w32_table(val, octrll1->reg, idx)
#define octrll1_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, octrll1->reg, idx)
#define octrll1_adr_table(reg, idx) adr_table(octrll1->reg, idx)

#define octrll2_r32(reg) reg_r32(&octrll2->reg)
#define octrll2_w32(val, reg) reg_w32(val, &octrll2->reg)
#define octrll2_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &octrll2->reg)
#define octrll2_r32_table(reg, idx) reg_r32_table(octrll2->reg, idx)
#define octrll2_w32_table(val, reg, idx) reg_w32_table(val, octrll2->reg, idx)
#define octrll2_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, octrll2->reg, idx)
#define octrll2_adr_table(reg, idx) adr_table(octrll2->reg, idx)

#define octrll3_r32(reg) reg_r32(&octrll3->reg)
#define octrll3_w32(val, reg) reg_w32(val, &octrll3->reg)
#define octrll3_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &octrll3->reg)
#define octrll3_r32_table(reg, idx) reg_r32_table(octrll3->reg, idx)
#define octrll3_w32_table(val, reg, idx) reg_w32_table(val, octrll3->reg, idx)
#define octrll3_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, octrll3->reg, idx)
#define octrll3_adr_table(reg, idx) adr_table(octrll3->reg, idx)


/** OCTRLL register structure */
struct gpon_reg_octrll
{
   /** Control Register */
   unsigned int ctrl; /* 0x00000000 */
   /** Configuration Register */
   unsigned int cfg; /* 0x00000004 */
   /** Raw Control Register */
   unsigned int rawctrl; /* 0x00000008 */
   /** Raw Configuration Register 0
       Note: Modify only when RAWCTRL.RAWTX is disabled! */
   unsigned int rawcfg0; /* 0x0000000C */
   /** Raw Configuration Register 1
       Note: Modify only when RAWCTRL.RAWTX is disabled! */
   unsigned int rawcfg1; /* 0x00000010 */
   /** Timeout Configuration Register
       This Register holds the Timeout Configuration */
   unsigned int toutcfg; /* 0x00000014 */
   /** DMAR Control Register */
   unsigned int dctrl; /* 0x00000018 */
   /** Transmitted Bytes Counter (Low Part)
       This counter is metering the transmitted Bytes for the LAN Interface. First the low and then the high part must be read. */
   unsigned int txbcntl; /* 0x0000001C */
   /** Transmitted Bytes Counter (High Part)
       This counter is metering the transmitted Bytes for the LAN Interface. First the low and then the high part must be read. */
   unsigned int txbcnth; /* 0x00000020 */
   /** Transmitted Packets Counter
       This counter is metering the transmitted Packets for the LAN Interface. */
   unsigned int txpcnt; /* 0x00000024 */
   /** Transmitted Packets MINSIZE-64 Counter
       This counter is metering the transmitted Packets with MINSIZE to 64 Bytes for the LAN Interface. */
   unsigned int txp64cnt; /* 0x00000028 */
   /** Transmitted Packets 65-127 Counter
       This counter is metering the transmitted Packets with 65 to 127 Bytes for the LAN Interface. */
   unsigned int txp65cnt; /* 0x0000002C */
   /** Transmitted Packets 128-255 Counter
       This counter is metering the transmitted Packets with 128 to 255 Bytes for the LAN Interface. */
   unsigned int txp128cnt; /* 0x00000030 */
   /** Transmitted Packets 256-511 Counter
       This counter is metering the transmitted Packets with 256 to 511 Bytes for the LAN Interface. */
   unsigned int txp256cnt; /* 0x00000034 */
   /** Transmitted Packets 512-1023 Counter
       This counter is metering the transmitted Packets with 512 to 1023 Bytes for the LAN Interface. */
   unsigned int txp512cnt; /* 0x00000038 */
   /** Transmitted Packets 1024-1518 Counter
       This counter is metering the transmitted Packets with 1024 to 1518 Bytes for the LAN Interface. */
   unsigned int txp1024cnt; /* 0x0000003C */
   /** Transmitted Packets 1519-MAXSIZE Counter
       This counter is metering the transmitted Packets with 1519 to MAXSIZE Bytes for the LAN Interface. */
   unsigned int txp1519cnt; /* 0x00000040 */
   /** DMAR Pointer Register
       This read only Register mirrors the DMAR.PTR Register and may be used for debugging. */
   unsigned int dptr; /* 0x00000044 */
   /** DMAR Context Register
       This read only Register mirrors the DMAR.CONTEXT Register and may be used for debugging. */
   unsigned int dcontext; /* 0x00000048 */
   /** State Register
       This Register shows the internal state. */
   unsigned int state; /* 0x0000004C */
   /** Reserved */
   unsigned int res_0[12]; /* 0x00000050 */
   /** IRN Capture Register
       This register shows the currently active interrupt events masked with the corresponding enable bits of the IRNEN register. The interrupts can be acknowledged by a write operation. */
   unsigned int irncr; /* 0x00000080 */
   /** IRN Interrupt Control Register
       A write operation directly effects the interrupts. This can be used to trigger events under software control for testing purposes. A read operation returns the unmasked interrupt events. */
   unsigned int irnicr; /* 0x00000084 */
   /** IRN Interrupt Enable Register
       This register contains the enable (or mask) bits for the interrupts. Disabled interrupts are not visible in the IRNCR register and are not signalled via the interrupt line towards the controller. */
   unsigned int irnen; /* 0x00000088 */
   /** Reserved */
   unsigned int res_1[29]; /* 0x0000008C */
};


/* Fields of "Control Register" */
/** Retransmission Enable
    This bit enables the retransmission mode.The value is stored in a shadow register and assigned to the internal register before the start of a packet.A read returns the shadowed value. */
#define OCTRLL_CTRL_RTX 0x00000004
/* Disable
#define OCTRLL_CTRL_RTX_DIS 0x00000000 */
/** Enable */
#define OCTRLL_CTRL_RTX_EN 0x00000004
/** Timeout Enable
    Note: Modify only when ACT is disabled!If set, the queues attached to this interface will be actively emptied after the programmable period TOUTCFG.TOUTVALUE of inactivity. */
#define OCTRLL_CTRL_TOUTEN 0x00000002
/* Disable
#define OCTRLL_CTRL_TOUTEN_DIS 0x00000000 */
/** Enable */
#define OCTRLL_CTRL_TOUTEN_EN 0x00000002
/** Activate Core State Machine
    This bit enables the OCTRL state machine.When deactivating, the current Ethernet frame is finished and then the OCTRL is on hold.Note 1: All static configuration must be done before activation.Note 2: Deactivation is for debugging only. act - deact - act is prohibited! */
#define OCTRLL_CTRL_ACT 0x00000001
/* Disable
#define OCTRLL_CTRL_ACT_DIS 0x00000000 */
/** Enable */
#define OCTRLL_CTRL_ACT_EN 0x00000001

/* Fields of "Configuration Register" */
/** Egress Port Number
    Note: Modify only when CTRL.ACT is disabled!Assigned EPN0 to 71: Implemented EPN range71: No EPN assigned */
#define OCTRLL_CFG_EPN_MASK 0x0000007F
/** field offset */
#define OCTRLL_CFG_EPN_OFFSET 0

/* Fields of "Raw Control Register" */
/** Transmit Frame in Raw Mode
    Note: Modify only when disabled, i.e. previous transmission is finished!Triggers Raw transmission when set by CPU.Acknowledge Raw transmission when reset by OCTRL. */
#define OCTRLL_RAWCTRL_RAWTX 0x00000001
/* Disable
#define OCTRLL_RAWCTRL_RAWTX_DIS 0x00000000 */
/** Enable */
#define OCTRLL_RAWCTRL_RAWTX_EN 0x00000001

/* Fields of "Raw Configuration Register 0" */
/** Head LSA
    Head Logical Segment Address */
#define OCTRLL_RAWCFG0_HLSA_MASK 0x00007FFF
/** field offset */
#define OCTRLL_RAWCFG0_HLSA_OFFSET 0

/* Fields of "Raw Configuration Register 1" */
/** Header Length
    Length of the Packet Header */
#define OCTRLL_RAWCFG1_HDRL_MASK 0xFF000000
/** field offset */
#define OCTRLL_RAWCFG1_HDRL_OFFSET 24
/** Offset
    Offset into Frame Segment(s) */
#define OCTRLL_RAWCFG1_OFFS_MASK 0x00FF0000
/** field offset */
#define OCTRLL_RAWCFG1_OFFS_OFFSET 16
/** Body Length
    Length of the Packet Body w/o FCS */
#define OCTRLL_RAWCFG1_BDYL_MASK 0x0000FFFF
/** field offset */
#define OCTRLL_RAWCFG1_BDYL_OFFSET 0

/* Fields of "Timeout Configuration Register" */
/** Timeout Value
    This value determines the time till the packet is dropped.0x0000: no timeout0x0001: approx. 9.15ms0xFFFF: approx. 600sNote: The values are based on 312.5MHz core clock frequency. */
#define OCTRLL_TOUTCFG_TOUTVALUE_MASK 0x0000FFFF
/** field offset */
#define OCTRLL_TOUTCFG_TOUTVALUE_OFFSET 0

/* Fields of "DMAR Control Register" */
/** Free Queue
    FSQM Queue selection for LSA freeing. */
#define OCTRLL_DCTRL_FQ 0x00000001
/* Select Queue 0 (Note: Usage is prohibited!)
#define OCTRLL_DCTRL_FQ_Q0 0x00000000 */
/** Select Queue 1 (Default) */
#define OCTRLL_DCTRL_FQ_Q1 0x00000001

/* Fields of "Transmitted Bytes Counter (Low Part)" */
/** Counter Value (Low)
    Byte Counter Value (Low Part) */
#define OCTRLL_TXBCNTL_BCNTL_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXBCNTL_BCNTL_OFFSET 0

/* Fields of "Transmitted Bytes Counter (High Part)" */
/** Counter Value (High)
    Byte Counter Value (High Part) */
#define OCTRLL_TXBCNTH_BCNTH_MASK 0x0000FFFF
/** field offset */
#define OCTRLL_TXBCNTH_BCNTH_OFFSET 0

/* Fields of "Transmitted Packets Counter" */
/** Counter Value
    Packet Counter Value */
#define OCTRLL_TXPCNT_PCNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXPCNT_PCNT_OFFSET 0

/* Fields of "Transmitted Packets MINSIZE-64 Counter" */
/** Counter Value
    Packet MINSIZE-64 Counter Value */
#define OCTRLL_TXP64CNT_P64CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP64CNT_P64CNT_OFFSET 0

/* Fields of "Transmitted Packets 65-127 Counter" */
/** Counter Value
    Packet 65-127 Counter Value */
#define OCTRLL_TXP65CNT_P65CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP65CNT_P65CNT_OFFSET 0

/* Fields of "Transmitted Packets 128-255 Counter" */
/** Counter Value
    Packet 128-255 Counter Value */
#define OCTRLL_TXP128CNT_P128CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP128CNT_P128CNT_OFFSET 0

/* Fields of "Transmitted Packets 256-511 Counter" */
/** Counter Value
    Packet 256-511 Counter Value */
#define OCTRLL_TXP256CNT_P256CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP256CNT_P256CNT_OFFSET 0

/* Fields of "Transmitted Packets 512-1023 Counter" */
/** Counter Value
    Packet 512-1023 Counter Value */
#define OCTRLL_TXP512CNT_P512CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP512CNT_P512CNT_OFFSET 0

/* Fields of "Transmitted Packets 1024-1518 Counter" */
/** Counter Value
    Packet 1024-1518 Counter Value */
#define OCTRLL_TXP1024CNT_P1024CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP1024CNT_P1024CNT_OFFSET 0

/* Fields of "Transmitted Packets 1519-MAXSIZE Counter" */
/** Counter Value
    Packet 1519-MAXSIZE Counter Value */
#define OCTRLL_TXP1519CNT_P1519CNT_MASK 0xFFFFFFFF
/** field offset */
#define OCTRLL_TXP1519CNT_P1519CNT_OFFSET 0

/* Fields of "DMAR Pointer Register" */
/** Tail LSA
    Tail Logical Segment Address */
#define OCTRLL_DPTR_TLSA_MASK 0x7FFF0000
/** field offset */
#define OCTRLL_DPTR_TLSA_OFFSET 16
/** Head LSA */
#define OCTRLL_DPTR_HLSA_MASK 0x00007FFF
/** field offset */
#define OCTRLL_DPTR_HLSA_OFFSET 0

/* Fields of "DMAR Context Register" */
/** Header Length
    Length of the Packet Header */
#define OCTRLL_DCONTEXT_HDRL_MASK 0xFF000000
/** field offset */
#define OCTRLL_DCONTEXT_HDRL_OFFSET 24
/** Offset
    Offset into Frame Segment(s) */
#define OCTRLL_DCONTEXT_OFFS_MASK 0x00FF0000
/** field offset */
#define OCTRLL_DCONTEXT_OFFS_OFFSET 16
/** Body Length
    Length of the Packet Body w/o FCS */
#define OCTRLL_DCONTEXT_BDYL_MASK 0x0000FFFF
/** field offset */
#define OCTRLL_DCONTEXT_BDYL_OFFSET 0

/* Fields of "State Register" */
/** Retransmission Enable
    This bit shows the value of the internal retransmission mode enable register. */
#define OCTRLL_STATE_RTX 0x00080000
/* Disable
#define OCTRLL_STATE_RTX_DIS 0x00000000 */
/** Enable */
#define OCTRLL_STATE_RTX_EN 0x00080000
/** Egress Port Filled
    Indicates whether Egress Port is filled or not. */
#define OCTRLL_STATE_EPFILLED 0x00040000
/* Not Filled
#define OCTRLL_STATE_EPFILLED_NFILLED 0x00000000 */
/** Filled */
#define OCTRLL_STATE_EPFILLED_FILLED 0x00040000
/** TX-Data Fifo Full
    Indicates whether the TX-Data Fifo is full or not. */
#define OCTRLL_STATE_TXFIFOFULL 0x00020000
/* FIFO not full: There is free space in the FIFO.
#define OCTRLL_STATE_TXFIFOFULL_FNFULL 0x00000000 */
/** FIFO full: There is no space in the FIFO. */
#define OCTRLL_STATE_TXFIFOFULL_FFULL 0x00020000
/** DMAR Data Ready
    Indicates whether DMAR Data is ready or not. */
#define OCTRLL_STATE_DMARDRDY 0x00010000
/* Not Ready
#define OCTRLL_STATE_DMARDRDY_NRDY 0x00000000 */
/** Ready */
#define OCTRLL_STATE_DMARDRDY_RDY 0x00010000
/** Transmission State
    Current state of data transmission. */
#define OCTRLL_STATE_TX_MASK 0x00000007
/** field offset */
#define OCTRLL_STATE_TX_OFFSET 0
/** Idle */
#define OCTRLL_STATE_TX_IDLE 0x00000000
/** Schedule */
#define OCTRLL_STATE_TX_SCHEDULE 0x00000001
/** DMAR open channel */
#define OCTRLL_STATE_TX_DMAROPEN 0x00000002
/** DMAR data transmission */
#define OCTRLL_STATE_TX_DMARTX 0x00000003
/** DMAR close channel */
#define OCTRLL_STATE_TX_DMARCLOSE 0x00000004
/** DMAR delete channel (deallocate segments in SSB) */
#define OCTRLL_STATE_TX_DMARDELETE 0x00000005
/** Retransmission acknowledge */
#define OCTRLL_STATE_TX_RTXACK 0x00000006

/* Fields of "IRN Capture Register" */
/** PDU Length
    The PDU Length received from the TMU is zero, i.e. HDRL + BDYL = 0.The schedule response is discarded and the next pending PDU is processed.This bit contributes to the OCTRLL0_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define OCTRLL_IRNCR_PLEN 0x00080000
/* Nothing
#define OCTRLL_IRNCR_PLEN_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define OCTRLL_IRNCR_PLEN_INTACK 0x00080000
/** Read: Interrupt occurred. */
#define OCTRLL_IRNCR_PLEN_INTOCC 0x00080000
/** OCTRL NIL LSA
    OCTRL has received a NIL LSA from TMU.The schedule response is discarded and the next pending PDU is processed.This bit contributes to the OCTRLL0_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define OCTRLL_IRNCR_NIL 0x00040000
/* Nothing
#define OCTRLL_IRNCR_NIL_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define OCTRLL_IRNCR_NIL_INTACK 0x00040000
/** Read: Interrupt occurred. */
#define OCTRLL_IRNCR_NIL_INTOCC 0x00040000
/** DMAR NIL LSA
    DMAR has received a NIL LSA from FSQM, i.e. linked list in FSQM is corrupt.The PDU transmission is immediately stopped, the memory, allocated by the already transmitted bytes, is deallocated and the OCTRL will be disabled, i.e. CTRL.ACT = 0.This bit contributes to the OCTRLL0_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define OCTRLL_IRNCR_DNIL 0x00010000
/* Nothing
#define OCTRLL_IRNCR_DNIL_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define OCTRLL_IRNCR_DNIL_INTACK 0x00010000
/** Read: Interrupt occurred. */
#define OCTRLL_IRNCR_DNIL_INTOCC 0x00010000
/** Timeout
    A timeout of the transmission backpressure has occured and the egress queue will be actively emptied. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define OCTRLL_IRNCR_TOUT 0x00000002
/* Nothing
#define OCTRLL_IRNCR_TOUT_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define OCTRLL_IRNCR_TOUT_INTACK 0x00000002
/** Read: Interrupt occurred. */
#define OCTRLL_IRNCR_TOUT_INTOCC 0x00000002
/** RAW Transmission Acknowledge
    The Transmission in RAW mode has been finished. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define OCTRLL_IRNCR_RAWACK 0x00000001
/* Nothing
#define OCTRLL_IRNCR_RAWACK_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define OCTRLL_IRNCR_RAWACK_INTACK 0x00000001
/** Read: Interrupt occurred. */
#define OCTRLL_IRNCR_RAWACK_INTOCC 0x00000001

/* Fields of "IRN Interrupt Control Register" */
/** PDU Length
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNICR_PLEN 0x00080000
/** OCTRL NIL LSA
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNICR_NIL 0x00040000
/** DMAR NIL LSA
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNICR_DNIL 0x00010000
/** Timeout
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNICR_TOUT 0x00000002
/** RAW Transmission Acknowledge
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNICR_RAWACK 0x00000001

/* Fields of "IRN Interrupt Enable Register" */
/** PDU Length
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNEN_PLEN 0x00080000
/* Disable
#define OCTRLL_IRNEN_PLEN_DIS 0x00000000 */
/** Enable */
#define OCTRLL_IRNEN_PLEN_EN 0x00080000
/** OCTRL NIL LSA
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNEN_NIL 0x00040000
/* Disable
#define OCTRLL_IRNEN_NIL_DIS 0x00000000 */
/** Enable */
#define OCTRLL_IRNEN_NIL_EN 0x00040000
/** DMAR NIL LSA
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNEN_DNIL 0x00010000
/* Disable
#define OCTRLL_IRNEN_DNIL_DIS 0x00000000 */
/** Enable */
#define OCTRLL_IRNEN_DNIL_EN 0x00010000
/** Timeout
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNEN_TOUT 0x00000002
/* Disable
#define OCTRLL_IRNEN_TOUT_DIS 0x00000000 */
/** Enable */
#define OCTRLL_IRNEN_TOUT_EN 0x00000002
/** RAW Transmission Acknowledge
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define OCTRLL_IRNEN_RAWACK 0x00000001
/* Disable
#define OCTRLL_IRNEN_RAWACK_DIS 0x00000000 */
/** Enable */
#define OCTRLL_IRNEN_RAWACK_EN 0x00000001

/*! @} */ /* OCTRLL_REGISTER */

#endif /* _octrll_reg_h */
