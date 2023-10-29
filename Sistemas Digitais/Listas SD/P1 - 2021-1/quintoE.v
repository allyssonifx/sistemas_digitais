`timescale 1ns/1ps
`include "teste_8.v"

module teste_tb();
    reg [7:0] In1, In2;
    wire V3, V2, V1;

    Comparator8Bit UUT(.V3(V3), .V2(v2), .V1(V1), .a(In1), .b(In2));

    initial 
    
    begin

        $dumpfile("teste_tb.vcd");
        $dumpvars(0, teste_8_tb);


        In1 = 8'b0;

        In2 = 8'b0;

        #20;
               

        In1 = 8'd8;

        In2 = 8'd7;

        #20;

        In1 = 8'd100;

        In2 = 8'd120;

        #20;

        In1 = 8'd64;

        In2 = 8'd78;

        #20;

        In1 = 8'd32;

        In2 = 8'd32;

        #20;
 

        end
endmodule