`timescale 1ns/1ns
`include "decodificador.v"

module decodificador_teste;

    reg  [3:0] mins_TB, sec_tens_TB, sec_ones_TB;
  	wire [6:0] mins_segs_TB, sec_tens_segs_TB, sec_ones_segs_TB;

  	decodificador DUT(.mins(mins_TB), .sec_tens(sec_tens_TB), .sec_ones(sec_ones_TB), .mins_segs(mins_segs_TB), .sec_tens_segs(sec_tens_segs_TB), .sec_ones_segs(sec_ones_segs_TB));

    initial
        begin

            $dumpfile("decodificador_teste.vcd");
            $dumpvars(0, decodificador_teste);

                mins_TB=4'b0000; sec_tens_TB=4'b0000; sec_ones_TB=4'b0000;  
            #5  mins_TB=4'b0001; sec_tens_TB=4'b0001; sec_ones_TB=4'b0001; 
         	  #5  mins_TB=4'b0010; sec_tens_TB=4'b0010; sec_ones_TB=4'b0010;
            #5  mins_TB=4'b0011; sec_tens_TB=4'b0011; sec_ones_TB=4'b0011;
            #5  mins_TB=4'b0100; sec_tens_TB=4'b0100; sec_ones_TB=4'b0100;
            #5  mins_TB=4'b0101; sec_tens_TB=4'b0101; sec_ones_TB=4'b0101;
          	#5  mins_TB=4'b0110; sec_tens_TB=4'b0110; sec_ones_TB=4'b0110;
            #5  mins_TB=4'b0111; sec_tens_TB=4'b0111; sec_ones_TB=4'b0111;
          	#5  mins_TB=4'b1000; sec_tens_TB=4'b1000; sec_ones_TB=4'b1000;
            #5  mins_TB=4'b1001; sec_tens_TB=4'b1001; sec_ones_TB=4'b1001; 
   
        end
endmodule