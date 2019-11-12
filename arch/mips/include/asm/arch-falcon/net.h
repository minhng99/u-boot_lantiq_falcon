/*
 * (C) Copyright 2011 Lantiq Deutschland GmbH, http://www.lantiq.com
 *
 * See file CREDITS for list of people who contributed to this
 * project.
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
 */

#ifndef __FALCON_NET_H
#define __FALCON_NET_H

#define FALCON_NET_PORT_MASK_GPHY0	(1<<0)
#define FALCON_NET_PORT_MASK_GPHY1	(1<<1)
#define FALCON_NET_PORT_MASK_RGMII0	(1<<2)
#define FALCON_NET_PORT_MASK_RGMII1	(1<<3)
#define FALCON_NET_PORT_MASK_GMII_PHY	(1<<4)
#define FALCON_NET_PORT_MASK_GMII_MAC	(1<<5)
#define FALCON_NET_PORT_MASK_MII_PHY	(1<<6)
#define FALCON_NET_PORT_MASK_MII_MAC	(1<<7)
#define FALCON_NET_PORT_MASK_SGMII	(1<<8)

#define FALCON_NET_PORT_MASK_GPHY \
	(FALCON_NET_PORT_MASK_GPHY0 | FALCON_NET_PORT_MASK_GPHY1)

#define FALCON_NET_PORT_MASK_RGMII \
	(FALCON_NET_PORT_MASK_RGMII0 | FALCON_NET_PORT_MASK_RGMII1)

#define FALCON_NET_PORT_MASK_GMII \
	(FALCON_NET_PORT_MASK_GMII_PHY | FALCON_NET_PORT_MASK_GMII_MAC)

#define FALCON_NET_PORT_MASK_MII \
	(FALCON_NET_PORT_MASK_MII_PHY | FALCON_NET_PORT_MASK_MII_MAC)

#define FALCON_NET_PORT_MASK_xMII \
	(FALCON_NET_PORT_MASK_RGMII | \
	 FALCON_NET_PORT_MASK_GMII | \
	 FALCON_NET_PORT_MASK_MII)

#define FALCON_NET_PORT_MASK_ALL \
	(FALCON_NET_PORT_MASK_GPHY | FALCON_NET_PORT_MASK_RGMII | \
	 FALCON_NET_PORT_MASK_GMII | FALCON_NET_PORT_MASK_MII | \
	 FALCON_NET_PORT_MASK_SGMII)

#ifndef CONFIG_FALCON_NET_PORT_MASK
#define CONFIG_FALCON_NET_PORT_MASK	FALCON_NET_PORT_MASK_ALL
#endif

int falcon_net_register(unsigned int mask);

#endif /* __FALCON_NET_H */
