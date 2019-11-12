/******************************************************************************

                               Copyright (c) 2012
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _ddrdb_reg_h
#define _ddrdb_reg_h

/** \addtogroup DDRDB_REGISTER
   @{
*/
/* access macros */
#define ddrdb_r32(reg) reg_r32(&ddrdb->reg)
#define ddrdb_w32(val, reg) reg_w32(val, &ddrdb->reg)
#define ddrdb_w32_mask(clear, set, reg) reg_w32_mask(clear, set, &ddrdb->reg)
#define ddrdb_r32_table(reg, idx) reg_r32_table(ddrdb->reg, idx)
#define ddrdb_w32_table(val, reg, idx) reg_w32_table(val, ddrdb->reg, idx)
#define ddrdb_w32_table_mask(clear, set, reg, idx) reg_w32_table_mask(clear, set, ddrdb->reg, idx)
#define ddrdb_adr_table(reg, idx) adr_table(ddrdb->reg, idx)


/** DDRDB register structure */
struct gpon_reg_ddrdb
{
   /** Denali CTL_00 register */
   unsigned int ctl0[4]; /* 0x00000000 */
   /** Denali CTL_01 register */
   unsigned int ctl1[4]; /* 0x00000010 */
   /** Denali CTL_02 register */
   unsigned int ctl2[4]; /* 0x00000020 */
   /** Denali CTL_03 register */
   unsigned int ctl3[4]; /* 0x00000030 */
   /** Denali CTL_04 register */
   unsigned int ctl4[4]; /* 0x00000040 */
   /** Denali CTL_05 register */
   unsigned int ctl5[4]; /* 0x00000050 */
   /** Denali CTL_06 register */
   unsigned int ctl6[4]; /* 0x00000060 */
   /** Denali CTL_07 register */
   unsigned int ctl7[4]; /* 0x00000070 */
   /** Denali CTL_08 register */
   unsigned int ctl8[4]; /* 0x00000080 */
   /** Denali CTL_09 register */
   unsigned int ctl9[4]; /* 0x00000090 */
   /** Denali CTL_10 register */
   unsigned int ctl_10; /* 0x000000A0 */
   /** Reserved */
   unsigned int res_10[3]; /* 0x000000A4 */
   /** Denali CTL_11 register */
   unsigned int ctl_11; /* 0x000000B0 */
   /** Reserved */
   unsigned int res_11[3]; /* 0x000000B4 */
   /** Denali CTL_12 register */
   unsigned int ctl_12; /* 0x000000C0 */
   /** Reserved */
   unsigned int res_12[3]; /* 0x000000C4 */
   /** Denali CTL_13 register */
   unsigned int ctl_13; /* 0x000000D0 */
   /** Reserved */
   unsigned int res_13[3]; /* 0x000000D4 */
   /** Denali CTL_14 register */
   unsigned int ctl_14; /* 0x000000E0 */
   /** Reserved */
   unsigned int res_14[3]; /* 0x000000E4 */
   /** Denali CTL_15 register */
   unsigned int ctl_15; /* 0x000000F0 */
   /** Reserved */
   unsigned int res_15[3]; /* 0x000000F4 */
   /** Denali CTL_16 register */
   unsigned int ctl_16; /* 0x00000100 */
   /** Reserved */
   unsigned int res_16[3]; /* 0x00000104 */
   /** Denali CTL_17 register */
   unsigned int ctl_17; /* 0x00000110 */
   /** Reserved */
   unsigned int res_17[3]; /* 0x00000114 */
   /** Denali CTL_18 register */
   unsigned int ctl_18; /* 0x00000120 */
   /** Reserved */
   unsigned int res_18[3]; /* 0x00000124 */
   /** Denali CTL_19 register */
   unsigned int ctl_19; /* 0x00000130 */
   /** Reserved */
   unsigned int res_19[3]; /* 0x00000134 */
   /** Denali CTL_20 register */
   unsigned int ctl_20; /* 0x00000140 */
   /** Reserved */
   unsigned int res_20[3]; /* 0x00000144 */
   /** Denali CTL_21 register */
   unsigned int ctl_21; /* 0x00000150 */
   /** Reserved */
   unsigned int res_21[3]; /* 0x00000154 */
   /** Denali CTL_22 register */
   unsigned int ctl_22; /* 0x00000160 */
   /** Reserved */
   unsigned int res_22[3]; /* 0x00000164 */
   /** Denali CTL_23 register */
   unsigned int ctl_23; /* 0x00000170 */
   /** Reserved */
   unsigned int res_23[3]; /* 0x00000174 */
   /** Denali CTL_24 register */
   unsigned int ctl_24; /* 0x00000180 */
   /** Reserved */
   unsigned int res_24[3]; /* 0x00000184 */
   /** Denali CTL_25 register */
   unsigned int ctl_25; /* 0x00000190 */
   /** Reserved */
   unsigned int res_25[3]; /* 0x00000194 */
   /** Denali CTL_26 register */
   unsigned int ctl_26; /* 0x000001A0 */
   /** Reserved */
   unsigned int res_26[3]; /* 0x000001A4 */
   /** Denali CTL_27 register */
   unsigned int ctl_27; /* 0x000001B0 */
   /** Reserved */
   unsigned int res_27[3]; /* 0x000001B4 */
   /** Denali CTL_28 register */
   unsigned int ctl_28; /* 0x000001C0 */
   /** Reserved */
   unsigned int res_28[3]; /* 0x000001C4 */
   /** Denali CTL_29 register */
   unsigned int ctl_29; /* 0x000001D0 */
   /** Reserved */
   unsigned int res_29[3]; /* 0x000001D4 */
   /** Denali CTL_30 register */
   unsigned int ctl_30; /* 0x000001E0 */
   /** Reserved */
   unsigned int res_30[3]; /* 0x000001E4 */
   /** Denali CTL_31 register */
   unsigned int ctl_31; /* 0x000001F0 */
   /** Reserved */
   unsigned int res_31[3]; /* 0x000001F4 */
   /** Denali CTL_32 register */
   unsigned int ctl_32; /* 0x00000200 */
   /** Reserved */
   unsigned int res_32[3]; /* 0x00000204 */
   /** Denali CTL_33 register */
   unsigned int ctl_33; /* 0x00000210 */
   /** Reserved */
   unsigned int res_33[3]; /* 0x00000214 */
   /** Denali CTL_34 register */
   unsigned int ctl_34; /* 0x00000220 */
   /** Reserved */
   unsigned int res_34[3]; /* 0x00000224 */
   /** Denali CTL_35 register */
   unsigned int ctl_35; /* 0x00000230 */
   /** Reserved */
   unsigned int res_35[3]; /* 0x00000234 */
   /** Denali CTL_36 register */
   unsigned int ctl_36; /* 0x00000240 */
   /** Reserved */
   unsigned int res_36[3]; /* 0x00000244 */
   /** Denali CTL_37 register */
   unsigned int ctl_37; /* 0x00000250 */
   /** Reserved */
   unsigned int res_37[3]; /* 0x00000254 */
   /** Denali CTL_38 register */
   unsigned int ctl_38; /* 0x00000260 */
   /** Reserved */
   unsigned int res_38[3]; /* 0x00000264 */
   /** Denali CTL_39 register
       Controls the DLL bypass logic, DLL start point and holds the read DQS delay settings for data slice 0. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_0_X. */
   unsigned int ctl_39; /* 0x00000270 */
   /** Reserved */
   unsigned int res_39[3]; /* 0x00000274 */
   /** Denali CTL_40 register
       Controls the DLL bypass logic, DLL start point and holds the read DQS delay settings for data slice 1. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_0_X. */
   unsigned int ctl_40; /* 0x00000280 */
   /** Reserved */
   unsigned int res_40[3]; /* 0x00000284 */
   /** Denali CTL_41 register
       Controls the DLL bypass logic, DLL start point and holds the read DQS delay settings for data slice 2. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_0_X. */
   unsigned int ctl_41; /* 0x00000290 */
   /** Reserved */
   unsigned int res_41[3]; /* 0x00000294 */
   /** Denali CTL_42 register
       Controls the DLL bypass logic, DLL start point and holds the read DQS delay settings for data slice 3. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_0_X. */
   unsigned int ctl_42; /* 0x000002A0 */
   /** Reserved */
   unsigned int res_42[3]; /* 0x000002A4 */
   /** Denali CTL_43 register
       Holds the clk_wr settings and the DLL increment value for data slice 0. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_1_X. */
   unsigned int ctl_43; /* 0x000002B0 */
   /** Reserved */
   unsigned int res_43[3]; /* 0x000002B4 */
   /** Denali CTL_44 register
       Holds the clk_wr settings and the DLL increment value for data slice 1. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_1_X. */
   unsigned int ctl_44; /* 0x000002C0 */
   /** Reserved */
   unsigned int res_44[3]; /* 0x000002C4 */
   /** Denali CTL_45 register
       Holds the clk_wr settings and the DLL increment value for data slice 2. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_1_X. */
   unsigned int ctl_45; /* 0x000002D0 */
   /** Reserved */
   unsigned int res_45[3]; /* 0x000002D4 */
   /** Denali CTL_46 register
       Holds the clk_wr settings and the DLL increment value for data slice 3. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_ctrl_reg_1_X. */
   unsigned int ctl_46; /* 0x000002E0 */
   /** Reserved */
   unsigned int res_46[3]; /* 0x000002E4 */
   /** Denali CTL_47 register
       Reports the lock status and the encoder value for data slice 0. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_obs_reg_0_X. */
   unsigned int ctl_47; /* 0x000002F0 */
   /** Reserved */
   unsigned int res_47[3]; /* 0x000002F4 */
   /** Denali CTL_48 register
       Reports the lock status and the encoder value for data slice 1. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_obs_reg_0_X. */
   unsigned int ctl_48; /* 0x00000300 */
   /** Reserved */
   unsigned int res_48[3]; /* 0x00000304 */
   /** Denali CTL_49 register
       Reports the lock status and the encoder value for data slice 2. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_obs_reg_0_X. */
   unsigned int ctl_49; /* 0x00000310 */
   /** Reserved */
   unsigned int res_49[3]; /* 0x00000314 */
   /** Denali CTL_50 register
       Reports the lock status and the encoder value for data slice 3. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = dll_obs_reg_0_X. */
   unsigned int ctl_50; /* 0x00000320 */
   /** Reserved */
   unsigned int res_50[3]; /* 0x00000324 */
   /** Denali CTL_51 register */
   unsigned int ctl_51; /* 0x00000330 */
   /** Reserved */
   unsigned int res_51[3]; /* 0x00000334 */
   /** Denali CTL_52 register
       These bit settings are specific to the pad models included with this PHY. The user should alter the programming relative to the particular pads being used in their design. Note: Denali provides a dynamic termination signal tsel that provides one bit per byte of memory data. The user must attach this signal to the pads dependent on pad requirements. Denali has not connected this signal to the pad model. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = pad_ctrl_reg_0. */
   unsigned int ctl_52; /* 0x00000340 */
   /** Reserved */
   unsigned int res_52[3]; /* 0x00000344 */
   /** Denali CTL_53 register
       Controls pad output enable times and other PHY parameters for data slice 0. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_0_X. */
   unsigned int ctl_53; /* 0x00000350 */
   /** Reserved */
   unsigned int res_53[3]; /* 0x00000354 */
   /** Denali CTL_54 register
       Controls pad output enable times and other PHY parameters for data slice 1. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_0_X. */
   unsigned int ctl_54; /* 0x00000360 */
   /** Reserved */
   unsigned int res_54[3]; /* 0x00000364 */
   /** Denali CTL_55 register
       Controls pad output enable times and other PHY parameters for data slice 2. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_0_X. */
   unsigned int ctl_55; /* 0x00000370 */
   /** Reserved */
   unsigned int res_55[3]; /* 0x00000374 */
   /** Denali CTL_56 register
       Controls pad output enable times and other PHY parameters for data slice 3. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_0_X. */
   unsigned int ctl_56; /* 0x00000380 */
   /** Reserved */
   unsigned int res_56[3]; /* 0x00000384 */
   /** Denali CTL_57 register
       Controls pad termination and loopback for data slice 0. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_1_X. */
   unsigned int ctl_57; /* 0x00000390 */
   /** Reserved */
   unsigned int res_57[3]; /* 0x00000394 */
   /** Denali CTL_58 register
       Controls pad termination and loopback for data slice 1. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_1_X. */
   unsigned int ctl_58; /* 0x000003A0 */
   /** Reserved */
   unsigned int res_58[3]; /* 0x000003A4 */
   /** Denali CTL_59 register
       Controls pad termination and loopback for data slice 2. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_1_X. */
   unsigned int ctl_59; /* 0x000003B0 */
   /** Reserved */
   unsigned int res_59[3]; /* 0x000003B4 */
   /** Denali CTL_60 register
       Controls pad termination and loopback for data slice 3. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_1_X. */
   unsigned int ctl_60; /* 0x000003C0 */
   /** Reserved */
   unsigned int res_60[3]; /* 0x000003C4 */
   /** Denali CTL_61 register
       Selects normal or low latency PHY paths and the dfi_rddata_valid delay Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_ctrl_reg_2. */
   unsigned int ctl_61; /* 0x000003D0 */
   /** Reserved */
   unsigned int res_61[3]; /* 0x000003D4 */
   /** Denali CTL_62 register
       Controls loopback status, data and masking info for data slic 0. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_obs_reg_0_X. */
   unsigned int ctl_62; /* 0x000003E0 */
   /** Reserved */
   unsigned int res_62[3]; /* 0x000003E4 */
   /** Denali CTL_63 register
       Controls loopback status, data and masking info for data slic 1. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_obs_reg_0_X. */
   unsigned int ctl_63; /* 0x000003F0 */
   /** Reserved */
   unsigned int res_63[3]; /* 0x000003F4 */
   /** Denali CTL_64 register
       Controls loopback status, data and masking info for data slic 2. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_obs_reg_0_X. */
   unsigned int ctl_64; /* 0x00000400 */
   /** Reserved */
   unsigned int res_64[3]; /* 0x00000404 */
   /** Denali CTL_65 register
       Controls loopback status, data and masking info for data slic 3. There is a separate register for each of the slices of data sent on the DFI data bus. Note: The DENALI docu regarding this register is somehow inconsistent with the majority of other registers as the fields of this register are not specified as individual fields, but as one large field consisting of a table of bit-slices. When looking up the corresponding register documentation of the DENALI documents please refer to: DENALI-original-field-name = phy_obs_reg_0_X. */
   unsigned int ctl_65; /* 0x00000410 */
   /** Reserved */
   unsigned int res_65[3]; /* 0x00000414 */
   /** Denali CTL_66 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_66; /* 0x00000420 */
   /** Reserved */
   unsigned int res_66[3]; /* 0x00000424 */
   /** Denali CTL_67 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_67; /* 0x00000430 */
   /** Reserved */
   unsigned int res_67[3]; /* 0x00000434 */
   /** Denali CTL_68 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_68; /* 0x00000440 */
   /** Reserved */
   unsigned int res_68[3]; /* 0x00000444 */
   /** Denali CTL_69 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_69; /* 0x00000450 */
   /** Reserved */
   unsigned int res_69[3]; /* 0x00000454 */
   /** Denali CTL_70 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_70; /* 0x00000460 */
   /** Reserved */
   unsigned int res_70[3]; /* 0x00000464 */
   /** Denali CTL_71 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_71; /* 0x00000470 */
   /** Reserved */
   unsigned int res_71[3]; /* 0x00000474 */
   /** Denali CTL_72 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_72; /* 0x00000480 */
   /** Reserved */
   unsigned int res_72[3]; /* 0x00000484 */
   /** Denali CTL_73 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_73; /* 0x00000490 */
   /** Reserved */
   unsigned int res_73[3]; /* 0x00000494 */
   /** Denali CTL_74 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_74; /* 0x000004A0 */
   /** Reserved */
   unsigned int res_74[3]; /* 0x000004A4 */
   /** Denali CTL_75 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_75; /* 0x000004B0 */
   /** Reserved */
   unsigned int res_75[3]; /* 0x000004B4 */
   /** Denali CTL_76 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_76; /* 0x000004C0 */
   /** Reserved */
   unsigned int res_76[3]; /* 0x000004C4 */
   /** Denali CTL_77 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_77; /* 0x000004D0 */
   /** Reserved */
   unsigned int res_77[3]; /* 0x000004D4 */
   /** Denali CTL_78 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_78; /* 0x000004E0 */
   /** Reserved */
   unsigned int res_78[3]; /* 0x000004E4 */
   /** Denali CTL_79 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_79; /* 0x000004F0 */
   /** Reserved */
   unsigned int res_79[3]; /* 0x000004F4 */
   /** Denali CTL_80 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_80; /* 0x00000500 */
   /** Reserved */
   unsigned int res_80[3]; /* 0x00000504 */
   /** Denali CTL_81 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_81; /* 0x00000510 */
   /** Reserved */
   unsigned int res_81[3]; /* 0x00000514 */
   /** Denali CTL_82 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_82; /* 0x00000520 */
   /** Reserved */
   unsigned int res_82[3]; /* 0x00000524 */
   /** Denali CTL_83 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_83; /* 0x00000530 */
   /** Reserved */
   unsigned int res_83[3]; /* 0x00000534 */
   /** Denali CTL_84 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_84; /* 0x00000540 */
   /** Reserved */
   unsigned int res_84[3]; /* 0x00000544 */
   /** Denali CTL_85 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_85; /* 0x00000550 */
   /** Reserved */
   unsigned int res_85[3]; /* 0x00000554 */
   /** Denali CTL_86 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_86; /* 0x00000560 */
   /** Reserved */
   unsigned int res_86[3]; /* 0x00000564 */
   /** Denali CTL_87 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_87; /* 0x00000570 */
   /** Reserved */
   unsigned int res_87[3]; /* 0x00000574 */
   /** Denali CTL_88 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_88; /* 0x00000580 */
   /** Reserved */
   unsigned int res_88[3]; /* 0x00000584 */
   /** Denali CTL_89 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_89; /* 0x00000590 */
   /** Reserved */
   unsigned int res_89[3]; /* 0x00000594 */
   /** Denali CTL_90 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_90; /* 0x000005A0 */
   /** Reserved */
   unsigned int res_90[3]; /* 0x000005A4 */
   /** Denali CTL_91 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_91; /* 0x000005B0 */
   /** Reserved */
   unsigned int res_91[3]; /* 0x000005B4 */
   /** Denali CTL_92 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_92; /* 0x000005C0 */
   /** Reserved */
   unsigned int res_92[3]; /* 0x000005C4 */
   /** Denali CTL_93 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_93; /* 0x000005D0 */
   /** Reserved */
   unsigned int res_93[3]; /* 0x000005D4 */
   /** Denali CTL_94 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_94; /* 0x000005E0 */
   /** Reserved */
   unsigned int res_94[3]; /* 0x000005E4 */
   /** Denali CTL_95 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_95; /* 0x000005F0 */
   /** Reserved */
   unsigned int res_95[3]; /* 0x000005F4 */
   /** Denali CTL_96 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_96; /* 0x00000600 */
   /** Reserved */
   unsigned int res_96[3]; /* 0x00000604 */
   /** Denali CTL_97 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_97; /* 0x00000610 */
   /** Reserved */
   unsigned int res_97[3]; /* 0x00000614 */
   /** Denali CTL_98 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_98; /* 0x00000620 */
   /** Reserved */
   unsigned int res_98[3]; /* 0x00000624 */
   /** Denali CTL_99 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_99; /* 0x00000630 */
   /** Reserved */
   unsigned int res_99[3]; /* 0x00000634 */
   /** Denali CTL_100 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_100; /* 0x00000640 */
   /** Reserved */
   unsigned int res_100[3]; /* 0x00000644 */
   /** Denali CTL_101 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_101; /* 0x00000650 */
   /** Reserved */
   unsigned int res_101[3]; /* 0x00000654 */
   /** Denali CTL_102 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_102; /* 0x00000660 */
   /** Reserved */
   unsigned int res_102[3]; /* 0x00000664 */
   /** Denali CTL_103 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_103; /* 0x00000670 */
   /** Reserved */
   unsigned int res_103[3]; /* 0x00000674 */
   /** Denali CTL_104 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_104; /* 0x00000680 */
   /** Reserved */
   unsigned int res_104[3]; /* 0x00000684 */
   /** Denali CTL_105 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_105; /* 0x00000690 */
   /** Reserved */
   unsigned int res_105[3]; /* 0x00000694 */
   /** Denali CTL_106 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_106; /* 0x000006A0 */
   /** Reserved */
   unsigned int res_106[3]; /* 0x000006A4 */
   /** Denali CTL_107 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_107; /* 0x000006B0 */
   /** Reserved */
   unsigned int res_107[3]; /* 0x000006B4 */
   /** Denali CTL_108 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_108; /* 0x000006C0 */
   /** Reserved */
   unsigned int res_108[3]; /* 0x000006C4 */
   /** Denali CTL_109 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_109; /* 0x000006D0 */
   /** Reserved */
   unsigned int res_109[3]; /* 0x000006D4 */
   /** Denali CTL_110 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_110; /* 0x000006E0 */
   /** Reserved */
   unsigned int res_110[3]; /* 0x000006E4 */
   /** Denali CTL_111 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_111; /* 0x000006F0 */
   /** Reserved */
   unsigned int res_111[3]; /* 0x000006F4 */
   /** Denali CTL_112 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_112; /* 0x00000700 */
   /** Reserved */
   unsigned int res_112[3]; /* 0x00000704 */
   /** Denali CTL_113 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_113; /* 0x00000710 */
   /** Reserved */
   unsigned int res_113[3]; /* 0x00000714 */
   /** Denali CTL_114 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_114; /* 0x00000720 */
   /** Reserved */
   unsigned int res_114[3]; /* 0x00000724 */
   /** Denali CTL_115 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_115; /* 0x00000730 */
   /** Reserved */
   unsigned int res_115[3]; /* 0x00000734 */
   /** Denali CTL_116 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_116; /* 0x00000740 */
   /** Reserved */
   unsigned int res_116[3]; /* 0x00000744 */
   /** Denali CTL_117 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_117; /* 0x00000750 */
   /** Reserved */
   unsigned int res_117[3]; /* 0x00000754 */
   /** Denali CTL_118 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_118; /* 0x00000760 */
   /** Reserved */
   unsigned int res_118[3]; /* 0x00000764 */
   /** Denali CTL_119 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_119; /* 0x00000770 */
   /** Reserved */
   unsigned int res_119[3]; /* 0x00000774 */
   /** Denali CTL_120 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_120; /* 0x00000780 */
   /** Reserved */
   unsigned int res_120[3]; /* 0x00000784 */
   /** Denali CTL_121 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_121; /* 0x00000790 */
   /** Reserved */
   unsigned int res_121[3]; /* 0x00000794 */
   /** Denali CTL_122 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_122; /* 0x000007A0 */
   /** Reserved */
   unsigned int res_122[3]; /* 0x000007A4 */
   /** Denali CTL_123 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_123; /* 0x000007B0 */
   /** Reserved */
   unsigned int res_123[3]; /* 0x000007B4 */
   /** Denali CTL_124 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_124; /* 0x000007C0 */
   /** Reserved */
   unsigned int res_124[3]; /* 0x000007C4 */
   /** Denali CTL_125 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_125; /* 0x000007D0 */
   /** Reserved */
   unsigned int res_125[3]; /* 0x000007D4 */
   /** Denali CTL_126 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_126; /* 0x000007E0 */
   /** Reserved */
   unsigned int res_126[3]; /* 0x000007E4 */
   /** Denali CTL_127 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_127; /* 0x000007F0 */
   /** Reserved */
   unsigned int res_127[3]; /* 0x000007F4 */
   /** Denali CTL_128 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_128; /* 0x00000800 */
   /** Reserved */
   unsigned int res_128[3]; /* 0x00000804 */
   /** Denali CTL_129 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_129; /* 0x00000810 */
   /** Reserved */
   unsigned int res_129[3]; /* 0x00000814 */
   /** Denali CTL_130 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_130; /* 0x00000820 */
   /** Reserved */
   unsigned int res_130[3]; /* 0x00000824 */
   /** Denali CTL_131 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_131; /* 0x00000830 */
   /** Reserved */
   unsigned int res_131[3]; /* 0x00000834 */
   /** Denali CTL_132 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_132; /* 0x00000840 */
   /** Reserved */
   unsigned int res_132[3]; /* 0x00000844 */
   /** Denali CTL_133 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_133; /* 0x00000850 */
   /** Reserved */
   unsigned int res_133[3]; /* 0x00000854 */
   /** Denali CTL_134 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_134; /* 0x00000860 */
   /** Reserved */
   unsigned int res_134[3]; /* 0x00000864 */
   /** Denali CTL_135 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_135; /* 0x00000870 */
   /** Reserved */
   unsigned int res_135[3]; /* 0x00000874 */
   /** Denali CTL_136 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_136; /* 0x00000880 */
   /** Reserved */
   unsigned int res_136[3]; /* 0x00000884 */
   /** Denali CTL_137 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_137; /* 0x00000890 */
   /** Reserved */
   unsigned int res_137[3]; /* 0x00000894 */
   /** Denali CTL_138 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_138; /* 0x000008A0 */
   /** Reserved */
   unsigned int res_138[3]; /* 0x000008A4 */
   /** Denali CTL_139 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_139; /* 0x000008B0 */
   /** Reserved */
   unsigned int res_139[3]; /* 0x000008B4 */
   /** Denali CTL_140 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_140; /* 0x000008C0 */
   /** Reserved */
   unsigned int res_140[3]; /* 0x000008C4 */
   /** Denali CTL_141 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_141; /* 0x000008D0 */
   /** Reserved */
   unsigned int res_141[3]; /* 0x000008D4 */
   /** Denali CTL_142 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_142; /* 0x000008E0 */
   /** Reserved */
   unsigned int res_142[3]; /* 0x000008E4 */
   /** Denali CTL_143 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_143; /* 0x000008F0 */
   /** Reserved */
   unsigned int res_143[3]; /* 0x000008F4 */
   /** Denali CTL_144 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_144; /* 0x00000900 */
   /** Reserved */
   unsigned int res_144[3]; /* 0x00000904 */
   /** Denali CTL_145 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_145; /* 0x00000910 */
   /** Reserved */
   unsigned int res_145[3]; /* 0x00000914 */
   /** Denali CTL_146 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_146; /* 0x00000920 */
   /** Reserved */
   unsigned int res_146[3]; /* 0x00000924 */
   /** Denali CTL_147 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_147; /* 0x00000930 */
   /** Reserved */
   unsigned int res_147[3]; /* 0x00000934 */
   /** Denali CTL_148 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_148; /* 0x00000940 */
   /** Reserved */
   unsigned int res_148[3]; /* 0x00000944 */
   /** Denali CTL_149 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_149; /* 0x00000950 */
   /** Reserved */
   unsigned int res_149[3]; /* 0x00000954 */
   /** Denali CTL_150 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_150; /* 0x00000960 */
   /** Reserved */
   unsigned int res_150[3]; /* 0x00000964 */
   /** Denali CTL_151 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_151; /* 0x00000970 */
   /** Reserved */
   unsigned int res_151[3]; /* 0x00000974 */
   /** Denali CTL_152 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_152; /* 0x00000980 */
   /** Reserved */
   unsigned int res_152[3]; /* 0x00000984 */
   /** Denali CTL_153 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_153; /* 0x00000990 */
   /** Reserved */
   unsigned int res_153[3]; /* 0x00000994 */
   /** Denali CTL_154 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_154; /* 0x000009A0 */
   /** Reserved */
   unsigned int res_154[3]; /* 0x000009A4 */
   /** Denali CTL_155 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_155; /* 0x000009B0 */
   /** Reserved */
   unsigned int res_155[3]; /* 0x000009B4 */
   /** Denali CTL_156 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_156; /* 0x000009C0 */
   /** Reserved */
   unsigned int res_156[3]; /* 0x000009C4 */
   /** Denali CTL_157 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_157; /* 0x000009D0 */
   /** Reserved */
   unsigned int res_157[3]; /* 0x000009D4 */
   /** Denali CTL_158 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_158; /* 0x000009E0 */
   /** Reserved */
   unsigned int res_158[3]; /* 0x000009E4 */
   /** Denali CTL_159 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_159; /* 0x000009F0 */
   /** Reserved */
   unsigned int res_159[3]; /* 0x000009F4 */
   /** Denali CTL_160 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_160; /* 0x00000A00 */
   /** Reserved */
   unsigned int res_160[3]; /* 0x00000A04 */
   /** Denali CTL_161 register
       There is a separate set of registers for each of the slices of data sent on the DFI data bus. */
   unsigned int ctl_161; /* 0x00000A10 */
   /** Reserved */
   unsigned int res_161[379]; /* 0x00000A14 */
};


/* Fields of "Denali CTL_00 register" */
/** Trigger auto-refresh at boundary specified by AUTO_REFRESH_MODE
    Initiates an automatic refresh to the DRAM devices based on the setting of the auto_refresh_mode parameter. If there are any open banks when this parameter is set, the Denali Databahn Memory Controller will automatically close these banks before issuing the auto-refresh command. This parameter will always read back '0'. */
#define CTL0_AREFRESH 0x01000000
/* No-Operation
#define CTL0_AREFRESH_NOP 0x00000000 */
/** Trigger */
#define CTL0_AREFRESH_TRIG 0x01000000
/** Enable auto precharge mode of controller.
    Enables auto pre-charge mode for DRAM devices. Auto pre-charge mode enabled: All read and write transactions must be terminated by an auto pre-charge command. If a transaction consists of multiple read or write bursts, only the last command is issued with an auto pre-charge.Auto pre-charge mode disabled. Memory banks will stay open until another request requires this bank, the maximum open time (tras_max) has elapsed, or a refresh command closes all the banks. Note: This parameter may not be modified after the start parameter has been asserted. */
#define CTL0_AP 0x00010000
/* Disable
#define CTL0_AP_DIS 0x00000000 */
/** Enable */
#define CTL0_AP_EN 0x00010000
/** Enable address collision detection for cmd queue placement logic.
    Enables address collision/data coherency detection as a condition when using the placement logic to fill the command queue. */
#define CTL0_ADDR_CMP_EN 0x00000100
/* Disable
#define CTL0_ADDR_CMP_EN_DIS 0x00000000 */
/** Enable */
#define CTL0_ADDR_CMP_EN_EN 0x00000100
/** Enable command aging in the command queue.
    Enables aging of commands in the command queue when using the placement logic to fill the command queue. The total number of cycles required to decrement the priority value on a command by one is the product of the values in the age_count and command_age_count parameters. */
#define CTL0_ACTIVE_AGING 0x00000001
/* Disable
#define CTL0_ACTIVE_AGING_DIS 0x00000000 */
/** Enable */
#define CTL0_ACTIVE_AGING_EN 0x00000001

/* Fields of "Denali CTL_01 register" */
/** Allow controller to issue cmds to other banks while a bank is in auto pre-charge.
    Enables concurrent auto pre-charge. Some DRAM devices do not allow one bank to be auto pre-charged while another bank is reading or writing. The JEDEC standard allows concurrent auto pre-charge. Set this parameter for the DRAM device being used. */
#define CTL1_CONCURRENTAP 0x01000000
/* Disable
#define CTL1_CONCURRENTAP_DIS 0x00000000 */
/** Enable */
#define CTL1_CONCURRENTAP_EN 0x01000000
/** Set byte ordering as little endian or big endian.
    Selects the byte ordering for Denali Databahn Memory Controllers with programmable endian setting. */
#define CTL1_BIG_ENDIAN_EN 0x00010000
/* Little Endian
#define CTL1_BIG_ENDIAN_EN_LITTLE_ENDIAN 0x00000000 */
/** Big Endian */
#define CTL1_BIG_ENDIAN_EN_BIG_ENDIAN 0x00010000
/** Enable bank splitting for cmd queue placement logic.
    Enables bank splitting as a condition when using the placement logic to fill the command queue. */
#define CTL1_BANK_SPLIT_EN 0x00000100
/* Disable
#define CTL1_BANK_SPLIT_EN_DIS 0x00000000 */
/** Enable */
#define CTL1_BANK_SPLIT_EN_EN 0x00000100
/** Define auto-refresh to occur at next burst or next cmd boundary.
    Sets the mode for when the automatic refresh will occur. If auto_refresh_mode is set and a refresh is required to memory, the memory controller will delay this refresh until the end of the current transaction (if the transaction is fully contained inside a single page), or until the current transaction hits the end of the current page. */
#define CTL1_AUTO_REFRESH_MODE 0x00000001
/* Issue refresh on the next DRAM burst boundary even if the current command is not complete.
#define CTL1_AUTO_REFRESH_MODE_BURST_BOUNDARY 0x00000000 */
/** Issue refresh on the next command boundary. */
#define CTL1_AUTO_REFRESH_MODE_CMD_BOUNDARY 0x00000001

/* Fields of "Denali CTL_02 register" */
/** Sets DQ/DQS output enable behavior when controller is idle.
    Selects if the DQ output enables and DQS output enables will be driven active when the memory controller is in an idle state. */
#define CTL2_DRIVE_DQ_DQS 0x01000000
/* Leave the output enables de-asserted when idle.
#define CTL2_DRIVE_DQ_DQS_LEAVE 0x00000000 */
/** Drive the output enables active when idle. */
#define CTL2_DRIVE_DQ_DQS_DRIVE 0x01000000
/** Set DQS pin as single-ended or differential.
    Enables differential data strobe signals from the DRAM. */
#define CTL2_DQS_N_EN 0x00010000
/* Single-ended DQS signal from the DRAM.
#define CTL2_DQS_N_EN_SINGLE_ENDED 0x00000000 */
/** Differential DQS signal from the DRAM. */
#define CTL2_DQS_N_EN_DIFFERENTIAL 0x00010000
/** Enable the DLL bypass feature of the controller.
    Defines the behavior of the DLL bypass logic and establishes which set of delay parameters will be used. */
#define CTL2_DLL_BYPASS_MODE 0x00000100
/* Normal operational mode.
#define CTL2_DLL_BYPASS_MODE_NORMAL 0x00000000 */
/** Bypass the DLL master delay line. */
#define CTL2_DLL_BYPASS_MODE_BYPASS 0x00000100
/** Status of DLL lock coming out of master delay.
    Shows status of the DLL as locked or unlocked. */
#define CTL2_DLLLOCKREG 0x00000001

/* Fields of "Denali CTL_03 register" */
/** Allow the controller to interrupt an auto pre-charge cmd with another cmd.
    Enables interrupting an auto pre-charge command with another command for a different bank. If enabled, the current operation will be interrupted. However, the bank will be pre-charged as if the current operation were allowed to continue. */
#define CTL3_INTRPTAPBURST 0x01000000
/* Disable
#define CTL3_INTRPTAPBURST_DIS 0x00000000 */
/** Enable */
#define CTL3_INTRPTAPBURST_EN 0x01000000
/** Define when write cmds are issued to DRAM devices.
    Controls when the write commands are issued to the DRAM devices. */
#define CTL3_FAST_WRITE 0x00010000
/* The memory controller will issue a write command to the DRAM devices when it has received enough data for one DRAM burst. In this mode, write data can be sent in any cycle relative to the write command. This mode also allows for multi-word write command data to arrive in non-sequential cycles.
#define CTL3_FAST_WRITE_SLOW 0x00000000 */
/** The memory controller will issue a write command to the DRAM devices after the first word of the write data is received by the memory controller. The first word can be sent at any time relative to the write command. In this mode, multi-word write command data must be available to the memory controller in sequential cycles. */
#define CTL3_FAST_WRITE_FAST 0x00010000
/** Allow user to interrupt memory initialization to enter self-refresh mode.
    When this bit is set, the memory initialization sequence will be interrupted and self-refresh mode will be entered. This is used to place the memory devices into self-refresh mode when a power loss is detected during the initialization process. */
#define CTL3_ENABLE_QUICK_SREFRESH 0x00000100
/* Disable
#define CTL3_ENABLE_QUICK_SREFRESH_DIS 0x00000000 */
/** Enable */
#define CTL3_ENABLE_QUICK_SREFRESH_EN 0x00000100
/** Number of banks on the DRAM(s).
    Indicates that the memory devices have eight banks. */
#define CTL3_EIGHT_BANK_MODE 0x00000001
/* Memory devices have 4 banks.
#define CTL3_EIGHT_BANK_MODE_FOUR_BANKS 0x00000000 */
/** Memory devices have 8 banks. */
#define CTL3_EIGHT_BANK_MODE_EIGHT_BANKS 0x00000001

/* Fields of "Denali CTL_04 register" */
/** Enable extra turnaround clock between back-to-back reads/writes to different chip selects.
    Adds a turn-around clock between back-to-back reads or back-to-back writes to different chip selects. The additional clock may be needed at higher clock frequencies. The turn off and turn on time of termination resistors are not scalable. At higher clock frequencies, it is possible that these times may overlap, resulting in two active resistors while the DQS line is still active. This could compromise the signal integrity of the DQS signal. The additional clock prevents this overlap. */
#define CTL4_ODT_ADD_TURN_CLK_EN 0x01000000
/* Disable
#define CTL4_ODT_ADD_TURN_CLK_EN_DIS 0x00000000 */
/** Enable */
#define CTL4_ODT_ADD_TURN_CLK_EN_EN 0x01000000
/** Disable DRAM cmds until TDLL has expired during initialization.
    Disables DRAM commands until DLL initialization is complete and tdll has expired. */
#define CTL4_NO_CMD_INIT 0x00010000
/* Issue only REF and PRE commands during DLL initialization of the DRAM devices. If PRE commands are issued before DLL initialization is complete, the command will be executed immediately, and then the DLL initialization will continue.
#define CTL4_NO_CMD_INIT_REFPRE 0x00000000 */
/** Do not issue any type of command during DLL initialization of the DRAM devices. If any other commands are issued during the initialization time, they will be held off until DLL initialization is complete. */
#define CTL4_NO_CMD_INIT_NOCMD 0x00010000
/** Allow the controller to interrupt a combined write cmd with auto pre-charge with another write cmd.
    Enables interrupting of a combined write with auto precharge command with another read or write command to the same bank before the first write command is completed. */
#define CTL4_INTRPTWRITEA 0x00000100
/* Disable
#define CTL4_INTRPTWRITEA_DIS 0x00000000 */
/** Enable */
#define CTL4_INTRPTWRITEA_EN 0x00000100
/** Allow the controller to interrupt a combined read with auto pre-charge cmd with another read cmd.
    Enables interrupting of a combined read with auto precharge command with another read command to the same bank before the first read command is completed. */
#define CTL4_INTRPTREADA 0x00000001
/* Disable
#define CTL4_INTRPTREADA_DIS 0x00000000 */
/** Enable */
#define CTL4_INTRPTREADA_EN 0x00000001

/* Fields of "Denali CTL_05 register" */
/** Enable priority for cmd queue placement logic.
    Enables priority as a condition when using the placement logic to fill the command queue. */
#define CTL5_PRIORITY_EN 0x01000000
/* Disable
#define CTL5_PRIORITY_EN_DIS 0x00000000 */
/** Enable */
#define CTL5_PRIORITY_EN_EN 0x01000000
/** Disable clock enable and set DRAMs in power-down state.
    When this parameter is written with a '1', the memory controller will complete processing of the current burst for the current transaction (if any), issue a pre-charge all command and then disable the clock enable signal to the DRAM devices. Any subsequent commands in the command queue will be suspended until this parameter is written with a '0'. */
#define CTL5_POWER_DOWN 0x00010000
/* Enable full power state.
#define CTL5_POWER_DOWN_FPS 0x00000000 */
/** Disable the clock enable and power down the memory controller. */
#define CTL5_POWER_DOWN_PDS 0x00010000
/** Enable placement logic for cmd queue.
    Enables using the placement logic to fill the command queue. */
#define CTL5_PLACEMENT_EN 0x00000100
/* Placement logic is disabled. The command queue is a straight FIFO.
#define CTL5_PLACEMENT_EN_FIFO 0x00000000 */
/** Placement logic is enabled. The command queue will be filled according to the placement logic factors. */
#define CTL5_PLACEMENT_EN_PL 0x00000100
/** Enable use of non- DFI odt_alt signal.
    Enables the use of the non-DFI compliant alternative ODT internal signal odt_alt, which is externally viewed as the signal reserved0. This signal is only required if the user intends to use a CAS latency of 3 with ODT support. The user will need to modify the dmc_asic.v file for this support. Refer to Section 11.3.4, On-Die Termination in the DDR PHY Interface (DFI) Chapter for more information. */
#define CTL5_ODT_ALT_EN 0x00000001
/* ODT support with CAS latency 3 is not supported.
#define CTL5_ODT_ALT_EN_NODTLAT3 0x00000000 */
/** ODT support with CAS latency 3 is supported but is not DFI compliant. This disables the interrupt bit for ODT-with-CAS3 and disables the OVL error. */
#define CTL5_ODT_ALT_EN_ODTLAT3 0x00000001

/* Fields of "Denali CTL_06 register" */
/** Enable read/write grouping for cmd queue placement logic.
    Enables read/write grouping as a condition when using the placement logic to fill the command queue. */
#define CTL6_RW_SAME_EN 0x01000000
/* Disable
#define CTL6_RW_SAME_EN_DIS 0x00000000 */
/** Enable */
#define CTL6_RW_SAME_EN_EN 0x01000000
/** Enable registered DIMM operation of the controller.
    Enables registered DIMM operations to control the address and command pipeline of the memory controller. */
#define CTL6_REG_DIMM_ENABLE 0x00010000
/* Disable
#define CTL6_REG_DIMM_ENABLE_DIS 0x00000000 */
/** Enable */
#define CTL6_REG_DIMM_ENABLE_EN 0x00010000
/** Enable the half datapath feature of the controller.
    Controls the width of the memory datapath. When enabled, the upper half of the memory buses (DQ, DQS and DM) are unused and relevant data only exists in the lower half of the buses. This parameter expands the Denali Databahn Memory Controller for use with memory devices of the configured width or half of the configured width. Note: The entire user datapath is used regardless of this setting. When operating in half datapath mode, only bstlen values of 4 and 8 are supported. For more information on half datapath mode, refer to the Other Databahn Features Chapter. */
#define CTL6_REDUC 0x00000100
/* Disable
#define CTL6_REDUC_DIS 0x00000000 */
/** Enable */
#define CTL6_REDUC_EN 0x00000100
/** Allow powerup via self-refresh instead of full memory initialization.
    Allows controller to exit power-down mode by executing a self-refresh exit instead of the full memory initialization. This parameter provides a means to skip full initialization when the DRAM devices are in a known self-refresh state. */
#define CTL6_PWRUP_SREFRESH_EXIT 0x00000001
/* Disable
#define CTL6_PWRUP_SREFRESH_EXIT_DIS 0x00000000 */
/** Enable */
#define CTL6_PWRUP_SREFRESH_EXIT_EN 0x00000001

/* Fields of "Denali CTL_07 register" */
/** Allow the controller to execute auto precharge cmds before TRAS_MIN expires.
    Defines the tRAS lockout setting for the DRAM device. tRAS lockout allows the memory controller to execute auto pre-charge commands before the tras_min parameter has expired. */
#define CTL7_TRAS_LOCKOUT 0x01000000
/* tRAS lockout not supported by memory device.
#define CTL7_TRAS_LOCKOUT_NTRASL 0x00000000 */
/** tRAS lockout supported by memory device. */
#define CTL7_TRAS_LOCKOUT_TRASL 0x01000000
/** Enable command swapping logic in execution unit.
    Enables swapping of the active command for a new higher-priority command when using the placement logic. */
#define CTL7_SWAP_EN 0x00010000
/* Disable
#define CTL7_SWAP_EN_DIS 0x00000000 */
/** Enable */
#define CTL7_SWAP_EN_EN 0x00010000
/** Initiate cmd processing in the controller.
    With this parameter set to b0, the memory controller will not issue any commands to the DRAM devices or respond to any signal activity except for reading and writing parameters. Once this parameter is set to b1, the memory controller will respond to inputs from the ASIC. When set, the memory controller begins its initialization routine. Note: The user must wait for the initialization complete bit to be set in the int_status parameter and for the dfi_init_complete signal to be asserted from the PHY before submitting any transactions. */
#define CTL7_START 0x00000100
/* Controller is not in active mode.
#define CTL7_START_NOACT 0x00000000 */
/** Initiate active mode for the memory controller. */
#define CTL7_START_IACT 0x00000100
/** Place DRAMs in self-refresh mode.
    When this parameter is written with a b1, the DRAM device(s) will be placed in self-refresh mode. For this, the current burst for the current transaction (if any) will complete, all banks will be closed, the self-refresh command will be issued to the DRAM, and the clock enable signal will be de-asserted. The system will remain in self-refresh mode until this parameter is written with a b0. The DRAM devices will return to normal operating mode after the self-refresh exit time (txsr) of the device and any DLL initialization time for the DRAM is reached. The memory controller will resume processing of the commands from the interruption point. This parameter will be updated with an assertion of the srefresh_enter pin, regardless of the behavior on the register interface. To disable self-refresh again after a srefresh_enter pin assertion, the user will need to clear the parameter to b0. */
#define CTL7_SREFRESH 0x00000001
/* Disable self-refresh mode.
#define CTL7_SREFRESH_DISSR 0x00000000 */
/** Initiate self-refresh of the DRAM devices. */
#define CTL7_SREFRESH_INITSR 0x00000001

/* Fields of "Denali CTL_08 register" */
/** Defines which chip selects are active.
    Sets the mask that determines which chip select pins are active, with each bit representing a different chip select. The user address chip select field will be mapped into the active chip selects indicated by this parameter in ascending order from lowest to highest. This allows the memory controller to map the entire contiguous user address into any group of chip selects. Bit [0] of this parameter corresponds to chip select [0], bit [1] corresponds to chip select [1], etc. The number of chip selects, the number of bits set to 1 in this parameter, must be a power of 2 (20, 21, 22, etc.) */
#define CTL8_CS_MAP_MASK 0x03000000
/** field offset */
#define CTL8_CS_MAP_OFFSET 24
/** Write mode register data to the DRAMs. WRITE-ONLY
    Supplies the EMRS data for each chip select to allow individual chips to set masked refreshing. When this parameter is written with a b1, the mode parameter(s) [EMRS register] within the DRAM devices will be written. Each subsequent write_modereg setting will write the EMRS register of the next chip select. This parameter will always read back as b0. The mode registers are automatically written at initialization of the memory controller. There is no need to initiate a mode register write after setting the start parameter in the memory controller unless some value in these registers needs to be changed after initialization. Note: This parameter may not be changed when the memory is in power-down mode (when the CKE input is de-asserted). */
#define CTL8_WRITE_MODEREG 0x00010000
/** Allow controller to interrupt a write burst to the DRAMs with a read cmd.
    Defines whether the memory controller can interrupt a write burst with a read command. Some memory devices do not allow this functionality. */
#define CTL8_WRITEINTERP 0x00000100
/* The device does not support read commands interrupting write commands.
#define CTL8_WRITEINTERP_NRIWB 0x00000000 */
/** The device does support read commands interrupting write commands. */
#define CTL8_WRITEINTERP_RIWB 0x00000100
/** Issue auto-refresh cmds to the DRAMs every TREF cycles.
    Enables refresh commands. If command refresh mode is configured, then refresh commands will be automatically issued based on the internal tref counter and any refresh commands sent through the command interface or the register interface. */
#define CTL8_TREF_ENABLE 0x00000001
/* Disable
#define CTL8_TREF_ENABLE_DIS 0x00000000 */
/** Enable */
#define CTL8_TREF_ENABLE_EN 0x00000001

/* Fields of "Denali CTL_09 register" */
/** Determines which chip(s) will have termination when a read occurs on chip 0.
    Sets up which (if any) chip(s) will have their ODT termination active while a read occurs on chip select 0. Note: Only one chip select (and therefore 1 bit) may be set at any time. Example: If the system consists of 4 chip selects and odt_rd_map_cs0 is set to b0010, then when CS0 is performing a read, CS1 will have active ODT termination. And if odt_rd_map_cs0 was set to b1000, then instead CS3 would be active. Bit [3] = CS3 will have active ODT termination when chip select 0 is performing a read. Bit [2] = CS2 will have active ODT termination when chip select 0 is performing a read. Bit [1] = CS1 will have active ODT termination when chip select 0 is performing a read. Bit [0] = CS0 will have active ODT termination when chip select 0 is performing a read. Etc. */
#define CTL9_ODT_RD_MAP_CS0_MASK 0x03000000
/** field offset */
#define CTL9_ODT_RD_MAP_CS0_OFFSET 24
/** Maximum number of chip selects available. READONLY
    Displays the maximum number of chip selects configured for this memory controller. This parameter is read-only. */
#define CTL9_MAX_CS_REG_MASK 0x00030000
/** field offset */
#define CTL9_MAX_CS_REG_OFFSET 16
/** Enable refreshes while in low power mode.
    Sets whether refreshes will occur while the memory controller is in any of the low power modes. */
#define CTL9_LOWPOWER_REFRESH_ENABLE_MASK 0x00000300
/** field offset */
#define CTL9_LOWPOWER_REFRESH_ENABLE_OFFSET 8
/** Refreshes still occur */
#define CTL9_LOWPOWER_REFRESH_ENABLE_LPREF 0x00000000
/** Refreshes do not occur */
#define CTL9_LOWPOWER_REFRESH_ENABLE_LPNREF 0x00000100
/** Set value for dfi_dram_clk_disable.
    Sets value for the DFI output signal dfi_dram_clk_disable. Bit [0] controls CS0, Bit [1] controls CS1. For each bit: */
#define CTL9_DRAM_CLK_DISABLE_MASK 0x00000003
/** field offset */
#define CTL9_DRAM_CLK_DISABLE_OFFSET 0
/** Memory clock/s should be active. */
#define CTL9_DRAM_CLK_DISABLE_CLKACT 0x00000000
/** Memory clock/s should be disabled. */
#define CTL9_DRAM_CLK_DISABLE_CLKDIS 0x00000001

/* Fields of "Denali CTL_10 register" */
/** On-Die termination resistance setting for all DRAM devices.
    Defines the On-Die termination resistance for all DRAM devices. The Denali Databahn Memory Controller can not be set for different termination values for each chip select. Note: The user must program the same values into the A6/A2 bits of emrs1_data_X and rtt_0. */
#define CTL_10_RTT_0_MASK 0x03000000
/** field offset */
#define CTL_10_RTT_0_OFFSET 24
/** Disable */
#define CTL_10_RTT_0_DIS 0x00000000
/** 75 Ohm */
#define CTL_10_RTT_0_OHM_75 0x01000000
/** 150 Ohm */
#define CTL_10_RTT_0_OHM_150 0x02000000
/** Determines which chip(s) will have termination when a write occurs on chip 1.
    Sets up which (if any) chip(s) will have their ODT termination active while a write occurs on chip select 1. Note: Only one chip select (and therefore 1 bit) may be set at any time. Example: If the system consists of 4 chip selects and odt_wr_map_cs0 is set to b0010, then when CS0 is performing a write, CS1 will have active ODT termination. And if odt_wr_map_cs0 was set to b1000, then instead CS3 would be active. Bit [3] = CS3 will have active ODT termination when chip select 1 is performing a write. Bit [2] = CS2 will have active ODT termination when chip select 1 is performing a write. Bit [1] = CS1 will have active ODT termination when chip select 1 is performing a write. Bit [0] = CS0 will have active ODT termination when chip select 1 is performing a write. Etc. */
#define CTL_10_ODT_WR_MAP_CS1_MASK 0x00030000
/** field offset */
#define CTL_10_ODT_WR_MAP_CS1_OFFSET 16
/** Determines which chip(s) will have termination when a write occurs on chip 1.
    Sets up which (if any) chip(s) will have their ODT termination active while a write occurs on chip select 0. Note: Only one chip select (and therefore 1 bit) may be set at any time. Example: If the system consists of 4 chip selects and odt_wr_map_cs0 is set to b0010, then when CS0 is performing a write, CS1 will have active ODT termination. And if odt_wr_map_cs0 was set to b1000, then instead CS3 would be active. Bit [3] = CS3 will have active ODT termination when chip select 0 is performing a write. Bit [2] = CS2 will have active ODT termination when chip select 0 is performing a write. Bit [1] = CS1 will have active ODT termination when chip select 0 is performing a write. Bit [0] = CS0 will have active ODT termination when chip select 0 is performing a write. Etc. */
#define CTL_10_ODT_WR_MAP_CS0_MASK 0x00000300
/** field offset */
#define CTL_10_ODT_WR_MAP_CS0_OFFSET 8
/** Determines which chip(s) will have termination when a read occurs on chip 1.
    Sets up which (if any) chip(s) will have their ODT termination active while a read occurs on chip select 1. Note: Only one chip select (and therefore 1 bit) may be set at any time. Example: If the system consists of 4 chip selects and odt_rd_map_cs0 is set to b0010, then when CS0 is performing a read, CS1 will have active ODT termination. And if odt_rd_map_cs0 was set to b1000, then instead CS3 would be active. Bit [3] = CS3 will have active ODT termination when chip select 1 is performing a read. Bit [2] = CS2 will have active ODT termination when chip select 1 is performing a read. Bit [1] = CS1 will have active ODT termination when chip select 1 is performing a read. Bit [0] = CS0 will have active ODT termination when chip select 1 is performing a read. Etc. */
#define CTL_10_ODT_RD_MAP_CS1_MASK 0x00000003
/** field offset */
#define CTL_10_ODT_RD_MAP_CS1_OFFSET 0

/* Fields of "Denali CTL_11 register" */
/** Difference between number of column pins available and number being used.
    Shows the difference between the maximum column width available (12) and the actual number of column pins being used. The user address is automatically shifted so that the user address space is mapped contiguously into the memory map based on the value of this parameter. For details, refer to the Databahn Address Mapping Chapter. */
#define CTL_11_COLUMN_SIZE_MASK 0x07000000
/** field offset */
#define CTL_11_COLUMN_SIZE_OFFSET 24
/** Additional cycles to delay CKE for status reporting.
    Sets the number of additional cycles of delay to include in the CKE signal cke_status for status reporting. The default delay is 0 cycles. */
#define CTL_11_CKE_DELAY_MASK 0x00070000
/** field offset */
#define CTL_11_CKE_DELAY_OFFSET 16
/** Encoded CAS latency sent to DRAMs during initialization.
    Sets the CAS (Column Address Strobe) latency encoding that the memory uses. The binary value programmed into this parameter is dependent on the memory device, since the same caslat value may have different meanings to different memories. This will be programmed into the DRAM devices at initialization. The CAS encoding will be specified in the DRAM spec sheet, and should correspond to the caslat_lin parameter. Refer to the files in the regconfigs/ directory in the release for actual settings for each particular device. Note: For optimal synthesis behavior, the ODT path for a CAS latency of three is clocked at a 200 MHz clock regardless of configured maximum speed. */
#define CTL_11_CASLAT_MASK 0x00000700
/** field offset */
#define CTL_11_CASLAT_OFFSET 8
/** Difference between number of addr pins available and number being used.
    Defines the difference between the maximum number of address pins configured (14) and the actual number of pins being used. The user address is automatically shifted so that the user address space is mapped contiguously into the memory map based on the value of this parameter. For details, refer to the Databahn Address Mapping Chapter. */
#define CTL_11_ADDR_PINS_MASK 0x00000007
/** field offset */
#define CTL_11_ADDR_PINS_OFFSET 0

/* Fields of "Denali CTL_12 register" */
/** Delay from DFI clock disable to memory clock disable.
    Holds the DFI tdram_clk_disable timing parameter. This parameter should be programmed with the number of cycles that the PHY requires to disable the clock after the dfi_dram_clk_disable signal is asserted. */
#define CTL_12_TDFI_DRAM_CLK_DISABLE_MASK 0x07000000
/** field offset */
#define CTL_12_TDFI_DRAM_CLK_DISABLE_OFFSET 24
/** Minimum CKE pulse width.
    Defines the minimum CKE pulse width, in cycles. */
#define CTL_12_TCKE_MASK 0x00070000
/** field offset */
#define CTL_12_TCKE_OFFSET 16
/** Quantity that determines cmd queue full.
    Defines quantity of data that will be considered full for the command queue. */
#define CTL_12_Q_FULLNESS_MASK 0x00000700
/** field offset */
#define CTL_12_Q_FULLNESS_OFFSET 8
/** Type of cmd that caused an Out-of- Range interrupt. READ-ONLY
    Holds the type of command that caused an out-of-range interrupt request to the memory devices. This parameter is read-only. For more information on out-of-range address checking, refer to the Other Databahn Features Chapter. */
#define CTL_12_OUT_OF_RANGE_TYPE_MASK 0x00000007
/** field offset */
#define CTL_12_OUT_OF_RANGE_TYPE_OFFSET 0

/* Fields of "Denali CTL_13 register" */
/** Additional clocks of delay to insert between writes and reads to the same chip select.
    Defines the number of additional clocks of delay to insert between a write and a read to the same chip selects. The registers in the memory controller must be configured before the DRAM devices can be accessed. */
#define CTL_13_W2R_SAMECS_DLY_MASK 0x07000000
/** field offset */
#define CTL_13_W2R_SAMECS_DLY_OFFSET 24
/** Additional clocks of delay to insert between writes and reads to different chip selects.
    Defines the number of additional clocks of delay to insert between a write and a read to the different chip select. */
#define CTL_13_W2R_DIFFCS_DLY_MASK 0x00070000
/** field offset */
#define CTL_13_W2R_DIFFCS_DLY_OFFSET 16
/** DRAM TRTP parameter in cycles.
    Defines the DRAM tRTP (read to pre-charge time) parameter, in cycles. */
#define CTL_13_TRTP_MASK 0x00000700
/** field offset */
#define CTL_13_TRTP_OFFSET 8
/** DRAM TRRD parameter in cycles.
    Defines the DRAM activate to activate delay for different banks, in cycles. */
#define CTL_13_TRRD_MASK 0x00000007
/** field offset */
#define CTL_13_TRRD_OFFSET 0

/* Fields of "Denali CTL_14 register" */
/** Adjusts data capture gate open by half cycles.
    Adjusts the data capture gate open time by 1/2 cycle increments. This parameter is programmed differently than caslat_lin when there are fixed offsets in the flight path between the memories and the memory controller for clock gating. When caslat_lin_gate is a larger value than caslat_lin, the data capture window will become shorter. A caslat_lin_gate value smaller than caslat_lin may have no effect on the data capture window, depending on the fixed offsets in the ASIC and the board. Note: For optimal synthesis behavior, the ODT path for a CAS latency of three is clocked at a 200 MHz clock regardless of configured maximum speed. b0000 - b0001 = Reserved */
#define CTL_14_CASLAT_LIN_GATE_MASK 0x0F000000
/** field offset */
#define CTL_14_CASLAT_LIN_GATE_OFFSET 24
/** 1 cycle */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_1 0x02000000
/** 1.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_1_5 0x03000000
/** 2 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_2 0x04000000
/** 2.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_2_5 0x05000000
/** 3 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_3 0x06000000
/** 3.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_3_5 0x07000000
/** 4 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_4 0x08000000
/** 4.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_4_5 0x09000000
/** 5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_5 0x0A000000
/** 5.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_5_5 0x0B000000
/** 6 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_6 0x0C000000
/** 6.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_6_5 0x0D000000
/** 7 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_7 0x0E000000
/** 7.5 cycles */
#define CTL_14_CASLAT_LIN_GATE_CYCLES_7_5 0x0F000000
/** Sets latency from read cmd send to data receive from/to controller.
    Sets the CAS latency linear value in 1/2 cycle increments. This sets an internal adjustment for the delay from when the read command is sent from the memory controller to when data will be received back. The window of time in which the data is captured is a fixed length. The caslat_lin parameter adjusts the start of this data capture window. Not all linear values will be supported for the memory devices being used. Refer to the specification for the memory devices being used. Note: For optimal synthesis behavior, the ODT path for a CAS latency of three is clocked at a 200 MHz clock regardless of configured maximum speed. */
#define CTL_14_CASLAT_LIN_MASK 0x000F0000
/** field offset */
#define CTL_14_CASLAT_LIN_OFFSET 16
/** 1 cycle */
#define CTL_14_CASLAT_LIN_CYCLES_1 0x00020000
/** 1.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_1_5 0x00030000
/** 2 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_2 0x00040000
/** 2.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_2_5 0x00050000
/** 3 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_3 0x00060000
/** 3.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_3_5 0x00070000
/** 4 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_4 0x00080000
/** 4.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_4_5 0x00090000
/** 5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_5 0x000A0000
/** 5.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_5_5 0x000B0000
/** 6 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_6 0x000C0000
/** 6.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_6_5 0x000D0000
/** 7 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_7 0x000E0000
/** 7.5 cycles */
#define CTL_14_CASLAT_LIN_CYCLES_7_5 0x000F0000
/** Location of the auto pre-charge bit in the DRAM address.
    Defines the location of the auto pre-charge bit in the DRAM address in decimal encoding. */
#define CTL_14_APREBIT_MASK 0x00000F00
/** field offset */
#define CTL_14_APREBIT_OFFSET 8
/** Initial value of master aging-rate counter for cmd aging.
    Holds the initial value of the master aging-rate counter. When using the placement logic to fill the command queue, the command aging counters will be decremented one each time the master aging-rate counter counts down age_count cycles. */
#define CTL_14_AGE_COUNT_MASK 0x0000000F
/** field offset */
#define CTL_14_AGE_COUNT_OFFSET 0

/* Fields of "Denali CTL_15 register" */
/** Maximum width of column address in DRAMs. READONLY
    Defines the maximum width of column address in the DRAM devices. This value can be used to set the column_size parameter. This parameter is read-only. column_size = max_col_reg - [number of column bits in memory device]. */
#define CTL_15_MAX_COL_REG_MASK 0x0F000000
/** field offset */
#define CTL_15_MAX_COL_REG_OFFSET 24
/** Number of autorefresh cmds to execute during DRAM initialization.
    Defines the number of auto-refresh commands needed by the DRAM devices to satisfy the initialization sequence. */
#define CTL_15_INITAREF_MASK 0x000F0000
/** field offset */
#define CTL_15_INITAREF_OFFSET 16
/** Defines the mode of operation of the controller.
    Selects the mode of operation for the Denali Databahn Memory Controller. All other settings reserved. */
#define CTL_15_DRAM_CLASS_MASK 0x00000F00
/** field offset */
#define CTL_15_DRAM_CLASS_OFFSET 8
/** DDR1 */
#define CTL_15_DRAM_CLASS_DDR1 0x00000000
/** DDR2 */
#define CTL_15_DRAM_CLASS_DDR2 0x00000400
/** Initial value of individual cmd aging counters for cmd aging.
    Holds the initial value of the command aging counters associated with each command in the command queue. When using the placement logic to fill the command queue, the command aging counters decrement one each time the master aging-rate counter counts down age_count cycles. */
#define CTL_15_COMMAND_AGE_COUNT_MASK 0x0000000F
/** field offset */
#define CTL_15_COMMAND_AGE_COUNT_OFFSET 0

/* Fields of "Denali CTL_16 register" */
/** Holds the DFI tCTRLUPD_MIN timing parameter. READ-ONLY
    Holds the DFI tctrlupd_min timing parameter. This parameter is read-only. */
#define CTL_16_TDFI_CTRLUPD_MIN_MASK 0x0F000000
/** field offset */
#define CTL_16_TDFI_CTRLUPD_MIN_OFFSET 24
/** Adjustment value for PHY read timing.
    Adjusts the relative timing between DFI read commands and the dfi_rddata_en signal to conform to PHY timing requirements. When this parameter is programmed to 0x0, dfi_rddata_en will assert one cycle after the dfi_address. */
#define CTL_16_RDLAT_ADJ_MASK 0x000F0000
/** field offset */
#define CTL_16_RDLAT_ADJ_OFFSET 16
/** Source ID of cmd that caused an Outof- Range interrupt. READ-ONLY
    Holds the Source ID of the command that caused an outof- range interrupt request to the memory devices. This parameter is read-only. For more information on out-of-range address checking, refer to the Other Databahn Features Chapter. */
#define CTL_16_OUT_OF_RANGE_SOURCE_ID_MASK 0x00000F00
/** field offset */
#define CTL_16_OUT_OF_RANGE_SOURCE_ID_OFFSET 8
/** Maximum width of memory address bus. READ-ONLY
    Defines the maximum width of the memory address bus (number of row bits) for the memory controller. This value can be used to set the addr_pins parameter. This parameter is read-only. addr_pins = max_row_reg - [number of row bits in memory device]. */
#define CTL_16_MAX_ROW_REG_MASK 0x0000000F
/** field offset */
#define CTL_16_MAX_ROW_REG_OFFSET 0

/* Fields of "Denali CTL_17 register" */
/** Holds the calculated DFI tPHY_WRLAT timing parameter. READ-ONLY
    Holds the calculated value of the tphy_wrlat timing parameter. This equation is dependent on the latency setting for the address / control path of the PHY as set in the phy_ctrl_reg_2 [25] parameter bit. If phy_ctrl_reg_2 [25] = 0: ..... If (tdfi_phy_wrlat_base + wrlat_adj) = 2: .......... tdfi_phy_wrlat = reg_dimm_enable;..... If (tdfi_phy_wrlat_base + wrlat_adj) 2: .......... tdfi_phy_wrlat = tdfi_phy_wrlat_base + wrlat_adj + reg_dimm_enable - WRLAT_WIDTH'h3 Note: Values of (tdfi_phy_wrlat_base + wrlat_adj) If phy_ctrl_reg_2 [25] = 1: ..... If (tdfi_phy_wrlat_base + wrlat_adj) .......... tdfi_phy_wrlat = reg_dimm_enable; ..... If (tdfi_phy_wrlat_base + wrlat_adj)= 4: .......... tdfi_phy_wrlat = tdfi_phy_wrlat_base + wrlat_adj + reg_dimm_enable - WRLAT_WIDTH'h4;This parameter is read-only. */
#define CTL_17_TDFI_PHY_WRLAT_MASK 0x0F000000
/** field offset */
#define CTL_17_TDFI_PHY_WRLAT_OFFSET 24
/** Holds the tPHY_RDLAT timing parameter.
    Holds the tphy_rdlat timing parameter. */
#define CTL_17_TDFI_PHY_RDLAT_MASK 0x000F0000
/** field offset */
#define CTL_17_TDFI_PHY_RDLAT_OFFSET 16
/** Delay from DFI clock enable to memory clock enable.
    Holds the DFI tdram_clk_enable timing parameter. This parameter is currently unused in the Denali Databahn Memory Controller. */
#define CTL_17_TDFI_DRAM_CLK_ENABLE_MASK 0x00000F00
/** field offset */
#define CTL_17_TDFI_DRAM_CLK_ENABLE_OFFSET 8
/** Delay from DFI command to memory command.
    Holds the DFI tctrl_delay timing parameter. This parameter should be programmed with the number of cycles that the PHY requires to send a power-down or self-refresh command to the DRAM devices. */
#define CTL_17_TDFI_CTRL_DELAY_MASK 0x0000000F
/** field offset */
#define CTL_17_TDFI_CTRL_DELAY_OFFSET 0

/* Fields of "Denali CTL_18 register" */
/** DRAM TRP parameter in cycles.
    Defines the DRAM pre-charge command time, in cycles. */
#define CTL_18_TRP_MASK 0x0F000000
/** field offset */
#define CTL_18_TRP_OFFSET 24
/** Sets DFI base value for the tRDDATA_EN timing parameter.
    Used to adjust the tdfi_rddata_en parameter if the PHY requires greater delay from read command to read data enable. */
#define CTL_18_TDFI_RDDATA_EN_BASE_MASK 0x000F0000
/** field offset */
#define CTL_18_TDFI_RDDATA_EN_BASE_OFFSET 16
/** Holds the calculated DFI tRDDATA_EN timing parameter. READ-ONLY
    Holds the calculated value of the trddata_en timing parameter. This equation is dependent on the latency setting for the address / control path of the PHY as set in the phy_ctrl_reg_2 [25] parameter bit. If phy_ctrl_reg_2 [25] = 0: ..... If (tdfi_rddata_en_base + rdlat_adj) = 2: .......... tdfi_rddata_en = reg_dimm_enable; ..... If (tdfi_rddata_en_base + rdlat_adj) 2: .......... tdfi_rddata_en = tdfi_rddata_en_base + rdlat_adj + reg_dimm_enable - RDLAT_WIDTH'h3 Note: Values of (tdfi_rddata_en_base + rdlat_adj) If phy_ctrl_reg_2 [25] = 1:..... If (tdfi_rddata_en_base + rdlat_adj) .......... tdfi_rddata_en = reg_dimm_enable;..... If (tdfi_rddata_en_base + rdlat_adj) = 4: .......... tdfi_rddata_en = tdfi_rddata_en_base + rdlat_adj + reg_dimm_enable - RDLAT_WIDTH'h4This parameter is read-only. */
#define CTL_18_TDFI_RDDATA_EN_MASK 0x00000F00
/** field offset */
#define CTL_18_TDFI_RDDATA_EN_OFFSET 8
/** Sets DFI base value for the tPHY_WRLAT timing parameter.
    Used to adjust the tdfi_phy_wrlat parameter if the PHY requires greater delay from write command to write data. */
#define CTL_18_TDFI_PHY_WRLAT_BASE_MASK 0x0000000F
/** field offset */
#define CTL_18_TDFI_PHY_WRLAT_BASE_OFFSET 0

/* Fields of "Denali CTL_19 register" */
/** Enables automatic entry into the low power mode on idle.
    Enables automatic entry into the low power modes of the memory controller. Bit [4] = Controls memory power-down mode (Mode 1). Bit [3] = Controls memory power-down with memory clock gating mode (Mode 2). Bit [2] = Controls memory self-refresh mode (Mode 3). Bit [1] = Controls memory self-refresh with memory clock gating mode (Mode 4). Bit [0] = Controls memory self-refresh with memory and controller clock gating mode (Mode 5). For all bits: */
#define CTL_19_LOWPOWER_AUTO_ENABLE_MASK 0x1F000000
/** field offset */
#define CTL_19_LOWPOWER_AUTO_ENABLE_OFFSET 24
/** Automatic entry into this mode is disabled. The user may enter this mode manually by setting the associated lowpower_control bit. */
#define CTL_19_LOWPOWER_AUTO_ENABLE_AUTODIS 0x00000000
/** Automatic entry into this mode is enabled. The mode will be entered automatically when the proper counters expire, and only if the associated lowpower_control bit is set. */
#define CTL_19_LOWPOWER_AUTO_ENABLE_AUTOEN 0x01000000
/** Adjustment value for PHY write timing.
    Adjusts the relative timing between DFI write commands and the dfi_wrdata_en signal to conform to PHY timing requirements. When this parameter is programmed to 0x0, dfi_wrdata_en will assert on the same cycle as the dfi_address. */
#define CTL_19_WRLAT_ADJ_MASK 0x000F0000
/** field offset */
#define CTL_19_WRLAT_ADJ_OFFSET 16
/** DRAM WRLAT parameter in cycles.
    Defines the write latency from when the write command is issued to the time the write data is presented to the DRAM devices, in cycles. Note: This parameter must be set to 0x1 when the Denali Databahn Memory Controller is used in DDR1 mode. */
#define CTL_19_WRLAT_MASK 0x00000F00
/** field offset */
#define CTL_19_WRLAT_OFFSET 8
/** DRAM TWTR parameter in cycles.
    Sets the number of cycles needed to switch from a write to a read operation, as dictated by the DDR SDRAM specification. */
#define CTL_19_TWTR_MASK 0x0000000F
/** field offset */
#define CTL_19_TWTR_OFFSET 0

/* Fields of "Denali CTL_20 register" */
/** DRAM TDAL parameter in cycles.
    Defines the auto pre-charge write recovery time when auto pre-charge is enabled (ap is set), in cycles. This is defined internally as tRP (pre-charge time) + auto precharge write recovery time. Not all memories use this parameter. If tDAL is defined in the memory specification, then program this parameter to the specified value. If the memory does not specify a tDAL time, then program this parameter to tWR + tRP. DO NOT program this parameter with a value of 0x0 or the memory controller will not function properly when auto pre-charge is enabled. */
#define CTL_20_TDAL_MASK 0x1F000000
/** field offset */
#define CTL_20_TDAL_OFFSET 24
/** OCD pull-up adjust setting for DRAMs for chip select 0.
    Sets the off-chip driver (OCD) pull-up adjustment settings for the DRAM devices. The memory controller will issue OCD adjust commands to the DRAM devices during power up. Bit [4] = Increment(1) or decrement(0) OCD settings. Bits [3:0] = Number of OCD adjust commands to issue. */
#define CTL_20_OCD_ADJUST_PUP_CS_0_MASK 0x001F0000
/** field offset */
#define CTL_20_OCD_ADJUST_PUP_CS_0_OFFSET 16
/** OCD pull-down adjust setting for DRAMs for chip select 0.
    Sets the off-chip driver (OCD) pull-down adjustment settings for the DRAM devices. The memory controller will issue OCD adjust commands to the DRAM devices during power up. Bit [4] = Increment(1) or decrement(0) OCD settings. Bits [3:0] = Number of OCD adjust commands to issue. */
#define CTL_20_OCD_ADJUST_PDN_CS_0_MASK 0x00001F00
/** field offset */
#define CTL_20_OCD_ADJUST_PDN_CS_0_OFFSET 8
/** Controls entry into the low power modes.
    Enables the individual low power modes of the device. Bit [4] = Controls memory power-down mode (Mode 1). Bit [3] = Controls memory power-down with memory clock gating mode (Mode 2). Bit [2] = Controls memory self-refresh mode (Mode 3). Bit [1] = Controls memory self-refresh with memory clock gating mode (Mode 4). Bit [0] = Controls memory self-refresh with memory and controller clock gating mode (Mode 5). For all bits: */
#define CTL_20_LOWPOWER_CONTROL_MASK 0x0000001F
/** field offset */
#define CTL_20_LOWPOWER_CONTROL_OFFSET 0
/** Disable */
#define CTL_20_LOWPOWER_CONTROL_DIS 0x00000000
/** Enable */
#define CTL_20_LOWPOWER_CONTROL_EN 0x00000001

/* Fields of "Denali CTL_21 register" */
/** DRAM TWR parameter in cycles.
    Defines the DRAM write recovery time, in cycles. */
#define CTL_21_TWR_INT_MASK 0x1F000000
/** field offset */
#define CTL_21_TWR_INT_OFFSET 24
/** DRAM TRC parameter in cycles.
    Defines the DRAM period between active commands for the same bank, in cycles. */
#define CTL_21_TRC_MASK 0x001F0000
/** field offset */
#define CTL_21_TRC_OFFSET 16
/** DRAM TMRD parameter in cycles.
    Defines the minimum number of cycles required between two mode register write commands. This is the time required to complete the write operation to the mode register. */
#define CTL_21_TMRD_MASK 0x00001F00
/** field offset */
#define CTL_21_TMRD_OFFSET 8
/** DRAM TFAW parameter in cycles.
    Defines the DRAM tFAW parameter, in cycles. */
#define CTL_21_TFAW_MASK 0x0000001F
/** field offset */
#define CTL_21_TFAW_OFFSET 0

/* Fields of "Denali CTL_22 register" */
/** Status of interrupt features in the controller. READONLY
    Shows the status of all possible interrupts generated by the memory controller. The MSB is the result of a logical OR of all the lower bits. This parameter is read-only. Note: Backwards compatibility is available for register parameters across configurations. However, even with this compatibility, the individual bits, their meaning and the size of the int_status parameter may change. The int_status bits correspond to these interrupts: Bit [6] = Logical OR of all lower bits. Bit [5] = DLL unlock condition detected. Bit [4] = Indicates that a read DQS gate error occurred. Bit [3] = ODT enabled and CAS Latency 3 programmed error detected. This is an unsupported programming option. Bit [2] = DRAM initialization complete. Bit [1] = Multiple accesses outside the defined PHYSICAL memory space detected. Bit [0] = A single access outside the defined PHYSICAL memory space detected. */
#define CTL_22_INT_STATUS_MASK 0x7F000000
/** field offset */
#define CTL_22_INT_STATUS_OFFSET 24
/** Mask for controller_int signals from the INT_STATUS parameter.
    Active-high mask bits that control the value of the memory controller_int signal on the ASIC interface. Unless the user has suppressed interrupt reporting (by setting bit [6] of this parameter to 'b1), bits [5:0] of the int_mask parameter will be inverted and logically AND'ed with bits [5:0] of the int_status parameter and the result is reported on the controller_int signal. */
#define CTL_22_INT_MASK_MASK 0x007F0000
/** field offset */
#define CTL_22_INT_MASK_OFFSET 16
/** Length of cmd that caused an Out-of- Range interrupt. READ-ONLY
    Holds the length of the command that caused an out-of-range interrupt request to the memory devices. This parameter is read-only. For more information on out-of-range address checking, refer to the Other Databahn Features Chapter. */
#define CTL_22_OUT_OF_RANGE_LENGTH_MASK 0x00003F00
/** field offset */
#define CTL_22_OUT_OF_RANGE_LENGTH_OFFSET 8
/** Clear mask of the INT_STATUS parameter.
    Controls the clearing of the int_status parameter. If any of the int_ack bits are set to a '1' the corresponding bit in the int_status parameter will be set to '0' Any int_ack bits written with a '0' will not alter the corresponding bit in the int_status parameter. This parameter will always read back as '0'. */
#define CTL_22_INT_ACK_MASK 0x0000003F
/** field offset */
#define CTL_22_INT_ACK_OFFSET 0

/* Fields of "Denali CTL_23 register" */
/** DRAM TRAS_MIN parameter in cycles.
    Defines the DRAM minimum row activate time, in cycles. */
#define CTL_23_TRAS_MIN_MASK 0xFF000000
/** field offset */
#define CTL_23_TRAS_MIN_OFFSET 24
/** Number of clock cycles after MRS command and before any other command.
    Defines the number of cycles of wait time after a mode register write to any non-mode register write command. For write leveling, this is defined as the number of cycles of wait time after a MRS command to the ODT enable. */
#define CTL_23_TMOD_MASK 0x00FF0000
/** field offset */
#define CTL_23_TMOD_OFFSET 16
/** Minimum number of cycles after setting master delay in DLL until reset is released.
    Specifies the minimum number of cycles after the master delay value is programmed before the DLL reset may be asserted. */
#define CTL_23_DLL_RST_ADJ_DLY_MASK 0x0000FF00
/** field offset */
#define CTL_23_DLL_RST_ADJ_DLY_OFFSET 8
/** Number of delay elements in master DLL lock.
    Defines the actual number of delay elements used to capture one full clock cycle. This parameter is automatically updated every time a refresh operation is performed. This parameter is read-only. */
#define CTL_23_DLL_LOCK_MASK 0x000000FF
/** field offset */
#define CTL_23_DLL_LOCK_OFFSET 0

/* Fields of "Denali CTL_24 register" */
/** Data to program into memory mode register 1 for chip select 0.
    Holds the EMRS1 data written during memory initialization for chip select 0. The contents of this parameter will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. Note that the Denali Databahn Memory Controller does not support additive latency. Therefore, the user should ensure that the additive latency bits are cleared to b0. For DDR2 memories, these are bits A5:A3. Note: The user must program the same values into the A6/A2 bits of emrs1_data_0 and rtt_0. */
#define CTL_24_EMRS1_DATA_0_MASK 0x3FFF0000
/** field offset */
#define CTL_24_EMRS1_DATA_0_OFFSET 16
/** DRAM TRFC parameter in cycles.
    Defines the DRAM refresh command time, in cycles. */
#define CTL_24_TRFC_MASK 0x0000FF00
/** field offset */
#define CTL_24_TRFC_OFFSET 8
/** DRAM TRCD parameter in cycles.
    Defines the DRAM RAS to CAS delay, in cycles */
#define CTL_24_TRCD_INT_MASK 0x000000FF
/** field offset */
#define CTL_24_TRCD_INT_OFFSET 0

/* Fields of "Denali CTL_25 register" */
/** Data to program into memory mode register 2 for chip select 0.
    Holds the EMRS2 data written during memory initialization for chip select 0. The contents of this parameter will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. */
#define CTL_25_EMRS2_DATA_0_MASK 0x3FFF0000
/** field offset */
#define CTL_25_EMRS2_DATA_0_OFFSET 16
/** Data to program into memory mode register 1 for chip select 1.
    Holds the EMRS1 data written during memory initialization for chip select 1. The contents of this parameter will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. Note that the Denali Databahn Memory Controller does not support additive latency. Therefore, the user should ensure that the additive latency bits are cleared to b0. For DDR2 memories, these are bits A5:A3. Note: The user must program the same values into the A6/A2 bits of emrs1_data_1 and rtt_0. */
#define CTL_25_EMRS1_DATA_1_MASK 0x00003FFF
/** field offset */
#define CTL_25_EMRS1_DATA_1_OFFSET 0

/* Fields of "Denali CTL_26 register" */
/** Data to program into memory mode register 3 for chip select 0.
    Holds the EMRS3 data written during memory initialization for chip select 0. The contents of this parameter will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. */
#define CTL_26_EMRS3_DATA_0_MASK 0x3FFF0000
/** field offset */
#define CTL_26_EMRS3_DATA_0_OFFSET 16
/** Data to program into memory mode register 2 for chip select 1.
    Holds the EMRS2 data written during memory initialization for chip select 1. The contents of this parameter will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. */
#define CTL_26_EMRS2_DATA_1_MASK 0x00003FFF
/** field offset */
#define CTL_26_EMRS2_DATA_1_OFFSET 0

/* Fields of "Denali CTL_27 register" */
/** MRS data to program to memory mode register 0 for chip select 0.
    Holds the MRS data written during memory initialization. This mode parameter should contain the necessary MRS fields in the correct bit locations. The Denali Databahn Memory Controller ignores the programmed value of the DLL Reset bit in this parameter. An internal state machine controls this bit and only sets the DLL Reset bit during initialization. The Denali Databahn Memory Controller does not support Interleaved bursts or burst lengths other than 4. Therefore, the user should ensure that A3 is cleared to b0 and [A2:A0] are set to b010. The contents of this parameter, except the DLL Reset bit, will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. */
#define CTL_27_MRS_DATA_0_MASK 0x3FFF0000
/** field offset */
#define CTL_27_MRS_DATA_0_OFFSET 16
/** Data to program into memory mode register 3 for chip select 1.
    Holds the EMRS3 data written during memory initialization for chip select 1. The contents of this parameter will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. */
#define CTL_27_EMRS3_DATA_1_MASK 0x00003FFF
/** field offset */
#define CTL_27_EMRS3_DATA_1_OFFSET 0

/* Fields of "Denali CTL_28 register" */
/** Holds the DFI tCTRLUPD_MAX timing parameter. READ-ONLY
    Holds the DFI tctrlupd_max timing parameter. This parameter is read-only. */
#define CTL_28_TDFI_CTRLUPD_MAX_MASK 0x3FFF0000
/** field offset */
#define CTL_28_TDFI_CTRLUPD_MAX_OFFSET 16
/** MRS data to program to memory mode register 0 for chip select 1.
    Holds the MRS data written during memory initialization. This mode parameter should contain the necessary MRS fields in the correct bit locations. The Denali Databahn Memory Controller ignores the programmed value of the DLL Reset bit in this parameter. An internal state machine controls this bit and only sets the DLL Reset bit during initialization. The Denali Databahn Memory Controller does not support Interleaved bursts or burst lengths other than 4. Therefore, the user should ensure that A3 is cleared to b0 and [A2:A0] are set to b010. The contents of this parameter, except the DLL Reset bit, will be programmed into the DRAM at initialization or when the write_modereg parameter is written with a '1'. Consult the DRAM specification for the correct settings for this parameter. */
#define CTL_28_MRS_DATA_1_MASK 0x00003FFF
/** field offset */
#define CTL_28_MRS_DATA_1_OFFSET 0

/* Fields of "Denali CTL_29 register" */
/** Holds the DFI tPHYUPD_TYPE0 timing parameter. READ-ONLY
    Holds the DFI tphyupd_type0 timing parameter. This parameter is read-only. */
#define CTL_29_TDFI_PHYUPD_TYPE0_MASK 0x3FFF0000
/** field offset */
#define CTL_29_TDFI_PHYUPD_TYPE0_OFFSET 16
/** Holds the DFI tPHYUPD_RESP timing parameter. READ-ONLY
    Holds the DFI tphyupd_resp timing parameter. This parameter is read-only. */
#define CTL_29_TDFI_PHYUPD_RESP_MASK 0x00003FFF
/** field offset */
#define CTL_29_TDFI_PHYUPD_RESP_OFFSET 0

/* Fields of "Denali CTL_30 register" */
/** Minimum number of cycles required for DLL reset.
    Sets the number of cycles that the reset must be held asserted for the DLL. */
#define CTL_30_DLL_RST_DELAY_MASK 0xFFFF0000
/** field offset */
#define CTL_30_DLL_RST_DELAY_OFFSET 16
/** DRAM TREF parameter in cycles.
    Defines the DRAM cycles between refresh commands. */
#define CTL_30_TREF_MASK 0x00003FFF
/** field offset */
#define CTL_30_TREF_OFFSET 0

/* Fields of "Denali CTL_31 register" */
/** Counts idle cycles to self-refresh with memory and controller clk gating.
    Counts the number of idle cycles before memory selfrefresh with memory and controller clock gating low power mode. */
#define CTL_31_LOWPOWER_INTERNAL_CNT_MASK 0xFFFF0000
/** field offset */
#define CTL_31_LOWPOWER_INTERNAL_CNT_OFFSET 16
/** Counts idle cycles to self-refresh with memory clock gating.
    Counts the number of idle cycles before memory selfrefresh with memory clock gating low power mode. */
#define CTL_31_LOWPOWER_EXTERNAL_CNT_MASK 0x0000FFFF
/** field offset */
#define CTL_31_LOWPOWER_EXTERNAL_CNT_OFFSET 0

/* Fields of "Denali CTL_32 register" */
/** Re-Sync counter for DLL in Clock Gate Mode.
    Sets the number of cycles that the Denali Databahn Memory Controller will wait before attempting to re-lock the DLL when using the controller clock gating mode low power mode. This counter will ONLY be used in this mode, the deepest low power mode. When this counter expires, the DLL will be un-gated for at least 16 cycles during which the DLL will attempt to re-lock. After 16 cycles have elapsed and the DLL has locked, then the DLL controller clock will be gated again and the counter will reset to this value. If the DLL requires more than 16 cycles to re-lock, then the un-gated time will be longer. */
#define CTL_32_LOWPOWER_REFRESH_HOLD_MASK 0xFFFF0000
/** field offset */
#define CTL_32_LOWPOWER_REFRESH_HOLD_OFFSET 16
/** Counts idle cycles to memory powerdown.
    Counts the number of idle cycles before memory powerdown or power-down with memory clock gating low power mode. */
#define CTL_32_LOWPOWER_POWER_DOWN_CNT_MASK 0x0000FFFF
/** field offset */
#define CTL_32_LOWPOWER_POWER_DOWN_CNT_OFFSET 0

/* Fields of "Denali CTL_33 register" */
/** DRAM TCPD parameter in cycles.
    Defines the clock enable to pre-charge delay time for the DRAM devices, in cycles. */
#define CTL_33_TCPD_MASK 0xFFFF0000
/** field offset */
#define CTL_33_TCPD_OFFSET 16
/** Counts idle cycles to memory self-refresh.
    Counts the number of cycles to the next memory selfrefresh low power mode. */
#define CTL_33_LOWPOWER_SELF_REFRESH_CNT_MASK 0x0000FFFF
/** field offset */
#define CTL_33_LOWPOWER_SELF_REFRESH_CNT_OFFSET 0

/* Fields of "Denali CTL_34 register" */
/** DRAM TPDEX parameter in cycles.
    Defines the DRAM power-down exit command period, in cycles. */
#define CTL_34_TPDEX_MASK 0xFFFF0000
/** field offset */
#define CTL_34_TPDEX_OFFSET 16
/** DRAM TDLL parameter in cycles.
    Defines the DRAM DLL lock time, in cycles. */
#define CTL_34_TDLL_MASK 0x0000FFFF
/** field offset */
#define CTL_34_TDLL_OFFSET 0

/* Fields of "Denali CTL_35 register" */
/** DRAM TXSNR parameter in cycles.
    Defines the DRAM tXSNR parameter, in cycles. */
#define CTL_35_TXSNR_MASK 0xFFFF0000
/** field offset */
#define CTL_35_TXSNR_OFFSET 16
/** DRAM TRAS_MAX parameter in cycles.
    Defines the DRAM maximum row active time, in cycles. */
#define CTL_35_TRAS_MAX_MASK 0x0000FFFF
/** field offset */
#define CTL_35_TRAS_MAX_OFFSET 0

/* Fields of "Denali CTL_36 register" */
/** Controller version number. READONLY
    Holds the Denali version number for this controller. This parameter is read-only. */
#define CTL_36_VERSION_MASK 0xFFFF0000
/** field offset */
#define CTL_36_VERSION_OFFSET 16
/** DRAM TXSR parameter in cycles.
    Defines the DRAM self-refresh exit time, in cycles. */
#define CTL_36_TXSR_MASK 0x0000FFFF
/** field offset */
#define CTL_36_TXSR_OFFSET 0

/* Fields of "Denali CTL_37 register" */
/** DRAM TINIT parameter in cycles.
    Defines the DRAM initialization time, in cycles. */
#define CTL_37_TINIT_MASK 0x00FFFFFF
/** field offset */
#define CTL_37_TINIT_OFFSET 0

/* Fields of "Denali CTL_38 register" */
/** Enables the PHY testing mode.
    Enables the PHY testing mode. Bits [2:1] are used: Bits [2:1] = b10 = Normal Mode, Bits [2:1] = b01 = Scan Mode. Currently Not Functional */
#define CTL_38_DFT_CTRL_REG_MASK 0xFFFFFFFF
/** field offset */
#define CTL_38_DFT_CTRL_REG_OFFSET 0

/* Fields of "Denali CTL_39 register" */
/** DLL Bypass Control */
#define CTL_39_DLL_BYP_CTRL 0x10000000
/* Normal operational mode. In this mode, the DLL uses CTL_39.DLLN_DQS_DEL for the read DQS and CTL_43.DLLN_CLK_WR for clk_wr.
#define CTL_39_DLL_BYP_CTRL_DLLN 0x00000000 */
/** Bypass Mode is on. In this mode, the DLL uses CTL_39.DLLB_DQS_DEL for the read DQS and CTL_43.DLLB_CLK_WR for clk_wr. */
#define CTL_39_DLL_BYP_CTRL_DLLB 0x10000000
/** Bypass Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). */
#define CTL_39_DLLB_DQS_DEL_MASK 0x00FF0000
/** field offset */
#define CTL_39_DLLB_DQS_DEL_OFFSET 16
/** Normal Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in normal mode (DLL_BYP_CTRL= b0). Typically, this value is 1/ 4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_39_DLLN_DQS_DEL_MASK 0x0000FF00
/** field offset */
#define CTL_39_DLLN_DQS_DEL_OFFSET 8
/** DLL Start Point Control
    This value is loaded into the DLL at initialization and is the value at which the DLL will begin searching for a lock. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_39_DLLSPC_MASK 0x000000FF
/** field offset */
#define CTL_39_DLLSPC_OFFSET 0

/* Fields of "Denali CTL_40 register" */
/** DLL Bypass Control */
#define CTL_40_DLL_BYP_CTRL 0x10000000
/* Normal operational mode. In this mode, the DLL uses CTL_40.DLLN_DQS_DEL for the read DQS and CTL_44.DLLN_CLK_WR for clk_wr.
#define CTL_40_DLL_BYP_CTRL_DLLN 0x00000000 */
/** Bypass Mode is on. In this mode, the DLL uses CTL_40.DLLB_DQS_DEL for the read DQS and CTL_44.DLLB_CLK_WR for clk_wr. */
#define CTL_40_DLL_BYP_CTRL_DLLB 0x10000000
/** Bypass Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). */
#define CTL_40_DLLB_DQS_DEL_MASK 0x00FF0000
/** field offset */
#define CTL_40_DLLB_DQS_DEL_OFFSET 16
/** Normal Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in normal mode (DLL_BYP_CTRL= b0). Typically, this value is 1/ 4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_40_DLLN_DQS_DEL_MASK 0x0000FF00
/** field offset */
#define CTL_40_DLLN_DQS_DEL_OFFSET 8
/** DLL Start Point Control
    This value is loaded into the DLL at initialization and is the value at which the DLL will begin searching for a lock. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_40_DLLSPC_MASK 0x000000FF
/** field offset */
#define CTL_40_DLLSPC_OFFSET 0

/* Fields of "Denali CTL_41 register" */
/** DLL Bypass Control */
#define CTL_41_DLL_BYP_CTRL 0x10000000
/* Normal operational mode. In this mode, the DLL uses CTL_41.DLLN_DQS_DEL for the read DQS and CTL_45.DLLN_CLK_WR for clk_wr.
#define CTL_41_DLL_BYP_CTRL_DLLN 0x00000000 */
/** Bypass Mode is on. In this mode, the DLL uses CTL_41.DLLB_DQS_DEL for the read DQS and CTL_45.DLLB_CLK_WR for clk_wr. */
#define CTL_41_DLL_BYP_CTRL_DLLB 0x10000000
/** Bypass Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). */
#define CTL_41_DLLB_DQS_DEL_MASK 0x00FF0000
/** field offset */
#define CTL_41_DLLB_DQS_DEL_OFFSET 16
/** Normal Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in normal mode (DLL_BYP_CTRL= b0). Typically, this value is 1/ 4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_41_DLLN_DQS_DEL_MASK 0x0000FF00
/** field offset */
#define CTL_41_DLLN_DQS_DEL_OFFSET 8
/** DLL Start Point Control
    This value is loaded into the DLL at initialization and is the value at which the DLL will begin searching for a lock. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_41_DLLSPC_MASK 0x000000FF
/** field offset */
#define CTL_41_DLLSPC_OFFSET 0

/* Fields of "Denali CTL_42 register" */
/** DLL Bypass Control */
#define CTL_42_DLL_BYP_CTRL 0x10000000
/* Normal operational mode. In this mode, the DLL uses CTL_42.DLLN_DQS_DEL for the read DQS and CTL_46.DLLN_CLK_WR for clk_wr.
#define CTL_42_DLL_BYP_CTRL_DLLN 0x00000000 */
/** Bypass Mode is on. In this mode, the DLL uses CTL_42.DLLB_DQS_DEL for the read DQS and CTL_46.DLLB_CLK_WR for clk_wr. */
#define CTL_42_DLL_BYP_CTRL_DLLB 0x10000000
/** Bypass Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). */
#define CTL_42_DLLB_DQS_DEL_MASK 0x00FF0000
/** field offset */
#define CTL_42_DLLB_DQS_DEL_OFFSET 16
/** Normal Mode DQS Delay
    Holds the read DQS delay setting when the DLL is operating in normal mode (DLL_BYP_CTRL= b0). Typically, this value is 1/ 4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_42_DLLN_DQS_DEL_MASK 0x0000FF00
/** field offset */
#define CTL_42_DLLN_DQS_DEL_OFFSET 8
/** DLL Start Point Control
    This value is loaded into the DLL at initialization and is the value at which the DLL will begin searching for a lock. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_42_DLLSPC_MASK 0x000000FF
/** field offset */
#define CTL_42_DLLSPC_OFFSET 0

/* Fields of "Denali CTL_43 register" */
/** Bypass Mode CLK_WR Setting
    Holds the clk_wr delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_43_DLLB_CLK_WR_MASK 0x00FF0000
/** field offset */
#define CTL_43_DLLB_CLK_WR_OFFSET 16
/** Normal Mode CLK_WR Setting
    Holds the clk_wr delay setting in normal mode (DLL_BYP_CTRL= b1). Typically, this value is 3/4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_43_DLLN_CLK_WR_MASK 0x0000FF00
/** field offset */
#define CTL_43_DLLN_CLK_WR_OFFSET 8
/** DLL Increment Value
    DLL Increment Value. This sets the increment used by the DLL when searching for a lock. Denali recommends keeping this field small (around 0x4) to keep the steps gradual. */
#define CTL_43_DLLINCVAL_MASK 0x000000FF
/** field offset */
#define CTL_43_DLLINCVAL_OFFSET 0

/* Fields of "Denali CTL_44 register" */
/** Bypass Mode CLK_WR Setting
    Holds the clk_wr delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_44_DLLB_CLK_WR_MASK 0x00FF0000
/** field offset */
#define CTL_44_DLLB_CLK_WR_OFFSET 16
/** Normal Mode CLK_WR Setting
    Holds the clk_wr delay setting in normal mode (DLL_BYP_CTRL= b1). Typically, this value is 3/4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_44_DLLN_CLK_WR_MASK 0x0000FF00
/** field offset */
#define CTL_44_DLLN_CLK_WR_OFFSET 8
/** DLL Increment Value
    DLL Increment Value. This sets the increment used by the DLL when searching for a lock. Denali recommends keeping this field small (around 0x4) to keep the steps gradual. */
#define CTL_44_DLLINCVAL_MASK 0x000000FF
/** field offset */
#define CTL_44_DLLINCVAL_OFFSET 0

/* Fields of "Denali CTL_45 register" */
/** Bypass Mode CLK_WR Setting
    Holds the clk_wr delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_45_DLLB_CLK_WR_MASK 0x00FF0000
/** field offset */
#define CTL_45_DLLB_CLK_WR_OFFSET 16
/** Normal Mode CLK_WR Setting
    Holds the clk_wr delay setting in normal mode (DLL_BYP_CTRL= b1). Typically, this value is 3/4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_45_DLLN_CLK_WR_MASK 0x0000FF00
/** field offset */
#define CTL_45_DLLN_CLK_WR_OFFSET 8
/** DLL Increment Value
    DLL Increment Value. This sets the increment used by the DLL when searching for a lock. Denali recommends keeping this field small (around 0x4) to keep the steps gradual. */
#define CTL_45_DLLINCVAL_MASK 0x000000FF
/** field offset */
#define CTL_45_DLLINCVAL_OFFSET 0

/* Fields of "Denali CTL_46 register" */
/** Bypass Mode CLK_WR Setting
    Holds the clk_wr delay setting when the DLL is operating in bypass mode (DLL_BYP_CTRL= b1). Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_46_DLLB_CLK_WR_MASK 0x00FF0000
/** field offset */
#define CTL_46_DLLB_CLK_WR_OFFSET 16
/** Normal Mode CLK_WR Setting
    Holds the clk_wr delay setting in normal mode (DLL_BYP_CTRL= b1). Typically, this value is 3/4 of a clock cycle. Each increment of this field represents 1/128th of a clock cycle. */
#define CTL_46_DLLN_CLK_WR_MASK 0x0000FF00
/** field offset */
#define CTL_46_DLLN_CLK_WR_OFFSET 8
/** DLL Increment Value
    DLL Increment Value. This sets the increment used by the DLL when searching for a lock. Denali recommends keeping this field small (around 0x4) to keep the steps gradual. */
#define CTL_46_DLLINCVAL_MASK 0x000000FF
/** field offset */
#define CTL_46_DLLINCVAL_OFFSET 0

/* Fields of "Denali CTL_47 register" */
/** DLL Encoder Value
    Reports the DLL encoder value from the master DLL to the slave DLL's. The slaves use this value to set up their delays for the clk_wr and read DQS signals. */
#define CTL_47_DLL_ENCVAL_MASK 0xFFFFFFFE
/** field offset */
#define CTL_47_DLL_ENCVAL_OFFSET 1
/** DLL Lock Indicator */
#define CTL_47_DLL_LOCK 0x00000001
/* DLL has not locked.
#define CTL_47_DLL_LOCK_NLOCK 0x00000000 */
/** DLL is locked. */
#define CTL_47_DLL_LOCK_LOCK 0x00000001

/* Fields of "Denali CTL_48 register" */
/** DLL Encoder Value
    Reports the DLL encoder value from the master DLL to the slave DLL's. The slaves use this value to set up their delays for the clk_wr and read DQS signals. */
#define CTL_48_DLL_ENCVAL_MASK 0xFFFFFFFE
/** field offset */
#define CTL_48_DLL_ENCVAL_OFFSET 1
/** DLL Lock Indicator */
#define CTL_48_DLL_LOCK 0x00000001
/* DLL has not locked.
#define CTL_48_DLL_LOCK_NLOCK 0x00000000 */
/** DLL is locked. */
#define CTL_48_DLL_LOCK_LOCK 0x00000001

/* Fields of "Denali CTL_49 register" */
/** DLL Encoder Value
    Reports the DLL encoder value from the master DLL to the slave DLL's. The slaves use this value to set up their delays for the clk_wr and read DQS signals. */
#define CTL_49_DLL_ENCVAL_MASK 0xFFFFFFFE
/** field offset */
#define CTL_49_DLL_ENCVAL_OFFSET 1
/** DLL Lock Indicator */
#define CTL_49_DLL_LOCK 0x00000001
/* DLL has not locked.
#define CTL_49_DLL_LOCK_NLOCK 0x00000000 */
/** DLL is locked. */
#define CTL_49_DLL_LOCK_LOCK 0x00000001

/* Fields of "Denali CTL_50 register" */
/** DLL Encoder Value
    Reports the DLL encoder value from the master DLL to the slave DLL's. The slaves use this value to set up their delays for the clk_wr and read DQS signals. */
#define CTL_50_DLL_ENCVAL_MASK 0xFFFFFFFE
/** field offset */
#define CTL_50_DLL_ENCVAL_OFFSET 1
/** DLL Lock Indicator */
#define CTL_50_DLL_LOCK 0x00000001
/* DLL has not locked.
#define CTL_50_DLL_LOCK_NLOCK 0x00000000 */
/** DLL is locked. */
#define CTL_50_DLL_LOCK_LOCK 0x00000001

/* Fields of "Denali CTL_51 register" */
/** Address of cmd that caused an Out-of- Range interrupt. READ-ONLY
    Holds the address of the command that caused an out-of-range interrupt request to the memory devices. This parameter is read-only. For more information on out-of-range address checking, refer to the Other Databahn Features Chapter. */
#define CTL_51_OUT_OF_RANGE_ADDR_MASK 0xFFFFFFFF
/** field offset */
#define CTL_51_OUT_OF_RANGE_ADDR_OFFSET 0

/* Fields of "Denali CTL_52 register" */
/** Pad Impedance
    Defines the pad impedance if the parallel termination option is enabled. */
#define CTL_52_PADIMP 0x00001000
/* 75 Ohm
#define CTL_52_PADIMP_PAD75 0x00000000 */
/** 150 Ohm */
#define CTL_52_PADIMP_PAD150 0x00001000
/** Pad Type */
#define CTL_52_PADTYPE 0x00000100
/* 75 Ohm
#define CTL_52_PADTYPE_PADDDR1 0x00000000 */
/** 150 Ohm */
#define CTL_52_PADTYPE_PADDDR2 0x00000100
/** IDDQ_RX Select Signals
    Defines the IDDQ_RX select for the signal pads. */
#define CTL_52_IDDQ_RX_SIG 0x00000020
/* Do not feed input into IDDQ
#define CTL_52_IDDQ_RX_SIG_NINIDDQ 0x00000000 */
/** Feed input into IDDQ */
#define CTL_52_IDDQ_RX_SIG_INIDDQ 0x00000020
/** IDDQ_TX Select Signals
    Defines the IDDQ_TX select for the signal pads. */
#define CTL_52_IDDQ_TX_SIG 0x00000010
/* Do not feed output into IDDQ
#define CTL_52_IDDQ_TX_SIG_NOUTIDDQ 0x00000000 */
/** Feed output into IDDQ */
#define CTL_52_IDDQ_TX_SIG_OUTIDDQ 0x00000010
/** IDDQ_RX Select Clocks
    Defines the IDDQ_RX select for the clock pads. */
#define CTL_52_IDDQ_RX_CLK 0x00000002
/* Do not feed input into IDDQ
#define CTL_52_IDDQ_RX_CLK_NINIDDQ 0x00000000 */
/** Feed input into IDDQ */
#define CTL_52_IDDQ_RX_CLK_INIDDQ 0x00000002
/** IDDQ_TX Select Clocks
    Defines the IDDQ_TX select for the clock pads. */
#define CTL_52_IDDQ_TX_CLK 0x00000001
/* Do not feed output into IDDQ
#define CTL_52_IDDQ_TX_CLK_NOUTIDDQ 0x00000000 */
/** Feed output into IDDQ */
#define CTL_52_IDDQ_TX_CLK_OUTIDDQ 0x00000001

/* Fields of "Denali CTL_53 register" */
/** Dynamic On-Die Termination DataMask Enable
    Enables/disables dynamic on-die termination for the DataMask pads in the PHY. */
#define CTL_53_ODT_DM_EN 0x80000000
/* Disable
#define CTL_53_ODT_DM_EN_DIS 0x00000000 */
/** Enable */
#define CTL_53_ODT_DM_EN_EN 0x80000000
/** Dynamic On-Die Termination Data Mask Disable
    Disables dynamic on-die termination for the DataMask pads in the PHY. Note: This control bit is set according to the DQ:DQS ratio. In case x8 organized DDR SDRAM devices are connected, this bit is set to 1B and causes the ODT feature to be disabled for date mask signals. This is independent of control bit ODT_DM_EN. */
#define CTL_53_ODT_DM_DIS 0x20000000
/* Enabled
#define CTL_53_ODT_DM_DIS_ODT_DM_EN 0x00000000 */
/** Echo Gate Control
    Echo gate control for data slice 0 */
#define CTL_53_EGC 0x10000000
/* Uses the dfi_rddata_en signal to create a gate
#define CTL_53_EGC_DFI 0x00000000 */
/** Creates an echo gate signal. */
#define CTL_53_EGC_CRT 0x10000000
/** Gather FIFO Enable */
#define CTL_53_GFEN 0x08000000
/* Disable
#define CTL_53_GFEN_DIS 0x00000000 */
/** Enable */
#define CTL_53_GFEN_EN 0x08000000
/** Read Data Delay
    Defines the read data delay. Holds the number of cycles to delay the dfi_rddata_en signal prior to enabling the read FIFO. After this delay, the read pointers begin incrementing the read FIFO. */
#define CTL_53_RDD_MASK 0x07000000
/** field offset */
#define CTL_53_RDD_OFFSET 24
/** DQS and DQ Pad Output Enable Polarity
    Sets the pad output enable polarity for the data slices. */
#define CTL_53_OEPOL 0x00100000
/* OEN pad
#define CTL_53_OEPOL_OEN 0x00000000 */
/** OE pad */
#define CTL_53_OEPOL_OE 0x00100000
/** Adjust Read DQS Gate
    Enables the adjustment of the read DQS gate by 1/2 cycle. */
#define CTL_53_ENGTADJ 0x00010000
/* Disable
#define CTL_53_ENGTADJ_DIS 0x00000000 */
/** Enable */
#define CTL_53_ENGTADJ_EN 0x00010000
/** Adjust Starting Point of DQS Output Enable Window
    Adjusts the starting point of the DQS pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_53_DQS_START_OE_MASK 0x00007000
/** field offset */
#define CTL_53_DQS_START_OE_OFFSET 12
/** Adjust Ending Point of DQS Output Enable Window
    Adjusts the ending point of the DQS pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_53_DQS_END_OE_MASK 0x00000700
/** field offset */
#define CTL_53_DQS_END_OE_OFFSET 8
/** Adjust Starting Point of DQ Output Enable Window
    Adjusts the starting point of the DQ pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_53_DQ_START_OE_MASK 0x00000070
/** field offset */
#define CTL_53_DQ_START_OE_OFFSET 4
/** Adjust Ending Point of DQ Output Enable Window
    Adjusts the ending point of the DQ pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_53_DQ_END_OE_MASK 0x00000007
/** field offset */
#define CTL_53_DQ_END_OE_OFFSET 0

/* Fields of "Denali CTL_54 register" */
/** Dynamic On-Die Termination DataMask Enable
    Enables/disables dynamic on-die termination for the DataMask pads in the PHY. */
#define CTL_54_ODT_DM_EN 0x80000000
/* Disable
#define CTL_54_ODT_DM_EN_DIS 0x00000000 */
/** Enable */
#define CTL_54_ODT_DM_EN_EN 0x80000000
/** Dynamic On-Die Termination Data Mask Disable
    Disables dynamic on-die termination for the DataMask pads in the PHY. Note: This control bit is set according to the DQ:DQS ratio. In case x8 organized DDR SDRAM devices are connected, this bit is set to 1B and causes the ODT feature to be disabled for date mask signals. This is independent of control bit ODT_DM_EN. */
#define CTL_54_ODT_DM_DIS 0x20000000
/* Enabled
#define CTL_54_ODT_DM_DIS_ODT_DM_EN 0x00000000 */
/** Echo Gate Control
    Echo gate control for data slice 1 */
#define CTL_54_EGC 0x10000000
/* Uses the dfi_rddata_en signal to create a gate
#define CTL_54_EGC_DFI 0x00000000 */
/** Creates an echo gate signal. */
#define CTL_54_EGC_CRT 0x10000000
/** Gather FIFO Enable */
#define CTL_54_GFEN 0x08000000
/* Disable
#define CTL_54_GFEN_DIS 0x00000000 */
/** Enable */
#define CTL_54_GFEN_EN 0x08000000
/** Read Data Delay
    Defines the read data delay. Holds the number of cycles to delay the dfi_rddata_en signal prior to enabling the read FIFO. After this delay, the read pointers begin incrementing the read FIFO. */
#define CTL_54_RDD_MASK 0x07000000
/** field offset */
#define CTL_54_RDD_OFFSET 24
/** DQS and DQ Pad Output Enable Polarity
    Sets the pad output enable polarity for the data slices. */
#define CTL_54_OEPOL 0x00100000
/* OEN pad
#define CTL_54_OEPOL_OEN 0x00000000 */
/** OE pad */
#define CTL_54_OEPOL_OE 0x00100000
/** Adjust Read DQS Gate
    Enables the adjustment of the read DQS gate by 1/2 cycle. */
#define CTL_54_ENGTADJ 0x00010000
/* Disable
#define CTL_54_ENGTADJ_DIS 0x00000000 */
/** Enable */
#define CTL_54_ENGTADJ_EN 0x00010000
/** Adjust Starting Point of DQS Output Enable Window
    Adjusts the starting point of the DQS pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_54_DQS_START_OE_MASK 0x00007000
/** field offset */
#define CTL_54_DQS_START_OE_OFFSET 12
/** Adjust Ending Point of DQS Output Enable Window
    Adjusts the ending point of the DQS pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_54_DQS_END_OE_MASK 0x00000700
/** field offset */
#define CTL_54_DQS_END_OE_OFFSET 8
/** Adjust Starting Point of DQ Output Enable Window
    Adjusts the starting point of the DQ pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_54_DQ_START_OE_MASK 0x00000070
/** field offset */
#define CTL_54_DQ_START_OE_OFFSET 4
/** Adjust Ending Point of DQ Output Enable Window
    Adjusts the ending point of the DQ pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_54_DQ_END_OE_MASK 0x00000007
/** field offset */
#define CTL_54_DQ_END_OE_OFFSET 0

/* Fields of "Denali CTL_55 register" */
/** Dynamic On-Die Termination DataMask Enable
    Enables/disables dynamic on-die termination for the DataMask pads in the PHY. */
#define CTL_55_ODT_DM_EN 0x80000000
/* Disable
#define CTL_55_ODT_DM_EN_DIS 0x00000000 */
/** Enable */
#define CTL_55_ODT_DM_EN_EN 0x80000000
/** Dynamic On-Die Termination Data Mask Disable
    Disables dynamic on-die termination for the DataMask pads in the PHY. Note: This control bit is set according to the DQ:DQS ratio. In case x8 organized DDR SDRAM devices are connected, this bit is set to 1B and causes the ODT feature to be disabled for date mask signals. This is independent of control bit ODT_DM_EN. */
#define CTL_55_ODT_DM_DIS 0x20000000
/* Enabled
#define CTL_55_ODT_DM_DIS_ODT_DM_EN 0x00000000 */
/** Echo Gate Control
    Echo gate control for data slice 2 */
#define CTL_55_EGC 0x10000000
/* Uses the dfi_rddata_en signal to create a gate
#define CTL_55_EGC_DFI 0x00000000 */
/** Creates an echo gate signal. */
#define CTL_55_EGC_CRT 0x10000000
/** Gather FIFO Enable */
#define CTL_55_GFEN 0x08000000
/* Disable
#define CTL_55_GFEN_DIS 0x00000000 */
/** Enable */
#define CTL_55_GFEN_EN 0x08000000
/** Read Data Delay
    Defines the read data delay. Holds the number of cycles to delay the dfi_rddata_en signal prior to enabling the read FIFO. After this delay, the read pointers begin incrementing the read FIFO. */
#define CTL_55_RDD_MASK 0x07000000
/** field offset */
#define CTL_55_RDD_OFFSET 24
/** DQS and DQ Pad Output Enable Polarity
    Sets the pad output enable polarity for the data slices. */
#define CTL_55_OEPOL 0x00100000
/* OEN pad
#define CTL_55_OEPOL_OEN 0x00000000 */
/** OE pad */
#define CTL_55_OEPOL_OE 0x00100000
/** Adjust Read DQS Gate
    Enables the adjustment of the read DQS gate by 1/2 cycle. */
#define CTL_55_ENGTADJ 0x00010000
/* Disable
#define CTL_55_ENGTADJ_DIS 0x00000000 */
/** Enable */
#define CTL_55_ENGTADJ_EN 0x00010000
/** Adjust Starting Point of DQS Output Enable Window
    Adjusts the starting point of the DQS pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_55_DQS_START_OE_MASK 0x00007000
/** field offset */
#define CTL_55_DQS_START_OE_OFFSET 12
/** Adjust Ending Point of DQS Output Enable Window
    Adjusts the ending point of the DQS pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_55_DQS_END_OE_MASK 0x00000700
/** field offset */
#define CTL_55_DQS_END_OE_OFFSET 8
/** Adjust Starting Point of DQ Output Enable Window
    Adjusts the starting point of the DQ pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_55_DQ_START_OE_MASK 0x00000070
/** field offset */
#define CTL_55_DQ_START_OE_OFFSET 4
/** Adjust Ending Point of DQ Output Enable Window
    Adjusts the ending point of the DQ pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_55_DQ_END_OE_MASK 0x00000007
/** field offset */
#define CTL_55_DQ_END_OE_OFFSET 0

/* Fields of "Denali CTL_56 register" */
/** Dynamic On-Die Termination DataMask Enable
    Enables/disables dynamic on-die termination for the DataMask pads in the PHY. */
#define CTL_56_ODT_DM_EN 0x80000000
/* Disable
#define CTL_56_ODT_DM_EN_DIS 0x00000000 */
/** Enable */
#define CTL_56_ODT_DM_EN_EN 0x80000000
/** Dynamic On-Die Termination Data Mask Disable
    Disables dynamic on-die termination for the DataMask pads in the PHY. Note: This control bit is set according to the DQ:DQS ratio. In case x8 organized DDR SDRAM devices are connected, this bit is set to 1B and causes the ODT feature to be disabled for date mask signals. This is independent of control bit ODT_DM_EN. */
#define CTL_56_ODT_DM_DIS 0x20000000
/* Enabled
#define CTL_56_ODT_DM_DIS_ODT_DM_EN 0x00000000 */
/** Echo Gate Control
    Echo gate control for data slice 3 */
#define CTL_56_EGC 0x10000000
/* Uses the dfi_rddata_en signal to create a gate
#define CTL_56_EGC_DFI 0x00000000 */
/** Creates an echo gate signal. */
#define CTL_56_EGC_CRT 0x10000000
/** Gather FIFO Enable */
#define CTL_56_GFEN 0x08000000
/* Disable
#define CTL_56_GFEN_DIS 0x00000000 */
/** Enable */
#define CTL_56_GFEN_EN 0x08000000
/** Read Data Delay
    Defines the read data delay. Holds the number of cycles to delay the dfi_rddata_en signal prior to enabling the read FIFO. After this delay, the read pointers begin incrementing the read FIFO. */
#define CTL_56_RDD_MASK 0x07000000
/** field offset */
#define CTL_56_RDD_OFFSET 24
/** DQS and DQ Pad Output Enable Polarity
    Sets the pad output enable polarity for the data slices. */
#define CTL_56_OEPOL 0x00100000
/* OEN pad
#define CTL_56_OEPOL_OEN 0x00000000 */
/** OE pad */
#define CTL_56_OEPOL_OE 0x00100000
/** Adjust Read DQS Gate
    Enables the adjustment of the read DQS gate by 1/2 cycle. */
#define CTL_56_ENGTADJ 0x00010000
/* Disable
#define CTL_56_ENGTADJ_DIS 0x00000000 */
/** Enable */
#define CTL_56_ENGTADJ_EN 0x00010000
/** Adjust Starting Point of DQS Output Enable Window
    Adjusts the starting point of the DQS pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_56_DQS_START_OE_MASK 0x00007000
/** field offset */
#define CTL_56_DQS_START_OE_OFFSET 12
/** Adjust Ending Point of DQS Output Enable Window
    Adjusts the ending point of the DQS pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_56_DQS_END_OE_MASK 0x00000700
/** field offset */
#define CTL_56_DQS_END_OE_OFFSET 8
/** Adjust Starting Point of DQ Output Enable Window
    Adjusts the starting point of the DQ pad output enable window. Lower numbers pull the rising edge earlier in time, and larger numbers cause the rising edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_56_DQ_START_OE_MASK 0x00000070
/** field offset */
#define CTL_56_DQ_START_OE_OFFSET 4
/** Adjust Ending Point of DQ Output Enable Window
    Adjusts the ending point of the DQ pad output enable window. Lower numbers pull the falling edge earlier in time, and larger numbers cause the falling edge to be delayed. Each bit changes the output enable time by a 1/4 cycle resolution. */
#define CTL_56_DQ_END_OE_MASK 0x00000007
/** field offset */
#define CTL_56_DQ_END_OE_OFFSET 0

/* Fields of "Denali CTL_57 register" */
/** Dynamic On-Die Termination Enable Time
    Defines the dynamic on-die termination enable time. Larger values add greater delay to when signal tsel turns on. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_57_ODT_ENT_MASK 0xF0000000
/** field offset */
#define CTL_57_ODT_ENT_OFFSET 28
/** Dynamic On-Die Termination Disable Time
    Defines the dynamic on-die termination disable time. Larger values reduce the delay to when signal tsel turns off. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_57_ODT_DIST_MASK 0x0F000000
/** field offset */
#define CTL_57_ODT_DIST_OFFSET 24
/** Dynamic On-Die Termination Enable
    Enables/disables dynamic on-die termination in the PHY. This bit must be set to allow dynamic on-die termination options to be used. */
#define CTL_57_ODT_EN 0x00800000
/* Disable
#define CTL_57_ODT_EN_DIS 0x00000000 */
/** Enable */
#define CTL_57_ODT_EN_EN 0x00800000
/** Dynamic On-Die Termination Polarity of TSEL
    Controls the polarity of signal tsel for the data bus, the strobe signals and the data mask signals in the PHY. */
#define CTL_57_ODT_PTSEL 0x00400000
/* Negative Polarity
#define CTL_57_ODT_PTSEL_NEG 0x00000000 */
/** Positive Polarity */
#define CTL_57_ODT_PTSEL_POS 0x00400000
/** Trigger Data Return
    Triggers a data return (loopback data on the dfi_rddata signal) to the DDR SDRAM Controller. */
#define CTL_57_TDR 0x00200000
/* No-Operation
#define CTL_57_TDR_NOP 0x00000000 */
/** Trigger */
#define CTL_57_TDR_TRIG 0x00200000
/** Loopback Data Output Type
    Selects data output type to either the actual data or expected data for bit field CTL_62.LPBKDATA */
#define CTL_57_LPBKDOT 0x00100000
/* Return the expected data
#define CTL_57_LPBKDOT_LPBKEXP 0x00000000 */
/** Return the actual data */
#define CTL_57_LPBKDOT_LPBKACT 0x00100000
/** Loopback Control
    Selects the different options in loopback mode. */
#define CTL_57_LPBKCTRL_MASK 0x000C0000
/** field offset */
#define CTL_57_LPBKCTRL_OFFSET 18
/** Normal operational mode */
#define CTL_57_LPBKCTRL_LPBKN 0x00000000
/** Enables loopback write mode */
#define CTL_57_LPBKCTRL_LPBKW 0x00040000
/** Stop loopback to check the error register */
#define CTL_57_LPBKCTRL_LPBKST 0x00080000
/** Clear loopback registers */
#define CTL_57_LPBKCTRL_LPBKC 0x000C0000
/** Loopback Read MUX
    Controls the loopback read multiplexer. */
#define CTL_57_LPBKRM 0x00020000
/** Loopback Write MUX
    Controls the loopback write multiplexer. */
#define CTL_57_LPBKWM 0x00010000
/** Loopback LFSR to Error Checking Logic Delay
    Sets the cycle delay between the Linear Feedback Shift Register (LFSR) and loopback error check logic. */
#define CTL_57_LPBKLFSRECLD_MASK 0x00007000
/** field offset */
#define CTL_57_LPBKLFSRECLD_OFFSET 12
/** Read DQS Gate Close Configuration
    This bit is used to delay the read DQS gate close logic in the DDR SDRAM PHY. This bit should be set to b1 if the DDR SDRAM controller is running in echo gate mode (CTL_53.EGC = b1) and the echo delay (pad_out + pad_in + flight + flight + tdqsck_max) 2 cycles. */
#define CTL_57_DQS_GATE_CLOSE_CFG 0x00000800
/** Stretch Trailing Edge of DFI Read Data Enable
    This bit field stretches the trailing edge of dfi_rddata_en for closing the read DQS gate */
#define CTL_57_STRTREGT_MASK 0x00000700
/** field offset */
#define CTL_57_STRTREGT_OFFSET 8
/** Read DQS Gate Opening
    This bit field controls, when the read DQS gate opens. This value is the number of cycles to delay the dfi_rddata_en signal prior to opening the read DQS gate. */
#define CTL_57_DQS_GATE_OPEN_MASK 0x000000FF
/** field offset */
#define CTL_57_DQS_GATE_OPEN_OFFSET 0

/* Fields of "Denali CTL_58 register" */
/** Dynamic On-Die Termination Enable Time
    Defines the dynamic on-die termination enable time. Larger values add greater delay to when signal tsel turns on. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_58_ODT_ENT_MASK 0xF0000000
/** field offset */
#define CTL_58_ODT_ENT_OFFSET 28
/** Dynamic On-Die Termination Disable Time
    Defines the dynamic on-die termination disable time. Larger values reduce the delay to when signal tsel turns off. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_58_ODT_DIST_MASK 0x0F000000
/** field offset */
#define CTL_58_ODT_DIST_OFFSET 24
/** Dynamic On-Die Termination Enable
    Enables/disables dynamic on-die termination in the PHY. This bit must be set to allow dynamic on-die termination options to be used. */
#define CTL_58_ODT_EN 0x00800000
/* Disable
#define CTL_58_ODT_EN_DIS 0x00000000 */
/** Enable */
#define CTL_58_ODT_EN_EN 0x00800000
/** Dynamic On-Die Termination Polarity of TSEL
    Controls the polarity of signal tsel for the data bus, the strobe signals and the data mask signals in the PHY. */
#define CTL_58_ODT_PTSEL 0x00400000
/* Negative Polarity
#define CTL_58_ODT_PTSEL_NEG 0x00000000 */
/** Positive Polarity */
#define CTL_58_ODT_PTSEL_POS 0x00400000
/** Trigger Data Return
    Triggers a data return (loopback data on the dfi_rddata signal) to the DDR SDRAM Controller. */
#define CTL_58_TDR 0x00200000
/* No-Operation
#define CTL_58_TDR_NOP 0x00000000 */
/** Trigger */
#define CTL_58_TDR_TRIG 0x00200000
/** Loopback Data Output Type
    Selects data output type to either the actual data or expected data for bit field CTL_63.LPBKDATA */
#define CTL_58_LPBKDOT 0x00100000
/* Return the expected data
#define CTL_58_LPBKDOT_LPBKEXP 0x00000000 */
/** Return the actual data */
#define CTL_58_LPBKDOT_LPBKACT 0x00100000
/** Loopback Control
    Selects the different options in loopback mode. */
#define CTL_58_LPBKCTRL_MASK 0x000C0000
/** field offset */
#define CTL_58_LPBKCTRL_OFFSET 18
/** Normal operational mode */
#define CTL_58_LPBKCTRL_LPBKN 0x00000000
/** Enables loopback write mode */
#define CTL_58_LPBKCTRL_LPBKW 0x00040000
/** Stop loopback to check the error register */
#define CTL_58_LPBKCTRL_LPBKST 0x00080000
/** Clear loopback registers */
#define CTL_58_LPBKCTRL_LPBKC 0x000C0000
/** Loopback Read MUX
    Controls the loopback read multiplexer. */
#define CTL_58_LPBKRM 0x00020000
/** Loopback Write MUX
    Controls the loopback write multiplexer. */
#define CTL_58_LPBKWM 0x00010000
/** Loopback LFSR to Error Checking Logic Delay
    Sets the cycle delay between the Linear Feedback Shift Register (LFSR) and loopback error check logic. */
#define CTL_58_LPBKLFSRECLD_MASK 0x00007000
/** field offset */
#define CTL_58_LPBKLFSRECLD_OFFSET 12
/** Read DQS Gate Close Configuration
    This bit is used to delay the read DQS gate close logic in the DDR SDRAM PHY. This bit should be set to b1 if the DDR SDRAM controller is running in echo gate mode (CTL_53.EGC = b1) and the echo delay (pad_out + pad_in + flight + flight + tdqsck_max) 2 cycles. */
#define CTL_58_DQS_GATE_CLOSE_CFG 0x00000800
/** Stretch Trailing Edge of DFI Read Data Enable
    This bit field stretches the trailing edge of dfi_rddata_en for closing the read DQS gate */
#define CTL_58_STRTREGT_MASK 0x00000700
/** field offset */
#define CTL_58_STRTREGT_OFFSET 8
/** Read DQS Gate Opening
    This bit field controls, when the read DQS gate opens. This value is the number of cycles to delay the dfi_rddata_en signal prior to opening the read DQS gate. */
#define CTL_58_DQS_GATE_OPEN_MASK 0x000000FF
/** field offset */
#define CTL_58_DQS_GATE_OPEN_OFFSET 0

/* Fields of "Denali CTL_59 register" */
/** Dynamic On-Die Termination Enable Time
    Defines the dynamic on-die termination enable time. Larger values add greater delay to when signal tsel turns on. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_59_ODT_ENT_MASK 0xF0000000
/** field offset */
#define CTL_59_ODT_ENT_OFFSET 28
/** Dynamic On-Die Termination Disable Time
    Defines the dynamic on-die termination disable time. Larger values reduce the delay to when signal tsel turns off. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_59_ODT_DIST_MASK 0x0F000000
/** field offset */
#define CTL_59_ODT_DIST_OFFSET 24
/** Dynamic On-Die Termination Enable
    Enables/disables dynamic on-die termination in the PHY. This bit must be set to allow dynamic on-die termination options to be used. */
#define CTL_59_ODT_EN 0x00800000
/* Disable
#define CTL_59_ODT_EN_DIS 0x00000000 */
/** Enable */
#define CTL_59_ODT_EN_EN 0x00800000
/** Dynamic On-Die Termination Polarity of TSEL
    Controls the polarity of signal tsel for the data bus, the strobe signals and the data mask signals in the PHY. */
#define CTL_59_ODT_PTSEL 0x00400000
/* Negative Polarity
#define CTL_59_ODT_PTSEL_NEG 0x00000000 */
/** Positive Polarity */
#define CTL_59_ODT_PTSEL_POS 0x00400000
/** Trigger Data Return
    Triggers a data return (loopback data on the dfi_rddata signal) to the DDR SDRAM Controller. */
#define CTL_59_TDR 0x00200000
/* No-Operation
#define CTL_59_TDR_NOP 0x00000000 */
/** Trigger */
#define CTL_59_TDR_TRIG 0x00200000
/** Loopback Data Output Type
    Selects data output type to either the actual data or expected data for bit field CTL_64.LPBKDATA */
#define CTL_59_LPBKDOT 0x00100000
/* Return the expected data
#define CTL_59_LPBKDOT_LPBKEXP 0x00000000 */
/** Return the actual data */
#define CTL_59_LPBKDOT_LPBKACT 0x00100000
/** Loopback Control
    Selects the different options in loopback mode. */
#define CTL_59_LPBKCTRL_MASK 0x000C0000
/** field offset */
#define CTL_59_LPBKCTRL_OFFSET 18
/** Normal operational mode */
#define CTL_59_LPBKCTRL_LPBKN 0x00000000
/** Enables loopback write mode */
#define CTL_59_LPBKCTRL_LPBKW 0x00040000
/** Stop loopback to check the error register */
#define CTL_59_LPBKCTRL_LPBKST 0x00080000
/** Clear loopback registers */
#define CTL_59_LPBKCTRL_LPBKC 0x000C0000
/** Loopback Read MUX
    Controls the loopback read multiplexer. */
#define CTL_59_LPBKRM 0x00020000
/** Loopback Write MUX
    Controls the loopback write multiplexer. */
#define CTL_59_LPBKWM 0x00010000
/** Loopback LFSR to Error Checking Logic Delay
    Sets the cycle delay between the Linear Feedback Shift Register (LFSR) and loopback error check logic. */
#define CTL_59_LPBKLFSRECLD_MASK 0x00007000
/** field offset */
#define CTL_59_LPBKLFSRECLD_OFFSET 12
/** Read DQS Gate Close Configuration
    This bit is used to delay the read DQS gate close logic in the DDR SDRAM PHY. This bit should be set to b1 if the DDR SDRAM controller is running in echo gate mode (CTL_53.EGC = b1) and the echo delay (pad_out + pad_in + flight + flight + tdqsck_max) 2 cycles. */
#define CTL_59_DQS_GATE_CLOSE_CFG 0x00000800
/** Stretch Trailing Edge of DFI Read Data Enable
    This bit field stretches the trailing edge of dfi_rddata_en for closing the read DQS gate */
#define CTL_59_STRTREGT_MASK 0x00000700
/** field offset */
#define CTL_59_STRTREGT_OFFSET 8
/** Read DQS Gate Opening
    This bit field controls, when the read DQS gate opens. This value is the number of cycles to delay the dfi_rddata_en signal prior to opening the read DQS gate. */
#define CTL_59_DQS_GATE_OPEN_MASK 0x000000FF
/** field offset */
#define CTL_59_DQS_GATE_OPEN_OFFSET 0

/* Fields of "Denali CTL_60 register" */
/** Dynamic On-Die Termination Enable Time
    Defines the dynamic on-die termination enable time. Larger values add greater delay to when signal tsel turns on. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_60_ODT_ENT_MASK 0xF0000000
/** field offset */
#define CTL_60_ODT_ENT_OFFSET 28
/** Dynamic On-Die Termination Disable Time
    Defines the dynamic on-die termination disable time. Larger values reduce the delay to when signal tsel turns off. Each bit changes the output enable time by a 1/2 cycle resolution. */
#define CTL_60_ODT_DIST_MASK 0x0F000000
/** field offset */
#define CTL_60_ODT_DIST_OFFSET 24
/** Dynamic On-Die Termination Enable
    Enables/disables dynamic on-die termination in the PHY. This bit must be set to allow dynamic on-die termination options to be used. */
#define CTL_60_ODT_EN 0x00800000
/* Disable
#define CTL_60_ODT_EN_DIS 0x00000000 */
/** Enable */
#define CTL_60_ODT_EN_EN 0x00800000
/** Dynamic On-Die Termination Polarity of TSEL
    Controls the polarity of signal tsel for the data bus, the strobe signals and the data mask signals in the PHY. */
#define CTL_60_ODT_PTSEL 0x00400000
/* Negative Polarity
#define CTL_60_ODT_PTSEL_NEG 0x00000000 */
/** Positive Polarity */
#define CTL_60_ODT_PTSEL_POS 0x00400000
/** Trigger Data Return
    Triggers a data return (loopback data on the dfi_rddata signal) to the DDR SDRAM Controller. */
#define CTL_60_TDR 0x00200000
/* No-Operation
#define CTL_60_TDR_NOP 0x00000000 */
/** Trigger */
#define CTL_60_TDR_TRIG 0x00200000
/** Loopback Data Output Type
    Selects data output type to either the actual data or expected data for bit field CTL_65.LPBKDATA */
#define CTL_60_LPBKDOT 0x00100000
/* Return the expected data
#define CTL_60_LPBKDOT_LPBKEXP 0x00000000 */
/** Return the actual data */
#define CTL_60_LPBKDOT_LPBKACT 0x00100000
/** Loopback Control
    Selects the different options in loopback mode. */
#define CTL_60_LPBKCTRL_MASK 0x000C0000
/** field offset */
#define CTL_60_LPBKCTRL_OFFSET 18
/** Normal operational mode */
#define CTL_60_LPBKCTRL_LPBKN 0x00000000
/** Enables loopback write mode */
#define CTL_60_LPBKCTRL_LPBKW 0x00040000
/** Stop loopback to check the error register */
#define CTL_60_LPBKCTRL_LPBKST 0x00080000
/** Clear loopback registers */
#define CTL_60_LPBKCTRL_LPBKC 0x000C0000
/** Loopback Read MUX
    Controls the loopback read multiplexer. */
#define CTL_60_LPBKRM 0x00020000
/** Loopback Write MUX
    Controls the loopback write multiplexer. */
#define CTL_60_LPBKWM 0x00010000
/** Loopback LFSR to Error Checking Logic Delay
    Sets the cycle delay between the Linear Feedback Shift Register (LFSR) and loopback error check logic. */
#define CTL_60_LPBKLFSRECLD_MASK 0x00007000
/** field offset */
#define CTL_60_LPBKLFSRECLD_OFFSET 12
/** Read DQS Gate Close Configuration
    This bit is used to delay the read DQS gate close logic in the DDR SDRAM PHY. This bit should be set to b1 if the DDR SDRAM controller is running in echo gate mode (CTL_53.EGC = b1) and the echo delay (pad_out + pad_in + flight + flight + tdqsck_max) 2 cycles. */
#define CTL_60_DQS_GATE_CLOSE_CFG 0x00000800
/** Stretch Trailing Edge of DFI Read Data Enable
    This bit field stretches the trailing edge of dfi_rddata_en for closing the read DQS gate */
#define CTL_60_STRTREGT_MASK 0x00000700
/** field offset */
#define CTL_60_STRTREGT_OFFSET 8
/** Read DQS Gate Opening
    This bit field controls, when the read DQS gate opens. This value is the number of cycles to delay the dfi_rddata_en signal prior to opening the read DQS gate. */
#define CTL_60_DQS_GATE_OPEN_MASK 0x000000FF
/** field offset */
#define CTL_60_DQS_GATE_OPEN_OFFSET 0

/* Fields of "Denali CTL_61 register" */
/** Select Address and Command Path
    Selects the latency of the address and command path. Note: The Low Latency option is not functional at this time */
#define CTL_61_SELACP 0x02000000
/* DFI control signals are captured 1 cycle after being sent from the DDR SDRAM Controller
#define CTL_61_SELACP_ACCYC 0x00000000 */
/** DFI control signals are captured 1/4 cycle after being sent from the DDR SDRAM Controller */
#define CTL_61_SELACP_ACQRT 0x02000000
/** Select Write Data Path
    Selects the latency of the write data path. Note:The Low Latency option is not functional at this time */
#define CTL_61_SELWRP 0x01000000
/* Write Data is captured 1 cycle after being sent from the DDR SDRAM Controller
#define CTL_61_SELWRP_WRCYC 0x00000000 */
/** Write data is captured 1/4 ycle after being sent from the DDR SDRAM Controller. */
#define CTL_61_SELWRP_WRQRT 0x01000000
/** DFI Control Mobile MCs
    DFI Control for Mobile MCs. This bit is unused for this MC. */
#define CTL_61_DFICM 0x00800000
/** Loopback Pad Input External Enable
    Enables the pad inputs specifically for external loopback. */
#define CTL_61_LPBKPIEXEN 0x00000020
/* Normal Operation
#define CTL_61_LPBKPIEXEN_NORM 0x00000000 */
/** Loopback Mode */
#define CTL_61_LPBKPIEXEN_LPBK 0x00000020
/** Loopback Pad Output External Enable
    Enables the pad outputs specifically for external loopback mode. */
#define CTL_61_LPBKPOEXEN 0x00000010
/* Normal Operation
#define CTL_61_LPBKPOEXEN_NORM 0x00000000 */
/** Loopback Mode */
#define CTL_61_LPBKPOEXEN_LPBK 0x00000010
/** DFI Read Data Valid to Enable Delay
    Sets the dfi_rddata_valid delay relative to dfi_rddata_en. The dfi_rddata_valid signal is not used in the DDR SDRAM controller */
#define CTL_61_DFIRDVEDLY_MASK 0x0000000F
/** field offset */
#define CTL_61_DFIRDVEDLY_OFFSET 0

/* Fields of "Denali CTL_62 register" */
/** Gate Close Forced Status
    Status signal to indicate that the logic gate had to be forced closed. */
#define CTL_62_GCF 0x01000000
/* Nothing
#define CTL_62_GCF_NULL 0x00000000 */
/** Loopback Data
    Reports the actual data or expected data, depending on the setting of CTL_57.LPBKDOT. */
#define CTL_62_LPBKDATA_MASK 0x00FFFF00
/** field offset */
#define CTL_62_LPBKDATA_OFFSET 8
/** Loopback Mask Data
    Reports the actual data mask or the expected data mask, depending on the setting of CTL_57.LPBKDOT. */
#define CTL_62_LBMASKDATA_MASK 0x00000030
/** field offset */
#define CTL_62_LBMASKDATA_OFFSET 4
/** Loopback Error Status
    Reports status of loopback errors. */
#define CTL_62_LPBKERR 0x00000002
/* Last Loopback test had no errors.
#define CTL_62_LPBKERR_NLPBKERR 0x00000000 */
/** Loopback Mode Status
    Defines the status of the loopback mode. */
#define CTL_62_LPBKMODE 0x00000001
/* Not in loopback mode
#define CTL_62_LPBKMODE_NLPBKMODE 0x00000000 */

/* Fields of "Denali CTL_63 register" */
/** Gate Close Forced Status
    Status signal to indicate that the logic gate had to be forced closed. */
#define CTL_63_GCF 0x01000000
/* Nothing
#define CTL_63_GCF_NULL 0x00000000 */
/** Loopback Data
    Reports the actual data or expected data, depending on the setting of CTL_58.LPBKDOT. */
#define CTL_63_LPBKDATA_MASK 0x00FFFF00
/** field offset */
#define CTL_63_LPBKDATA_OFFSET 8
/** Loopback Mask Data
    Reports the actual data mask or the expected data mask, depending on the setting of CTL_58.LPBKDOT. */
#define CTL_63_LBMASKDATA_MASK 0x00000030
/** field offset */
#define CTL_63_LBMASKDATA_OFFSET 4
/** Loopback Error Status
    Reports status of loopback errors. */
#define CTL_63_LPBKERR 0x00000002
/* Last Loopback test had no errors.
#define CTL_63_LPBKERR_NLPBKERR 0x00000000 */
/** Loopback Mode Status
    Defines the status of the loopback mode. */
#define CTL_63_LPBKMODE 0x00000001
/* Not in loopback mode
#define CTL_63_LPBKMODE_NLPBKMODE 0x00000000 */

/* Fields of "Denali CTL_64 register" */
/** Gate Close Forced Status
    Status signal to indicate that the logic gate had to be forced closed. */
#define CTL_64_GCF 0x01000000
/* Nothing
#define CTL_64_GCF_NULL 0x00000000 */
/** Loopback Data
    Reports the actual data or expected data, depending on the setting of CTL_59.LPBKDOT. */
#define CTL_64_LPBKDATA_MASK 0x00FFFF00
/** field offset */
#define CTL_64_LPBKDATA_OFFSET 8
/** Loopback Mask Data
    Reports the actual data mask or the expected data mask, depending on the setting of CTL_59.LPBKDOT. */
#define CTL_64_LBMASKDATA_MASK 0x00000030
/** field offset */
#define CTL_64_LBMASKDATA_OFFSET 4
/** Loopback Error Status
    Reports status of loopback errors. */
#define CTL_64_LPBKERR 0x00000002
/* Last Loopback test had no errors.
#define CTL_64_LPBKERR_NLPBKERR 0x00000000 */
/** Loopback Mode Status
    Defines the status of the loopback mode. */
#define CTL_64_LPBKMODE 0x00000001
/* Not in loopback mode
#define CTL_64_LPBKMODE_NLPBKMODE 0x00000000 */

/* Fields of "Denali CTL_65 register" */
/** Gate Close Forced Status
    Status signal to indicate that the logic gate had to be forced closed. */
#define CTL_65_GCF 0x01000000
/* Nothing
#define CTL_65_GCF_NULL 0x00000000 */
/** Loopback Data
    Reports the actual data or expected data, depending on the setting of CTL_60.LPBKDOT. */
#define CTL_65_LPBKDATA_MASK 0x00FFFF00
/** field offset */
#define CTL_65_LPBKDATA_OFFSET 8
/** Loopback Mask Data
    Reports the actual data mask or the expected data mask, depending on the setting of CTL_60.LPBKDOT. */
#define CTL_65_LBMASKDATA_MASK 0x00000030
/** field offset */
#define CTL_65_LBMASKDATA_OFFSET 4
/** Loopback Error Status
    Reports status of loopback errors. */
#define CTL_65_LPBKERR 0x00000002
/* Last Loopback test had no errors.
#define CTL_65_LPBKERR_NLPBKERR 0x00000000 */
/** Loopback Mode Status
    Defines the status of the loopback mode. */
#define CTL_65_LPBKMODE 0x00000001
/* Not in loopback mode
#define CTL_65_LPBKMODE_NLPBKMODE 0x00000000 */

/* Fields of "Denali CTL_66 register" */
/** Reports master DLL info for delay line 0. Bits [31:0]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_66_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_66_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_67 register" */
/** Reports master DLL info for delay line 0. Bits [63:32]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_67_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_67_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_68 register" */
/** Reports master DLL info for delay line 0. Bits [95:64]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_68_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_68_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_69 register" */
/** Reports master DLL info for delay line 0. Bits [127:96]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_69_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_69_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_70 register" */
/** Reports master DLL info for delay line 0. Bits [159:128]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_70_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_70_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_71 register" */
/** Reports master DLL info for delay line 0. Bits [191:160]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_71_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_71_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_72 register" */
/** Reports master DLL info for delay line 0. Bits [223:192]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_72_DLL_OBS_REG_1_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_72_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_73 register" */
/** Reports master DLL info for delay line 0. Bits [251:224]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_73_DLL_OBS_REG_1_0_MASK 0x0FFFFFFF
/** field offset */
#define CTL_73_DLL_OBS_REG_1_0_OFFSET 0

/* Fields of "Denali CTL_74 register" */
/** Reports master DLL info for delay line 1. Bits [31:0]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_74_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_74_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_75 register" */
/** Reports master DLL info for delay line 1. Bits [63:32]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_75_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_75_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_76 register" */
/** Reports master DLL info for delay line 1. Bits [95:64]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_76_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_76_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_77 register" */
/** Reports master DLL info for delay line 1. Bits [127:96]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_77_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_77_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_78 register" */
/** Reports master DLL info for delay line 1. Bits [159:128]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_78_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_78_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_79 register" */
/** Reports master DLL info for delay line 1. Bits [191:160]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_79_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_79_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_80 register" */
/** Reports master DLL info for delay line 1. Bits [223:192]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_80_DLL_OBS_REG_1_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_80_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_81 register" */
/** Reports master DLL info for delay line 1. Bits [251:224]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_81_DLL_OBS_REG_1_1_MASK 0x0FFFFFFF
/** field offset */
#define CTL_81_DLL_OBS_REG_1_1_OFFSET 0

/* Fields of "Denali CTL_82 register" */
/** Reports master DLL info for delay line 2. Bits [31:0]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_82_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_82_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_83 register" */
/** Reports master DLL info for delay line 2. Bits [63:32]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_83_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_83_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_84 register" */
/** Reports master DLL info for delay line 2. Bits [95:64]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_84_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_84_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_85 register" */
/** Reports master DLL info for delay line 2. Bits [127:96]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_85_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_85_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_86 register" */
/** Reports master DLL info for delay line 2. Bits [159:128]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_86_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_86_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_87 register" */
/** Reports master DLL info for delay line 2. Bits [191:160]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_87_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_87_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_88 register" */
/** Reports master DLL info for delay line 2. Bits [223:192]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_88_DLL_OBS_REG_1_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_88_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_89 register" */
/** Reports master DLL info for delay line 2. Bits [251:224]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_89_DLL_OBS_REG_1_2_MASK 0x0FFFFFFF
/** field offset */
#define CTL_89_DLL_OBS_REG_1_2_OFFSET 0

/* Fields of "Denali CTL_90 register" */
/** Reports master DLL info for delay line 3. Bits [31:0]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_90_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_90_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_91 register" */
/** Reports master DLL info for delay line 3. Bits [63:32]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_91_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_91_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_92 register" */
/** Reports master DLL info for delay line 3. Bits [95:64]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_92_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_92_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_93 register" */
/** Reports master DLL info for delay line 3. Bits [127:96]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_93_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_93_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_94 register" */
/** Reports master DLL info for delay line 3. Bits [159:128]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_94_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_94_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_95 register" */
/** Reports master DLL info for delay line 3. Bits [191:160]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_95_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_95_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_96 register" */
/** Reports master DLL info for delay line 3. Bits [223:192]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_96_DLL_OBS_REG_1_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_96_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_97 register" */
/** Reports master DLL info for delay line 3. Bits [251:224]
    One-hot register that identifies which multiplexer controls the master delay line. As an example, 0x200 = b1000000000, so this identifies the 10th multiplexer. */
#define CTL_97_DLL_OBS_REG_1_3_MASK 0x0FFFFFFF
/** field offset */
#define CTL_97_DLL_OBS_REG_1_3_OFFSET 0

/* Fields of "Denali CTL_98 register" */
/** Reports the read DQS delay value for data slice 0. Bits [31:0] */
#define CTL_98_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_98_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_99 register" */
/** Reports the read DQS delay value for data slice 0. Bits [63:32] */
#define CTL_99_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_99_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_100 register" */
/** Reports the read DQS delay value for data slice 0. Bits [95:64] */
#define CTL_100_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_100_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_101 register" */
/** Reports the read DQS delay value for data slice 0. Bits [127:96] */
#define CTL_101_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_101_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_102 register" */
/** Reports the read DQS delay value for data slice 0. Bits [159:128] */
#define CTL_102_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_102_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_103 register" */
/** Reports the read DQS delay value for data slice 0. Bits [191:160] */
#define CTL_103_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_103_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_104 register" */
/** Reports the read DQS delay value for data slice 0. Bits [223:192] */
#define CTL_104_DLL_OBS_REG_2_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_104_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_105 register" */
/** Reports the read DQS delay value for data slice 0. Bits [251:224] */
#define CTL_105_DLL_OBS_REG_2_0_MASK 0x0FFFFFFF
/** field offset */
#define CTL_105_DLL_OBS_REG_2_0_OFFSET 0

/* Fields of "Denali CTL_106 register" */
/** Reports the read DQS delay value for data slice 1. Bits [31:0] */
#define CTL_106_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_106_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_107 register" */
/** Reports the read DQS delay value for data slice 1. Bits [63:32] */
#define CTL_107_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_107_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_108 register" */
/** Reports the read DQS delay value for data slice 1. Bits [95:64] */
#define CTL_108_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_108_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_109 register" */
/** Reports the read DQS delay value for data slice 1. Bits [127:96] */
#define CTL_109_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_109_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_110 register" */
/** Reports the read DQS delay value for data slice 1. Bits [159:128] */
#define CTL_110_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_110_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_111 register" */
/** Reports the read DQS delay value for data slice 1. Bits [191:160] */
#define CTL_111_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_111_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_112 register" */
/** Reports the read DQS delay value for data slice 1. Bits [223:192] */
#define CTL_112_DLL_OBS_REG_2_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_112_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_113 register" */
/** Reports the read DQS delay value for data slice 1. Bits [251:224] */
#define CTL_113_DLL_OBS_REG_2_1_MASK 0x0FFFFFFF
/** field offset */
#define CTL_113_DLL_OBS_REG_2_1_OFFSET 0

/* Fields of "Denali CTL_114 register" */
/** Reports the read DQS delay value for data slice 2. Bits [31:0] */
#define CTL_114_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_114_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_115 register" */
/** Reports the read DQS delay value for data slice 2. Bits [63:32] */
#define CTL_115_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_115_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_116 register" */
/** Reports the read DQS delay value for data slice 2. Bits [95:64] */
#define CTL_116_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_116_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_117 register" */
/** Reports the read DQS delay value for data slice 2. Bits [127:96] */
#define CTL_117_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_117_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_118 register" */
/** Reports the read DQS delay value for data slice 2. Bits [159:128] */
#define CTL_118_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_118_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_119 register" */
/** Reports the read DQS delay value for data slice 2. Bits [191:160] */
#define CTL_119_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_119_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_120 register" */
/** Reports the read DQS delay value for data slice 2. Bits [223:192] */
#define CTL_120_DLL_OBS_REG_2_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_120_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_121 register" */
/** Reports the read DQS delay value for data slice 2. Bits [251:224] */
#define CTL_121_DLL_OBS_REG_2_2_MASK 0x0FFFFFFF
/** field offset */
#define CTL_121_DLL_OBS_REG_2_2_OFFSET 0

/* Fields of "Denali CTL_122 register" */
/** Reports the read DQS delay value for data slice 3. Bits [31:0] */
#define CTL_122_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_122_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_123 register" */
/** Reports the read DQS delay value for data slice 3. Bits [63:32] */
#define CTL_123_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_123_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_124 register" */
/** Reports the read DQS delay value for data slice 3. Bits [95:64] */
#define CTL_124_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_124_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_125 register" */
/** Reports the read DQS delay value for data slice 3. Bits [127:96] */
#define CTL_125_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_125_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_126 register" */
/** Reports the read DQS delay value for data slice 3. Bits [159:128] */
#define CTL_126_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_126_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_127 register" */
/** Reports the read DQS delay value for data slice 3. Bits [191:160] */
#define CTL_127_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_127_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_128 register" */
/** Reports the read DQS delay value for data slice 3. Bits [223:192] */
#define CTL_128_DLL_OBS_REG_2_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_128_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_129 register" */
/** Reports the read DQS delay value for data slice 3. Bits [251:224] */
#define CTL_129_DLL_OBS_REG_2_3_MASK 0x0FFFFFFF
/** field offset */
#define CTL_129_DLL_OBS_REG_2_3_OFFSET 0

/* Fields of "Denali CTL_130 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [31:0] */
#define CTL_130_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_130_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_131 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [63:32] */
#define CTL_131_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_131_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_132 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [95:64] */
#define CTL_132_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_132_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_133 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [127:96] */
#define CTL_133_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_133_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_134 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [159:128] */
#define CTL_134_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_134_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_135 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [191:160] */
#define CTL_135_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_135_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_136 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [223:192] */
#define CTL_136_DLL_OBS_REG_3_0_MASK 0xFFFFFFFF
/** field offset */
#define CTL_136_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_137 register" */
/** Reports the clk_wr delay value for data slice 0. Bits [251:224] */
#define CTL_137_DLL_OBS_REG_3_0_MASK 0x0FFFFFFF
/** field offset */
#define CTL_137_DLL_OBS_REG_3_0_OFFSET 0

/* Fields of "Denali CTL_138 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [31:0] */
#define CTL_138_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_138_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_139 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [63:32] */
#define CTL_139_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_139_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_140 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [95:64] */
#define CTL_140_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_140_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_141 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [127:96] */
#define CTL_141_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_141_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_142 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [159:128] */
#define CTL_142_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_142_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_143 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [191:160] */
#define CTL_143_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_143_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_144 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [223:192] */
#define CTL_144_DLL_OBS_REG_3_1_MASK 0xFFFFFFFF
/** field offset */
#define CTL_144_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_145 register" */
/** Reports the clk_wr delay value for data slice 1. Bits [251:224] */
#define CTL_145_DLL_OBS_REG_3_1_MASK 0x0FFFFFFF
/** field offset */
#define CTL_145_DLL_OBS_REG_3_1_OFFSET 0

/* Fields of "Denali CTL_146 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [31:0] */
#define CTL_146_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_146_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_147 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [63:32] */
#define CTL_147_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_147_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_148 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [95:64] */
#define CTL_148_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_148_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_149 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [127:96] */
#define CTL_149_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_149_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_150 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [159:128] */
#define CTL_150_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_150_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_151 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [191:160] */
#define CTL_151_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_151_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_152 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [223:192] */
#define CTL_152_DLL_OBS_REG_3_2_MASK 0xFFFFFFFF
/** field offset */
#define CTL_152_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_153 register" */
/** Reports the clk_wr delay value for data slice 2. Bits [251:224] */
#define CTL_153_DLL_OBS_REG_3_2_MASK 0x0FFFFFFF
/** field offset */
#define CTL_153_DLL_OBS_REG_3_2_OFFSET 0

/* Fields of "Denali CTL_154 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [31:0] */
#define CTL_154_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_154_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_155 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [63:32] */
#define CTL_155_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_155_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_156 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [95:64] */
#define CTL_156_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_156_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_157 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [127:96] */
#define CTL_157_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_157_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_158 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [159:128] */
#define CTL_158_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_158_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_159 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [191:160] */
#define CTL_159_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_159_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_160 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [223:192] */
#define CTL_160_DLL_OBS_REG_3_3_MASK 0xFFFFFFFF
/** field offset */
#define CTL_160_DLL_OBS_REG_3_3_OFFSET 0

/* Fields of "Denali CTL_161 register" */
/** Reports the clk_wr delay value for data slice 3. Bits [251:224] */
#define CTL_161_DLL_OBS_REG_3_3_MASK 0x0FFFFFFF
/** field offset */
#define CTL_161_DLL_OBS_REG_3_3_OFFSET 0

/*! @} */ /* DDRDB_REGISTER */

#endif /* _ddrdb_reg_h */
