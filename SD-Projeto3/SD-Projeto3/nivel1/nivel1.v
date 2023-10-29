`include "nivel2/contador/contador_nivel2.v"
`include "nivel2/decodificador/decodificador.v"
`include "nivel2/entrada_time/entrada_time_nivel2.v"
`include "nivel2/magnetron/nivel2_controle.v"

module nivel1(
    input wire [9:0]keypad,
    input wire clock, startn, stopn, clearn, door_closed,
    output wire [6:0] mins, 
    output wire [6:0] sec_tens, 
    output wire [6:0] sec_ones,
    output wire mag_on);

    wire saida_controle;
    wire [3:0] D;
    wire loadn;
    wire pgt_1Hz;
    wire zero;

    assign mag_on = saida_controle;

    wire [3:0] count_ONES, count_TENS, count_MINS; 

    // codificador
    entrada_time_nivel2 entrada_time_nivel2(keypad, saida_controle, clock, D, loadn, pgt_1Hz);

    // timer
    contador_nivel2 contador_nivel2(D, pgt_1Hz, saida_controle, loadn, clearn, count_ONES, count_TENS, count_MINS, zero);

    // controle do magnetron
    nivel2_controle nivel2_controle(startn, stopn, clearn, door_closed, zero, saida_controle);

    // decodificador
    decodificador decodificador(count_MINS, count_TENS, count_ONES, mins, sec_tens, sec_ones);

endmodule