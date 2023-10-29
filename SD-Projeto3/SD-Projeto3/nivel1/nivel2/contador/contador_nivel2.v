`include "nivel2/contador/nivel3/contador_mod10/contador_mod10.v"
`include "nivel2/contador/nivel3/contador_mod6/contador_mod6.v"
`timescale 1ns/1ps

module contador_nivel2(data, clk, enable, loadn, clrn, count_ONES, count_TENS, count_MINS, zero);

  input [3:0] data;
  input wire clk, enable, loadn, clrn;
  output wire [3:0] count_ONES, count_TENS, count_MINS;
  output wire zero;
  
  wire tc1;
  wire tc2;
  wire tc3;
  wire zero1;
  wire zero2;
  wire zero3;

  // Quando a contagem chegar em 0, o controle do magnetron vai
  // ordenar a parada dele, e esse output do controle do magnetron
  // Vai ser também o enable desse contador, logo, o enable = 0 e
  // o contador irá parar automaticamente.

  contador_mod10 ONES(data, clock, loadn, enable, clrn, count_ONES, tc1, zero1);
  contador_mod6  TENS(count_ONES, clock, loadn, tc1, clrn, count_TENS, tc2, zero2);
  contador_mod10 MINS(count_TENS, clock, loadn, tc2, clrn, count_MINS, tc3, zero3);

  assign zero = zero1 & zero2 & zero3;
endmodule