/******************************************************************************

                               Copyright (c) 2012
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _gpio_reg_h
#define _gpio_reg_h

/** \addtogroup GPIO_REGISTER
   @{
*/
/* access macros */
#define gpio0_r32(reg) reg_r32(&gpio0->reg)
#define gpio0_w32(val, reg) reg_w32(val, &gpio0->reg)
#define gpio0_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &gpio0->reg)
#define gpio0_r32_table(reg, idx) reg_r32_table(gpio0->reg, idx)
#define gpio0_w32_table(val, reg, idx) reg_w32_table(val, gpio0->reg, idx)
#define gpio0_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, gpio0->reg, idx)
#define gpio0_adr_table(reg, idx) adr_table(gpio0->reg, idx)

#define gpio1_r32(reg) reg_r32(&gpio1->reg)
#define gpio1_w32(val, reg) reg_w32(val, &gpio1->reg)
#define gpio1_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &gpio1->reg)
#define gpio1_r32_table(reg, idx) reg_r32_table(gpio1->reg, idx)
#define gpio1_w32_table(val, reg, idx) reg_w32_table(val, gpio1->reg, idx)
#define gpio1_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, gpio1->reg, idx)
#define gpio1_adr_table(reg, idx) adr_table(gpio1->reg, idx)

#define gpio2_r32(reg) reg_r32(&gpio2->reg)
#define gpio2_w32(val, reg) reg_w32(val, &gpio2->reg)
#define gpio2_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &gpio2->reg)
#define gpio2_r32_table(reg, idx) reg_r32_table(gpio2->reg, idx)
#define gpio2_w32_table(val, reg, idx) reg_w32_table(val, gpio2->reg, idx)
#define gpio2_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, gpio2->reg, idx)
#define gpio2_adr_table(reg, idx) adr_table(gpio2->reg, idx)

#define gpio3_r32(reg) reg_r32(&gpio3->reg)
#define gpio3_w32(val, reg) reg_w32(val, &gpio3->reg)
#define gpio3_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &gpio3->reg)
#define gpio3_r32_table(reg, idx) reg_r32_table(gpio3->reg, idx)
#define gpio3_w32_table(val, reg, idx) reg_w32_table(val, gpio3->reg, idx)
#define gpio3_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, gpio3->reg, idx)
#define gpio3_adr_table(reg, idx) adr_table(gpio3->reg, idx)

#define gpio4_r32(reg) reg_r32(&gpio4->reg)
#define gpio4_w32(val, reg) reg_w32(val, &gpio4->reg)
#define gpio4_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &gpio4->reg)
#define gpio4_r32_table(reg, idx) reg_r32_table(gpio4->reg, idx)
#define gpio4_w32_table(val, reg, idx) reg_w32_table(val, gpio4->reg, idx)
#define gpio4_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, gpio4->reg, idx)
#define gpio4_adr_table(reg, idx) adr_table(gpio4->reg, idx)


/** GPIO register structure */
struct gpon_reg_gpio
{
   /** Data Output Register
       Via this register the output values of the different bits can be set if they are switched as outputs. */
   unsigned int out; /* 0x00000000 */
   /** Data Input Register
       Via this register the input values of the different bits can be observed. */
   unsigned int in; /* 0x00000004 */
   /** Direction Register
       Via this register the input direction of the different bits can be determined. */
   unsigned int dir; /* 0x00000008 */
   /** Reserved */
   unsigned int res_0[3]; /* 0x0000000C */
   /** External Interrupt Control Register 0 */
   unsigned int exintcr0; /* 0x00000018 */
   /** External Interrupt Control Register 1 */
   unsigned int exintcr1; /* 0x0000001C */
   /** IRN Capture Register
       This register shows the currently active interrupt events masked with the corresponding enable bits of the IRNEN register. The interrupts can be acknowledged by a write operation. */
   unsigned int irncr; /* 0x00000020 */
   /** IRN Interrupt Control Register
       A write operation directly effects the interrupts. This can be used to trigger events under software control for testing purposes. A read operation returns the unmasked interrupt events. */
   unsigned int irnicr; /* 0x00000024 */
   /** IRN Interrupt Enable Register
       This register contains the enable (or mask) bits for the interrupts. Disabled interrupts are not visible in the IRNCR register and are not signalled via the interrupt line towards the controller. */
   unsigned int irnen; /* 0x00000028 */
   /** IRN Interrupt Configuration Register
       Configures the interrupts bitwise to be edge-senstivie or level-sensitive. */
   unsigned int irncfg; /* 0x0000002C */
   /** IRN Interrupt Enable Set Register
       The corresponding bit in the IRNEN register can be set with an atomic access. */
   unsigned int irnenset; /* 0x00000030 */
   /** IRN Interrupt Enable Clear Register
       The corresponding bit in the IRNEN register can be cleared with an atomic access. */
   unsigned int irnenclr; /* 0x00000034 */
   /** Reserved */
   unsigned int res_1[2]; /* 0x00000038 */
   /** Output Set Register
       This register can be used to set certain bits within the OUT register without touching the other bits. */
   unsigned int outset; /* 0x00000040 */
   /** Output Clear Register
       This register can be used to clear certain bits within the OUT register without touching the other bits. */
   unsigned int outclr; /* 0x00000044 */
   /** Direction Set Register
       This register can be used to set certain bits within the DIR register without touching the other bits. */
   unsigned int dirset; /* 0x00000048 */
   /** Direction Clear Register
       This register can be used to clear certain bits within the DIR register without touching the other bits. */
   unsigned int dirclr; /* 0x0000004C */
   /** Reserved */
   unsigned int res_2[12]; /* 0x00000050 */
};


/* Fields of "Data Output Register" */
/** Bit 24 Output Value */
#define GPIO_OUT_P24 0x01000000
/** Bit 23 Output Value */
#define GPIO_OUT_P23 0x00800000
/** Bit 22 Output Value */
#define GPIO_OUT_P22 0x00400000
/** Bit 21 Output Value */
#define GPIO_OUT_P21 0x00200000
/** Bit 20 Output Value */
#define GPIO_OUT_P20 0x00100000
/** Bit 19 Output Value */
#define GPIO_OUT_P19 0x00080000
/** Bit 18 Output Value */
#define GPIO_OUT_P18 0x00040000
/** Bit 17 Output Value */
#define GPIO_OUT_P17 0x00020000
/** Bit 16 Output Value */
#define GPIO_OUT_P16 0x00010000
/** Bit 15 Output Value */
#define GPIO_OUT_P15 0x00008000
/** Bit 14 Output Value */
#define GPIO_OUT_P14 0x00004000
/** Bit 13 Output Value */
#define GPIO_OUT_P13 0x00002000
/** Bit 12 Output Value */
#define GPIO_OUT_P12 0x00001000
/** Bit 11 Output Value */
#define GPIO_OUT_P11 0x00000800
/** Bit 10 Output Value */
#define GPIO_OUT_P10 0x00000400
/** Bit 9 Output Value */
#define GPIO_OUT_P9 0x00000200
/** Bit 8 Output Value */
#define GPIO_OUT_P8 0x00000100
/** Bit 7 Output Value */
#define GPIO_OUT_P7 0x00000080
/** Bit 6 Output Value */
#define GPIO_OUT_P6 0x00000040
/** Bit 5 Output Value */
#define GPIO_OUT_P5 0x00000020
/** Bit 4 Output Value */
#define GPIO_OUT_P4 0x00000010
/** Bit 3 Output Value */
#define GPIO_OUT_P3 0x00000008
/** Bit 2 Output Value */
#define GPIO_OUT_P2 0x00000004
/** Bit 1 Output Value */
#define GPIO_OUT_P1 0x00000002
/** Bit 0 Output Value */
#define GPIO_OUT_P0 0x00000001

/* Fields of "Data Input Register" */
/** Bit 24 Latched Input Value */
#define GPIO_IN_P24 0x01000000
/** Bit 23 Latched Input Value */
#define GPIO_IN_P23 0x00800000
/** Bit 22 Latched Input Value */
#define GPIO_IN_P22 0x00400000
/** Bit 21 Latched Input Value */
#define GPIO_IN_P21 0x00200000
/** Bit 20 Latched Input Value */
#define GPIO_IN_P20 0x00100000
/** Bit 19 Latched Input Value */
#define GPIO_IN_P19 0x00080000
/** Bit 18 Latched Input Value */
#define GPIO_IN_P18 0x00040000
/** Bit 17 Latched Input Value */
#define GPIO_IN_P17 0x00020000
/** Bit 16 Latched Input Value */
#define GPIO_IN_P16 0x00010000
/** Bit 15 Latched Input Value */
#define GPIO_IN_P15 0x00008000
/** Bit 14 Latched Input Value */
#define GPIO_IN_P14 0x00004000
/** Bit 13 Latched Input Value */
#define GPIO_IN_P13 0x00002000
/** Bit 12 Latched Input Value */
#define GPIO_IN_P12 0x00001000
/** Bit 11 Latched Input Value */
#define GPIO_IN_P11 0x00000800
/** Bit 10 Latched Input Value */
#define GPIO_IN_P10 0x00000400
/** Bit 9 Latched Input Value */
#define GPIO_IN_P9 0x00000200
/** Bit 8 Latched Input Value */
#define GPIO_IN_P8 0x00000100
/** Bit 7 Latched Input Value */
#define GPIO_IN_P7 0x00000080
/** Bit 6 Latched Input Value */
#define GPIO_IN_P6 0x00000040
/** Bit 5 Latched Input Value */
#define GPIO_IN_P5 0x00000020
/** Bit 4 Latched Input Value */
#define GPIO_IN_P4 0x00000010
/** Bit 3 Latched Input Value */
#define GPIO_IN_P3 0x00000008
/** Bit 2 Latched Input Value */
#define GPIO_IN_P2 0x00000004
/** Bit 1 Latched Input Value */
#define GPIO_IN_P1 0x00000002
/** Bit 0 Latched Input Value */
#define GPIO_IN_P0 0x00000001

/* Fields of "Direction Register" */
/** Bit 24 Direction Control */
#define GPIO_DIR_P24 0x01000000
/* Input
#define GPIO_DIR_P24_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P24_OUT 0x01000000
/** Bit 23 Direction Control */
#define GPIO_DIR_P23 0x00800000
/* Input
#define GPIO_DIR_P23_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P23_OUT 0x00800000
/** Bit 22 Direction Control */
#define GPIO_DIR_P22 0x00400000
/* Input
#define GPIO_DIR_P22_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P22_OUT 0x00400000
/** Bit 21 Direction Control */
#define GPIO_DIR_P21 0x00200000
/* Input
#define GPIO_DIR_P21_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P21_OUT 0x00200000
/** Bit 20 Direction Control */
#define GPIO_DIR_P20 0x00100000
/* Input
#define GPIO_DIR_P20_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P20_OUT 0x00100000
/** Bit 19 Direction Control */
#define GPIO_DIR_P19 0x00080000
/* Input
#define GPIO_DIR_P19_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P19_OUT 0x00080000
/** Bit 18 Direction Control */
#define GPIO_DIR_P18 0x00040000
/* Input
#define GPIO_DIR_P18_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P18_OUT 0x00040000
/** Bit 17 Direction Control */
#define GPIO_DIR_P17 0x00020000
/* Input
#define GPIO_DIR_P17_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P17_OUT 0x00020000
/** Bit 16 Direction Control */
#define GPIO_DIR_P16 0x00010000
/* Input
#define GPIO_DIR_P16_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P16_OUT 0x00010000
/** Bit 15 Direction Control */
#define GPIO_DIR_P15 0x00008000
/* Input
#define GPIO_DIR_P15_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P15_OUT 0x00008000
/** Bit 14 Direction Control */
#define GPIO_DIR_P14 0x00004000
/* Input
#define GPIO_DIR_P14_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P14_OUT 0x00004000
/** Bit 13 Direction Control */
#define GPIO_DIR_P13 0x00002000
/* Input
#define GPIO_DIR_P13_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P13_OUT 0x00002000
/** Bit 12 Direction Control */
#define GPIO_DIR_P12 0x00001000
/* Input
#define GPIO_DIR_P12_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P12_OUT 0x00001000
/** Bit 11 Direction Control */
#define GPIO_DIR_P11 0x00000800
/* Input
#define GPIO_DIR_P11_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P11_OUT 0x00000800
/** Bit 10 Direction Control */
#define GPIO_DIR_P10 0x00000400
/* Input
#define GPIO_DIR_P10_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P10_OUT 0x00000400
/** Bit 9 Direction Control */
#define GPIO_DIR_P9 0x00000200
/* Input
#define GPIO_DIR_P9_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P9_OUT 0x00000200
/** Bit 8 Direction Control */
#define GPIO_DIR_P8 0x00000100
/* Input
#define GPIO_DIR_P8_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P8_OUT 0x00000100
/** Bit 7 Direction Control */
#define GPIO_DIR_P7 0x00000080
/* Input
#define GPIO_DIR_P7_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P7_OUT 0x00000080
/** Bit 6 Direction Control */
#define GPIO_DIR_P6 0x00000040
/* Input
#define GPIO_DIR_P6_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P6_OUT 0x00000040
/** Bit 5 Direction Control */
#define GPIO_DIR_P5 0x00000020
/* Input
#define GPIO_DIR_P5_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P5_OUT 0x00000020
/** Bit 4 Direction Control */
#define GPIO_DIR_P4 0x00000010
/* Input
#define GPIO_DIR_P4_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P4_OUT 0x00000010
/** Bit 3 Direction Control */
#define GPIO_DIR_P3 0x00000008
/* Input
#define GPIO_DIR_P3_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P3_OUT 0x00000008
/** Bit 2 Direction Control */
#define GPIO_DIR_P2 0x00000004
/* Input
#define GPIO_DIR_P2_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P2_OUT 0x00000004
/** Bit 1 Direction Control */
#define GPIO_DIR_P1 0x00000002
/* Input
#define GPIO_DIR_P1_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P1_OUT 0x00000002
/** Bit 0 Direction Control */
#define GPIO_DIR_P0 0x00000001
/* Input
#define GPIO_DIR_P0_IN 0x00000000 */
/** Output */
#define GPIO_DIR_P0_OUT 0x00000001

/* Fields of "External Interrupt Control Register 0" */
/** Bit 24 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P24 0x01000000
/* Positive Logic
#define GPIO_EXINTCR0_P24_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P24_NEG 0x01000000
/** Bit 23 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P23 0x00800000
/* Positive Logic
#define GPIO_EXINTCR0_P23_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P23_NEG 0x00800000
/** Bit 22 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P22 0x00400000
/* Positive Logic
#define GPIO_EXINTCR0_P22_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P22_NEG 0x00400000
/** Bit 21 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P21 0x00200000
/* Positive Logic
#define GPIO_EXINTCR0_P21_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P21_NEG 0x00200000
/** Bit 20 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P20 0x00100000
/* Positive Logic
#define GPIO_EXINTCR0_P20_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P20_NEG 0x00100000
/** Bit 19 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P19 0x00080000
/* Positive Logic
#define GPIO_EXINTCR0_P19_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P19_NEG 0x00080000
/** Bit 18 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P18 0x00040000
/* Positive Logic
#define GPIO_EXINTCR0_P18_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P18_NEG 0x00040000
/** Bit 17 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P17 0x00020000
/* Positive Logic
#define GPIO_EXINTCR0_P17_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P17_NEG 0x00020000
/** Bit 16 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P16 0x00010000
/* Positive Logic
#define GPIO_EXINTCR0_P16_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P16_NEG 0x00010000
/** Bit 15 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P15 0x00008000
/* Positive Logic
#define GPIO_EXINTCR0_P15_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P15_NEG 0x00008000
/** Bit 14 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P14 0x00004000
/* Positive Logic
#define GPIO_EXINTCR0_P14_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P14_NEG 0x00004000
/** Bit 13 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P13 0x00002000
/* Positive Logic
#define GPIO_EXINTCR0_P13_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P13_NEG 0x00002000
/** Bit 12 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P12 0x00001000
/* Positive Logic
#define GPIO_EXINTCR0_P12_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P12_NEG 0x00001000
/** Bit 11 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P11 0x00000800
/* Positive Logic
#define GPIO_EXINTCR0_P11_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P11_NEG 0x00000800
/** Bit 10 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P10 0x00000400
/* Positive Logic
#define GPIO_EXINTCR0_P10_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P10_NEG 0x00000400
/** Bit 9 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P9 0x00000200
/* Positive Logic
#define GPIO_EXINTCR0_P9_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P9_NEG 0x00000200
/** Bit 8 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P8 0x00000100
/* Positive Logic
#define GPIO_EXINTCR0_P8_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P8_NEG 0x00000100
/** Bit 7 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P7 0x00000080
/* Positive Logic
#define GPIO_EXINTCR0_P7_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P7_NEG 0x00000080
/** Bit 6 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P6 0x00000040
/* Positive Logic
#define GPIO_EXINTCR0_P6_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P6_NEG 0x00000040
/** Bit 5 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P5 0x00000020
/* Positive Logic
#define GPIO_EXINTCR0_P5_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P5_NEG 0x00000020
/** Bit 4 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P4 0x00000010
/* Positive Logic
#define GPIO_EXINTCR0_P4_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P4_NEG 0x00000010
/** Bit 3 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P3 0x00000008
/* Positive Logic
#define GPIO_EXINTCR0_P3_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P3_NEG 0x00000008
/** Bit 2 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P2 0x00000004
/* Positive Logic
#define GPIO_EXINTCR0_P2_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P2_NEG 0x00000004
/** Bit 1 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P1 0x00000002
/* Positive Logic
#define GPIO_EXINTCR0_P1_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P1_NEG 0x00000002
/** Bit 0 External Interrupt Control 0
    Selects whether a positive logic event (rising edge, high level) or a negative logic event (falling edge, low level) triggers the interrupt. Selection between edge or level sensitivity can be determined using the IRNCFG register. */
#define GPIO_EXINTCR0_P0 0x00000001
/* Positive Logic
#define GPIO_EXINTCR0_P0_POS 0x00000000 */
/** Negative Logic */
#define GPIO_EXINTCR0_P0_NEG 0x00000001

/* Fields of "External Interrupt Control Register 1" */
/** Bit 24 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P24 0x01000000
/* Single edge
#define GPIO_EXINTCR1_P24_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P24_BOTH 0x01000000
/** Bit 23 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P23 0x00800000
/* Single edge
#define GPIO_EXINTCR1_P23_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P23_BOTH 0x00800000
/** Bit 22 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P22 0x00400000
/* Single edge
#define GPIO_EXINTCR1_P22_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P22_BOTH 0x00400000
/** Bit 21 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P21 0x00200000
/* Single edge
#define GPIO_EXINTCR1_P21_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P21_BOTH 0x00200000
/** Bit 20 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P20 0x00100000
/* Single edge
#define GPIO_EXINTCR1_P20_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P20_BOTH 0x00100000
/** Bit 19 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P19 0x00080000
/* Single edge
#define GPIO_EXINTCR1_P19_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P19_BOTH 0x00080000
/** Bit 18 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P18 0x00040000
/* Single edge
#define GPIO_EXINTCR1_P18_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P18_BOTH 0x00040000
/** Bit 17 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P17 0x00020000
/* Single edge
#define GPIO_EXINTCR1_P17_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P17_BOTH 0x00020000
/** Bit 16 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P16 0x00010000
/* Single edge
#define GPIO_EXINTCR1_P16_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P16_BOTH 0x00010000
/** Bit 15 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P15 0x00008000
/* Single edge
#define GPIO_EXINTCR1_P15_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P15_BOTH 0x00008000
/** Bit 14 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P14 0x00004000
/* Single edge
#define GPIO_EXINTCR1_P14_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P14_BOTH 0x00004000
/** Bit 13 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P13 0x00002000
/* Single edge
#define GPIO_EXINTCR1_P13_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P13_BOTH 0x00002000
/** Bit 12 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P12 0x00001000
/* Single edge
#define GPIO_EXINTCR1_P12_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P12_BOTH 0x00001000
/** Bit 11 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P11 0x00000800
/* Single edge
#define GPIO_EXINTCR1_P11_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P11_BOTH 0x00000800
/** Bit 10 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P10 0x00000400
/* Single edge
#define GPIO_EXINTCR1_P10_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P10_BOTH 0x00000400
/** Bit 9 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P9 0x00000200
/* Single edge
#define GPIO_EXINTCR1_P9_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P9_BOTH 0x00000200
/** Bit 8 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P8 0x00000100
/* Single edge
#define GPIO_EXINTCR1_P8_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P8_BOTH 0x00000100
/** Bit 7 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P7 0x00000080
/* Single edge
#define GPIO_EXINTCR1_P7_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P7_BOTH 0x00000080
/** Bit 6 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P6 0x00000040
/* Single edge
#define GPIO_EXINTCR1_P6_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P6_BOTH 0x00000040
/** Bit 5 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P5 0x00000020
/* Single edge
#define GPIO_EXINTCR1_P5_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P5_BOTH 0x00000020
/** Bit 4 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P4 0x00000010
/* Single edge
#define GPIO_EXINTCR1_P4_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P4_BOTH 0x00000010
/** Bit 3 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P3 0x00000008
/* Single edge
#define GPIO_EXINTCR1_P3_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P3_BOTH 0x00000008
/** Bit 2 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P2 0x00000004
/* Single edge
#define GPIO_EXINTCR1_P2_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P2_BOTH 0x00000004
/** Bit 1 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P1 0x00000002
/* Single edge
#define GPIO_EXINTCR1_P1_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P1_BOTH 0x00000002
/** Bit 0 External Interrupt Control 1
    Selects whether just one edge or both edges should trigger the interrupt. Note: This bit is only useful if the corresponding interrupt is configured to be edge sensitive in its IRNCFG register. */
#define GPIO_EXINTCR1_P0 0x00000001
/* Single edge
#define GPIO_EXINTCR1_P0_SGL 0x00000000 */
/** Both edges */
#define GPIO_EXINTCR1_P0_BOTH 0x00000001

/* Fields of "IRN Capture Register" */
/** P24 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P24 0x01000000
/* Nothing
#define GPIO_IRNCR_P24_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P24_INTACK 0x01000000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P24_INTOCC 0x01000000
/** P23 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P23 0x00800000
/* Nothing
#define GPIO_IRNCR_P23_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P23_INTACK 0x00800000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P23_INTOCC 0x00800000
/** P22 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P22 0x00400000
/* Nothing
#define GPIO_IRNCR_P22_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P22_INTACK 0x00400000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P22_INTOCC 0x00400000
/** P21 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P21 0x00200000
/* Nothing
#define GPIO_IRNCR_P21_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P21_INTACK 0x00200000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P21_INTOCC 0x00200000
/** P20 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P20 0x00100000
/* Nothing
#define GPIO_IRNCR_P20_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P20_INTACK 0x00100000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P20_INTOCC 0x00100000
/** P19 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P19 0x00080000
/* Nothing
#define GPIO_IRNCR_P19_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P19_INTACK 0x00080000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P19_INTOCC 0x00080000
/** P18 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P18 0x00040000
/* Nothing
#define GPIO_IRNCR_P18_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P18_INTACK 0x00040000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P18_INTOCC 0x00040000
/** P17 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P17 0x00020000
/* Nothing
#define GPIO_IRNCR_P17_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P17_INTACK 0x00020000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P17_INTOCC 0x00020000
/** P16 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P16 0x00010000
/* Nothing
#define GPIO_IRNCR_P16_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P16_INTACK 0x00010000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P16_INTOCC 0x00010000
/** P15 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P15 0x00008000
/* Nothing
#define GPIO_IRNCR_P15_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P15_INTACK 0x00008000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P15_INTOCC 0x00008000
/** P14 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P14 0x00004000
/* Nothing
#define GPIO_IRNCR_P14_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P14_INTACK 0x00004000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P14_INTOCC 0x00004000
/** P13 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P13 0x00002000
/* Nothing
#define GPIO_IRNCR_P13_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P13_INTACK 0x00002000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P13_INTOCC 0x00002000
/** P12 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P12 0x00001000
/* Nothing
#define GPIO_IRNCR_P12_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P12_INTACK 0x00001000
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P12_INTOCC 0x00001000
/** P11 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P11 0x00000800
/* Nothing
#define GPIO_IRNCR_P11_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P11_INTACK 0x00000800
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P11_INTOCC 0x00000800
/** P10 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P10 0x00000400
/* Nothing
#define GPIO_IRNCR_P10_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P10_INTACK 0x00000400
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P10_INTOCC 0x00000400
/** P9 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P9 0x00000200
/* Nothing
#define GPIO_IRNCR_P9_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P9_INTACK 0x00000200
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P9_INTOCC 0x00000200
/** P8 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P8 0x00000100
/* Nothing
#define GPIO_IRNCR_P8_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P8_INTACK 0x00000100
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P8_INTOCC 0x00000100
/** P7 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P7 0x00000080
/* Nothing
#define GPIO_IRNCR_P7_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P7_INTACK 0x00000080
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P7_INTOCC 0x00000080
/** P6 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P6 0x00000040
/* Nothing
#define GPIO_IRNCR_P6_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P6_INTACK 0x00000040
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P6_INTOCC 0x00000040
/** P5 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P5 0x00000020
/* Nothing
#define GPIO_IRNCR_P5_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P5_INTACK 0x00000020
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P5_INTOCC 0x00000020
/** P4 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P4 0x00000010
/* Nothing
#define GPIO_IRNCR_P4_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P4_INTACK 0x00000010
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P4_INTOCC 0x00000010
/** P3 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P3 0x00000008
/* Nothing
#define GPIO_IRNCR_P3_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P3_INTACK 0x00000008
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P3_INTOCC 0x00000008
/** P2 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P2 0x00000004
/* Nothing
#define GPIO_IRNCR_P2_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P2_INTACK 0x00000004
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P2_INTOCC 0x00000004
/** P1 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P1 0x00000002
/* Nothing
#define GPIO_IRNCR_P1_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P1_INTACK 0x00000002
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P1_INTOCC 0x00000002
/** P0 Interrupt
    This bit is configurable to be either level- or edge-sensitive. This bit contributes to the indirect interrupt. */
#define GPIO_IRNCR_P0 0x00000001
/* Nothing
#define GPIO_IRNCR_P0_NULL 0x00000000 */
/** Write: Acknowledge the interrupt. */
#define GPIO_IRNCR_P0_INTACK 0x00000001
/** Read: Interrupt occurred. */
#define GPIO_IRNCR_P0_INTOCC 0x00000001

/* Fields of "IRN Interrupt Control Register" */
/** P24 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P24 0x01000000
/** P23 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P23 0x00800000
/** P22 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P22 0x00400000
/** P21 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P21 0x00200000
/** P20 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P20 0x00100000
/** P19 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P19 0x00080000
/** P18 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P18 0x00040000
/** P17 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P17 0x00020000
/** P16 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P16 0x00010000
/** P15 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P15 0x00008000
/** P14 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P14 0x00004000
/** P13 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P13 0x00002000
/** P12 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P12 0x00001000
/** P11 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P11 0x00000800
/** P10 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P10 0x00000400
/** P9 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P9 0x00000200
/** P8 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P8 0x00000100
/** P7 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P7 0x00000080
/** P6 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P6 0x00000040
/** P5 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P5 0x00000020
/** P4 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P4 0x00000010
/** P3 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P3 0x00000008
/** P2 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P2 0x00000004
/** P1 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P1 0x00000002
/** P0 Interrupt
    Interrupt control bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNICR_P0 0x00000001

/* Fields of "IRN Interrupt Enable Register" */
/** P24 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P24 0x01000000
/* Disable
#define GPIO_IRNEN_P24_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P24_EN 0x01000000
/** P23 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P23 0x00800000
/* Disable
#define GPIO_IRNEN_P23_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P23_EN 0x00800000
/** P22 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P22 0x00400000
/* Disable
#define GPIO_IRNEN_P22_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P22_EN 0x00400000
/** P21 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P21 0x00200000
/* Disable
#define GPIO_IRNEN_P21_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P21_EN 0x00200000
/** P20 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P20 0x00100000
/* Disable
#define GPIO_IRNEN_P20_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P20_EN 0x00100000
/** P19 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P19 0x00080000
/* Disable
#define GPIO_IRNEN_P19_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P19_EN 0x00080000
/** P18 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P18 0x00040000
/* Disable
#define GPIO_IRNEN_P18_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P18_EN 0x00040000
/** P17 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P17 0x00020000
/* Disable
#define GPIO_IRNEN_P17_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P17_EN 0x00020000
/** P16 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P16 0x00010000
/* Disable
#define GPIO_IRNEN_P16_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P16_EN 0x00010000
/** P15 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P15 0x00008000
/* Disable
#define GPIO_IRNEN_P15_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P15_EN 0x00008000
/** P14 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P14 0x00004000
/* Disable
#define GPIO_IRNEN_P14_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P14_EN 0x00004000
/** P13 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P13 0x00002000
/* Disable
#define GPIO_IRNEN_P13_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P13_EN 0x00002000
/** P12 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P12 0x00001000
/* Disable
#define GPIO_IRNEN_P12_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P12_EN 0x00001000
/** P11 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P11 0x00000800
/* Disable
#define GPIO_IRNEN_P11_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P11_EN 0x00000800
/** P10 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P10 0x00000400
/* Disable
#define GPIO_IRNEN_P10_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P10_EN 0x00000400
/** P9 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P9 0x00000200
/* Disable
#define GPIO_IRNEN_P9_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P9_EN 0x00000200
/** P8 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P8 0x00000100
/* Disable
#define GPIO_IRNEN_P8_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P8_EN 0x00000100
/** P7 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P7 0x00000080
/* Disable
#define GPIO_IRNEN_P7_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P7_EN 0x00000080
/** P6 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P6 0x00000040
/* Disable
#define GPIO_IRNEN_P6_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P6_EN 0x00000040
/** P5 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P5 0x00000020
/* Disable
#define GPIO_IRNEN_P5_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P5_EN 0x00000020
/** P4 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P4 0x00000010
/* Disable
#define GPIO_IRNEN_P4_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P4_EN 0x00000010
/** P3 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P3 0x00000008
/* Disable
#define GPIO_IRNEN_P3_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P3_EN 0x00000008
/** P2 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P2 0x00000004
/* Disable
#define GPIO_IRNEN_P2_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P2_EN 0x00000004
/** P1 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P1 0x00000002
/* Disable
#define GPIO_IRNEN_P1_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P1_EN 0x00000002
/** P0 Interrupt
    Interrupt enable bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNEN_P0 0x00000001
/* Disable
#define GPIO_IRNEN_P0_DIS 0x00000000 */
/** Enable */
#define GPIO_IRNEN_P0_EN 0x00000001

/* Fields of "IRN Interrupt Configuration Register" */
/** P24 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P24 0x01000000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P24_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P24_LEVEL 0x01000000
/** P23 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P23 0x00800000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P23_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P23_LEVEL 0x00800000
/** P22 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P22 0x00400000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P22_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P22_LEVEL 0x00400000
/** P21 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P21 0x00200000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P21_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P21_LEVEL 0x00200000
/** P20 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P20 0x00100000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P20_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P20_LEVEL 0x00100000
/** P19 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P19 0x00080000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P19_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P19_LEVEL 0x00080000
/** P18 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P18 0x00040000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P18_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P18_LEVEL 0x00040000
/** P17 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P17 0x00020000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P17_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P17_LEVEL 0x00020000
/** P16 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P16 0x00010000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P16_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P16_LEVEL 0x00010000
/** P15 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P15 0x00008000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P15_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P15_LEVEL 0x00008000
/** P14 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P14 0x00004000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P14_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P14_LEVEL 0x00004000
/** P13 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P13 0x00002000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P13_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P13_LEVEL 0x00002000
/** P12 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P12 0x00001000
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P12_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P12_LEVEL 0x00001000
/** P11 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P11 0x00000800
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P11_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P11_LEVEL 0x00000800
/** P10 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P10 0x00000400
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P10_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P10_LEVEL 0x00000400
/** P9 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P9 0x00000200
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P9_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P9_LEVEL 0x00000200
/** P8 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P8 0x00000100
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P8_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P8_LEVEL 0x00000100
/** P7 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P7 0x00000080
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P7_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P7_LEVEL 0x00000080
/** P6 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P6 0x00000040
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P6_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P6_LEVEL 0x00000040
/** P5 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P5 0x00000020
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P5_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P5_LEVEL 0x00000020
/** P4 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P4 0x00000010
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P4_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P4_LEVEL 0x00000010
/** P3 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P3 0x00000008
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P3_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P3_LEVEL 0x00000008
/** P2 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P2 0x00000004
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P2_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P2_LEVEL 0x00000004
/** P1 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P1 0x00000002
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P1_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P1_LEVEL 0x00000002
/** P0 Interrupt
    Interrupt configuration bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNCFG_P0 0x00000001
/* Interrupt is edge-sensitive
#define GPIO_IRNCFG_P0_EDGE 0x00000000 */
/** Interrupt is level-sensitive */
#define GPIO_IRNCFG_P0_LEVEL 0x00000001

/* Fields of "IRN Interrupt Enable Set Register" */
/** P24 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P24 0x01000000
/* Nothing
#define GPIO_IRNENSET_P24_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P24_SET 0x01000000
/** P23 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P23 0x00800000
/* Nothing
#define GPIO_IRNENSET_P23_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P23_SET 0x00800000
/** P22 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P22 0x00400000
/* Nothing
#define GPIO_IRNENSET_P22_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P22_SET 0x00400000
/** P21 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P21 0x00200000
/* Nothing
#define GPIO_IRNENSET_P21_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P21_SET 0x00200000
/** P20 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P20 0x00100000
/* Nothing
#define GPIO_IRNENSET_P20_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P20_SET 0x00100000
/** P19 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P19 0x00080000
/* Nothing
#define GPIO_IRNENSET_P19_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P19_SET 0x00080000
/** P18 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P18 0x00040000
/* Nothing
#define GPIO_IRNENSET_P18_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P18_SET 0x00040000
/** P17 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P17 0x00020000
/* Nothing
#define GPIO_IRNENSET_P17_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P17_SET 0x00020000
/** P16 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P16 0x00010000
/* Nothing
#define GPIO_IRNENSET_P16_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P16_SET 0x00010000
/** P15 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P15 0x00008000
/* Nothing
#define GPIO_IRNENSET_P15_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P15_SET 0x00008000
/** P14 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P14 0x00004000
/* Nothing
#define GPIO_IRNENSET_P14_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P14_SET 0x00004000
/** P13 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P13 0x00002000
/* Nothing
#define GPIO_IRNENSET_P13_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P13_SET 0x00002000
/** P12 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P12 0x00001000
/* Nothing
#define GPIO_IRNENSET_P12_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P12_SET 0x00001000
/** P11 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P11 0x00000800
/* Nothing
#define GPIO_IRNENSET_P11_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P11_SET 0x00000800
/** P10 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P10 0x00000400
/* Nothing
#define GPIO_IRNENSET_P10_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P10_SET 0x00000400
/** P9 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P9 0x00000200
/* Nothing
#define GPIO_IRNENSET_P9_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P9_SET 0x00000200
/** P8 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P8 0x00000100
/* Nothing
#define GPIO_IRNENSET_P8_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P8_SET 0x00000100
/** P7 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P7 0x00000080
/* Nothing
#define GPIO_IRNENSET_P7_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P7_SET 0x00000080
/** P6 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P6 0x00000040
/* Nothing
#define GPIO_IRNENSET_P6_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P6_SET 0x00000040
/** P5 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P5 0x00000020
/* Nothing
#define GPIO_IRNENSET_P5_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P5_SET 0x00000020
/** P4 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P4 0x00000010
/* Nothing
#define GPIO_IRNENSET_P4_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P4_SET 0x00000010
/** P3 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P3 0x00000008
/* Nothing
#define GPIO_IRNENSET_P3_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P3_SET 0x00000008
/** P2 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P2 0x00000004
/* Nothing
#define GPIO_IRNENSET_P2_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P2_SET 0x00000004
/** P1 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P1 0x00000002
/* Nothing
#define GPIO_IRNENSET_P1_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P1_SET 0x00000002
/** P0 Interrupt
    Interrupt-enable set bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENSET_P0 0x00000001
/* Nothing
#define GPIO_IRNENSET_P0_NULL 0x00000000 */
/** Set */
#define GPIO_IRNENSET_P0_SET 0x00000001

/* Fields of "IRN Interrupt Enable Clear Register" */
/** P24 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P24 0x01000000
/* Nothing
#define GPIO_IRNENCLR_P24_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P24_CLR 0x01000000
/** P23 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P23 0x00800000
/* Nothing
#define GPIO_IRNENCLR_P23_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P23_CLR 0x00800000
/** P22 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P22 0x00400000
/* Nothing
#define GPIO_IRNENCLR_P22_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P22_CLR 0x00400000
/** P21 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P21 0x00200000
/* Nothing
#define GPIO_IRNENCLR_P21_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P21_CLR 0x00200000
/** P20 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P20 0x00100000
/* Nothing
#define GPIO_IRNENCLR_P20_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P20_CLR 0x00100000
/** P19 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P19 0x00080000
/* Nothing
#define GPIO_IRNENCLR_P19_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P19_CLR 0x00080000
/** P18 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P18 0x00040000
/* Nothing
#define GPIO_IRNENCLR_P18_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P18_CLR 0x00040000
/** P17 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P17 0x00020000
/* Nothing
#define GPIO_IRNENCLR_P17_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P17_CLR 0x00020000
/** P16 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P16 0x00010000
/* Nothing
#define GPIO_IRNENCLR_P16_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P16_CLR 0x00010000
/** P15 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P15 0x00008000
/* Nothing
#define GPIO_IRNENCLR_P15_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P15_CLR 0x00008000
/** P14 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P14 0x00004000
/* Nothing
#define GPIO_IRNENCLR_P14_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P14_CLR 0x00004000
/** P13 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P13 0x00002000
/* Nothing
#define GPIO_IRNENCLR_P13_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P13_CLR 0x00002000
/** P12 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P12 0x00001000
/* Nothing
#define GPIO_IRNENCLR_P12_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P12_CLR 0x00001000
/** P11 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P11 0x00000800
/* Nothing
#define GPIO_IRNENCLR_P11_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P11_CLR 0x00000800
/** P10 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P10 0x00000400
/* Nothing
#define GPIO_IRNENCLR_P10_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P10_CLR 0x00000400
/** P9 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P9 0x00000200
/* Nothing
#define GPIO_IRNENCLR_P9_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P9_CLR 0x00000200
/** P8 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P8 0x00000100
/* Nothing
#define GPIO_IRNENCLR_P8_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P8_CLR 0x00000100
/** P7 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P7 0x00000080
/* Nothing
#define GPIO_IRNENCLR_P7_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P7_CLR 0x00000080
/** P6 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P6 0x00000040
/* Nothing
#define GPIO_IRNENCLR_P6_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P6_CLR 0x00000040
/** P5 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P5 0x00000020
/* Nothing
#define GPIO_IRNENCLR_P5_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P5_CLR 0x00000020
/** P4 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P4 0x00000010
/* Nothing
#define GPIO_IRNENCLR_P4_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P4_CLR 0x00000010
/** P3 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P3 0x00000008
/* Nothing
#define GPIO_IRNENCLR_P3_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P3_CLR 0x00000008
/** P2 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P2 0x00000004
/* Nothing
#define GPIO_IRNENCLR_P2_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P2_CLR 0x00000004
/** P1 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P1 0x00000002
/* Nothing
#define GPIO_IRNENCLR_P1_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P1_CLR 0x00000002
/** P0 Interrupt
    Interrupt-enable clear bit for the corresponding bit in the IRNCR register. */
#define GPIO_IRNENCLR_P0 0x00000001
/* Nothing
#define GPIO_IRNENCLR_P0_NULL 0x00000000 */
/** Clear */
#define GPIO_IRNENCLR_P0_CLR 0x00000001

/* Fields of "Output Set Register" */
/** Bit 24 Output Set */
#define GPIO_OUTSET_P24 0x01000000
/* No-Operation
#define GPIO_OUTSET_P24_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P24_SET 0x01000000
/** Bit 23 Output Set */
#define GPIO_OUTSET_P23 0x00800000
/* No-Operation
#define GPIO_OUTSET_P23_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P23_SET 0x00800000
/** Bit 22 Output Set */
#define GPIO_OUTSET_P22 0x00400000
/* No-Operation
#define GPIO_OUTSET_P22_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P22_SET 0x00400000
/** Bit 21 Output Set */
#define GPIO_OUTSET_P21 0x00200000
/* No-Operation
#define GPIO_OUTSET_P21_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P21_SET 0x00200000
/** Bit 20 Output Set */
#define GPIO_OUTSET_P20 0x00100000
/* No-Operation
#define GPIO_OUTSET_P20_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P20_SET 0x00100000
/** Bit 19 Output Set */
#define GPIO_OUTSET_P19 0x00080000
/* No-Operation
#define GPIO_OUTSET_P19_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P19_SET 0x00080000
/** Bit 18 Output Set */
#define GPIO_OUTSET_P18 0x00040000
/* No-Operation
#define GPIO_OUTSET_P18_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P18_SET 0x00040000
/** Bit 17 Output Set */
#define GPIO_OUTSET_P17 0x00020000
/* No-Operation
#define GPIO_OUTSET_P17_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P17_SET 0x00020000
/** Bit 16 Output Set */
#define GPIO_OUTSET_P16 0x00010000
/* No-Operation
#define GPIO_OUTSET_P16_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P16_SET 0x00010000
/** Bit 15 Output Set */
#define GPIO_OUTSET_P15 0x00008000
/* No-Operation
#define GPIO_OUTSET_P15_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P15_SET 0x00008000
/** Bit 14 Output Set */
#define GPIO_OUTSET_P14 0x00004000
/* No-Operation
#define GPIO_OUTSET_P14_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P14_SET 0x00004000
/** Bit 13 Output Set */
#define GPIO_OUTSET_P13 0x00002000
/* No-Operation
#define GPIO_OUTSET_P13_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P13_SET 0x00002000
/** Bit 12 Output Set */
#define GPIO_OUTSET_P12 0x00001000
/* No-Operation
#define GPIO_OUTSET_P12_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P12_SET 0x00001000
/** Bit 11 Output Set */
#define GPIO_OUTSET_P11 0x00000800
/* No-Operation
#define GPIO_OUTSET_P11_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P11_SET 0x00000800
/** Bit 10 Output Set */
#define GPIO_OUTSET_P10 0x00000400
/* No-Operation
#define GPIO_OUTSET_P10_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P10_SET 0x00000400
/** Bit 9 Output Set */
#define GPIO_OUTSET_P9 0x00000200
/* No-Operation
#define GPIO_OUTSET_P9_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P9_SET 0x00000200
/** Bit 8 Output Set */
#define GPIO_OUTSET_P8 0x00000100
/* No-Operation
#define GPIO_OUTSET_P8_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P8_SET 0x00000100
/** Bit 7 Output Set */
#define GPIO_OUTSET_P7 0x00000080
/* No-Operation
#define GPIO_OUTSET_P7_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P7_SET 0x00000080
/** Bit 6 Output Set */
#define GPIO_OUTSET_P6 0x00000040
/* No-Operation
#define GPIO_OUTSET_P6_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P6_SET 0x00000040
/** Bit 5 Output Set */
#define GPIO_OUTSET_P5 0x00000020
/* No-Operation
#define GPIO_OUTSET_P5_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P5_SET 0x00000020
/** Bit 4 Output Set */
#define GPIO_OUTSET_P4 0x00000010
/* No-Operation
#define GPIO_OUTSET_P4_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P4_SET 0x00000010
/** Bit 3 Output Set */
#define GPIO_OUTSET_P3 0x00000008
/* No-Operation
#define GPIO_OUTSET_P3_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P3_SET 0x00000008
/** Bit 2 Output Set */
#define GPIO_OUTSET_P2 0x00000004
/* No-Operation
#define GPIO_OUTSET_P2_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P2_SET 0x00000004
/** Bit 1 Output Set */
#define GPIO_OUTSET_P1 0x00000002
/* No-Operation
#define GPIO_OUTSET_P1_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P1_SET 0x00000002
/** Bit 0 Output Set */
#define GPIO_OUTSET_P0 0x00000001
/* No-Operation
#define GPIO_OUTSET_P0_NOP 0x00000000 */
/** Set */
#define GPIO_OUTSET_P0_SET 0x00000001

/* Fields of "Output Clear Register" */
/** Bit 24 Output Clear */
#define GPIO_OUTCLR_P24 0x01000000
/* No-Operation
#define GPIO_OUTCLR_P24_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P24_CLR 0x01000000
/** Bit 23 Output Clear */
#define GPIO_OUTCLR_P23 0x00800000
/* No-Operation
#define GPIO_OUTCLR_P23_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P23_CLR 0x00800000
/** Bit 22 Output Clear */
#define GPIO_OUTCLR_P22 0x00400000
/* No-Operation
#define GPIO_OUTCLR_P22_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P22_CLR 0x00400000
/** Bit 21 Output Clear */
#define GPIO_OUTCLR_P21 0x00200000
/* No-Operation
#define GPIO_OUTCLR_P21_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P21_CLR 0x00200000
/** Bit 20 Output Clear */
#define GPIO_OUTCLR_P20 0x00100000
/* No-Operation
#define GPIO_OUTCLR_P20_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P20_CLR 0x00100000
/** Bit 19 Output Clear */
#define GPIO_OUTCLR_P19 0x00080000
/* No-Operation
#define GPIO_OUTCLR_P19_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P19_CLR 0x00080000
/** Bit 18 Output Clear */
#define GPIO_OUTCLR_P18 0x00040000
/* No-Operation
#define GPIO_OUTCLR_P18_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P18_CLR 0x00040000
/** Bit 17 Output Clear */
#define GPIO_OUTCLR_P17 0x00020000
/* No-Operation
#define GPIO_OUTCLR_P17_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P17_CLR 0x00020000
/** Bit 16 Output Clear */
#define GPIO_OUTCLR_P16 0x00010000
/* No-Operation
#define GPIO_OUTCLR_P16_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P16_CLR 0x00010000
/** Bit 15 Output Clear */
#define GPIO_OUTCLR_P15 0x00008000
/* No-Operation
#define GPIO_OUTCLR_P15_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P15_CLR 0x00008000
/** Bit 14 Output Clear */
#define GPIO_OUTCLR_P14 0x00004000
/* No-Operation
#define GPIO_OUTCLR_P14_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P14_CLR 0x00004000
/** Bit 13 Output Clear */
#define GPIO_OUTCLR_P13 0x00002000
/* No-Operation
#define GPIO_OUTCLR_P13_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P13_CLR 0x00002000
/** Bit 12 Output Clear */
#define GPIO_OUTCLR_P12 0x00001000
/* No-Operation
#define GPIO_OUTCLR_P12_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P12_CLR 0x00001000
/** Bit 11 Output Clear */
#define GPIO_OUTCLR_P11 0x00000800
/* No-Operation
#define GPIO_OUTCLR_P11_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P11_CLR 0x00000800
/** Bit 10 Output Clear */
#define GPIO_OUTCLR_P10 0x00000400
/* No-Operation
#define GPIO_OUTCLR_P10_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P10_CLR 0x00000400
/** Bit 9 Output Clear */
#define GPIO_OUTCLR_P9 0x00000200
/* No-Operation
#define GPIO_OUTCLR_P9_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P9_CLR 0x00000200
/** Bit 8 Output Clear */
#define GPIO_OUTCLR_P8 0x00000100
/* No-Operation
#define GPIO_OUTCLR_P8_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P8_CLR 0x00000100
/** Bit 7 Output Clear */
#define GPIO_OUTCLR_P7 0x00000080
/* No-Operation
#define GPIO_OUTCLR_P7_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P7_CLR 0x00000080
/** Bit 6 Output Clear */
#define GPIO_OUTCLR_P6 0x00000040
/* No-Operation
#define GPIO_OUTCLR_P6_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P6_CLR 0x00000040
/** Bit 5 Output Clear */
#define GPIO_OUTCLR_P5 0x00000020
/* No-Operation
#define GPIO_OUTCLR_P5_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P5_CLR 0x00000020
/** Bit 4 Output Clear */
#define GPIO_OUTCLR_P4 0x00000010
/* No-Operation
#define GPIO_OUTCLR_P4_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P4_CLR 0x00000010
/** Bit 3 Output Clear */
#define GPIO_OUTCLR_P3 0x00000008
/* No-Operation
#define GPIO_OUTCLR_P3_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P3_CLR 0x00000008
/** Bit 2 Output Clear */
#define GPIO_OUTCLR_P2 0x00000004
/* No-Operation
#define GPIO_OUTCLR_P2_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P2_CLR 0x00000004
/** Bit 1 Output Clear */
#define GPIO_OUTCLR_P1 0x00000002
/* No-Operation
#define GPIO_OUTCLR_P1_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P1_CLR 0x00000002
/** Bit 0 Output Clear */
#define GPIO_OUTCLR_P0 0x00000001
/* No-Operation
#define GPIO_OUTCLR_P0_NOP 0x00000000 */
/** Clear */
#define GPIO_OUTCLR_P0_CLR 0x00000001

/* Fields of "Direction Set Register" */
/** Bit 24 Direction Set */
#define GPIO_DIRSET_P24 0x01000000
/* No-Operation
#define GPIO_DIRSET_P24_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P24_SET 0x01000000
/** Bit 23 Direction Set */
#define GPIO_DIRSET_P23 0x00800000
/* No-Operation
#define GPIO_DIRSET_P23_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P23_SET 0x00800000
/** Bit 22 Direction Set */
#define GPIO_DIRSET_P22 0x00400000
/* No-Operation
#define GPIO_DIRSET_P22_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P22_SET 0x00400000
/** Bit 21 Direction Set */
#define GPIO_DIRSET_P21 0x00200000
/* No-Operation
#define GPIO_DIRSET_P21_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P21_SET 0x00200000
/** Bit 20 Direction Set */
#define GPIO_DIRSET_P20 0x00100000
/* No-Operation
#define GPIO_DIRSET_P20_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P20_SET 0x00100000
/** Bit 19 Direction Set */
#define GPIO_DIRSET_P19 0x00080000
/* No-Operation
#define GPIO_DIRSET_P19_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P19_SET 0x00080000
/** Bit 18 Direction Set */
#define GPIO_DIRSET_P18 0x00040000
/* No-Operation
#define GPIO_DIRSET_P18_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P18_SET 0x00040000
/** Bit 17 Direction Set */
#define GPIO_DIRSET_P17 0x00020000
/* No-Operation
#define GPIO_DIRSET_P17_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P17_SET 0x00020000
/** Bit 16 Direction Set */
#define GPIO_DIRSET_P16 0x00010000
/* No-Operation
#define GPIO_DIRSET_P16_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P16_SET 0x00010000
/** Bit 15 Direction Set */
#define GPIO_DIRSET_P15 0x00008000
/* No-Operation
#define GPIO_DIRSET_P15_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P15_SET 0x00008000
/** Bit 14 Direction Set */
#define GPIO_DIRSET_P14 0x00004000
/* No-Operation
#define GPIO_DIRSET_P14_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P14_SET 0x00004000
/** Bit 13 Direction Set */
#define GPIO_DIRSET_P13 0x00002000
/* No-Operation
#define GPIO_DIRSET_P13_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P13_SET 0x00002000
/** Bit 12 Direction Set */
#define GPIO_DIRSET_P12 0x00001000
/* No-Operation
#define GPIO_DIRSET_P12_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P12_SET 0x00001000
/** Bit 11 Direction Set */
#define GPIO_DIRSET_P11 0x00000800
/* No-Operation
#define GPIO_DIRSET_P11_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P11_SET 0x00000800
/** Bit 10 Direction Set */
#define GPIO_DIRSET_P10 0x00000400
/* No-Operation
#define GPIO_DIRSET_P10_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P10_SET 0x00000400
/** Bit 9 Direction Set */
#define GPIO_DIRSET_P9 0x00000200
/* No-Operation
#define GPIO_DIRSET_P9_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P9_SET 0x00000200
/** Bit 8 Direction Set */
#define GPIO_DIRSET_P8 0x00000100
/* No-Operation
#define GPIO_DIRSET_P8_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P8_SET 0x00000100
/** Bit 7 Direction Set */
#define GPIO_DIRSET_P7 0x00000080
/* No-Operation
#define GPIO_DIRSET_P7_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P7_SET 0x00000080
/** Bit 6 Direction Set */
#define GPIO_DIRSET_P6 0x00000040
/* No-Operation
#define GPIO_DIRSET_P6_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P6_SET 0x00000040
/** Bit 5 Direction Set */
#define GPIO_DIRSET_P5 0x00000020
/* No-Operation
#define GPIO_DIRSET_P5_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P5_SET 0x00000020
/** Bit 4 Direction Set */
#define GPIO_DIRSET_P4 0x00000010
/* No-Operation
#define GPIO_DIRSET_P4_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P4_SET 0x00000010
/** Bit 3 Direction Set */
#define GPIO_DIRSET_P3 0x00000008
/* No-Operation
#define GPIO_DIRSET_P3_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P3_SET 0x00000008
/** Bit 2 Direction Set */
#define GPIO_DIRSET_P2 0x00000004
/* No-Operation
#define GPIO_DIRSET_P2_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P2_SET 0x00000004
/** Bit 1 Direction Set */
#define GPIO_DIRSET_P1 0x00000002
/* No-Operation
#define GPIO_DIRSET_P1_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P1_SET 0x00000002
/** Bit 0 Direction Set */
#define GPIO_DIRSET_P0 0x00000001
/* No-Operation
#define GPIO_DIRSET_P0_NOP 0x00000000 */
/** Set */
#define GPIO_DIRSET_P0_SET 0x00000001

/* Fields of "Direction Clear Register" */
/** Bit 24 Direction Clear */
#define GPIO_DIRCLR_P24 0x01000000
/* No-Operation
#define GPIO_DIRCLR_P24_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P24_CLR 0x01000000
/** Bit 23 Direction Clear */
#define GPIO_DIRCLR_P23 0x00800000
/* No-Operation
#define GPIO_DIRCLR_P23_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P23_CLR 0x00800000
/** Bit 22 Direction Clear */
#define GPIO_DIRCLR_P22 0x00400000
/* No-Operation
#define GPIO_DIRCLR_P22_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P22_CLR 0x00400000
/** Bit 21 Direction Clear */
#define GPIO_DIRCLR_P21 0x00200000
/* No-Operation
#define GPIO_DIRCLR_P21_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P21_CLR 0x00200000
/** Bit 20 Direction Clear */
#define GPIO_DIRCLR_P20 0x00100000
/* No-Operation
#define GPIO_DIRCLR_P20_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P20_CLR 0x00100000
/** Bit 19 Direction Clear */
#define GPIO_DIRCLR_P19 0x00080000
/* No-Operation
#define GPIO_DIRCLR_P19_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P19_CLR 0x00080000
/** Bit 18 Direction Clear */
#define GPIO_DIRCLR_P18 0x00040000
/* No-Operation
#define GPIO_DIRCLR_P18_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P18_CLR 0x00040000
/** Bit 17 Direction Clear */
#define GPIO_DIRCLR_P17 0x00020000
/* No-Operation
#define GPIO_DIRCLR_P17_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P17_CLR 0x00020000
/** Bit 16 Direction Clear */
#define GPIO_DIRCLR_P16 0x00010000
/* No-Operation
#define GPIO_DIRCLR_P16_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P16_CLR 0x00010000
/** Bit 15 Direction Clear */
#define GPIO_DIRCLR_P15 0x00008000
/* No-Operation
#define GPIO_DIRCLR_P15_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P15_CLR 0x00008000
/** Bit 14 Direction Clear */
#define GPIO_DIRCLR_P14 0x00004000
/* No-Operation
#define GPIO_DIRCLR_P14_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P14_CLR 0x00004000
/** Bit 13 Direction Clear */
#define GPIO_DIRCLR_P13 0x00002000
/* No-Operation
#define GPIO_DIRCLR_P13_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P13_CLR 0x00002000
/** Bit 12 Direction Clear */
#define GPIO_DIRCLR_P12 0x00001000
/* No-Operation
#define GPIO_DIRCLR_P12_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P12_CLR 0x00001000
/** Bit 11 Direction Clear */
#define GPIO_DIRCLR_P11 0x00000800
/* No-Operation
#define GPIO_DIRCLR_P11_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P11_CLR 0x00000800
/** Bit 10 Direction Clear */
#define GPIO_DIRCLR_P10 0x00000400
/* No-Operation
#define GPIO_DIRCLR_P10_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P10_CLR 0x00000400
/** Bit 9 Direction Clear */
#define GPIO_DIRCLR_P9 0x00000200
/* No-Operation
#define GPIO_DIRCLR_P9_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P9_CLR 0x00000200
/** Bit 8 Direction Clear */
#define GPIO_DIRCLR_P8 0x00000100
/* No-Operation
#define GPIO_DIRCLR_P8_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P8_CLR 0x00000100
/** Bit 7 Direction Clear */
#define GPIO_DIRCLR_P7 0x00000080
/* No-Operation
#define GPIO_DIRCLR_P7_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P7_CLR 0x00000080
/** Bit 6 Direction Clear */
#define GPIO_DIRCLR_P6 0x00000040
/* No-Operation
#define GPIO_DIRCLR_P6_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P6_CLR 0x00000040
/** Bit 5 Direction Clear */
#define GPIO_DIRCLR_P5 0x00000020
/* No-Operation
#define GPIO_DIRCLR_P5_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P5_CLR 0x00000020
/** Bit 4 Direction Clear */
#define GPIO_DIRCLR_P4 0x00000010
/* No-Operation
#define GPIO_DIRCLR_P4_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P4_CLR 0x00000010
/** Bit 3 Direction Clear */
#define GPIO_DIRCLR_P3 0x00000008
/* No-Operation
#define GPIO_DIRCLR_P3_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P3_CLR 0x00000008
/** Bit 2 Direction Clear */
#define GPIO_DIRCLR_P2 0x00000004
/* No-Operation
#define GPIO_DIRCLR_P2_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P2_CLR 0x00000004
/** Bit 1 Direction Clear */
#define GPIO_DIRCLR_P1 0x00000002
/* No-Operation
#define GPIO_DIRCLR_P1_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P1_CLR 0x00000002
/** Bit 0 Direction Clear */
#define GPIO_DIRCLR_P0 0x00000001
/* No-Operation
#define GPIO_DIRCLR_P0_NOP 0x00000000 */
/** Clear */
#define GPIO_DIRCLR_P0_CLR 0x00000001

/*! @} */ /* GPIO_REGISTER */

#endif /* _gpio_reg_h */
