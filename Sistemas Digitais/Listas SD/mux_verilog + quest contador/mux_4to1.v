module mux_4to1 (output wire F, 
                 input wire A,B,C,D,
                 input wire [1:0] Sel);
  
  assign F = (Sel == 2'b00) ? A :
  			 (Sel == 2'b01) ? B :
  			 (Sel == 2'b10) ? C :
  			 (Sel == 2'b11) ? D :
  			 1'bX;
  
endmodule