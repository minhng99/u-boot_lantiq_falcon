/*
 * (C) Copyright 2011
 * Thomas Langer, Lantiq Deutschland GmbH, http://www.lantiq.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
#define DEBUG
#define DEBUG_GPIO
*/
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>
#include <asm/arch/dcdc_reg.h>

#define DCDC_V1_0_SELECTION	3

static struct gpon_reg_dcdc * const dcdc_core = (struct gpon_reg_dcdc *)GPON_DCDC_CORE_BASE;
static struct gpon_reg_dcdc * const dcdc_ddr = (struct gpon_reg_dcdc *)GPON_DCDC_DDR_BASE;

DECLARE_GLOBAL_DATA_PTR;

#ifdef DEBUG_GPIO
#include <asm/gpio.h>
#define DEBUG_GPIO_NR	1
static void setup_debug_gpio(int value)
{
	gpio_request(DEBUG_GPIO_NR, "dcdc debug");
	gpio_direction_output(DEBUG_GPIO_NR, value);
}
static void cleanup_debug_gpio(void)
{
	gpio_direction_input(DEBUG_GPIO_NR);
	gpio_free(DEBUG_GPIO_NR);
}
static void set_debug_gpio(int value)
{
	gpio_set_value(DEBUG_GPIO_NR, value);
}
#else
static void setup_debug_gpio(int value) {}
static void cleanup_debug_gpio(void) {}
static void set_debug_gpio(int value ) {}
#endif

/**
 * Calculate coefficients for dcdc controller
 * @param[in]	L	Inductance in nH
 * @param[in]	C	Capacity in uF
 * @param[in]	fsw	frequency in kHz
 * @param	b0	returns b0 coefficient
 * @param	b1	returns b1 coefficient
 * @param	b2	returns b2 coefficient
 * @return
 * 	0	on success
 * 	-1	on error
 */
static int calc_dcdc_coeff(int L, int C, uint fsw,
	uint16_t *b0, uint16_t *b1, uint16_t *b2)
{
	/** \todo calculate these coefficients */
	if ((L==4700) && (C==22) && (fsw==977)) {
		/* L=4.7uH, C=22uF, fsw=0.977MHz */
		*b0 = 0x0181;
		*b1 = 0xFCEA;
		*b2 = 0x0198;
	} else if ((L==1500) && (C==166) && (fsw==977)) {
		/* L=1.5uH,C=166uF, fsw=0.977MHz */
		*b0 = 0x0256;
		*b1 = 0xFB41;
		*b2 = 0x026C;
	} else {
		printf("No DCDC coefficients for L=%d.%03duH, C=%duF, "
			"fsw=%d.%03dMHz\n",
			L/1000, L%1000, C, fsw/1000, fsw%1000);
		return -1;
	}
	return 0;
}

/**
 * update voltage reference (dig_ref)
 *
 * @param voltage	target voltage in mV
 * @return none
 */
void falcon_dcdc_core_set_voltage(unsigned int voltage)
{
	uint8_t dig_ref, offset_fuse;
	int8_t offset;

	offset_fuse = (status_r32(fuse1) & STATUS_FUSE1_OFFSET1V0DCDC_MASK)
		>> STATUS_FUSE1_OFFSET1V0DCDC_OFFSET;
	/* let the cpu convert the 5bit signed value */
	offset = (int8_t)(offset_fuse<<3) / 8;

	dig_ref = (((voltage * 512) - 3000) / 4000) + offset;
	debug("dcdc_core: dig_ref=0x%02X, voltage=%d, offset=%d\n",
		dig_ref, voltage, offset);

	dcdc_core_w8(dig_ref, pdi_dig_ref);
}

static void wait_and_print_dcdc_err(uint32_t m_sec, const char *txt)
{
	debug("%s: error_read %d\n",
		txt, (int8_t)dcdc_core_r8(pdi_error_read));
	if (m_sec) {
		/* wait X ms for stabilisation */
		udelay(m_sec*1000);
		debug("after %d ms: error_read %d\n",
			m_sec, (int8_t)dcdc_core_r8(pdi_error_read));
	}
}

/**
 * Init the core dcdc with new coefficients
 *
 * @param voltage	target voltage in mV
 * @return status
 */
int falcon_dcdc_core_init(unsigned int voltage)
{
	const uint32_t DUTY_CYCLE_TIMES = 100;
	int coeff_valid;
	uint16_t b0, b1, b2;
	uint32_t duty_cycle_av, i;
	uint32_t duty_cycle_diff[3];
	uint8_t duty_cycle_curr, duty_cycle_min, duty_cycle_max;
	int8_t error_read;

	gd->have_console = 1;
	coeff_valid = (calc_dcdc_coeff(1500, 166, 977, &b0, &b1, &b2) == 0);

	sys1_hw_activate(ACTS_DCDC1V0);

	setup_debug_gpio(1);

	duty_cycle_diff[0] = 0;
	duty_cycle_diff[1] = 0;
	duty_cycle_diff[2] = 0;
	do {
		duty_cycle_av = 0;
		duty_cycle_min = 0xFF;
		duty_cycle_max = 0;
		for (i=0; i<DUTY_CYCLE_TIMES; i++) {
			duty_cycle_curr = dcdc_core_r8(pdi_duty_cycle);
			duty_cycle_av += duty_cycle_curr;
			if (duty_cycle_curr < duty_cycle_min)
				duty_cycle_min = duty_cycle_curr;
			if (duty_cycle_curr > duty_cycle_max)
				duty_cycle_max = duty_cycle_curr;
			udelay(10);
		}

		duty_cycle_av = duty_cycle_av / DUTY_CYCLE_TIMES;
		debug("duty_cycle_average = %d, min = %d, max = %d\n",
			duty_cycle_av, duty_cycle_min, duty_cycle_max);

		/* copy to history */
		duty_cycle_diff[2] = duty_cycle_diff[1];
		duty_cycle_diff[1] = duty_cycle_diff[0];
		duty_cycle_diff[0] = duty_cycle_max - duty_cycle_min;
		debug("duty_cycle_diff[0/1/2] = %d, %d, %d\n",
			duty_cycle_diff[0], duty_cycle_diff[1], duty_cycle_diff[2]);

		if (duty_cycle_diff[0] <= duty_cycle_diff[1] &&
		    duty_cycle_diff[0] <= duty_cycle_diff[2])
			break;
	} while (1);

	set_debug_gpio(0);
	/* restrict duty cycle range around average */
	dcdc_core_w8(duty_cycle_av+10, pdi_duty_cycle_max_sat);
	dcdc_core_w8(duty_cycle_av-10, pdi_duty_cycle_min_sat);

	/* force static duty cycle value during coefficient programming */
	dcdc_core_w8(duty_cycle_av, pdi_pwm1);

	set_debug_gpio(1);
	dcdc_core_w8_mask(0, DCDC_CONF_TEST_DIG_SOFT_PRESET_PID |
			     DCDC_CONF_TEST_DIG_FREEZE_PID, 
			     pdi_conf_test_dig);

	if (coeff_valid) {
		dcdc_core_w8(b0>>8, pdi_pid_hi_b0);
		dcdc_core_w8(b0, pdi_pid_lo_b0);
		dcdc_core_w8(b1>>8, pdi_pid_hi_b1);
		dcdc_core_w8(b1, pdi_pid_lo_b1);
		dcdc_core_w8(b2>>8, pdi_pid_hi_b2);
		dcdc_core_w8(b2, pdi_pid_lo_b2);
	}
	error_read = (int8_t)dcdc_core_r8(pdi_error_read);
	dcdc_core_w8_mask(DCDC_CONF_TEST_DIG_SOFT_PRESET_PID |
			  DCDC_CONF_TEST_DIG_FREEZE_PID,
			  0, pdi_conf_test_dig);
	debug("before unfreeze: error_read %d\n", error_read);
	wait_and_print_dcdc_err(1, "unfreeze");

	set_debug_gpio(0);
	/* for chip-ver < A12: meaning of DCDC_CLK_SET0_CLK_SEL_PWM is inverted! */
	if (is_falcon_chip_a1x() && ((status_r32(config) & STATUS_CONFIG_SUBVERS_MASK) == 0))
		dcdc_core_w8_mask(0, DCDC_CLK_SET0_CLK_SEL_PWM, pdi_clk_set0);
	/* set to 249 leads to a switching frequency of 250MHz/250 = 1MHz */
	dcdc_core_w8(249, pdi_pwm0);
	wait_and_print_dcdc_err(1, "switch freq");

	set_debug_gpio(1);
	/* set wider limitation for normal operation */
	dcdc_core_w8(duty_cycle_av+40, pdi_duty_cycle_max_sat);
	dcdc_core_w8(duty_cycle_av-30, pdi_duty_cycle_min_sat);
	/* set alarm ranges */
	dcdc_core_w8(duty_cycle_av+30, pdi_duty_cycle_max);
	dcdc_core_w8(duty_cycle_av-20, pdi_duty_cycle_min);
	wait_and_print_dcdc_err(1, "normal duty");

	set_debug_gpio(0);
	falcon_dcdc_core_set_voltage(voltage);
	wait_and_print_dcdc_err(1, "switch voltage");

	cleanup_debug_gpio();
	gd->have_console = 0;

	return 0;
}

/**
 * Init the ddr dcdc with coefficients
 *
 * @param voltage	target voltage in mV
 * @return status
 */
int falcon_dcdc_ddr_init(unsigned int voltage)
{
	int ret;
	uint16_t b0, b1, b2;
	uint8_t dig_ref;

	sys1_hw_activate(ACTS_DCDCDDR);

	dig_ref = ((( (((voltage/10) + 100)*64 - 75) *
		      (320 ) ) / 32000 ) );

	/* disable */
	dcdc_ddr_w8(0x78, pdi_conf_test_ana_noauto);
	dcdc_ddr_w8(0x00, pdi_conf_test_dig_noauto);

	ret = calc_dcdc_coeff(4700, 22, 977, &b0, &b1, &b2);

	if (ret == 0) {
		dcdc_ddr_w8(b0>>8, pdi_pid_hi_b0);
		dcdc_ddr_w8(b0, pdi_pid_lo_b0);
		dcdc_ddr_w8(b1>>8, pdi_pid_hi_b1);
		dcdc_ddr_w8(b1, pdi_pid_lo_b1);
		dcdc_ddr_w8(b2>>8, pdi_pid_hi_b2);
		dcdc_ddr_w8(b2, pdi_pid_lo_b2);
	}

	/* divide output clock by 2 and leave default multiplication factor */
	dcdc_ddr_w8_mask(0, DCDC_CLK_SET0_CLK_SEL_PWM, pdi_clk_set0);
	dcdc_ddr_w8((1<<DCDC_CLK_SET1_MDLL_RES_OFFSET), pdi_clk_set1);
	/* set to 249 leads to a switching frequency of 250MHz/250 = 1MHz */
	dcdc_ddr_w8(249, pdi_pwm0);
	dcdc_ddr_w8(0x00, pdi_pwm1);
	dcdc_ddr_w8(DCDC_BIAS_VREG_VREG_SEL_NOMINAL, pdi_bias_vreg);
	dcdc_ddr_w8(dig_ref, pdi_dig_ref);
	dcdc_ddr_w8(DCDC_GENERAL_OS_EN | DCDC_GENERAL_RESERVED0 |
		DCDC_GENERAL_SET_LSB_DIGREF, pdi_general);
	dcdc_ddr_w8(0x62, pdi_adc0); /* reset value */
	dcdc_ddr_w8(0x12, pdi_adc1); /* reset value */
	dcdc_ddr_w8(0x77, pdi_adc2); /* reset value */
	dcdc_ddr_w8(0x00, pdi_duty_cycle);
	dcdc_ddr_w8(0x47, pdi_non_ov_delay);
	dcdc_ddr_w8(DCDC_ANALOG_GAIN_ATTENUATE_ANA, pdi_analog_gain);
	dcdc_ddr_w8(0xA0, pdi_duty_cycle_max_sat);
	dcdc_ddr_w8(0x07, pdi_duty_cycle_min_sat);
	dcdc_ddr_w8(0x7E, pdi_duty_cycle_max);	/** \todo calculate value */
	dcdc_ddr_w8(0xAC, pdi_duty_cycle_min);	/** \todo calculate value */
	dcdc_ddr_w8(0x40, pdi_error_max);
	dcdc_ddr_w8(15 << DCDC_DELAY_DEGLITCH_ALARM_DEGLITCH_OFFSET |
		     0 << DCDC_DELAY_DEGLITCH_RAMP_DELAY_OFFSET,
		     pdi_delay_deglitch);
	dcdc_ddr_w8(0x51, pdi_latch_control_noauto);
	dcdc_ddr_w8(0x80, pdi_cap_clk_cnt);
	dcdc_ddr_w8(0x00, pdi_mdll_divider);

	/* enable */
	dcdc_ddr_w8(0x07, pdi_conf_test_ana_noauto);
	dcdc_ddr_w8(0x03, pdi_conf_test_dig_noauto);

	return 0;
}
