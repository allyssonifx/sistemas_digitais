`timescale 1ns/1ns
`include "mux.v"

module mux_teste;

    reg sel_TB, Q_TB, clk_TB;
  	wire  pgt_1Hz_TB;

  	mux DUT(.sel(sel_TB), .Q(Q_TB), .Hz(clk_TB), .pgt_1Hz(pgt_1Hz_TB));

    initial
        begin

            $dumpfile("mux_teste.vcd");
            $dumpvars(0, mux_teste);

                sel_TB=1; Q_TB=0; clk_TB=1;
            #5  sel_TB=0; Q_TB=0; clk_TB=1;
         	  #5  sel_TB=1; Q_TB=1; clk_TB=0;
          	#5  sel_TB=0; Q_TB=1; clk_TB=0;
            #5  sel_TB=1; Q_TB=1; clk_TB=1;
          	#5  sel_TB=0; Q_TB=1; clk_TB=1;
            #5  sel_TB=1; Q_TB=0; clk_TB=0;
          	#5  sel_TB=0; Q_TB=0; clk_TB=0;
          
        end
endmodule