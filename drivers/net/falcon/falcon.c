/*
 * FALCON U-boot Ethernet driver
 * Copyright (c) 2011 Lantiq Deutschland GmbH
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/* #define DEBUG */
/* #define DEBUG_COUNTER */
/* #define DEBUG_DATA */
#include <common.h>

#include <malloc.h>
#include <net.h>
#include <miiphy.h>
#include <hwconfig.h>

#include "falcon_std_defs.h"
#include "falcon_resource.h"
#include "falcon_register.h"

#include "falcon_ll.h"

#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>
#include <asm/arch/net.h>
#include <asm/falcon.h>

/*
 * This driver requires CONFIG_MII for some functionality
 */
#if !defined(CONFIG_MII)
#error CONFIG_MII not set!
#endif

#define INGRESS_QUEUE FALCON_INGRESS_QUEUE_LAN_0

static struct gpon_reg_sbs0ctrl * const sbs0ctrl =
	(struct gpon_reg_sbs0ctrl *)GPON_SBS0CTRL_BASE;
static struct gpon_reg_iqm * const iqm =
	(struct gpon_reg_iqm *) GPON_IQM_BASE;
static struct gpon_reg_eim_a1x * const eim_a1x =
	(struct gpon_reg_eim_a1x *) GPON_EIM_BASE;
static struct gpon_reg_eim_a2x * const eim_a2x =
	(struct gpon_reg_eim_a2x *) GPON_EIM_BASE;
static struct gpon_reg_ictrll * const ictrll0 =
	(struct gpon_reg_ictrll *) GPON_ICTRLL0_BASE;
static struct gpon_reg_octrll * const octrll0 =
	(struct gpon_reg_octrll *) GPON_OCTRLL0_BASE;
static struct gpon_reg_sgmii * const sgmii =
	(struct gpon_reg_sgmii *)GPON_SGMII_BASE;
static struct gpon_reg_sxgmii * const sxgmii =
	(struct gpon_reg_sxgmii *)GPON_SXGMII_BASE;

typedef enum {
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY)
	PORT_GPHY0,
	PORT_GPHY1,
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_xMII)
	PORT_XMII0,
	PORT_XMII1,
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
	PORT_SGMII
#endif
} port_type;

struct eth_port {
	const char *name;
	const char *env_name;	/* environment variable to select the phy addr */
	port_type port;
	uint32_t sys_eth_act;	/* which modules to activate */
	int defspeed;		/* Standard speed of port, without phy info */
	uint32_t miicfg;	/* mii rate and mode (only for xmii) */
	uint32_t support_mask;	/* mask of supported chip types */
	uint32_t port_mask;	/* mask for selecting ports from board info */
};

static const char *mdio_name = "falcon_mdio";
static int ll_hw_is_initialized;


static const struct eth_port falcon_eth_ports[] = {
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY0)
	{
		.name = "GPHY0",
		.env_name = "gphy0_phyaddr",
		.port = PORT_GPHY0,
		.sys_eth_act = 0,
		.defspeed = _1000BASET,
		.support_mask = FALCON_D | FALCON_V | FALCON_M | FALCON_S,
		.port_mask = FALCON_NET_PORT_MASK_GPHY0,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY1)
	{
		.name = "GPHY1",
		.env_name = "gphy1_phyaddr",
		.port = PORT_GPHY1,
		.sys_eth_act = 0,
		.defspeed = _1000BASET,
		.support_mask = FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_GPHY1,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_RGMII0)
	{
		.name = "RGMII0",
		.env_name = "rgmii0_phyaddr",
		.port = PORT_XMII0,
		.sys_eth_act = SYS_ETH_ACT_xMII,
		.defspeed = _1000BASET,
		.miicfg = EIM_MII_CFG_MIIRATE_AUTO | EIM_MII_CFG_MIIMODE_RGMII,
		.support_mask = FALCON_D | FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_RGMII0,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_RGMII1)
	{
		.name = "RGMII1",
		.env_name = "rgmii1_phyaddr",
		.port = PORT_XMII1,
		.sys_eth_act = SYS_ETH_ACT_xMII,
		.defspeed = _1000BASET,
		.miicfg = EIM_MII_CFG_MIIRATE_AUTO | EIM_MII_CFG_MIIMODE_RGMII,
		.support_mask = FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_RGMII1,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GMII_PHY)
	{
		.name = "GMII_PHY",
		.env_name = "gmiip_phyaddr",
		.port = PORT_XMII0,
		.sys_eth_act = SYS_ETH_ACT_xMII,
		.defspeed = _1000BASET,
		.miicfg = EIM_MII_CFG_MIIRATE_M125 | EIM_MII_CFG_MIIMODE_MIIP,
		.support_mask = FALCON_D | FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_GMII_PHY,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GMII_MAC)
	{
		.name = "GMII_MAC",
		.env_name = "gmiim_phyaddr",
		.port = PORT_XMII0,
		.sys_eth_act = SYS_ETH_ACT_xMII,
		.defspeed = _1000BASET,
		.miicfg = EIM_MII_CFG_MIIRATE_M125 | EIM_MII_CFG_MIIMODE_MIIM,
		.support_mask = FALCON_D | FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_GMII_MAC,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_MII_PHY)
	{
		.name = "MII_PHY",
		.env_name = "miip_phyaddr",
		.port = PORT_XMII0,
		.sys_eth_act = SYS_ETH_ACT_xMII,
		.defspeed = _100BASET,
		.miicfg = EIM_MII_CFG_MIIRATE_M25 | EIM_MII_CFG_MIIMODE_MIIP,
		.support_mask = FALCON_D | FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_MII_PHY,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_MII_MAC)
	{
		.name = "MII_MAC",
		.env_name = "miim_phyaddr",
		.port = PORT_XMII0,
		.sys_eth_act = SYS_ETH_ACT_xMII,
		.defspeed = _100BASET,
		.miicfg = EIM_MII_CFG_MIIRATE_M25 | EIM_MII_CFG_MIIMODE_MIIM,
		.support_mask = FALCON_D | FALCON_V | FALCON_M,
		.port_mask = FALCON_NET_PORT_MASK_MII_MAC,
	},
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
	{
		.name = "SGMII",
		.env_name = "sgmii_phyaddr",
		.port = PORT_SGMII,
		.sys_eth_act = SYS_ETH_ACT_SGMII,
		.defspeed = _1000BASET,
		.support_mask = FALCON_M | FALCON_S,
		.port_mask = FALCON_NET_PORT_MASK_SGMII,
	},
#endif
};

static int falcon_send(struct eth_device *dev, volatile void *packet,
	int length)
{
	int ret;

	debug("falcon_send(0x%p, 0x%p, %d)\n", dev, packet, length);

	if (length <= 0) {
		printf("falcon_send: Invalid packet length (%d)\n", length);
		return -1;
	}
#ifdef DEBUG_DATA
	print_buffer(0, (void *)packet, 1, (length > 64) ? 64 : length, 0);
#endif

	ret = falcon_pdu_write(length, (const uint8_t *) packet);

	return ret;
}

#ifdef DEBUG_COUNTER
static u32 ictrll0_macerr, ictrll0_pdc, ictrll0_rxpcnt;
static u32 octrll0_txpcnt;
static struct eim_top_pdi eim_top_pdi;
#define CHECK_CNT(hwmod, name) \
	do { \
		reg = hwmod ## r32(name); \
		if (hwmod ## name != reg) { \
			printf("%8s %8d -> %8d\n", #name, hwmod ## name, reg); \
			hwmod ## name = reg; \
		} else if (always) { \
			printf("%8s %8d\n", #name, reg); \
		} \
	} while (0)

static void falcon_check_counter(int always)
{
	u32 reg;
	CHECK_CNT(ictrll0_, macerr);
	CHECK_CNT(ictrll0_, pdc);
	CHECK_CNT(ictrll0_, rxpcnt);
	CHECK_CNT(octrll0_, txpcnt);
	CHECK_CNT(eim_, top_pdi.eim_mib_fcser[0]);
}
#else
static inline void falcon_check_counter(int always) {}
#endif

static int falcon_recv(struct eth_device *dev)
{
	void *packet = (void *) NetRxPackets[0];
	struct pdu_info info;

	falcon_check_counter(0);

	if (falcon_pdu_info_read(INGRESS_QUEUE, &info) < 0)
		return -1;

	if (info.len > PKTSIZE_ALIGN)
		BUG();

	if (falcon_pdu_data_read(&info, packet) < 0) {
		puts("error in falcon_pdu_data_read()\n");
		return -1;
	}

	debug("falcon_recv(len %d)\n", info.len);
#ifdef DEBUG_DATA
	if (info.len)
		print_buffer(0, packet, 1, (info.len > 64) ? 64 : info.len, 0);
#endif
	if (info.len)
		NetReceive(packet, info.len);

	return info.len;
}

static void falcon_set_hwaddr(uchar *eth_mac)
{
	/* set MAC address */
	ictrll0_w32(eth_mac[0]<<24 | eth_mac[1]<<16 |
		    eth_mac[2]<<8 | eth_mac[3],
		    rawda0);
	ictrll0_w32(eth_mac[4]<<24 | eth_mac[5]<<16, rawda1);
}

static int falcon_ll_hwinit(void)
{
	if (ll_hw_is_initialized) {
		/*sys_eth_hw_activate(SYS_ETH_ACT_GMAC0);
		sys_gpe_hw_activate(SYS_GPE_ACT_LAN0 | SYS_GPE_ACT_FSQM
			| SYS_GPE_ACT_IQM | SYS_GPE_ACT_ARB);*/
		iqm_queue_enable_set(INGRESS_QUEUE, 1);
		return 0;
	}
	ll_hw_is_initialized = 1;

	sys_eth_hw_activate_or_reboot(SYS_ETH_ACT_GMAC0);
	sys_gpe_hw_activate_or_reboot(SYS_GPE_ACT_LAN0 | SYS_GPE_ACT_FSQM
		| SYS_GPE_ACT_IQM | SYS_GPE_ACT_ARB);

	/* initialize HW */
	gpearb_init();
	fsqm_init();
	iqm_init();
	octrll_init();
	ictrll_init();

	/* enable raw mode with broadcasts on ICTRLL0 */
	ictrll0_w32_mask(0, ICTRLL_CTRL_RAW_EN |
				 ICTRLL_CTRL_BC_EN, ctrl);

	octrll_port_enable_set(1);
	ictrll_port_enable_set(1);

	iqm_queue_enable_set(INGRESS_QUEUE, 1);

	return 0;
}

static void falcon_halt(struct eth_device *dev)
{
	debug("falcon_halt(%s)\n", dev->name);
	if (ll_hw_is_initialized)
		iqm_queue_enable_set(INGRESS_QUEUE, 0);

	if (ll_hw_is_initialized)
		falcon_check_counter(1);
/*
	sys_eth_hw_clk_disable(SYS_ETH_CLKS_GMAC0);
	sys_gpe_hw_clk_disable(SYS_GPE_CLKS_LAN0 | SYS_GPE_CLKS_FSQM
		| SYS_GPE_CLKS_IQM | SYS_GPE_CLKS_ARB);
*/
}

#define PHY_AUTONEGOTIATE_TIMEOUT	8000	/* 8000 ms autonegotiate timeout */

static int get_phy_status(struct eth_port *priv, unsigned int phy_addr,
		int *speed, int *duplex)
{
	unsigned short reg;
	int i;

	if (!speed || !duplex)
		return -1;

	miiphy_read(mdio_name, phy_addr, MII_BMSR, &reg);

	/*
	 * Wait if PHY is capable of autonegotiation and autonegotiation is not complete
	 */
	if ((reg & BMSR_ANEGCAPABLE) && !(reg & BMSR_ANEGCOMPLETE)) {
		printf("%s: Waiting for PHY(%d) auto negotiation to complete ",
			priv->name, phy_addr);
		i = 0;
		while (!(reg & BMSR_ANEGCOMPLETE)) {
			/*
			 * Timeout reached ?
			 */
			if (i > PHY_AUTONEGOTIATE_TIMEOUT) {
				puts(" TIMEOUT !\n");
				return -1;
			}

			if (ctrlc()) {
				puts(" canceled!\n");
				return -1;
			}

			if ((i++ % 1000) == 0)
				putc('.');

			udelay(1000);	/* 1 ms */
			miiphy_read(mdio_name, phy_addr, MII_BMSR, &reg);
		}
		puts(" done\n");
	}

	if ((reg & BMSR_LSTATUS) == 0) {
		printf("%s: No Link!\n", priv->name);
		return -1;
	}

	*speed = miiphy_speed(mdio_name, phy_addr);
	*duplex = miiphy_duplex(mdio_name, phy_addr);

	printf("%s: Link Speed is %d Mbps - %s duplex connection\n",
		priv->name, *speed, (*duplex == HALF) ? "HALF" : "FULL");

	return 0;
}

static int update_port_speed(struct eth_device *dev)
{
	struct eth_port *priv = dev->priv;
	int speed = priv->defspeed;
	int duplex = HALF;
	const char *s = NULL;
	size_t len;
	int phy_addr = -1;
	uint32_t eim_phy_addr_speed;
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_xMII)
#define ASSIGN_xMII_VAR(code)	code
	int speed_idx;
	port_type port = priv->port;
	uint32_t drc;

	static const uint32_t drc_mask[3] = {
		SYS_ETH_DRC_xMII0_MASK,
		SYS_ETH_DRC_xMII1_MASK,
		SYS_ETH_DRC_SGMII_MASK,
	};
	static const uint32_t drc_vals[3][3] = {
		{
		SYS_ETH_DRC_xMII0_DR10,
		SYS_ETH_DRC_xMII0_DR100,
		SYS_ETH_DRC_xMII0_DR1000,
		}, {
		SYS_ETH_DRC_xMII1_DR10,
		SYS_ETH_DRC_xMII1_DR100,
		SYS_ETH_DRC_xMII1_DR1000,
		}, {
		SYS_ETH_DRC_SGMII_DR10,
		SYS_ETH_DRC_SGMII_DR100,
		SYS_ETH_DRC_SGMII_DR1000,
		}
	};
#else
#define ASSIGN_xMII_VAR(code)
#endif

	if (hwconfig(priv->name)) {
		s = hwconfig_subarg(priv->name, "speed", &len);
		if ((s != NULL) && (len > 0)) {
			speed = simple_strtoul(s, NULL, 10);
			switch (speed) {
			case _10BASET:
			case _100BASET:
			case _1000BASET:
				/* supported values */
				break;
			default:
				/* fall back to defspeed */
				speed = priv->defspeed;
				break;
			}
		}

		s = hwconfig_subarg(priv->name, "phyaddr", &len);
		if ((s != NULL) && (len > 0))
			phy_addr = simple_strtoul(s, NULL, 10);
	}
	/* if no phyaddr in hwconfig, try port specific environment variable */
	if (s == NULL) {
		s = getenv((char *)priv->env_name);
		if (s != NULL)
			phy_addr = simple_strtoul(s, NULL, 10);
	}

	if (phy_addr >= 0 && phy_addr < 32) {
		if (get_phy_status(priv, phy_addr, &speed, &duplex) != 0)
			return -1;
	}

	switch (speed) {
	case _10BASET:
		ASSIGN_xMII_VAR(speed_idx = 0;)
		eim_phy_addr_speed = EIM_PHY_ADDR_SPEED_M10;
		break;
	case _100BASET:
		ASSIGN_xMII_VAR(speed_idx = 1;)
		eim_phy_addr_speed = EIM_PHY_ADDR_SPEED_M100;
		break;
	case _1000BASET:
		ASSIGN_xMII_VAR(speed_idx = 2;)
		eim_phy_addr_speed = EIM_PHY_ADDR_SPEED_G1;
		break;
	default:
		ASSIGN_xMII_VAR(speed_idx = -1;)
		eim_phy_addr_speed = EIM_PHY_ADDR_SPEED_AUTO;
		break;
	}

	if (is_falcon_chip_a2x()) {
		u32 reg;
		reg = eim_a2x_r32(mdio_pdi.phy_addr[0]);
		reg &= ~(EIM_PHY_ADDR_LNKST_MASK | EIM_PHY_ADDR_SPEED_MASK
			| EIM_PHY_ADDR_FDUP_MASK);
		reg |= EIM_PHY_ADDR_LNKST_UP | eim_phy_addr_speed;
		if (duplex == FULL)
			reg |= EIM_PHY_ADDR_FDUP_EN;
		else
			reg |= EIM_PHY_ADDR_FDUP_DIS;
		eim_a2x_w32(reg, mdio_pdi.phy_addr[0]);
	}
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_xMII)
	if ((speed_idx != -1) && (port >= PORT_XMII0)) {
		drc = drc_vals[port-PORT_XMII0][speed_idx];
		sys_eth_hw_clk_disable(SYS_ETH_CLKEN_GMAC0);
		sys_eth_w32_mask(drc_mask[port-PORT_XMII0], drc, drc);
		sys_eth_hw_clk_enable(SYS_ETH_CLKEN_GMAC0);
	}
#endif
	return 0;
}

#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_xMII)
static int xmii_init(struct eth_device *dev,
	port_type port, uint32_t miicfg)
{
	struct eth_port *priv = dev->priv;
	const char *s = NULL;
	size_t len;
	uint32_t rxdly = 0;
	uint32_t txdly = 0;
	enum lan_mode_duplex duplex;
	enum lan_mode_flow flow;

	if (hwconfig_subarg_cmp(priv->name, "duplex", "full"))
		duplex = LAN_MAC_MODE_DUPLEX_FULL;
	else if (hwconfig_subarg_cmp(priv->name, "duplex", "half"))
		duplex = LAN_MAC_MODE_DUPLEX_HALF;
	else
		duplex = LAN_MAC_MODE_DUPLEX_AUTO;

	if (hwconfig_subarg_cmp(priv->name, "flow", "rxtx"))
		flow = LAN_MAC_MODE_FLOW_RXTX;
	else if (hwconfig_subarg_cmp(priv->name, "flow", "rx"))
		flow = LAN_MAC_MODE_FLOW_RX;
	else if (hwconfig_subarg_cmp(priv->name, "flow", "tx"))
		flow = LAN_MAC_MODE_FLOW_TX;
	else if (hwconfig_subarg_cmp(priv->name, "flow", "none"))
		flow = LAN_MAC_MODE_FLOW_NONE;
	else
		flow = LAN_MAC_MODE_DUPLEX_AUTO;

	s = hwconfig_subarg(priv->name, "rxdly", &len);
	if ((s != NULL) && (len > 0))
		rxdly = simple_strtoul(s, NULL, 10);

	s = hwconfig_subarg(priv->name, "txdly", &len);
	if ((s != NULL) && (len > 0))
		txdly = simple_strtoul(s, NULL, 10);

	s = getenv("rgmiidelay");
	if (s != NULL)
		rxdly = txdly = simple_strtoul(s, NULL, 10);

	eim_mac_config_set(LAN_MAC_MODE_AUTO, duplex, flow);

	if (port == PORT_XMII0)
		eim_mii_config_set(0, miicfg);
	else {
		/* make sure port 1 can used by setting port 0 to RGMII */
		eim_mii_config_set(0, EIM_MII_CFG_MIIRATE_M25 | EIM_MII_CFG_MIIMODE_RGMII);
		eim_mii_config_set(1, miicfg);
	}

	/* always write rgmii delay, doesn't hurt in other modes */
	if (port == PORT_XMII0)
		eim_w32_mask(EIM_PCDU_RXDLY_MASK | EIM_PCDU_TXDLY_MASK,
			((rxdly << EIM_PCDU_RXDLY_OFFSET) & EIM_PCDU_RXDLY_MASK) |
			((txdly << EIM_PCDU_TXDLY_OFFSET) & EIM_PCDU_TXDLY_MASK),
			mii_pdi[0].pcdu);
	else
		eim_w32_mask(EIM_PCDU_RXDLY_MASK | EIM_PCDU_TXDLY_MASK,
			((rxdly << EIM_PCDU_RXDLY_OFFSET) & EIM_PCDU_RXDLY_MASK) |
			((txdly << EIM_PCDU_TXDLY_OFFSET) & EIM_PCDU_TXDLY_MASK),
			mii_pdi[1].pcdu);

	return 0;
}
#endif

#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
static int sgmii_init(void)
{
	static int sgmii_is_initialized = 0;
	u32 cfg;
	int cnt;
	const char *s = NULL;
	int invrx = 0;
	int invtx = 0;

	/* default MAC setup */
	eim_mac_config_set(LAN_MAC_MODE_GMII, LAN_MAC_MODE_DUPLEX_FULL,
		LAN_MAC_MODE_FLOW_AUTO);

	if (sgmii_is_initialized)
		goto skip_init;

	sgmii_is_initialized = 1;

	if (hwconfig_sub("SGMII", "invrx"))
		invrx = 1;

	if (hwconfig_sub("SGMII", "invtx"))
		invtx = 1;

	s = getenv("sgmii_inv");
	if (s != NULL)
		invtx = (simple_strtoul(s, NULL, 10) != 0);

	sgmii_w32_mask(PLL_REGFILE_A_CTRL4_MMD_MASK, 0x2E<<PLL_REGFILE_A_CTRL4_MMD_OFFSET,
		pll_regfile_a_ctrl4);
	sgmii_w32_mask(0, PLL_REGFILE_A_CTRL2_LF_MODE,
		pll_regfile_a_ctrl2);
	sgmii_w32_mask(PLL_REGFILE_A_CTRL1_CP_SEL_MASK, 0,
		pll_regfile_a_ctrl1);

	/* restart SGMII PHY */
	cfg = PMA_REGFILE_STARTUP_CTRL_SKIP_CAL | PMA_REGFILE_STARTUP_CTRL_PD | PMA_REGFILE_STARTUP_CTRL_PLL_PD | PMA_REGFILE_STARTUP_CTRL_BYPASS;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg &= ~PMA_REGFILE_STARTUP_CTRL_PLL_PD;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg |= PMA_REGFILE_STARTUP_CTRL_PLL_RSTN;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg &= ~PMA_REGFILE_STARTUP_CTRL_PD;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg |= PMA_REGFILE_STARTUP_CTRL_CLK_EN;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg |= PMA_REGFILE_STARTUP_CTRL_RSTN_PMD;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg |= PMA_REGFILE_STARTUP_CTRL_RSTN_DIG;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);
	cfg |= PMA_REGFILE_STARTUP_CTRL_STARTUP_RDY;
	sgmii_w32(cfg, pma_regfile_startup_ctrl);

	sgmii_w32_mask(RX_REGFILE_CTRL1_PI_CTRL_MASK | RX_REGFILE_CTRL1_LOAD | RX_REGFILE_CTRL1_FLIP | RX_REGFILE_CTRL1_HALFRATE,
			(15<<RX_REGFILE_CTRL1_PI_CTRL_OFFSET) | RX_REGFILE_CTRL1_LOAD | RX_REGFILE_CTRL1_HALFRATE,
		rx_regfile_ctrl1);
	udelay(1); /* wait a micro second */
	sgmii_w32_mask(RX_REGFILE_CTRL1_LOAD, 0,
		rx_regfile_ctrl1);
	if (invrx)
		sgmii_w32_mask(0, RX_REGFILE_CTRL1_INV_EN, rx_regfile_ctrl1);
	sgmii_w32_mask(RX_REGFILE_CDR_COMP_MASK | RX_REGFILE_CDR_SUM_INT | RX_REGFILE_CDR_DUMPINT_MASK,
		(4<<RX_REGFILE_CDR_COMP_OFFSET) | RX_REGFILE_CDR_XOR_INV,
		rx_regfile_cdr);
	sgmii_w32_mask(RX_REGFILE_EI_ENDCNT_MASK, (4<<RX_REGFILE_EI_ENDCNT_OFFSET),
		rx_regfile_ei);

	sgmii_w32_mask(TX_REGFILE_0_CTRL1_INV_EN | TX_REGFILE_0_CTRL1_FORCE | TX_REGFILE_0_CTRL1_FLIP | TX_REGFILE_0_CTRL1_HALFRATE, TX_REGFILE_0_CTRL1_HALFRATE,
		tx_regfile_0_ctrl1);
	if (invtx)
		sgmii_w32_mask(0, TX_REGFILE_0_CTRL1_INV_EN, tx_regfile_0_ctrl1);

	sgmii_w32_mask(TX_REGFILE_1_CTRL1_INV_EN | TX_REGFILE_1_CTRL1_FLIP | TX_REGFILE_1_CTRL1_HALFRATE, TX_REGFILE_1_CTRL1_HALFRATE,
		tx_regfile_1_ctrl1);
	if (invtx)
		sgmii_w32_mask(0, TX_REGFILE_1_CTRL1_INV_EN, tx_regfile_1_ctrl1);
	sgmii_w32_mask(TX_REGFILE_0_A_CTRL2_PREDRV_SER_EN_MASK, 4<<TX_REGFILE_0_A_CTRL2_PREDRV_SER_EN_OFFSET,
		tx_regfile_0_a_ctrl2);
	sgmii_w32_mask(TX_REGFILE_0_CTRL3_CNTR_LIM_MASK, 0x1FFF<<TX_REGFILE_0_CTRL3_CNTR_LIM_OFFSET,
		tx_regfile_0_ctrl3);
	sgmii_w32_mask(TX_REGFILE_0_A_CTRL1_CTRL_MASK, 8<<TX_REGFILE_0_A_CTRL1_CTRL_OFFSET,
		tx_regfile_0_a_ctrl1);
	sgmii_w32_mask(TX_REGFILE_0_A_CTRL2_PREDRV_SER_EN_MASK, 0x44<<TX_REGFILE_0_A_CTRL2_PREDRV_SER_EN_OFFSET,
		tx_regfile_0_a_ctrl2);

	sxgmii_w32_mask(RXBCFG_DLY_WP_MASK, 2<<RXBCFG_DLY_WP_OFFSET,
		s_sgmii_pcs_pdi_rxbcfg);
	sxgmii_w32_mask(TXBCFG_DLY_WP_MASK, 2<<TXBCFG_DLY_WP_OFFSET,
		s_sgmii_pcs_pdi_txbcfg);
	sxgmii_w32_mask(TBICTL_INITTBI, TBICTL_ENTBI,
		tbi_pdi_tbictl);

skip_init:
	cnt = 200;
	while ((sxgmii_r32(tbi_pdi_tbistat) & TBISTAT_SSTAT) == 0) {
		if (--cnt == 0) {
			printf("Error: SGMII TBI not in sync!\n");
			return 1;
		}
		udelay(10);
	}

	return 0;
}

static int sgmii_aneg(struct eth_device *dev)
{
	int cnt;
	u32 reg;

	/* if ANEG not enabled? */
	if ((sxgmii_r32(tbi_pdi_anegctl) & ANEGCTL_ANEGEN) != ANEGCTL_ANEGEN_ENABLE) {
		puts("SGMII: enable ANEG\n");
		sys_eth_w32_mask(SYS_ETH_SGMIIC_ANP, SYS_ETH_SGMIIC_ANP_SGMIIM,
			sgmiic);
		/* setup ANEG data */
		sxgmii_w32(0, tbi_pdi_txanegh);
		sxgmii_w32(1, tbi_pdi_txanegl);
		/* enable aneg */
		sxgmii_w32_mask(ANEGCTL_OVRABL_OVERRIDE | ANEGCTL_RANEG_RESTART | ANEGCTL_LT_MASK,
			ANEGCTL_OVRANEG_OVERRIDE | ANEGCTL_ANEGEN_ENABLE | ANEGCTL_LT_T_1_6MS,
			tbi_pdi_anegctl);
	}

	cnt = 100;
	while ((sxgmii_r32(tbi_pdi_tbistat) & TBISTAT_LSTAT) == 0) {
		if (--cnt == 0) {
			puts("SGMII ANEG: No LSTAT\n");
			return -1;
		}
		udelay(1000); /* 1 ms */
	}
	if (sxgmii_r32(tbi_pdi_tbistat) & TBISTAT_ANEGERR)
		puts("Warning: SGMII ANEG Error!\n");

	/* ack the interrupts */
	sxgmii_w32(sxgmii_r32(tbi_pdi_istat), tbi_pdi_istat);

	reg = sxgmii_r32(tbi_pdi_lpstat);
	while ((reg & LPSTAT_DR_MASK) == LPSTAT_DR_INVALID) {
		cnt = 500;
		while ((sxgmii_r32(tbi_pdi_istat) & ISTAT_ANEG_BP) == 0) {
			if (--cnt == 0) {
				puts("SGMII: no PHY Link!\n");
				return -1;
			}
			udelay(100);
		}
		reg = sxgmii_r32(tbi_pdi_lpstat);
	}

	if ((reg & LPSTAT_DR_MASK) == LPSTAT_DR_INVALID) {
		/* still invalid */
		puts("SGMII: Invalid Datarate!\n");
		return -1;
	}

	sys_eth_hw_clk_disable(SYS_ETH_CLKEN_GMAC0);
	switch (reg & LPSTAT_DR_MASK) {
	case LPSTAT_DR_DR10:
		sys_eth_w32_mask(SYS_ETH_DRC_SGMII_MASK,
			SYS_ETH_DRC_SGMII_DR10, drc);
		break;
	case LPSTAT_DR_DR100:
		sys_eth_w32_mask(SYS_ETH_DRC_SGMII_MASK,
			SYS_ETH_DRC_SGMII_DR100, drc);
		break;
	case LPSTAT_DR_DR1000:
		sys_eth_w32_mask(SYS_ETH_DRC_SGMII_MASK,
			SYS_ETH_DRC_SGMII_DR1000, drc);
		break;
	}
	sys_eth_hw_clk_enable(SYS_ETH_CLKEN_GMAC0);
	if ((reg & LPSTAT_DPX) == LPSTAT_DPX_FD)
		eim_mac_config_set(LAN_MAC_MODE_GMII, LAN_MAC_MODE_DUPLEX_FULL,
			LAN_MAC_MODE_FLOW_AUTO);
	else
		eim_mac_config_set(LAN_MAC_MODE_GMII, LAN_MAC_MODE_DUPLEX_HALF,
			LAN_MAC_MODE_FLOW_AUTO);

	return 0;
}
#endif

#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY)
/**
 * Boot a GPHY instance
 * \param phyno[in]     select GPHY instance
 * \param addr1[in]     MDIO address 1
 * \param addr2[in]     MDIO address 2
 * \return 0            Boot successful
 *         -1           Error
 */
static int gphy_boot(u32 phyno, u32 addr1, u32 addr2)
{
	/* address of gphy firmware in ROM */
	static const u32 *gphy11g_image_A11 = (u32 *)0xbf020000;
	static const u32 *gphy11g_image_A12 = (u32 *)0xbf018000;
	u32 gphy11g_image;
	u32 ier, isr;

	if (phyno > 1)
		return -1;

	/* detect correct address of gphy firmware */
	if (*gphy11g_image_A12 == 0xAAAAAAAA)
		gphy11g_image = (u32)gphy11g_image_A11;
	else
		gphy11g_image = (u32)gphy11g_image_A12;

	if (phyno == 0)
		sbs0ctrl_w32(gphy11g_image & SBS0CTRL_GPHY0IMG_ADDRV_MASK,
			gphy0img);
	else
		sbs0ctrl_w32(gphy11g_image & SBS0CTRL_GPHY1IMG_ADDRV_MASK,
			gphy1img);

	if (phyno == 0) {
		if (is_falcon_chip_a1x()) {
			ier = EIM_EIM_IER_A1X_GPHY0_IEN_EN;
			isr = EIM_EIM_ISR_A1X_GPHY0_IRQ;
		} else {
			ier = EIM_EIM_IER_A2X_GPHY0_IEN_EN;
			isr = EIM_EIM_ISR_A2X_GPHY0_IRQ;
		}
	} else {
		if (is_falcon_chip_a1x()) {
			ier = EIM_EIM_IER_A1X_GPHY1_IEN_EN;
			isr = EIM_EIM_ISR_A1X_GPHY1_IRQ;
		} else {
			ier = EIM_EIM_IER_A2X_GPHY1_IEN_EN;
			isr = EIM_EIM_ISR_A2X_GPHY1_IRQ;
		}
	}
	sys_eth_hw_activate_or_reboot((phyno == 0) ? SYS_ETH_ACT_GPHY0 :
						     SYS_ETH_ACT_GPHY1);

	eim_w32(((addr1 << EIM_GPHY_CFG_ADDR_PHYADR1_OFFSET) &
					EIM_GPHY_CFG_ADDR_PHYADR1_MASK)
		| ((addr2 << EIM_GPHY_CFG_ADDR_PHYADR2_OFFSET) &
					EIM_GPHY_CFG_ADDR_PHYADR2_MASK),
		top_pdi.gphy_cfg_addr[phyno]);

	/* enable the interrupt for gphy */
	eim_w32_mask(0, ier, top_pdi.eim_ier);
	/* do hard reset on gphy (srst does not work reliable) */
	sys_eth_w32((phyno == 0) ? SYS_ETH_RBT_GPHY0_TRIG :
				   SYS_ETH_RBT_GPHY1_TRIG, rbt);

	/* wait for interrupt */
	while ((eim_r32(top_pdi.eim_isr) & isr) == 0) {
		};
	/* disable interrupt */
	eim_w32_mask(ier, 0, top_pdi.eim_ier);
	/* acknowledge interrupt */
	eim_w32_mask(isr, 0, top_pdi.eim_isr);

	return 0;
}
#endif

static int falcon_init(struct eth_device *dev, bd_t *bis)
{
	struct eth_port *priv = dev->priv;
	static const uint32_t gmuxc[] = {
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY)
	[PORT_GPHY0] =
		SYS_ETH_GMUXC_GMAC0_GPHY0_GMII |
		SYS_ETH_GMUXC_GMAC1_GPHY0_MII2 |
		SYS_ETH_GMUXC_GMAC2_GPHY1_GMII |
		SYS_ETH_GMUXC_GMAC3_GPHY1_MII2,
	[PORT_GPHY1] =
		SYS_ETH_GMUXC_GMAC0_GPHY1_GMII |
		SYS_ETH_GMUXC_GMAC1_GPHY0_MII2 |
		SYS_ETH_GMUXC_GMAC2_GPHY0_GMII |
		SYS_ETH_GMUXC_GMAC3_GPHY1_MII2,
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_xMII)
	[PORT_XMII0] =
		SYS_ETH_GMUXC_GMAC0_xMII0 |
		SYS_ETH_GMUXC_GMAC1_GPHY0_MII2 |
		SYS_ETH_GMUXC_GMAC2_GPHY1_GMII |
		SYS_ETH_GMUXC_GMAC3_GPHY1_MII2,
	[PORT_XMII1] =
		SYS_ETH_GMUXC_GMAC0_xMII1 |
		SYS_ETH_GMUXC_GMAC1_GPHY0_MII2 |
		SYS_ETH_GMUXC_GMAC2_GPHY1_GMII |
		SYS_ETH_GMUXC_GMAC3_GPHY1_MII2,
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
	[PORT_SGMII] =
		SYS_ETH_GMUXC_GMAC0_SGMII |
		SYS_ETH_GMUXC_GMAC1_GPHY0_MII2 |
		SYS_ETH_GMUXC_GMAC2_GPHY1_GMII |
		SYS_ETH_GMUXC_GMAC3_GPHY1_MII2,
#endif
	};

	falcon_ll_hwinit();
	falcon_set_hwaddr(dev->enetaddr);
	sys_eth_hw_activate(priv->sys_eth_act);

	/* setup port */
	switch (priv->port) {
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY)
	case PORT_GPHY0:
	case PORT_GPHY1:
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_xMII)
	case PORT_XMII0:
	case PORT_XMII1:
		xmii_init(dev, priv->port, priv->miicfg);
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
	case PORT_SGMII:
		sgmii_init();
		break;
#endif
	}

	/* connect gmac to port */
	sys_eth_w32(gmuxc[priv->port], gmuxc);

#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
	if (priv->port == PORT_SGMII)
		return sgmii_aneg(dev);
	else
#endif
		return update_port_speed(dev);
}

static int falcon_miiphy_read(const char *devname, unsigned char addr,
	unsigned char reg, unsigned short *value)
{
	return eim_mdio_data_read(addr, reg, value);
}

static int falcon_miiphy_write(const char *devname, unsigned char addr,
	unsigned char reg, unsigned short value)
{
	return eim_mdio_data_write(addr, reg, value);
}

static void falcon_autoset_ethprime(void)
{
	char *ethprime;

	/* setup default interface for network boot, depending on bootmode */
	switch (sys1_r32(bmc) & BMC_BM_MASK) {
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_RGMII0)
	case 9:
	case 10:
	case 11:
	case 12:
		ethprime = "RGMII0";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_RGMII1)
	case 13:
	case 14:
	case 15:
	case 16:
		ethprime = "RGMII1";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GMII_PHY)
	case 17:
		ethprime = "GMII_PHY";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GMII_MAC)
	case 18:
		ethprime = "GMII_MAC";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_MII_PHY)
	case 19:
		ethprime = "MII_PHY";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_MII_MAC)
	case 20:
		ethprime = "MII_MAC";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY0)
	case 21:
		ethprime = "GPHY0";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY1)
	case 22:
		ethprime = "GPHY1";
		break;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_SGMII)
	case 23:
	case 24:
	case 25:
		ethprime = "SGMII";
		break;
#endif
	default:
		ethprime = NULL;
		break;
	}
	if (ethprime)
		setenv("ethprime", ethprime);
}

int falcon_net_register(unsigned int falcon_net_mask)
{
	struct eth_device *dev;
	int i, cnt = 0;
	const char *s;
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY)
	size_t len;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY0)
	unsigned long gphy0_phyaddr = 0;
#endif
#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY1)
	unsigned long gphy1_phyaddr = 1;
#endif

	debug("Support mask: compiled 0x%X, detected 0x%X\n",
		CONFIG_FALCON_NET_PORT_MASK, falcon_net_mask);

	for (i = 0; i < ARRAY_SIZE(falcon_eth_ports); i++) {
		/*
		   if interface is selected from hwconfig, register it,
		   otherwise only register interfaces valid for falcon-type
		   (allows testing of interfaces on non-qualified chips also)
		*/
		debug("Check for %s: ", falcon_eth_ports[i].name);
		if (!hwconfig(falcon_eth_ports[i].name))
			if (((falcon_eth_ports[i].port_mask & falcon_net_mask) == 0) ||
			    (!support_falcon_type(falcon_eth_ports[i].support_mask))) {
				debug("skip!\n");
				continue;
			}
		debug("register\n");
		dev = (struct eth_device *) malloc(sizeof(*dev));
		if (!dev) {
			puts("Memory allocation error\n");
			break;
		}

		memset(dev, 0, sizeof(*dev));

		sprintf(dev->name, "%s", falcon_eth_ports[i].name);
		dev->init = falcon_init;
		dev->halt = falcon_halt;
		dev->send = falcon_send;
		dev->recv = falcon_recv;
		dev->priv = (void *)&falcon_eth_ports[i];

		eth_register(dev);
		cnt++;
	}

	if (!getenv("ethprime"))
		falcon_autoset_ethprime();

	eim_init();
	miiphy_register(mdio_name, falcon_miiphy_read, falcon_miiphy_write);

#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY0)
	s = hwconfig_subarg("GPHY0", "phyaddr", &len);
	if ((s != NULL) && (len > 0))
		gphy0_phyaddr = simple_strtoul(s, NULL, 10);
	else {
		s = getenv("gphy0_phyaddr");
		if (s != NULL)
			gphy0_phyaddr = simple_strtoul(s, NULL, 10);
	}
	gphy_boot(0, gphy0_phyaddr, 2);
#endif

#if (CONFIG_FALCON_NET_PORT_MASK & FALCON_NET_PORT_MASK_GPHY1)
	if (support_falcon_type(FALCON_V | FALCON_M) || hwconfig("GPHY1")) {
		s = hwconfig_subarg("GPHY1", "phyaddr", &len);
		if ((s != NULL) && (len > 0))
			gphy1_phyaddr = simple_strtoul(s, NULL, 10);
		else {
			s = getenv("gphy1_phyaddr");
			if (s != NULL)
				gphy1_phyaddr = simple_strtoul(s, NULL, 10);
		}
		gphy_boot(1, gphy1_phyaddr, 3);
	}
#endif

	s = getenv("extphy");
	if (s != NULL)
		falcon_extphy_enable(simple_strtoul(s, NULL, 0));

	return cnt;
}
