/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _falcon_ll_h
#define _falcon_ll_h

/** \addtogroup MAPI_REFERENCE_INTERNAL
   @{
*/

/** \defgroup FALCON_INTERNAL FalcON Low-Level Interface
   @{
*/

/** Ingress queue of UNI port 0 */
#define FALCON_INGRESS_QUEUE_LAN_0     0
/** Ingress queue of UNI port 1 */
#define FALCON_INGRESS_QUEUE_LAN_1     1
/** Ingress queue of UNI port 2 */
#define FALCON_INGRESS_QUEUE_LAN_2     2
/** Ingress queue of UNI port 3 */
#define FALCON_INGRESS_QUEUE_LAN_3     3

enum lan_mode {
	/** 10/100/1000BASE-T automatic speed negotiation */
	LAN_MAC_MODE_AUTO = 0,
	/** MII/RMII interface mode at 10, 100, or 200 Mbit/s */
	LAN_MAC_MODE_MII = 1,
	/** GMII/RGMII interface mode at 1000 Mbit/s */
	LAN_MAC_MODE_GMII = 2
};

/** Ethernet PHY duplex modes
*/
enum lan_mode_duplex {
	/** 10/100/1000BASE-T automatic speed negotiation */
	LAN_MAC_MODE_DUPLEX_AUTO = 0,
	/** 10BASE-T fixed speed selection */
	LAN_MAC_MODE_DUPLEX_FULL = 1,
	/** 100BASE-T fixed speed selection */
	LAN_MAC_MODE_DUPLEX_HALF = 2
};

/** Ethernet PHY duplex modes
*/
enum lan_mode_flow {
	/** flow control is automatic */
	LAN_MAC_MODE_FLOW_AUTO = 0,
	/** flow control in receive (ingress direction) only */
	LAN_MAC_MODE_FLOW_RX = 1,
	/** flow control in transmit (egress direction) only */
	LAN_MAC_MODE_FLOW_TX = 2,
	/** flow control in receive and transmit direction */
	LAN_MAC_MODE_FLOW_RXTX = 3,
	/** flow control is disabled */
	LAN_MAC_MODE_FLOW_NONE = 4
};


/** IQT entry
*/
struct iqt_entry {
	uint16_t qe;
	uint16_t qdth;
	uint16_t qrth;
	uint16_t qb;
	uint16_t qbth;
	uint16_t qbtl;
	uint16_t qf;
	uint16_t bp;
	uint16_t pocc;
	uint16_t qocc;
	uint32_t qdc;
	uint16_t tick;
	uint32_t tmask;  /* bit mask t0...t17, link0, link1 */
	uint16_t tqpp;
	uint16_t hqpp;
};

struct pdu_info {
	/** PDU length in bytes */
	uint32_t len;
	/** logical segment address - head */
	uint32_t hlsa;
	/** logical segment address - tail */
	uint32_t tlsa;
	/** number of segments */
	uint32_t segments;
};

/**
   Initialize the EIM block.
*/
void eim_init(void);

/**
   Configure LAN ports.
*/
void eim_mac_config_set(const enum lan_mode mode,
			const enum lan_mode_duplex mode_duplex,
			const enum lan_mode_flow mode_flow);

void eim_mii_config_set(const uint8_t xmii_port_id, uint32_t miicfg);

/**
   Read MDIO register.
*/
int eim_mdio_data_read(const uint8_t addr_dev, const uint8_t addr_reg,
		       uint16_t *data);

/**
   Write MDIO register.
*/
int eim_mdio_data_write(const uint8_t addr_dev, const uint8_t addr_reg,
			const uint16_t data);

/**
   Initialize the IQM block.
*/
void iqm_init(void);

/** enable/disable a queue */
void iqm_queue_enable_set(const uint16_t queue_idx, const bool queue_en);

/**
   Initialize the GPEARB block.
*/
void gpearb_init(void);

/**
   Initialize the FSQM block.
*/
void fsqm_init(void);

/**
   Initialize the ICTRLL block.
*/
void ictrll_init(void);

/**
   Enable LAN ports.
   \param lan_port_en  LAN port enable
*/
void ictrll_port_enable_set(const bool lan_port_en);

/**
   Initialize the OCTRLL block.
*/
void octrll_init(void);

/**
   Enable LAN ports.
   \param lan_port_en 	LAN port enable flags
*/
void octrll_port_enable_set(const bool lan_port_en);

/**
   Read the PDU information from the hardware. This information will be used to
   read the PDU data afterwards.

   The data read process is splitted into tow functions to allow the calling
   process to allocate the destination data memory.
*/
int falcon_pdu_info_read(const uint8_t qid, struct pdu_info *info);

/**
   Read the PDU data from the hardware.
   In case that the data pointer is zero the PDU will be freed.
*/
int falcon_pdu_data_read(const struct pdu_info *info, uint8_t *data);

/**
   Write a ethernet frame to the specified LAN port. This mechanism doesn't use
   the packet engine.

   \param lan_port   LAN port number
   \param len        data length
   \param data       ethernet frame (not padded, no fcs)

   \return
   - -1 error
   - 0 success
*/
int falcon_pdu_write(const uint32_t len, const uint8_t *data);

/*! @} */

/*! @} */

#endif
