############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab04_HLS
set_top sobel_accel
add_files C:/Users/Gonglingyu/Desktop/sobel.cpp
add_files C:/Users/Gonglingyu/Desktop/sobel.h
add_files -tb C:/Users/Gonglingyu/Desktop/tb_sobel.cpp
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog -version 0.0.0
#source "./lab04_HLS/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog -version "0.0.0"
