module decodificador(input wire [3:0] mins,      sec_tens,      sec_ones,
                     output reg [6:0] mins_segs, sec_tens_segs, sec_ones_segs);
  
  always@(mins)
    case(mins)
      4'b0000 : mins_segs = 7'b0000001;
      4'b0001 : mins_segs = 7'b1001111;
      4'b0010 : mins_segs = 7'b0010010;
      4'b0011 : mins_segs = 7'b0000110;
      4'b0100 : mins_segs = 7'b1001100;
      4'b0101 : mins_segs = 7'b0100100;
      4'b0110 : mins_segs = 7'b0100000;
      4'b0111 : mins_segs = 7'b0001101;
      4'b1000 : mins_segs = 7'b0000000;
      4'b1001 : mins_segs = 7'b0000100;
    endcase
  
  always@(sec_tens)
  case(sec_tens)
      4'b0000 : sec_tens_segs = 7'b0000001;
      4'b0001 : sec_tens_segs = 7'b1001111;
      4'b0010 : sec_tens_segs = 7'b0010010;
      4'b0011 : sec_tens_segs = 7'b0000110;
      4'b0100 : sec_tens_segs = 7'b1001100;
      4'b0101 : sec_tens_segs = 7'b0100100;
      4'b0110 : sec_tens_segs = 7'b0100000;
      4'b0111 : sec_tens_segs = 7'b0001101;
      4'b1000 : sec_tens_segs = 7'b0000000;
      4'b1001 : sec_tens_segs = 7'b0000100;
    endcase
  
  always@(sec_ones)
  case(sec_ones)
      4'b0000 : sec_ones_segs = 7'b0000001;
      4'b0001 : sec_ones_segs = 7'b1001111;
      4'b0010 : sec_ones_segs = 7'b0010010;
      4'b0011 : sec_ones_segs = 7'b0000110;
      4'b0100 : sec_ones_segs = 7'b1001100;
      4'b0101 : sec_ones_segs = 7'b0100100;
      4'b0110 : sec_ones_segs = 7'b0100000;
      4'b0111 : sec_ones_segs = 7'b0001101;
      4'b1000 : sec_ones_segs = 7'b0000000;
      4'b1001 : sec_ones_segs = 7'b0000100;
    endcase
  
endmodule