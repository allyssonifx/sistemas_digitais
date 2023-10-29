`include "nivel3/latch/latch.v"
`include "nivel3/circuito_logico/control_mag.v"

module nivel2_controle (
    input wire startn, stopn, clearn, door_closed, timer_done,
    output wire Q2
);

wire saida_set;
wire saida_reset;

control_mag control_mag(startn, stopn, clearn, door_closed, timer_done, saida_set, saida_reset);
latch latch(saida_set, saida_reset, Q2);

endmodule