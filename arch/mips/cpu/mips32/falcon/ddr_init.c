/*
 * (C) Copyright 2012
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

#include <common.h>

#ifndef CONFIG_SYS_NO_DDR_INIT

#include <command.h>
#include <asm/addrspace.h>
#include <asm/io.h>
#include <asm/falcon.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysctrl.h>
#include <asm/arch/ddrdb_reg.h>

typedef struct
{
	u32 reg;
	u32 res[3];
} ddrdb_t;

static ddrdb_t * const pDDRDB = (ddrdb_t *)GPON_DDRDB_BASE;

/* Register access macros */
#define ddrdb_readl(idx)	\
	reg_r32(&(pDDRDB+idx)->reg)
#define ddrdb_writel_mask(idx,clear,set)	\
	reg_w32_mask(clear, set, &(pDDRDB+idx)->reg)
#if 1
#define ddrdb_writel(idx,value)	\
	reg_w32(value, &(pDDRDB+idx)->reg)
#else
static inline void ddrdb_writel(u32 idx, u32 val)
{
	debug("%2d < 0x%08X\n", idx, val);
	writel(val, &(pDDRDB+idx)->reg);
}
#endif

/* some fixed values for Falcon */
#define DDR_CLOCK		200			/* in MHz */
#define DDR_CLK_PERIOD		(1000/DDR_CLOCK)	/* in ns */
#define DDR_CHIP_NUM		1			/* only one CS available */

/* calculation of intermediate values from settings */
#ifdef DDR_CHIP_TYPE
#if (DDR_CHIP_TYPE != 2)
#error "Only DDR2 (DDR_CHIP_TYPE=2) supported!"
#endif
#else
#error "Please define DDR_CHIP_TYPE"
#endif
#if (DDR_CHIP_CAS_LATENCY<2)
#error "Invalid/unsupported value for DDR_CHIP_CAS_LATENCY"
#endif

#define DEFAULT_LOWPOWER_POWER_DOWN_CNT		100
#define DEFAULT_LOWPOWER_SELF_REFRESH_CNT	256

#define LOWPOWER_MODE2BITS(mode)	(1<<(5-mode))

struct sdram_conf_s {
	ulong size;
	int rows;
	int banks;
};

struct sdram_conf_s sdram_conf[] = {
	{(128 << 20), 13, 8}, /* 128MByte: 1x1GBit,  13x10, 8 banks */
	{(64 << 20),  13, 4}, /* 64MByte: 1x512MBit, 13x10, 4 banks */
	{(32 << 20),  12, 4}, /* 32MByte: 1x256MBit, 12x10, 4 banks */
};

/* Return the bit position of the most significant 1 bit in a word */
static inline int ilog2(unsigned int x)
{
	extern int __builtin_clz (unsigned int x);
	return 31 - __builtin_clz(x);
}

static int ddrstatus(void);

static void ddr_init_exec(void)
{
	u32 start_time;

	/* activate memory controller */
	ddrdb_writel(7, ddrdb_readl(7) | CTL7_START);

	/* Wait for init complete status */
	debug("\nWait for init complete: ");
	start_time = get_timer(0);
	for (;;) {
		u32 ctl_22 = ddrdb_readl(22);
		if (get_timer(start_time) > 100)
			printf("\r\t( %lu: ctl_22 0x%08X, dll-lock %d)\t",
				get_timer(start_time), ctl_22, ddrdb_readl(47) & 1);
		if ((ctl_22 & 0x04000000) != 0x04000000)
			udelay(100);
		else {
			debug("Initialized (ctl_22: 0x%08X)", ctl_22);
			break;
		}
	}

	/* Wait for DLLs lock */
	debug("\nWait for DLLs lock: ");
	for (;;) {
		if ((ddrdb_readl(47) & ddrdb_readl(48) & CTL_47_DLL_LOCK) != CTL_47_DLL_LOCK) {
			udelay(1);
		}
		else {
			debug("Locked\n");
			break;
		}
	}

	/* Add delay of >200ns before any external access */
	udelay(1);

#ifdef DEBUG
	debug("DDR_GSR0: 0x%08X\n", xbar_r32(ddr_gsr0));
	//ddrstatus();
#endif
	xbar_w32_mask(XBAR_DDR_PRIO_TI_DISABLE_DMC2PAD_RX_ENABLE, 0,
		ddr_prio_ti);
}

static void setup_geometry(ulong size, int rows, int banks)
{
	int total_addr_lines;
	int ba_lines;
	int columns;
	u32 col_size;
	u32 addr_pins = 14 - rows;

	total_addr_lines = ilog2(size) - 1; /* 16bit datawidth */
	ba_lines = ilog2(banks);

	columns = total_addr_lines - rows - ba_lines;
	col_size = 12 - columns;

	debug("setup_geometry:\n\tsize: %ld\n", size);
	debug("\taddr per 16-bit: %d\n", total_addr_lines);

	debug("\tcols: %d\n", columns);
	debug("\trows: %d\n", rows);
	debug("\tbanks: %d (%d lines)\n", banks, ba_lines);

	ddrdb_writel_mask( 3,
		CTL3_EIGHT_BANK_MODE,
		(banks==8) ? CTL3_EIGHT_BANK_MODE_EIGHT_BANKS:0);

	ddrdb_writel_mask(11,
		CTL_11_COLUMN_SIZE_MASK | CTL_11_ADDR_PINS_MASK,
		(((col_size << CTL_11_COLUMN_SIZE_OFFSET) & CTL_11_COLUMN_SIZE_MASK) |
		((addr_pins << CTL_11_ADDR_PINS_OFFSET) & CTL_11_ADDR_PINS_MASK)) );

}

static void setup_ddr_params(unsigned int cl)
{
	if (cl < 2)
		cl = DDR_CHIP_CAS_LATENCY;

	/* ctl_00 */
	u32 arefresh = 0;
	u32 ap = 0;		/* auto precharge */
	u32 addr_cmp_en = 1;
	u32 active_aging = 1;

	/* ctl_01 */
	u32 concurrentap = 1;
	u32 big_endian_en = 0;
	u32 bank_split_en = 1;
	u32 auto_refresh_mode = 0;

	/* ctl_02 */
	u32 drive_dq_dqs = 1;
	u32 dqs_n_en = 1;
	u32 dll_bypass_mode = 0;

	/* ctl_03 */
	u32 intrptapburst = 0;
	u32 fast_write = 0; /* 1 not working */
	u32 enable_quick_srefresh = 1;
	u32 eight_bank_mode = 0; /* as default, will change during probing */

	/* ctl_04 */
	u32 odt_add_turn_clk_en = 1; //(DDR_CHIP_NUM>1);
	u32 no_cmd_init = 0;
	u32 intrptwritea = 0;
	u32 intrptreada = 0;

	/* ctl_05 */
	u32 priority_en = 1;
	u32 power_down = 0;	/* power-down(1) does not work */
	u32 placement_en = 1;
	u32 odt_alt_en = 0;

	/* ctl_06 */
	u32 rw_same_en = 1;
	u32 reg_dimm_enable = 0;
	u32 reduc = 1;
	u32 pwrup_srefresh_exit = 0;

	/* ctl_07 */
	u32 tras_lockout = 1;
	u32 swap_en = 1;
	u32 srefresh = 0;

	/* ctl_08 */
	u32 cs_map = (1 << DDR_CHIP_NUM)-1;
	u32 writeinterp = 1;
	u32 tref_enable = 1;

	/* ctl_09 */
	u32 odt_rd_map_cs0 = (DDR_CHIP_NUM>1) ? 2 : 0;
	/*u32 max_cs_reg = 0; Read-Only */
	u32 lowpower_refresh_enable =
		CTL9_LOWPOWER_REFRESH_ENABLE_LPREF>>CTL9_LOWPOWER_REFRESH_ENABLE_OFFSET;
	u32 dram_clk_disable = (DDR_CHIP_NUM>1) ? 0 : 2;

	/* ctl_10 */
	u32 rtt_0 = (DDR_CHIP_NUM>1) ?
		CTL_10_RTT_0_OHM_75>>CTL_10_RTT_0_OFFSET :
		CTL_10_RTT_0_OHM_150>>CTL_10_RTT_0_OFFSET;
	u32 odt_wr_map_cs1 = (DDR_CHIP_NUM>1) ? 1 : 0;
	u32 odt_wr_map_cs0 = (DDR_CHIP_NUM>1) ? 2 : 0;
	u32 odt_rd_map_cs1 = (DDR_CHIP_NUM>1) ? 1 : 0;

	/* ctl_11 */
	u32 col_size = 0;
	u32 cke_delay = 0;
	u32 cas_lat = cl;
	u32 addr_pins = 0;

	/* ctl_12 */
	u32 tdfi_dram_clk_disable = 0;
	u32 tcke = DDR_DEVICE_T_CKE;
	u32 q_fullness = 0;

	/* ctl_13 */
	u32 w2r_samecs_dly = 0;
	u32 w2r_diffcs_dly = 0;
	u32 trtp = DIV_ROUND_UP(DDR_DEVICE_T_RTP,DDR_CLK_PERIOD);
	u32 trrd = DIV_ROUND_UP(DDR_DEVICE_T_RRD,DDR_CLK_PERIOD);

	/* ctl_14 */
	u32 caslat_lin_gate = (cas_lat*2)-1;
	u32 caslat_lin = cas_lat*2;
	u32 aprebit = DDR_DEVICE_APREBIT;
	u32 age_count = 15;

	/* ctl_15 */
	/* u32 max_col_reg Read-Only */
	u32 initaref = DDR_DEVICE_INITAREF;
	u32 dram_class = ((DDR_CHIP_TYPE==2) ? CTL_15_DRAM_CLASS_DDR2 :
		CTL_15_DRAM_CLASS_DDR1) >> CTL_15_DRAM_CLASS_OFFSET;
	u32 command_age_count = 15;

	/* ctl_16 */
	u32 rdlat_adj = cas_lat;
	/* other fields Read-Only */

	/* ctl_17 */
	/*u32 tdfi_phy_wrlat Read-Only */
	u32 tdfi_phy_rdlat = cas_lat;
	u32 tdfi_dram_clk_enable = 1;
	u32 tdfi_ctrl_delay = 2;

	/* ctl_18 */
	u32 trp = DIV_ROUND_UP(DDR_DEVICE_T_RP,DDR_CLK_PERIOD);
	u32 tdfi_rddata_en_base = 2; /* ??? */
	/*u32 tdfi_rddata_en Read-Only */
	u32 tdfi_phy_wrlat_base = 2;

	/* ctl_19 */
	u32 lowpower_auto_enable = LOWPOWER_MODE2BITS(1)
				 | LOWPOWER_MODE2BITS(3)
				 | LOWPOWER_MODE2BITS(4);
	u32 wrlat_adj = cas_lat-1;
	u32 wrlat = cas_lat-1;
	u32 twtr = DIV_ROUND_UP(DDR_DEVICE_T_WTR,DDR_CLK_PERIOD);

	/* ctl_20 */
	u32 tdal = DIV_ROUND_UP(DDR_DEVICE_T_RP+DDR_DEVICE_T_WR,DDR_CLK_PERIOD);
	u32 ocd_adjust_pup_cs0 = 0;
	u32 ocd_adjust_pdn_cs0 = 7;
	u32 lowpower_control = LOWPOWER_MODE2BITS(1) | LOWPOWER_MODE2BITS(4);

	/* ctl_21 */
	u32 twr_int = DIV_ROUND_UP(DDR_DEVICE_T_WR,DDR_CLK_PERIOD);
	u32 trc = DIV_ROUND_UP(DDR_DEVICE_T_RC,DDR_CLK_PERIOD);
	u32 tmrd = DDR_DEVICE_T_MRD;
	u32 tfaw = DIV_ROUND_UP(DDR_DEVICE_T_FAW,DDR_CLK_PERIOD);

	/* ctl_23 */
	u32 tras_min = DIV_ROUND_UP(DDR_DEVICE_T_RAS_MIN,DDR_CLK_PERIOD);
	u32 tmod = DIV_ROUND_UP(DDR_DEVICE_T_MOD,DDR_CLK_PERIOD);
	u32 dll_rst_adj_dly = 0;
	/* u32 dll_lock Read-Only */

	/* ctl_24 */
	u32 trfc = DIV_ROUND_UP(DDR_DEVICE_T_RFC,DDR_CLK_PERIOD);
	u32 trcd_int = DIV_ROUND_UP(DDR_DEVICE_T_RCD,DDR_CLK_PERIOD);

	/* mode register */
	u32 mrs_burst_length_type = 2; /* bl=4: 2, bl=8: 3 */
	u32 mrs_write_recovery = 4;
	u32 mrs_powerdown = 0;
	u32 mrs = mrs_burst_length_type |
			(cas_lat << 4) |
			((mrs_write_recovery-1) << 9) |
			(mrs_powerdown << 12);

	/* extended mode register 1 */
	u32 emrs1_out_drive_strength = 0;
	u32 emrs1_rtt_mask = /* currently only 75 or 150 Ohm */
		(rtt_0 == CTL_10_RTT_0_OHM_75>>CTL_10_RTT_0_OFFSET) ? 0x04 : 0x40;
	/* AL (Additive Latency): only 0 supported */
	u32 emrs1 = (emrs1_out_drive_strength << 1) |
		emrs1_rtt_mask |
		((dqs_n_en ? 0 : 1) << 10);

	/* extended mode register 2 */
	u32 emrs2 = 0;
	/* extended mode register 3 */
	u32 emrs3 = 0;

	/* registers up to ctl_28 containing the mode registers */

	/* ctl_30 */
	u32 dll_rst_delay = 0;
	u32 tref = DIV_ROUND_UP(DDR_DEVICE_T_REF*1000,DDR_CLK_PERIOD);

	/* ctl_31 */
	u32 lowpower_external_cnt = DEFAULT_LOWPOWER_SELF_REFRESH_CNT;
	u32 lowpower_internal_cnt = DEFAULT_LOWPOWER_SELF_REFRESH_CNT;

	/* ctl_32 */
	u32 lowpower_refresh_hold = 0;
	/* number of idle cycles before memory power-down low power mode */
	u32 lowpower_power_down_cnt = DEFAULT_LOWPOWER_POWER_DOWN_CNT;

	/* ctl_33 */
	u32 tcpd = 80;
	/* number of cycles to the next memory self-refresh low power mode */
	u32 lowpower_self_refresh_cnt = DEFAULT_LOWPOWER_SELF_REFRESH_CNT;

	/* ctl_34 */
	/* DRAM TPDEX parameter in cycles */
	u32 tpdex = 2;
	/* DRAM TDLL parameter in cycles */
	u32 tdll = 200;

	/* ctl_35 */
	/* DRAM TXSNR parameter in cycles */
	u32 txsnr = 0x1C;
	/* DRAM TRAS_MAX parameter in cycles */
	u32 tras_max = 13990; /* 0x36A6 */

	/* ctl_36 */
	/* u32 version Read-Only */
	u32 txsr = 200;

	/* ctl_37 */
	u32 tinit = DIV_ROUND_UP(200*1000,DDR_CLK_PERIOD); /* 200us */

	/* ctl_38 */
	/* PHY testing mode */
	u32 dft_ctrl_reg = 0;

	/* ctl_39 - ctl_42 */
	/* DLL Bypass Control */
	u32 dll_byp_ctrl = 0;
	/* Bypass Mode DQS Delay */
	u32 dllb_dqs_del = 0x1A;
	/* Normal Mode DQS Delay */
	u32 dlln_dqs_del = 0x1C;
	/* DLL Start Point Control */
	u32 dllspc = 0x20;
	u32 dll_ctrl_reg_0_X = (dll_byp_ctrl ? CTL_39_DLL_BYP_CTRL_DLLB : 0) |
		((dllb_dqs_del << CTL_39_DLLB_DQS_DEL_OFFSET) & CTL_39_DLLB_DQS_DEL_MASK) |
		((dlln_dqs_del << CTL_39_DLLN_DQS_DEL_OFFSET) & CTL_39_DLLN_DQS_DEL_MASK) |
		((dllspc << CTL_39_DLLSPC_OFFSET) & CTL_39_DLLSPC_MASK);

	/* ctl_43 - ctl_46 */
	/* Bypass Mode CLK_WR Setting */
	u32 dllb_clk_wr = 0x55;
	/* Normal Mode CLK_WR Setting */
	u32 dlln_clk_wr = 0x5F;
	/* DLL Increment Value */
	u32 dllincval = 0x04;
	u32 dll_ctrl_reg_1_X =
		((dllb_clk_wr << CTL_43_DLLB_CLK_WR_OFFSET) & CTL_43_DLLB_CLK_WR_MASK) |
		((dlln_clk_wr << CTL_43_DLLN_CLK_WR_OFFSET) & CTL_43_DLLN_CLK_WR_MASK) |
		((dllincval << CTL_43_DLLINCVAL_OFFSET) & CTL_43_DLLINCVAL_MASK);

	/* ctl_52 */
	u32 pad_ctrl_reg_0 = CTL_52_PADIMP_PAD150 |
		((DDR_CHIP_TYPE==2) ? CTL_52_PADTYPE_PADDDR2 : 0) |
		CTL_52_IDDQ_RX_SIG_INIDDQ | CTL_52_IDDQ_TX_SIG_OUTIDDQ |
		CTL_52_IDDQ_RX_CLK_INIDDQ | CTL_52_IDDQ_TX_CLK_OUTIDDQ;

	/* ctl_53 - ctl_56 */
	/* Read Data Delay */
	u32 rdd = 3;
	/* Adjust Starting Point of DQS Output Enable Window */
	u32 dqs_start_oe = 4;
	/* Adjust Ending Point of DQS Output Enable Window */
	u32 dqs_end_oe = 3;
	/* Adjust Starting Point of DQ Output Enable Window */
	u32 dq_start_oe = 2;
	/* Adjust Ending Point of DQ Output Enable Window */
	u32 dq_end_oe = 7;
	u32 phy_ctrl_reg_0_X =
		CTL_53_ODT_DM_EN_EN | 0x40000000 | CTL_53_ODT_DM_DIS | CTL_53_EGC_CRT |
		((rdd << CTL_53_RDD_OFFSET) & CTL_53_RDD_MASK) |
		CTL_53_ENGTADJ_EN |
		((dqs_start_oe << CTL_53_DQS_START_OE_OFFSET) & CTL_53_DQS_START_OE_MASK) |
		0x00000800 |
		((dqs_end_oe << CTL_53_DQS_END_OE_OFFSET) & CTL_53_DQS_END_OE_MASK) |
		((dq_start_oe << CTL_53_DQ_START_OE_OFFSET) & CTL_53_DQ_START_OE_MASK) |
		((dq_end_oe << CTL_53_DQ_END_OE_OFFSET) & CTL_53_DQ_END_OE_MASK);

	/* ctl_57 - ctl_60 */
	/* Dynamic On-Die Termination Enable Time */
	u32 odt_ent = 0;
	/* Dynamic On-Die Termination Disable Time */
	u32 odt_dist = 7;
	/* Dynamic On-Die Termination Enable */
	u32 odt_en = 1;
	/* Dynamic On-Die Termination Polarity of TSEL */
	u32 odt_ptsel = 0;
	/* Loopback LFSR to Error Checking Logic Delay */
	u32 lpbklfsrecld = 0;
	/* Read DQS Gate Close Configuration */
	u32 dqs_gate_close_cfg = 0;
	/* Stretch Trailing Edge of DFI Read Data Enable */
	u32 strtregt = 3;
	/* Read DQS Gate Opening */
	u32 dqs_gate_open = 1;
	u32 phy_ctrl_reg_1_X =
		((odt_ent << CTL_57_ODT_ENT_OFFSET) & CTL_57_ODT_ENT_MASK) |
		((odt_dist << CTL_57_ODT_DIST_OFFSET) & CTL_57_ODT_DIST_MASK) |
		(odt_en ? CTL_57_ODT_EN_EN : 0) |
		(odt_ptsel ? CTL_57_ODT_PTSEL_POS : 0) |
		((lpbklfsrecld << CTL_57_LPBKLFSRECLD_OFFSET) & CTL_57_LPBKLFSRECLD_MASK) |
		(dqs_gate_close_cfg ? CTL_57_DQS_GATE_CLOSE_CFG : 0) |
		((strtregt << CTL_57_STRTREGT_OFFSET) & CTL_57_STRTREGT_MASK) |
		((dqs_gate_open << CTL_57_DQS_GATE_OPEN_OFFSET) & CTL_57_DQS_GATE_OPEN_MASK);

	/* ctl_61 */
	/* DFI Read Data Valid to Enable Delay */
	u32 dfirdvedly = 4;
	u32 phy_ctrl_reg_2 =
		((dfirdvedly << CTL_61_DFIRDVEDLY_OFFSET) & CTL_61_DFIRDVEDLY_MASK);


	/* write values to the registers */
	ddrdb_writel( 0,
		(arefresh ? CTL0_AREFRESH : 0) |
		(ap ? CTL0_AP : 0) |
		(addr_cmp_en ? CTL0_ADDR_CMP_EN : 0) |
		(active_aging ? CTL0_ACTIVE_AGING : 0) );

	ddrdb_writel( 1,
		(concurrentap ? CTL1_CONCURRENTAP : 0) |
		(big_endian_en ? CTL1_BIG_ENDIAN_EN : 0) |
		(bank_split_en ? CTL1_BANK_SPLIT_EN : 0) |
		(auto_refresh_mode ? CTL1_AUTO_REFRESH_MODE : 0) );

	ddrdb_writel( 2,
		(drive_dq_dqs ? CTL2_DRIVE_DQ_DQS : 0) |
		(dqs_n_en ? CTL2_DQS_N_EN : 0) |
		(dll_bypass_mode ? CTL2_DLL_BYPASS_MODE : 0) );

	ddrdb_writel( 3,
		(intrptapburst ? CTL3_INTRPTAPBURST : 0) |
		(fast_write ? CTL3_FAST_WRITE : 0) |
		(enable_quick_srefresh ? CTL3_ENABLE_QUICK_SREFRESH : 0) |
		(eight_bank_mode ? CTL3_EIGHT_BANK_MODE : 0) );

	ddrdb_writel( 4,
		(odt_add_turn_clk_en ? CTL4_ODT_ADD_TURN_CLK_EN : 0) |
		(no_cmd_init ? CTL4_NO_CMD_INIT : 0) |
		(intrptwritea ? CTL4_INTRPTWRITEA : 0) |
		(intrptreada ? CTL4_INTRPTREADA : 0) );

	ddrdb_writel( 5,
		(priority_en ? CTL5_PRIORITY_EN : 0) |
		(power_down ? CTL5_POWER_DOWN : 0) |
		(placement_en ? CTL5_PLACEMENT_EN : 0) |
		(odt_alt_en ? CTL5_ODT_ALT_EN : 0) );

	ddrdb_writel( 6,
		(rw_same_en ? CTL6_RW_SAME_EN : 0) |
		(reg_dimm_enable ? CTL6_REG_DIMM_ENABLE : 0) |
		(reduc ? CTL6_REDUC : 0) |
		(pwrup_srefresh_exit ? CTL6_PWRUP_SREFRESH_EXIT : 0) );

	ddrdb_writel( 7,
		(tras_lockout ? CTL7_TRAS_LOCKOUT : 0) |
		(swap_en ? CTL7_SWAP_EN : 0) |
		(srefresh ? CTL7_SREFRESH : 0) );

	ddrdb_writel( 8,
		(((cs_map << CTL8_CS_MAP_OFFSET) & CTL8_CS_MAP_MASK) |
		(writeinterp ? CTL8_WRITEINTERP : 0) |
		(tref_enable ? CTL8_TREF_ENABLE : 0)) );

	ddrdb_writel( 9,
		((odt_rd_map_cs0 << CTL9_ODT_RD_MAP_CS0_OFFSET) & CTL9_ODT_RD_MAP_CS0_MASK) |
		((lowpower_refresh_enable << CTL9_LOWPOWER_REFRESH_ENABLE_OFFSET) & CTL9_LOWPOWER_REFRESH_ENABLE_MASK) |
		((dram_clk_disable << CTL9_DRAM_CLK_DISABLE_OFFSET) & CTL9_DRAM_CLK_DISABLE_MASK) );

	ddrdb_writel(10,
		(((rtt_0 << CTL_10_RTT_0_OFFSET) & CTL_10_RTT_0_MASK) |
		((odt_wr_map_cs1 << CTL_10_ODT_WR_MAP_CS1_OFFSET) & CTL_10_ODT_WR_MAP_CS1_MASK) |
		((odt_wr_map_cs0 << CTL_10_ODT_WR_MAP_CS0_OFFSET) & CTL_10_ODT_WR_MAP_CS0_MASK) |
		((odt_rd_map_cs1 << CTL_10_ODT_RD_MAP_CS1_OFFSET) & CTL_10_ODT_RD_MAP_CS1_MASK)) );

	ddrdb_writel(11,
		(((col_size << CTL_11_COLUMN_SIZE_OFFSET) & CTL_11_COLUMN_SIZE_MASK) |
		((cke_delay << CTL_11_CKE_DELAY_OFFSET) & CTL_11_CKE_DELAY_MASK) |
		((cas_lat << CTL_11_CASLAT_OFFSET) & CTL_11_CASLAT_MASK) |
		((addr_pins << CTL_11_ADDR_PINS_OFFSET) & CTL_11_ADDR_PINS_MASK)) );

	ddrdb_writel(12,
		(((tdfi_dram_clk_disable << CTL_12_TDFI_DRAM_CLK_DISABLE_OFFSET) & CTL_12_TDFI_DRAM_CLK_DISABLE_MASK) |
		((tcke << CTL_12_TCKE_OFFSET) & CTL_12_TCKE_MASK) |
		((q_fullness << CTL_12_Q_FULLNESS_OFFSET) & CTL_12_Q_FULLNESS_MASK)) );

	ddrdb_writel(13,
		(((w2r_samecs_dly << CTL_13_W2R_SAMECS_DLY_OFFSET) & CTL_13_W2R_SAMECS_DLY_MASK) |
		((w2r_diffcs_dly << CTL_13_W2R_DIFFCS_DLY_OFFSET) & CTL_13_W2R_DIFFCS_DLY_MASK) |
		((trtp << CTL_13_TRTP_OFFSET) & CTL_13_TRTP_MASK) |
		((trrd << CTL_13_TRRD_OFFSET) & CTL_13_TRRD_MASK)) );

	ddrdb_writel(14,
		(((caslat_lin_gate << CTL_14_CASLAT_LIN_GATE_OFFSET) & CTL_14_CASLAT_LIN_GATE_MASK) |
		((caslat_lin << CTL_14_CASLAT_LIN_OFFSET) & CTL_14_CASLAT_LIN_MASK) |
		((aprebit << CTL_14_APREBIT_OFFSET) & CTL_14_APREBIT_MASK) |
		((age_count << CTL_14_AGE_COUNT_OFFSET) & CTL_14_AGE_COUNT_MASK)) );

	ddrdb_writel(15,
		(((initaref << CTL_15_INITAREF_OFFSET) & CTL_15_INITAREF_MASK) |
		((dram_class << CTL_15_DRAM_CLASS_OFFSET) & CTL_15_DRAM_CLASS_MASK) |
		((command_age_count << CTL_15_COMMAND_AGE_COUNT_OFFSET) & CTL_15_COMMAND_AGE_COUNT_MASK)) );

	ddrdb_writel(16,
		(rdlat_adj << CTL_16_RDLAT_ADJ_OFFSET) & CTL_16_RDLAT_ADJ_MASK);

	ddrdb_writel(17,
		(((tdfi_phy_rdlat << CTL_17_TDFI_PHY_RDLAT_OFFSET) & CTL_17_TDFI_PHY_RDLAT_MASK) |
		((tdfi_dram_clk_enable << CTL_17_TDFI_DRAM_CLK_ENABLE_OFFSET) & CTL_17_TDFI_DRAM_CLK_ENABLE_MASK) |
		((tdfi_ctrl_delay << CTL_17_TDFI_CTRL_DELAY_OFFSET) & CTL_17_TDFI_CTRL_DELAY_MASK)) );

	ddrdb_writel(18,
		(((trp << CTL_18_TRP_OFFSET) & CTL_18_TRP_MASK) |
		((tdfi_rddata_en_base << CTL_18_TDFI_RDDATA_EN_BASE_OFFSET) & CTL_18_TDFI_RDDATA_EN_BASE_MASK) |
		((tdfi_phy_wrlat_base << CTL_18_TDFI_PHY_WRLAT_BASE_OFFSET) & CTL_18_TDFI_PHY_WRLAT_BASE_MASK)) );

	ddrdb_writel(19,
		(((lowpower_auto_enable << CTL_19_LOWPOWER_AUTO_ENABLE_OFFSET) & CTL_19_LOWPOWER_AUTO_ENABLE_MASK) |
		((wrlat_adj << CTL_19_WRLAT_ADJ_OFFSET) & CTL_19_WRLAT_ADJ_MASK) |
		((wrlat << CTL_19_WRLAT_OFFSET) & CTL_19_WRLAT_MASK) |
		((twtr << CTL_19_TWTR_OFFSET) & CTL_19_TWTR_MASK)) );

	ddrdb_writel(20,
		(((tdal << CTL_20_TDAL_OFFSET) & CTL_20_TDAL_MASK) |
		((ocd_adjust_pup_cs0 << CTL_20_OCD_ADJUST_PUP_CS_0_OFFSET) & CTL_20_OCD_ADJUST_PUP_CS_0_MASK) |
		((ocd_adjust_pdn_cs0 << CTL_20_OCD_ADJUST_PDN_CS_0_OFFSET) & CTL_20_OCD_ADJUST_PDN_CS_0_MASK) |
		((lowpower_control << CTL_20_LOWPOWER_CONTROL_OFFSET) & CTL_20_LOWPOWER_CONTROL_MASK)) );

	ddrdb_writel(21,
		(((twr_int << CTL_21_TWR_INT_OFFSET) & CTL_21_TWR_INT_MASK) |
		((trc << CTL_21_TRC_OFFSET) & CTL_21_TRC_MASK) |
		((tmrd << CTL_21_TMRD_OFFSET) & CTL_21_TMRD_MASK) |
		((tfaw << CTL_21_TFAW_OFFSET) & CTL_21_TFAW_MASK)) );

	ddrdb_writel(22, CTL_22_INT_ACK_MASK); /* reset status (int_mask and int_ack) */

	ddrdb_writel(23,
		(((tras_min <<CTL_23_TRAS_MIN_OFFSET) & CTL_23_TRAS_MIN_MASK) |
		((tmod << CTL_23_TMOD_OFFSET) & CTL_23_TMOD_MASK) |
		((dll_rst_adj_dly << CTL_23_DLL_RST_ADJ_DLY_OFFSET) & CTL_23_DLL_RST_ADJ_DLY_MASK)) );

	ddrdb_writel(24,
		(((emrs1 << CTL_24_EMRS1_DATA_0_OFFSET) & CTL_24_EMRS1_DATA_0_MASK) |
		((trfc << CTL_24_TRFC_OFFSET) & CTL_24_TRFC_MASK) |
		((trcd_int << CTL_24_TRCD_INT_OFFSET) & CTL_24_TRCD_INT_MASK)) );
	ddrdb_writel(25,
		(((emrs2 << CTL_25_EMRS2_DATA_0_OFFSET) & CTL_25_EMRS2_DATA_0_MASK) |
		((emrs1 << CTL_25_EMRS1_DATA_1_OFFSET) & CTL_25_EMRS1_DATA_1_MASK)) );
	ddrdb_writel(26,
		(((emrs3 << CTL_26_EMRS3_DATA_0_OFFSET) & CTL_26_EMRS3_DATA_0_MASK) |
		((emrs2 << CTL_26_EMRS2_DATA_1_OFFSET) & CTL_26_EMRS2_DATA_1_MASK)) );
	ddrdb_writel(27,
		(((mrs << CTL_27_MRS_DATA_0_OFFSET) & CTL_27_MRS_DATA_0_MASK) |
		((emrs3 << CTL_27_EMRS3_DATA_1_OFFSET) & CTL_27_EMRS3_DATA_1_MASK)) );
	ddrdb_writel(28,
		((mrs << CTL_28_MRS_DATA_1_OFFSET) & CTL_28_MRS_DATA_1_MASK) );

	/* readonly register: CTL_29 */

	ddrdb_writel(30,
		(((dll_rst_delay << CTL_30_DLL_RST_DELAY_OFFSET) & CTL_30_DLL_RST_DELAY_MASK) |
		((tref << CTL_30_TREF_OFFSET) & CTL_30_TREF_MASK)) );
	ddrdb_writel(31,
		(((lowpower_internal_cnt << CTL_31_LOWPOWER_INTERNAL_CNT_OFFSET) & CTL_31_LOWPOWER_INTERNAL_CNT_MASK) |
		((lowpower_external_cnt << CTL_31_LOWPOWER_EXTERNAL_CNT_OFFSET) & CTL_31_LOWPOWER_EXTERNAL_CNT_MASK)) );
	ddrdb_writel(32,
		(((lowpower_refresh_hold << CTL_32_LOWPOWER_REFRESH_HOLD_OFFSET) & CTL_32_LOWPOWER_REFRESH_HOLD_MASK) |
		((lowpower_power_down_cnt << CTL_32_LOWPOWER_POWER_DOWN_CNT_OFFSET) & CTL_32_LOWPOWER_POWER_DOWN_CNT_MASK)) );
	ddrdb_writel(33,
		(((tcpd << CTL_33_TCPD_OFFSET) & CTL_33_TCPD_MASK) |
		((lowpower_self_refresh_cnt << CTL_33_LOWPOWER_SELF_REFRESH_CNT_OFFSET) & CTL_33_LOWPOWER_SELF_REFRESH_CNT_MASK)) );
	ddrdb_writel(34,
		(((tpdex << CTL_34_TPDEX_OFFSET) & CTL_34_TPDEX_MASK) |
		((tdll << CTL_34_TDLL_OFFSET) & CTL_34_TDLL_MASK)) );
	ddrdb_writel(35,
		(((txsnr << CTL_35_TXSNR_OFFSET) & CTL_35_TXSNR_MASK) |
		((tras_max << CTL_35_TRAS_MAX_OFFSET) & CTL_35_TRAS_MAX_MASK)) );
	ddrdb_writel(36,
		((txsr << CTL_36_TXSR_OFFSET) & CTL_36_TXSR_MASK) );

	ddrdb_writel(37, tinit);
	ddrdb_writel(38, dft_ctrl_reg);
	ddrdb_writel(39, dll_ctrl_reg_0_X);

	ddrdb_writel(40, dll_ctrl_reg_0_X);
	ddrdb_writel(41, dll_ctrl_reg_0_X);
	ddrdb_writel(42, dll_ctrl_reg_0_X);
	ddrdb_writel(43, dll_ctrl_reg_1_X);
	ddrdb_writel(44, dll_ctrl_reg_1_X);
	ddrdb_writel(45, dll_ctrl_reg_1_X);
	ddrdb_writel(46, dll_ctrl_reg_1_X);

	/* readonly registers: CTL_47 - CTL_51 */

	ddrdb_writel(52, pad_ctrl_reg_0);
	ddrdb_writel(53, phy_ctrl_reg_0_X);
	ddrdb_writel(54, phy_ctrl_reg_0_X);
	ddrdb_writel(55, phy_ctrl_reg_0_X);
	ddrdb_writel(56, phy_ctrl_reg_0_X);
	ddrdb_writel(57, phy_ctrl_reg_1_X);
	ddrdb_writel(58, phy_ctrl_reg_1_X);
	ddrdb_writel(59, phy_ctrl_reg_1_X);
	ddrdb_writel(60, phy_ctrl_reg_1_X);

	ddrdb_writel(61, phy_ctrl_reg_2);

	/* readonly registers: CTL_62 and up */
}

phys_size_t falcon_ddr_init(void)
{
	u32 version;
	phys_size_t size;
	int n;

	falcon_dcdc_ddr_init(1800);

	/* need long delay after dcdc setup
	   FIXME: check DCDC status?
	*/
	udelay(100000);
	sys1_hw_activate_or_reboot(RBT_DDR);

	version = ((ddrdb_readl(36) & CTL_36_VERSION_MASK) >>CTL_36_VERSION_OFFSET);
	if (version != 0x2042) {
		printf("ERROR: Unknown Denali-Controller version (0x%04X)\n", version);
		return -1;
	}

	/* deactivate memory controller */
	ddrdb_writel(7, 0);

	setup_ddr_params(0);
	ddr_init_exec();

	/* go through supported memory configurations */
	for (n = 0; n < ARRAY_SIZE(sdram_conf); n++) {
		setup_geometry(sdram_conf[n].size, sdram_conf[n].rows,
			sdram_conf[n].banks);

		size = get_ram_size((long *)KSEG1ADDR(CONFIG_SYS_DDR_BASE), 
				CONFIG_SYS_MAX_RAM);
#ifdef DEBUG
		puts("expected size:");
		print_size (sdram_conf[n].size, "\n");

		puts("found size:");
		print_size (size, "\n");
#endif
		if (sdram_conf[n].size == size)
			return size;
	}
	return 0;
}

static int ddrstatus(void)
{
	u32 reg, i;

	puts("DDR Status:\n");

	reg = ddrdb_readl(22);
	ddrdb_writel(22, CTL_22_INT_ACK_MASK); /* reset status (int_mask and int_ack) */
	if (reg & (0x40 << CTL_22_INT_STATUS_OFFSET)) {
		puts("Interrupts:\n");
		if (reg & (0x01 << CTL_22_INT_STATUS_OFFSET))
			puts(" single access outside mem space\n");
		if (reg & (0x02 << CTL_22_INT_STATUS_OFFSET))
			puts(" multiple accesses outside mem space\n");
		if (reg & (0x04 << CTL_22_INT_STATUS_OFFSET))
			puts(" init complete\n");
		if (reg & (0x08 << CTL_22_INT_STATUS_OFFSET))
			puts(" CL3 with ODT detected (not supported!)\n");
		if (reg & (0x10 << CTL_22_INT_STATUS_OFFSET))
			puts(" read DQS gate error\n");
		if (reg & (0x20 << CTL_22_INT_STATUS_OFFSET))
			puts(" DLL unlock condition detected\n");
	}

#ifdef DEBUG
#define MAX_SLICE	4
#else
#define MAX_SLICE	2
#endif
	for (i=0; i<MAX_SLICE; i++) {
		reg = ddrdb_readl(47+i);
		printf("Slice%d: DLL %slocked\n", i, (reg & 1) ? "" : "not ");
	}

	for (i=1; i<=5; i++) {
		if (((ddrdb_readl(20) & CTL_20_LOWPOWER_CONTROL_MASK)
		    >> CTL_20_LOWPOWER_CONTROL_OFFSET) & LOWPOWER_MODE2BITS(i)) {
			reg = 0;
			switch(i) {
			case 1:
			case 2:
				reg = ((ddrdb_readl(32) & CTL_32_LOWPOWER_POWER_DOWN_CNT_MASK)
					>> CTL_32_LOWPOWER_POWER_DOWN_CNT_OFFSET);
				break;
			case 3:
				reg = ((ddrdb_readl(33) & CTL_33_LOWPOWER_SELF_REFRESH_CNT_MASK)
					>> CTL_33_LOWPOWER_SELF_REFRESH_CNT_OFFSET);
				break;
			case 4:
				reg = ((ddrdb_readl(31) & CTL_31_LOWPOWER_EXTERNAL_CNT_MASK)
					>> CTL_31_LOWPOWER_EXTERNAL_CNT_OFFSET);
				break;
			}
			printf("LowPower Mode %d active, enabled after %d clocks idle\n",
				i, reg);
		}
	}
	return 0;
}


static int do_ddrstatus( cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	ddrstatus();
	return 0;
}

U_BOOT_CMD(
	ddrstatus,	1,	0,	do_ddrstatus,
	"show DDR Controller status",
	""
);

static int do_ddrlp( cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	u32 mode, count, control_mask, lowpower_auto_enable;

	/* need at least one arguments */
	if (argc < 2)
		goto usage;

	mode = simple_strtoul(argv[1], NULL, 10);
	control_mask = (1<<(5-mode));
	lowpower_auto_enable = (ddrdb_readl(19) & CTL_19_LOWPOWER_AUTO_ENABLE_MASK)
				>> CTL_19_LOWPOWER_AUTO_ENABLE_OFFSET;
	if ((lowpower_auto_enable & control_mask) == 0)
		goto usage;

	if (argc > 2)
		count = simple_strtoul(argv[2], NULL, 10);
	else {
		switch (mode) {
		case 1:
			count = DEFAULT_LOWPOWER_POWER_DOWN_CNT;
			break;
		case 3:
		case 4:
		default:
			count = DEFAULT_LOWPOWER_SELF_REFRESH_CNT;
			break;
		}
	}

	if (count) {
		switch (mode) {
		case 1:
			ddrdb_writel_mask(32,
				CTL_32_LOWPOWER_POWER_DOWN_CNT_MASK,
				((count << CTL_32_LOWPOWER_POWER_DOWN_CNT_OFFSET)
					& CTL_32_LOWPOWER_POWER_DOWN_CNT_MASK));
			break;
		case 3:
			ddrdb_writel_mask(33,
				CTL_33_LOWPOWER_SELF_REFRESH_CNT_MASK,
				((count << CTL_33_LOWPOWER_SELF_REFRESH_CNT_OFFSET)
					& CTL_33_LOWPOWER_SELF_REFRESH_CNT_MASK));
			break;
		case 4:
			ddrdb_writel_mask(31,
				CTL_31_LOWPOWER_EXTERNAL_CNT_MASK,
				((count << CTL_31_LOWPOWER_EXTERNAL_CNT_OFFSET)
					& CTL_31_LOWPOWER_EXTERNAL_CNT_MASK));
			break;
		default:
			break;
		}
		ddrdb_writel_mask(20, 0,
			control_mask<<CTL_20_LOWPOWER_CONTROL_OFFSET);
	} else {
		ddrdb_writel_mask(20,
			control_mask<<CTL_20_LOWPOWER_CONTROL_OFFSET, 0);
	}
	return 0;

usage:
	return cmd_usage(cmdtp);
}

U_BOOT_CMD(
	ddrlp,	3,	0,	do_ddrlp,
	"config DDR LowPower",
	"mode [count]\n"
	"    mode = LowPower Mode (1 or 3)\n"
	"    count = ticks from idle (count is decimal!!!)\n"
	"            nothing for default value or 0 to switch mode off\n"
);


#if defined(DEBUG)
static int do_ddrdump( cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	u32 i, start=0, end=61;

	if (argc > 1) {
		start = simple_strtoul(argv[1], NULL, 10);
		end = start;
	}

	if (argc > 2)
		end = simple_strtoul(argv[2], NULL, 10);

	puts("DDR Register Dump:\n");
	for (i=start; i<=end; i++) {
#ifdef CONFIG_EMULATION
		printf("CTL_%02d = 0x%08X\n", i, ddrdb_readl(i));
#else
		printf("CTL_%02d (@%08X) = 0x%08X\n",
			i, (u32)(&(pDDRDB+i)->reg), ddrdb_readl(i));
#endif
	}
	return 0;
}

U_BOOT_CMD(
	ddrdump,	3,	0,	do_ddrdump,
	"dump DDR Controller registers",
	"[start [end]]\n"
);
#endif

#endif /* CONFIG_SYS_NO_DDR_INIT */
