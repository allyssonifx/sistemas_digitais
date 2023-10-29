module mux_4to1 (output wire F, 
                 input wire A,B,C,D,
                 input wire [1:0] Sel);
  
  assign F = (A & ~Sel[1] & ~Sel[0]) |
             (B & ~Sel[1] &  Sel[0]) |
             (C &  Sel[1] & ~Sel[0]) |
             (D &  Sel[1] &  Sel[0]);
  
endmodule