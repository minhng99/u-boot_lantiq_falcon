/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _fsqm_reg_h
#define _fsqm_reg_h

/** \addtogroup FSQM_REGISTER
   @{
*/
/* access macros */
#define fsqm_r32(reg) reg_r32(&fsqm->reg)
#define fsqm_w32(val, reg) reg_w32(val, &fsqm->reg)
#define fsqm_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &fsqm->reg)
#define fsqm_r32_table(reg, idx) reg_r32_table(fsqm->reg, idx)
#define fsqm_w32_table(val, reg, idx) reg_w32_table(val, fsqm->reg, idx)
#define fsqm_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, fsqm->reg, idx)
#define fsqm_adr_table(reg, idx) adr_table(fsqm->reg, idx)


/** FSQM register structure */
struct gpon_reg_fsqm
{
   /** Control Register
       This register provides the global FSQM controls. */
   unsigned int ctrl; /* 0x00000000 */
   /** Priority Control Register (only A1x)
       This register controls the LLT access priority of the different FSQM bus masters. */
   unsigned int prio_a1x; /* 0x00000004 */
   /** IO-Buffer Control Register for Read (ALLOC)
       This register controls the different IO read buffers in the FSQM. */
   unsigned int io_buf_rd; /* 0x00000008 */
   /** IO-Buffer Control Register for Write (FREE)
       This register controls the different IO write buffers in the FSQM. */
   unsigned int io_buf_wr; /* 0x0000000C */
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
   unsigned int res_0; /* 0x0000001C */
   union {
      /** Input Free Segment Queue Register (only A1x)
          This register provides access to the head and tail pointers of the Input Free Segment Queue. */
      unsigned int ifsq_a1x; /* 0x00000020 */
      /** TAIL LSA Capture Register (only A2x)
          In case of a memory address violation (FRMEM, ACCMEM), this register holds the OFSQ TAIL captured at that time */
      unsigned int tailcapr; /* 0x00000020 */
   };
   /** Output Free Segment Queue Register
       This register provides access to the head and tail pointers of the Output Free Segment Queue. */
   unsigned int ofsq; /* 0x00000024 */
   /** Input Free Segment Counter Register (only A1x)
       This register holds the number of entries in the Input Free Segment Queue. */
   unsigned int ifsc_a1x; /* 0x00000028 */
   /** Output Free Segment Counter Register
       This register holds the number of entries in the Output Free Segment Queue. */
   unsigned int ofsc; /* 0x0000002C */
   /** Free Segment Queue Threshold Register 0
       This register provides a general supervision threshold for the free segment queue. */
   unsigned int fsqt0; /* 0x00000030 */
   /** Reserved */
   unsigned int res_1[15]; /* 0x00000034 */
   /** Free Segment Queue Threshold Register 1
       This register provides a general supervision threshold for the free segment queue. */
   unsigned int fsqt1; /* 0x00000070 */
   /** Reserved */
   unsigned int res_2[15]; /* 0x00000074 */
   /** Free Segment Queue Threshold Register 2
       This register provides a general supervision threshold for the free segment queue. */
   unsigned int fsqt2; /* 0x000000B0 */
   /** Reserved */
   unsigned int res_3[15]; /* 0x000000B4 */
   /** Free Segment Queue Threshold Register 3
       This register provides a general supervision threshold for the free segment queue. */
   unsigned int fsqt3; /* 0x000000F0 */
   /** Reserved */
   unsigned int res_4[15]; /* 0x000000F4 */
   /** Free Segment Queue Threshold Register 4
       This register provides a general supervision threshold for the free segment queue. */
   unsigned int fsqt4; /* 0x00000130 */
   /** Reserved */
   unsigned int res_5[19]; /* 0x00000134 */
   /** Logical Segment Address Range (only A2x)
       This register holds the allowed LSA range for the OFSQ. At initialization the OFSQ must be started at MINLSA and terminated at MAXLSA */
   unsigned int lsarng; /* 0x00000180 */
   /** Reserved */
   unsigned int res_6[3]; /* 0x00000184 */
   /** Requestrate Limitation Register 0 (only A2x)
       This register holds the parameters for the request rate limiters for masters 0 ... 3 */
   unsigned int rlimr0; /* 0x00000190 */
   /** Requestrate Limitation Register 1 (only A2x)
       This register holds the parameters for the request rate limiters for masters 4 ... 7 */
   unsigned int rlimr1; /* 0x00000194 */
   /** Requestrate Limitation Register 2 (only A2x)
       This register holds the parameters for the request rate limiters for masters 0 ... 3 */
   unsigned int rlimr2; /* 0x00000198 */
   /** Requestrate Limitation Register 3 (only A2x)
       This register holds the parameters for the request rate limiters for masters 0 ... 3 */
   unsigned int rlimr3; /* 0x0000019C */
   /** Reserved */
   unsigned int res_7[65432]; /* 0x000001A0 */
   /** Input Message Queue Register (only A1x)
       When written (FREE command), this register reflects the head and tail entries of the respective Input Message Queue, the length to be freed must be provided in the lower 15 bits of the address. When read (ALLOC command), the register returns an LSA in the field HLSA. */
   unsigned int imq_a1x[32768]; /* 0x00040000 */
   /** Output Message Queue Register
       When written (FREE command), this register reflects the head and tail entries of the respective Output Message Queue, the length to be freed must be provided in the lower 15 bits of the address. When read (ALLOC command), the register returns an LSA in the field HLSA. */
   unsigned int omq[32768]; /* 0x00060000 */
   /** Repeat Counter Addresses
       This addresses reflect the memory containing the Repeat Counter values. */
   unsigned int rcnt[32768]; /* 0x00080000 */
   /** Repeat Counter Inc/Dec Addresses
       This addresses are used to increment (Write) or decrement (Read) the repeat rounter values. A read operation will return the old read counter value. */
   unsigned int rcnt_incdec[32768]; /* 0x000A0000 */
   /** LLT RAM Addresses
       This addresses reflect the memory containing the LLT. */
   unsigned int ram[65536]; /* 0x000C0000 */
};


/* Fields of "Control Register" */
/** Alloc Disable for master 14
    When selected (=1) this bit disables alloc for master14. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD14 0x40000000
/* Not selected
#define FSQM_CTRL_AD14_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD14_SEL 0x40000000
/** Alloc Disable for master 13
    When selected (=1) this bit disables alloc for master13. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD13 0x20000000
/* Not selected
#define FSQM_CTRL_AD13_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD13_SEL 0x20000000
/** Alloc Disable for master 12
    When selected (=1) this bit disables alloc for master12. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD12 0x10000000
/* Not selected
#define FSQM_CTRL_AD12_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD12_SEL 0x10000000
/** Alloc Disable for master 11
    When selected (=1) this bit disables alloc for master11. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD11 0x08000000
/* Not selected
#define FSQM_CTRL_AD11_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD11_SEL 0x08000000
/** Alloc Disable for master 10
    When selected (=1) this bit disables alloc for master10. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD10 0x04000000
/* Not selected
#define FSQM_CTRL_AD10_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD10_SEL 0x04000000
/** Alloc Disable for master 9
    When selected (=1) this bit disables alloc for master9. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD9 0x02000000
/* Not selected
#define FSQM_CTRL_AD9_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD9_SEL 0x02000000
/** Alloc Disable for master 8
    When selected (=1) this bit disables alloc for master8. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD8 0x01000000
/* Not selected
#define FSQM_CTRL_AD8_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD8_SEL 0x01000000
/** Alloc Disable for master 7
    When selected (=1) this bit disables alloc for master7. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD7 0x00800000
/* Not selected
#define FSQM_CTRL_AD7_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD7_SEL 0x00800000
/** Alloc Disable for master 6
    When selected (=1) this bit disables alloc for master6. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD6 0x00400000
/* Not selected
#define FSQM_CTRL_AD6_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD6_SEL 0x00400000
/** Alloc Disable for master 5
    When selected (=1) this bit disables alloc for master5. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD5 0x00200000
/* Not selected
#define FSQM_CTRL_AD5_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD5_SEL 0x00200000
/** Alloc Disable for master 4
    When selected (=1) this bit disables alloc for master4. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD4 0x00100000
/* Not selected
#define FSQM_CTRL_AD4_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD4_SEL 0x00100000
/** Alloc Disable for master 3
    When selected (=1) this bit disables alloc for master3. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD3 0x00080000
/* Not selected
#define FSQM_CTRL_AD3_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD3_SEL 0x00080000
/** Alloc Disable for master 2
    When selected (=1) this bit disables alloc for master2. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD2 0x00040000
/* Not selected
#define FSQM_CTRL_AD2_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD2_SEL 0x00040000
/** Alloc Disable for master 1
    When selected (=1) this bit disables alloc for master1. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD1 0x00020000
/* Not selected
#define FSQM_CTRL_AD1_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD1_SEL 0x00020000
/** Alloc Disable for master 0
    When selected (=1) this bit disables alloc for master0. This master will receive NIL = 0x7FFF */
#define FSQM_CTRL_AD0 0x00010000
/* Not selected
#define FSQM_CTRL_AD0_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_AD0_SEL 0x00010000
/** Soft Reset of the FSQM Module
    This bit resets all registers of the FSQM. Note that the memory contents are not touched. */
#define FSQM_CTRL_RES 0x00000010
/* Disable
#define FSQM_CTRL_RES_DIS 0x00000000 */
/** Enable */
#define FSQM_CTRL_RES_EN 0x00000010
/** Disable Allocation Mechanism
    When selected (=1) this bit disables the allocation mechanism in the FSQM completely. Any allocation request to the FSQM will return a NIL! */
#define FSQM_CTRL_ALLOC_DIS 0x00000004
/* Not selected
#define FSQM_CTRL_ALLOC_DIS_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_ALLOC_DIS_SEL 0x00000004
/** Allocation Freeze Mechanism
    When selected (=1) this bit disables the allocation mechanism in the FSQM in case of Memory Address Violations. Any subsequent allocation request to the FSQM will return a NIL! */
#define FSQM_CTRL_ALLOC_FRZ 0x00000002
/* Not selected
#define FSQM_CTRL_ALLOC_FRZ_NSEL 0x00000000 */
/** Selected */
#define FSQM_CTRL_ALLOC_FRZ_SEL 0x00000002
/** Activate Core State Machine
    This bit enables the FSQM state machine. Allocate and Free commands cannot be executed when FSQM is disabled. */
#define FSQM_CTRL_ACT 0x00000001
/* Disable
#define FSQM_CTRL_ACT_DIS 0x00000000 */
/** Enable */
#define FSQM_CTRL_ACT_EN 0x00000001

/* Fields of "Priority Control Register" */
/** Enable/disable round-robin of priorities
    This bit enables the automatic round-robin of priorities. This bit only affects internal priorities of DMAW1, DMAW2, DMAR. */
#define FSQM_PRIO_A1X_RR 0x01000000
/* Disable
#define FSQM_PRIO_A1X_RR_DIS 0x00000000 */
/** Enable */
#define FSQM_PRIO_A1X_RR_EN 0x01000000
/** Priority number for IQM (GPE_KERNEL)
    This register holds the priority information for the Ingress Queue Manager. 0 means highest priority, 7 lowest. */
#define FSQM_PRIO_A1X_PIQM_MASK 0x00070000
/** field offset */
#define FSQM_PRIO_A1X_PIQM_OFFSET 16
/** Priority number for OCTRL (GPE_OUT)
    This register holds the priority information for the output control bus accesses. 0 means highest priority, 7 lowest. */
#define FSQM_PRIO_A1X_POCTRL_MASK 0x00007000
/** field offset */
#define FSQM_PRIO_A1X_POCTRL_OFFSET 12
/** Priority number for PCTRL (GPE_KERNEL)
    This register holds the priority information for the packet control bus accesses. 0 means highest priority, 7 lowest. */
#define FSQM_PRIO_A1X_PPCTRL_MASK 0x00000700
/** field offset */
#define FSQM_PRIO_A1X_PPCTRL_OFFSET 8
/** Priority number for ICTRL (GPE_IN)
    This register holds the priority information for the input control bus accesses. 0 means highest priority, 7 lowest. */
#define FSQM_PRIO_A1X_PICTRL_MASK 0x00000070
/** field offset */
#define FSQM_PRIO_A1X_PICTRL_OFFSET 4
/** Priority number for CPU
    This register holds the priority information for the CPU. 0 means highest priority, 7 lowest. */
#define FSQM_PRIO_A1X_PCPU_MASK 0x00000007
/** field offset */
#define FSQM_PRIO_A1X_PCPU_OFFSET 0

/* Fields of "IO-Buffer Control Register for Read (ALLOC)" */
/** Enable/disable specific IO-Buffer(s)
    This register enables the different IO-buffers. Bit 0 ... CPU, bits 1-5 ... ICTRLx, bits 6-8 ... PCTRL, 9-13 ... OCTRLx, 14 ... IQM. */
#define FSQM_IO_BUF_RD_BUF_EN_MASK 0x00007FFF
/** field offset */
#define FSQM_IO_BUF_RD_BUF_EN_OFFSET 0

/* Fields of "IO-Buffer Control Register for Write (FREE)" */
/** Enable/disable specific IO-Buffer(s)
    This register enables the different IO-buffers. Bit 0 ... CPU, bits 1-5 ... ICTRLx, bits 6-8 ... PCTRL, 9-13 ... OCTRLx, 14 ... IQM. */
#define FSQM_IO_BUF_WR_BUF_EN_MASK 0x00007FFF
/** field offset */
#define FSQM_IO_BUF_WR_BUF_EN_OFFSET 0

/* Fields of "IRN Capture Register" */
/** Alloc Command NIL Response
    Indicates all cases where an Alloc Command issued towards an enabled port returned a NIL reponse.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_ALLNIL 0x01000000
/* Nothing
#define FSQM_IRNCR_ALLNIL_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_ALLNIL_INTACK 0x01000000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_ALLNIL_INTOCC 0x01000000
/** OFSC Underflow
    Indicates that the OFSC value was one when the OFSQ Alloc command was permitted.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_OFSCUFL_A1X 0x00400000
/* Nothing
#define FSQM_IRNCR_OFSCUFL_A1X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_OFSCUFL_A1X_INTACK 0x00400000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_OFSCUFL_A1X_INTOCC 0x00400000
/** IFSC Underflow
    Indicates that the IFSC value was one when the IFSQ Alloc command was permitted.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_IFSCUFL_A1X 0x00200000
/* Nothing
#define FSQM_IRNCR_IFSCUFL_A1X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_IFSCUFL_A1X_INTACK 0x00200000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_IFSCUFL_A1X_INTOCC 0x00200000
/** Free Command Underflow on OFSQ
    Indicates that at the OFSQ a Free command with length 0 was issued.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_FRUVLO_A1X 0x00100000
/* Nothing
#define FSQM_IRNCR_FRUVLO_A1X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_FRUVLO_A1X_INTACK 0x00100000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_FRUVLO_A1X_INTOCC 0x00100000
/** Free Command Underflow on IFSQ
    Indicates that at the IFSQ a Free command with length 0 was issued.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_FRUVLI_A1X 0x00080000
/* Nothing
#define FSQM_IRNCR_FRUVLI_A1X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_FRUVLI_A1X_INTACK 0x00080000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_FRUVLI_A1X_INTOCC 0x00080000
/** Free Command Overflow on OFSQ
    Indicates that the OFSC exceeds the maximum possible value.The maximum possible value is equal to MAXLSA - MINLSA.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_FROVLO_A1X 0x00040000
#define FSQM_IRNCR_FROVLO_A2X 0x00100000
/* Nothing
#define FSQM_IRNCR_FROVLO_A1X_NULL 0x00000000
#define FSQM_IRNCR_FROVLO_A2X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_FROVLO_A1X_INTACK 0x00040000
#define FSQM_IRNCR_FROVLO_A2X_INTACK 0x00100000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_FROVLO_A1X_INTOCC 0x00040000
#define FSQM_IRNCR_FROVLO_A2X_INTOCC 0x00100000

/** Free Command Overflow on IFSQ
    Indicates that the IFSC exceeds the maximum possible value.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_FROVLI_A1X 0x00020000
/* Nothing
#define FSQM_IRNCR_FROVLI_A1X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_FROVLI_A1X_INTACK 0x00020000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_FROVLI_A1X_INTOCC 0x00020000
/** Free Command RAM Access Violation
    Indicates that a Free Command tried to free segments outside the allowed address range.The allowed address range is [MINLSA...MAXLSA].When CTRL.ALLOC_FRZ is enabled, the allocation is subsequently stopped.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_FRMEM 0x00010000
/* Nothing
#define FSQM_IRNCR_FRMEM_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_FRMEM_INTACK 0x00010000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_FRMEM_INTOCC 0x00010000
/** RAM Access Violation
    Indicates that a memory access was done either with an address or data outside the allowed address range.The allowed address range is [MINLSA...MAXLSA].The allowed data range is [MINLSA...MAXLSA] + NIL.When CTRL.ALLOC_FRZ is enabled, the allocation is subsequently stopped.This bit contributes to the FSQM_ERR interrupt. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_ACCMEM 0x00001000
/* Nothing
#define FSQM_IRNCR_ACCMEM_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_ACCMEM_INTACK 0x00001000
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_ACCMEM_INTOCC 0x00001000
/** Input Free Segment Queue Not Empty
    Indicates that the IFSQ is not empty. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_IFSQNE_A1X 0x00000100
/* Nothing
#define FSQM_IRNCR_IFSQNE_A1X_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_IFSQNE_A1X_INTACK 0x00000100
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_IFSQNE_A1X_INTOCC 0x00000100
/** Threshold 4 Underflow
    Indicates that the number of entries in the OFSQ is smaller than Free Segment Queue Threshold Register 4. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_T4U 0x00000010
/* Nothing
#define FSQM_IRNCR_T4U_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_T4U_INTACK 0x00000010
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_T4U_INTOCC 0x00000010
/** Threshold 3 Underflow
    Indicates that the number of entries in the OFSQ is smaller than Free Segment Queue Threshold Register 3. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_T3U 0x00000008
/* Nothing
#define FSQM_IRNCR_T3U_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_T3U_INTACK 0x00000008
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_T3U_INTOCC 0x00000008
/** Threshold 2 Underflow
    Indicates that the number of entries in the OFSQ is smaller than Free Segment Queue Threshold Register 2. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_T2U 0x00000004
/* Nothing
#define FSQM_IRNCR_T2U_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_T2U_INTACK 0x00000004
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_T2U_INTOCC 0x00000004
/** Threshold 1 Underflow
    Indicates that the number of entries in the OFSQ is smaller than Free Segment Queue Threshold Register 1. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_T1U 0x00000002
/* Nothing
#define FSQM_IRNCR_T1U_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_T1U_INTACK 0x00000002
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_T1U_INTOCC 0x00000002
/** Threshold 0 Underflow
    Indicates that the number of entries in the OFSQ is smaller than Free Segment Queue Threshold Register 0. This bit is edge-sensitive. This bit contributes to the indirect interrupt. */
#define FSQM_IRNCR_T0U 0x00000001
/* Nothing
#define FSQM_IRNCR_T0U_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define FSQM_IRNCR_T0U_INTACK 0x00000001
/** Read: Interrupt occurred. */
#define FSQM_IRNCR_T0U_INTOCC 0x00000001

/* Fields of "IRN Interrupt Control Register" */
/** Alloc Command NIL Response
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_ALLNIL 0x01000000
/** Free Command Overflow on OFSQ
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_FROVLO_A2X 0x00100000
/** OFSC Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_OFSCUFL_A1X 0x00400000
/** IFSC Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_IFSCUFL_A1X 0x00200000
/** Free Command Underflow on OFSQ
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_FRUVLO_A1X 0x00100000
/** Free Command Underflow on IFSQ
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_FRUVLI_A1X 0x00080000
/** Free Command Overflow on OFSQ
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_FROVLO_A1X 0x00040000
/** Free Command Overflow on IFSQ
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_FROVLI_A1X 0x00020000
/** Free Command RAM Access Violation
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_FRMEM 0x00010000
/** RAM Access Violation
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_ACCMEM 0x00001000
/** Input Free Segment Queue Not Empty
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_IFSQNE_A1X 0x00000100
/** Threshold 4 Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_T4U 0x00000010
/** Threshold 3 Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_T3U 0x00000008
/** Threshold 2 Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_T2U 0x00000004
/** Threshold 1 Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_T1U 0x00000002
/** Threshold 0 Underflow
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNICR_T0U 0x00000001

/* Fields of "IRN Interrupt Enable Register" */
/** Alloc Command NIL Response
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_ALLNIL 0x01000000
/* Disable
#define FSQM_IRNEN_ALLNIL_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_ALLNIL_EN 0x01000000
/** OFSC Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_OFSCUFL_A1X 0x00400000
/* Disable
#define FSQM_IRNEN_OFSCUFL_A1X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_OFSCUFL_A1X_EN 0x00400000
/** IFSC Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_IFSCUFL_A1X 0x00200000
/* Disable
#define FSQM_IRNEN_IFSCUFL_A1X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_IFSCUFL_A1X_EN 0x00200000
/** Free Command Underflow on OFSQ
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_FRUVLO_A1X 0x00100000
/* Disable
#define FSQM_IRNEN_FRUVLO_A1X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_FRUVLO_A1X_EN 0x00100000
/** Free Command Underflow on IFSQ
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_FRUVLI_A1X 0x00080000
/* Disable
#define FSQM_IRNEN_FRUVLI_A1X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_FRUVLI_A1X_EN 0x00080000
/** Free Command Overflow on OFSQ
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_FROVLO_A1X 0x00040000
#define FSQM_IRNEN_FROVLO_A2X 0x00100000
/* Disable
#define FSQM_IRNEN_FROVLO_A1X_DIS 0x00000000
#define FSQM_IRNEN_FROVLO_A2X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_FROVLO_A1X_EN 0x00040000
#define FSQM_IRNEN_FROVLO_A2X_EN 0x00100000
/** Free Command Overflow on IFSQ
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_FROVLI_A1X 0x00020000
/* Disable
#define FSQM_IRNEN_FROVLI_A1X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_FROVLI_A1X_EN 0x00020000
/** Free Command RAM Access Violation
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_FRMEM 0x00010000
/* Disable
#define FSQM_IRNEN_FRMEM_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_FRMEM_EN 0x00010000
/** RAM Access Violation
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_ACCMEM 0x00001000
/* Disable
#define FSQM_IRNEN_ACCMEM_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_ACCMEM_EN 0x00001000
/** Input Free Segment Queue Not Empty
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_IFSQNE_A1X 0x00000100
/* Disable
#define FSQM_IRNEN_IFSQNE_A1X_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_IFSQNE_A1X_EN 0x00000100
/** Threshold 4 Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_T4U 0x00000010
/* Disable
#define FSQM_IRNEN_T4U_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_T4U_EN 0x00000010
/** Threshold 3 Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_T3U 0x00000008
/* Disable
#define FSQM_IRNEN_T3U_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_T3U_EN 0x00000008
/** Threshold 2 Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_T2U 0x00000004
/* Disable
#define FSQM_IRNEN_T2U_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_T2U_EN 0x00000004
/** Threshold 1 Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_T1U 0x00000002
/* Disable
#define FSQM_IRNEN_T1U_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_T1U_EN 0x00000002
/** Threshold 0 Underflow
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define FSQM_IRNEN_T0U 0x00000001
/* Disable
#define FSQM_IRNEN_T0U_DIS 0x00000000 */
/** Enable */
#define FSQM_IRNEN_T0U_EN 0x00000001

/* Fields of "Input Free Segment Queue Register" */
/** Tail Logical Segment Address
    Points to the tail of the Free Segment Queue. */
#define FSQM_IFSQ_A1X_TAIL_MASK 0x7FFF0000
/** field offset */
#define FSQM_IFSQ_A1X_TAIL_OFFSET 16
/** Head Logical Segment Address
    Points to the head of the Free Segment Queue. */
#define FSQM_IFSQ_A1X_HEAD_MASK 0x00007FFF
/** field offset */
#define FSQM_IFSQ_A1X_HEAD_OFFSET 0

/* Fields of "TAIL LSA Capture Register" */
/** Logical Segment Address of captured OFSQ TAIL
    In case of a memory address violation (FRMEM, ACCMEM), this field holds the OFSQ TAIL captured at that time */
#define FSQM_TAILCAPR_TAIL_FRZ_MASK 0x00007FFF
/** field offset */
#define FSQM_TAILCAPR_TAIL_FRZ_OFFSET 0

/* Fields of "Output Free Segment Queue Register" */
/** Tail Logical Segment Address
    Points to the tail of the Free Segment Queue. */
#define FSQM_OFSQ_TAIL_MASK 0x7FFF0000
/** field offset */
#define FSQM_OFSQ_TAIL_OFFSET 16
/** Head Logical Segment Address
    Points to the head of the Free Segment Queue. */
#define FSQM_OFSQ_HEAD_MASK 0x00007FFF
/** field offset */
#define FSQM_OFSQ_HEAD_OFFSET 0

/* Fields of "Input Free Segment Counter Register" */
/** Free Segment Counter
    Holds the number of entries in the Free Segment Queue. */
#define FSQM_IFSC_A1X_FSC_MASK 0x00007FFF
/** field offset */
#define FSQM_IFSC_A1X_FSC_OFFSET 0

/* Fields of "Output Free Segment Counter Register" */
/** Free Segment Counter
    Holds the number of entries in the Free Segment Queue. */
#define FSQM_OFSC_FSC_MASK 0x00007FFF
/** field offset */
#define FSQM_OFSC_FSC_OFFSET 0

/* Fields of "Free Segment Queue Threshold Register 0" */
/** Free Segment Queue Threshold 0
    When OFSC falls below this threshold, the pause_0 signal is asserted. When OFSC falls below this threshold, the interrupt T0U is asserted. When OFSC raises above this threshold, the interrupt T0U is deasserted. */
#define FSQM_FSQT0_FSQT_MASK 0x00007FFF
/** field offset */
#define FSQM_FSQT0_FSQT_OFFSET 0

/* Fields of "Free Segment Queue Threshold Register 1" */
/** Free Segment Queue Threshold 1
    When OFSC falls below this threshold, the pause_1 signal is asserted. When OFSC falls below this threshold, the interrupt T1U is asserted. When OFSC raises above this threshold, the interrupt T1U is deasserted. */
#define FSQM_FSQT1_FSQT_MASK 0x00007FFF
/** field offset */
#define FSQM_FSQT1_FSQT_OFFSET 0

/* Fields of "Free Segment Queue Threshold Register 2" */
/** Free Segment Queue Threshold 2
    When OFSC raises above this threshold, the pause_0 signal is deasserted. When OFSC falls below this threshold, the interrupt T2U is asserted. When OFSC raises above this threshold, the interrupt T2U is deasserted. */
#define FSQM_FSQT2_FSQT_MASK 0x00007FFF
/** field offset */
#define FSQM_FSQT2_FSQT_OFFSET 0

/* Fields of "Free Segment Queue Threshold Register 3" */
/** Free Segment Queue Threshold 3
    When OFSC raises above this threshold, the pause_1 signal is deasserted. When OFSC falls below this threshold, the interrupt T3U is asserted.When OFSC raises above this threshold, the interrupt T3U is deasserted. */
#define FSQM_FSQT3_FSQT_MASK 0x00007FFF
/** field offset */
#define FSQM_FSQT3_FSQT_OFFSET 0

/* Fields of "Free Segment Queue Threshold Register 4" */
/** Free Segment Queue Threshold 4
    When OFSC falls below this threshold, the interrupt T4U is asserted. When OFSC raises above this threshold, the interrupt T4U is deasserted. */
#define FSQM_FSQT4_FSQT_MASK 0x00007FFF
/** field offset */
#define FSQM_FSQT4_FSQT_OFFSET 0

/* Fields of "Logical Segment Address Range" */
/** Maximum Logical Segment Address
    Used for range checks. Whenever a LSA returned via FREE is larger than MAXLSA an interrupt is raised */
#define FSQM_LSARNG_MAXLSA_MASK 0x7FFF0000
/** field offset */
#define FSQM_LSARNG_MAXLSA_OFFSET 16
/** Minimum Logical Segment Address
    Used for range checks. Whenever a LSA returned via FREE is smaller than MINLSA an interrupt is raised */
#define FSQM_LSARNG_MINLSA_MASK 0x00007FFF
/** field offset */
#define FSQM_LSARNG_MINLSA_OFFSET 0

/* Fields of "Requestrate Limitation Register 0" */
/** Request rate limitation for master 03
    The request from master 03 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR0_RLIM03_MASK 0x3F000000
/** field offset */
#define FSQM_RLIMR0_RLIM03_OFFSET 24
/** Request rate limitation for master 02
    The request from master 02 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR0_RLIM02_MASK 0x003F0000
/** field offset */
#define FSQM_RLIMR0_RLIM02_OFFSET 16
/** Request rate limitation for master 01
    The request from master 01 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR0_RLIM01_MASK 0x00003F00
/** field offset */
#define FSQM_RLIMR0_RLIM01_OFFSET 8
/** Request rate limitation for master 00
    The request from master 00 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR0_RLIM00_MASK 0x0000003F
/** field offset */
#define FSQM_RLIMR0_RLIM00_OFFSET 0

/* Fields of "Requestrate Limitation Register 1" */
/** Request rate limitation for master 07
    The request from master 07 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR1_RLIM07_MASK 0x3F000000
/** field offset */
#define FSQM_RLIMR1_RLIM07_OFFSET 24
/** Request rate limitation for master 06
    The request from master 06 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR1_RLIM06_MASK 0x003F0000
/** field offset */
#define FSQM_RLIMR1_RLIM06_OFFSET 16
/** Request rate limitation for master 05
    The request from master 05 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR1_RLIM05_MASK 0x00003F00
/** field offset */
#define FSQM_RLIMR1_RLIM05_OFFSET 8
/** Request rate limitation for master 04
    The request from master 04 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR1_RLIM04_MASK 0x0000003F
/** field offset */
#define FSQM_RLIMR1_RLIM04_OFFSET 0

/* Fields of "Requestrate Limitation Register 2" */
/** Request rate limitation for master 11
    The request from master 11 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR2_RLIM11_MASK 0x3F000000
/** field offset */
#define FSQM_RLIMR2_RLIM11_OFFSET 24
/** Request rate limitation for master 10
    The request from master 10 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR2_RLIM10_MASK 0x003F0000
/** field offset */
#define FSQM_RLIMR2_RLIM10_OFFSET 16
/** Request rate limitation for master 09
    The request from master 09 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR2_RLIM09_MASK 0x00003F00
/** field offset */
#define FSQM_RLIMR2_RLIM09_OFFSET 8
/** Request rate limitation for master 08
    The request from master 08 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR2_RLIM08_MASK 0x0000003F
/** field offset */
#define FSQM_RLIMR2_RLIM08_OFFSET 0

/* Fields of "Requestrate Limitation Register 3" */
/** Request rate limitation for master 14
    The request from master 14 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR3_RLIM14_MASK 0x003F0000
/** field offset */
#define FSQM_RLIMR3_RLIM14_OFFSET 16
/** Request rate limitation for master 13
    The request from master 13 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR3_RLIM13_MASK 0x00003F00
/** field offset */
#define FSQM_RLIMR3_RLIM13_OFFSET 8
/** Request rate limitation for master 12
    The request from master 12 is delayed by the number of clocks specified in this field */
#define FSQM_RLIMR3_RLIM12_MASK 0x0000003F
/** field offset */
#define FSQM_RLIMR3_RLIM12_OFFSET 0

/* Fields of "Input Message Queue Register" */
/** Tail Logical Segment Address
    Points to the tail of the Free Segment List to be enqueued into the IFSQ. */
#define FSQM_IMQ_A1X_TLSA_MASK 0x7FFF0000
/** field offset */
#define FSQM_IMQ_A1X_TLSA_OFFSET 16
/** Head Logical Segment Address
    Points to the head of the Free Segment List to be enqueued into the IFSQ. */
#define FSQM_IMQ_A1X_HLSA_MASK 0x00007FFF
/** field offset */
#define FSQM_IMQ_A1X_HLSA_OFFSET 0

/* Fields of "Output Message Queue Register" */
/** Tail Logical Segment Address
    Points to the tail of the Free Segment List to be enqueued into the OFSQ. */
#define FSQM_OMQ_TLSA_MASK 0x7FFF0000
/** field offset */
#define FSQM_OMQ_TLSA_OFFSET 16
/** Head Logical Segment Address
    Points to the head of the Free Segment List to be enqueued into the OFSQ. */
#define FSQM_OMQ_HLSA_MASK 0x00007FFF
/** field offset */
#define FSQM_OMQ_HLSA_OFFSET 0

/* Fields of "Repeat Counter Addresses" */
/** Repeat Counter Value
    Contains the Repeat Counter for the corresponding LSA. */
#define FSQM_RCNT_RCNT_MASK 0x00000007
/** field offset */
#define FSQM_RCNT_RCNT_OFFSET 0

/* Fields of "Repeat Counter Inc/Dec Addresses" */
/** Repeat Counter Value
    Contains the Repeat Counter for the corresponding LSA. */
#define FSQM_RCNT_INCDEC_RCNT_OLD_MASK 0x00000007
/** field offset */
#define FSQM_RCNT_INCDEC_RCNT_OLD_OFFSET 0

/* Fields of "LLT RAM Addresses" */
/** Pointer to the next segment
    Contains the memory pointer to the next LSA. */
#define FSQM_RAM_SNEXT_MASK 0x00007FFF
/** field offset */
#define FSQM_RAM_SNEXT_OFFSET 0

/*! @} */ /* FSQM_REGISTER */

#endif /* _fsqm_reg_h */
