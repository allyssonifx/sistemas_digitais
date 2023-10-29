`include "nivel2/magnetron/nivel3/latch/latch.v"
`include "nivel2/magnetron/nivel3/circuito_logico/control_mag.v"

module nivel2_controle (input wire startn, stopn, clearn, door_closed, timer_done,
                        output wire mag_on);

    wire control_set;
    wire control_reset;

    control_mag control_mag(startn, stopn, clearn, door_closed, timer_done, control_set, control_reset);
    latch latch(control_set, control_reset, mag_on);

endmodule