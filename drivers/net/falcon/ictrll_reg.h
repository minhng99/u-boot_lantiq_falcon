/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _ictrll_reg_h
#define _ictrll_reg_h

/** \addtogroup ICTRLL_REGISTER
   @{
*/
/* access macros */
#define ictrll0_r32(reg) reg_r32(&ictrll0->reg)
#define ictrll0_w32(val, reg) reg_w32(val, &ictrll0->reg)
#define ictrll0_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &ictrll0->reg)
#define ictrll0_r32_table(reg, idx) reg_r32_table(ictrll0->reg, idx)
#define ictrll0_w32_table(val, reg, idx) reg_w32_table(val, ictrll0->reg, idx)
#define ictrll0_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, ictrll0->reg, idx)
#define ictrll0_adr_table(reg, idx) adr_table(ictrll0->reg, idx)

#define ictrll1_r32(reg) reg_r32(&ictrll1->reg)
#define ictrll1_w32(val, reg) reg_w32(val, &ictrll1->reg)
#define ictrll1_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &ictrll1->reg)
#define ictrll1_r32_table(reg, idx) reg_r32_table(ictrll1->reg, idx)
#define ictrll1_w32_table(val, reg, idx) reg_w32_table(val, ictrll1->reg, idx)
#define ictrll1_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, ictrll1->reg, idx)
#define ictrll1_adr_table(reg, idx) adr_table(ictrll1->reg, idx)

#define ictrll2_r32(reg) reg_r32(&ictrll2->reg)
#define ictrll2_w32(val, reg) reg_w32(val, &ictrll2->reg)
#define ictrll2_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &ictrll2->reg)
#define ictrll2_r32_table(reg, idx) reg_r32_table(ictrll2->reg, idx)
#define ictrll2_w32_table(val, reg, idx) reg_w32_table(val, ictrll2->reg, idx)
#define ictrll2_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, ictrll2->reg, idx)
#define ictrll2_adr_table(reg, idx) adr_table(ictrll2->reg, idx)

#define ictrll3_r32(reg) reg_r32(&ictrll3->reg)
#define ictrll3_w32(val, reg) reg_w32(val, &ictrll3->reg)
#define ictrll3_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &ictrll3->reg)
#define ictrll3_r32_table(reg, idx) reg_r32_table(ictrll3->reg, idx)
#define ictrll3_w32_table(val, reg, idx) reg_w32_table(val, ictrll3->reg, idx)
#define ictrll3_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, ictrll3->reg, idx)
#define ictrll3_adr_table(reg, idx) adr_table(ictrll3->reg, idx)


/** ICTRLL register structure */
struct gpon_reg_ictrll
{
   /** Control Register
       This register provides the global ICTRLL controls. */
   unsigned int ctrl; /* 0x00000000 */
   /** DMAW Configuration Register
       This register contains necessary configuration elements for the DMAW. */
   unsigned int dmaw_cfg; /* 0x00000004 */
   /** Reserved */
   unsigned int res_0[6]; /* 0x00000008 */
   /** RAW Mode Destination Address 0
       This register contains the destination address for RAW mode. */
   unsigned int rawda0; /* 0x00000020 */
   /** RAW Mode Destination Address 1
       This register contains the destination address for RAW mode. */
   unsigned int rawda1; /* 0x00000024 */
   /** Reserved */
   unsigned int res_1[2]; /* 0x00000028 */
   /** Maximum allowed Size for PDU Type 0
       This register contains the maximum allowed size for PDU type 0. */
   unsigned int maxsize0; /* 0x00000030 */
   /** Reserved */
   unsigned int res_2[7]; /* 0x00000034 */
   /** Received Bytes Counter (Low Part)
       This counter is metering the total number of received bytes. */
   unsigned int rxbcntl; /* 0x00000050 */
   /** Received Bytes Counter (High Part)
       This counter is metering the total number of received bytes. */
   unsigned int rxbcnth; /* 0x00000054 */
   /** Oversized PDUs Counter
       This counter is metering the number of oversized PDUs:- Oversized Frame (IRN*.OVRSIZE) */
   unsigned int ovrsize; /* 0x00000058 */
   /** DMAW Error Counter
       This counter is metering the number of DMAW Errors:- DMAW Out of FIFO Error (IRN*.DMAWOOF)- DMAW Out Of Memory Error (IRN*.DMAWOOM)- DMAW Timeout Error (IRN*.DMAWTMO)Note: Due to the LSA prefetch, the DMAW errors Out of Memory and Timeout can also occur when no Ethernet frame is processed. */
   unsigned int dmawerr; /* 0x0000005C */
   /** Reserved */
   unsigned int res_3[8]; /* 0x00000060 */
   /** GMAC Error Counter
       This register contains the number of GMAC errors:- MAC Abort (IRN*.MACABT)- Minimum Size Under-run (IRN*.MINSIZE)- Raw Mode Destination Address Error (IRN*.RAWDAERR) */
   unsigned int macerr; /* 0x00000080 */
   /** Packet Discard Counter
       This counter is metering the total number of PDUs which have been discarded due to:- Oversize Errors- GMAC Errors- DMAW Errors */
   unsigned int pdc; /* 0x00000084 */
   /** Reserved */
   unsigned int res_4[2]; /* 0x00000088 */
   /** Received Packets Counter
       This counter is metering the total number of received packets. */
   unsigned int rxpcnt; /* 0x00000090 */
   /** Received Packets 64 Counter
       This counter is metering the number of received packets with 64 bytes. */
   unsigned int rxp64cnt; /* 0x00000094 */
   /** Received Packets 65 - 127 Counter
       This counter is metering the number of received packets with 65 to 127 bytes. */
   unsigned int rxp65cnt; /* 0x00000098 */
   /** Received Packets 128 - 255 Counter
       This counter is metering the number of received packets with 128 to 255 bytes. */
   unsigned int rxp128cnt; /* 0x0000009C */
   /** Received Packets 256 - 511 Counter
       This counter is metering the number of received packets with 256 to 511 bytes. */
   unsigned int rxp256cnt; /* 0x000000A0 */
   /** Received Packets 512 - 1023 Counter
       This counter is metering the number of received packets with 512 to 1023 bytes. */
   unsigned int rxp512cnt; /* 0x000000A4 */
   /** Received Packets 1024 - 1518 Counter
       This counter is metering the number of received packets with 1024 to 1518 bytes. */
   unsigned int rxp1024cnt; /* 0x000000A8 */
   /** Received Packets 1519 - MAXSIZE Counter
       This counter is metering the number of received packets with 1519 to MAXSIZE bytes. */
   unsigned int rxp1519cnt; /* 0x000000AC */
   /** Received Packets MINSIZE - 63 Counter
       This counter is metering number of received packets with 5 to 63 bytes. */
   unsigned int undsize; /* 0x000000B0 */
   /** Reserved */
   unsigned int res_5[19]; /* 0x000000B4 */
   /** IRN Capture Register
       This register shows the currently active interrupt events masked with the corresponding enable bits of the IRNEN register. The interrupts can be acknowledged by a write operation. */
   unsigned int irncr; /* 0x00000100 */
   /** IRN Interrupt Control Register
       A write operation directly effects the interrupts. This can be used to trigger events under software control for testing purposes. A read operation returns the unmasked interrupt events. */
   unsigned int irnicr; /* 0x00000104 */
   /** IRN Interrupt Enable Register
       This register contains the enable (or mask) bits for the interrupts. Disabled interrupts are not visible in the IRNCR register and are not signalled via the interrupt line towards the controller. */
   unsigned int irnen; /* 0x00000108 */
   /** Reserved */
   unsigned int res_6[61]; /* 0x0000010C */
};


/* Fields of "Control Register" */
/** Activate Debug Mode of the ICTRL Module
    This bit enables the Debug Mode of the ICTRL. If this bit is set, ICTRLx will always write out data to the IQM, regardless IQM FIFO is ready or not. */
#define ICTRLL_CTRL_DBG 0x80000000
/* Disable
#define ICTRLL_CTRL_DBG_DIS 0x00000000 */
/** Enable */
#define ICTRLL_CTRL_DBG_EN 0x80000000
/** Enable Broadcast Filter for Raw Mode of the ICTRL Module
    This bit enables the Broadcast Filter for Raw Mode of the ICTRL (all packets with destination address 0xFFFF_FFFF_FFFF are accepted) */
#define ICTRLL_CTRL_BC 0x00000200
/* Disable
#define ICTRLL_CTRL_BC_DIS 0x00000000 */
/** Enable */
#define ICTRLL_CTRL_BC_EN 0x00000200
/** Activate Raw Mode of the ICTRL Module
    This bit enables the Raw Mode of the ICTRL. This mode is only used for Ethernet boot mode. */
#define ICTRLL_CTRL_RAW 0x00000100
/* Disable
#define ICTRLL_CTRL_RAW_DIS 0x00000000 */
/** Enable */
#define ICTRLL_CTRL_RAW_EN 0x00000100
/** Activate Core State Machine
    This bit enables the ICTRL state machine. */
#define ICTRLL_CTRL_ACT 0x00000001
/* Disable
#define ICTRLL_CTRL_ACT_DIS 0x00000000 */
/** Enable */
#define ICTRLL_CTRL_ACT_EN 0x00000001

/* Fields of "DMAW Configuration Register" */
/** Synchronous Reset of DMAW */
#define ICTRLL_DMAW_CFG_SRET 0x80000000
/* NoReset
#define ICTRLL_DMAW_CFG_SRET_NoReset 0x00000000 */
/** Reset */
#define ICTRLL_DMAW_CFG_SRET_Reset 0x80000000
/** Alloc Queue Selection
    FSQM Queue selection for LSA allocation. */
#define ICTRLL_DMAW_CFG_ALLOCQ 0x00000200
/* Select Queue 0 (Note: Usage is prohibited!)
#define ICTRLL_DMAW_CFG_ALLOCQ_Q0 0x00000000 */
/** Select Queue 1 (Default) */
#define ICTRLL_DMAW_CFG_ALLOCQ_Q1 0x00000200
/** Free Queue Selection
    FSQM Queue selection for LSA freeing. */
#define ICTRLL_DMAW_CFG_FREEQ 0x00000100
/* Select Queue 0 (Note: Usage is prohibited!)
#define ICTRLL_DMAW_CFG_FREEQ_Q0 0x00000000 */
/** Select Queue 1 (Default) */
#define ICTRLL_DMAW_CFG_FREEQ_Q1 0x00000100
/** FSQM LSA Request Limitation
    This is the number of wait cycles until a LSA request to FSQM issues an error. */
#define ICTRLL_DMAW_CFG_LSARLMT_MASK 0x000000FF
/** field offset */
#define ICTRLL_DMAW_CFG_LSARLMT_OFFSET 0

/* Fields of "RAW Mode Destination Address 0" */
/** Destination Address Byte 0 */
#define ICTRLL_RAWDA0_DAB0_MASK 0xFF000000
/** field offset */
#define ICTRLL_RAWDA0_DAB0_OFFSET 24
/** Destination Address Byte 1 */
#define ICTRLL_RAWDA0_DAB1_MASK 0x00FF0000
/** field offset */
#define ICTRLL_RAWDA0_DAB1_OFFSET 16
/** Destination Address Byte 2 */
#define ICTRLL_RAWDA0_DAB2_MASK 0x0000FF00
/** field offset */
#define ICTRLL_RAWDA0_DAB2_OFFSET 8
/** Destination Address Byte 3 */
#define ICTRLL_RAWDA0_DAB3_MASK 0x000000FF
/** field offset */
#define ICTRLL_RAWDA0_DAB3_OFFSET 0

/* Fields of "RAW Mode Destination Address 1" */
/** Destination Address Byte 4 */
#define ICTRLL_RAWDA1_DAB4_MASK 0xFF000000
/** field offset */
#define ICTRLL_RAWDA1_DAB4_OFFSET 24
/** Destination Address Byte 5 */
#define ICTRLL_RAWDA1_DAB5_MASK 0x00FF0000
/** field offset */
#define ICTRLL_RAWDA1_DAB5_OFFSET 16

/* Fields of "Maximum allowed Size for PDU Type 0" */
/** Size
    This register holds the size. */
#define ICTRLL_MAXSIZE0_SIZE_MASK 0x0000FFFF
/** field offset */
#define ICTRLL_MAXSIZE0_SIZE_OFFSET 0

/* Fields of "Received Bytes Counter (Low Part)" */
/** Counter
    Counter value (Low Part).Note: First the Low and then the High Part has to be read. */
#define ICTRLL_RXBCNTL_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXBCNTL_CNT_OFFSET 0

/* Fields of "Received Bytes Counter (High Part)" */
/** Counter
    Counter value (High Part).Note: First the Low and then the High Part has to be read. */
#define ICTRLL_RXBCNTH_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXBCNTH_CNT_OFFSET 0

/* Fields of "Oversized PDUs Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_OVRSIZE_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_OVRSIZE_CNT_OFFSET 0

/* Fields of "DMAW Error Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_DMAWERR_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_DMAWERR_CNT_OFFSET 0

/* Fields of "GMAC Error Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_MACERR_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_MACERR_CNT_OFFSET 0

/* Fields of "Packet Discard Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_PDC_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_PDC_CNT_OFFSET 0

/* Fields of "Received Packets Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXPCNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXPCNT_CNT_OFFSET 0

/* Fields of "Received Packets 64 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP64CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP64CNT_CNT_OFFSET 0

/* Fields of "Received Packets 65 - 127 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP65CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP65CNT_CNT_OFFSET 0

/* Fields of "Received Packets 128 - 255 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP128CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP128CNT_CNT_OFFSET 0

/* Fields of "Received Packets 256 - 511 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP256CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP256CNT_CNT_OFFSET 0

/* Fields of "Received Packets 512 - 1023 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP512CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP512CNT_CNT_OFFSET 0

/* Fields of "Received Packets 1024 - 1518 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP1024CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP1024CNT_CNT_OFFSET 0

/* Fields of "Received Packets 1519 - MAXSIZE Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_RXP1519CNT_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_RXP1519CNT_CNT_OFFSET 0

/* Fields of "Received Packets MINSIZE - 63 Counter" */
/** Counter
    This register holds the counter value. */
#define ICTRLL_UNDSIZE_CNT_MASK 0xFFFFFFFF
/** field offset */
#define ICTRLL_UNDSIZE_CNT_OFFSET 0

/* Fields of "IRN Capture Register" */
/** DMAW Out of FIFO Error
    Indicates that the IQM fifo was full when trying to enqueue the PDU.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_DMAWOOF 0x04000000
/* Nothing
#define ICTRLL_IRNCR_DMAWOOF_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_DMAWOOF_INTACK 0x04000000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_DMAWOOF_INTOCC 0x04000000
/** DMAW Out Of Memory Error
    Indicates that the LSA request to FSQM returned NIL.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_DMAWOOM 0x02000000
/* Nothing
#define ICTRLL_IRNCR_DMAWOOM_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_DMAWOOM_INTACK 0x02000000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_DMAWOOM_INTOCC 0x02000000
/** DMAW Timeout Error
    Indicates that the LSA request to FSQM went into timeout.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_DMAWTMO 0x01000000
/* Nothing
#define ICTRLL_IRNCR_DMAWTMO_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_DMAWTMO_INTACK 0x01000000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_DMAWTMO_INTOCC 0x01000000
/** Minimum Size Under-run
    Indicates that a PDU has under-run the minimum size of 5 bytes.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_MINSIZE 0x00080000
/* Nothing
#define ICTRLL_IRNCR_MINSIZE_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_MINSIZE_INTACK 0x00080000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_MINSIZE_INTOCC 0x00080000
/** MAC Abort
    Indicates that the GMAC has aborted the transmission at EOF.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_MACABT 0x00040000
/* Nothing
#define ICTRLL_IRNCR_MACABT_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_MACABT_INTACK 0x00040000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_MACABT_INTOCC 0x00040000
/** Raw Mode Destination Address Error
    Indicates that in raw mode a wrong destination address has been provided.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_RAWDAERR 0x00020000
/* Nothing
#define ICTRLL_IRNCR_RAWDAERR_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_RAWDAERR_INTACK 0x00020000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_RAWDAERR_INTOCC 0x00020000
/** Oversized Frame
    Indicates that a frame has been oversized, i.e.LENGTH MAXSIZE && MAXSIZE 0.This bit contributes to the ICTRLL_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define ICTRLL_IRNCR_OVRSIZE 0x00010000
/* Nothing
#define ICTRLL_IRNCR_OVRSIZE_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define ICTRLL_IRNCR_OVRSIZE_INTACK 0x00010000
/** Read: Interrupt occurred. */
#define ICTRLL_IRNCR_OVRSIZE_INTOCC 0x00010000

/* Fields of "IRN Interrupt Control Register" */
/** DMAW Out of FIFO Error
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_DMAWOOF 0x04000000
/** DMAW Out Of Memory Error
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_DMAWOOM 0x02000000
/** DMAW Timeout Error
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_DMAWTMO 0x01000000
/** Minimum Size Under-run
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_MINSIZE 0x00080000
/** MAC Abort
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_MACABT 0x00040000
/** Raw Mode Destination Address Error
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_RAWDAERR 0x00020000
/** Oversized Frame
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNICR_OVRSIZE 0x00010000

/* Fields of "IRN Interrupt Enable Register" */
/** DMAW Out of FIFO Error
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_DMAWOOF 0x04000000
/* Disable
#define ICTRLL_IRNEN_DMAWOOF_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_DMAWOOF_EN 0x04000000
/** DMAW Out Of Memory Error
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_DMAWOOM 0x02000000
/* Disable
#define ICTRLL_IRNEN_DMAWOOM_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_DMAWOOM_EN 0x02000000
/** DMAW Timeout Error
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_DMAWTMO 0x01000000
/* Disable
#define ICTRLL_IRNEN_DMAWTMO_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_DMAWTMO_EN 0x01000000
/** Minimum Size Under-run
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_MINSIZE 0x00080000
/* Disable
#define ICTRLL_IRNEN_MINSIZE_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_MINSIZE_EN 0x00080000
/** MAC Abort
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_MACABT 0x00040000
/* Disable
#define ICTRLL_IRNEN_MACABT_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_MACABT_EN 0x00040000
/** Raw Mode Destination Address Error
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_RAWDAERR 0x00020000
/* Disable
#define ICTRLL_IRNEN_RAWDAERR_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_RAWDAERR_EN 0x00020000
/** Oversized Frame
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define ICTRLL_IRNEN_OVRSIZE 0x00010000
/* Disable
#define ICTRLL_IRNEN_OVRSIZE_DIS 0x00000000 */
/** Enable */
#define ICTRLL_IRNEN_OVRSIZE_EN 0x00010000

/*! @} */ /* ICTRLL_REGISTER */

#endif /* _ictrll_reg_h */
