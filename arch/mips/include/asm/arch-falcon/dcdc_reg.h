/******************************************************************************

                               Copyright (c) 2012
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _dcdc_reg_h
#define _dcdc_reg_h

/** \addtogroup DCDC_REGISTER
   @{
*/
/* access macros */
#define dcdc_core_r8(reg) (reg_r32(&dcdc_core->reg) & 0xFF)
#define dcdc_core_w8(val, reg) reg_w32((val) & 0xFF, &dcdc_core->reg)
#define dcdc_core_w8_mask(clear, set, reg) reg_w32_mask((clear) & 0xFF, (set) & 0xFF, &dcdc_core->reg)
#define dcdc_core_r8_table(reg, idx) (reg_r32_table(dcdc_core->reg, idx) & 0xFF)
#define dcdc_core_w8_table(val, reg, idx) reg_w32_table((val) & 0xFF, dcdc_core->reg, idx)
#define dcdc_core_w8_table_mask(clear, set, reg, idx) reg_w32_table_mask((clear) & 0xFF, (set) & 0xFF, dcdc_core->reg, idx)
#define dcdc_core_adr_table(reg, idx) adr_table(dcdc_core->reg, idx)

#define dcdc_ddr_r8(reg) (reg_r32(&dcdc_ddr->reg) & 0xFF)
#define dcdc_ddr_w8(val, reg) reg_w32((val) & 0xFF, &dcdc_ddr->reg)
#define dcdc_ddr_w8_mask(clear, set, reg) reg_w32_mask((clear) & 0xFF, (set) & 0xFF, &dcdc_ddr->reg)
#define dcdc_ddr_r8_table(reg, idx) (reg_r32_table(dcdc_ddr->reg, idx) & 0xFF)
#define dcdc_ddr_w8_table(val, reg, idx) reg_w32_table((val) & 0xFF, dcdc_ddr->reg, idx)
#define dcdc_ddr_w8_table_mask(clear, set, reg, idx) reg_w32_table_mask((clear) & 0xFF, (set) & 0xFF, dcdc_ddr->reg, idx)
#define dcdc_ddr_adr_table(reg, idx) adr_table(dcdc_ddr->reg, idx)

#define dcdc_apd_r8(reg) (reg_r32(&dcdc_apd->reg) & 0xFF)
#define dcdc_apd_w8(val, reg) reg_w32((val) & 0xFF, &dcdc_apd->reg)
#define dcdc_apd_w8_mask(clear, set, reg) reg_w32_mask((clear) & 0xFF, (set) & 0xFF, &dcdc_apd->reg)
#define dcdc_apd_r8_table(reg, idx) (reg_r32_table(dcdc_apd->reg, idx) & 0xFF)
#define dcdc_apd_w8_table(val, reg, idx) reg_w32_table((val) & 0xFF, dcdc_apd->reg, idx)
#define dcdc_apd_w8_table_mask(clear, set, reg, idx) reg_w32_table_mask((clear) & 0xFF, (set) & 0xFF, dcdc_apd->reg, idx)
#define dcdc_apd_adr_table(reg, idx) adr_table(dcdc_apd->reg, idx)


/** DCDC register structure */
struct gpon_reg_dcdc
{
   /** DCDC_PDI: DCDC Submodule Register File */
   /** Hi Byte of coefficient b0 */
   unsigned int pdi_pid_hi_b0; /* 0x00000000 */
   /** Lo Byte of coefficient b0 */
   unsigned int pdi_pid_lo_b0; /* 0x00000004 */
   /** Hi Byte of coefficient b1 */
   unsigned int pdi_pid_hi_b1; /* 0x00000008 */
   /** Lo Byte of coefficient b1 */
   unsigned int pdi_pid_lo_b1; /* 0x0000000C */
   /** Hi Byte of coefficient b2 */
   unsigned int pdi_pid_hi_b2; /* 0x00000010 */
   /** Lo Byte of coefficient b2 */
   unsigned int pdi_pid_lo_b2; /* 0x00000014 */
   /** Set up clocks */
   unsigned int pdi_clk_set0; /* 0x00000018 */
   /** Set up clocks */
   unsigned int pdi_clk_set1; /* 0x0000001C */
   /** PWM Settings 0 */
   unsigned int pdi_pwm0; /* 0x00000020 */
   /** PWM Settings 1 */
   unsigned int pdi_pwm1; /* 0x00000024 */
   /** Set up BIAS and voltage regulator */
   unsigned int pdi_bias_vreg; /* 0x00000028 */
   /** Sets digital reference of DCDC converter */
   unsigned int pdi_dig_ref; /* 0x0000002C */
   /** General settings */
   unsigned int pdi_general; /* 0x00000030 */
   /** ADC conf0 */
   unsigned int pdi_adc0; /* 0x00000034 */
   /** ADC conf1 */
   unsigned int pdi_adc1; /* 0x00000038 */
   /** ADC conf2 */
   unsigned int pdi_adc2; /* 0x0000003C */
   /** Analog Test Configuration for Autostart Mode */
   unsigned int pdi_conf_test_ana; /* 0x00000040 */
   /** Digital Test Configuration for Autostart Mode */
   unsigned int pdi_conf_test_dig; /* 0x00000044 */
   /** Analog Test Configuration for Non-Autostart Mode */
   unsigned int pdi_conf_test_ana_noauto; /* 0x00000048 */
   /** Digital Test Configuration for Non-Autostart Mode */
   unsigned int pdi_conf_test_dig_noauto; /* 0x0000004C */
   /** DCDC_STATUS */
   unsigned int pdi_dcdc_status; /* 0x00000050 */
   /** PID_STATUS */
   unsigned int pdi_pid_status; /* 0x00000054 */
   /** DUTY_CYCLE */
   unsigned int pdi_duty_cycle; /* 0x00000058 */
   /** NON_OV_DELAY */
   unsigned int pdi_non_ov_delay; /* 0x0000005C */
   /** ANALOG_GAIN */
   unsigned int pdi_analog_gain; /* 0x00000060 */
   /** DUTY_CYCLE_MAX_SAT */
   unsigned int pdi_duty_cycle_max_sat; /* 0x00000064 */
   /** DUTY_CYCLE_MIN_SAT */
   unsigned int pdi_duty_cycle_min_sat; /* 0x00000068 */
   /** DUTY_CYCLE_MAX */
   unsigned int pdi_duty_cycle_max; /* 0x0000006C */
   /** DUTY_CYCLE_MIN */
   unsigned int pdi_duty_cycle_min; /* 0x00000070 */
   /** ERROR_MAX */
   unsigned int pdi_error_max; /* 0x00000074 */
   /** ERROR_READ */
   unsigned int pdi_error_read; /* 0x00000078 */
   /** DELAY_DEGLITCH */
   unsigned int pdi_delay_deglitch; /* 0x0000007C */
   /** LATCH_CONTROL */
   unsigned int pdi_latch_control; /* 0x00000080 */
   /** LATCH_CONTROL_NOAUTO */
   unsigned int pdi_latch_control_noauto; /* 0x00000084 */
   /** CAP_CLK_CNT */
   unsigned int pdi_cap_clk_cnt; /* 0x00000088 */
   /** MDLL_DIVIDER */
   unsigned int pdi_mdll_divider; /* 0x0000008C */
   /** Reserved */
   unsigned int pdi_res_0[220]; /* 0x00000090 */
   /** OSC_PDI: OSC Submodule Register File */
   /** OSC Configuration Register */
   unsigned int osc_pdi_osc_conf; /* 0x00000400 */
   /** OSC_STATUS */
   unsigned int osc_pdi_osc_status; /* 0x00000404 */
   /** Reserved */
   unsigned int osc_pdi_res_1; /* 0x00000408 */
};


/* Fields of "Hi Byte of coefficient b0" */
/** Hi Byte of coefficient b0 */
#define DCDC_PID_HI_B0_B_MASK 0xFF
/** field offset */
#define DCDC_PID_HI_B0_B_OFFSET 0
/** Kp = 1/Ks */
#define DCDC_PID_HI_B0_B_KP_1 0x02
/** Kp = 3/Ks */
#define DCDC_PID_HI_B0_B_KP_3 0x08
/** Kp = 5/Ks */
#define DCDC_PID_HI_B0_B_KP_5 0x0E
/** Kp = 7.5/Ks */
#define DCDC_PID_HI_B0_B_KP_7P5 0x15
/** Kp = 10/Ks */
#define DCDC_PID_HI_B0_B_KP_10 0x1C
/** Kp = 12.5/Ks */
#define DCDC_PID_HI_B0_B_KP_12P5 0x23
/** Kp = 15/Ks */
#define DCDC_PID_HI_B0_B_KP_15 0x2A
/** Kp = 17.5/Ks */
#define DCDC_PID_HI_B0_B_KP_17P5 0x31

/* Fields of "Lo Byte of coefficient b0" */
/** Lo Byte of coefficient b0 */
#define DCDC_PID_LO_B0_B_MASK 0xFF
/** field offset */
#define DCDC_PID_LO_B0_B_OFFSET 0
/** Kp = 5/Ks */
#define DCDC_PID_LO_B0_B_KP_5 0x20
/** Kp = 7.5/Ks */
#define DCDC_PID_LO_B0_B_KP_7P5 0x31
/** Kp = 10/Ks */
#define DCDC_PID_LO_B0_B_KP_10 0x41
/** Kp = 12.5/Ks */
#define DCDC_PID_LO_B0_B_KP_12P5 0x51
/** Kp = 15/Ks */
#define DCDC_PID_LO_B0_B_KP_15 0x61
/** Kp = 17.5/Ks */
#define DCDC_PID_LO_B0_B_KP_17P5 0x72
/** Kp = 3/Ks */
#define DCDC_PID_LO_B0_B_KP_3 0x7A
/** Kp = 1/Ks */
#define DCDC_PID_LO_B0_B_KP_1 0xD3

/* Fields of "Hi Byte of coefficient b1" */
/** Hi Byte of coefficient b1 */
#define DCDC_PID_HI_B1_B_MASK 0xFF
/** field offset */
#define DCDC_PID_HI_B1_B_OFFSET 0
/** Kp = 17.5/Ks */
#define DCDC_PID_HI_B1_B_KP_17P5 0x9B
/** Kp = 15/Ks */
#define DCDC_PID_HI_B1_B_KP_15 0xAA
/** Kp = 12.5/Ks */
#define DCDC_PID_HI_B1_B_KP_12P5 0xB8
/** Kp = 10/Ks */
#define DCDC_PID_HI_B1_B_KP_10 0xC6
/** Kp = 7.5/Ks */
#define DCDC_PID_HI_B1_B_KP_7P5 0xD5
/** Kp = 5/Ks */
#define DCDC_PID_HI_B1_B_KP_5 0xE3
/** Kp = 3/Ks */
#define DCDC_PID_HI_B1_B_KP_3 0xEE
/** Kp = 1/Ks */
#define DCDC_PID_HI_B1_B_KP_1 0xFA

/* Fields of "Lo Byte of coefficient b1" */
/** Lo Byte of coefficient b1 */
#define DCDC_PID_LO_B1_B_MASK 0xFF
/** field offset */
#define DCDC_PID_LO_B1_B_OFFSET 0
/** Kp = 7.5/Ks */
#define DCDC_PID_LO_B1_B_KP_7P5 0x22
/** Kp = 15/Ks */
#define DCDC_PID_LO_B1_B_KP_15 0x45
/** Kp = 1/Ks */
#define DCDC_PID_LO_B1_B_KP_1 0x49
/** Kp = 5/Ks */
#define DCDC_PID_LO_B1_B_KP_5 0x6C
/** Kp = 12.5/Ks */
#define DCDC_PID_LO_B1_B_KP_12P5 0x8E
/** Kp = 10/Ks */
#define DCDC_PID_LO_B1_B_KP_10 0xD8
/** Kp = 3/Ks */
#define DCDC_PID_LO_B1_B_KP_3 0xDB
/** Kp = 17.5/Ks */
#define DCDC_PID_LO_B1_B_KP_17P5 0xFB

/* Fields of "Hi Byte of coefficient b2" */
/** Hi Byte of coefficient b2 */
#define DCDC_PID_HI_B2_B_MASK 0xFF
/** field offset */
#define DCDC_PID_HI_B2_B_OFFSET 0
/** Kp = 1/Ks */
#define DCDC_PID_HI_B2_B_KP_1 0x02
/** Kp = 3/Ks */
#define DCDC_PID_HI_B2_B_KP_3 0x08
/** Kp = 5/Ks */
#define DCDC_PID_HI_B2_B_KP_5 0x0E
/** Kp = 7.5/Ks */
#define DCDC_PID_HI_B2_B_KP_7P5 0x15
/** Kp = 10/Ks */
#define DCDC_PID_HI_B2_B_KP_10 0x1C
/** Kp = 12.5/Ks */
#define DCDC_PID_HI_B2_B_KP_12P5 0x24
/** Kp = 15/Ks */
#define DCDC_PID_HI_B2_B_KP_15 0x2B
/** Kp = 17.5/Ks */
#define DCDC_PID_HI_B2_B_KP_17P5 0x32

/* Fields of "Lo Byte of coefficient b2" */
/** Lo Byte of coefficient b2 */
#define DCDC_PID_LO_B2_B_MASK 0xFF
/** field offset */
#define DCDC_PID_LO_B2_B_OFFSET 0
/** Kp = 12.5/Ks */
#define DCDC_PID_LO_B2_B_KP_12P5 0x38
/** Kp = 15/Ks */
#define DCDC_PID_LO_B2_B_KP_15 0x76
/** Kp = 5/Ks */
#define DCDC_PID_LO_B2_B_KP_5 0x7D
/** Kp = 3/Ks */
#define DCDC_PID_LO_B2_B_KP_3 0xB1
/** Kp = 17.5/Ks */
#define DCDC_PID_LO_B2_B_KP_17P5 0xB4
/** Kp = 7.5/Ks */
#define DCDC_PID_LO_B2_B_KP_7P5 0xBB
/** Kp = 1/Ks */
#define DCDC_PID_LO_B2_B_KP_1 0xE6
/** Kp = 10/Ks */
#define DCDC_PID_LO_B2_B_KP_10 0xF9

/* Fields of "Set up clocks" */
/** MDLL multiplication factor
    Integer by which input frequency is multiplied */
#define DCDC_CLK_SET0_MDLL_MUL_MASK 0x3F
/** field offset */
#define DCDC_CLK_SET0_MDLL_MUL_OFFSET 0
/** Sets PWM frequency to 720 MHz in VDSL-mode/to 500 MHz in non-VDSL-mode */
#define DCDC_CLK_SET0_MDLL_MUL_PWM500 0x12
/** Sets PWM frequency to 1440 MHz in VDSL-mode/to 1000 MHZ in non-VDSL-mode */
#define DCDC_CLK_SET0_MDLL_MUL_PWM1000 0x26
/** Set divider between MDLL and PWM
    0 => MDLL output goes straight to PWM */
#define DCDC_CLK_SET0_CLK_SEL_PWM 0x40
/** Bypass MDLL
    Input clock (36MHz in VDSL-mode, 25MHz in non-VDSL-mode) goes straight to PWM, bypassing the MDLL */
#define DCDC_CLK_SET0_MDLL_BYP 0x80

/* Fields of "Set up clocks" */
/** MDLL bias resistance
    0,1,2,3,7 Higher number for higher frequency */
#define DCDC_CLK_SET1_MDLL_RES_MASK 0x07
/** field offset */
#define DCDC_CLK_SET1_MDLL_RES_OFFSET 0
/** Increase current step size in MDLL
    Setting this bit will double the step size */
#define DCDC_CLK_SET1_MDLL_IX2 0x08
/** Double the frequency of ADC clocks
    When the PWM clock is halved to 250MHz, this can be used to ensure that the ADC is still clocked with 250MHz iteration frequency. This also means that the PID controller gets double the clock frequency */
#define DCDC_CLK_SET1_ADC_CLK_MODE 0x10
/** reserved */
#define DCDC_CLK_SET1_RESERVED_MASK 0xE0
/** field offset */
#define DCDC_CLK_SET1_RESERVED_OFFSET 5

/* Fields of "PWM Settings 0" */
/** Counter pre-load
    Sets factor between switching frequncy and PWM input clock. In order to work in VDSL-mode with 720MHz cpload has to be */
#define DCDC_PWM0_CPLOAD_MASK 0xFF
/** field offset */
#define DCDC_PWM0_CPLOAD_OFFSET 0

/* Fields of "PWM Settings 1" */
/** Static Duty Cycle Value
    Sets duty cycle in case of PFM mode, or if force_static_dc is set. Also using the soft_preset_pid signal, the PID controller is set to this value, meaning that the integrator doesn't need to be charged up. dc = dc_static/cpload => thus nominal 80/256 = 30%, which is roughly what is needed for 3.3 V operation */
#define DCDC_PWM1_DC_STATIC_MASK 0xFF
/** field offset */
#define DCDC_PWM1_DC_STATIC_OFFSET 0

/* Fields of "Set up BIAS and voltage regulator" */
/** Trimming of the reference voltage */
#define DCDC_BIAS_VREG_VREF_MASK 0x07
/** field offset */
#define DCDC_BIAS_VREG_VREF_OFFSET 0
/** nominal value */
#define DCDC_BIAS_VREG_VREF_NOMINAL 0x00
/** -1.25% */
#define DCDC_BIAS_VREG_VREF_M125 0x01
/** -2.50% */
#define DCDC_BIAS_VREG_VREF_M250 0x02
/** -3.75% */
#define DCDC_BIAS_VREG_VREF_M375 0x03
/** +1.25% */
#define DCDC_BIAS_VREG_VREF_P125 0x04
/** +2.50% */
#define DCDC_BIAS_VREG_VREF_P250 0x05
/** +3.75% */
#define DCDC_BIAS_VREG_VREF_P375 0x06
/** +5.00% */
#define DCDC_BIAS_VREG_VREF_P500 0x07
/** Set voltage of internal regulator
    Trimming of the internal voltage regulator */
#define DCDC_BIAS_VREG_VREG_SEL_MASK 0x18
/** field offset */
#define DCDC_BIAS_VREG_VREG_SEL_OFFSET 3
/** 0.93V */
#define DCDC_BIAS_VREG_VREG_SEL_M120 0x00
/** 1.0V */
#define DCDC_BIAS_VREG_VREG_SEL_M50 0x08
/** nominal value 1.05V */
#define DCDC_BIAS_VREG_VREG_SEL_NOMINAL 0x10
/** 1.175 */
#define DCDC_BIAS_VREG_VREG_SEL_P70 0x18
/** Reduce bias current for voltage regulator
    Useful if load is low to gain more stability */
#define DCDC_BIAS_VREG_I_RED 0x20
/** Increase current load for internal regulator
    Increase stability and performance by drawing 1mA of current through a resistor */
#define DCDC_BIAS_VREG_I_LOADINC 0x40
/** reserved */
#define DCDC_BIAS_VREG_RESERVED 0x80

/* Fields of "Sets digital reference of DCDC converter" */
/** Sets digital reference of DCDC converter
    Sets up Most Significant Bits of target voltage */
#define DCDC_DIG_REF_V_MASK 0xFF
/** field offset */
#define DCDC_DIG_REF_V_OFFSET 0
/** minus 100mV = 0.90 */
#define DCDC_DIG_REF_V_M100 0x72
/** minus 50mV = 0.95 */
#define DCDC_DIG_REF_V_M50 0x78
/** nominal value 1.0V */
#define DCDC_DIG_REF_V_NOMINAL 0x7F
/** plus 50mV = 1.05 */
#define DCDC_DIG_REF_V_P50 0x86
/** plus 100mV = 1.10 */
#define DCDC_DIG_REF_V_P100 0x8C

/* Fields of "General settings" */
/** Causes fixed duty cycle
    Value is taken from dc_static */
#define DCDC_GENERAL_FORCE_STATIC_DC 0x01
/** Switch on PFM mode
    Similar to force_static_dc, except that additionally the Output Stage is enabled and disabled depending on the output of the PFM comparator, which compares the core voltage to 1.0V and 1.05V */
#define DCDC_GENERAL_PFM_MODE 0x02
/** enable output stage
    Providing that the powerup signal has been received and pfm_mode isn't active, this signal enables the output stage, or makes it high ohmic */
#define DCDC_GENERAL_OS_EN 0x04
/** reserved */
#define DCDC_GENERAL_RESERVED0 0x08
/** invert PWM output signal
    Invert the output of the PWM for external power devices */
#define DCDC_GENERAL_OUT_INV 0x10
/** reserved */
#define DCDC_GENERAL_RESERVED1_MASK 0x60
/** field offset */
#define DCDC_GENERAL_RESERVED1_OFFSET 5
/** set half LSB of digital reference
    This is used to ensure that the control loop never reaches the dead region where it thinks the error is exactly 0 and makes no change to its output. Set at 1, the smallest error value can be + or - 0.5 LSB */
#define DCDC_GENERAL_SET_LSB_DIGREF 0x80

/* Fields of "ADC conf0" */
/** set comparator-to-arith clock delay
    set comparator-to-arith clock delay 0:1:3 */
#define DCDC_ADC0_SET_COMP2ARITH_MASK 0x07
/** field offset */
#define DCDC_ADC0_SET_COMP2ARITH_OFFSET 0
/** set comparator-to-array clock delay
    set comparator-to-array clock delay 0:1:7 */
#define DCDC_ADC0_SET_COMP2ARRAY_MASK 0x38
/** field offset */
#define DCDC_ADC0_SET_COMP2ARRAY_OFFSET 3
/** choose rom bank */
#define DCDC_ADC0_SET_ROM_SEL_MASK 0xC0
/** field offset */
#define DCDC_ADC0_SET_ROM_SEL_OFFSET 6

/* Fields of "ADC conf1" */
/** set reset arithunit
    0: start from last sample */
#define DCDC_ADC1_SET_RESETARITH 0x01
/** enable comparator offset calibration
    1: enable comparator offset calibration */
#define DCDC_ADC1_SET_OFFSET_CAL_EN 0x02
/** set comparator bias current
    set comparator bias current to 12.5uA x 2:1:6 */
#define DCDC_ADC1_SET_COMP_CURR_MASK 0x1C
/** field offset */
#define DCDC_ADC1_SET_COMP_CURR_OFFSET 2
/** set scrambling state
    set scrambling state 0:1:3 */
#define DCDC_ADC1_SET_SCR_STATE_MASK 0x60
/** field offset */
#define DCDC_ADC1_SET_SCR_STATE_OFFSET 5
/** reserved */
#define DCDC_ADC1_RESERVED 0x80

/* Fields of "ADC conf2" */
/** highest rom address while iterating
    highest rom address while iterating 0:1:11 */
#define DCDC_ADC2_SET_ROM_START_MASK 0x0F
/** field offset */
#define DCDC_ADC2_SET_ROM_START_OFFSET 0
/** number of cycles per conversion minus one
    number of cycles per conversion minus one 0:1:11 */
#define DCDC_ADC2_SET_START_MASK 0xF0
/** field offset */
#define DCDC_ADC2_SET_START_OFFSET 4

/* Fields of "Analog Test Configuration for Autostart Mode" */
/** Reset ADC */
#define DCDC_CONF_TEST_ANA_SOFT_RES_ADC_N 0x01
/** Reset MDLL */
#define DCDC_CONF_TEST_ANA_SOFT_RES_MDLL_N 0x02
/** Reset DPWM
    The PWM generator is disabled. */
#define DCDC_CONF_TEST_ANA_SOFT_RES_DPWM_N 0x04
/** Power Down ADC */
#define DCDC_CONF_TEST_ANA_PD_ADC 0x08
/** reserved */
#define DCDC_CONF_TEST_ANA_RESERVED0 0x10
/** Power Down of PFM comparator */
#define DCDC_CONF_TEST_ANA_PD_PFMCOMP 0x20
/** Bypass Digital PWM generator
    This passes the startup clk (25MHz/32) to the output of the DPWM block, allowing the DPWM to be put in reset. This feature is particularly interesting in PFM mode. */
#define DCDC_CONF_TEST_ANA_DPWM_BYP 0x40
/** Oscillator max suppression
    This switches on the max suppression filter in the oscillator. */
#define DCDC_CONF_TEST_ANA_OSC_MAX_SUPPR 0x80

/* Fields of "Digital Test Configuration for Autostart Mode" */
/** Reset PID Controller */
#define DCDC_CONF_TEST_DIG_SOFT_RES_PID_N 0x01
/** Reset Rampup Generator
    Causes the digital reference to start at zero and ramp to the value in its register */
#define DCDC_CONF_TEST_DIG_SOFT_RES_RAMPUP_N 0x02
/** Bypass PID control
    Bypass PID control - Data from ADC accumulator are passed straight to DPWM */
#define DCDC_CONF_TEST_DIG_TEST_ADC2DUTY 0x04
/** Bypass of ADC accumulator
    Bypass ADC accumulator - Data from ADC are passed straight to output of accumulator */
#define DCDC_CONF_TEST_DIG_TEST_ACCUM_BYP 0x08
/** Freeze PID controller
    This is used to reset the sequencer which controls the pid filter. Should be set while changing any of the coefficients */
#define DCDC_CONF_TEST_DIG_FREEZE_PID 0x10
/** Soft preset of PID controller
    This is used to preset the PID integrator, and output with the value of the static_dc register, and other registers to zero. Can be used to bring the system back under control */
#define DCDC_CONF_TEST_DIG_SOFT_PRESET_PID 0x20
/** reserved */
#define DCDC_CONF_TEST_DIG_RESERVED_MASK 0xC0
/** field offset */
#define DCDC_CONF_TEST_DIG_RESERVED_OFFSET 6

/* Fields of "Analog Test Configuration for Non-Autostart Mode" */
/** Reset ADC */
#define DCDC_CONF_TEST_ANA_NOAUTO_SOFT_RES_ADC_N 0x01
/** Reset MDLL */
#define DCDC_CONF_TEST_ANA_NOAUTO_SOFT_RES_MDLL_N 0x02
/** Reset DPWM */
#define DCDC_CONF_TEST_ANA_NOAUTO_SOFT_RES_DPWM_N 0x04
/** Power Down ADC */
#define DCDC_CONF_TEST_ANA_NOAUTO_PD_ADC 0x08
/** reserved */
#define DCDC_CONF_TEST_ANA_NOAUTO_RESERVED0 0x10
/** Power Down of PFM comparator */
#define DCDC_CONF_TEST_ANA_NOAUTO_PD_PFMCOMP 0x20
/** Bypass Digital PWM generator
    This passes the startup clk (25MHz/32) to the output of the DPWM block, allowing the DPWM to be put in reset. This feature is particularly interesting in PFM mode. */
#define DCDC_CONF_TEST_ANA_NOAUTO_DPWM_BYP 0x40
/** Oscillator max suppression
    This switches on the max suppression filter in the oscillator. */
#define DCDC_CONF_TEST_ANA_NOAUTO_OSC_MAX_SUPPR 0x80

/* Fields of "Digital Test Configuration for Non-Autostart Mode" */
/** Reset PID Controller */
#define DCDC_CONF_TEST_DIG_NOAUTO_SOFT_RES_PID_N 0x01
/** Reset Rampup Generator
    Causes the digital reference to start at zero and ramp to the value in its register */
#define DCDC_CONF_TEST_DIG_NOAUTO_SOFT_RES_RAMPUP_N 0x02
/** Bypass PID control
    Bypass PID control - Data from ADC accumulator are passed straight to DPWM */
#define DCDC_CONF_TEST_DIG_NOAUTO_TEST_ADC2DUTY 0x04
/** Bypass of ADC accumulator
    Bypass ADC accumulator - Data from ADC are passed straight to output of accumulator */
#define DCDC_CONF_TEST_DIG_NOAUTO_TEST_ACCUM_BYP 0x08
/** Freeze PID controller
    This is used to reset the sequencer which controls the pid filter. Should be set while changing any of the coefficients */
#define DCDC_CONF_TEST_DIG_NOAUTO_FREEZE_PID 0x10
/** Soft preset of PID controller
    This is used to preset the PID integrator, and output with the value of the static_dc register, and other registers to zero. Can be used to bring the system back under control */
#define DCDC_CONF_TEST_DIG_NOAUTO_SOFT_PRESET_PID 0x20
/** reserved */
#define DCDC_CONF_TEST_DIG_NOAUTO_RESERVED_MASK 0xC0
/** field offset */
#define DCDC_CONF_TEST_DIG_NOAUTO_RESERVED_OFFSET 6

/* Fields of "DCDC_STATUS" */
/** powerup dcdc signal detected just after reset */
#define DCDC_DCDC_STATUS_POWERUP_DCDC 0x01
/** Output current higher than 1A for more than 8 cycles */
#define DCDC_DCDC_STATUS_IMAX_REACHED 0x02
/** mdll locked signal */
#define DCDC_DCDC_STATUS_MDLL_LOCKED 0x04
/** inverted version of mdll locked signal - used to detect whether the MDLL wwas continually in locked. If set, then it was at least temporarily out of lock */
#define DCDC_DCDC_STATUS_MDLL_LOCKED_N 0x08

/* Fields of "PID_STATUS" */
/** duty cycle positive saturation (240/255) */
#define DCDC_PID_STATUS_DUTY_SAT_HI 0x01
/** duty cycle negative saturation (7/255) */
#define DCDC_PID_STATUS_DUTY_SAT_LO 0x02
/** error positive saturation (2^8-1) */
#define DCDC_PID_STATUS_ERR_SAT_HI 0x04
/** error negative saturation (-2^8) */
#define DCDC_PID_STATUS_ERR_SAT_LO 0x08
/** multiplier positive saturation (2^20-1) */
#define DCDC_PID_STATUS_MUL_SAT_HI 0x10
/** multiplier negative saturation (-2^20) */
#define DCDC_PID_STATUS_MUL_SAT_LO 0x20
/** PID controller has detected an error of > +/- 120mV for 7 cycles in a row! DANGER! */
#define DCDC_PID_STATUS_REG_FAIL 0x40
/** reserved */
#define DCDC_PID_STATUS_RESERVED 0x80

/* Fields of "DUTY_CYCLE" */
/** Contains the data going from PID to DPWM */
#define DCDC_DUTY_CYCLE_DC_WISH_MASK 0xFF
/** field offset */
#define DCDC_DUTY_CYCLE_DC_WISH_OFFSET 0

/* Fields of "NON_OV_DELAY" */
/** non-overlap-time for PMOS turn off
    time between PMOS turn-off and NMOS turn-on */
#define DCDC_NON_OV_DELAY_DEL_N_MASK 0x0F
/** field offset */
#define DCDC_NON_OV_DELAY_DEL_N_OFFSET 0
/** non-overlap-time for PMOS turn on
    time between NMOS turn-off and PMOS turn-on */
#define DCDC_NON_OV_DELAY_DEL_P_MASK 0xF0
/** field offset */
#define DCDC_NON_OV_DELAY_DEL_P_OFFSET 4

/* Fields of "ANALOG_GAIN" */
/** attenuation after subtraction of the analog reference. Used for DCDC that senses 1.8V or 2.5V, in case of DDR1 or DDR2 supply, together with the changed reference voltage (see vref_ana bit): */
#define DCDC_ANALOG_GAIN_ATTENUATE_ANA 0x01
/** gain in front ADC (after subtraction of the analog reference) */
#define DCDC_ANALOG_GAIN_GAIN_ANA_MASK 0x06
/** field offset */
#define DCDC_ANALOG_GAIN_GAIN_ANA_OFFSET 1
/** reference voltage for single to diff SC input buffer: */
#define DCDC_ANALOG_GAIN_VREF_ANA 0x08
/** reserved */
#define DCDC_ANALOG_GAIN_RESERVED_MASK 0xF0
/** field offset */
#define DCDC_ANALOG_GAIN_RESERVED_OFFSET 4

/* Fields of "DUTY_CYCLE_MAX_SAT" */
/** Contains the upper saturation value for the duty cycle */
#define DCDC_DUTY_CYCLE_MAX_SAT_DUTY_MAX_SAT_MASK 0xFF
/** field offset */
#define DCDC_DUTY_CYCLE_MAX_SAT_DUTY_MAX_SAT_OFFSET 0

/* Fields of "DUTY_CYCLE_MIN_SAT" */
/** Contains the lower saturation value for the duty cycle */
#define DCDC_DUTY_CYCLE_MIN_SAT_DUTY_MIN_SAT_MASK 0xFF
/** field offset */
#define DCDC_DUTY_CYCLE_MIN_SAT_DUTY_MIN_SAT_OFFSET 0

/* Fields of "DUTY_CYCLE_MAX" */
/** Contains the comparison value for the duty cycle. If the duty cycle is higher than this value => alarm that a overcurrent/short condition is happening */
#define DCDC_DUTY_CYCLE_MAX_DUTY_MAX_MASK 0xFF
/** field offset */
#define DCDC_DUTY_CYCLE_MAX_DUTY_MAX_OFFSET 0

/* Fields of "DUTY_CYCLE_MIN" */
/** Contains the comparison value for the duty cycle. If the duty cycle is lower than this value => alarm that a pmos short etc. condition is happening */
#define DCDC_DUTY_CYCLE_MIN_DUTY_MIN_MASK 0xFF
/** field offset */
#define DCDC_DUTY_CYCLE_MIN_DUTY_MIN_OFFSET 0

/* Fields of "ERROR_MAX" */
/** Contains the comparison value for the error. */
#define DCDC_ERROR_MAX_ERROR_MAX_MASK 0xFF
/** field offset */
#define DCDC_ERROR_MAX_ERROR_MAX_OFFSET 0

/* Fields of "ERROR_READ" */
/** Contains the actual error that is fed to the PID */
#define DCDC_ERROR_READ_ERROR_MASK 0xFF
/** field offset */
#define DCDC_ERROR_READ_ERROR_OFFSET 0

/* Fields of "DELAY_DEGLITCH" */
/** Deglitching counter for alarm. The alarm must be consistent active for the alarm_deglitch number of DCDC cycles, before the output is activated: */
#define DCDC_DELAY_DEGLITCH_ALARM_DEGLITCH_MASK 0x0F
/** field offset */
#define DCDC_DELAY_DEGLITCH_ALARM_DEGLITCH_OFFSET 0
/** Speed setting for soft start ramp: */
#define DCDC_DELAY_DEGLITCH_RAMP_DELAY_MASK 0x70
/** field offset */
#define DCDC_DELAY_DEGLITCH_RAMP_DELAY_OFFSET 4
/** reserved */
#define DCDC_DELAY_DEGLITCH_RESERVED 0x80

/* Fields of "LATCH_CONTROL" */
/** Select the latch for synchronising the SC input buffer data with the ADC result. */
#define DCDC_LATCH_CONTROL_CAP_CLK_MODE 0x01
/** reserved */
#define DCDC_LATCH_CONTROL_RESERVED1_MASK 0x06
/** field offset */
#define DCDC_LATCH_CONTROL_RESERVED1_OFFSET 1
/** Force p-transistor to static value. */
#define DCDC_LATCH_CONTROL_PFORCE_EN 0x08
/** Static value for p-transistor when forced. */
#define DCDC_LATCH_CONTROL_PFORCE_AT 0x10
/** Force n-transistor to static value. */
#define DCDC_LATCH_CONTROL_NFORCE_EN 0x20
/** Static value for n-transistor when forced. */
#define DCDC_LATCH_CONTROL_NFORCE_AT 0x40
/** reserved */
#define DCDC_LATCH_CONTROL_RESERVED2 0x80

/* Fields of "LATCH_CONTROL_NOAUTO" */
/** Select the latch for synchronising the SC input buffer data with the ADC result. */
#define DCDC_LATCH_CONTROL_NOAUTO_CAP_CLK_MODE 0x01
/** reserved */
#define DCDC_LATCH_CONTROL_NOAUTO_RESERVED1_MASK 0x06
/** field offset */
#define DCDC_LATCH_CONTROL_NOAUTO_RESERVED1_OFFSET 1
/** Force p-transistor to static value. */
#define DCDC_LATCH_CONTROL_NOAUTO_PFORCE_EN 0x08
/** Static value for p-transistor when forced. */
#define DCDC_LATCH_CONTROL_NOAUTO_PFORCE_AT 0x10
/** Force n-transistor to static value. */
#define DCDC_LATCH_CONTROL_NOAUTO_NFORCE_EN 0x20
/** Static value for n-transistor when forced. */
#define DCDC_LATCH_CONTROL_NOAUTO_NFORCE_AT 0x40
/** reserved */
#define DCDC_LATCH_CONTROL_NOAUTO_RESERVED2 0x80

/* Fields of "CAP_CLK_CNT" */
/** Contains the value for the capture clock counter. The ouput frequency is calculated by the formula fcap_clk = fsample_clk/counter value. */
#define DCDC_CAP_CLK_CNT_COUNTER_MASK 0xFF
/** field offset */
#define DCDC_CAP_CLK_CNT_COUNTER_OFFSET 0

/* Fields of "MDLL_DIVIDER" */
/** Select the post divider for MDLL clock. */
#define DCDC_MDLL_DIVIDER_DIVIDER_MASK 0x03
/** field offset */
#define DCDC_MDLL_DIVIDER_DIVIDER_OFFSET 0
/** Reserved bits for analog part of the DCDC converter. */
#define DCDC_MDLL_DIVIDER_ANA_RES_MASK 0x0C
/** field offset */
#define DCDC_MDLL_DIVIDER_ANA_RES_OFFSET 2

/* Fields of "OSC Configuration Register" */
/** Disable amplitude regulation
    Leads to increase of amplitude at XTAL1, */
#define DCDC_OSC_CONF_REG_DIS 0x01
/** Increase regulation capacitance
    Leads to increase of amplitude at XTAL1, */
#define DCDC_OSC_CONF_CAP_UP 0x02
/** Bypass shaper */
#define DCDC_OSC_CONF_SH_BYP_REG 0x04
/** Overwrite frequency detection
    Instead of automatically detecting incoming frequency, this can be overwritten using this bit. The value is taken from OWR_FDET_VAL */
#define DCDC_OSC_CONF_OWR_FDET 0x08
/** Value of frequency detection in overwrite mode
    0 => Frequency at XTAL1 goes through */
#define DCDC_OSC_CONF_OWR_FDET_VAL 0x10
/** Power down of frequency detector */
#define DCDC_OSC_CONF_PD_FDETECT 0x20
/** Power down of clock shaper */
#define DCDC_OSC_CONF_PD_SHAPER 0x40
/** Power down of oscillator core */
#define DCDC_OSC_CONF_PD_CORE 0x80

/* Fields of "OSC_STATUS" */
/** osc clk frequency detected */
#define DCDC_OSC_STATUS_CLK_FREQ 0x01

/*! @} */ /* DCDC_REGISTER */

#endif /* _dcdc_reg_h */
