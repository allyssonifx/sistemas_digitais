`include "nivel2/entrada_time/nivel3/codificador_priori/codificador_priori.v"
`include "nivel2/entrada_time/nivel3/cont_assincrono/counter_assin.v"
`include "nivel2/entrada_time/nivel3/divisor_freq/divi.v"
`include "nivel2/entrada_time/nivel3/mux/mux.v"

module entrada_time_nivel2(input [9:0] keypad, input enablen, clk,
                           output [3:0] D, output loadn, pgt_1Hz);

    wire [9:0] clk100;
    reg pressed;
    reg enable;
    
    initial pressed = 0;

    always @(keypad) begin
        if(keypad == 10'b00000_00000)
            pressed <= 0;
        else
            pressed <= 1;
    end

    // always @(enablen) begin
    //     if(enablen == 10'b00000_00000)
    //         enable <= 0;
    //     else
    //         enable <= 1;
    // end

    assign loadn = pressed;

    codificador_priori codificador_priori(keypad, enablen, D);
    divi divi(clk, clk100);
    counter counter(clk, pressed, Q);
    mux mux(enablen, Q, clk100[5], pgt_1Hz);

endmodule