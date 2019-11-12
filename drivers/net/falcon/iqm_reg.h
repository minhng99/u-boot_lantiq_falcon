/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _iqm_reg_h
#define _iqm_reg_h

/** \addtogroup IQM_REGISTER
   @{
*/
/* access macros */
#define iqm_r32(reg) reg_r32(&iqm->reg)
#define iqm_w32(val, reg) reg_w32(val, &iqm->reg)
#define iqm_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &iqm->reg)
#define iqm_r32_table(reg, idx) reg_r32_table(iqm->reg, idx)
#define iqm_w32_table(val, reg, idx) reg_w32_table(val, iqm->reg, idx)
#define iqm_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, iqm->reg, idx)
#define iqm_adr_table(reg, idx) adr_table(iqm->reg, idx)

struct iqm_iqt
{
   /** Ingress Queue Table Register 0
       This register provides access to Queue Configuration Parameters. */
   unsigned int iqt0; /* 0x00000020 */
   /** Ingress Queue Table Register 1
       This register provides access to Queue Status. */
   unsigned int iqt1; /* 0x00000024 */
   /** Ingress Queue Table Register 2
       This register provides access to Queue Status. */
   unsigned int iqt2; /* 0x00000028 */
   /** Ingress Queue Table Register 3
       This register provides access to Queue Status. */
   unsigned int iqt3; /* 0x0000002C */
   /** Ingress Queue Table Register 4
       This register provides access to Queue Status. */
   unsigned int iqt4; /* 0x00000030 */
   /** Ingress Queue Table Register 5
       This register provides the thread mask which assigns the Ingress Queue 0 to different threads. */
   unsigned int iqt5; /* 0x00000034 */
   /** Reserved */
   unsigned int res[2]; /* 0x00000038 */
};

/** IQM register structure */
struct gpon_reg_iqm
{
   /** Control Register
       This register provides the global IQM controls. */
   unsigned int ctrl; /* 0x00000000 */
   /** Reserved */
   unsigned int res_0[3]; /* 0x00000004 */
   /** IRN Capture Register
       This register shows the currently active interrupt events masked with the corresponding enable bits of the IRNEN register. The interrupts can be acknowledged by a write operation. */
   unsigned int irncr; /* 0x00000010 */
   /** IRN Interrupt Control Register
       A write operation directly effects the interrupts. This can be used to trigger events under software control for testing purposes. A read operation returns the unmasked interrupt events. */
   unsigned int irnicr; /* 0x00000014 */
   /** IRN Interrupt Enable Register
       This register contains the enable (or mask) bits for the interrupts. Disabled interrupts are not visible in the IRNCR register and are not signalled via the interrupt line towards the controller. */
   unsigned int irnen; /* 0x00000018 */
   /** Reserved */
   unsigned int res_1; /* 0x0000001C */

   struct iqm_iqt iqt[9];

   /** Free Pointer Counter Register
       This register provides the free PDU pointer counter. */
   unsigned int fpcr; /* 0x00000140 */
   /** Reserved */
   unsigned int res_11[7]; /* 0x00000144 */
   /** Global Occupancy Counter Register
       This register provides the global occupancy counter */
   unsigned int gocc; /* 0x00000160 */
   /** Global Occupancy Threshold Register
       This register provides the global occupancy threshold */
   unsigned int goth; /* 0x00000164 */
   /** Global PDU Discard Counter Register
       This register provides the global occupancy discard counter measured in PDUs */
   unsigned int gpdc; /* 0x00000168 */
   /** Time Stamp Register
       This register provides time stamp to be attached to accepted PDUs */
   unsigned int ts; /* 0x0000016C */
   /** WRR Control Register
       This register controls the scheduler behavior. */
   unsigned int wrrc; /* 0x00000170 */
   /** Reserved */
   unsigned int res_12; /* 0x00000174 */
   /** WRR QID Register
       This register provides a mapping from the WRR slots to arbitrary QIDs */
   unsigned int wrrq[5]; /* 0x00000178 */
   /** Reserved */
   unsigned int res_13; /* 0x0000018C */
   /** Segment Free Register 0
       Each bit in this register indicates by its position if the coresponding pointer segment address is free (=1) */
   unsigned int sfree0; /* 0x00000190 */
   /** Segment Free Register 1
       Each bit in this register indicates by its position if the corresponding pointer segment address is free (=1) */
   unsigned int sfree1; /* 0x00000194 */
   /** Reserved */
   unsigned int res_14[26]; /* 0x00000198 */
   /** Dequeue Respond Parameter Register 0
       This register provides respond parameters for a Dequeue_Request command submitted by the CPU */
   unsigned int drp0; /* 0x00000200 */
   /** Dequeue Respond Parameter Register 1
       This register provides respond parameters for a Dequeue_Request command to be submitted by the CPU */
   unsigned int drp1; /* 0x00000204 */
   /** Dequeue Respond Parameter Register 2
       This register provides respond parameters for a Dequeue_Request command to be submitted by the CPU */
   unsigned int drp2; /* 0x00000208 */
   /** Dequeue Respond Parameter Register 3
       This register provides respond parameters for a Dequeue_Request command to be submitted by the CPU */
   unsigned int drp3; /* 0x0000020C */
   /** Dequeue Request Command Register
       This register activates the command submitted by the CPU to the internal state machines */
   unsigned int drc; /* 0x00000210 */
   /** Reserved */
   unsigned int res_15[16251]; /* 0x00000214 */
};


/* Fields of "Control Register" */
/** TIMESTAMP PRESCALER
    This field defines the exponent of a clock divider used before the timestamp counter is incremented */
#define IQM_CTRL_TSPRESCALE_MASK 0x07000000
/** field offset */
#define IQM_CTRL_TSPRESCALE_OFFSET 24
/** RAW mode of data transfer
    If this mode is enabled, raw packets can be transferred from the LAN interfaces to the CPU via the IQM CPU dequeue register interface, but no data transfer is possible towards the dispatcher. If the raw mode is disabled, the CPU dequeue interface is also disabled and normal data flow to the dispatcher is possible. The raw mode is used during boot-up. */
#define IQM_CTRL_RAW 0x00000004
/* Disable
#define IQM_CTRL_RAW_DIS 0x00000000 */
/** Enable */
#define IQM_CTRL_RAW_EN 0x00000004
/** Freeze Core State Machine
    This bit freezes the IQM state machine. */
#define IQM_CTRL_FRZ 0x00000002
/* Disable
#define IQM_CTRL_FRZ_DIS 0x00000000 */
/** Enable */
#define IQM_CTRL_FRZ_EN 0x00000002
/** Activate Core State Machine
    This bit enables the IQM state machine. */
#define IQM_CTRL_ACT 0x00000001
/* Disable
#define IQM_CTRL_ACT_DIS 0x00000000 */
/** Enable */
#define IQM_CTRL_ACT_EN 0x00000001

/* Fields of "IRN Capture Register" */
/** IQM Queue 8 Back Pressure
    This bit is set, if the IQM Queue 8 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP8 0x10000000
/* Nothing
#define IQM_IRNCR_BP8_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP8_INTOCC 0x10000000
/** IQM Queue 7 Back Pressure
    This bit is set, if the IQM Queue 7 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP7 0x08000000
/* Nothing
#define IQM_IRNCR_BP7_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP7_INTOCC 0x08000000
/** IQM Queue 6 Back Pressure
    This bit is set, if the IQM Queue 6 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP6 0x04000000
/* Nothing
#define IQM_IRNCR_BP6_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP6_INTOCC 0x04000000
/** IQM Queue 5 Back Pressure
    This bit is set, if the IQM Queue 5 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP5 0x02000000
/* Nothing
#define IQM_IRNCR_BP5_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP5_INTOCC 0x02000000
/** IQM Queue 4 Back Pressure
    This bit is set, if the IQM Queue 4 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP4 0x01000000
/* Nothing
#define IQM_IRNCR_BP4_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP4_INTOCC 0x01000000
/** IQM Queue 3 Back Pressure
    This bit is set, if the IQM Queue 3 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP3 0x00800000
/* Nothing
#define IQM_IRNCR_BP3_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP3_INTOCC 0x00800000
/** IQM Queue 2 Back Pressure
    This bit is set, if the IQM Queue 2 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP2 0x00400000
/* Nothing
#define IQM_IRNCR_BP2_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP2_INTOCC 0x00400000
/** IQM Queue 1 Back Pressure
    This bit is set, if the IQM Queue 1 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP1 0x00200000
/* Nothing
#define IQM_IRNCR_BP1_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP1_INTOCC 0x00200000
/** IQM Queue 0 Back Pressure
    This bit is set, if the IQM Queue 0 initiates a back presserue. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_BP0 0x00100000
/* Nothing
#define IQM_IRNCR_BP0_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_BP0_INTOCC 0x00100000
/** IQM Queue 8 Filled
    This bit is set, if the IQM Queue 8 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF8 0x00010000
/* Nothing
#define IQM_IRNCR_QF8_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF8_INTOCC 0x00010000
/** IQM Queue 7 Filled
    This bit is set, if the IQM Queue 7 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF7 0x00008000
/* Nothing
#define IQM_IRNCR_QF7_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF7_INTOCC 0x00008000
/** IQM Queue 6 Filled
    This bit is set, if the IQM Queue 6 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF6 0x00004000
/* Nothing
#define IQM_IRNCR_QF6_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF6_INTOCC 0x00004000
/** IQM Queue 5 Filled
    This bit is set, if the IQM Queue 5 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF5 0x00002000
/* Nothing
#define IQM_IRNCR_QF5_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF5_INTOCC 0x00002000
/** IQM Queue 4 Filled
    This bit is set, if the IQM Queue 4 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF4 0x00001000
/* Nothing
#define IQM_IRNCR_QF4_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF4_INTOCC 0x00001000
/** IQM Queue 3 FilledThis bit is set, if the IQM Queue 3 is filled (ready).
    This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF3 0x00000800
/* Nothing
#define IQM_IRNCR_QF3_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF3_INTOCC 0x00000800
/** IQM Queue 2 FilledThis bit is set, if the IQM Queue 2 is filled (ready).
    This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF2 0x00000400
/* Nothing
#define IQM_IRNCR_QF2_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF2_INTOCC 0x00000400
/** IQM Queue 1 Filled
    This bit is set, if the IQM Queue 1 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF1 0x00000200
/* Nothing
#define IQM_IRNCR_QF1_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF1_INTOCC 0x00000200
/** IQM Queue 0 Filled
    This bit is set, if the IQM Queue 0 is filled (ready). This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_QF0 0x00000100
/* Nothing
#define IQM_IRNCR_QF0_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_QF0_INTOCC 0x00000100
/** IQM Full
    This bit is set, when the shared IQM buffer is full. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_IF 0x00000010
/* Nothing
#define IQM_IRNCR_IF_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_IF_INTOCC 0x00000010
/** Command Error
    This bit is set, if any invalid command is received (TBD). This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_CER 0x00000008
/* Nothing
#define IQM_IRNCR_CER_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define IQM_IRNCR_CER_INTACK 0x00000008
/** Read: Interrupt occurred. */
#define IQM_IRNCR_CER_INTOCC 0x00000008
/** Dequeue Ready
    This bit is set when there is valid data in the DRP registers. This bit is level-sensitive. This bit contributes to the indirect interrupt. */
#define IQM_IRNCR_DR 0x00000004
/* Nothing
#define IQM_IRNCR_DR_NULL 0x00000000 */
/** Read: Interrupt occurred. */
#define IQM_IRNCR_DR_INTOCC 0x00000004

/* Fields of "IRN Interrupt Control Register" */
/** IQM Queue 8 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP8 0x10000000
/** IQM Queue 7 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP7 0x08000000
/** IQM Queue 6 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP6 0x04000000
/** IQM Queue 5 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP5 0x02000000
/** IQM Queue 4 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP4 0x01000000
/** IQM Queue 3 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP3 0x00800000
/** IQM Queue 2 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP2 0x00400000
/** IQM Queue 1 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP1 0x00200000
/** IQM Queue 0 Back Pressure
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_BP0 0x00100000
/** IQM Queue 8 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF8 0x00010000
/** IQM Queue 7 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF7 0x00008000
/** IQM Queue 6 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF6 0x00004000
/** IQM Queue 5 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF5 0x00002000
/** IQM Queue 4 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF4 0x00001000
/** IQM Queue 3 FilledThis bit is set, if the IQM Queue 3 is filled (ready).
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF3 0x00000800
/** IQM Queue 2 FilledThis bit is set, if the IQM Queue 2 is filled (ready).
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF2 0x00000400
/** IQM Queue 1 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF1 0x00000200
/** IQM Queue 0 Filled
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_QF0 0x00000100
/** IQM Full
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_IF 0x00000010
/** Command Error
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_CER 0x00000008
/** Dequeue Ready
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNICR_DR 0x00000004

/* Fields of "IRN Interrupt Enable Register" */
/** IQM Queue 8 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP8 0x10000000
/* Disable
#define IQM_IRNEN_BP8_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP8_EN 0x10000000
/** IQM Queue 7 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP7 0x08000000
/* Disable
#define IQM_IRNEN_BP7_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP7_EN 0x08000000
/** IQM Queue 6 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP6 0x04000000
/* Disable
#define IQM_IRNEN_BP6_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP6_EN 0x04000000
/** IQM Queue 5 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP5 0x02000000
/* Disable
#define IQM_IRNEN_BP5_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP5_EN 0x02000000
/** IQM Queue 4 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP4 0x01000000
/* Disable
#define IQM_IRNEN_BP4_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP4_EN 0x01000000
/** IQM Queue 3 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP3 0x00800000
/* Disable
#define IQM_IRNEN_BP3_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP3_EN 0x00800000
/** IQM Queue 2 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP2 0x00400000
/* Disable
#define IQM_IRNEN_BP2_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP2_EN 0x00400000
/** IQM Queue 1 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP1 0x00200000
/* Disable
#define IQM_IRNEN_BP1_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP1_EN 0x00200000
/** IQM Queue 0 Back Pressure
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_BP0 0x00100000
/* Disable
#define IQM_IRNEN_BP0_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_BP0_EN 0x00100000
/** IQM Queue 8 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF8 0x00010000
/* Disable
#define IQM_IRNEN_QF8_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF8_EN 0x00010000
/** IQM Queue 7 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF7 0x00008000
/* Disable
#define IQM_IRNEN_QF7_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF7_EN 0x00008000
/** IQM Queue 6 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF6 0x00004000
/* Disable
#define IQM_IRNEN_QF6_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF6_EN 0x00004000
/** IQM Queue 5 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF5 0x00002000
/* Disable
#define IQM_IRNEN_QF5_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF5_EN 0x00002000
/** IQM Queue 4 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF4 0x00001000
/* Disable
#define IQM_IRNEN_QF4_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF4_EN 0x00001000
/** IQM Queue 3 FilledThis bit is set, if the IQM Queue 3 is filled (ready).
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF3 0x00000800
/* Disable
#define IQM_IRNEN_QF3_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF3_EN 0x00000800
/** IQM Queue 2 FilledThis bit is set, if the IQM Queue 2 is filled (ready).
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF2 0x00000400
/* Disable
#define IQM_IRNEN_QF2_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF2_EN 0x00000400
/** IQM Queue 1 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF1 0x00000200
/* Disable
#define IQM_IRNEN_QF1_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF1_EN 0x00000200
/** IQM Queue 0 Filled
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_QF0 0x00000100
/* Disable
#define IQM_IRNEN_QF0_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_QF0_EN 0x00000100
/** IQM Full
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_IF 0x00000010
/* Disable
#define IQM_IRNEN_IF_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_IF_EN 0x00000010
/** Command Error
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_CER 0x00000008
/* Disable
#define IQM_IRNEN_CER_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_CER_EN 0x00000008
/** Dequeue Ready
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define IQM_IRNEN_DR 0x00000004
/* Disable
#define IQM_IRNEN_DR_DIS 0x00000000 */
/** Enable */
#define IQM_IRNEN_DR_EN 0x00000004

/* Fields of "Ingress Queue 0 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT00_QE 0x80000000
/* Disable
#define IQM_IQT00_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT00_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT00_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT00_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT00_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT00_QRTH_OFFSET 0

/* Fields of "Ingress Queue 0 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT01_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT01_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT01_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT01_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT01_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT01_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT01_QBTL_OFFSET 0

/* Fields of "Ingress Queue 0 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT02_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT02_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT02_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT02_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT02_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT02_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT02_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT02_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT02_QOCC_OFFSET 0

/* Fields of "Ingress Queue 0 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT03_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT03_QDC_OFFSET 0

/* Fields of "Ingress Queue 0 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT04_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT04_TICK_OFFSET 0

/* Fields of "Ingress Queue 0 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 0 to CPU Link 1 */
#define IQM_IQT05_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 0 to CPU Link 0 */
#define IQM_IQT05_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 0 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT05_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 0 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT05_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 0 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT05_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 0 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT05_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 0 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT05_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 0 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT05_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 0 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT05_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 0 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT05_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 0 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT05_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 0 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT05_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 0 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT05_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 0 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT05_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 0 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT05_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 0 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT05_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 0 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT05_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 0 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT05_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 0 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT05_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 0 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT05_T00 0x00000001

/* Fields of "Ingress Queue 1 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT10_QE 0x80000000
/* Disable
#define IQM_IQT10_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT10_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT10_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT10_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT10_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT10_QRTH_OFFSET 0

/* Fields of "Ingress Queue 1 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT11_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT11_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT11_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT11_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT11_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT11_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT11_QBTL_OFFSET 0

/* Fields of "Ingress Queue 1 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT12_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT12_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT12_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT12_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT12_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT12_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT12_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT12_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT12_QOCC_OFFSET 0

/* Fields of "Ingress Queue 1 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT13_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT13_QDC_OFFSET 0

/* Fields of "Ingress Queue 1 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT14_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT14_TICK_OFFSET 0

/* Fields of "Ingress Queue 1 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 1 to CPU Link 1 */
#define IQM_IQT15_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 1 to CPU Link 0 */
#define IQM_IQT15_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 1 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT15_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 1 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT15_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 1 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT15_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 1 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT15_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 1 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT15_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 1 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT15_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 1 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT15_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 1 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT15_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 1 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT15_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 1 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT15_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 1 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT15_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 1 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT15_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 1 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT15_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 1 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT15_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 1 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT15_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 1 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT15_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 1 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT15_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 1 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT15_T00 0x00000001

/* Fields of "Ingress Queue 2 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT20_QE 0x80000000
/* Disable
#define IQM_IQT20_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT20_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT20_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT20_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT20_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT20_QRTH_OFFSET 0

/* Fields of "Ingress Queue 2 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT21_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT21_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT21_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT21_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT21_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT21_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT21_QBTL_OFFSET 0

/* Fields of "Ingress Queue 2 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT22_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT22_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT22_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT22_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT22_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT22_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT22_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT22_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT22_QOCC_OFFSET 0

/* Fields of "Ingress Queue 2 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT23_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT23_QDC_OFFSET 0

/* Fields of "Ingress Queue 2 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT24_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT24_TICK_OFFSET 0

/* Fields of "Ingress Queue 2 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 2 to CPU Link 1 */
#define IQM_IQT25_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 2 to CPU Link 0 */
#define IQM_IQT25_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 2 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT25_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 2 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT25_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 2 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT25_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 2 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT25_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 2 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT25_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 2 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT25_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 2 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT25_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 2 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT25_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 2 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT25_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 2 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT25_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 2 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT25_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 2 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT25_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 2 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT25_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 2 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT25_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 2 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT25_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 2 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT25_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 2 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT25_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 2 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT25_T00 0x00000001

/* Fields of "Ingress Queue 3 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT30_QE 0x80000000
/* Disable
#define IQM_IQT30_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT30_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT30_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT30_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT30_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT30_QRTH_OFFSET 0

/* Fields of "Ingress Queue 3 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT31_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT31_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT31_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT31_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT31_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT31_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT31_QBTL_OFFSET 0

/* Fields of "Ingress Queue 3 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT32_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT32_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT32_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT32_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT32_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT32_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT32_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT32_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT32_QOCC_OFFSET 0

/* Fields of "Ingress Queue 3 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT33_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT33_QDC_OFFSET 0

/* Fields of "Ingress Queue 3 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT34_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT34_TICK_OFFSET 0

/* Fields of "Ingress Queue 3 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 3 to CPU Link 1 */
#define IQM_IQT35_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 3 to CPU Link 0 */
#define IQM_IQT35_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 3 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT35_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 3 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT35_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 3 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT35_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 3 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT35_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 3 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT35_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 3 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT35_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 3 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT35_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 3 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT35_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 3 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT35_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 3 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT35_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 3 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT35_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 3 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT35_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 3 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT35_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 3 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT35_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 3 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT35_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 3 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT35_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 3 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT35_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 3 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT35_T00 0x00000001

/* Fields of "Ingress Queue 4 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT40_QE 0x80000000
/* Disable
#define IQM_IQT40_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT40_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT40_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT40_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT40_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT40_QRTH_OFFSET 0

/* Fields of "Ingress Queue 4 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT41_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT41_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT41_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT41_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT41_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT41_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT41_QBTL_OFFSET 0

/* Fields of "Ingress Queue 4 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT42_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT42_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT42_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT42_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT42_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT42_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT42_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT42_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT42_QOCC_OFFSET 0

/* Fields of "Ingress Queue 4 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT43_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT43_QDC_OFFSET 0

/* Fields of "Ingress Queue 4 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT44_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT44_TICK_OFFSET 0

/* Fields of "Ingress Queue 4 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 4 to CPU Link 1 */
#define IQM_IQT45_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 4 to CPU Link 0 */
#define IQM_IQT45_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 4 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT45_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 4 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT45_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 4 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT45_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 4 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT45_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 4 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT45_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 4 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT45_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 4 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT45_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 4 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT45_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 4 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT45_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 4 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT45_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 4 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT45_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 4 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT45_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 4 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT45_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 4 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT45_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 4 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT45_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 4 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT45_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 4 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT45_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 4 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT45_T00 0x00000001

/* Fields of "Ingress Queue 5 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT50_QE 0x80000000
/* Disable
#define IQM_IQT50_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT50_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT50_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT50_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT50_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT50_QRTH_OFFSET 0

/* Fields of "Ingress Queue 5 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT51_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT51_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT51_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT51_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT51_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT51_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT51_QBTL_OFFSET 0

/* Fields of "Ingress Queue 5 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT52_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT52_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT52_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT52_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT52_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT52_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT52_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT52_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT52_QOCC_OFFSET 0

/* Fields of "Ingress Queue 5 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT53_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT53_QDC_OFFSET 0

/* Fields of "Ingress Queue 5 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT54_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT54_TICK_OFFSET 0

/* Fields of "Ingress Queue 5 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 5 to CPU Link 1 */
#define IQM_IQT55_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 5 to CPU Link 0 */
#define IQM_IQT55_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 5 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT55_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 5 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT55_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 5 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT55_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 5 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT55_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 5 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT55_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 5 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT55_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 5 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT55_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 5 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT55_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 5 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT55_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 5 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT55_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 5 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT55_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 5 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT55_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 5 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT55_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 5 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT55_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 5 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT55_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 5 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT55_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 5 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT55_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 5 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT55_T00 0x00000001

/* Fields of "Ingress Queue 6 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT60_QE 0x80000000
/* Disable
#define IQM_IQT60_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT60_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT60_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT60_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT60_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT60_QRTH_OFFSET 0

/* Fields of "Ingress Queue 6 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT61_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT61_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT61_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT61_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT61_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT61_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT61_QBTL_OFFSET 0

/* Fields of "Ingress Queue 6 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT62_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT62_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT62_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT62_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT62_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT62_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT62_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT62_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT62_QOCC_OFFSET 0

/* Fields of "Ingress Queue 6 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT63_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT63_QDC_OFFSET 0

/* Fields of "Ingress Queue 6 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT64_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT64_TICK_OFFSET 0

/* Fields of "Ingress Queue 6 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 6 to CPU Link 1 */
#define IQM_IQT65_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 6 to CPU Link 0 */
#define IQM_IQT65_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 6 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT65_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 6 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT65_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 6 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT65_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 6 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT65_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 6 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT65_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 6 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT65_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 6 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT65_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 6 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT65_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 6 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT65_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 6 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT65_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 6 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT65_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 6 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT65_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 6 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT65_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 6 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT65_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 6 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT65_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 6 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT65_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 6 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT65_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 6 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT65_T00 0x00000001

/* Fields of "Ingress Queue 7 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT70_QE 0x80000000
/* Disable
#define IQM_IQT70_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT70_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT70_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT70_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT70_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT70_QRTH_OFFSET 0

/* Fields of "Ingress Queue 7 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT71_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT71_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT71_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT71_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT71_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT71_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT71_QBTL_OFFSET 0

/* Fields of "Ingress Queue 7 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT72_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT72_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT72_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT72_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT72_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT72_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT72_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT72_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT72_QOCC_OFFSET 0

/* Fields of "Ingress Queue 7 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT73_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT73_QDC_OFFSET 0

/* Fields of "Ingress Queue 7 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT74_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT74_TICK_OFFSET 0

/* Fields of "Ingress Queue 7 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 7 to CPU Link 1 */
#define IQM_IQT75_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 7 to CPU Link 0 */
#define IQM_IQT75_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 7 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT75_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 7 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT75_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 7 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT75_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 7 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT75_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 7 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT75_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 7 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT75_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 7 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT75_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 7 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT75_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 7 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT75_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 7 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT75_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 7 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT75_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 7 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT75_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 7 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT75_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 7 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT75_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 7 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT75_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 7 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT75_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 7 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT75_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 7 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT75_T00 0x00000001

/* Fields of "Ingress Queue 8 Table Register 0" */
/** Queue Enable
    This bit can be set to enable admission of PDUs into the queue */
#define IQM_IQT80_QE 0x80000000
/* Disable
#define IQM_IQT80_QE_DIS 0x00000000 */
/** Enable */
#define IQM_IQT80_QE_EN 0x80000000
/** Queue Tail Drop Threshold
    This threshold specifies the queue discard level in units of 8 segments. Above this threshold, arriving PDUs are discarded without further check. Highest functional value is 2304, as queue occupies complete SSB */
#define IQM_IQT80_QDTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT80_QDTH_OFFSET 16
/** Queue Reservation Threshold
    This threshold specifies the minimum queue buffer reservation in units of 8 segments. Below this threshold, arriving PDUs are accepted without consideration in the global shared buffer.It is possible to modify this threshold after activation, but it is not recommended to do so unless the SSB is completely emptied of stored PDUs and the ingress traffic to IQM is blocked */
#define IQM_IQT80_QRTH_MASK 0x00000FFF
/** field offset */
#define IQM_IQT80_QRTH_OFFSET 0

/* Fields of "Ingress Queue 8 Table Register 1" */
/** Queue Blocked
    This bit set indicates that the queue does not participate in the WRR scheduling */
#define IQM_IQT81_QB 0x80000000
/* Queue Not Blocked
#define IQM_IQT81_QB_NB 0x00000000 */
/** Queue Blocked */
#define IQM_IQT81_QB_BL 0x80000000
/** Queue Backpressure Threshold High
    This threshold specifies the backpressure assertion level in units of 8 segments. If QOCC raises above this threshold, BP is set to 1, asserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT81_QBTH_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT81_QBTH_OFFSET 16
/** Queue Backpressure Threshold Low
    This threshold specifies the backpressure de-assertion level in units of 8 segments. If QOCC falls below this threshold, BP is set to 0, deasserting the backpressure signal IQ_Backpressure. */
#define IQM_IQT81_QBTL_MASK 0x00000FFF
/** field offset */
#define IQM_IQT81_QBTL_OFFSET 0

/* Fields of "Ingress Queue 8 Table Register 2" */
/** Queue Filled
    This bit set indicates that the queue contains at least one waiting PDU. Used to drive the Q_filled status signals towards PCTRL. */
#define IQM_IQT82_QF 0x80000000
/** Backpressure
    This bit set indicates asserted backpressure towards the ingress interfaces. */
#define IQM_IQT82_BP 0x40000000
/* Backpressure De-asserted
#define IQM_IQT82_BP_BD 0x00000000 */
/** Backpressure Asserted */
#define IQM_IQT82_BP_BA 0x40000000
/** Queue pointer segment full
    This bit indicates the queue pointer segment full status. */
#define IQM_IQT82_QPSF 0x10000000
/** PDU Occupancy Counter
    This field gives the queue occupancy in units of PDUs. Initialized to 0. */
#define IQM_IQT82_POCC_MASK 0x0FFF0000
/** field offset */
#define IQM_IQT82_POCC_OFFSET 16
/** Queue Occupancy Counter
    This field gives the queue occupancy in units of segments. Initialized to 0. */
#define IQM_IQT82_QOCC_MASK 0x00007FFF
/** field offset */
#define IQM_IQT82_QOCC_OFFSET 0

/* Fields of "Ingress Queue 8 Table Register 3" */
/** Queue PDU Discard Counter
    Roll over at max */
#define IQM_IQT83_QDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT83_QDC_OFFSET 0

/* Fields of "Ingress Queue 8 Table Register 4" */
/** Ingress Queue Ticket Counter
    This counter is incremented for every PDU that is transmitted from the IQM queue to the dispatcher. It wraps at max. The lower 8 bits of TICK are used as a re-sequencing ticket and transferred to the dispatcher in the PDU meta-data. */
#define IQM_IQT84_TICK_MASK 0xFFFFFFFF
/** field offset */
#define IQM_IQT84_TICK_OFFSET 0

/* Fields of "Ingress Queue 8 Table Register 5" */
/** CPU Link 1
    Dispatches packet header data from Ingress Queue 8 to CPU Link 1 */
#define IQM_IQT85_T61 0x00080000
/** CPU Link 0
    Dispatches packet header data from Ingress Queue 8 to CPU Link 0 */
#define IQM_IQT85_T60 0x00040000
/** Thread 5.2.x
    Dispatches packet header data from Ingress Queue 8 to PE 5, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT85_T52 0x00020000
/** Thread 5.1.x
    Dispatches packet header data from Ingress Queue 8 to PE 5, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT85_T51 0x00010000
/** Thread 5.0.x
    Dispatches packet header data from Ingress Queue 8 to PE 5, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT85_T50 0x00008000
/** Thread 4.2.x
    Dispatches packet header data from Ingress Queue 8 to PE 4, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT85_T42 0x00004000
/** Thread 4.1.x
    Dispatches packet header data from Ingress Queue 8 to PE 4, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT85_T41 0x00002000
/** Thread 4.0.x
    Dispatches packet header data from Ingress Queue 8 to PE 4, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT85_T40 0x00001000
/** Thread 3.2.x
    Dispatches packet header data from Ingress Queue 8 to PE 3, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT85_T32 0x00000800
/** Thread 3.1.x
    Dispatches packet header data from Ingress Queue 8 to PE 3, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT85_T31 0x00000400
/** Thread 3.0.x
    Dispatches packet header data from Ingress Queue 8 to PE 3, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT85_T30 0x00000200
/** Thread 2.2.x
    Dispatches packet header data from Ingress Queue 8 to PE 2, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT85_T22 0x00000100
/** Thread 2.1.x
    Dispatches packet header data from Ingress Queue 8 to PE 2, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT85_T21 0x00000080
/** Thread 2.0.x
    Dispatches packet header data from Ingress Queue 8 to PE 2, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT85_T20 0x00000040
/** Thread 1.2.x
    Dispatches packet header data from Ingress Queue 8 to PE 1, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT85_T12 0x00000020
/** Thread 1.1.x
    Dispatches packet header data from Ingress Queue 8 to PE 1, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT85_T11 0x00000010
/** Thread 1.0.x
    Dispatches packet header data from Ingress Queue 8 to PE 1, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT85_T10 0x00000008
/** Thread 0.2.x
    Dispatches packet header data from Ingress Queue 8 to PE 0, Virtual Machine 2, Threads 0-3 */
#define IQM_IQT85_T02 0x00000004
/** Thread 0.1.x
    Dispatches packet header data from Ingress Queue 8 to PE 0, Virtual Machine 1, Threads 0-3 */
#define IQM_IQT85_T01 0x00000002
/** Thread 0.0.x
    Dispatches packet header data from Ingress Queue 8 to PE 0, Virtual Machine 0, Threads 0-3 */
#define IQM_IQT85_T00 0x00000001

/* Fields of "Free Pointer Counter Register" */
/** Free Pointer Counter
    This field holds the number of free PDU pointers in the IPPT. */
#define IQM_FPCR_FPC_MASK 0x00000FFF
/** field offset */
#define IQM_FPCR_FPC_OFFSET 0

/* Fields of "Global Occupancy Counter Register" */
/** Global Occupancy Counter
    This register defines the global occupancy of the IQM in Segments. */
#define IQM_GOCC_GOCC_MASK 0x00007FFF
/** field offset */
#define IQM_GOCC_GOCC_OFFSET 0

/* Fields of "Global Occupancy Threshold Register" */
/** Global Occupancy Threshold
    When GOCC raises above this threshold, PDUs are discarded */
#define IQM_GOTH_GOTH_MASK 0x00007FFF
/** field offset */
#define IQM_GOTH_GOTH_OFFSET 0

/* Fields of "Global PDU Discard Counter Register" */
/** Global PDU Discard Counter
    Counts PDUs discarded beacause GOTH is exceeded. */
#define IQM_GPDC_GPDC_MASK 0xFFFFFFFF
/** field offset */
#define IQM_GPDC_GPDC_OFFSET 0

/* Fields of "Time Stamp Register" */
/** Time Stamp
    Each accepted PDU gets the current value of this register interpreted as a time stamp. */
#define IQM_TS_TS_MASK 0x00FFFFFF
/** field offset */
#define IQM_TS_TS_OFFSET 0

/* Fields of "WRR Control Register" */
/** Scheduler Period
    This field defines the scheduler period for the IQM module and thus the number of slots in the WRRQx registers which are used. */
#define IQM_WRRC_PER_MASK 0x0000003F
/** field offset */
#define IQM_WRRC_PER_OFFSET 0

/* Fields of "WRR QID Register 0" */
/** WRR QID slot 7
    This field holds the QID to be selected in WRR slot 7 */
#define IQM_WRRQ0_WRRQ7_MASK 0xF0000000
/** field offset */
#define IQM_WRRQ0_WRRQ7_OFFSET 28
/** WRR QID slot 6
    This field holds the QID to be selected in WRR slot 6 */
#define IQM_WRRQ0_WRRQ6_MASK 0x0F000000
/** field offset */
#define IQM_WRRQ0_WRRQ6_OFFSET 24
/** WRR QID slot 5
    This field holds the QID to be selected in WRR slot 5 */
#define IQM_WRRQ0_WRRQ5_MASK 0x00F00000
/** field offset */
#define IQM_WRRQ0_WRRQ5_OFFSET 20
/** WRR QID slot 4
    This field holds the QID to be selected in WRR slot 4 */
#define IQM_WRRQ0_WRRQ4_MASK 0x000F0000
/** field offset */
#define IQM_WRRQ0_WRRQ4_OFFSET 16
/** WRR QID slot 3
    This field holds the QID to be selected in WRR slot 3 */
#define IQM_WRRQ0_WRRQ3_MASK 0x0000F000
/** field offset */
#define IQM_WRRQ0_WRRQ3_OFFSET 12
/** WRR QID slot 2
    This field holds the QID to be selected in WRR slot 2 */
#define IQM_WRRQ0_WRRQ2_MASK 0x00000F00
/** field offset */
#define IQM_WRRQ0_WRRQ2_OFFSET 8
/** WRR QID slot 1
    This field holds the QID to be selected in WRR slot 1 */
#define IQM_WRRQ0_WRRQ1_MASK 0x000000F0
/** field offset */
#define IQM_WRRQ0_WRRQ1_OFFSET 4
/** WRR QID slot 0
    This field holds the QID to be selected in WRR slot 0 */
#define IQM_WRRQ0_WRRQ0_MASK 0x0000000F
/** field offset */
#define IQM_WRRQ0_WRRQ0_OFFSET 0

/* Fields of "WRR QID Register 1" */
/** WRR QID slot 15
    This field holds the QID to be selected in WRR slot 15 */
#define IQM_WRRQ1_WRRQ15_MASK 0xF0000000
/** field offset */
#define IQM_WRRQ1_WRRQ15_OFFSET 28
/** WRR QID slot 14
    This field holds the QID to be selected in WRR slot 14 */
#define IQM_WRRQ1_WRRQ14_MASK 0x0F000000
/** field offset */
#define IQM_WRRQ1_WRRQ14_OFFSET 24
/** WRR QID slot 13
    This field holds the QID to be selected in WRR slot 13 */
#define IQM_WRRQ1_WRRQ13_MASK 0x00F00000
/** field offset */
#define IQM_WRRQ1_WRRQ13_OFFSET 20
/** WRR QID slot 12
    This field holds the QID to be selected in WRR slot 12 */
#define IQM_WRRQ1_WRRQ12_MASK 0x000F0000
/** field offset */
#define IQM_WRRQ1_WRRQ12_OFFSET 16
/** WRR QID slot 11
    This field holds the QID to be selected in WRR slot 11 */
#define IQM_WRRQ1_WRRQ11_MASK 0x0000F000
/** field offset */
#define IQM_WRRQ1_WRRQ11_OFFSET 12
/** WRR QID slot 10
    This field holds the QID to be selected in WRR slot 10 */
#define IQM_WRRQ1_WRRQ10_MASK 0x00000F00
/** field offset */
#define IQM_WRRQ1_WRRQ10_OFFSET 8
/** WRR QID slot 9
    This field holds the QID to be selected in WRR slot 9 */
#define IQM_WRRQ1_WRRQ9_MASK 0x000000F0
/** field offset */
#define IQM_WRRQ1_WRRQ9_OFFSET 4
/** WRR QID slot 8
    This field holds the QID to be selected in WRR slot 8 */
#define IQM_WRRQ1_WRRQ8_MASK 0x0000000F
/** field offset */
#define IQM_WRRQ1_WRRQ8_OFFSET 0

/* Fields of "WRR QID Register 2" */
/** WRR QID slot 23
    This field holds the QID to be selected in WRR slot 23 */
#define IQM_WRRQ2_WRRQ23_MASK 0xF0000000
/** field offset */
#define IQM_WRRQ2_WRRQ23_OFFSET 28
/** WRR QID slot 22
    This field holds the QID to be selected in WRR slot 22 */
#define IQM_WRRQ2_WRRQ22_MASK 0x0F000000
/** field offset */
#define IQM_WRRQ2_WRRQ22_OFFSET 24
/** WRR QID slot 21
    This field holds the QID to be selected in WRR slot 21 */
#define IQM_WRRQ2_WRRQ21_MASK 0x00F00000
/** field offset */
#define IQM_WRRQ2_WRRQ21_OFFSET 20
/** WRR QID slot 20
    This field holds the QID to be selected in WRR slot 20 */
#define IQM_WRRQ2_WRRQ20_MASK 0x000F0000
/** field offset */
#define IQM_WRRQ2_WRRQ20_OFFSET 16
/** WRR QID slot 19
    This field holds the QID to be selected in WRR slot 19 */
#define IQM_WRRQ2_WRRQ19_MASK 0x0000F000
/** field offset */
#define IQM_WRRQ2_WRRQ19_OFFSET 12
/** WRR QID slot 18
    This field holds the QID to be selected in WRR slot 18 */
#define IQM_WRRQ2_WRRQ18_MASK 0x00000F00
/** field offset */
#define IQM_WRRQ2_WRRQ18_OFFSET 8
/** WRR QID slot 17
    This field holds the QID to be selected in WRR slot 17 */
#define IQM_WRRQ2_WRRQ17_MASK 0x000000F0
/** field offset */
#define IQM_WRRQ2_WRRQ17_OFFSET 4
/** WRR QID slot 16
    This field holds the QID to be selected in WRR slot 16 */
#define IQM_WRRQ2_WRRQ16_MASK 0x0000000F
/** field offset */
#define IQM_WRRQ2_WRRQ16_OFFSET 0

/* Fields of "WRR QID Register 3" */
/** WRR QID slot 31
    This field holds the QID to be selected in WRR slot 31 */
#define IQM_WRRQ3_WRRQ31_MASK 0xF0000000
/** field offset */
#define IQM_WRRQ3_WRRQ31_OFFSET 28
/** WRR QID slot 30
    This field holds the QID to be selected in WRR slot 30 */
#define IQM_WRRQ3_WRRQ30_MASK 0x0F000000
/** field offset */
#define IQM_WRRQ3_WRRQ30_OFFSET 24
/** WRR QID slot 29
    This field holds the QID to be selected in WRR slot 29 */
#define IQM_WRRQ3_WRRQ29_MASK 0x00F00000
/** field offset */
#define IQM_WRRQ3_WRRQ29_OFFSET 20
/** WRR QID slot 28
    This field holds the QID to be selected in WRR slot 28 */
#define IQM_WRRQ3_WRRQ28_MASK 0x000F0000
/** field offset */
#define IQM_WRRQ3_WRRQ28_OFFSET 16
/** WRR QID slot 27
    This field holds the QID to be selected in WRR slot 27 */
#define IQM_WRRQ3_WRRQ27_MASK 0x0000F000
/** field offset */
#define IQM_WRRQ3_WRRQ27_OFFSET 12
/** WRR QID slot 26
    This field holds the QID to be selected in WRR slot 26 */
#define IQM_WRRQ3_WRRQ26_MASK 0x00000F00
/** field offset */
#define IQM_WRRQ3_WRRQ26_OFFSET 8
/** WRR QID slot 25
    This field holds the QID to be selected in WRR slot 25 */
#define IQM_WRRQ3_WRRQ25_MASK 0x000000F0
/** field offset */
#define IQM_WRRQ3_WRRQ25_OFFSET 4
/** WRR QID slot 24
    This field holds the QID to be selected in WRR slot 24 */
#define IQM_WRRQ3_WRRQ24_MASK 0x0000000F
/** field offset */
#define IQM_WRRQ3_WRRQ24_OFFSET 0

/* Fields of "WRR QID Register 4" */
/** WRR QID slot 35
    This field holds the QID to be selected in WRR slot 35 */
#define IQM_WRRQ4_WRRQ35_MASK 0x0000F000
/** field offset */
#define IQM_WRRQ4_WRRQ35_OFFSET 12
/** WRR QID slot 34
    This field holds the QID to be selected in WRR slot 34 */
#define IQM_WRRQ4_WRRQ34_MASK 0x00000F00
/** field offset */
#define IQM_WRRQ4_WRRQ34_OFFSET 8
/** WRR QID slot 33
    This field holds the QID to be selected in WRR slot 33 */
#define IQM_WRRQ4_WRRQ33_MASK 0x000000F0
/** field offset */
#define IQM_WRRQ4_WRRQ33_OFFSET 4
/** WRR QID slot 32
    This field holds the QID to be selected in WRR slot 32 */
#define IQM_WRRQ4_WRRQ32_MASK 0x0000000F
/** field offset */
#define IQM_WRRQ4_WRRQ32_OFFSET 0

/* Fields of "Segment Free Register 0" */
/** Segment 31 - 00 Free
    Each bit in this register indicates by its position if the corresponding pointer segment address is free (=1) */
#define IQM_SFREE0_SF31_00_MASK 0xFFFFFFFF
/** field offset */
#define IQM_SFREE0_SF31_00_OFFSET 0

/* Fields of "Segment Free Register 1" */
/** Segment 47 - 32 Free
    Each bit in this register indicates by its position if the corresponding pointer segment address is free (=1) */
#define IQM_SFREE1_SF47_32_MASK 0x0000FFFF
/** field offset */
#define IQM_SFREE1_SF47_32_OFFSET 0

/* Fields of "Dequeue Respond Parameter Register 0" */
/** Time Stamp
    Each accepted PDU gets the current value of this register interpreted as a time stamp. */
#define IQM_DRP0_TS_MASK 0x00FFFFFF
/** field offset */
#define IQM_DRP0_TS_OFFSET 0

/* Fields of "Dequeue Respond Parameter Register 1" */
/** Head LSA
    The logical SSB address of the stored PDU head */
#define IQM_DRP1_NLSA_MASK 0x7FFF0000
/** field offset */
#define IQM_DRP1_NLSA_OFFSET 16
/** PDU Type
    The PDU type is provided by SDMAx as a basic HW classification */
#define IQM_DRP1_PDUT_MASK 0x00007000
/** field offset */
#define IQM_DRP1_PDUT_OFFSET 12
/** Ingress Port Identifier
    Indentifies the ingress port. The assignment is done in hardware upon dequeue. */
#define IQM_DRP1_IPN_MASK 0x00000F00
/** field offset */
#define IQM_DRP1_IPN_OFFSET 8
/** Ticket
    The Ticket is locally assigned from a ticket counter per queue. The assignment is done in hardware upon dequeue. */
#define IQM_DRP1_TICK_MASK 0x000000FF
/** field offset */
#define IQM_DRP1_TICK_OFFSET 0

/* Fields of "Dequeue Respond Parameter Register 2" */
/** GEM Port Index
    The GEM Port Index is mapped from the GEM Port Identifier in SDMAG */
#define IQM_DRP2_GPIX_MASK 0x00FF0000
/** field offset */
#define IQM_DRP2_GPIX_OFFSET 16
/** PDU Length
    The PDU Length in Bytes */
#define IQM_DRP2_PLEN_MASK 0x0000FFFF
/** field offset */
#define IQM_DRP2_PLEN_OFFSET 0

/* Fields of "Dequeue Respond Parameter Register 3" */
/** Tail LSA
    The logical SSB address of the stored PDU tail */
#define IQM_DRP3_TLSA_MASK 0x7FFF0000
/** field offset */
#define IQM_DRP3_TLSA_OFFSET 16
/** Head LSA
    The logical SSB address of the stored PDU head */
#define IQM_DRP3_HLSA_MASK 0x00007FFF
/** field offset */
#define IQM_DRP3_HLSA_OFFSET 0

/* Fields of "Dequeue Request Command Register" */
/** Enable
    Writing a 1 to ENA triggers the submission of the Enqueue_Request command and the corresponding parameters to the internal state machines */
#define IQM_DRC_ENA 0x00010000
/** Queue Identifier
    Selector for the QID needed for the submission of the Dequeue_Request command and the corresponding parameters to the internal state machines */
#define IQM_DRC_QID_MASK 0x0000000F
/** field offset */
#define IQM_DRC_QID_OFFSET 0

/*! @} */ /* IQM_REGISTER */

#endif /* _iqm_reg_h */
