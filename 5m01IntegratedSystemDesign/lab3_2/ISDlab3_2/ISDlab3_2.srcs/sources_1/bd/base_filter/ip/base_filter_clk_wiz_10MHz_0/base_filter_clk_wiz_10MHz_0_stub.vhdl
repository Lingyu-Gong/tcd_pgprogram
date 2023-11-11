-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.2 (win64) Build 2708876 Wed Nov  6 21:40:23 MST 2019
-- Date        : Fri Nov 10 00:49:24 2023
-- Host        : Gonglingyu running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               c:/PYNQ-image_v2.5.4/boards/Pynq-Z2/base/base_filter/base_filter.srcs/sources_1/bd/base_filter/ip/base_filter_clk_wiz_10MHz_0/base_filter_clk_wiz_10MHz_0_stub.vhdl
-- Design      : base_filter_clk_wiz_10MHz_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity base_filter_clk_wiz_10MHz_0 is
  Port ( 
    clk_out1 : out STD_LOGIC;
    resetn : in STD_LOGIC;
    locked : out STD_LOGIC;
    clk_in1 : in STD_LOGIC
  );

end base_filter_clk_wiz_10MHz_0;

architecture stub of base_filter_clk_wiz_10MHz_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk_out1,resetn,locked,clk_in1";
begin
end;
