module decodificador(input wire [3:0] Minutos, DezenaSeg, Segundos,
                     output reg [6:0] OutMinutos, OutDezena, OutSegundos);
  
  always@(Minutos)
    case(Minutos)
      4'b0000 : OutMinutos = 7'b1111110;
      4'b0001 : OutMinutos = 7'b0110000;
      4'b0010 : OutMinutos = 7'b1101101;
      4'b0011 : OutMinutos = 7'b1111001;
      4'b0100 : OutMinutos = 7'b0110011;
      4'b0101 : OutMinutos = 7'b1011011;
      4'b0110 : OutMinutos = 7'b1011111;
      4'b0111 : OutMinutos = 7'b1110000;
      4'b1000 : OutMinutos = 7'b1111111;
      4'b1001 : OutMinutos = 7'b1111011;
    endcase
  
  always@(DezenaSeg)
  case(DezenaSeg)
      4'b0000 : OutDezena = 7'b1111110;
      4'b0001 : OutDezena = 7'b0110000;
      4'b0010 : OutDezena = 7'b1101101;
      4'b0011 : OutDezena = 7'b1111001;
      4'b0100 : OutDezena = 7'b0110011;
      4'b0101 : OutDezena = 7'b1011011;
      4'b0110 : OutDezena = 7'b1011111;
      4'b0111 : OutDezena = 7'b1110000;
      4'b1000 : OutDezena = 7'b1111111;
      4'b1001 : OutDezena = 7'b1111011;
    endcase
  
  always@(Segundos)
  case(Segundos)
      4'b0000 : OutSegundos = 7'b1111110;
      4'b0001 : OutSegundos = 7'b0110000;
      4'b0010 : OutSegundos = 7'b1101101;
      4'b0011 : OutSegundos = 7'b1111001;
      4'b0100 : OutSegundos = 7'b0110011;
      4'b0101 : OutSegundos = 7'b1011011;
      4'b0110 : OutSegundos = 7'b1011111;
      4'b0111 : OutSegundos = 7'b1110000;
      4'b1000 : OutSegundos = 7'b1111111;
      4'b1001 : OutSegundos = 7'b1111011;
    endcase
  
endmodule