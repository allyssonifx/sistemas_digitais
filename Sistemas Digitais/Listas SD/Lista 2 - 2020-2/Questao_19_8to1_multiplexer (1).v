module mux_8t01 (output wire F, input wire [7:0] A, input wire [2:0] Sel);

    assign F = (A[0] & ~Sel[2] & ~Sel[1] & ~Sel[0]) |
            (A[1] & ~Sel[2] & ~Sel[1] & Sel[0]) |
            (A[2] & ~Sel[2] & Sel[1] & ~Sel[0]) |
            (A[3] & ~Sel[2] & Sel[1] & Sel[0]) |
            (A[4] & Sel[2] & ~Sel[1] & ~Sel[0]) |
            (A[5] & Sel[2] & ~Sel[1] & Sel[0]) |
            (A[6] & Sel[2] & Sel[1] & ~Sel[0]) |
            (A[7] & Sel[2] & Sel[1] & Sel[0]);

endmodule