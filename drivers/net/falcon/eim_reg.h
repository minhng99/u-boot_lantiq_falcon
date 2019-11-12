/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _eim_reg_h
#define _eim_reg_h

/** \addtogroup EIM_REGISTER
   @{
*/
/* access macros */
#define eim_a1x_r32(reg) reg_r32(&eim_a1x->reg)
#define eim_a1x_w32(val, reg) reg_w32(val, &eim_a1x->reg)
#define eim_a1x_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &eim_a1x->reg)

#define eim_a2x_r32(reg) reg_r32(&eim_a2x->reg)
#define eim_a2x_w32(val, reg) reg_w32(val, &eim_a2x->reg)
#define eim_a2x_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &eim_a2x->reg)

#define eim_r32(reg) (is_falcon_chip_a1x()?eim_a1x_r32(reg):eim_a2x_r32(reg))
#define eim_w32(val, reg) \
	do { \
		if (is_falcon_chip_a1x()) \
			eim_a1x_w32(val, reg); \
		else \
			eim_a2x_w32(val, reg); \
	} while(0)
#define eim_w32_mask(clear, set, reg) \
	do { \
		if (is_falcon_chip_a1x()) \
			eim_a1x_w32_mask(clear, set, reg); \
		else \
			eim_a2x_w32_mask(clear, set, reg); \
	} while(0)


/** EIM_MACS_TOP_PDI: Ethernet MAC Toplevel Registers */
struct eim_macs_top_pdi
{
   /** MAC Test Register
       This register is used to select test functions. */
   unsigned int mac_test; /* 0x00000000 */
   /** MAC Pause Frame Source Address Configuration Register
       This register is used to configure if a common MAC source address is used for transmitted Pause frames on all Ethernet ports or if individual addresses are used. */
   unsigned int mac_pfad_cfg; /* 0x00000004 */
   /** Pause Frame Source Address Part 0
       This register is used to configure the Pause frame source address. */
   unsigned int mac_pfsa[3]; /* 0x00000008 */
   /** MAC Frame Length Register
       This register is used to configure the maximum frame length for Jumbo frames. */
   unsigned int mac_flen; /* 0x00000014 */
   /** MAC VLAN Ethertype Register 0
       This register is used to configure the Ethertype to detect an outer VLAN tag. */
   unsigned int mac_vlan_etype[2]; /* 0x00000018 */
};

/** EIM_MAC_PDI: Ethernet MAC Registers */
struct eim_mac_pdi_a1x
{
   /** MAC Port Status Register
       This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process. */
   unsigned int pstat; /* 0x00000020 */
   /** MAC Interrupt Status Register
       This register provides information about the current status of the Ethernet MAC and generates an interrupt. */
   unsigned int pisr; /* 0x00000024 */
   /** MAC Interrupt Enable Register
       This register enables the activation of interrupts. */
   unsigned int pier; /* 0x00000028 */
   /** MAC Control Register 0
       This register is used to configure the Ethernet MAC. */
   unsigned int ctrl_0; /* 0x0000002C */
   /** MAC Control Register 1
       This register is used to configure the Ethernet MAC. */
   unsigned int ctrl_1; /* 0x00000030 */
   /** MAC Control Register 2
       This register is used to configure the maximum frame length to be received. */
   unsigned int ctrl_2; /* 0x00000034 */
   /** MAC Control Register 3
       This register is used to configure the frame handling in half-duplex mode. */
   unsigned int ctrl_3; /* 0x00000038 */
   /** MAC Control Register 4
       This register is used to configure the LPI function. */
   unsigned int ctrl_4; /* 0x0000003C */
   /** MAC Control Register 5
       This register is used to configure the Jam pattern size. */
   unsigned int ctrl_5; /* 0x00000040 */
   /** Transmit and Receive Buffer Control Register
       This register is used to configure the internal buffer configuration. */
   unsigned int ctrl_6; /* 0x00000044 */
   /** MAC Receive and Transmit Buffer Status Register
       This register is used to indicate the internal buffer status. */
   unsigned int bufst; /* 0x00000048 */
   /** MAC Test Enable Register
       This register is used to select MAC-related test functions. */
   unsigned int testen; /* 0x0000004C */
};

/** EIM_MAC_PDI: Ethernet MAC Registers */
struct eim_mac_pdi_a2x
{
   /** MAC Port Status Register
       This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process. */
   unsigned int pstat; /* 0x00000028 */
   /** MAC Interrupt Status Register
       This register provides information about the current status of the Ethernet MAC and generates an interrupt. */
   unsigned int pisr; /* 0x0000002C */
   /** MAC Interrupt Enable Register
       This register enables the activation of interrupts. */
   unsigned int pier; /* 0x00000030 */
   /** MAC Control Register 0
       This register is used to configure the Ethernet MAC. */
   unsigned int ctrl_0; /* 0x00000034 */
   /** MAC Control Register 1
       This register is used to configure the Ethernet MAC. */
   unsigned int ctrl_1; /* 0x00000038 */
   /** MAC Control Register 2
       This register is used to configure the maximum frame length to be received. */
   unsigned int ctrl_2; /* 0x0000003C */
   /** MAC Control Register 3
       This register is used to configure the frame handling in half-duplex mode. */
   unsigned int ctrl_3; /* 0x00000040 */
   /** MAC Control Register 4
       This register is used to configure the LPI function. */
   unsigned int ctrl_4; /* 0x00000044 */
   /** MAC Control Register 5
       This register is used to configure the Jam pattern size. */
   unsigned int ctrl_5; /* 0x00000048 */
   /** MAC Test Enable Register
       This register is used to select MAC-related test functions. */
   unsigned int testen; /* 0x0000004C */
};

/** EIM_TOP_PDI: GPON Ethernet Interface Module Toplevel Registers */
struct eim_top_pdi
{
   /** Reset Control Register */
   unsigned int gphy_ctl;
   /** GPHY Version Configuration Register */
   unsigned int gphy_cfg_ver;
   /** GPHY PLL Configuration Register */
   unsigned int gphy_cfg_pll;
   /** GPHY General Configuration Register */
   unsigned int gphy_cfg_gen[2];
   /** GPHY Auto-Negotiation Capability Configuration Register */
   unsigned int gphy_cfg_aneg[2];
   /** GPHY PHY Address Configuration Register */
   unsigned int gphy_cfg_addr[2];
   /** Configuration register for Strobe Generator 0 (2Hz target frequency) */
   unsigned int eim_strb_gen0_ctl;
   /** Configuration register for Strobe Generator 1 (25MHz target frequency) */
   unsigned int eim_strb_gen1_ctl;
   /** Configuration register for Packet Engine Interface 0 */
   unsigned int eim_lan_ifc_cfg_0;
   /** Configuration register for Packet Engine Interface 1  */
   unsigned int eim_lan_ifc_cfg_1;
   /** MIB Counter (FCS Errored Frames) */
   unsigned int eim_mib_fcser[4];
   /** MIB Counter (Oversized Frames) */
   unsigned int eim_mib_ovsz[4];
   /** MIB Counter (Misaligned Frames) */
   unsigned int eim_mib_algn[4];
   /** MIB Counter (Late Collsions) */
   unsigned int eim_mib_late_col[4];
   /** MIB Counter (Excessive Collisions) */
   unsigned int eim_mib_exc_col[4];
   /** MIB Counter (Single Collisions) */
   unsigned int eim_mib_sgl_col[4];
   /** MIB Counter (Multiple Collisions) */
   unsigned int eim_mib_mul_col[4];
   /** MIB Counter (Deferred Transmission) */
   unsigned int eim_mib_def_trans[4];
   /** Central EIM Interrupt Enable */
   unsigned int eim_ier;
   /** Central EIM Interrupt Register */
   unsigned int eim_isr;
};

/** EIM_MDIO_MAC_PDI: This is the register description of the MDIO interface (MAC part) */
struct eim_mdio_mac_pdi
{
   /** Interrupt Status Register */
   unsigned int istat; /* 0x0000019C */
   /** Interrupt Enable Register */
   unsigned int ienable; /* 0x000001A0 */
   /** Configuration Register */
   unsigned int cfg; /* 0x000001A4 */
   /** Startup Phase Data Register
       This register holds the DATA DEVAD, the PHYAD, the ST and OP fields, which are currently received by the mdio interface serial to parallel converter, independent on MAC read or PHY receive mode. The data stored in this register will be written from the HW (during a MAC transmit or a PHY receive mode) and could be observed by CPU / SW. After an MAC transmit or MAC receive or PHY receive access has finished the data are xxx.... */
   unsigned int startup; /* 0x000001A8 */
   /** Mac Data Transmit Register
       Only used in MAC mode. Data to be transmitted to the PHY on the mdio interface in mac mode. */
   unsigned int mac_data; /* 0x000001AC */
   /** Mac Header Transmit Register
       Only used in MAC mode. Header to be transmitted to the PHY. With this register it also chosen what kind of access (read or write) should be done. With the start_tx bit the transmission of the mdio frame to the PHY is started. The rw bit decides about the kind of access (read / write) independent of the content of the programmed bits in the bit positions 15:0 */
   unsigned int mac_header; /* 0x000001B0 */
   /** MAC Preamble Transmit Length Register
       This register is only used in MAC mode. With this register the length of the transmitted preamble length (ones) can be set, the IEEE assumes 32 bit, but many PHY's have the ability to handle so called short preambles. With this register the preamble length up front an read or write access could be set. The register is used only in MAC mode while sending the preamble. */
   unsigned int preamble; /* 0x000001B4 */
   /** Preamble Length Register
       This register is used in MAC and PHY mode for all the incoming (received) data. In both cases the input is observing the mdio pin. In MAC mode the register must have the same content as the 'preamble' register. In MAC or PHY mode the register is used by the mdio_read_phy_fsm to detect the earliest possible position of the ST bits at the end of the preamble. */
   unsigned int preamble_incoming; /* 0x000001B8 */
};

/** ETHSW_EIM_MDIO_PDI: MDIO Master and Global Control and Status Registers */
struct ethsw_eim_mdio_pdi
{
   /** MDIO Control Register
       This register is used to access devices that are connected to the serial MDIO master interface, internally or externally. */
   unsigned int mdio_ctrl; /* 0x00000184 */
   /** MDIO Read Data Register
       This register is used to read back data across the serial MDIO master interface, internally or externally. */
   unsigned int mdio_read; /* 0x00000188 */
   /** MDIO Write Data Register
       This register is used to write data across the serial MDIO master interface, internally or externally. */
   unsigned int mdio_write; /* 0x0000018C */
   /** MDC Clock Configuration Register 0
       This register is used to control the MDC clock output and polling state machine. */
   unsigned int mdc_cfg_0; /* 0x00000190 */
   /** MDC Clock Configuration Register 1
       This register is used to configure clocking rate for the MDIO master interfaces. */
   unsigned int mdc_cfg_1; /* 0x00000194 */
   /** PHY Address Register PORT 0
       This register is used to define the phy address of the port. */
   unsigned int phy_addr[4]; /* 0x00000198 */
   /** PHY MDIO Polling Status per PORT
       This register provides information about the current status of the attached Ethernet PHY retrieved by using the auto-polling process. */
   unsigned int mdio_stat[4]; /* 0x000001A8 */
   /** EEE auto negotiation overides
       Overide what is conveyd to the MAC from the auto negotiation with PHY. */
   unsigned int aneg_eee[4]; /* 0x000001B8 */
};

/** EIM_MII_PDI: xMII Control Registers */
struct eim_mii_pdi
{
   /** xMII Port Configuration Register
       This register controls the settings of the xMII Interface. */
   unsigned int mii_cfg;
   /** Configuration of Clock Delay
       This register controls the settings of the receive and transmit clock delay (used for RGMII mode only). */
   unsigned int pcdu;
   /** Configuration of Jitter Buffer */
   unsigned int buff;
};

/** EIM register structure for A1x version */
struct gpon_reg_eim_a1x
{
   struct eim_macs_top_pdi macs_top_pdi;	/* 0x00000000--0x0000001F */
   struct eim_mac_pdi_a1x mac_pdi[4];		/* 0x00000020--0x000000DF */
   struct eim_top_pdi top_pdi;			/* 0x000000E0--0x0000019B */
   struct eim_mdio_mac_pdi mdio_mac_pdi;	/* 0x0000019C--0x000001BB */
   struct eim_mii_pdi mii_pdi[2];		/* 0x000001BC--0x000001D3 */
};

/** EIM register structure for A2x version */
struct gpon_reg_eim_a2x
{
   struct eim_macs_top_pdi macs_top_pdi;	/* 0x00000000--0x0000001F */

   /** MAC Interrupt Enable Register
       This register is used to enable or disable all MAC interrupts per port. */
   unsigned int macs_top_pdi_mac_ier;		/* 0x00000020 */
   /** MAC Interrupt Status Register
       This register collects the interrupt status information that is provided per port. */
   unsigned int macs_top_pdi_mac_isr;		/* 0x00000024 */

   struct eim_mac_pdi_a2x mac_pdi[4];		/* 0x00000028--0x000000C7 */

   struct eim_top_pdi top_pdi;			/* 0x000000C8--0x00000183 */
   struct ethsw_eim_mdio_pdi mdio_pdi;		/* 0x00000184--0x000001C7 */
   struct eim_mii_pdi mii_pdi[2];		/* 0x000001C8--0x000001DF */

};

/* Fields of "MAC Test Register" */
/** Jitter Test Pattern
    User definable test pattern for jitter test mode 3. */
#define EIM_MAC_TEST_JTP_MASK 0x0000FFFF
/** field offset */
#define EIM_MAC_TEST_JTP_OFFSET 0

/* Fields of "MAC Pause Frame Source Address Configuration Register" */
/** Source Address Mode
    Enables individual MAC source addresses per Ethernet port for transmitted Pause frames. */
#define EIM_MAC_PFAD_CFG_SAMOD 0x00000001
/* pause frames use a common MAC source address
#define EIM_MAC_PFAD_CFG_SAMOD_COMMON 0x00000000 */
/** pause frames use a port-specific MAC source address */
#define EIM_MAC_PFAD_CFG_SAMOD_PORT 0x00000001

/* Fields of "Pause Frame Source Address Part 0" */
/** Pause Frame Source Address Part 0
    Defines bit 15:0 of the Pause frame source address. */
#define EIM_MAC_PFSA_PFAD_MASK 0x0000FFFF
/** field offset */
#define EIM_MAC_PFSA_PFAD_OFFSET 0

/* Fields of "MAC Frame Length Register" */
/** Maximum Frame Length
    Defines the maximum length of frames to be received, given in number of bytes. The count includes the optional VLAN tag(s). */
#define EIM_MAC_FLEN_LEN_MASK 0x00003FFF
/** field offset */
#define EIM_MAC_FLEN_LEN_OFFSET 0

/* Fields of "MAC VLAN Ethertype Register 0" */
/** Ethertype
    Defines the Ethertype associated with the outer VLAN tag. */
#define EIM_MAC_VLAN_ETYPE_OUTER_MASK 0x0000FFFF
/** field offset */
#define EIM_MAC_VLAN_ETYPE_OUTER_OFFSET 0

/* Fields of "MAC Interrupt Enable Register" */
/** MAC Interrupt Enable
    Setting a bit enables MAC interrupts from the related port. */
#define EIM_MAC_IER_MACIEN_MASK 0x0000000F
/** field offset */
#define EIM_MAC_IER_MACIEN_OFFSET 0

/* Fields of "MAC Interrupt Status Register" */
/** MAC Interrupt
    Indicates if an interrupt related to this port needs service. */
#define EIM_MAC_ISR_MACINT_MASK 0x0000000F
/** field offset */
#define EIM_MAC_ISR_MACINT_OFFSET 0

/* Fields of "MAC Port Status Register" */
/** PHY Active Status
    Indicates if the external PHY is responding to MDIO accesses. */
#define EIM_MAC_PSTAT_PACT 0x00000800
/* the PHY is inactive or not present
#define EIM_MAC_PSTAT_PACT_INACTIVE 0x00000000 */
/** the PHY is active and responds to MDIO accesses */
#define EIM_MAC_PSTAT_PACT_ACTIVE 0x00000800
/** Gigabit Speed Status
    Indicates if Gigabit Ethernet speed is used by the Interface. */
#define EIM_MAC_PSTAT_GBIT 0x00000400
/* low speed (10 or 100 Mbit/s)
#define EIM_MAC_PSTAT_GBIT_LOW 0x00000000 */
/** High speed status (1000 Mbit/s or 2000 Mbit/s) */
#define EIM_MAC_PSTAT_GBIT_HIGH 0x00000400
/** Megabit Speed Status
    Indicates if the attached PHY runs at a data rate of 10 or 100 Mbit/s. */
#define EIM_MAC_PSTAT_MBIT 0x00000200
/* 10 Mbit/s
#define EIM_MAC_PSTAT_MBIT_E10 0x00000000 */
/** 100 Mbit/s */
#define EIM_MAC_PSTAT_MBIT_E100 0x00000200
/** Full Duplex Status
    Indicates if the attached PHY runs in half- or full-duplex mode. */
#define EIM_MAC_PSTAT_FDUP 0x00000100
/* half-duplex mode
#define EIM_MAC_PSTAT_FDUP_HALF 0x00000000 */
/** full-duplex mode */
#define EIM_MAC_PSTAT_FDUP_FULL 0x00000100
/** Receive Pause Status
    Indicates if the receive pause status is active in the MAC. */
#define EIM_MAC_PSTAT_RXPAU 0x00000080
/* normal receive operation
#define EIM_MAC_PSTAT_RXPAU_NORM 0x00000000 */
/** receive pause status is active */
#define EIM_MAC_PSTAT_RXPAU_PAU 0x00000080
/** Transmit Pause Status
    Indicates if the transmit pause status is active in the MAC. */
#define EIM_MAC_PSTAT_TXPAU 0x00000040
/* normal transmit operation
#define EIM_MAC_PSTAT_TXPAU_NORM 0x00000000 */
/** transmit pause status is active */
#define EIM_MAC_PSTAT_TXPAU_PAU 0x00000040
/** Receive Pause Enable Status
    This status information is retrieved from the attached Ethernet PHY by polling the related MDIO register. */
#define EIM_MAC_PSTAT_RXPAUEN 0x00000020
/* the link partner does not send pause frames
#define EIM_MAC_PSTAT_RXPAUEN_DIS 0x00000000 */
/** the link partner sends pause frames */
#define EIM_MAC_PSTAT_RXPAUEN_EN 0x00000020
/** Transmit Pause Enable Status
    This status information is retrieved from the attached Ethernet PHY by polling the related MDIO register. */
#define EIM_MAC_PSTAT_TXPAUEN 0x00000010
/* the link partner does not accept pause frames
#define EIM_MAC_PSTAT_TXPAUEN_DIS 0x00000000 */
/** the link partner accepts pause frames */
#define EIM_MAC_PSTAT_TXPAUEN_EN 0x00000010
/** Link Status
    This status information is retrieved from the attached Ethernet PHY by polling the related MDIO register. */
#define EIM_MAC_PSTAT_LSTAT 0x00000008
/* the link is down
#define EIM_MAC_PSTAT_LSTAT_DOWN 0x00000000 */
/** the link is up */
#define EIM_MAC_PSTAT_LSTAT_UP 0x00000008
/** Carrier Sense Status
    Indicates if a carrier is detected in half-duplex mode. */
#define EIM_MAC_PSTAT_CRS 0x00000004
/* no carrier detected
#define EIM_MAC_PSTAT_CRS_NO 0x00000000 */
/** Transmit Low-power Idle Status
    Indicates the Low-power Idle status in transmit direction. This bit is set as long as the LPI_TX_Indicate is received from the EEE transmit state machine. */
#define EIM_MAC_PSTAT_TXLPI 0x00000002
/* normal power state
#define EIM_MAC_PSTAT_TXLPI_NORM 0x00000000 */
/** low-power idle state */
#define EIM_MAC_PSTAT_TXLPI_LPI 0x00000002
/** Receive Low-power Idle Status
    Indicates the Low-power Idle status in receive direction. This bit is set as long as the LPI_RX_Indicate is received from the EEE receive state machine. */
#define EIM_MAC_PSTAT_RXLPI 0x00000001
/* normal power state
#define EIM_MAC_PSTAT_RXLPI_NORM 0x00000000 */
/** low-power idle state */
#define EIM_MAC_PSTAT_RXLPI_LPI 0x00000001

/* Fields of "MAC Interrupt Status Register" */
/** PHY Receive Error
    Indicates the reception of an errored frame. */
#define EIM_MAC_PISR_RXER 0x00004000
/* no interrupt condition detected
#define EIM_MAC_PISR_RXER_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_RXER_INT 0x00004000
/** PHY Active Status
    Indicates a change of link activity. See PSTAT register. */
#define EIM_MAC_PISR_PACT 0x00002000
/* no interrupt condition detected
#define EIM_MAC_PISR_PACT_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_PACT_INT 0x00002000
/** Megabit Speed Status
    Indicates a change of speed mode. See PSTAT register. */
#define EIM_MAC_PISR_SPEED 0x00001000
/* no interrupt condition detected
#define EIM_MAC_PISR_SPEED_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_SPEED_INT 0x00001000
/** Full Duplex Status
    Indicates a change of half- or full-duplex mode. See PSTAT register. */
#define EIM_MAC_PISR_FDUP 0x00000800
/* no interrupt condition detected
#define EIM_MAC_PISR_FDUP_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_FDUP_INT 0x00000800
/** Receive Pause Enable Status
    Indicates a change of Receive Pause Enable Status. See PSTAT register. */
#define EIM_MAC_PISR_RXPAUEN 0x00000400
/* no interrupt condition detected
#define EIM_MAC_PISR_RXPAUEN_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_RXPAUEN_INT 0x00000400
/** Transmit Pause Enable Status
    Indicates a change of Transmit Pause Enable Status. See PSTAT register. */
#define EIM_MAC_PISR_TXPAUEN 0x00000200
/* no interrupt condition detected
#define EIM_MAC_PISR_TXPAUEN_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_TXPAUEN_INT 0x00000200
/** Receive Low-power Idle Mode is left
    Indicates that LPI mode has been left in receive (ingress) direction. */
#define EIM_MAC_PISR_LPIOFF 0x00000100
/* no interrupt condition detected
#define EIM_MAC_PISR_LPIOFF_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_LPIOFF_INT 0x00000100
/** Receive Low-power Idle Mode is entered
    Indicates that a Low-power Idle condition has been detected in receive (ingress) direction. */
#define EIM_MAC_PISR_LPION 0x00000080
/* no interrupt condition detected
#define EIM_MAC_PISR_LPION_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_LPION_INT 0x00000080
/** Jam Status Detected
    Indicates that a Jam condition has been detected. */
#define EIM_MAC_PISR_JAM 0x00000040
/* no interrupt condition detected
#define EIM_MAC_PISR_JAM_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_JAM_INT 0x00000040
/** Too Short Frame Error Detected
    Indicates that a frame has been received which is shorter than the minimum allowed frame length. */
#define EIM_MAC_PISR_TOOSHORT 0x00000020
/* no interrupt condition detected
#define EIM_MAC_PISR_TOOSHORT_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_TOOSHORT_INT 0x00000020
/** Too Long Frame Error Detected
    Indicates that a frame has been received which is longer than the maximum allowed frame length. */
#define EIM_MAC_PISR_TOOLONG 0x00000010
/* no interrupt condition detected
#define EIM_MAC_PISR_TOOLONG_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_TOOLONG_INT 0x00000010
/** Length Mismatch Error Detected
    Indicates that a frames has been received where the indicated length did not fit the actually received number of bytes. */
#define EIM_MAC_PISR_LENERR 0x00000008
/* no interrupt condition detected
#define EIM_MAC_PISR_LENERR_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_LENERR_INT 0x00000008
/** Frame Checksum Error Detected
    Indicates that an FCS error has been detected for an incoming frame. */
#define EIM_MAC_PISR_FCSERR 0x00000004
/* no interrupt condition detected
#define EIM_MAC_PISR_FCSERR_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_FCSERR_INT 0x00000004
/** Pause Frame Transmitted
    Indicates that at least one Pause frame has been transmitted. */
#define EIM_MAC_PISR_TXPAUSE 0x00000002
/* no interrupt condition detected
#define EIM_MAC_PISR_TXPAUSE_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_TXPAUSE_INT 0x00000002
/** Pause Frame Received
    Indicates that at least one Pause frame has been received. */
#define EIM_MAC_PISR_RXPAUSE 0x00000001
/* no interrupt condition detected
#define EIM_MAC_PISR_RXPAUSE_NOINT 0x00000000 */
/** interrupt condition has been detected at least once */
#define EIM_MAC_PISR_RXPAUSE_INT 0x00000001
/* Fields of "MAC Interrupt Enable Register" */
/** PHY Receive Error (A1X) */
#define EIM_MAC_PIER_A1X_RXER 0x00004000
/* interrupt is disabled (default)
#define EIM_MAC_PIER_A1X_RXER_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_A1X_RXER_EN 0x00004000
/** PHY Error Interrupt (A2X) */
#define EIM_MAC_PIER_A2X_PHYERR 0x00008000
/* interrupt is disabled (default)
#define EIM_MAC_PIER_PHYERR_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_A2X_PHYERR_EN 0x00008000
/** Allignment Error Interrupt (A2X) */
#define EIM_MAC_PIER_A2X_ALIGN 0x00004000
/* interrupt is disabled (default)
#define EIM_MAC_PIER_ALIGN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_A2X_ALIGN_EN 0x00004000
/** PHY Active Status */
#define EIM_MAC_PIER_PACT 0x00002000
/* interrupt is disabled (default)
#define EIM_MAC_PIER_PACT_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_PACT_EN 0x00002000
/** Megabit Speed Status */
#define EIM_MAC_PIER_SPEED 0x00001000
/* interrupt is disabled (default)
#define EIM_MAC_PIER_SPEED_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_SPEED_EN 0x00001000
/** Full Duplex Status */
#define EIM_MAC_PIER_FDUP 0x00000800
/* interrupt is disabled (default)
#define EIM_MAC_PIER_FDUP_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_FDUP_EN 0x00000800
/** Receive Pause Enable Status */
#define EIM_MAC_PIER_RXPAUEN 0x00000400
/* interrupt is disabled (default)
#define EIM_MAC_PIER_RXPAUEN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_RXPAUEN_EN 0x00000400
/** Transmit Pause Enable Status */
#define EIM_MAC_PIER_TXPAUEN 0x00000200
/* interrupt is disabled (default)
#define EIM_MAC_PIER_TXPAUEN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_TXPAUEN_EN 0x00000200
/** Low-power Idle Off Interrupt Mask */
#define EIM_MAC_PIER_LPIOFF 0x00000100
/* interrupt is disabled (default)
#define EIM_MAC_PIER_LPIOFF_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_LPIOFF_EN 0x00000100
/** Low-power Idle On Interrupt Mask */
#define EIM_MAC_PIER_LPION 0x00000080
/* interrupt is disabled (default)
#define EIM_MAC_PIER_LPION_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_LPION_EN 0x00000080
/** Jam Status Interrupt Mask */
#define EIM_MAC_PIER_JAM 0x00000040
/* interrupt is disabled (default)
#define EIM_MAC_PIER_JAM_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_JAM_EN 0x00000040
/** Too Short Frame Error Interrupt Mask */
#define EIM_MAC_PIER_TOOSHORT 0x00000020
/* interrupt is disabled (default)
#define EIM_MAC_PIER_TOOSHORT_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_TOOSHORT_EN 0x00000020
/** Too Long Frame Error Interrupt Mask */
#define EIM_MAC_PIER_TOOLONG 0x00000010
/* interrupt is disabled (default)
#define EIM_MAC_PIER_TOOLONG_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_TOOLONG_EN 0x00000010
/** Length Mismatch Error Interrupt Mask */
#define EIM_MAC_PIER_LENERR 0x00000008
/* interrupt is disabled (default)
#define EIM_MAC_PIER_LENERR_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_LENERR_EN 0x00000008
/** Frame Checksum Error Interrupt Mask */
#define EIM_MAC_PIER_FCSERR 0x00000004
/* interrupt is disabled (default)
#define EIM_MAC_PIER_FCSERR_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_FCSERR_EN 0x00000004
/** Transmit Pause Frame Interrupt Mask */
#define EIM_MAC_PIER_TXPAUSE 0x00000002
/* interrupt is disabled (default)
#define EIM_MAC_PIER_TXPAUSE_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_TXPAUSE_EN 0x00000002
/** Receive Pause Frame Interrupt Mask */
#define EIM_MAC_PIER_RXPAUSE 0x00000001
/* interrupt is disabled (default)
#define EIM_MAC_PIER_RXPAUSE_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_MAC_PIER_RXPAUSE_EN 0x00000001

/* Fields of "MAC Control Register 0" */
/** Late Collision Control
    Late collision handling is different for 10/100BASE-T and 1000BASE-T operation mode. Frames can either be dropped or repeated. */
#define EIM_MAC_A1X_CTRL_0_LCOL_MASK 0x00006000
/** field offset */
#define EIM_MAC_A1X_CTRL_0_LCOL_OFFSET 13
/** mode detected by autonegotiation (default) */
#define EIM_MAC_A1X_CTRL_0_LCOL_AUTO 0x00000000
/** drop frames in case of late collisions */
#define EIM_MAC_A1X_CTRL_0_LCOL_DRP 0x00002000
/** repeat frames in case of late collisions */
#define EIM_MAC_A1X_CTRL_0_LCOL_REP 0x00004000
/** reserved */
#define EIM_MAC_A1X_CTRL_0_LCOL_RES 0x00006000
/** Burst Mode Control
    Burst frame transmission can be used in half duplex mode to claim the carrier for more than one frame. */
#define EIM_MAC_CTRL_0_BM 0x00001000
/* burst mode is disabled (default)
#define EIM_MAC_CTRL_0_BM_DIS 0x00000000 */
/** burst mode is enabled */
#define EIM_MAC_CTRL_0_BM_EN 0x00001000
/** Automatic VLAN Padding Enable
    Padding of short VLAN frames can be enabled. Normal frames and VLAN frames are automatically distinguished. */
#define EIM_MAC_CTRL_0_APADEN 0x00000800
/* VLAN padding is disabled (default)
#define EIM_MAC_CTRL_0_APADEN_DIS 0x00000000 */
/** VLAN padding is enabled */
#define EIM_MAC_CTRL_0_APADEN_EN 0x00000800
/** Stacked VLAN Padding Enable
    Padding of short stacked VLAN frames can be enabled. The following conditions apply: */
#define EIM_MAC_CTRL_0_VPAD2EN 0x00000400
/* stacked VLAN padding is disabled (default)
#define EIM_MAC_CTRL_0_VPAD2EN_DIS 0x00000000 */
/** stacked VLAN padding is enabled */
#define EIM_MAC_CTRL_0_VPAD2EN_EN 0x00000400
/** VLAN Padding Enable
    Padding of short VLAN frames can be enabled. The following conditions apply: */
#define EIM_MAC_CTRL_0_VPADEN 0x00000200
/* VLAN padding is disabled (default)
#define EIM_MAC_CTRL_0_VPADEN_DIS 0x00000000 */
/** VLAN padding is enabled */
#define EIM_MAC_CTRL_0_VPADEN_EN 0x00000200
/** Padding Enable
    Padding of short frames can be enabled. If disabled, bits APADEN, VPADEN, and VPAD2EN are ignored. */
#define EIM_MAC_CTRL_0_PADEN 0x00000100
/* padding is disabled (default)
#define EIM_MAC_CTRL_0_PADEN_DIS 0x00000000 */
/** padding is enabled */
#define EIM_MAC_CTRL_0_PADEN_EN 0x00000100
/** Transmit FCS Control
    Frame checksum generation can be enabled in transmit direction. If disabled, no FCS is attached. */
#define EIM_MAC_CTRL_0_FCS 0x00000080
/* FCS generation is disabled
#define EIM_MAC_CTRL_0_FCS_DIS 0x00000000 */
/** FCS generation is enabled (default) */
#define EIM_MAC_CTRL_0_FCS_EN 0x00000080
/** Flow Control Mode
    Selects the flow control operation mode. */
#define EIM_MAC_CTRL_0_FCON_MASK 0x00000070
/** field offset */
#define EIM_MAC_CTRL_0_FCON_OFFSET 4
/** mode detected by autonegotiation (default) */
#define EIM_MAC_CTRL_0_FCON_AUTO 0x00000000
/** flow control in receive (ingress direction) only */
#define EIM_MAC_CTRL_0_FCON_RX 0x00000010
/** flow control in transmit (egress direction) only */
#define EIM_MAC_CTRL_0_FCON_TX 0x00000020
/** flow control in receive and transmit direction */
#define EIM_MAC_CTRL_0_FCON_RXTX 0x00000030
/** flow control is disabled */
#define EIM_MAC_CTRL_0_FCON_NONE 0x00000040
/** reserved */
#define EIM_MAC_CTRL_0_FCON_RES1 0x00000050
/** reserved */
#define EIM_MAC_CTRL_0_FCON_RES2 0x00000060
/** reserved */
#define EIM_MAC_CTRL_0_FCON_RES3 0x00000070
/** Full Duplex Control
    Selects between automatic, half-duplex and full-duplex mode. */
#define EIM_MAC_CTRL_0_FDUP_MASK 0x0000000C
/** field offset */
#define EIM_MAC_CTRL_0_FDUP_OFFSET 2
/** mode detected by autonegotiation (default) */
#define EIM_MAC_CTRL_0_FDUP_AUTO 0x00000000
/** full duplex mode */
#define EIM_MAC_CTRL_0_FDUP_EN 0x00000004
/** reserved */
#define EIM_MAC_CTRL_0_FDUP_RES 0x00000008
/** half duplex mode */
#define EIM_MAC_CTRL_0_FDUP_DIS 0x0000000C
/** GMII/MII interface mode selection
    Selects between GMII and MII interface mode. */
#define EIM_MAC_CTRL_0_GMII_MASK 0x00000003
/** field offset */
#define EIM_MAC_CTRL_0_GMII_OFFSET 0
/** mode detected by autonegotiation (default) */
#define EIM_MAC_CTRL_0_GMII_AUTO 0x00000000
/** MII/RMII interface mode at 10, 100, or 200 Mbit/s */
#define EIM_MAC_CTRL_0_GMII_MII 0x00000001
/** GMII/RGMII interface mode at 1000 Mbit/s */
#define EIM_MAC_CTRL_0_GMII_GMII 0x00000002
/** reserved */
#define EIM_MAC_CTRL_0_GMII_RES 0x00000003

/* Fields of "MAC Control Register 1" */
/** Short Preamble Control
    Shorten the Preamble to 1 byte. */
#define EIM_MAC_CTRL_1_SHORTPRE 0x00000100
/* Preamble is 7 byte (default)
#define EIM_MAC_CTRL_1_SHORTPRE_DIS 0x00000000 */
/** Preamble is 1 byte */
#define EIM_MAC_CTRL_1_SHORTPRE_EN 0x00000100
/** Minimum Inter Packet Gap Size
    Number of bytes to be inserted between frames that are transmitted back-to-back. */
#define EIM_MAC_CTRL_1_IPG_MASK 0x0000000F
/** field offset */
#define EIM_MAC_CTRL_1_IPG_OFFSET 0

/* Fields of "MAC Control Register 2" */
/** Maximum Untagged Frame Length
    Defines the maximum length of frames to be received, given in number of bytes. They do not include the optional VLAN tag(s). */
#define EIM_MAC_CTRL_2_MLEN 0x00000008
/* 1518 byte (no VLAN tags included, default)
#define EIM_MAC_CTRL_2_MLEN_NORMAL 0x00000000 */
/** configured value, including any number of VLAN tags */
#define EIM_MAC_CTRL_2_MLEN_JUMBO 0x00000008
/** Frame Length Check Long Enable
    The length of received Ethernet frames is checked against the configured limit. */
#define EIM_MAC_CTRL_2_LCHKL 0x00000004
/* length check long is disabled
#define EIM_MAC_CTRL_2_LCHKL_DIS 0x00000000 */
/** length check long is enabled (default) */
#define EIM_MAC_CTRL_2_LCHKL_EN 0x00000004
/** Frame Length Check Short Enable
    The length of received Ethernet frames is checked against the standard minimum of 64 byte including VLAN TAG's or leaving VLAN TAG's unconsidered. */
#define EIM_MAC_CTRL_2_LCHKS_MASK 0x00000003
/** field offset */
#define EIM_MAC_CTRL_2_LCHKS_OFFSET 0
/** length check short is disabled */
#define EIM_MAC_CTRL_2_LCHKS_DIS 0x00000000
/** length check short is enabled for 64 byte, VLAN TAGs unconsidered */
#define EIM_MAC_CTRL_2_LCHKS_EN_UNTAG 0x00000001
/** length check short is enabled including detected VLAN TAG's */
#define EIM_MAC_CTRL_2_LCHKS_EN_TAG 0x00000002
/** RESERVED */
#define EIM_MAC_CTRL_2_LCHKS_RESERVED 0x00000003

/* Fields of "MAC Control Register 3" */
/** Retry Count
    Defines the number of retries in case of collisions. The default is 15. */
#define EIM_MAC_CTRL_3_RCNT_MASK 0x0000000F
/** field offset */
#define EIM_MAC_CTRL_3_RCNT_OFFSET 0

/* Fields of "MAC Control Register 4" */
/** LPI Wait Time for 1G (only A2X)
    Defines the wait time for the EEE state machine. */
#define EIM_MAC_CTRL_4_GWAIT_MASK 0x00007F00
/** field offset */
#define EIM_MAC_CTRL_4_GWAIT_OFFSET 8
/** LPI Mode Enable
    Enables the LPI function. */
#define EIM_MAC_CTRL_4_LPIEN 0x00000080
/* the LPI function is disabled
#define EIM_MAC_CTRL_4_LPIEN_DIS 0x00000000 */
/** the LPI function is enabled */
#define EIM_MAC_CTRL_4_LPIEN_EN 0x00000080
/** LPI Wait Time (for 100M on A2X)
    Defines the wait time for the EEE state machine. */
#define EIM_MAC_CTRL_4_WAIT_MASK 0x0000007F
/** field offset */
#define EIM_MAC_CTRL_4_WAIT_OFFSET 0

/* Fields of "MAC Control Register 5" */
/** Prolonged Jam pattern size during no-backpressure state
    Jam pattern size in case of no backpressure. */
#define EIM_MAC_CTRL_5_PJPS_NOBP 0x00000002
/* 32 bit jam pattern
#define EIM_MAC_CTRL_5_PJPS_NOBP_SHORT 0x00000000 */
/** 64 bit jam pattern */
#define EIM_MAC_CTRL_5_PJPS_NOBP_LONG 0x00000002
/** Prolonged Jam pattern size during backpressure state
    Jam pattern size in case of backpressure. */
#define EIM_MAC_CTRL_5_PJPS_BP 0x00000001
/* 32 bit jam pattern
#define EIM_MAC_CTRL_5_PJPS_BP_SHORT 0x00000000 */
/** 64 bit jam pattern */
#define EIM_MAC_CTRL_5_PJPS_BP_LONG 0x00000001

/* Fields of "Transmit and Receive Buffer Control Register" */
/** Delay
    This register is used to configure the initial delay of the write pointer in the receive buffer. */
#define EIM_MAC_A1X_CTRL_6_RBUF_DLY_WP_MASK 0x00000E00
/** field offset */
#define EIM_MAC_A1X_CTRL_6_RBUF_DLY_WP_OFFSET 9
/** Receive Buffer Initialization
    If this control bit is activated the receive buffer will be reset and initialized (idle state). */
#define EIM_MAC_A1X_CTRL_6_RBUF_INIT 0x00000100
/* the receive buffer is operating normally
#define EIM_MAC_A1X_CTRL_6_RBUF_INIT_NOP 0x00000000 */
/** the receive buffer is initialized */
#define EIM_MAC_A1X_CTRL_6_RBUF_INIT_INIT 0x00000100
/** Bypass the Receive Buffer
    This bit controls the receive buffer bypass mode. */
#define EIM_MAC_A1X_CTRL_6_RBUF_BYPASS 0x00000040
/* receive buffer is active
#define EIM_MAC_A1X_CTRL_6_RBUF_BYPASS_BUFFER 0x00000000 */
/** receive buffer is bypassed */
#define EIM_MAC_A1X_CTRL_6_RBUF_BYPASS_BYPASS 0x00000040
/** Delay
    This register is used to configure the initial delay of the write pointer in the transmit buffer. */
#define EIM_MAC_A1X_CTRL_6_XBUF_DLY_WP_MASK 0x00000038
/** field offset */
#define EIM_MAC_A1X_CTRL_6_XBUF_DLY_WP_OFFSET 3
/** Initialize the Transmit Buffer
    If this control bit is activated the transmit buffer will be reset and initialized (idle state). */
#define EIM_MAC_A1X_CTRL_6_XBUF_INIT 0x00000004
/* the transmit buffer is operating normally
#define EIM_MAC_A1X_CTRL_6_XBUF_INIT_NOP 0x00000000 */
/** the transmit buffer is initialized */
#define EIM_MAC_A1X_CTRL_6_XBUF_INIT_INIT 0x00000004
/** Bypass the Transmit Buffer
    This control bit is used to bypass the transmit buffer. */
#define EIM_MAC_A1X_CTRL_6_XBUF_BYPASS 0x00000001
/* transmit buffer is active
#define EIM_MAC_A1X_CTRL_6_XBUF_BYPASS_BUFFER 0x00000000 */
/** transmit buffer is bypassed */
#define EIM_MAC_A1X_CTRL_6_XBUF_BYPASS_BYPASS 0x00000001

/* Fields of "MAC Receive and Transmit Buffer Status Register" */
/** Receive Buffer Underflow Indicator
    Indicates if one or more receive buffer underflow events have been detected. */
#define EIM_MAC_A1X_BUFST_RBUF_UFL 0x00000008
/* Underflow never detected
#define EIM_MAC_A1X_BUFST_RBUF_UFL_NONE 0x00000000 */
/** Underflow occurred at least once */
#define EIM_MAC_A1X_BUFST_RBUF_UFL_UFL 0x00000008
/** Receive Buffer Overflow Indicator
    Indicates if one or more receive buffer overflow events have been detected. */
#define EIM_MAC_A1X_BUFST_RBUF_OFL 0x00000004
/* Overflow never detected
#define EIM_MAC_A1X_BUFST_RBUF_OFL_NONE 0x00000000 */
/** Overflow occurred at least once */
#define EIM_MAC_A1X_BUFST_RBUF_OFL_OFL 0x00000004
/** Transmit Buffer Underflow Indicator
    Indicates if one or more transmit buffer underflow events have been detected. */
#define EIM_MAC_A1X_BUFST_XBUF_UFL 0x00000002
/* Underflow never detected
#define EIM_MAC_A1X_BUFST_XBUF_UFL_NONE 0x00000000 */
/** Underflow occurred at least once */
#define EIM_MAC_A1X_BUFST_XBUF_UFL_UFL 0x00000002
/** Transmit Buffer Overflow Indicator
    Indicates if one or more transmit buffer overflow events have been detected. */
#define EIM_MAC_A1X_BUFST_XBUF_OFL 0x00000001
/* Overflow never detected
#define EIM_MAC_A1X_BUFST_XBUF_OFL_NONE 0x00000000 */
/** Overflow occurred at least once */
#define EIM_MAC_A1X_BUFST_XBUF_OFL_OFL 0x00000001

/* Fields of "MAC Test Enable Register" */
/** Jitter Test Enable
    Loopback mode for test purposes. */
#define EIM_MAC_TESTEN_JTEN 0x00000004
/* test mode is disabled (default)
#define EIM_MAC_TESTEN_JTEN_NORM 0x00000000 */
/** test mode is enabled */
#define EIM_MAC_TESTEN_JTEN_TEST 0x00000004
/** Transmit Error Insertion
    Inject a transmit error during frame transmission. */
#define EIM_MAC_TESTEN_TXER 0x00000002
/* test mode is disabled (default)
#define EIM_MAC_TESTEN_TXER_NORM 0x00000000 */
/** test mode is enabled */
#define EIM_MAC_TESTEN_TXER_TEST 0x00000002
/** MAC Loopback Enable
    8-bit PCS loopback mode for test purposes. */
#define EIM_MAC_TESTEN_LOOP 0x00000001
/* loopback is disabled (default)
#define EIM_MAC_TESTEN_LOOP_DIS 0x00000000 */
/** loopback is enabled */
#define EIM_MAC_TESTEN_LOOP_EN 0x00000001

/* Fields of "Reset Control Register" */
/** MDIO Software Reset
    This register controls the software reset of the MDIO module. */
#define EIM_GPHY_CTL_A1X_MDIO_SRST 0x00000004
/* Run
#define EIM_GPHY_CTL_A1X_MDIO_SRST_RUN 0x00000000 */
/** Reset the GPHY */
#define EIM_GPHY_CTL_A1X_MDIO_SRST_RESET 0x00000004
/** GPHY Software Reset
    This register controls the software reset of the GPHY IP macro. */
#define EIM_GPHY_CTL_GPHY_SRST_1 0x00000002
/* Reset the GPHY
#define EIM_GPHY_CTL_GPHY_SRST_1_RESET 0x00000000 */
/** Run */
#define EIM_GPHY_CTL_GPHY_SRST_1_RUN 0x00000002
/** GPHY Software Reset
    This register controls the software reset of the GPHY IP macro. */
#define EIM_GPHY_CTL_GPHY_SRST_0 0x00000001
/* Reset the GPHY
#define EIM_GPHY_CTL_GPHY_SRST_0_RESET 0x00000000 */
/** Run */
#define EIM_GPHY_CTL_GPHY_SRST_0_RUN 0x00000001

/* Fields of "GPHY Version Configuration Register" */
/** CHIP Version Configuration
    This type of information is evaluated by the integrated */
#define EIM_GPHY_CFG_VER_CHIP_VER_MASK 0x000000F0
/** field offset */
#define EIM_GPHY_CFG_VER_CHIP_VER_OFFSET 4
/** Chip-ID of the instantiating SOC Configuration
    These pins specify the Chip Identification Number of the */
#define EIM_GPHY_CFG_VER_CHIP_ID_MASK 0x0000000F
/** field offset */
#define EIM_GPHY_CFG_VER_CHIP_ID_OFFSET 0

/* Fields of "GPHY PLL Configuration Register" */
/** Divider 1 */
#define EIM_GPHY_CFG_PLL_DIV1_MASK 0x0000003E
/** field offset */
#define EIM_GPHY_CFG_PLL_DIV1_OFFSET 1
/** Divider 0 */
#define EIM_GPHY_CFG_PLL_DIV0 0x00000001

/* Fields of "GPHY General Configuration Register" */
/** Base Frequency Deviation Configuration
    This input is used as a pin-strapping to specify the deviation */
#define EIM_GPHY_CFG_GEN_BFDEV_MASK 0xFFFF0000
/** field offset */
#define EIM_GPHY_CFG_GEN_BFDEV_OFFSET 16
/** General Purpose Pin-Strapping
    Use this input to pin-strap software mapped functionality. */
#define EIM_GPHY_CFG_GEN_GPS_MASK 0x0000FF00
/** field offset */
#define EIM_GPHY_CFG_GEN_GPS_OFFSET 8
/** MDIO Interrupt Polarity Configuration
    This type of information is evaluated by the integrated */
#define EIM_GPHY_CFG_GEN_MDINTP 0x00000008
/* MDIO interrupt is low-active
#define EIM_GPHY_CFG_GEN_MDINTP_LOW 0x00000000 */
/** MDIO interrupt is high-active */
#define EIM_GPHY_CFG_GEN_MDINTP_HIGH 0x00000008
/** Clock Input Single-Ended Configuration
    This pin allows for a pin-strapping in order to select the */
#define EIM_GPHY_CFG_GEN_SECLK_EN 0x00000004
/* Use CLK_DIFF_IN[P/N] as clock.
#define EIM_GPHY_CFG_GEN_SECLK_EN_DIFFERENTIAL 0x00000000 */
/** Use CLK as input clock source. */
#define EIM_GPHY_CFG_GEN_SECLK_EN_SINGLE_ENDED 0x00000004
/** Clock Input Speed Bypass Configuration
    This pin allows for a pin-strapping in order to select the */
#define EIM_GPHY_CFG_GEN_CLK 0x00000002
/* Input Clock is provided at 25MHz.
#define EIM_GPHY_CFG_GEN_CLK_MHZ25 0x00000000 */
/** Input Clock is provided at 125MHz. */
#define EIM_GPHY_CFG_GEN_CLK_MHZ125 0x00000002
/** PLL Bypass Configuration
    This is the PLL Bypass Configuration Pin. It can be used to */
#define EIM_GPHY_CFG_GEN_PLLBYP 0x00000001
/* PLL is used in normal mode
#define EIM_GPHY_CFG_GEN_PLLBYP_NORMAL 0x00000000 */
/** PLL is bypassed */
#define EIM_GPHY_CFG_GEN_PLLBYP_BYPASS 0x00000001

/* Fields of "GPHY Auto-Negotiation Capability Configuration Register" */
/** Autonegociation Capability for Pause
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_PS_MASK 0x00000300
/** field offset */
#define EIM_GPHY_CFG_ANEG_CAP_PS_OFFSET 8
/** No Pause Supported. */
#define EIM_GPHY_CFG_ANEG_CAP_PS_NO 0x00000000
/** Asymmetric Pause towards Link-Partner */
#define EIM_GPHY_CFG_ANEG_CAP_PS_ASYM 0x00000100
/** Symetric Pause */
#define EIM_GPHY_CFG_ANEG_CAP_PS_SYM 0x00000200
/** Symmetric Pause and Asymmetric Pause towards local device */
#define EIM_GPHY_CFG_ANEG_CAP_PS_BOTH 0x00000300
/** Autonegociation Capability for 100baseFX Full-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_100BFX_FDX 0x00000080
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_100BFX_FDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_100BFX_FDX_ENABLE 0x00000080
/** Autonegociation Capability for 100baseFX Half-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_100BFX_HDX 0x00000040
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_100BFX_HDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_100BFX_HDX_ENABLE 0x00000040
/** Autonegociation Capability for 10baseT Full-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_10BT_FDX 0x00000020
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_10BT_FDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_10BT_FDX_ENABLE 0x00000020
/** Autonegociation Capability for 10baseT Half-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_10BT_HDX 0x00000010
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_10BT_HDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_10BT_HDX_ENABLE 0x00000010
/** Autonegociation Capability for 100baseTX Full-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_100BTX_FDX 0x00000008
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_100BTX_FDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_100BTX_FDX_ENABLE 0x00000008
/** Autonegociation Capability for 100baseTX Half-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_100BTX_HDX 0x00000004
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_100BTX_HDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_100BTX_HDX_ENABLE 0x00000004
/** Autonegociation Capability for 1000baseT Full-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_1000BT_FDX 0x00000002
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_1000BT_FDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_1000BT_FDX_ENABLE 0x00000002
/** Autonegociation Capability for 1000baseT Half-Duplex
    Use this input to select the capabilities which shall be */
#define EIM_GPHY_CFG_ANEG_CAP_1000BT_HDX 0x00000001
/* Disables this Capability
#define EIM_GPHY_CFG_ANEG_CAP_1000BT_HDX_DISBALE 0x00000000 */
/** Enables this Capability */
#define EIM_GPHY_CFG_ANEG_CAP_1000BT_HDX_ENABLE 0x00000001

/* Fields of "GPHY PHY Address Configuration Register" */
/** Physical Layer Address 2 (MDIO) Configuration
    This is the Configuration Input for the MDIO address of the */
#define EIM_GPHY_CFG_ADDR_PHYADR2_MASK 0x00001F00
/** field offset */
#define EIM_GPHY_CFG_ADDR_PHYADR2_OFFSET 8
/** Physical Layer Address 1 (MDIO) Configuration
    This is the Configuration Input for the MDIO address of the */
#define EIM_GPHY_CFG_ADDR_PHYADR1_MASK 0x0000001F
/** field offset */
#define EIM_GPHY_CFG_ADDR_PHYADR1_OFFSET 0

/* Fields of "Configuration register for Strobe Generator 0 (2Hz target frequency)" */
/** Strobe Generator Mode
    Enables the strobe generator. */
#define EIM_EIM_STRB_GEN0_CTL_EN 0x40000000
/* Disable
#define EIM_EIM_STRB_GEN0_CTL_EN_DIS 0x00000000 */
/** Strobe Generator Mode
    Selects the operating mode. When set to PULSE, the generated strobe will only be active for 1 system clock cycle. Otherwise a symmetric duty cycle will be generated. */
#define EIM_EIM_STRB_GEN0_CTL_MODE 0x20000000
/* Symmetric Duty Cycle
#define EIM_EIM_STRB_GEN0_CTL_MODE_SYM 0x00000000 */
/** Pulsed Shape */
#define EIM_EIM_STRB_GEN0_CTL_MODE_PULSE 0x20000000
/** Divider
    Sets the divider value used for strobe generation. By default strobe generator 0 will produce a 2Hz signal derived from a 125 MHz clock. */
#define EIM_EIM_STRB_GEN0_CTL_DVD_MASK 0x1FFFFFFF
/** field offset */
#define EIM_EIM_STRB_GEN0_CTL_DVD_OFFSET 0

/* Fields of "Configuration register for Strobe Generator 1 (25MHz target frequency)" */
/** Strobe Generator Mode
    Enables the strobe generator. */
#define EIM_EIM_STRB_GEN1_CTL_EN 0x40000000
/* Disable
#define EIM_EIM_STRB_GEN1_CTL_EN_DIS 0x00000000 */
/** Strobe Generator Mode
    Selects the operating mode. When set to PULSE, the generated strobe will only be active for 1 system clock cycle. Otherwise a symmetric duty cycle will be generated. */
#define EIM_EIM_STRB_GEN1_CTL_MODE 0x20000000
/* Symmetric Duty Cycle
#define EIM_EIM_STRB_GEN1_CTL_MODE_SYM 0x00000000 */
/** Pulsed Shape */
#define EIM_EIM_STRB_GEN1_CTL_MODE_PULSE 0x20000000
/** Divider
    Sets the divider value used for strobe generation. By default strobe generator 1 will produce a 25MHz signal derived from a 125 MHz clock. */
#define EIM_EIM_STRB_GEN1_CTL_DVD_MASK 0x1FFFFFFF
/** field offset */
#define EIM_EIM_STRB_GEN1_CTL_DVD_OFFSET 0

/* Fields of "Configuration register for Packet Engine Interface 0" */
/** Threshold for LAN-Interface
    Number of words which need to be available at LAN Interface before 'not empty' is signalled. */
#define EIM_EIM_LAN_IFC_CFG_0_THR_3_MASK 0xFF000000
/** field offset */
#define EIM_EIM_LAN_IFC_CFG_0_THR_3_OFFSET 24
/** Threshold for LAN-Interface
    Number of words which need to be available at LAN Interface before 'not empty' is signalled. */
#define EIM_EIM_LAN_IFC_CFG_0_THR_2_MASK 0x00FF0000
/** field offset */
#define EIM_EIM_LAN_IFC_CFG_0_THR_2_OFFSET 16
/** Threshold for LAN-Interface
    Number of words which need to be available at LAN Interface before 'not empty' is signalled. */
#define EIM_EIM_LAN_IFC_CFG_0_THR_1_MASK 0x0000FF00
/** field offset */
#define EIM_EIM_LAN_IFC_CFG_0_THR_1_OFFSET 8
/** Threshold for LAN-Interface
    Number of words which need to be available at LAN Interface before 'not empty' is signalled. */
#define EIM_EIM_LAN_IFC_CFG_0_THR_0_MASK 0x000000FF
/** field offset */
#define EIM_EIM_LAN_IFC_CFG_0_THR_0_OFFSET 0

/* Fields of "Configuration register for Packet Engine Interface 1" */
/** SEND LPI on MAC-TX
    Starting with the next interframe gap Low-Power Idle will be send instead of normal idle. Should only be activated when no data is expected to be transferred on this interface for some while. */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_3 0x00000080
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_3_OFF 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_3_ON 0x00000080
/** SEND LPI on MAC-TX
    Starting with the next interframe gap Low-Power Idle will be send instead of normal idle. Should only be activated when no data is expected to be transferred on this interface for some while. */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_2 0x00000040
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_2_OFF 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_2_ON 0x00000040
/** SEND LPI on MAC-TX
    Starting with the next interframe gap Low-Power Idle will be send instead of normal idle. Should only be activated when no data is expected to be transferred on this interface for some while. */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_1 0x00000020
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_1_OFF 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_1_ON 0x00000020
/** SEND LPI on MAC-TX
    Starting with the next interframe gap Low-Power Idle will be send instead of normal idle. Should only be activated when no data is expected to be transferred on this interface for some while. */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_0 0x00000010
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_0_OFF 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_TXLPI_0_ON 0x00000010
/** Byte Endianess on LAN-Interface
    Selects the byte endianess on LAN Interface. (Little means, byte 0 is on bit position 7..0 of the incoming 32-bit vector.) */
#define EIM_EIM_LAN_IFC_CFG_1_END_3 0x00000008
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_END_3_BIG 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_END_3_LITTLE 0x00000008
/** Byte Endianess on LAN-Interface
    Selects the byte endianess on LAN Interface. (Little means, byte 0 is on bit position 7..0 of the incoming 32-bit vector.) */
#define EIM_EIM_LAN_IFC_CFG_1_END_2 0x00000004
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_END_2_BIG 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_END_2_LITTLE 0x00000004
/** Byte Endianess on LAN-Interface
    Selects the byte endianess on LAN Interface. (Little means, byte 0 is on bit position 7..0 of the incoming 32-bit vector.) */
#define EIM_EIM_LAN_IFC_CFG_1_END_1 0x00000002
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_END_1_BIG 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_END_1_LITTLE 0x00000002
/** Byte Endianess on LAN-Interface
    Selects the byte endianess on LAN Interface. (Little means, byte 0 is on bit position 7..0 of the incoming 32-bit vector.) */
#define EIM_EIM_LAN_IFC_CFG_1_END_0 0x00000001
/* Big Endian
#define EIM_EIM_LAN_IFC_CFG_1_END_0_BIG 0x00000000 */
/** Little Endian */
#define EIM_EIM_LAN_IFC_CFG_1_END_0_LITTLE 0x00000001

/* Fields of "MIB Counter (FCS Errored Frames)" */
/** 32-Bit counter
    Counts the total number of FCS violated frames. */
#define EIM_EIM_MIB_FCSER_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_FCSER_CNT_OFFSET 0

/* Fields of "MIB Counter (Oversized Frames)" */
/** 32-Bit counter
    Counts the total number of frames with more bytes than specified by EIM_MAX_FRSZ. */
#define EIM_EIM_MIB_OVSZ_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_OVSZ_CNT_OFFSET 0

/* Fields of "MIB Counter (Misaligned Frames)" */
/** 32-Bit counter
    Counts the total number of frames which aren't byte aligned. */
#define EIM_EIM_MIB_ALGN_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_ALGN_CNT_OFFSET 0

/* Fields of "MIB Counter (Late Collsions)" */
/** 32-Bit counter
    Counts the total number of late collisions in half duplex mode. */
#define EIM_EIM_MIB_LATE_COL_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_LATE_COL_CNT_OFFSET 0

/* Fields of "MIB Counter (Excessive Collisions)" */
/** 32-Bit counter
    Counts the total number of excessive colisions in half duplex mode. (An excessive collision occurs when a single frame i srepeated more often then the programmed number of times due to a collision). */
#define EIM_EIM_MIB_EXC_COL_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_EXC_COL_CNT_OFFSET 0

/* Fields of "MIB Counter (Single Collisions)" */
/** 32-Bit counter
    Counts the total number of frames which experienced a single collision in half duplex mode. (Thus they've been transmitted successfully after the first re-transmission). */
#define EIM_EIM_MIB_SGL_COL_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_SGL_COL_CNT_OFFSET 0

/* Fields of "MIB Counter (Multiple Collisions)" */
/** 32-Bit counter
    Counts the total number of frames which experienced multiple collision in half duplex mode. (The frame was successfully transmitted after more than one retry; butr less than programmed for excessive collisions). */
#define EIM_EIM_MIB_MUL_COL_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_MUL_COL_CNT_OFFSET 0

/* Fields of "MIB Counter (Deferred Transmission)" */
/** 32-Bit counter
    Counts the total number of frames whose transmission was delayed on its first attempt because the medium was busy. */
#define EIM_EIM_MIB_DEF_TRANS_CNT_MASK 0xFFFFFFFF
/** field offset */
#define EIM_EIM_MIB_DEF_TRANS_CNT_OFFSET 0

/* Fields of "Central EIM Interrupt Enable" */
/** LAN Egress Underflow Enable */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_3 0x00008000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_3 0x00000400
/* interrupt is disabled
#define EIM_EIM_IER_LAN_EG_UNFL_3_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_3_EN 0x00008000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_3_EN 0x00000400
/** LAN Egress Underflow Enable */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_2 0x00004000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_2 0x00000200
/* interrupt is disabled
#define EIM_EIM_IER_LAN_EG_UNFL_2_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_2_EN 0x00004000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_2_EN 0x00000200
/** LAN Egress Underflow Enable */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_1 0x00002000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_1 0x00000100
/* interrupt is disabled
#define EIM_EIM_IER_LAN_EG_UNFL_1_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_1_EN 0x00002000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_1_EN 0x00000100
/** LAN Egress Underflow Enable */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_0 0x00001000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_0 0x00000080
/* interrupt is disabled
#define EIM_EIM_IER_LAN_EG_UNFL_0_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_EG_UNFL_0_EN 0x00001000
#define EIM_EIM_IER_A2X_LAN_EG_UNFL_0_EN 0x00000080
/** LAN Ingress Overflow Enable */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_3 0x00000800
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_3 0x00000040
/* interrupt is disabled
#define EIM_EIM_IER_LAN_IG_OVFL_3_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_3_EN 0x00000800
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_3_EN 0x00000040
/** LAN Ingress Overflow Enable */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_2 0x00000400
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_2 0x00000020
/* interrupt is disabled
#define EIM_EIM_IER_LAN_IG_OVFL_2_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_2_EN 0x00000400
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_2_EN 0x00000020
/** LAN Ingress Overflow Enable */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_1 0x00000200
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_1 0x00000010
/* interrupt is disabled
#define EIM_EIM_IER_LAN_IG_OVFL_1_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_1_EN 0x00000200
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_1_EN 0x00000010
/** LAN Ingress Overflow Enable */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_0 0x00000100
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_0 0x00000008
/* interrupt is disabled
#define EIM_EIM_IER_LAN_IG_OVFL_0_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_LAN_IG_OVFL_0_EN 0x00000100
#define EIM_EIM_IER_A2X_LAN_IG_OVFL_0_EN 0x00000008
/** SGMII Interrupt Enable */
#define EIM_EIM_IER_A1X_SGMII_IEN 0x00000080
#define EIM_EIM_IER_A2X_SGMII_IEN 0x00000004
/* interrupt is disabled
#define EIM_EIM_IER_SGMII_IEN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_SGMII_IEN_EN 0x00000080
#define EIM_EIM_IER_A2X_SGMII_IEN_EN 0x00000004
/** GPHY1 Interrupt Enable */
#define EIM_EIM_IER_A1X_GPHY1_IEN 0x00000040
#define EIM_EIM_IER_A2X_GPHY1_IEN 0x00000002
/* interrupt is disabled
#define EIM_EIM_IER_GPHY1_IEN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_GPHY1_IEN_EN 0x00000040
#define EIM_EIM_IER_A2X_GPHY1_IEN_EN 0x00000002
/** GPHY0 Interrupt Enable */
#define EIM_EIM_IER_A1X_GPHY0_IEN 0x00000020
#define EIM_EIM_IER_A2X_GPHY0_IEN 0x00000001
/* interrupt is disabled
#define EIM_EIM_IER_GPHY0_IEN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_GPHY0_IEN_EN 0x00000020
#define EIM_EIM_IER_A2X_GPHY0_IEN_EN 0x00000001
/** MDIO Interrupt Enable */
#define EIM_EIM_IER_A1X_MDIO_IEN 0x00000010
/* interrupt is disabled
#define EIM_EIM_IER_A1X_MDIO_IEN_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_MDIO_IEN_EN 0x00000010
/** MAC Interrupt Enable */
#define EIM_EIM_IER_A1X_MAC_IRQ_3 0x00000008
/* interrupt is disabled
#define EIM_EIM_IER_A1X_MAC_IRQ_3_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_MAC_IRQ_3_EN 0x00000008
/** MAC Interrupt Enable */
#define EIM_EIM_IER_A1X_MAC_IRQ_2 0x00000004
/* interrupt is disabled
#define EIM_EIM_IER_A1X_MAC_IRQ_2_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_MAC_IRQ_2_EN 0x00000004
/** MAC Interrupt Enable */
#define EIM_EIM_IER_A1X_MAC_IRQ_1 0x00000002
/* interrupt is disabled
#define EIM_EIM_IER_A1X_MAC_IRQ_1_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_MAC_IRQ_1_EN 0x00000002
/** MAC Interrupt Enable */
#define EIM_EIM_IER_A1X_MAC_IRQ_0 0x00000001
/* interrupt is disabled
#define EIM_EIM_IER_A1X_MAC_IRQ_0_DIS 0x00000000 */
/** interrupt is enabled */
#define EIM_EIM_IER_A1X_MAC_IRQ_0_EN 0x00000001

/* Fields of "Central EIM Interrupt Register" */
/** MAC Interrupt Request
    Interrupt from a MAC port received. This bit is mirrored from register file ETHSW_MACS_PDI. The corresponding interrupt enable bit is also located in that file. */
#define EIM_EIM_ISR_A2X_MAC_IRQ 0x00000800
/** LAN Egress Underflow
    An underflow on the egress lane (MAC TX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_EG_UNFL_3 0x00008000
#define EIM_EIM_ISR_A2X_LAN_EG_UNFL_3 0x00000400
/** LAN Egress Underflow
    An underflow on the egress lane (MAC TX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_EG_UNFL_2 0x00004000
#define EIM_EIM_ISR_A2X_LAN_EG_UNFL_2 0x00000200
/** LAN Egress Underflow
    An underflow on the egress lane (MAC TX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_EG_UNFL_1 0x00002000
#define EIM_EIM_ISR_A2X_LAN_EG_UNFL_1 0x00000100
/** LAN Egress Underflow
    An underflow on the egress lane (MAC TX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_EG_UNFL_0 0x00001000
#define EIM_EIM_ISR_A2X_LAN_EG_UNFL_0 0x00000080
/** LAN Ingress Overflow
    An overflow on the ingress lane (MAC RX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_IG_OVFL_3 0x00000800
#define EIM_EIM_ISR_A2X_LAN_IG_OVFL_3 0x00000040
/** LAN Ingress Overflow
    An overflow on the ingress lane (MAC RX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_IG_OVFL_2 0x00000400
#define EIM_EIM_ISR_A2X_LAN_IG_OVFL_2 0x00000020
/** LAN Ingress Overflow
    An overflow on the ingress lane (MAC RX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_IG_OVFL_1 0x00000200
#define EIM_EIM_ISR_A2X_LAN_IG_OVFL_1 0x00000010
/** LAN Ingress Overflow
    An overflow on the ingress lane (MAC RX) of the LAN interface occured. */
#define EIM_EIM_ISR_A1X_LAN_IG_OVFL_0 0x00000100
#define EIM_EIM_ISR_A2X_LAN_IG_OVFL_0 0x00000008
/** SGMII Interrupt Request */
#define EIM_EIM_ISR_A1X_SGMII_IRQ 0x00000080
#define EIM_EIM_ISR_A2X_SGMII_IRQ 0x00000004
/** GPHY1 Interrupt Request */
#define EIM_EIM_ISR_A1X_GPHY1_IRQ 0x00000040
#define EIM_EIM_ISR_A2X_GPHY1_IRQ 0x00000002
/** GPHY0 Interrupt Request */
#define EIM_EIM_ISR_A1X_GPHY0_IRQ 0x00000020
#define EIM_EIM_ISR_A2X_GPHY0_IRQ 0x00000001
/** MDIO Interrupt Request */
#define EIM_EIM_ISR_A1X_MDIO_IRQ 0x00000010
/** MAC Interrupt Request */
#define EIM_EIM_ISR_A1X_MAC_IRQ_3 0x00000008
/** MAC Interrupt Request */
#define EIM_EIM_ISR_A1X_MAC_IRQ_2 0x00000004
/** MAC Interrupt Request */
#define EIM_EIM_ISR_A1X_MAC_IRQ_1 0x00000002
/** MAC Interrupt Request */
#define EIM_EIM_ISR_A1X_MAC_IRQ_0 0x00000001

/* Fields of "Interrupt Status Register" */
/** MAC mode: transmission / reception of complete frame finished
    Initiated (mac_header.start_tx) read or write access (mac_header.wr) in */
#define EIM_ISTAT_INT_MAC 0x00000001

/* Fields of "Interrupt Enable Register" */
/** forward interrupt enable */
#define EIM_IENABLE_INT_MAC 0x00000001
/* interrupt is disabled
#define EIM_IENABLE_INT_MAC_DISBALE 0x00000000 */
/** interrupt is enabled */
#define EIM_IENABLE_INT_MAC_ENABLE 0x00000001

/* Fields of "Configuration Register" */
/** reset the MAC FSM
    0: MAC FSM is not in reset */
#define EIM_CFG_MAC_FSM_RES 0x00000001

/* Fields of "Startup Phase Data Register" */
/** ST bits received
    The received ST bits within the MDIO frame */
#define EIM_STARTUP_ST_MASK 0xC0000000
/** field offset */
#define EIM_STARTUP_ST_OFFSET 30
/** OP bits received
    The received OP bits within the MDIO frame */
#define EIM_STARTUP_OP_MASK 0x30000000
/** field offset */
#define EIM_STARTUP_OP_OFFSET 28
/** PRTAD bits received
    The received prtad bits within the MDIO Frame (clause 22 the name is PHYAD) */
#define EIM_STARTUP_PRTAD_MASK 0x0F800000
/** field offset */
#define EIM_STARTUP_PRTAD_OFFSET 23
/** DEVAD bits received
    The received DEVAD bits within the MDIO Frame (clause 22 the name is REGAD) */
#define EIM_STARTUP_DEVAD_MASK 0x007C0000
/** field offset */
#define EIM_STARTUP_DEVAD_OFFSET 18
/** TA bits received
    The received TA */
#define EIM_STARTUP_TA_MASK 0x00030000
/** field offset */
#define EIM_STARTUP_TA_OFFSET 16
/** DATA bits received
    The received DATA or ADDRESS (only with clause 45 access) */
#define EIM_STARTUP_DATA_MASK 0x0000FFFF
/** field offset */
#define EIM_STARTUP_DATA_OFFSET 0

/* Fields of "Mac Data Transmit Register" */
/** data
    16 bit data to transmit in mac mode (clause 22 data) */
#define EIM_MAC_DATA_DATA_MASK 0x0000FFFF
/** field offset */
#define EIM_MAC_DATA_DATA_OFFSET 0

/* Fields of "Mac Header Transmit Register" */
/** start_transmission
    With this bit the transmission of the actual header and data will be send. Self-clearing. */
#define EIM_MAC_HEADER_START_TX 0x00020000
/** read/write bit
    Bit indicates if the next access is a read or a write access (0 write, 1 read) */
#define EIM_MAC_HEADER_RW 0x00010000
/* WRITE
#define EIM_MAC_HEADER_RW_WRITE 0x00000000 */
/** READ */
#define EIM_MAC_HEADER_RW_READ 0x00010000
/** ST bits transmit
    The transmit ST bits within the MDIO frame */
#define EIM_MAC_HEADER_ST_MASK 0x0000C000
/** field offset */
#define EIM_MAC_HEADER_ST_OFFSET 14
/** OP bits received
    The transmit OP bits within the MDIO frame */
#define EIM_MAC_HEADER_OP_MASK 0x00003000
/** field offset */
#define EIM_MAC_HEADER_OP_OFFSET 12
/** PHYAD bits transmit
    The transmit prtad bits within the MDIO Frame */
#define EIM_MAC_HEADER_PHYAD_MASK 0x00000F80
/** field offset */
#define EIM_MAC_HEADER_PHYAD_OFFSET 7
/** REGAD bits transmit
    The transmit DEVAD bits within the MDIO Frame */
#define EIM_MAC_HEADER_REGAD_MASK 0x0000007C
/** field offset */
#define EIM_MAC_HEADER_REGAD_OFFSET 2
/** TA bits to transmit
    The TA bits to transmit */
#define EIM_MAC_HEADER_TA_MASK 0x00000003
/** field offset */
#define EIM_MAC_HEADER_TA_OFFSET 0

/* Fields of "MAC Preamble Transmit Length Register" */
/** length of preamble
    Length of the transmitted preamble (ones) */
#define EIM_PREAMBLE_LEN_MASK 0x0000007F
/** field offset */
#define EIM_PREAMBLE_LEN_OFFSET 0

/* Fields of "Preamble Length Register" */
/** length of preamble
    Minimum length of the received preamble */
#define EIM_PREAMBLE_INCOMING_LEN_MASK 0x0000007F
/** field offset */
#define EIM_PREAMBLE_INCOMING_LEN_OFFSET 0

/* Fields of "MDIO Control Register" */
/** MDIO Busy
    This bit is set to BSY by hardware upon each write access to the register, which starts a transmission. */
#define EIM_MDIO_CTRL_MBUSY 0x00001000
/* the bus is available
#define EIM_MDIO_CTRL_MBUSY_IDLE 0x00000000 */
/** the bus is busy */
#define EIM_MDIO_CTRL_MBUSY_BUSY 0x00001000
/** Operation Code
    Selects the operation command. The value is directly mapped into the serial address frame. */
#define EIM_MDIO_CTRL_OP_MASK 0x00000C00
/** field offset */
#define EIM_MDIO_CTRL_OP_OFFSET 10
/** reserved, do not use */
#define EIM_MDIO_CTRL_OP_RES0 0x00000000
/** write access */
#define EIM_MDIO_CTRL_OP_WR 0x00000400
/** read access */
#define EIM_MDIO_CTRL_OP_RD 0x00000800
/** reserved, do not use */
#define EIM_MDIO_CTRL_OP_RES3 0x00000C00
/** PHY Address
    PHY address of the target device. The value is directly mapped into the serial address frame. */
#define EIM_MDIO_CTRL_PHYAD_MASK 0x000003E0
/** field offset */
#define EIM_MDIO_CTRL_PHYAD_OFFSET 5
/** Register Address
    Register address in the target device. The value is directly mapped into the serial address frame. */
#define EIM_MDIO_CTRL_REGAD_MASK 0x0000001F
/** field offset */
#define EIM_MDIO_CTRL_REGAD_OFFSET 0

/* Fields of "MDIO Read Data Register" */
/** Read Data
    A read access is triggered by writing to MDIO_CTRL (OP = RD, MBUSY = BSY). After MBUSY = RDY, data can be read. */
#define EIM_MDIO_READ_RDATA_MASK 0x0000FFFF
/** field offset */
#define EIM_MDIO_READ_RDATA_OFFSET 0

/* Fields of "MDIO Write Data Register" */
/** Write Data
    A write access is triggered by writing to MDIO_CTRL (OP = WR, MBUSY = BSY). */
#define EIM_MDIO_WRITE_WDATA_MASK 0x0000FFFF
/** field offset */
#define EIM_MDIO_WRITE_WDATA_OFFSET 0

/* Fields of "MDC Clock Configuration Register 0" */
/** Polling State Machine Enable
    Enables the state machine to read PHY information automatically on this port. Unused ports should be disabled to reduce the polling latency. If px_port_disable is set the autopolling is also disabled. */
#define EIM_MDC_CFG_0_PEN_3 0x00000008
/* automatic PHY polling is disabled on this port
#define EIM_MDC_CFG_0_PEN_3_DIS 0x00000000 */
/** automatic PHY polling is enabled on this port (default) */
#define EIM_MDC_CFG_0_PEN_3_EN 0x00000008
/** Polling State Machine Enable
    Enables the state machine to read PHY information automatically on this port. Unused ports should be disabled to reduce the polling latency. If px_port_disable is set the autopolling is also disabled. */
#define EIM_MDC_CFG_0_PEN_2 0x00000004
/* automatic PHY polling is disabled on this port
#define EIM_MDC_CFG_0_PEN_2_DIS 0x00000000 */
/** automatic PHY polling is enabled on this port (default) */
#define EIM_MDC_CFG_0_PEN_2_EN 0x00000004
/** Polling State Machine Enable
    Enables the state machine to read PHY information automatically on this port. Unused ports should be disabled to reduce the polling latency. If px_port_disable is set the autopolling is also disabled. */
#define EIM_MDC_CFG_0_PEN_1 0x00000002
/* automatic PHY polling is disabled on this port
#define EIM_MDC_CFG_0_PEN_1_DIS 0x00000000 */
/** automatic PHY polling is enabled on this port (default) */
#define EIM_MDC_CFG_0_PEN_1_EN 0x00000002
/** Polling State Machine Enable
    Enables the state machine to read PHY information automatically on this port. Unused ports should be disabled to reduce the polling latency. If px_port_disable is set the autopolling is also disabled. */
#define EIM_MDC_CFG_0_PEN_0 0x00000001
/* automatic PHY polling is disabled on this port
#define EIM_MDC_CFG_0_PEN_0_DIS 0x00000000 */
/** automatic PHY polling is enabled on this port (default) */
#define EIM_MDC_CFG_0_PEN_0_EN 0x00000001

/* Fields of "MDC Clock Configuration Register 1" */
/** MDIO Hardware Reset
    Reset all hardware modules except for the register settings. */
#define EIM_MDC_CFG_1_RES 0x00008000
/* reset is off
#define EIM_MDC_CFG_1_RES_OFF 0x00000000 */
/** reset is active */
#define EIM_MDC_CFG_1_RES_ON 0x00008000
/** Management Clock Enable
    Enables the MDC clock driver. The driver can be disabled to save power if no external devices are connected to the MDIO master interface. */
#define EIM_MDC_CFG_1_MCEN 0x00000100
/* clock driver is disabled
#define EIM_MDC_CFG_1_MCEN_DIS 0x00000000 */
/** clock driver is enabled (default) */
#define EIM_MDC_CFG_1_MCEN_EN 0x00000100
/** MDIO Interface Clock Rate
    Selects the interface data and clock rate for the MDIO master interface. */
#define EIM_MDC_CFG_1_FREQ_MASK 0x000000FF
/** field offset */
#define EIM_MDC_CFG_1_FREQ_OFFSET 0
/** 25.0 MHz */
#define EIM_MDC_CFG_1_FREQ_S0 0x00000000
/** 12.50 MHz */
#define EIM_MDC_CFG_1_FREQ_S1 0x00000001
/** 8.333 MHz */
#define EIM_MDC_CFG_1_FREQ_S2 0x00000002
/** 6.250 MHz */
#define EIM_MDC_CFG_1_FREQ_S3 0x00000003
/** 5.000 MHz */
#define EIM_MDC_CFG_1_FREQ_S4 0x00000004
/** 4.167 MHz */
#define EIM_MDC_CFG_1_FREQ_S5 0x00000005
/** 3.571 MHz */
#define EIM_MDC_CFG_1_FREQ_S6 0x00000006
/** 3.125 MHz */
#define EIM_MDC_CFG_1_FREQ_S7 0x00000007
/** 2.778 MHz */
#define EIM_MDC_CFG_1_FREQ_S8 0x00000008
/** 2.500 MHz(default) */
#define EIM_MDC_CFG_1_FREQ_S9 0x00000009
/** 2.273 MHz */
#define EIM_MDC_CFG_1_FREQ_S10 0x0000000A
/** 2.083 MHz */
#define EIM_MDC_CFG_1_FREQ_S11 0x0000000B
/** 1.923 MHz */
#define EIM_MDC_CFG_1_FREQ_S12 0x0000000C
/** 1.786 MHz */
#define EIM_MDC_CFG_1_FREQ_S13 0x0000000D
/** 1.667 MHz */
#define EIM_MDC_CFG_1_FREQ_S14 0x0000000E
/** 1.563 MHz */
#define EIM_MDC_CFG_1_FREQ_S15 0x0000000F
/** 97.6 kHz */
#define EIM_MDC_CFG_1_FREQ_S255 0x000000FF

/* Fields of "PHY Address Register PORT 0" */
/** Link Status Control */
#define EIM_PHY_ADDR_LNKST_MASK 0x00006000
/** field offset */
#define EIM_PHY_ADDR_LNKST_OFFSET 13
/** automatic mode detection by the Ethernet PHY (default) */
#define EIM_PHY_ADDR_LNKST_AUTO 0x00000000
/** the link status is forced up */
#define EIM_PHY_ADDR_LNKST_UP 0x00002000
/** the link status is forced down */
#define EIM_PHY_ADDR_LNKST_DOWN 0x00004000
/** reserved, do not use */
#define EIM_PHY_ADDR_LNKST_RES 0x00006000
/** Speed Control */
#define EIM_PHY_ADDR_SPEED_MASK 0x00001800
/** field offset */
#define EIM_PHY_ADDR_SPEED_OFFSET 11
/** Data Rate 10 MBPS */
#define EIM_PHY_ADDR_SPEED_M10 0x00000000
/** Data Rate 100 MBPS */
#define EIM_PHY_ADDR_SPEED_M100 0x00000800
/** Data Rate 1 GBPS */
#define EIM_PHY_ADDR_SPEED_G1 0x00001000
/** automatic mode detection by the Ethernet PHY (default) */
#define EIM_PHY_ADDR_SPEED_AUTO 0x00001800
/** Full Duplex Control */
#define EIM_PHY_ADDR_FDUP_MASK 0x00000600
/** field offset */
#define EIM_PHY_ADDR_FDUP_OFFSET 9
/** automatic mode detection by the Ethernet PHY (default) */
#define EIM_PHY_ADDR_FDUP_AUTO 0x00000000
/** full duplex mode */
#define EIM_PHY_ADDR_FDUP_EN 0x00000200
/** reserved */
#define EIM_PHY_ADDR_FDUP_RES 0x00000400
/** half duplex mode */
#define EIM_PHY_ADDR_FDUP_DIS 0x00000600
/** Flow Control Mode TX */
#define EIM_PHY_ADDR_FCONTX_MASK 0x00000180
/** field offset */
#define EIM_PHY_ADDR_FCONTX_OFFSET 7
/** automatic mode detection by the Ethernet PHY (default) */
#define EIM_PHY_ADDR_FCONTX_AUTO 0x00000000
/** flow control in receive (ingress direction) only */
#define EIM_PHY_ADDR_FCONTX_EN 0x00000080
/** reserved */
#define EIM_PHY_ADDR_FCONTX_RES 0x00000100
/** flow control in transmit (egress direction) only */
#define EIM_PHY_ADDR_FCONTX_DIS 0x00000180
/** Flow Control Mode RX */
#define EIM_PHY_ADDR_FCONRX_MASK 0x00000060
/** field offset */
#define EIM_PHY_ADDR_FCONRX_OFFSET 5
/** automatic mode detection by the Ethernet PHY (default) */
#define EIM_PHY_ADDR_FCONRX_AUTO 0x00000000
/** flow control in receive (ingress direction) only */
#define EIM_PHY_ADDR_FCONRX_EN 0x00000020
/** reserved */
#define EIM_PHY_ADDR_FCONRX_RES 0x00000040
/** flow control in transmit (egress direction) only */
#define EIM_PHY_ADDR_FCONRX_DIS 0x00000060
/** PHY Address */
#define EIM_PHY_ADDR_ADDR_MASK 0x0000001F
/** field offset */
#define EIM_PHY_ADDR_ADDR_OFFSET 0

/* Fields of "PHY MDIO Polling Status per PORT" */
/** PHY supports MAC turning of TX clk */
#define EIM_MDIO_STAT_CLK_STOP_CAPABLE 0x00000100
/* is not supported
#define EIM_MDIO_STAT_CLK_STOP_CAPABLE_DIS 0x00000000 */
/** is supported */
#define EIM_MDIO_STAT_CLK_STOP_CAPABLE_EN 0x00000100
/** PHY and link partner support EEE for current speed */
#define EIM_MDIO_STAT_EEE_CAPABLE 0x00000080
/* is not supported
#define EIM_MDIO_STAT_EEE_CAPABLE_DIS 0x00000000 */
/** is supported */
#define EIM_MDIO_STAT_EEE_CAPABLE_EN 0x00000080
/** PHY Active Status
    Indicates if the external PHY is responding to MDIO accesses. */
#define EIM_MDIO_STAT_PACT 0x00000040
/* the PHY is inactive or not present
#define EIM_MDIO_STAT_PACT_INACTIVE 0x00000000 */
/** the PHY is active and responds to MDIO accesses */
#define EIM_MDIO_STAT_PACT_ACTIVE 0x00000040
/** Link Status
    This status information is retrieved from the attached Ethernet PHY by polling the related MDIO register. */
#define EIM_MDIO_STAT_LSTAT 0x00000020
/* the link is down
#define EIM_MDIO_STAT_LSTAT_DOWN 0x00000000 */
/** the link is up */
#define EIM_MDIO_STAT_LSTAT_UP 0x00000020
/** Speed Control */
#define EIM_MDIO_STAT_SPEED_MASK 0x00000018
/** field offset */
#define EIM_MDIO_STAT_SPEED_OFFSET 3
/** Data Rate 10 MBPS */
#define EIM_MDIO_STAT_SPEED_M10 0x00000000
/** Data Rate 100 MBPS */
#define EIM_MDIO_STAT_SPEED_M100 0x00000008
/** Data Rate 1 GBPS */
#define EIM_MDIO_STAT_SPEED_G1 0x00000010
/** reserved */
#define EIM_MDIO_STAT_SPEED_RES 0x00000018
/** Full Duplex Status
    Indicates if the attached PHY runs in half- or full-duplex mode. */
#define EIM_MDIO_STAT_FDUP 0x00000004
/* half-duplex mode
#define EIM_MDIO_STAT_FDUP_HALF 0x00000000 */
/** full-duplex mode */
#define EIM_MDIO_STAT_FDUP_FULL 0x00000004
/** Receive Pause Enable Status
    This status information is retrieved from the attached Ethernet PHY by polling the related MDIO register. */
#define EIM_MDIO_STAT_RXPAUEN 0x00000002
/* the link partner does not send pause frames
#define EIM_MDIO_STAT_RXPAUEN_DIS 0x00000000 */
/** the link partner sends pause frames */
#define EIM_MDIO_STAT_RXPAUEN_EN 0x00000002
/** Transmit Pause Enable Status
    This status information is retrieved from the attached Ethernet PHY by polling the related MDIO register. */
#define EIM_MDIO_STAT_TXPAUEN 0x00000001
/* the link partner does not accept pause frames
#define EIM_MDIO_STAT_TXPAUEN_DIS 0x00000000 */
/** the link partner accepts pause frames */
#define EIM_MDIO_STAT_TXPAUEN_EN 0x00000001

/* Fields of "EEE auto negotiation overides" */
/** clk stop capable */
#define EIM_ANEG_EEE_CLK_STOP_CAPABLE_MASK 0x0000000C
/** field offset */
#define EIM_ANEG_EEE_CLK_STOP_CAPABLE_OFFSET 2
/** automatic detection by auto negotiation with PHY (default) */
#define EIM_ANEG_EEE_CLK_STOP_CAPABLE_AUTO 0x00000000
/** force capable on */
#define EIM_ANEG_EEE_CLK_STOP_CAPABLE_EN 0x00000004
/** reserved */
#define EIM_ANEG_EEE_CLK_STOP_CAPABLE_RES 0x00000008
/** force capable off */
#define EIM_ANEG_EEE_CLK_STOP_CAPABLE_DIS 0x0000000C
/** EEE capable */
#define EIM_ANEG_EEE_EEE_CAPABLE_MASK 0x00000003
/** field offset */
#define EIM_ANEG_EEE_EEE_CAPABLE_OFFSET 0
/** automatic detection by auto negotiation with PHY (default) */
#define EIM_ANEG_EEE_EEE_CAPABLE_AUTO 0x00000000
/** force capable on */
#define EIM_ANEG_EEE_EEE_CAPABLE_EN 0x00000001
/** reserved */
#define EIM_ANEG_EEE_EEE_CAPABLE_RES 0x00000002
/** force capable off */
#define EIM_ANEG_EEE_EEE_CAPABLE_DIS 0x00000003

/* Fields of "xMII Port Configuration Register" */
/** Hardware Reset
    Resets all related hardware modules except for the register settings. */
#define EIM_MII_CFG_RES 0x00008000
/* reset is off
#define EIM_MII_CFG_RES_OFF 0x00000000 */
/** reset is active */
#define EIM_MII_CFG_RES_ON 0x00008000
/** xMII Interface Enable
    The corresponding port can only be enabled if the disable signal at macro boundary is inactive. */
#define EIM_MII_CFG_EN 0x00004000
/* disable the interface
#define EIM_MII_CFG_EN_DIS 0x00000000 */
/** Loopback
    Enables the far-end tesloop which sends back all ingress data (RX when MAC mode) back to the egress port (TX when MAC mode). */
#define EIM_MII_CFG_LPBK 0x00000800
/* disable the interface
#define EIM_MII_CFG_LPBK_DIS 0x00000000 */
/** enable the interface */
#define EIM_MII_CFG_LPBK_EN 0x00000800
/** CRS Sensitivity Configuration
    These Bits are only valid in PHY Mode. CRS can be configured depending on RX and TX activity and Half/Full Duplex Modes (HDX/FDX) */
#define EIM_MII_CFG_CRS_MASK 0x00000600
/** field offset */
#define EIM_MII_CFG_CRS_OFFSET 9
/** HDX:TX+RX, FDX:RX */
#define EIM_MII_CFG_CRS_MODE1 0x00000000
/** HDX:TX+RX, FDX:0 */
#define EIM_MII_CFG_CRS_MODE2 0x00000200
/** HDX:RX, FDX:RX */
#define EIM_MII_CFG_CRS_MODE3 0x00000400
/** HDX:RX, FDX:0 */
#define EIM_MII_CFG_CRS_MODE4 0x00000600
/** RGMII In Band Status
    If RGMII mode is selected, this bit controls if the In Band Status Bits Link, Clock Speed duplex are transmitted during IPG */
#define EIM_MII_CFG_RGMII_IBS 0x00000100
/* RGMII In Band Status off
#define EIM_MII_CFG_RGMII_IBS_OFF 0x00000000 */
/** RGMII In Band Satus on */
#define EIM_MII_CFG_RGMII_IBS_ON 0x00000100
/** RMII Reference Clock Direction of the Port
    If RMII mode is selected, this bit controls the clock source of the port. */
#define EIM_MII_CFG_RMII 0x00000080
/* RMII clock is input
#define EIM_MII_CFG_RMII_IN 0x00000000 */
/** RMII clock is output */
#define EIM_MII_CFG_RMII_OUT 0x00000080
/** xMII Port Interface Clock Rate
    Selects the data and clock rate for the xMII interface. */
#define EIM_MII_CFG_MIIRATE_MASK 0x00000070
/** field offset */
#define EIM_MII_CFG_MIIRATE_OFFSET 4
/** 2.5 MHz */
#define EIM_MII_CFG_MIIRATE_M2P5 0x00000000
/** 25 MHz */
#define EIM_MII_CFG_MIIRATE_M25 0x00000010
/** 125 MHz */
#define EIM_MII_CFG_MIIRATE_M125 0x00000020
/** 50 MHz */
#define EIM_MII_CFG_MIIRATE_M50 0x00000030
/** Speed used from Autopolling */
#define EIM_MII_CFG_MIIRATE_AUTO 0x00000040
/** xMII Interface Mode
    This selects the xMII interface mode. */
#define EIM_MII_CFG_MIIMODE_MASK 0x0000000F
/** field offset */
#define EIM_MII_CFG_MIIMODE_OFFSET 0
/** (G)MII PHY mode, connected to external MAC */
#define EIM_MII_CFG_MIIMODE_MIIP 0x00000000
/** (G)MII MAC mode, connected to external PHY */
#define EIM_MII_CFG_MIIMODE_MIIM 0x00000001
/** RMII PHY mode, connected to external MAC */
#define EIM_MII_CFG_MIIMODE_RMIIP 0x00000002
/** RMII MAC mode, connected to external PHY */
#define EIM_MII_CFG_MIIMODE_RMIIM 0x00000003
/** RGMII MAC mode, connected to external PHY */
#define EIM_MII_CFG_MIIMODE_RGMII 0x00000004

/* Fields of "Configuration of Clock Delay" */
/** Lock Status MDL of Receive PCDU */
#define EIM_PCDU_RXLOCK 0x00008000
/* Receive MDL is out of sync
#define EIM_PCDU_RXLOCK_UNLOCK 0x00000000 */
/** Receive MDL is LOCKED */
#define EIM_PCDU_RXLOCK_LOCKED 0x00008000
/** Lock Status of MDL of Transmit PCDU */
#define EIM_PCDU_TXLOCK 0x00004000
/* Transmit MDL is out of sync
#define EIM_PCDU_TXLOCK_UNLOCK 0x00000000 */
/** Transmit MDL is LOCKED */
#define EIM_PCDU_TXLOCK_LOCKED 0x00004000
/** Input Clock Selection for Receive PCDU
    Selection of AUTO mode is recommended for normal operation. In this mode, RXCLK is used if the clock rate is 125 MHz and CLKREF in all other cases. */
#define EIM_PCDU_RXSEL_CLK_MASK 0x00003000
/** field offset */
#define EIM_PCDU_RXSEL_CLK_OFFSET 12
/** Selection of input clock depends on speed */
#define EIM_PCDU_RXSEL_CLK_AUTO 0x00000000
/** Input clock is CLKREF (125 MHz) */
#define EIM_PCDU_RXSEL_CLK_CLKREF 0x00001000
/** Input clock is RXCLK */
#define EIM_PCDU_RXSEL_CLK_RXCLK 0x00002000
/** reserved */
#define EIM_PCDU_RXSEL_CLK_RES3 0x00003000
/** Reset of Receive PCDU */
#define EIM_PCDU_RXINIT 0x00000800
/* Normal operation of Receive PCDU
#define EIM_PCDU_RXINIT_NORMAL 0x00000000 */
/** Reset Receive PCDU */
#define EIM_PCDU_RXINIT_INIT 0x00000800
/** Power Down of Receive PCDU */
#define EIM_PCDU_RXPD 0x00000400
/* Receive PCDU is enabled
#define EIM_PCDU_RXPD_ENABLE 0x00000000 */
/** Receive PCDU is in Power Down Mode */
#define EIM_PCDU_RXPD_PDOWN 0x00000400
/** Configure Receive Clock Delay
    Configure the delay of RX_CLK_D versus RX_CLK in steps of 500 ps. The resulting delay is TD = RXDLY * 500 ps. */
#define EIM_PCDU_RXDLY_MASK 0x00000380
/** field offset */
#define EIM_PCDU_RXDLY_OFFSET 7
/** Input Reference Clock Selection for Transmit PCDU
    Selection of AUTO mode is recommended for normal operation. In this mode, TXCLK is used if the clock rate is 125 MHz and CLKREF in all other cases. */
#define EIM_PCDU_TXSEL_CLK_MASK 0x00000060
/** field offset */
#define EIM_PCDU_TXSEL_CLK_OFFSET 5
/** Selection of input clock depends on speed */
#define EIM_PCDU_TXSEL_CLK_AUTO 0x00000000
/** Input clock is CLKREF (125 MHz) */
#define EIM_PCDU_TXSEL_CLK_CLKREF 0x00000020
/** Input clock is TXCLK */
#define EIM_PCDU_TXSEL_CLK_TXCLK 0x00000040
/** reserved */
#define EIM_PCDU_TXSEL_CLK_RES3 0x00000060
/** Reset of Transmit PCDU */
#define EIM_PCDU_TXINIT 0x00000010
/* Normal operation of Transmit PCDU
#define EIM_PCDU_TXINIT_NORMAL 0x00000000 */
/** Reset Transmit PCDU */
#define EIM_PCDU_TXINIT_INIT 0x00000010
/** Power Down of Transmit PCDU */
#define EIM_PCDU_TXPD 0x00000008
/* Transmit PCDU is enabled
#define EIM_PCDU_TXPD_ENABLE 0x00000000 */
/** Transmit PCDU is in Power Down Mode */
#define EIM_PCDU_TXPD_PDOWN 0x00000008
/** Configure Transmit Clock Delay
    Configure the delay of TX_CLK_D versus TX_CLK in steps of 500ps. The total configured delay is TD = TXDLY * 500ps. */
#define EIM_PCDU_TXDLY_MASK 0x00000007
/** field offset */
#define EIM_PCDU_TXDLY_OFFSET 0

/* Fields of "Configuration of Jitter Buffer" */
/** TXB Under/Overflow Indicator
     */
#define EIM_BUFF_TXB_ERR 0x00002000
/* TXB Under/Overflow never detected
#define EIM_BUFF_TXB_ERR_NONE 0x00000000 */
/** TXB Under/Overflow occurred at least once */
#define EIM_BUFF_TXB_ERR_ONCE 0x00002000
/** TXB Write pointer offset to read pointer
    The read pointer always starts at position 0. The write pointer starts at the programmed value. */
#define EIM_BUFF_TXB_DLY_MASK 0x00001C00
/** field offset */
#define EIM_BUFF_TXB_DLY_OFFSET 10
/** TXB initialization
    Initializes the TXB. Should be done afte over- or underflow. */
#define EIM_BUFF_TXB_INIT 0x00000200
/** TXB enable
    Enables the RXB. */
#define EIM_BUFF_TXB_EN 0x00000100
/** RXB Under/Overflow Indicator
     */
#define EIM_BUFF_RXB_ERR 0x00000020
/* RXB Under/Overflow never detected
#define EIM_BUFF_RXB_ERR_NONE 0x00000000 */
/** RXB Under/Overflow occurred at least once */
#define EIM_BUFF_RXB_ERR_ONCE 0x00000020
/** RXB Write pointer offset to read pointer
    The read pointer always starts at position 0. The write pointer starts at the programmed value. */
#define EIM_BUFF_RXB_DLY_MASK 0x0000001C
/** field offset */
#define EIM_BUFF_RXB_DLY_OFFSET 2
/** RXB initialization
    Initializes the RXB. Should be done afte over- or underflow. */
#define EIM_BUFF_RXB_INIT 0x00000002
/** RXB enable
    Enables the RXB. */
#define EIM_BUFF_RXB_EN 0x00000001

/*! @} */ /* EIM_REGISTER */

#endif /* _eim_reg_h */
