`timescale  1ms / 1ms

module testet(a,b,cin,s,cout);
    input a,b,cin;
    output s,cout;

    wire w1,w2,w3;

    xor (w1,a,b);
    xor (s,w1,cin);
    and (w2,cin,w1);
    and (w3,a,b);
    or (cout,w2,w3);

endmodule