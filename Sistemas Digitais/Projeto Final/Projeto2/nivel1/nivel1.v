`include "nivel2/contador/contador_nivel2.v"
`include "nivel2/decodificador/decodificador.v"
`include "nivel2/entrada_time/entrada_time_nivel2.v"
`include "nivel2/magnetron/nivel2_controle.v"


module nivel2_controle (
    input wire [9:0]keypad;
    input wire clock, startn, stopn, clearn, door_closed,
    output wire minutos, dezenas, segundos
);

wire saida_controle;
wire [3:0] D;
wire loadn;
wire pgt_1Hz;
wire zero;

wire [3:0] count_us, count_ds, count_m;

nivel2_controle nivel2_controle(startn, stopn, clearn, door_closed, zero, saida_controle);
entrada_time_nivel2 entrada_time_nivel2(keypad, saida_controle, clock, D, loadn, pgt_1Hz);
contador_nivel2 contador_nivel2(keypad, pgt_1Hz, saida_controle, loadn, count_us, count_ds, count_m, zero);
decodificador decodificador(count_us, count_ds, count_m);

endmodule