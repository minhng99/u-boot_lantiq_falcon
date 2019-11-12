/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#include "falcon_std_defs.h"
#include "falcon_resource.h"
#include "falcon_register.h"
#include "falcon_ll.h"

#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>

/* EIM declarations*/
static struct gpon_reg_eim_a1x * const eim_a1x =
	(struct gpon_reg_eim_a1x *) GPON_EIM_BASE;
static struct gpon_reg_eim_a2x * const eim_a2x =
	(struct gpon_reg_eim_a2x *) GPON_EIM_BASE;

/* IQM declarations*/
static struct gpon_reg_iqm * const iqm = (struct gpon_reg_iqm *) GPON_IQM_BASE;
#define IQM_SSB_SIZE		0x1200
#define IQM_MAX_QUEUE		9
/** Number of Ingress Packet Pointers */
#define IQM_NUM_IPP		3072
/** Ingress queue of CPU for data in downstream direction (to the LAN ports) */
#define IQM_QUEUE_CPU_DS	4
/** Ingress queue of CPU for data in uptream direction (to the OLT) */
#define IQM_QUEUE_CPU_US	8
/** Ingress queue of ANI port, non-OMCI data, unicast */
#define IQM_QUEUE_GEM_UC	5


/* GPEARB declarations*/
static struct gpon_reg_gpearb * const gpearb = (struct gpon_reg_gpearb *) GPON_GPEARB_BASE;
#define GPEARB_PID0_ID1		8       /* (rw) Port ID 1 */
#define GPEARB_PID0_ID1_INIT	0x0
#define GPEARB_PID0_ID1_MSK	((1<<6)-1)

/* FSQM declarations*/
static struct gpon_reg_fsqm * const fsqm = (struct gpon_reg_fsqm *) GPON_FSQM_BASE;
/** Buffer segment size, in number of bytes */
#define FSQM_BUFFER_SEGMENT_SIZE 64
#define FSQM_RCNT_INIT		0x1
/** Maximum Logical Link Table (LLT) value */
#define FSQM_LLT_MAX		0x4800
/** Logical Link Table NIL pointer */
#define FSQM_LLT_NIL		0x7FFF
struct fsq {
	uint16_t head;
	uint16_t tail;
};

/* SSB declarations*/
static struct gpon_reg_sbs0ctrl * const sbs0ctrl = (struct gpon_reg_sbs0ctrl *)GPON_SBS0CTRL_BASE;
#define ONU_RAM_PACKET_BUFFER_OFFSET (sbs0ctrl_r32(bar1) & SBS0CTRL_BAR1_BA1V_MASK)

/* ICTRLL declarations*/
static struct gpon_reg_ictrll * const ictrll0 = (struct gpon_reg_ictrll * ) GPON_ICTRLL0_BASE;

/* OCTRLL declarations*/
static struct gpon_reg_octrll * const octrll0 = (struct gpon_reg_octrll *) GPON_OCTRLL0_BASE;

void eim_init(void)
{
	uint8_t i;
	sys_eth_hw_activate(SYS_ETH_ACT_MDIO);
	eim_mac_config_set(LAN_MAC_MODE_AUTO, LAN_MAC_MODE_DUPLEX_AUTO,
		LAN_MAC_MODE_FLOW_AUTO);
	for (i=0; i<2; i++) {
		eim_mii_config_set(i,
			EIM_MII_CFG_MIIRATE_M25 | EIM_MII_CFG_MIIMODE_RGMII);
	}
	/* correct settings for gphy */
	eim_w32(0x27, top_pdi.gphy_cfg_pll);
}

void eim_mac_config_set(const enum lan_mode mode, 
			const enum lan_mode_duplex mode_duplex,
			const enum lan_mode_flow mode_flow)
{
	uint32_t cfg = EIM_MAC_CTRL_0_FCS_EN | EIM_MAC_CTRL_0_PADEN_EN;

	switch (mode) {
	case LAN_MAC_MODE_AUTO:
	default:
		break;
	case LAN_MAC_MODE_MII:
		cfg |= EIM_MAC_CTRL_0_GMII_MII;
		break;
	case LAN_MAC_MODE_GMII:
		cfg |= EIM_MAC_CTRL_0_GMII_GMII;
		break;
	}

	switch (mode_duplex) {
	case LAN_MAC_MODE_DUPLEX_AUTO:
	default:
		break;

	case LAN_MAC_MODE_DUPLEX_FULL:
		cfg |= EIM_MAC_CTRL_0_FDUP_EN;
		break;

	case LAN_MAC_MODE_DUPLEX_HALF:
		cfg |= EIM_MAC_CTRL_0_FDUP_DIS;
		break;
	}

	switch (mode_flow) {
	case LAN_MAC_MODE_FLOW_AUTO:
	default:
		cfg |= EIM_MAC_CTRL_0_FCON_AUTO;
		break;
	case LAN_MAC_MODE_FLOW_RX:
		cfg |= EIM_MAC_CTRL_0_FCON_RX;
		break;
	case LAN_MAC_MODE_FLOW_TX:
		cfg |= EIM_MAC_CTRL_0_FCON_TX;
		break;
	case LAN_MAC_MODE_FLOW_RXTX:
		cfg |= EIM_MAC_CTRL_0_FCON_RXTX;
		break;
	case LAN_MAC_MODE_FLOW_NONE:
		cfg |= EIM_MAC_CTRL_0_FCON_NONE;
		break;
	}

	eim_w32(cfg, mac_pdi[0].ctrl_0);
	eim_w32(0, mac_pdi[0].testen);
}

void eim_mii_config_set(const uint8_t xmii_port_id, uint32_t miicfg)
{
	uint32_t cfg = miicfg | EIM_MII_CFG_EN;

	if (xmii_port_id<2) {
		eim_w32(cfg, mii_pdi[xmii_port_id].mii_cfg);
		/* configure and enable jitter buffers */
		cfg = EIM_BUFF_RXB_EN | EIM_BUFF_TXB_EN |
			EIM_BUFF_RXB_INIT | EIM_BUFF_TXB_INIT |
			3 << EIM_BUFF_TXB_DLY_OFFSET |
			3 << EIM_BUFF_RXB_DLY_OFFSET;
		eim_w32(cfg, mii_pdi[xmii_port_id].buff);
		eim_w32_mask(EIM_BUFF_RXB_INIT | EIM_BUFF_TXB_INIT, 0,
			mii_pdi[xmii_port_id].buff);
	}
}


/** The eim_mdio_data_read function provides read access to an external or
   internal Ethernet PHY.
*/
int eim_mdio_data_read(const uint8_t addr_dev, const uint8_t addr_reg,
		       uint16_t *data)
{
	uint32_t cnt;
	if (is_falcon_chip_a1x()) {
		uint32_t cfg = EIM_MAC_HEADER_RW_READ | EIM_MAC_HEADER_START_TX;

		set_val(cfg, 1, EIM_MAC_HEADER_ST_MASK, EIM_MAC_HEADER_ST_OFFSET);
		set_val(cfg, 2, EIM_MAC_HEADER_OP_MASK, EIM_MAC_HEADER_OP_OFFSET);
		set_val(cfg, addr_dev, EIM_MAC_HEADER_PHYAD_MASK,
			EIM_MAC_HEADER_PHYAD_OFFSET);
		set_val(cfg, addr_reg, EIM_MAC_HEADER_REGAD_MASK,
			EIM_MAC_HEADER_REGAD_OFFSET);

		cnt = 100;
		eim_a1x_w32(EIM_ISTAT_INT_MAC, mdio_mac_pdi.istat);
		while (cnt && ((eim_a1x_r32(mdio_mac_pdi.istat) & EIM_ISTAT_INT_MAC) ==
								  EIM_ISTAT_INT_MAC) ) {
			cnt--;
			udelay(10);
		}

		if (cnt == 0)
			return -1;

		cnt = 100;
		eim_a1x_w32(cfg, mdio_mac_pdi.mac_header);
		while (cnt && ((eim_a1x_r32(mdio_mac_pdi.istat) & EIM_ISTAT_INT_MAC)
									       == 0) ) {
			cnt--;
			udelay(10);
		}
		if (cnt == 0)
			return -2;

		/* *data = (eim_a1x_r32(mdio_mac_pdi.mac_data) & EIM_MAC_DATA_DATA_MASK);*/
		*data = (eim_a1x_r32(mdio_mac_pdi.startup) & EIM_STARTUP_DATA_MASK);
		eim_a1x_w32(EIM_ISTAT_INT_MAC, mdio_mac_pdi.istat);

	} else if (is_falcon_chip_a2x()) {
		cnt = 100;
		while (cnt && eim_a2x_r32(mdio_pdi.mdio_ctrl) & EIM_MDIO_CTRL_MBUSY) {
			cnt--;
			udelay(10);
		}
		if (cnt == 0)
			return -1;
		eim_a2x_w32(EIM_MDIO_CTRL_OP_RD | EIM_MDIO_CTRL_MBUSY_BUSY |
			((addr_dev << EIM_MDIO_CTRL_PHYAD_OFFSET) & EIM_MDIO_CTRL_PHYAD_MASK) |
			((addr_reg << EIM_MDIO_CTRL_REGAD_OFFSET) & EIM_MDIO_CTRL_REGAD_MASK),
			mdio_pdi.mdio_ctrl);
		cnt = 100;
		while (cnt && eim_a2x_r32(mdio_pdi.mdio_ctrl) & EIM_MDIO_CTRL_MBUSY) {
			cnt--;
    			udelay(10);
		}
		if (cnt == 0)
			return -1;

		*data = eim_a2x_r32(mdio_pdi.mdio_read) & EIM_MDIO_READ_RDATA_MASK;
	} else
		return -1;

	return 0;
}

/**
   Write MDIO register.
 */
int eim_mdio_data_write(const uint8_t addr_dev, const uint8_t addr_reg,
			const uint16_t data)
{
	uint32_t cnt;
	if (is_falcon_chip_a1x()) {
		uint32_t cfg = EIM_MAC_HEADER_START_TX;

		set_val(cfg, 1, EIM_MAC_HEADER_ST_MASK, EIM_MAC_HEADER_ST_OFFSET);
		set_val(cfg, 1, EIM_MAC_HEADER_OP_MASK, EIM_MAC_HEADER_OP_OFFSET);
		set_val(cfg, addr_dev, EIM_MAC_HEADER_PHYAD_MASK,
			EIM_MAC_HEADER_PHYAD_OFFSET);
		set_val(cfg, addr_reg, EIM_MAC_HEADER_REGAD_MASK,
			EIM_MAC_HEADER_REGAD_OFFSET);

		eim_a1x_w32(data, mdio_mac_pdi.mac_data);
		/*eim_a1x_w32(data, mdio_mac_pdi.startup);*/

		cnt = 100;
		eim_a1x_w32(EIM_ISTAT_INT_MAC, mdio_mac_pdi.istat);
		while (cnt && ((eim_a1x_r32(mdio_mac_pdi.istat) & EIM_ISTAT_INT_MAC) ==
								  EIM_ISTAT_INT_MAC) ) {
			cnt--;
			udelay(10);
		}

		if (cnt == 0)
			return -1;

		eim_a1x_w32(cfg, mdio_mac_pdi.mac_header);
		while (cnt && ((eim_a1x_r32(mdio_mac_pdi.istat) & EIM_ISTAT_INT_MAC)
									       == 0) ) {
			cnt--;
			udelay(10);
		}

		if (cnt == 0)
			return -2;
	} else if (is_falcon_chip_a2x()) {
		cnt = 100;
		while (cnt && eim_a2x_r32(mdio_pdi.mdio_ctrl) & EIM_MDIO_CTRL_MBUSY) {
			cnt--;
			udelay(10);
		}
		if (cnt == 0)
			return -1;
		eim_a2x_w32(data & EIM_MDIO_WRITE_WDATA_MASK, mdio_pdi.mdio_write);
		eim_a2x_w32(EIM_MDIO_CTRL_OP_WR | EIM_MDIO_CTRL_MBUSY_BUSY |
			((addr_dev << EIM_MDIO_CTRL_PHYAD_OFFSET) & EIM_MDIO_CTRL_PHYAD_MASK) |
			((addr_reg << EIM_MDIO_CTRL_REGAD_OFFSET) & EIM_MDIO_CTRL_REGAD_MASK),
			mdio_pdi.mdio_ctrl);
		cnt = 100;
		while (cnt && eim_a2x_r32(mdio_pdi.mdio_ctrl) & EIM_MDIO_CTRL_MBUSY) {
			cnt--;
    			udelay(10);
		}
		if (cnt == 0)
			return -1;
	} else
		return -1;

	return 0;
}

static void iqm_iqt_write(const uint16_t queue_idx,
			  const struct iqt_entry *entry)
{
	uint32_t iqtr;

	iqtr = 0;
	if (entry->qe)
		iqtr |= IQM_IQT00_QE;

	set_val(iqtr, entry->qrth, IQM_IQT00_QRTH_MASK, IQM_IQT00_QRTH_OFFSET);
	set_val(iqtr, entry->qdth, IQM_IQT00_QDTH_MASK, IQM_IQT00_QDTH_OFFSET);
	iqm_w32(iqtr, iqt[queue_idx].iqt0);

	iqtr = 0;
	if (entry->qb)
		iqtr |= IQM_IQT01_QB;

	set_val(iqtr, entry->qbth, IQM_IQT01_QBTH_MASK, IQM_IQT01_QBTH_OFFSET);
	set_val(iqtr, entry->qbtl, IQM_IQT01_QBTL_MASK, IQM_IQT01_QBTL_OFFSET);
	iqm_w32(iqtr, iqt[queue_idx].iqt1);

	iqtr = 0;
	if (entry->qf)
		iqtr |= IQM_IQT02_QF;

	if (entry->bp)
		iqtr |= IQM_IQT02_BP;

	set_val(iqtr, entry->pocc, IQM_IQT02_POCC_MASK, IQM_IQT02_POCC_OFFSET);
	set_val(iqtr, entry->qocc, IQM_IQT02_QOCC_MASK, IQM_IQT02_QOCC_OFFSET);
	iqm_w32(iqtr, iqt[queue_idx].iqt2);

	iqtr = 0;
	set_val(iqtr, entry->qdc, IQM_IQT03_QDC_MASK, IQM_IQT03_QDC_OFFSET);
	iqm_w32(iqtr, iqt[queue_idx].iqt3);

	iqm_w32(entry->tmask, iqt[queue_idx].iqt5);
}

void iqm_queue_enable_set(const uint16_t queue_idx, const bool queue_en)
{
	if (queue_idx < IQM_MAX_QUEUE) {
		if (queue_en)
			iqm_w32_mask(0, IQM_IQT00_QE, iqt[queue_idx].iqt0);
		else
			iqm_w32_mask(IQM_IQT00_QE, 0, iqt[queue_idx].iqt0);
	}
}

/*
    - Disable and clear all ingress queues
     IQM.IQT<n>0.QE = EN, <n> = 0 ... number of ingress queues - 1
     IQM.IQT<n>1.QB = EN,  <n> = 0 ... number of ingress queues - 1

      \todo define how the ingress queues can be cleared, HW documentation is
	    yet missing
*/
void iqm_init(void)
{
	/*  initialization such that all queues are enabled and blocked
	     all discard thresholds set to max, no reservation
	     all 36 WRR slots allocated
	     all queues can transmit to all threads
	*/
	int i;
	uint16_t queue_idx;
	struct iqt_entry iqt_entry;
	uint32_t qid[5] = {
		0x76543210,
		0x65432108,
		0x54321087,
		0x43210876,
		0x32108765,
	};

	iqm_w32(IQM_CTRL_RAW | IQM_CTRL_FRZ | IQM_CTRL_ACT, ctrl);

	iqm_w32(0 , irncr);
	iqm_w32(0 , irnicr);
	iqm_w32(IQM_IRNCR_QF7, irnen);

	/* for all ingress queues write default start table entry */
	iqt_entry.qe    = 0;       /* queue disable */
	iqt_entry.qdth  = IQM_SSB_SIZE;   /* queue discard threshold (2304
					     lowest value such that queue
					     occupies complete SSB) */
	iqt_entry.qrth  = 0;       /* queue reservation threshold */
	iqt_entry.qb    = 1;       /* queue blocked */
	iqt_entry.qbth  = IQM_SSB_SIZE;   /* queue backpressure threshold high
					     (no backpressure) */
	iqt_entry.qbtl  = 0;       /* queue backpressure threshold low
				      (no backpressure) */
	iqt_entry.qf    = 0;       /* status bit set to 0 */
	iqt_entry.bp    = 0;       /* status bit set to 0 */
	iqt_entry.pocc  = 0;       /* PDU occupancy counter */
	iqt_entry.qocc  = 0;       /* queue occupancy counter */
	iqt_entry.qdc   = 0;       /* queue PDU discard counter */
	iqt_entry.tqpp  = 0xFFFF;  /* tail queue packet pointer
				      (not visible for CPU) */
	iqt_entry.hqpp  = 0xFFFF;  /* head queue packet pointer
				      (not visible for CPU) */
	iqt_entry.tmask = 0;       /* disable all threads */

	for (queue_idx = 0; queue_idx < IQM_MAX_QUEUE; queue_idx++) {
		switch (queue_idx) {
		case IQM_QUEUE_CPU_DS:
		case IQM_QUEUE_CPU_US:
		case IQM_QUEUE_GEM_UC:
			/* forward to hardware/SCI */
			iqt_entry.qb = 0;
			break;
		default:
			/* make available for software */
			iqt_entry.qb = 1;
			break;
		}
		iqm_iqt_write(queue_idx, &iqt_entry);
	}

	iqm_w32(IQM_NUM_IPP, fpcr);
	iqm_w32(0, gocc);
	iqm_w32(0, gpdc);
	iqm_w32(0, ts);

	iqm_w32(IQM_SSB_SIZE, goth);     /*  total SSB capacity in
					     Segments (=18432) */
	iqm_w32(36, wrrc);               /*  36 slots in WRR used */

	for (i = 0; i < 5; i++)
		iqm_w32(qid[i], wrrq[i]); /* all queues treated equally*/

	/* sfreeX shouldn't be initialized */

	iqm_w32(0, drc);

	/* enable the module */
	iqm_w32_mask(IQM_CTRL_FRZ, IQM_CTRL_RAW | IQM_CTRL_ACT, ctrl);
}

static void gpearb_config(void)
{
	uint32_t wdata;
	uint32_t loop_cnt=0;
	uint32_t i;
	uint8_t nb_of_ports = 13;

	gpearb_w32(nb_of_ports, cntr);

	while (loop_cnt <= (nb_of_ports/4)) {
		wdata=0;
		for (i=0;i<4;i++) {
			if ((loop_cnt*4+i)< nb_of_ports) {
				wdata |=
					((loop_cnt*4+i) << (i*GPEARB_PID0_ID1));
			}
		}
		gpearb_w32(wdata, pid[loop_cnt]);
		loop_cnt++;
	}
}

void gpearb_init(void)
{
	gpearb_config();
}

/*
- FSQM deactivated
- IO buffer disabled
- all pause thresholds deasserted
- all interrupts disabled
- same prio for all masters, except CPU (highest prio)
- enable round robin
*/
static void fsqm_basic_init(void)
{
	uint32_t reg;

	fsqm_w32(0, ctrl);

	if (is_falcon_chip_a1x()) {
		reg  = 0x0;
		reg |= FSQM_PRIO_A1X_RR_EN;
		reg |= (1 << FSQM_PRIO_A1X_PIQM_OFFSET);
		reg |= (1 << FSQM_PRIO_A1X_POCTRL_OFFSET);
		reg |= (1 << FSQM_PRIO_A1X_PPCTRL_OFFSET);
		reg |= (1 << FSQM_PRIO_A1X_PICTRL_OFFSET);
		fsqm_w32(reg, prio_a1x);
		fsqm_w32(0, ifsc_a1x);
		fsqm_w32(0, imq_a1x);
	}

	/* Disable all interrupts */
	fsqm_w32(0, irncr);
	fsqm_w32(0, irnicr);
	fsqm_w32(0, irnen);

	fsqm_w32(0, ofsc);
	fsqm_w32(0, fsqt0);
	fsqm_w32(0, fsqt1);
	fsqm_w32(0, fsqt2);
	fsqm_w32(0, fsqt3);
	fsqm_w32(0, fsqt4);
	fsqm_w32(0, omq);
}

/*
   \param nb_of_elements   Number of memory elements that will be put into
                           the initial Free Segment Queue (FSQ).
                           A Linked List Table (LLT) will be built up starting
                           from first_element to last_element.
*/
static void fsqm_llt_init(const uint32_t first_element,
			  const uint32_t last_element)
{
	uint32_t i=first_element;
	int wdata;

	while (i < (last_element)) {
		wdata = i+1;
		fsqm_w32(wdata, ram[i]);
		fsqm_w32(FSQM_RCNT_INIT, rcnt[i]);
		i++;
	}

	fsqm_w32(FSQM_LLT_NIL, ram[i]);
	fsqm_w32(FSQM_RCNT_INIT, rcnt[i]);

	/* ofsq - is used */
	/* init in queue head & tail */
	wdata  = first_element << FSQM_OFSQ_HEAD_OFFSET;
	wdata |= last_element << FSQM_OFSQ_TAIL_OFFSET;
	fsqm_w32(wdata, ofsq);

	/* init in queue counter */
	fsqm_w32((last_element-first_element)-1, ofsc);

	if (is_falcon_chip_a2x()) {
		/* lsarng - is used */
		/* init range for checks to head & tail */
		wdata  = first_element << FSQM_LSARNG_MINLSA_OFFSET;
		wdata |= last_element << FSQM_LSARNG_MAXLSA_OFFSET;
		fsqm_w32(wdata, lsarng);
	}
	if (is_falcon_chip_a1x()) {
		/* ifsq - is not used? */
		/* init out queue head & tail */
		wdata  = FSQM_LLT_NIL << FSQM_IFSQ_A1X_HEAD_OFFSET;
		wdata |= FSQM_LLT_NIL << FSQM_IFSQ_A1X_TAIL_OFFSET;
		fsqm_w32(wdata, ifsq_a1x);

		/* init out queue counter */
		fsqm_w32(0, ifsc_a1x);
	}
}

static uint16_t fsqm_llt_read(const uint16_t idx)
{
	return fsqm_r32(ram[idx]);
}

static void fsqm_llt_write(const uint16_t idx, const uint32_t val)
{
	fsqm_w32(val, ram[idx]);
}

static uint16_t fsqm_seg_alloc(void)
{
	uint16_t hlsa;
	debug("A1 OFSC %d\n", fsqm_r32(ofsc));
	hlsa = (fsqm_r32(omq[1]) >> FSQM_OMQ_HLSA_OFFSET) &
				    FSQM_OMQ_HLSA_MASK;
	debug("A2 OFSC %d\n", fsqm_r32(ofsc));
	fsqm_w32(1, rcnt[hlsa]);
	if (hlsa == FSQM_LLT_NIL)
		printf("ooops, can't get enough segments\n");

	return hlsa;
}

static void fsqm_seg_free(const uint16_t tlsa, const uint16_t hlsa,
			  const uint16_t seg_len)
{
	if (tlsa == FSQM_LLT_NIL || hlsa == FSQM_LLT_NIL || seg_len == 0)
		return;

	/*
	- Free the data segments by writing to
		FSQM.OMQ.TLSA = TLSA
		FSQM.OMQ.HLSA = HLSA
		t.b.d.        = SEGL
	*/
	debug("F OFSC %d\n", fsqm_r32(ofsc));
	fsqm_w32((tlsa << FSQM_OMQ_TLSA_OFFSET) | hlsa, omq[seg_len]);
}

/**
   Init FSQM
*/
void fsqm_init(void)
{
	uint32_t llt_first = 0,
		 llt_last = (GPON_SBS0RAM_SIZE/FSQM_BUFFER_SEGMENT_SIZE);
	llt_last -= (sbs0ctrl_r32(bar1) & SBS0CTRL_BAR1_BA1V_MASK)/
						    FSQM_BUFFER_SEGMENT_SIZE;

	if (llt_last > FSQM_LLT_MAX)
		llt_last = FSQM_LLT_MAX;
	/* if more than 6 RAM cells are available, reduce to these */
	if (llt_last >= 6*512)
		llt_first=llt_last - 6*512;
	/* point to the last usable entry */
	llt_last--;

	/*
	- SW reset brings module into defined HW state
	- initializes all registers
	- builds linked list
	- and then activates FSQM
	*/
	fsqm_w32_mask(0, FSQM_CTRL_RES_EN, ctrl);
	fsqm_w32_mask(FSQM_CTRL_RES_EN, 0, ctrl);

	fsqm_basic_init();
	fsqm_llt_init(llt_first, llt_last);

	fsqm_w32_mask(0, 0, io_buf_rd);
	fsqm_w32_mask(0, 0, io_buf_wr);

	fsqm_w32_mask(0, FSQM_CTRL_ACT_EN, ctrl);
}

static int ssb_write(const uint32_t max_len, const uint8_t *data,
		     uint32_t *hlsa, uint32_t *tlsa)
{
	int ret = 0;
	uint32_t i, to_copy, len, segments;
	const uint8_t *ptr;
	unsigned long psa;

	ptr = data;
	len = max_len;
	segments = (max_len / FSQM_BUFFER_SEGMENT_SIZE) + 1;

	*hlsa = *tlsa = fsqm_seg_alloc();
	if (*tlsa == FSQM_LLT_NIL) {
		printf("ooops, can't get enough segments\n");
		return -1;
	}

	do {

		if (len > FSQM_BUFFER_SEGMENT_SIZE)
			to_copy = FSQM_BUFFER_SEGMENT_SIZE;
		else
			to_copy = len;

		psa = GPON_SBS0RAM_BASE + ONU_RAM_PACKET_BUFFER_OFFSET +
		      (*tlsa * FSQM_BUFFER_SEGMENT_SIZE);
#ifdef DEBUG
		if (psa >= GPON_SBS0RAM_END)
			printf("TX SSB invalid: 0x%08lX\n", psa);
#endif

		if (((ulong_t)ptr & (sizeof(ulong_t)-1)) == 0) {
			/* source (ptr) is aligned */
			for (i=0;i<to_copy;) {
				reg_w32(*((uint32_t *)ptr), (void *)psa);
				ptr += 4;
				psa += 4;
				i += 4;
			}
		} else {
			for (i = 0; i < to_copy;) {
				uint32_t val;
				val = ((ptr[0])<<24) + ((ptr[1])<<16) +
				      ((ptr[2])<<8) + (ptr[3]);
				reg_w32(val, (void *)psa);
				ptr += 4;
				psa += 4;
				i += 4;
			}
		}
		len -= to_copy;
		if (len) {
			i = *tlsa;
			*tlsa = fsqm_seg_alloc();
			if (*tlsa == FSQM_LLT_NIL) {
				printf("ooops, can't get enough segments\n");
				fsqm_seg_free(*hlsa, i, segments);
				return -1;
			}
			fsqm_llt_write(i, *tlsa);
		}
	} while (len);

	return ret;
}

void ictrll_port_enable_set(const bool lan_port_en)
{
	if (lan_port_en)
		ictrll0_w32_mask(0, ICTRLL_CTRL_ACT_EN, ctrl);
	else
		ictrll0_w32_mask(ICTRLL_CTRL_ACT_EN, 0, ctrl);
}

void ictrll_init(void)
{
	uint32_t cfg;

	/*
	- DBG disabled
	- BroadCast disabled
	- RAW mode disabled
	- Soft reset disabled
	- ICTRL disabled
	*/
	ictrll0_w32(0, ctrl);

	/*
	Register DMAW_CFG
	- Queue for Alloc commands = 1
	- Queue for Free commands = 1
	- 8 wait cycles
	*/
	cfg  = ICTRLL_DMAW_CFG_ALLOCQ | ICTRLL_DMAW_CFG_FREEQ;
	set_val(cfg, 0x8, ICTRLL_DMAW_CFG_LSARLMT_MASK,
		ICTRLL_DMAW_CFG_LSARLMT_OFFSET);
	ictrll0_w32(cfg, dmaw_cfg);

	/* Ethernet DA (high adr) = 0 */
	ictrll0_w32(0, rawda0);

	/* Ethernet DA (low adr) = 0 */
	ictrll0_w32(0, rawda1);

	/* max size for ethernet: FALCON_MAX_ETHERNET_FRAME_LENGTH */
	ictrll0_w32(FALCON_MAX_ETHERNET_FRAME_LENGTH, maxsize0);

	/* Initialize all counters = 0 */
	ictrll0_w32(0, rxbcnth);
	ictrll0_w32(0, rxbcntl);
	ictrll0_w32(0, ovrsize);
	ictrll0_w32(0, dmawerr);
	ictrll0_w32(0, macerr);
	ictrll0_w32(0, rxpcnt);
	ictrll0_w32(0, rxp64cnt);
	ictrll0_w32(0, rxp65cnt);
	ictrll0_w32(0, rxp128cnt);
	ictrll0_w32(0, rxp256cnt);
	ictrll0_w32(0, rxp512cnt);
	ictrll0_w32(0, rxp1024cnt);
	ictrll0_w32(0, rxp1519cnt);
	ictrll0_w32(0, undsize);

	/* Disable all interrupts */
	ictrll0_w32(0, irncr);
	ictrll0_w32(0, irnicr);
	ictrll0_w32(0, irnen);
}


void octrll_init(void)
{
	/*
	- assigned EPN: 0, 1, 2, 3
	- timeout enabled: 1s
	- FSQM queue 1 selected (LSA freeing)
	- all counters set = 0
	- module OCTRLL activated
	*/

	octrll0_w32_mask(OCTRLL_CTRL_ACT_EN, OCTRLL_CTRL_TOUTEN_EN,
			      ctrl);

	/* timeout 1 s */
	octrll0_w32(0x6d, toutcfg);
	octrll0_w32(0, cfg);

	octrll0_w32(OCTRLL_DCTRL_FQ_Q1, dctrl);

	/* reset counter */
	octrll0_w32(0, txbcntl);
	octrll0_w32(0, txbcnth);
	octrll0_w32(0, txpcnt);
	octrll0_w32(0, txp64cnt);
	octrll0_w32(0, txp65cnt);
	octrll0_w32(0, txp128cnt);
	octrll0_w32(0, txp256cnt);
	octrll0_w32(0, txp512cnt);
	octrll0_w32(0, txp1024cnt);
	octrll0_w32(0, txp1519cnt);
}

void octrll_port_enable_set(const bool lan_port_en)
{
	if (lan_port_en)
		octrll0_w32_mask(0, OCTRLL_CTRL_ACT_EN, ctrl);
	else
		octrll0_w32_mask(OCTRLL_CTRL_ACT_EN, 0, ctrl);
}

static int octrll_write(const uint32_t max_len, const uint32_t hlsa,
			const uint32_t tlsa)
{
	uint32_t hdrl, bdyl, cfg;

	if(max_len > FSQM_BUFFER_SEGMENT_SIZE) {
		hdrl = FSQM_BUFFER_SEGMENT_SIZE;
		bdyl = max_len - FSQM_BUFFER_SEGMENT_SIZE;
	} else {
		hdrl = max_len;
		bdyl = 0;
	}
	octrll0_w32(hlsa, rawcfg0);
	cfg = 0;
	cfg |= (hdrl << OCTRLL_RAWCFG1_HDRL_OFFSET) & OCTRLL_RAWCFG1_HDRL_MASK;
	cfg |= (bdyl << OCTRLL_RAWCFG1_BDYL_OFFSET) & OCTRLL_RAWCFG1_BDYL_MASK;
	octrll0_w32(cfg, rawcfg1);
	octrll0_w32(OCTRLL_RAWCTRL_RAWTX, rawctrl);

	return 0;
}

#define GPE_PDU_TYPE_ETH	0

/** Read from ingress queue

   The OMCI messages can be received either directly from the OMCI ingress
   queue (before SCE processing) or from one or two egress queues (one per
   OMCI priority, after SCE processing).
*/
int falcon_pdu_info_read(const uint8_t qid, struct pdu_info *info)
{
	uint32_t reg, cnt;

	info->len = 0;
	info->segments = 0;
	info->hlsa = info->tlsa = FSQM_LLT_NIL;

	cnt = iqm_r32(iqt[qid].iqt2);
	if ((cnt & IQM_IQT02_QOCC_MASK) == 0)
		/* no data available */
		return -1;
	/*
	Hardware Programming Details - Read from Ingress Queue
	- The ingress queue <n> must be configured such that it is not read by
		the hardware scheduler.
		The OMCI ingress queue number is defined as
		n = ONU_GPE_INGRESS_QUEUE_OMCI
		IQT<n>0.QE = EN   enable the queue to receive data
		IQT<n>1.QB = EN   block the queue from HW WRR scheduling

		done in GPE_Init by default()
	*/

	/*
	- send a dequeue command to the IQM
         if (IQM.DRCR.EN != 0) {wait} else {
         IQM.DRCR.QID = ONU_GPE_INGRESS_QUEUE_OMCI
         IQM.DRCR.EN  = EN }

	*/
	iqm_w32_mask((IQM_DRC_QID_MASK | IQM_DRC_ENA), (qid | IQM_DRC_ENA),drc);
	/*
	- read the dequeue result from the IQM
         if (IQM.DRCR.ENA != 0) {wait} else {
         if (IQM.DRPR0.PDUT != ONU_GPE_PDU_TYPE_OMCI) {invalid PDU type, dicard
							the data} else
         read IQM.DRPR0.PLEN: this is the payload length to be handled
         read IQM.DRPR1.HLSA: this is the pointer to the first data segment
                              (which is the only segment for 48-byte OMCI)
         read IQM.DRPR1.TLSA: this is the pointer to the last data segment
                              (same as HLSA for 48-byte OMCI)
         read IQM.DRPR2.TS  : for debug only - this is a receive time stamp,
                              the time stamp unit is one clock cycle of the
                              312.5 MHz module clock (3.2 ns), rolling over
			      every 53 ms
	*/
	cnt = 0;
	while ((iqm_r32(drc) & IQM_DRC_ENA) && (cnt < 3000))
		cnt++;

	if (cnt == 3000) {
		printf("no drc response\n");
		return -2;
	}

	reg = iqm_r32(drp2);
	info->len = (reg & IQM_DRP2_PLEN_MASK) >> IQM_DRP2_PLEN_OFFSET;
	info->segments = (info->len / FSQM_BUFFER_SEGMENT_SIZE) + 1;
	reg = iqm_r32(drp3);
	info->hlsa = (reg & IQM_DRP3_HLSA_MASK) >> IQM_DRP3_HLSA_OFFSET;
	info->tlsa = (reg & IQM_DRP3_TLSA_MASK) >> IQM_DRP3_TLSA_OFFSET;

	debug("hlsa/tlsa %08x\n", reg);

	if ((iqm_r32(drp1) & IQM_DRP1_PDUT_MASK) !=
			(uint32_t)(GPE_PDU_TYPE_ETH << IQM_DRP1_PDUT_OFFSET)) {
		printf("wrong pdu type\n");
		/* discard data */
		falcon_pdu_data_read(info, NULL);
		return -3;
	}

	return 0;
}

int falcon_pdu_data_read(const struct pdu_info *info, uint8_t *data)
{
	int ret = 0;
	uint32_t lsa, len=info->len, to_copy, i;
	uint8_t *ptr;
	unsigned long psa;

	if (data == NULL || info->segments == 0 || info->tlsa == FSQM_LLT_NIL ||
	    info->hlsa == FSQM_LLT_NIL || info->len == 0) {
		ret = -1;
		goto err;
	}

	ptr = data;
	lsa = info->hlsa;
	do {
		if (len > FSQM_BUFFER_SEGMENT_SIZE)
			to_copy = FSQM_BUFFER_SEGMENT_SIZE;
		else
			to_copy = len;

		psa = GPON_SBS0RAM_BASE + ONU_RAM_PACKET_BUFFER_OFFSET +
		      (lsa * FSQM_BUFFER_SEGMENT_SIZE);
#ifdef DEBUG
		if (psa >= GPON_SBS0RAM_END)
			printf("RX SSB invalid: 0x%08lX\n", psa);
#endif

		/* use uint8_t for ptr to allow unaligned buffers */
		for (i=0;i<to_copy;) {
			uint32_t val;
			val = reg_r32((void *)psa);
			*ptr++ = (val >> 24) & 0xFF;
			*ptr++ = (val >> 16) & 0xFF;
			*ptr++ = (val >>  8) & 0xFF;
			*ptr++ =  val & 0xFF;
			psa += 4;
			i += 4;
		}

		len -= to_copy;
		if (len) {
			uint32_t new_lsa;
			new_lsa = fsqm_llt_read(lsa);
#ifdef DEBUG
			if (new_lsa == FSQM_LLT_NIL) {
				printf("invalid lsa at 0x%08X\n", lsa);
				return -1;
			}
#endif
			lsa = new_lsa;
		}
	} while (len);

	if (lsa != info->tlsa)
		printf("tlsa & lsa not equal\n");

err:
	fsqm_seg_free(info->tlsa, info->hlsa, info->segments);

	return ret;
}

int falcon_pdu_write(const uint32_t len, const uint8_t *data)
{
	int ret = 0;
	uint32_t hlsa, tlsa;

	ret = ssb_write(len, data, &hlsa, &tlsa);

	if (ret == 0) {
		ret = octrll_write(len, hlsa, tlsa);
		if (ret != 0)
			fsqm_seg_free(hlsa, tlsa,
				      (len / FSQM_BUFFER_SEGMENT_SIZE) + 1);
	}

	return ret;
}
