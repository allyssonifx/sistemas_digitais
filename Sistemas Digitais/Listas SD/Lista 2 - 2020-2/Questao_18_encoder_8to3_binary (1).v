module encoder_8to3_binary(output wire [2:0] F, input wire [7:0] A);
    always @ (*)
    case (A)
    8'b00000001: F=3'b000;
    8'b00000010: F=3'b001;
    8'b00000100: F=3'b010;
    8'b00001000: F=3'b011;
    8'b00010000: F=3'b100;
    8'b00100000: F=3'b101;
    8'b01000000: F=3'b110;
    8'b10000000: F=3'b111;
    default: F=3'bxxx;
    endcase
    
endmodule