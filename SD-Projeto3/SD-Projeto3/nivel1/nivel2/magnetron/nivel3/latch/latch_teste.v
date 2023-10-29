`timescale 1ns/1ps
`include "latch.v"

module latch_teste();

    reg set_TB, reset_TB;
    wire Q_TB;

    latch DUT(.set(set_TB), .reset(reset_TB), .Q(Q_TB));

    initial begin
        $dumpfile("latch_teste.vcd");
        $dumpvars(0,latch_teste);
            #10 set_TB = 0; reset_TB = 0;

            #10 set_TB = 0; reset_TB = 1;

            #10 set_TB = 0; reset_TB = 0;

            #10 set_TB = 1; reset_TB = 0;

            #10 set_TB = 0; reset_TB = 0;

            #10 set_TB = 1; reset_TB = 1;

            #10 set_TB = 0; reset_TB = 0;

            #10;
    end
endmodule