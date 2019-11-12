/*
 * (C) Copyright 2011
 * Lantiq Deutschland GmbH, http://www.lantiq.com
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

#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/hardware.h>
#include <asm/arch-falcon/sysctrl.h>

#define gpio_r32(reg)			__raw_readl(reg)
#define gpio_w32(val, reg)		__raw_writel(val, reg)
#define gpio_w32_mask(clear, set, reg)	gpio_w32((gpio_r32(reg) & ~(clear)) | (set), reg)

/** register structure for padctrl
    (mainly needed for mux control) */
struct gpon_padctrl
{
	/** Multiplexer Control Register
	    The value 0 (the reset-value) is always the default function corresponding to the pad's name. The value 1 selects always the GPIO functionality (if available). */
	unsigned int muxc[32];
	/** Pull Up Enable Register */
	unsigned int puen; /* 0x00000080 */
	/** Pull Down Enable Register */
	unsigned int pden; /* 0x00000084 */
	/** Slew Rate Control Register */
	unsigned int src; /* 0x00000088 */
	/** Drive Current Control Register */
	unsigned int dcc; /* 0x0000008C */
	/** Reserved */
	unsigned int res_0[24]; /* 0x00000090 */
	/** Pad Control Availability Register */
	unsigned int avail; /* 0x000000F0 */
};

/** register structure for gpio port */
struct gpon_port
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
};

struct falcon_gpio_port {
	struct gpon_padctrl *pad;
	struct gpon_port *port;
};

static const struct falcon_gpio_port gpio_ports[] = {
	{ (struct gpon_padctrl *)GPON_PADCTRL0_BASE,
	  (struct gpon_port *)GPON_GPIO0_BASE },
	{ (struct gpon_padctrl *)GPON_PADCTRL1_BASE,
	  (struct gpon_port *)GPON_GPIO1_BASE },
	{ (struct gpon_padctrl *)GPON_PADCTRL2_BASE,
	  (struct gpon_port *)GPON_GPIO2_BASE },
};

static void gpio_init(unsigned int gpio)
{
	switch (gpio/100)
	{
	case 0:
		sys_eth_hw_activate(SYS_ETH_ACTS_PADCTRL0 | SYS_ETH_ACTS_P0);
		break;
	case 1:
		sys1_hw_activate(ACTS_PADCTRL1 | ACTS_P1);
		break;
	case 2:
		sys_eth_hw_activate(SYS_ETH_ACTS_PADCTRL2 | SYS_ETH_ACTS_P2);
		break;
	default:
		return;
	}
}

static inline const struct falcon_gpio_port *to_falcon_gpio_port(unsigned int gpio)
{
	return &gpio_ports[gpio/100];
}

int gpio_request(unsigned gpio, const char *label)
{
	const struct falcon_gpio_port *gpio_port = to_falcon_gpio_port(gpio);
	int offset = gpio % 100;

	(void)label;

	if ( ((gpio%100) >= 32) || (gpio/100)>= ARRAY_SIZE(gpio_ports))
		return -1;

	/* call init everytime (no side effect and only little overhead) */
	gpio_init(gpio);

	if ((gpio_r32(&gpio_port->pad->avail) >> offset) & 1) {
		if (gpio_r32(&gpio_port->pad->muxc[offset]) > 1)
			return -1;
		/* switch on gpio function */
		gpio_w32(1, &gpio_port->pad->muxc[offset]);
		debug("gpio_request %d for %s: SUCCESS!\n", gpio, label);
		return 0;
	}

	return -2;
}

void gpio_free(unsigned gpio)
{
}

int gpio_direction_input(unsigned int gpio)
{
	const struct falcon_gpio_port *gpio_port = to_falcon_gpio_port(gpio);
	int offset = gpio % 100;

	gpio_w32(1<<offset, &gpio_port->port->dirclr);
	return 0;
}

int gpio_direction_output(unsigned gpio, int value)
{
	const struct falcon_gpio_port *gpio_port = to_falcon_gpio_port(gpio);
	int offset = gpio % 100;

	gpio_set_value(gpio, value);
	gpio_w32(1<<offset, &gpio_port->port->dirset);
	return 0;
}

int gpio_get_value(unsigned int gpio)
{
	const struct falcon_gpio_port *gpio_port = to_falcon_gpio_port(gpio);
	int offset = gpio % 100;

	return (gpio_r32(&gpio_port->port->in) >> offset) & 1;
}

void gpio_set_value(unsigned int gpio, int value)
{
	const struct falcon_gpio_port *gpio_port = to_falcon_gpio_port(gpio);
	int offset = gpio % 100;

	if (value)
		gpio_w32(1<<offset, &gpio_port->port->outset);
	else
		gpio_w32(1<<offset, &gpio_port->port->outclr);
}
