#ifndef __IFXMIPS_GPIO_H__
#define __IFXMIPS_GPIO_H__

#define MAX_PORTS			2
#define PINS_PER_PORT			16

#define GPIO_TO_PORT(x)			((x > 15) ? (1) : (0))
#define GPIO_TO_GPIO(x)			((x > 15) ? (x - 16) : (x))

#if defined(CONFIG_EASY50712)
#	include <asm/danube.h>
#	define CONFIG_IFXMIPS_LED	1

#	define IFXMIPS_GPIO_BASE_ADDR	DANUBE_GPIO
#	define IFXMIPS_GPIO_P0_OUT	DANUBE_GPIO_P0_OUT
#	define IFXMIPS_GPIO_P1_OUT	DANUBE_GPIO_P1_OUT
#	define IFXMIPS_GPIO_P2_OUT	/* undefined */
#	define IFXMIPS_GPIO_P3_OUT	/* undefined */
#	define IFXMIPS_GPIO_P0_IN	DANUBE_GPIO_P0_IN
#	define IFXMIPS_GPIO_P1_IN	DANUBE_GPIO_P1_IN
#	define IFXMIPS_GPIO_P2_IN	/* undefined */
#	define IFXMIPS_GPIO_P3_IN	/* undefined */
#	define IFXMIPS_GPIO_P0_DIR	DANUBE_GPIO_P0_DIR
#	define IFXMIPS_GPIO_P1_DIR	DANUBE_GPIO_P1_DIR
#	define IFXMIPS_GPIO_P2_DIR	/* undefined */
#	define IFXMIPS_GPIO_P3_DIR	/* undefined */
#	define IFXMIPS_GPIO_P0_ALTSEL0	DANUBE_GPIO_P0_ALTSEL0
#	define IFXMIPS_GPIO_P1_ALTSEL0	DANUBE_GPIO_P1_ALTSEL0
#	define IFXMIPS_GPIO_P2_ALTSEL0	/* undefined */
#	define IFXMIPS_GPIO_P3_ALTSEL0	/* undefined */
#	define IFXMIPS_GPIO_P0_ALTSEL1	DANUBE_GPIO_P0_ALTSEL1
#	define IFXMIPS_GPIO_P1_ALTSEL1	DANUBE_GPIO_P1_ALTSEL1
#	define IFXMIPS_GPIO_P2_ALTSEL1	/* undefined */
#	define IFXMIPS_GPIO_P3_ALTSEL1	/* undefined */
#	define IFXMIPS_GPIO_P0_OD	DANUBE_GPIO_P0_OD
#	define IFXMIPS_GPIO_P1_OD	DANUBE_GPIO_P1_OD
#	define IFXMIPS_GPIO_P2_OD	/* undefined */
#	define IFXMIPS_GPIO_P3_OD	/* undefined */
#	define IFXMIPS_GPIO_P0_STOFF	DANUBE_GPIO_P0_STOFF
#	define IFXMIPS_GPIO_P1_STOFF	DANUBE_GPIO_P1_STOFF
#	define IFXMIPS_GPIO_P2_STOFF	/* undefined */
#	define IFXMIPS_GPIO_P3_STOFF	/* undefined */
#	define IFXMIPS_GPIO_P0_PUDSEL	DANUBE_GPIO_P0_PUDSEL
#	define IFXMIPS_GPIO_P1_PUDSEL	DANUBE_GPIO_P1_PUDSEL
#	define IFXMIPS_GPIO_P2_PUDSEL	/* undefined */
#	define IFXMIPS_GPIO_P3_PUDSEL	/* undefined */
#	define IFXMIPS_GPIO_P0_PUDEN	DANUBE_GPIO_P0_PUDEN
#	define IFXMIPS_GPIO_P1_PUDEN	DANUBE_GPIO_P1_PUDEN
#	define IFXMIPS_GPIO_P2_PUDEN	/* undefined */
#	define IFXMIPS_GPIO_P3_PUDEN	/* undefined */

#	define IFXMIPS_LED_BASE_ADDR	DANUBE_LED
#	define IFXMIPS_LED_CON0		DANUBE_LED_CON0
#	define IFXMIPS_LED_CON1		DANUBE_LED_CON1
#	define IFXMIPS_LED_CPU0		DANUBE_LED_CPU0
#	define IFXMIPS_LED_CPU1		DANUBE_LED_CPU1
#	define IFXMIPS_LED_AR		DANUBE_LED_AR

#	define IFXMIPS_LED_GPIO_PORT	0
#elif defined(CONFIG_EASY50812)
#	include <asm/danube.h>

#	define IFXMIPS_GPIO_BASE_ADDR	AR9_GPIO
#	define IFXMIPS_GPIO_P0_OUT	AR9_GPIO_P0_OUT
#	define IFXMIPS_GPIO_P1_OUT	AR9_GPIO_P1_OUT
#	define IFXMIPS_GPIO_P2_OUT	AR9_GPIO_P2_OUT
#	define IFXMIPS_GPIO_P3_OUT	AR9_GPIO_P3_OUT
#	define IFXMIPS_GPIO_P0_IN	AR9_GPIO_P0_IN
#	define IFXMIPS_GPIO_P1_IN	AR9_GPIO_P1_IN
#	define IFXMIPS_GPIO_P2_IN	AR9_GPIO_P2_IN
#	define IFXMIPS_GPIO_P3_IN	AR9_GPIO_P3_IN
#	define IFXMIPS_GPIO_P0_DIR	AR9_GPIO_P0_DIR
#	define IFXMIPS_GPIO_P1_DIR	AR9_GPIO_P1_DIR
#	define IFXMIPS_GPIO_P2_DIR	AR9_GPIO_P2_DIR
#	define IFXMIPS_GPIO_P3_DIR	AR9_GPIO_P3_DIR
#	define IFXMIPS_GPIO_P0_ALTSEL0	AR9_GPIO_P0_ALTSEL0
#	define IFXMIPS_GPIO_P1_ALTSEL0	AR9_GPIO_P1_ALTSEL0
#	define IFXMIPS_GPIO_P2_ALTSEL0	AR9_GPIO_P2_ALTSEL0
#	define IFXMIPS_GPIO_P3_ALTSEL0	AR9_GPIO_P3_ALTSEL0
#	define IFXMIPS_GPIO_P0_ALTSEL1	AR9_GPIO_P0_ALTSEL1
#	define IFXMIPS_GPIO_P1_ALTSEL1	AR9_GPIO_P1_ALTSEL1
#	define IFXMIPS_GPIO_P2_ALTSEL1	AR9_GPIO_P2_ALTSEL1
#	define IFXMIPS_GPIO_P3_ALTSEL1	AR9_GPIO_P3_ALTSEL1
#	define IFXMIPS_GPIO_P0_OD	AR9_GPIO_P0_OD
#	define IFXMIPS_GPIO_P1_OD	AR9_GPIO_P1_OD
#	define IFXMIPS_GPIO_P2_OD	AR9_GPIO_P2_OD
#	define IFXMIPS_GPIO_P3_OD	AR9_GPIO_P3_OD
#	define IFXMIPS_GPIO_P0_STOFF	AR9_GPIO_P0_STOFF
#	define IFXMIPS_GPIO_P1_STOFF	AR9_GPIO_P1_STOFF
#	define IFXMIPS_GPIO_P2_STOFF	AR9_GPIO_P2_STOFF
#	define IFXMIPS_GPIO_P3_STOFF	AR9_GPIO_P3_STOFF
#	define IFXMIPS_GPIO_P0_PUDSEL	AR9_GPIO_P0_PUDSEL
#	define IFXMIPS_GPIO_P1_PUDSEL	AR9_GPIO_P1_PUDSEL
#	define IFXMIPS_GPIO_P2_PUDSEL	AR9_GPIO_P1_PUDSEL
#	define IFXMIPS_GPIO_P3_PUDSEL	AR9_GPIO_P1_PUDSEL
#	define IFXMIPS_GPIO_P0_PUDEN	AR9_GPIO_P0_PUDEN
#	define IFXMIPS_GPIO_P1_PUDEN	AR9_GPIO_P1_PUDEN
#	define IFXMIPS_GPIO_P2_PUDEN	AR9_GPIO_P2_PUDEN
#	define IFXMIPS_GPIO_P3_PUDEN	AR9_GPIO_P3_PUDEN

#	define IFXMIPS_LED_BASE_ADDR	0 /* undefined */
#	define IFXMIPS_LED_CON0		0 /* undefined */
#	define IFXMIPS_LED_CON1		0 /* undefined */
#	define IFXMIPS_LED_CPU0		0 /* undefined */
#	define IFXMIPS_LED_CPU1		0 /* undefined */
#	define IFXMIPS_LED_AR		0 /* undefined */

#	define IFXMIPS_LED_GPIO_PORT	0
#else
#	error Undefined IFXMIPS board type
#endif

int ifxmips_port_set_open_drain(unsigned int port, unsigned int pin);
int ifxmips_port_clear_open_drain(unsigned int port, unsigned int pin);
int ifxmips_port_set_pudsel(unsigned int port, unsigned int pin);
int ifxmips_port_clear_pudsel(unsigned int port, unsigned int pin);
int ifxmips_port_set_puden(unsigned int port, unsigned int pin);
int ifxmips_port_clear_puden(unsigned int port, unsigned int pin);
int ifxmips_port_set_stoff(unsigned int port, unsigned int pin);
int ifxmips_port_clear_stoff(unsigned int port, unsigned int pin);
int ifxmips_port_set_dir_out(unsigned int port, unsigned int pin);
int ifxmips_port_set_dir_in(unsigned int port, unsigned int pin);
int ifxmips_port_set_output(unsigned int port, unsigned int pin);
int ifxmips_port_clear_output(unsigned int port, unsigned int pin);
int ifxmips_port_get_input(unsigned int port, unsigned int pin);
int ifxmips_port_set_altsel0(unsigned int port, unsigned int pin);
int ifxmips_port_clear_altsel0(unsigned int port, unsigned int pin);
int ifxmips_port_set_altsel1(unsigned int port, unsigned int pin);
int ifxmips_port_clear_altsel1(unsigned int port, unsigned int pin);

#ifdef CONFIG_IFXMIPS_LED
void ifxmips_led_set(unsigned int led);
void ifxmips_led_clear(unsigned int led);
void ifxmips_led_blink_set(unsigned int led);
void ifxmips_led_blink_clear(unsigned int led);
void ifxmips_led_setup_gpio(void);
#else
#	define ifxmips_led_set(led)		/* NOP */
#	define ifxmips_led_clear(led)		/* NOP */
#	define ifxmips_led_blink_set(led)	/* NOP */
#	define ifxmips_led_blink_clear(led)	/* NOP */
#	define ifxmips_led_setup_gpio(led)	/* NOP */
#endif

#endif
