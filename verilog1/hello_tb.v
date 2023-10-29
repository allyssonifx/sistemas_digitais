`timescale 1ms / 1ms
`include "hello.v"

module hello_tb;
    reg A;
    wire B;

    hello out(A, B);

    initial begin
        $dumpfile("hello_tb.vcd");
        $dumpfile(0,hello_tb);
        A = 0;
        #20

        A = 1;
        #20

        A = 0;
        #20

        $display("Test Complete")
    end
endmodule