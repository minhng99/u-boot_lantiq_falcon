#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/ifxmips_gpio.h>

#define IFXMIPS_GPIO_SANITY	\
	do { \
		if (port > MAX_PORTS || pin > PINS_PER_PORT) return -1; \
	} while (0)

#define ifxmips_r32(reg)			__raw_readl(reg)
#define ifxmips_w32(val, reg)			__raw_writel(val, reg)
#define ifxmips_w32_mask(clear, set, reg)	ifxmips_w32((ifxmips_r32(reg) \
						& ~clear) | set, reg)

int ifxmips_port_set_open_drain(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_OD + (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_OD + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_open_drain(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_OD + (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_OD + (port * 0xC));
	return 0;
}

int ifxmips_port_set_pudsel(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_PUDSEL
		+ (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_PUDSEL + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_pudsel(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_PUDSEL
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_PUDSEL + (port * 0xC));
	return 0;
}

int ifxmips_port_set_puden(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_PUDEN
		+ (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_PUDEN + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_puden(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_PUDEN
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_PUDEN + (port * 0xC));
	return 0;
}

int ifxmips_port_set_stoff(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_STOFF
		+ (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_STOFF + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_stoff(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_STOFF
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_STOFF + (port * 0xC));
	return 0;
}

int ifxmips_port_set_dir_out(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_DIR + (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_DIR + (port * 0xC));
	return 0;
}

int ifxmips_port_set_dir_in(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_DIR
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_DIR + (port * 0xC));
	return 0;
}

int ifxmips_port_set_output(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_OUT + (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_OUT + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_output(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_OUT
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_OUT + (port * 0xC));
	return 0;
}

int ifxmips_port_get_input(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	if (ifxmips_r32(IFXMIPS_GPIO_P0_IN + (port * 0xC)) & (1 << pin))
		return 0;
	else
		return 1;
}

int ifxmips_port_set_altsel0(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_ALTSEL0
		+ (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_ALTSEL0 + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_altsel0(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_ALTSEL0
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_ALTSEL0 + (port * 0xC));
	return 0;
}

int ifxmips_port_set_altsel1(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_ALTSEL1
		+ (port * 0xC)) | (1 << pin),
		IFXMIPS_GPIO_P0_ALTSEL1 + (port * 0xC));
	return 0;
}

int ifxmips_port_clear_altsel1(unsigned int port, unsigned int pin)
{
	IFXMIPS_GPIO_SANITY;
	ifxmips_w32(ifxmips_r32(IFXMIPS_GPIO_P0_ALTSEL1
		+ (port * 0xC)) & ~(1 << pin),
		IFXMIPS_GPIO_P0_ALTSEL1 + (port * 0xC));
	return 0;
}

#ifdef CONFIG_IFXMIPS_LED
void ifxmips_led_set(unsigned int led)
{
	led &= 0xffffff;
	ifxmips_w32(ifxmips_r32(IFXMIPS_LED_CPU0) | led, IFXMIPS_LED_CPU0);
}

void ifxmips_led_clear(unsigned int led)
{
	led = ~(led & 0xffffff);
	ifxmips_w32(ifxmips_r32(IFXMIPS_LED_CPU0) & led, IFXMIPS_LED_CPU0);
}

void ifxmips_led_blink_set(unsigned int led)
{
	led &= 0xffffff;
	ifxmips_w32(ifxmips_r32(IFXMIPS_LED_CON0) | led, IFXMIPS_LED_CON0);
}

void ifxmips_led_blink_clear(unsigned int led)
{
	led = ~(led & 0xffffff);
	ifxmips_w32(ifxmips_r32(IFXMIPS_LED_CON0) & led, IFXMIPS_LED_CON0);
}

void ifxmips_led_setup_gpio(void)
{
	int i = 0;

	/* leds are controlled via a shift register
	   we need to setup pins SH,D,ST (4,5,6) to make it work */
	for (i = 4; i < 7; i++) {
		ifxmips_port_set_altsel0(IFXMIPS_LED_GPIO_PORT, i);
		ifxmips_port_clear_altsel1(IFXMIPS_LED_GPIO_PORT, i);
		ifxmips_port_set_dir_out(IFXMIPS_LED_GPIO_PORT, i);
		ifxmips_port_set_open_drain(IFXMIPS_LED_GPIO_PORT, i);
	}
}
#endif
