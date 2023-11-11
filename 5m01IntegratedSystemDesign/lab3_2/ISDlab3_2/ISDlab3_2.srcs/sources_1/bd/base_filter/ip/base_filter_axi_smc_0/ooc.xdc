# aclk {FREQ_HZ 100000000 CLK_DOMAIN base_filter_ps7_0_0_FCLK_CLK0 PHASE 0.000} aclk1 {FREQ_HZ 142857132 CLK_DOMAIN base_filter_ps7_0_0_FCLK_CLK1 PHASE 0.000}
# Clock Domain: base_filter_ps7_0_0_FCLK_CLK0
create_clock -name aclk -period 10.000 [get_ports aclk]
# Clock Domain: base_filter_ps7_0_0_FCLK_CLK1
create_clock -name aclk1 -period 7.000 [get_ports aclk1]
# Generated clocks
