`include "nivel3/codificador_priori/codificador_priori.v"
`include "nivel3/cont_assincrono/counter_assin.v"
`include "nivel3/divisor_freq/divi.v"
`include "nivel3/mux/mux.v"

module entrada_time_nivel2(input [9:0] teclado,
    input enablen,
    input clk,
    output [3:0] D,
    output loadn,
    output pgt_1Hz
);

    wire clk100, Q;
    wire load;

    codificador_priori codificador_priori(teclado, enablen, loadn, D);
    divi divi(clk, clk100);
    counter counter(clk, loadn, Q);
    mux mux(enablen, Q, clk100, pgt_1Hz);


endmodule