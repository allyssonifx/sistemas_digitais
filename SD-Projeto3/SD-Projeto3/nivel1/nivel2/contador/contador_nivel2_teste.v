`timescale 1ns/1ps
`include "contador_nivel2.v"

module contador_nivel2_teste();
    wire[3:0] mins_TB, sec_tens_TB, sec_ones_TB;
    wire timer_done_TB;
    reg [3:0]  data_TB;
    reg clrn_TB, enable_TB, loadn_TB, clock_TB;

    contador_nivel2 DUT(data_TB, clock_TB, enable_TB, loadn_TB, clrn_TB,
                        sec_ones_TB, sec_tens_TB, mins_TB, timer_done_TB);

    initial begin
        $dumpfile("contador_nivel2_teste.vcd");
        $dumpvars(0,contador_nivel2_teste);

        clock_TB  = 1'b0;
        enable_TB = 1'b0; 
        loadn_TB  = 1'b0;
    end

    always begin
        #1 clock_TB = loadn_TB? ~clock_TB : clock_TB;
    end

    initial begin    
        clrn_TB = 1'b1;    #0.5
        clrn_TB = 1'b0;    #0.5
        clrn_TB = 1'b1;    #0.5

        data_TB =  2;      #0.04;
        clock_TB = 1'b1;   #0.01;
        clock_TB = 1'b0;   #0.95;

        data_TB =  1;      #0.04;
        clock_TB = 1'b1;   #0.01;
        clock_TB = 1'b0;   #0.95;

        data_TB =  7;      #0.04;
        clock_TB = 1'b1;   #0.01;
        clock_TB = 1'b0;   #0.95;

        data_TB =  9;      #0.04;
        clock_TB = 1'b1;   #0.01;
        clock_TB = 1'b0;   #0.95;

        enable_TB = 1; loadn_TB = 1; #1000;

        $finish();
    end
endmodule