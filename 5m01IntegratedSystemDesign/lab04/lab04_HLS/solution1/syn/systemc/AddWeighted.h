// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _AddWeighted_HH_
#define _AddWeighted_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "sobel_accel_dadd_udo.h"
#include "sobel_accel_dmul_vdy.h"
#include "sobel_accel_uitodwdI.h"

namespace ap_rtl {

struct AddWeighted : public sc_module {
    // Port declarations 31
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_in< sc_logic > start_full_n;
    sc_out< sc_logic > ap_done;
    sc_in< sc_logic > ap_continue;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_logic > start_out;
    sc_out< sc_logic > start_write;
    sc_in< sc_lv<8> > src1_data_stream_V_dout;
    sc_in< sc_logic > src1_data_stream_V_empty_n;
    sc_out< sc_logic > src1_data_stream_V_read;
    sc_in< sc_lv<8> > src2_data_stream_V_dout;
    sc_in< sc_logic > src2_data_stream_V_empty_n;
    sc_out< sc_logic > src2_data_stream_V_read;
    sc_in< sc_lv<11> > dst_rows_V_dout;
    sc_in< sc_logic > dst_rows_V_empty_n;
    sc_out< sc_logic > dst_rows_V_read;
    sc_in< sc_lv<12> > dst_cols_V_dout;
    sc_in< sc_logic > dst_cols_V_empty_n;
    sc_out< sc_logic > dst_cols_V_read;
    sc_out< sc_lv<8> > dst_data_stream_V_din;
    sc_in< sc_logic > dst_data_stream_V_full_n;
    sc_out< sc_logic > dst_data_stream_V_write;
    sc_out< sc_lv<11> > dst_rows_V_out_din;
    sc_in< sc_logic > dst_rows_V_out_full_n;
    sc_out< sc_logic > dst_rows_V_out_write;
    sc_out< sc_lv<12> > dst_cols_V_out_din;
    sc_in< sc_logic > dst_cols_V_out_full_n;
    sc_out< sc_logic > dst_cols_V_out_write;
    sc_signal< sc_lv<64> > ap_var_for_const0;
    sc_signal< sc_lv<64> > ap_var_for_const1;


    // Module declarations
    AddWeighted(sc_module_name name);
    SC_HAS_PROCESS(AddWeighted);

    ~AddWeighted();

    sc_trace_file* mVcdFile;

    sobel_accel_dadd_udo<1,5,64,64,64>* sobel_accel_dadd_udo_U88;
    sobel_accel_dadd_udo<1,5,64,64,64>* sobel_accel_dadd_udo_U89;
    sobel_accel_dmul_vdy<1,6,64,64,64>* sobel_accel_dmul_vdy_U90;
    sobel_accel_dmul_vdy<1,6,64,64,64>* sobel_accel_dmul_vdy_U91;
    sobel_accel_uitodwdI<1,6,32,64>* sobel_accel_uitodwdI_U92;
    sobel_accel_uitodwdI<1,6,32,64>* sobel_accel_uitodwdI_U93;
    sc_signal< sc_logic > real_start;
    sc_signal< sc_logic > start_once_reg;
    sc_signal< sc_logic > ap_done_reg;
    sc_signal< sc_lv<4> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > internal_ap_ready;
    sc_signal< sc_logic > src1_data_stream_V_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_pp0_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter1;
    sc_signal< bool > ap_block_pp0_stage0;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048;
    sc_signal< sc_logic > src2_data_stream_V_blk_n;
    sc_signal< sc_logic > dst_rows_V_blk_n;
    sc_signal< sc_logic > dst_cols_V_blk_n;
    sc_signal< sc_logic > dst_data_stream_V_blk_n;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter27;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter26_reg;
    sc_signal< sc_logic > dst_rows_V_out_blk_n;
    sc_signal< sc_logic > dst_cols_V_out_blk_n;
    sc_signal< sc_lv<32> > t_V_4_reg_266;
    sc_signal< sc_lv<32> > rows_V_fu_302_p1;
    sc_signal< sc_lv<32> > rows_V_reg_1029;
    sc_signal< bool > ap_block_state1;
    sc_signal< sc_lv<32> > cols_V_fu_306_p1;
    sc_signal< sc_lv<32> > cols_V_reg_1034;
    sc_signal< sc_lv<1> > icmp_ln354_fu_310_p2;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<32> > i_V_fu_315_p2;
    sc_signal< sc_lv<32> > i_V_reg_1043;
    sc_signal< sc_lv<1> > icmp_ln355_fu_321_p2;
    sc_signal< bool > ap_block_state3_pp0_stage0_iter0;
    sc_signal< bool > ap_block_state4_pp0_stage0_iter1;
    sc_signal< bool > ap_block_state5_pp0_stage0_iter2;
    sc_signal< bool > ap_block_state6_pp0_stage0_iter3;
    sc_signal< bool > ap_block_state7_pp0_stage0_iter4;
    sc_signal< bool > ap_block_state8_pp0_stage0_iter5;
    sc_signal< bool > ap_block_state9_pp0_stage0_iter6;
    sc_signal< bool > ap_block_state10_pp0_stage0_iter7;
    sc_signal< bool > ap_block_state11_pp0_stage0_iter8;
    sc_signal< bool > ap_block_state12_pp0_stage0_iter9;
    sc_signal< bool > ap_block_state13_pp0_stage0_iter10;
    sc_signal< bool > ap_block_state14_pp0_stage0_iter11;
    sc_signal< bool > ap_block_state15_pp0_stage0_iter12;
    sc_signal< bool > ap_block_state16_pp0_stage0_iter13;
    sc_signal< bool > ap_block_state17_pp0_stage0_iter14;
    sc_signal< bool > ap_block_state18_pp0_stage0_iter15;
    sc_signal< bool > ap_block_state19_pp0_stage0_iter16;
    sc_signal< bool > ap_block_state20_pp0_stage0_iter17;
    sc_signal< bool > ap_block_state21_pp0_stage0_iter18;
    sc_signal< bool > ap_block_state22_pp0_stage0_iter19;
    sc_signal< bool > ap_block_state23_pp0_stage0_iter20;
    sc_signal< bool > ap_block_state24_pp0_stage0_iter21;
    sc_signal< bool > ap_block_state25_pp0_stage0_iter22;
    sc_signal< bool > ap_block_state26_pp0_stage0_iter23;
    sc_signal< bool > ap_block_state27_pp0_stage0_iter24;
    sc_signal< bool > ap_block_state28_pp0_stage0_iter25;
    sc_signal< bool > ap_block_state29_pp0_stage0_iter26;
    sc_signal< bool > ap_block_state30_pp0_stage0_iter27;
    sc_signal< bool > ap_block_pp0_stage0_11001;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter1_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter2_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter3_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter4_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter5_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter6_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter7_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter8_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter9_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter10_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter11_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter12_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter13_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter14_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter15_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter16_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter17_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter18_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter19_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter20_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter21_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter22_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter23_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter24_reg;
    sc_signal< sc_lv<1> > icmp_ln355_reg_1048_pp0_iter25_reg;
    sc_signal< sc_lv<32> > j_V_fu_326_p2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter0;
    sc_signal< sc_lv<8> > tmp_reg_1057;
    sc_signal< sc_lv<8> > tmp_62_reg_1062;
    sc_signal< sc_lv<64> > grp_fu_296_p1;
    sc_signal< sc_lv<64> > tmp_i_i_reg_1077;
    sc_signal< sc_lv<64> > grp_fu_299_p1;
    sc_signal< sc_lv<64> > tmp_8_i_i_reg_1082;
    sc_signal< sc_lv<64> > grp_fu_286_p2;
    sc_signal< sc_lv<64> > t1_reg_1087;
    sc_signal< sc_lv<64> > grp_fu_291_p2;
    sc_signal< sc_lv<64> > t2_reg_1092;
    sc_signal< sc_lv<64> > grp_fu_277_p2;
    sc_signal< sc_lv<64> > tmp_9_i_i_reg_1097;
    sc_signal< sc_lv<64> > grp_fu_281_p2;
    sc_signal< sc_lv<64> > sum_reg_1102;
    sc_signal< sc_lv<64> > p_Val2_22_fu_340_p1;
    sc_signal< sc_lv<64> > p_Val2_22_reg_1107;
    sc_signal< sc_lv<1> > icmp_ln833_fu_357_p2;
    sc_signal< sc_lv<1> > icmp_ln833_reg_1112;
    sc_signal< sc_lv<1> > icmp_ln833_reg_1112_pp0_iter25_reg;
    sc_signal< sc_lv<1> > icmp_ln833_reg_1112_pp0_iter26_reg;
    sc_signal< sc_lv<1> > icmp_ln837_fu_363_p2;
    sc_signal< sc_lv<1> > icmp_ln837_reg_1118;
    sc_signal< sc_lv<1> > icmp_ln837_reg_1118_pp0_iter25_reg;
    sc_signal< sc_lv<1> > icmp_ln837_reg_1118_pp0_iter26_reg;
    sc_signal< sc_lv<1> > p_Result_20_reg_1124;
    sc_signal< sc_lv<1> > p_Result_20_reg_1124_pp0_iter25_reg;
    sc_signal< sc_lv<54> > p_Result_21_fu_393_p1;
    sc_signal< sc_lv<54> > p_Result_21_reg_1133;
    sc_signal< sc_lv<54> > man_V_1_fu_397_p2;
    sc_signal< sc_lv<54> > man_V_1_reg_1138;
    sc_signal< sc_lv<1> > icmp_ln571_fu_403_p2;
    sc_signal< sc_lv<1> > icmp_ln571_reg_1143;
    sc_signal< sc_lv<1> > icmp_ln571_reg_1143_pp0_iter25_reg;
    sc_signal< sc_lv<1> > icmp_ln571_reg_1143_pp0_iter26_reg;
    sc_signal< sc_lv<12> > F2_fu_409_p2;
    sc_signal< sc_lv<12> > F2_reg_1149;
    sc_signal< sc_lv<1> > icmp_ln581_fu_415_p2;
    sc_signal< sc_lv<1> > icmp_ln581_reg_1157;
    sc_signal< sc_lv<12> > F2_6_fu_427_p3;
    sc_signal< sc_lv<12> > F2_6_reg_1163;
    sc_signal< sc_lv<12> > F2_6_reg_1163_pp0_iter25_reg;
    sc_signal< sc_lv<1> > icmp_ln582_fu_435_p2;
    sc_signal< sc_lv<1> > icmp_ln582_reg_1169;
    sc_signal< sc_lv<1> > icmp_ln582_reg_1169_pp0_iter25_reg;
    sc_signal< sc_lv<1> > icmp_ln585_fu_441_p2;
    sc_signal< sc_lv<1> > icmp_ln585_reg_1176;
    sc_signal< sc_lv<1> > icmp_ln603_fu_457_p2;
    sc_signal< sc_lv<1> > icmp_ln603_reg_1181;
    sc_signal< sc_lv<1> > icmp_ln603_reg_1181_pp0_iter25_reg;
    sc_signal< sc_lv<8> > trunc_ln583_fu_471_p1;
    sc_signal< sc_lv<8> > trunc_ln583_reg_1187;
    sc_signal< sc_lv<1> > p_Result_22_fu_540_p3;
    sc_signal< sc_lv<1> > p_Result_22_reg_1193;
    sc_signal< sc_lv<8> > p_Val2_24_fu_552_p2;
    sc_signal< sc_lv<8> > p_Val2_24_reg_1198;
    sc_signal< sc_lv<1> > and_ln581_fu_577_p2;
    sc_signal< sc_lv<1> > and_ln581_reg_1204;
    sc_signal< sc_lv<1> > and_ln403_fu_582_p2;
    sc_signal< sc_lv<1> > and_ln403_reg_1209;
    sc_signal< sc_lv<1> > or_ln581_fu_588_p2;
    sc_signal< sc_lv<1> > or_ln581_reg_1214;
    sc_signal< sc_lv<1> > and_ln603_6_fu_609_p2;
    sc_signal< sc_lv<1> > and_ln603_6_reg_1219;
    sc_signal< sc_lv<1> > icmp_ln621_fu_633_p2;
    sc_signal< sc_lv<1> > icmp_ln621_reg_1225;
    sc_signal< sc_lv<1> > xor_ln621_3_fu_647_p2;
    sc_signal< sc_lv<1> > xor_ln621_3_reg_1231;
    sc_signal< sc_lv<1> > Range1_all_ones_3_fu_673_p2;
    sc_signal< sc_lv<1> > Range1_all_ones_3_reg_1238;
    sc_signal< sc_lv<1> > tmp_70_reg_1245;
    sc_signal< sc_lv<1> > icmp_ln631_fu_687_p2;
    sc_signal< sc_lv<1> > icmp_ln631_reg_1250;
    sc_signal< sc_lv<54> > zext_ln635_fu_693_p1;
    sc_signal< sc_lv<54> > zext_ln635_reg_1256;
    sc_signal< sc_lv<54> > Range2_V_3_fu_697_p2;
    sc_signal< sc_lv<54> > Range2_V_3_reg_1261;
    sc_signal< sc_lv<1> > Range1_all_zeros_3_fu_709_p2;
    sc_signal< sc_lv<1> > Range1_all_zeros_3_reg_1267;
    sc_signal< sc_lv<1> > and_ln642_fu_727_p2;
    sc_signal< sc_lv<1> > and_ln642_reg_1272;
    sc_signal< sc_lv<8> > p_Val2_25_fu_780_p3;
    sc_signal< sc_lv<8> > p_Val2_25_reg_1278;
    sc_signal< sc_lv<1> > underflow_fu_919_p3;
    sc_signal< sc_lv<1> > underflow_reg_1284;
    sc_signal< sc_lv<1> > or_ln658_1_fu_932_p2;
    sc_signal< sc_lv<1> > or_ln658_1_reg_1290;
    sc_signal< bool > ap_block_pp0_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp0_exit_iter0_state3;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter3;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter4;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter5;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter6;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter7;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter8;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter9;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter10;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter11;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter12;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter13;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter14;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter15;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter16;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter17;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter18;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter19;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter20;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter21;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter22;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter23;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter24;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter25;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter26;
    sc_signal< sc_lv<32> > t_V_reg_255;
    sc_signal< sc_logic > ap_CS_fsm_state31;
    sc_signal< bool > ap_block_pp0_stage0_01001;
    sc_signal< sc_lv<32> > grp_fu_296_p0;
    sc_signal< sc_lv<32> > grp_fu_299_p0;
    sc_signal< sc_lv<11> > rows_V_fu_302_p0;
    sc_signal< sc_lv<12> > cols_V_fu_306_p0;
    sc_signal< sc_lv<11> > tmp_V_fu_343_p4;
    sc_signal< sc_lv<52> > tmp_V_5_fu_353_p1;
    sc_signal< sc_lv<53> > tmp_1_i_fu_385_p3;
    sc_signal< sc_lv<63> > trunc_ln556_fu_369_p1;
    sc_signal< sc_lv<12> > zext_ln461_fu_381_p1;
    sc_signal< sc_lv<12> > sub_ln581_fu_421_p2;
    sc_signal< sc_lv<9> > tmp_64_fu_447_p4;
    sc_signal< sc_lv<54> > p_Val2_s_fu_463_p3;
    sc_signal< sc_lv<32> > sext_ln581_fu_468_p1;
    sc_signal< sc_lv<54> > zext_ln586_fu_475_p1;
    sc_signal< sc_lv<54> > ashr_ln586_fu_479_p2;
    sc_signal< sc_lv<1> > tmp_65_fu_489_p3;
    sc_signal< sc_lv<8> > trunc_ln586_fu_485_p1;
    sc_signal< sc_lv<8> > select_ln588_fu_496_p3;
    sc_signal< sc_lv<12> > add_ln591_fu_516_p2;
    sc_signal< sc_lv<32> > zext_ln591_fu_521_p1;
    sc_signal< sc_lv<1> > icmp_ln591_fu_511_p2;
    sc_signal< sc_lv<1> > p_Result_s_fu_525_p3;
    sc_signal< sc_lv<8> > p_Val2_23_fu_504_p3;
    sc_signal< sc_lv<1> > qb_fu_533_p3;
    sc_signal< sc_lv<8> > zext_ln415_fu_548_p1;
    sc_signal< sc_lv<1> > tmp_67_fu_558_p3;
    sc_signal< sc_lv<1> > xor_ln582_fu_572_p2;
    sc_signal< sc_lv<1> > xor_ln603_fu_592_p2;
    sc_signal< sc_lv<1> > or_ln603_fu_597_p2;
    sc_signal< sc_lv<1> > xor_ln416_fu_566_p2;
    sc_signal< sc_lv<1> > and_ln603_5_fu_603_p2;
    sc_signal< sc_lv<12> > pos1_fu_615_p2;
    sc_signal< sc_lv<12> > pos2_fu_624_p2;
    sc_signal< sc_lv<1> > tmp_69_fu_639_p3;
    sc_signal< sc_lv<32> > sext_ln618_fu_620_p1;
    sc_signal< sc_lv<54> > zext_ln623_fu_653_p1;
    sc_signal< sc_lv<54> > ashr_ln623_fu_657_p2;
    sc_signal< sc_lv<1> > lD_fu_663_p1;
    sc_signal< sc_lv<1> > and_ln621_fu_667_p2;
    sc_signal< sc_lv<32> > sext_ln619_fu_629_p1;
    sc_signal< sc_lv<1> > xor_ln639_3_fu_715_p2;
    sc_signal< sc_lv<1> > icmp_ln642_fu_703_p2;
    sc_signal< sc_lv<1> > or_ln639_fu_721_p2;
    sc_signal< sc_lv<8> > trunc_ln581_fu_733_p1;
    sc_signal< sc_lv<8> > select_ln582_fu_741_p3;
    sc_signal< sc_lv<1> > xor_ln403_fu_753_p2;
    sc_signal< sc_lv<1> > and_ln403_3_fu_758_p2;
    sc_signal< sc_lv<8> > select_ln403_fu_747_p3;
    sc_signal< sc_lv<1> > xor_ln581_fu_770_p2;
    sc_signal< sc_lv<1> > and_ln603_fu_775_p2;
    sc_signal< sc_lv<8> > shl_ln604_fu_736_p2;
    sc_signal< sc_lv<8> > select_ln403_3_fu_763_p3;
    sc_signal< sc_lv<1> > xor_ln631_fu_796_p2;
    sc_signal< sc_lv<54> > r_V_fu_806_p2;
    sc_signal< sc_lv<1> > and_ln631_fu_801_p2;
    sc_signal< sc_lv<1> > Range2_all_ones_fu_811_p2;
    sc_signal< sc_lv<1> > select_ln631_fu_816_p3;
    sc_signal< sc_lv<1> > icmp_ln641_fu_833_p2;
    sc_signal< sc_lv<1> > Range1_all_zeros_fu_838_p2;
    sc_signal< sc_lv<1> > and_ln639_fu_824_p2;
    sc_signal< sc_lv<1> > Range1_all_ones_fu_828_p2;
    sc_signal< sc_lv<1> > select_ln642_fu_853_p3;
    sc_signal< sc_lv<1> > or_ln645_fu_849_p2;
    sc_signal< sc_lv<1> > and_ln641_fu_843_p2;
    sc_signal< sc_lv<1> > select_ln642_3_fu_866_p3;
    sc_signal< sc_lv<1> > select_ln639_fu_858_p3;
    sc_signal< sc_lv<1> > select_ln639_3_fu_873_p3;
    sc_signal< sc_lv<1> > and_ln654_fu_888_p2;
    sc_signal< sc_lv<1> > p_Result_23_fu_788_p3;
    sc_signal< sc_lv<1> > xor_ln621_fu_899_p2;
    sc_signal< sc_lv<1> > and_ln621_4_fu_904_p2;
    sc_signal< sc_lv<1> > and_ln557_fu_915_p2;
    sc_signal< sc_lv<1> > empty_118_fu_893_p2;
    sc_signal< sc_lv<1> > and_ln621_5_fu_910_p2;
    sc_signal< sc_lv<1> > or_ln658_fu_927_p2;
    sc_signal< sc_lv<1> > deleted_zeros_fu_881_p3;
    sc_signal< sc_lv<1> > xor_ln340_fu_942_p2;
    sc_signal< sc_lv<1> > xor_ln340_1_fu_952_p2;
    sc_signal< sc_lv<1> > and_ln340_fu_947_p2;
    sc_signal< sc_lv<1> > and_ln428_3_fu_970_p2;
    sc_signal< sc_lv<1> > xor_ln428_fu_974_p2;
    sc_signal< sc_lv<1> > and_ln571_fu_980_p2;
    sc_signal< sc_lv<1> > and_ln428_fu_938_p2;
    sc_signal< sc_lv<1> > or_ln571_fu_985_p2;
    sc_signal< sc_lv<1> > or_ln571_4_fu_991_p2;
    sc_signal< sc_lv<1> > or_ln571_3_fu_1003_p2;
    sc_signal< sc_lv<1> > or_ln340_fu_957_p2;
    sc_signal< sc_lv<1> > xor_ln571_fu_1008_p2;
    sc_signal< sc_lv<1> > and_ln340_1_fu_1014_p2;
    sc_signal< sc_lv<8> > select_ln340_fu_963_p3;
    sc_signal< sc_lv<8> > select_ln571_fu_996_p3;
    sc_signal< sc_logic > grp_fu_277_ce;
    sc_signal< sc_logic > grp_fu_281_ce;
    sc_signal< sc_logic > grp_fu_286_ce;
    sc_signal< sc_logic > grp_fu_291_ce;
    sc_signal< sc_logic > grp_fu_296_ce;
    sc_signal< sc_logic > grp_fu_299_ce;
    sc_signal< sc_lv<4> > ap_NS_fsm;
    sc_signal< sc_logic > ap_idle_pp0;
    sc_signal< sc_logic > ap_enable_pp0;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<4> ap_ST_fsm_state1;
    static const sc_lv<4> ap_ST_fsm_state2;
    static const sc_lv<4> ap_ST_fsm_pp0_stage0;
    static const sc_lv<4> ap_ST_fsm_state31;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const bool ap_const_boolean_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_3FE0000000000000;
    static const sc_lv<32> ap_const_lv32_34;
    static const sc_lv<32> ap_const_lv32_3E;
    static const sc_lv<11> ap_const_lv11_7FF;
    static const sc_lv<52> ap_const_lv52_0;
    static const sc_lv<32> ap_const_lv32_3F;
    static const sc_lv<54> ap_const_lv54_0;
    static const sc_lv<63> ap_const_lv63_0;
    static const sc_lv<12> ap_const_lv12_433;
    static const sc_lv<12> ap_const_lv12_0;
    static const sc_lv<11> ap_const_lv11_433;
    static const sc_lv<12> ap_const_lv12_36;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<9> ap_const_lv9_0;
    static const sc_lv<8> ap_const_lv8_FF;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<12> ap_const_lv12_FFF;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<12> ap_const_lv12_8;
    static const sc_lv<12> ap_const_lv12_9;
    static const sc_lv<54> ap_const_lv54_3FFFFFFFFFFFFF;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_var_for_const1();
    void thread_ap_clk_no_reset_();
    void thread_F2_6_fu_427_p3();
    void thread_F2_fu_409_p2();
    void thread_Range1_all_ones_3_fu_673_p2();
    void thread_Range1_all_ones_fu_828_p2();
    void thread_Range1_all_zeros_3_fu_709_p2();
    void thread_Range1_all_zeros_fu_838_p2();
    void thread_Range2_V_3_fu_697_p2();
    void thread_Range2_all_ones_fu_811_p2();
    void thread_add_ln591_fu_516_p2();
    void thread_and_ln340_1_fu_1014_p2();
    void thread_and_ln340_fu_947_p2();
    void thread_and_ln403_3_fu_758_p2();
    void thread_and_ln403_fu_582_p2();
    void thread_and_ln428_3_fu_970_p2();
    void thread_and_ln428_fu_938_p2();
    void thread_and_ln557_fu_915_p2();
    void thread_and_ln571_fu_980_p2();
    void thread_and_ln581_fu_577_p2();
    void thread_and_ln603_5_fu_603_p2();
    void thread_and_ln603_6_fu_609_p2();
    void thread_and_ln603_fu_775_p2();
    void thread_and_ln621_4_fu_904_p2();
    void thread_and_ln621_5_fu_910_p2();
    void thread_and_ln621_fu_667_p2();
    void thread_and_ln631_fu_801_p2();
    void thread_and_ln639_fu_824_p2();
    void thread_and_ln641_fu_843_p2();
    void thread_and_ln642_fu_727_p2();
    void thread_and_ln654_fu_888_p2();
    void thread_ap_CS_fsm_pp0_stage0();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state31();
    void thread_ap_block_pp0_stage0();
    void thread_ap_block_pp0_stage0_01001();
    void thread_ap_block_pp0_stage0_11001();
    void thread_ap_block_pp0_stage0_subdone();
    void thread_ap_block_state1();
    void thread_ap_block_state10_pp0_stage0_iter7();
    void thread_ap_block_state11_pp0_stage0_iter8();
    void thread_ap_block_state12_pp0_stage0_iter9();
    void thread_ap_block_state13_pp0_stage0_iter10();
    void thread_ap_block_state14_pp0_stage0_iter11();
    void thread_ap_block_state15_pp0_stage0_iter12();
    void thread_ap_block_state16_pp0_stage0_iter13();
    void thread_ap_block_state17_pp0_stage0_iter14();
    void thread_ap_block_state18_pp0_stage0_iter15();
    void thread_ap_block_state19_pp0_stage0_iter16();
    void thread_ap_block_state20_pp0_stage0_iter17();
    void thread_ap_block_state21_pp0_stage0_iter18();
    void thread_ap_block_state22_pp0_stage0_iter19();
    void thread_ap_block_state23_pp0_stage0_iter20();
    void thread_ap_block_state24_pp0_stage0_iter21();
    void thread_ap_block_state25_pp0_stage0_iter22();
    void thread_ap_block_state26_pp0_stage0_iter23();
    void thread_ap_block_state27_pp0_stage0_iter24();
    void thread_ap_block_state28_pp0_stage0_iter25();
    void thread_ap_block_state29_pp0_stage0_iter26();
    void thread_ap_block_state30_pp0_stage0_iter27();
    void thread_ap_block_state3_pp0_stage0_iter0();
    void thread_ap_block_state4_pp0_stage0_iter1();
    void thread_ap_block_state5_pp0_stage0_iter2();
    void thread_ap_block_state6_pp0_stage0_iter3();
    void thread_ap_block_state7_pp0_stage0_iter4();
    void thread_ap_block_state8_pp0_stage0_iter5();
    void thread_ap_block_state9_pp0_stage0_iter6();
    void thread_ap_condition_pp0_exit_iter0_state3();
    void thread_ap_done();
    void thread_ap_enable_pp0();
    void thread_ap_idle();
    void thread_ap_idle_pp0();
    void thread_ap_ready();
    void thread_ashr_ln586_fu_479_p2();
    void thread_ashr_ln623_fu_657_p2();
    void thread_cols_V_fu_306_p0();
    void thread_cols_V_fu_306_p1();
    void thread_deleted_zeros_fu_881_p3();
    void thread_dst_cols_V_blk_n();
    void thread_dst_cols_V_out_blk_n();
    void thread_dst_cols_V_out_din();
    void thread_dst_cols_V_out_write();
    void thread_dst_cols_V_read();
    void thread_dst_data_stream_V_blk_n();
    void thread_dst_data_stream_V_din();
    void thread_dst_data_stream_V_write();
    void thread_dst_rows_V_blk_n();
    void thread_dst_rows_V_out_blk_n();
    void thread_dst_rows_V_out_din();
    void thread_dst_rows_V_out_write();
    void thread_dst_rows_V_read();
    void thread_empty_118_fu_893_p2();
    void thread_grp_fu_277_ce();
    void thread_grp_fu_281_ce();
    void thread_grp_fu_286_ce();
    void thread_grp_fu_291_ce();
    void thread_grp_fu_296_ce();
    void thread_grp_fu_296_p0();
    void thread_grp_fu_299_ce();
    void thread_grp_fu_299_p0();
    void thread_i_V_fu_315_p2();
    void thread_icmp_ln354_fu_310_p2();
    void thread_icmp_ln355_fu_321_p2();
    void thread_icmp_ln571_fu_403_p2();
    void thread_icmp_ln581_fu_415_p2();
    void thread_icmp_ln582_fu_435_p2();
    void thread_icmp_ln585_fu_441_p2();
    void thread_icmp_ln591_fu_511_p2();
    void thread_icmp_ln603_fu_457_p2();
    void thread_icmp_ln621_fu_633_p2();
    void thread_icmp_ln631_fu_687_p2();
    void thread_icmp_ln641_fu_833_p2();
    void thread_icmp_ln642_fu_703_p2();
    void thread_icmp_ln833_fu_357_p2();
    void thread_icmp_ln837_fu_363_p2();
    void thread_internal_ap_ready();
    void thread_j_V_fu_326_p2();
    void thread_lD_fu_663_p1();
    void thread_man_V_1_fu_397_p2();
    void thread_or_ln340_fu_957_p2();
    void thread_or_ln571_3_fu_1003_p2();
    void thread_or_ln571_4_fu_991_p2();
    void thread_or_ln571_fu_985_p2();
    void thread_or_ln581_fu_588_p2();
    void thread_or_ln603_fu_597_p2();
    void thread_or_ln639_fu_721_p2();
    void thread_or_ln645_fu_849_p2();
    void thread_or_ln658_1_fu_932_p2();
    void thread_or_ln658_fu_927_p2();
    void thread_p_Result_21_fu_393_p1();
    void thread_p_Result_22_fu_540_p3();
    void thread_p_Result_23_fu_788_p3();
    void thread_p_Result_s_fu_525_p3();
    void thread_p_Val2_22_fu_340_p1();
    void thread_p_Val2_23_fu_504_p3();
    void thread_p_Val2_24_fu_552_p2();
    void thread_p_Val2_25_fu_780_p3();
    void thread_p_Val2_s_fu_463_p3();
    void thread_pos1_fu_615_p2();
    void thread_pos2_fu_624_p2();
    void thread_qb_fu_533_p3();
    void thread_r_V_fu_806_p2();
    void thread_real_start();
    void thread_rows_V_fu_302_p0();
    void thread_rows_V_fu_302_p1();
    void thread_select_ln340_fu_963_p3();
    void thread_select_ln403_3_fu_763_p3();
    void thread_select_ln403_fu_747_p3();
    void thread_select_ln571_fu_996_p3();
    void thread_select_ln582_fu_741_p3();
    void thread_select_ln588_fu_496_p3();
    void thread_select_ln631_fu_816_p3();
    void thread_select_ln639_3_fu_873_p3();
    void thread_select_ln639_fu_858_p3();
    void thread_select_ln642_3_fu_866_p3();
    void thread_select_ln642_fu_853_p3();
    void thread_sext_ln581_fu_468_p1();
    void thread_sext_ln618_fu_620_p1();
    void thread_sext_ln619_fu_629_p1();
    void thread_shl_ln604_fu_736_p2();
    void thread_src1_data_stream_V_blk_n();
    void thread_src1_data_stream_V_read();
    void thread_src2_data_stream_V_blk_n();
    void thread_src2_data_stream_V_read();
    void thread_start_out();
    void thread_start_write();
    void thread_sub_ln581_fu_421_p2();
    void thread_tmp_1_i_fu_385_p3();
    void thread_tmp_64_fu_447_p4();
    void thread_tmp_65_fu_489_p3();
    void thread_tmp_67_fu_558_p3();
    void thread_tmp_69_fu_639_p3();
    void thread_tmp_V_5_fu_353_p1();
    void thread_tmp_V_fu_343_p4();
    void thread_trunc_ln556_fu_369_p1();
    void thread_trunc_ln581_fu_733_p1();
    void thread_trunc_ln583_fu_471_p1();
    void thread_trunc_ln586_fu_485_p1();
    void thread_underflow_fu_919_p3();
    void thread_xor_ln340_1_fu_952_p2();
    void thread_xor_ln340_fu_942_p2();
    void thread_xor_ln403_fu_753_p2();
    void thread_xor_ln416_fu_566_p2();
    void thread_xor_ln428_fu_974_p2();
    void thread_xor_ln571_fu_1008_p2();
    void thread_xor_ln581_fu_770_p2();
    void thread_xor_ln582_fu_572_p2();
    void thread_xor_ln603_fu_592_p2();
    void thread_xor_ln621_3_fu_647_p2();
    void thread_xor_ln621_fu_899_p2();
    void thread_xor_ln631_fu_796_p2();
    void thread_xor_ln639_3_fu_715_p2();
    void thread_zext_ln415_fu_548_p1();
    void thread_zext_ln461_fu_381_p1();
    void thread_zext_ln586_fu_475_p1();
    void thread_zext_ln591_fu_521_p1();
    void thread_zext_ln623_fu_653_p1();
    void thread_zext_ln635_fu_693_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif