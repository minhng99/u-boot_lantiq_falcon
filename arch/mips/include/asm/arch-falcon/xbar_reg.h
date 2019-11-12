/******************************************************************************

                               Copyright (c) 2012
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _xbar_reg_h
#define _xbar_reg_h

/** \addtogroup XBAR_REGISTER
   @{
*/
/* access macros */
#define xbar_r32(reg) reg_r32(&xbar->reg)
#define xbar_w32(val, reg) reg_w32(val, &xbar->reg)
#define xbar_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &xbar->reg)
#define xbar_r32_table(reg, idx) reg_r32_table(xbar->reg, idx)
#define xbar_w32_table(val, reg, idx) reg_w32_table(val, xbar->reg, idx)
#define xbar_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, xbar->reg, idx)
#define xbar_adr_table(reg, idx) adr_table(xbar->reg, idx)


/** XBAR register structure */
struct gpon_reg_xbar
{
   /** CPU Subsystem Identification Registert
       t.b.d. */
   unsigned int css_id; /* 0x00000000 */
   /** Reserved */
   unsigned int res_0[7]; /* 0x00000004 */
   /** CPU Subsystem Transaction Initiator cpu Address Range Check Register
       The permission to perform read and write operations from cpu to the different targets may be configured using this register. Operations, which are configured not to be allowed will be error-terminated at the input of the crossbar already. Disabling write permissions may be convenient to debug problems, where multiple ports interfere eachother's transactions by writing to the same destination. Caveat: DO NOT CHANGE THE PERMISSIONS FOR A PORT WHILE TRAFFIC IS GOING ON ON THAT PORT! */
   unsigned int css_ti_cpu_chk; /* 0x00000020 */
   /** Reserved */
   unsigned int res_1[7]; /* 0x00000024 */
   /** CPU Subsystem Transaction Target Security Register
       The css_tt_sec register specifies the significant bits of the address range associated with the free-programmable address range. */
   unsigned int css_tt_sec; /* 0x00000040 */
   /** Reserved */
   unsigned int res_2[57]; /* 0x00000044 */
   /** CPU Subsystem Transaction Target fmi0 FPI Bus Master Control Registerm
       Register css_tt_fmi0_cr controls the functionality of the FPI-Bus master interface and the associated Downsizer. */
   unsigned int css_tt_fmi0_cr; /* 0x00000128 */
   /** Reserved */
   unsigned int res_3[53]; /* 0x0000012C */
   /** CPU Subsystem Interrupt Node Enable Register
       The interrupt node enable register CSS_IRNEN is used to enable/disable the propagation of individual interrupt signals from the Interrupt Node of the CPU Subsystem (CSS IRN) to the ICU. */
   unsigned int css_irn_en; /* 0x00000200 */
   /** Reserved */
   unsigned int res_4; /* 0x00000204 */
   /** CPU Subsystem Interrupt Node Control Register
       The interrupt node control register CSS_IRNCR is used to read the masked value of the interrupt capture register CSS_IRNICR in the CSS interrupt node and to clear interrupts, after they have been processed by the CPU. */
   unsigned int css_irn_cr; /* 0x00000208 */
   /** Reserved */
   unsigned int res_5; /* 0x0000020C */
   /** CPU Subsystem Interrupt Node Interrupt Capture Register
       The interrupt node interrupt capture register css_irn_icr is used to directly read/modify the captured interrupts inthe interrupt node of the CSS. Reading returns the unmasked value of the interrupts, that have been signalled by the CSS. Writing overwrites all values in the interrupt capture register, regardless whether the CSS has signalled interrupts or not. This can be used either to fake interrupts for test purposes or to kill interrupts, that are not interesting any more. For each css_irn_icr bit, hardware changes take precedence over software changes. If software tries to clear an interrupt bit by writing to css_irn_icr but at the same time the hardware signals a new interrupt condition, the interrupt bit will be set afterwards. */
   unsigned int css_irn_icr; /* 0x00000210 */
   /** Reserved */
   unsigned int res_6[123]; /* 0x00000214 */
   /** DDR SDRAM Controller Global Status Register 0
       Register ddr_gsr0 holds general status information of the DDR SDRAM Controller. Note: The functionality of thisregister and status bits is not verified. */
   unsigned int ddr_gsr0; /* 0x00000400 */
   /** Reserved */
   unsigned int res_7; /* 0x00000404 */
   /** DDR SDRAM Controller Global Control Register 0
       Register ddr_gcr1 controls the manually self refresh entry. Note: The functionality of this register and control bits is not verified. */
   unsigned int ddr_gcr0; /* 0x00000408 */
   /** Reserved */
   unsigned int res_8; /* 0x0000040C */
   /** DDR SDRAM Controller Global Control Register 1
       Register ddr_gcr1 controls the driver strength of the SSTL_2 pads */
   unsigned int ddr_gcr1; /* 0x00000410 */
   /** Reserved */
   unsigned int res_9; /* 0x00000414 */
   /** DDR SDRAM Controller Transaction Initiator Priority Register
       Register ddr_prio_ti controls the priority of the transaction initiators. */
   unsigned int ddr_prio_ti; /* 0x00000418 */
   /** Reserved */
   unsigned int res_10; /* 0x0000041C */
   /** DDR SDRAM Controller Echo Gate DLL Control Register 0
       Register ddr_echo_dll0 controls the additional delay inserted by the DLL. */
   unsigned int ddr_echo_dll0; /* 0x00000420 */
   /** Reserved */
   unsigned int res_11; /* 0x00000424 */
   /** DDR SDRAM Controller Echo Gate DLL Control Register 1
       Register ddr_echo_dll1 controls the additional delay inserted by the DLL. */
   unsigned int ddr_echo_dll1; /* 0x00000428 */
   /** Reserved */
   unsigned int res_12[5]; /* 0x0000042C */
   /** Select Control Register 0
       Register pmon_pcesscr0 selects event and source to be forwarded to the CPU internal performance counter 0 */
   unsigned int pmon_pcesscr0; /* 0x00000440 */
   /** Select Control Register 1
       Register pmon_pcesscr1 selects event and source to be forwarded to the CPU internal performance counter 1 */
   unsigned int pmon_pcesscr1; /* 0x00000444 */
   /** Select Control Register 2
       Register pmon_pcesscr2 selects event and source to be forwarded to the CPU internal performance counter 2 */
   unsigned int pmon_pcesscr2; /* 0x00000448 */
   /** Select Control Register 3
       Register pmon_pcesscr3 selects event and source to be forwarded to the CPU internal performance counter 3 */
   unsigned int pmon_pcesscr3; /* 0x0000044C */
   /** Select Control Register 4
       Register pmon_pcesscr4 selects event and source to be forwarded to the CPU internal performance counter 4 */
   unsigned int pmon_pcesscr4; /* 0x00000450 */
   /** Select Control Register 5
       Register pmon_pcesscr5 selects event and source to be forwarded to the CPU internal performance counter 5 */
   unsigned int pmon_pcesscr5; /* 0x00000454 */
   /** Select Control Register 6
       Register pmon_pcesscr6 selects event and source to be forwarded to the CPU internal performance counter 6 */
   unsigned int pmon_pcesscr6; /* 0x00000458 */
   /** Select Control Register 7
       Register pmon_pcesscr7 selects event and source to be forwarded to the CPU internal performance counter 7 */
   unsigned int pmon_pcesscr7; /* 0x0000045C */
   /** Reserved */
   unsigned int res_13[744]; /* 0x00000460 */
};


/* Fields of "CPU Subsystem Identification Registert" */
/** Field Layout
    version number of the layout database */
#define XBAR_CSS_ID_LAYOUT_MASK 0xFFFF0000
/** field offset */
#define XBAR_CSS_ID_LAYOUT_OFFSET 16
/** Field rtl
    version number of the RTL code */
#define XBAR_CSS_ID_RTL_MASK 0x0000FFFF
/** field offset */
#define XBAR_CSS_ID_RTL_OFFSET 0

/* Fields of "CPU Subsystem Transaction Initiator cpu Address Range Check Register" */
/** Field tt_sec_write_en
    enable write permission for crossbar input cpu to secure address range */
#define XBAR_CSS_TI_CPU_CHK_TT_SEC_WRITE_EN 0x00200000
/** Field tt_smi2_write_en
    enable write permission for crossbar input cpu to SRAM bus SMI2 */
#define XBAR_CSS_TI_CPU_CHK_TT_SMI2_WRITE_EN 0x00100000
/** Field tt_smi0_write_en
    enable write permission for crossbar input cpu to SRAM bus SMI0 */
#define XBAR_CSS_TI_CPU_CHK_TT_SMI0_WRITE_EN 0x00080000
/** Field tt_fmi0_write_en
    enable write permission for crossbar input cpu to FPI bus FMI0 */
#define XBAR_CSS_TI_CPU_CHK_TT_FMI0_WRITE_EN 0x00040000
/** Field tt_ddr_write_end
    enable write permission for crossbar input cpu to DDR SDRAM controller */
#define XBAR_CSS_TI_CPU_CHK_TT_DDR_WRITE_EN 0x00020000
/** Field tt_ebu_write_en
    enable write permission for crossbar input cpu to EBU */
#define XBAR_CSS_TI_CPU_CHK_TT_EBU_WRITE_EN 0x00010000
/** Field tt_sec_read_en
    enable read permission for crossbar input cpu to secure address range */
#define XBAR_CSS_TI_CPU_CHK_TT_SEC_READ_EN 0x00000020
/** Field tt_smi2_read_en
    enable read permission for crossbar input cpu to SRAM bus SMI2 */
#define XBAR_CSS_TI_CPU_CHK_TT_SMI2_READ_EN 0x00000010
/** Field tt_smi0_read_en
    enable read permission for crossbar input cpu to SRAM bus SMI0 */
#define XBAR_CSS_TI_CPU_CHK_TT_SMI0_READ_EN 0x00000008
/** Field tt_fmi0_read_en
    enable read permission for crossbar input cpu to FPI bus FMI0 */
#define XBAR_CSS_TI_CPU_CHK_TT_FMI0_READ_EN 0x00000004
/** Field tt_ddr_read_en
    enable read permission for crossbar input cpu to DDR SDRAM controller */
#define XBAR_CSS_TI_CPU_CHK_TT_DDR_READ_EN 0x00000002
/** Field tt_ebu_read_en
    enable read permission for crossbar input cpu to EBU */
#define XBAR_CSS_TI_CPU_CHK_TT_EBU_READ_EN 0x00000001

/* Fields of "CPU Subsystem Transaction Target Security Register" */
/** Field base
    Base Address of Security Address Range: Specifies the base address of the address range associated with the free programmable address range. */
#define XBAR_CSS_TT_SEC_BASE_MASK 0xFFF00000
/** field offset */
#define XBAR_CSS_TT_SEC_BASE_OFFSET 20
/** Field cmp
    Significant Bits of a Memory Address Range: Specifies these address bits which are used in the address comparison: 0xF00 256MByte The freeprogrammable address range is 256 MByte, 0xF80 128MByte The freeprogrammableaddress range is 128 MByte, 0xFC0 64MByte The freeprogrammableaddress range is 64 MByte, 0xFE0 32MByte The freeprogrammableaddress range is 32 MByte, 0xFF0 16MByte The freeprogrammableaddress range is 16 MByte, 0xFF8 8MByte The freeprogrammableaddress range is 8 MByte, 0xFFC 4MByte The freeprogrammableaddress range is 4 MByte */
#define XBAR_CSS_TT_SEC_CMP_MASK 0x0000FFF0
/** field offset */
#define XBAR_CSS_TT_SEC_CMP_OFFSET 4
/** Field inverse
    Invert secure range (encoding 0 = protect addresses within secure range, 1 = protect addresses outside of secure range). */
#define XBAR_CSS_TT_SEC_INVERSE 0x00000001

/* Fields of "CPU Subsystem Transaction Target fmi0 FPI Bus Master Control Registerm" */
/** Field burst2single
    Burst to Single: 1 B2S1 All MemPort transactions are performed as a sequence of single data transfers on the FPI bus. This allows to restrict the FPI commands to a minimum subset, which can be expected to be acceptable by all kinds of slaves. */
#define XBAR_CSS_TT_FMI0_CR_BURST2SINGLE 0x00000001

/* Fields of "CPU Subsystem Interrupt Node Enable Register" */
/** Field unused
    Unused Asynchronous Interrupt Enable Bit */
#define XBAR_CSS_IRN_EN_UNUSED 0x00000004
/** Field ti_cpu_cerr
    Transaction Initiator cpu Conflict Interrupt Request Enable. 0 DIS the propagation of the interrupt request is disabled, 1 EN the propagation of the interrupt request is enablede */
#define XBAR_CSS_IRN_EN_TI_CPU_CERR 0x00000002
/* Disable
#define XBAR_CSS_IRN_EN_TI_CPU_CERR_DIS 0x00000000 */
/** Enable */
#define XBAR_CSS_IRN_EN_TI_CPU_CERR_EN 0x00000002
/** Field ti_cpu_werr
    Transaction Initiator cpu Write Error Interrupt Request Enable. 0 DIS the propagation of the interrupt request is disabled, 1 EN the propagation of the interrupt request is enabled */
#define XBAR_CSS_IRN_EN_TI_CPU_WERR 0x00000001
/* Disable
#define XBAR_CSS_IRN_EN_TI_CPU_WERR_DIS 0x00000000 */
/** Enable */
#define XBAR_CSS_IRN_EN_TI_CPU_WERR_EN 0x00000001

/* Fields of "CPU Subsystem Interrupt Node Control Register" */
/** Field unused
    Unused Asynchronous Interrupt Control Bit */
#define XBAR_CSS_IRN_CR_UNUSED 0x00000004
/** Field ti_cpu_cerr
    Transaction Initiator cpu Conflict Interrupt Request. Writing 1 clears the interrupt request in css_irn_icr.ti_cpu_cerr. Writing 0 has no effect. Reading returns the logical AND of css_irn_icr.ti_cpu_cerr and css_irn_en.ti_cpu_cerr. */
#define XBAR_CSS_IRN_CR_TI_CPU_CERR_1 0x00000002
/** Field ti_cpu_werr
    Transaction Initiator cpu Write Error Interrupt Request. Writing 1 clears the interrupt request in css_irn_icr.ti_cpu_werr. Writing 0 has no effect. Reading returns the logical AND of css_irn_icr.ti_cpu_werr and css_irn_en.ti_cpu_werr */
#define XBAR_CSS_IRN_CR_TI_CPU_WERR_1 0x00000001

/* Fields of "CPU Subsystem Interrupt Node Interrupt Capture Register" */
/** Field unused
    Unused Asynchronous Interrupt Capture Bit */
#define XBAR_CSS_IRN_ICR_UNUSED 0x00000004
/** Field ti_cpu_cerr
    Transaction Initiator cpu Conflict Interrupt Request. If ti_cpu_cerr is set, a interrupt request is signalled depending on the css_irn_en.ti_cpu_cerr bit. If ti_cpu_cerr is cleared, a interrupt request is killed. Reading shows, whether a interrupt request has been captured by the interrupt node (even if the interrupt is not forwarded to the CPU, because it is disabled in css_irn_en register). */
#define XBAR_CSS_IRN_ICR_TI_CPU_CERR_2 0x00000002
/** Field ti_cpu_werr
    Transaction Initiator cpu Write Error Interrupt Request. If ti_cpu_werr is set, a interrupt request is signalled depending on the css_irn_en.ti_cpu_werr bit. If ti_cpu_werr is cleared, a interrupt request is killed. Reading shows, whether a interrupt request has been captured by the interrupt node (even if the interrupt is not forwarded to the CPU, because it is disabled in css_irn_en register). */
#define XBAR_CSS_IRN_ICR_TI_CPU_WERR_2 0x00000001

/* Fields of "DDR SDRAM Controller Global Status Register 0" */
/** Command Queue Full Status
    Indicates that the command queue is full. While this bit is high, the command queue will not capture any command requests. */
#define XBAR_DDR_GSR0_CQF 0x00000020
/** Queue Almost Full Status
    Indicates that the queue has reached the value set in the q_fullness parameter. 1 QAF_1 Queue almost full */
#define XBAR_DDR_GSR0_QAF 0x00000010
/** Controller Busy Status
    Status signal from the DDR SDRAM controller. This will only be low when the DDR SDRAM controller is neither reading data, writing data nor processing a command. 1 cbusy_1 DDR SDRAM controller is bus */
#define XBAR_DDR_GSR0_CBUSY 0x00000008
/** Refresh in Process Status
    Active-high signal that indicates that the memory controller is executing a refresh command. This signal is asserted when a refresh command is sent to the DRAM devices and remains asserted until the refresh command has completed. 1 rip_1 Refresh in process for the DDR SDRAM device(s) */
#define XBAR_DDR_GSR0_RIP 0x00000004
/** cke Signal Status
    Status bit cke reflects level of the cke_status signal, which indicates if the DDR SDRAM device(s) are in either in self-refresh or power-down mode. This signal is the status of the control_cke signal inside the DDR SDRAM controller, but may be delayed via the bit field CKE_DELAY to reflect the cke status on the DDR SDRAM interface. 1 cke_1 e */
#define XBAR_DDR_GSR0_CKE 0x00000002
/** Self-Refresh Acknolwdge
    Status bit sra reflects the level of the acknowledge signal srefresh_ack, which indicates if the DDR SDRAM device(s) are in self-refresh mode. This signal will only be asserted if the DDR SDRAM device(s) have been placed into self-refresh mode through the assertion of the request bit SRR and the assoicated srefresh_enter signal and if this signal is still held high until the DDR SDRAM device(s) enters selfrefresh mode. 1 sra_1 DDR SDRAM device(s) are in self-refresh modeh */
#define XBAR_DDR_GSR0_SRA 0x00000001

/* Fields of "DDR SDRAM Controller Global Control Register 0" */
/** Self-Refresh Request
    Writing 1 to SRR activates signal srefsh_enter, which initiates a selfrefresh to the DDR SDRAM devices(s) and updates bit SREFRESH. Request bit SRR and signal srefsh_enter is driven active-high, until the DDR SDRAM controller acknowledges via signal srefresh_ack that the DDR SDRAM devices(s) have entered self-refresh mode. 0 SRR_0 No action, 1 SRR_1 Request the DDR SDRAM devices(s) to enter selfrefresh mode */
#define XBAR_DDR_GCR0_SRR 0x00000001

/* Fields of "DDR SDRAM Controller Global Control Register 1" */
/** Field ck
    SSTL_2 Class I or Class II Output Driver Strength per CK/CKn. Controls the driving strength of the SSTL_2 output driver associated with the clock signals CK/CKn: 0 CLASS_I SSTL_2 class I output driver strength for CK/CKn, 1 CLASS_II SSTL_2 class II output driver strength for CK/CK */
#define XBAR_DDR_GCR1_CK 0x00000020
/** Field ca
    SSTL_2 Class I or Class II Output Driver Strength per CA. Controls the driving strength of the SSTL_2 output driver associated with the command and address bus. There is one control bit for the CA block: 0 CLASS_I SSTL_2 class I output driver strength for CA, 1 CLASS_II SSTL_2 class II output driver strength for CA */
#define XBAR_DDR_GCR1_CA 0x00000010
/** Field3
    SSTL_2 Class I or Class II Output Driver Strength per Data Slice #3Controls the driving strength of the SSTL_2 output driver associated with Data Slice #3. 0 CLASS_I SSTL_2 class I output driver strength for DQ[31:24], 1 CLASS_II SSTL_2 class II output driver strength for DQ[31:24] */
#define XBAR_DDR_GCR1_DS3 0x00000008
/** Field2
    SSTL_2 Class I or Class II Output Driver Strength per Data Slice #2Controls the driving strength of the SSTL_2 output driver associated with Data Slice #2. 0 CLASS_I SSTL_2 class I output driver strength for DQ[23:16], 1 CLASS_II SSTL_2 class II output driver strength for DQ[23:16] */
#define XBAR_DDR_GCR1_DS2 0x00000004
/** Field1
    SSTL_2 Class I or Class II Output Driver Strength per Data Slice #1Controls the driving strength of the SSTL_2 output driver associated with Data Slice #1. 0 CLASS_I SSTL_2 class I output driver strength for DQ[15:8], 1 CLASS_II SSTL_2 class II output driver strength for DQ[15:8] */
#define XBAR_DDR_GCR1_DS1 0x00000002
/** Field0
    SSTL_2 Class I or Class II Output Driver Strength per Data Slice #0Controls the driving strength of the SSTL_2 output driver associated with Data Slice #0. 0 CLASS_I SSTL_2 class I output driver strength for DQ[7:0], 1 CLASS_II SSTL_2 class II output driver strength for DQ[7:0] */
#define XBAR_DDR_GCR1_DS0 0x00000001

/* Fields of "DDR SDRAM Controller Transaction Initiator Priority Register" */
/** Field disable_dmc2pad_rx_enable
    disable dynamic receiver enable */
#define XBAR_DDR_PRIO_TI_DISABLE_DMC2PAD_RX_ENABLE 0x00010000
/** Field dr_prio_ti_cpu
    ddr controller priority for transactions from initiator cpu */
#define XBAR_DDR_PRIO_TI_DR_PRIO_TI_CPU_MASK 0x00000030
/** field offset */
#define XBAR_DDR_PRIO_TI_DR_PRIO_TI_CPU_OFFSET 4

/* Fields of "DDR SDRAM Controller Echo Gate DLL Control Register 0" */
/** Field echo_dll0
    ddr controller DLL sel value */
#define XBAR_DDR_ECHO_DLL0_ECHO_DLL0_MASK 0x000000FF
/** field offset */
#define XBAR_DDR_ECHO_DLL0_ECHO_DLL0_OFFSET 0

/* Fields of "DDR SDRAM Controller Echo Gate DLL Control Register 1" */
/** Field echo_dll1
    ddr controller DLL sel value */
#define XBAR_DDR_ECHO_DLL1_ECHO_DLL1_MASK 0x000000FF
/** field offset */
#define XBAR_DDR_ECHO_DLL1_ECHO_DLL1_OFFSET 0

/* Fields of "Select Control Register 0" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 0 */
#define XBAR_PMON_PCESSCR0_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR0_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 0 */
#define XBAR_PMON_PCESSCR0_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR0_EVENT_OFFSET 0

/* Fields of "Select Control Register 1" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 1 */
#define XBAR_PMON_PCESSCR1_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR1_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 1 */
#define XBAR_PMON_PCESSCR1_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR1_EVENT_OFFSET 0

/* Fields of "Select Control Register 2" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 2 */
#define XBAR_PMON_PCESSCR2_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR2_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 2 */
#define XBAR_PMON_PCESSCR2_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR2_EVENT_OFFSET 0

/* Fields of "Select Control Register 3" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 3 */
#define XBAR_PMON_PCESSCR3_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR3_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 3 */
#define XBAR_PMON_PCESSCR3_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR3_EVENT_OFFSET 0

/* Fields of "Select Control Register 4" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 4 */
#define XBAR_PMON_PCESSCR4_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR4_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 4 */
#define XBAR_PMON_PCESSCR4_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR4_EVENT_OFFSET 0

/* Fields of "Select Control Register 5" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 5 */
#define XBAR_PMON_PCESSCR5_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR5_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 5 */
#define XBAR_PMON_PCESSCR5_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR5_EVENT_OFFSET 0

/* Fields of "Select Control Register 6" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 6 */
#define XBAR_PMON_PCESSCR6_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR6_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 6 */
#define XBAR_PMON_PCESSCR6_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR6_EVENT_OFFSET 0

/* Fields of "Select Control Register 7" */
/** Field source
    This bit field selects one source to be forwarded to the CPU internal performance counter 7 */
#define XBAR_PMON_PCESSCR7_SOURCE_MASK 0x0000007C
/** field offset */
#define XBAR_PMON_PCESSCR7_SOURCE_OFFSET 2
/** Field event
    This bit field selects one event to be forwarded to the CPU internal performance counter 7 */
#define XBAR_PMON_PCESSCR7_EVENT_MASK 0x00000003
/** field offset */
#define XBAR_PMON_PCESSCR7_EVENT_OFFSET 0

/*! @} */ /* XBAR_REGISTER */

#endif /* _xbar_reg_h */
