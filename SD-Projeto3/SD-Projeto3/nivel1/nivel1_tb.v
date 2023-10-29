`timescale 1ms/1ms
`include "nivel1.v"

module nivel1_test();
    reg [9:0] keypad;
    reg clock;
    reg startn;
    reg stopn;
    reg door_closed;
    reg clearn;

    wire [6:0] segundos, dezenas, minutos;
    wire mag_on;

    nivel1 dut(.startn(startn), .stopn(stopn), .door_closed(door_closed), .clearn(clearn), .keypad(keypad), .clock(clock), .sec_ones(segundos), .sec_tens(dezenas), .mins(minutos), .mag_on(mag_on));

    initial clock = 0;

    always #1 clock = ~clock;

    initial begin
        $dumpfile("nivel1.vcd");
        $dumpvars(0, nivel1_test);
    end

    initial begin
            keypad = 9'b000000000;
            door_closed = 1;
            stopn = 0;
            startn = 0;

            // Inicializando o contador
            clearn = 1; #100;
            clearn = 0; #100;
            //clearn = 1;

            // Digitando o 2
            #1000;
            keypad = 9'b000000100;
            #1000;
            keypad = 9'b000000000;

            // Digitando o 5
            #1000;
            keypad = 9'b000100000;
            #1000;
            keypad = 9'b000000000;

            // Digitando o 9
            #1000;
            keypad = 10'b1000000000;
            #1000;
            keypad = 9'b000000000;

            // Digitando o 9
            #1000;
            keypad = 10'b1000000000;
            #1000;
            keypad = 9'b000000000;

            // Digitando o 9
            #1000;
            keypad = 10'b1000000000;
            #1000;
            keypad = 9'b000000000;

            // Tentando abrir
            // #1000;
            // startn = 0;
            #1000;
            startn = 1;
            // #1000;
            // // Fechando a porta
            // door_closed = 1;
            // #1000;
            // startn = 0;
            // #1000;
            // startn = 1;
            // #2000;
            // Pausando o timer
            // stopn = 0;
            // #2000;
            // stopn = 1;
            // #2000;
            // startn = 0;
            // #2000;
            // startn = 1;
            // #2000;
            // // Abrindo porta
            // door_closed = 0;
            // #2000;
            // door_closed = 1;
            $monitor("Tempo: %0d - Keypad: %b - Clock: %b - Startn: %b - Stopn: %b - Door_closed: %b - Clearn: %b - Segundos: %b - Dezenas: %b - Minutos: %b - Mag_on: %b", $time, keypad, clock, startn, stopn, door_closed, clearn, segundos, dezenas, minutos, mag_on);

            #100000;
            $finish();
    end

endmodule