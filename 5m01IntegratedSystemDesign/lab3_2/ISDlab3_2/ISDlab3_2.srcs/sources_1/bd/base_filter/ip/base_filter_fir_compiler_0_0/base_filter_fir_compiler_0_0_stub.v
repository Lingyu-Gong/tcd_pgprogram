// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.2 (win64) Build 2708876 Wed Nov  6 21:40:23 MST 2019
// Date        : Fri Nov 10 00:48:51 2023
// Host        : Gonglingyu running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/PYNQ-image_v2.5.4/boards/Pynq-Z2/base/base_filter/base_filter.srcs/sources_1/bd/base_filter/ip/base_filter_fir_compiler_0_0/base_filter_fir_compiler_0_0_stub.v
// Design      : base_filter_fir_compiler_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "fir_compiler_v7_2_13,Vivado 2019.2" *)
module base_filter_fir_compiler_0_0(aclk, s_axis_data_tvalid, s_axis_data_tready, 
  s_axis_data_tlast, s_axis_data_tdata, m_axis_data_tvalid, m_axis_data_tlast, 
  m_axis_data_tdata)
/* synthesis syn_black_box black_box_pad_pin="aclk,s_axis_data_tvalid,s_axis_data_tready,s_axis_data_tlast,s_axis_data_tdata[31:0],m_axis_data_tvalid,m_axis_data_tlast,m_axis_data_tdata[31:0]" */;
  input aclk;
  input s_axis_data_tvalid;
  output s_axis_data_tready;
  input s_axis_data_tlast;
  input [31:0]s_axis_data_tdata;
  output m_axis_data_tvalid;
  output m_axis_data_tlast;
  output [31:0]m_axis_data_tdata;
endmodule
