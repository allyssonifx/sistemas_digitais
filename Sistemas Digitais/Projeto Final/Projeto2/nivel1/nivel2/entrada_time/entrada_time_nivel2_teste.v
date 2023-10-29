`timescale 1ns/1ps

module entrada_time_nivel2_teste();

reg [9:0] teclado;
reg enablen;
reg clk;
wire [3:0] D;
wire loadn;
wire pgt_1Hz;

nivel2 dut(
    .teclado(teclado),
    .enablen(enablen),
    .clk(clk),
    .D(D),
    .loadn(loadn),
    .pgt_1Hz(pgt_1Hz)
);

initial begin
    $dumpfile("entrada_time_nivel2_teste.vcd");
    $dumpvars(0, entrada_time_nivel2_teste);

    //D deve ser 1111 nesse teste
        #1 teclado = 10'b1000000000;
        clk = 1;
        enablen = 0;
        repeat(201)
            #1 clk = ~clk;
        
    //D deve ser 0110 nesse teste
        #1 teclado = 10'b0100000000;
        clk = 1;
        repeat(201)
            #1 clk = ~clk;
  	//D nao deve mudar nesse teste
  		#1 teclado = 10'b100000000;
        clk = 1;
        enablen = 1;
        repeat(201)
            #1 clk = ~clk;
  	//Agora D deve mudar
  		enablen = 0;
        repeat(201)
            #1 clk = ~clk;
  		
end
endmodule