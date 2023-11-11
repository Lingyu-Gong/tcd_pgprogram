// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.2 (win64) Build 2708876 Wed Nov  6 21:40:23 MST 2019
// Date        : Fri Nov 10 00:49:24 2023
// Host        : Gonglingyu running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/PYNQ-image_v2.5.4/boards/Pynq-Z2/base/base_filter/base_filter.srcs/sources_1/bd/base_filter/ip/base_filter_clk_wiz_10MHz_0/base_filter_clk_wiz_10MHz_0_stub.v
// Design      : base_filter_clk_wiz_10MHz_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module base_filter_clk_wiz_10MHz_0(clk_out1, resetn, locked, clk_in1)
/* synthesis syn_black_box black_box_pad_pin="clk_out1,resetn,locked,clk_in1" */;
  output clk_out1;
  input resetn;
  output locked;
  input clk_in1;
endmodule
