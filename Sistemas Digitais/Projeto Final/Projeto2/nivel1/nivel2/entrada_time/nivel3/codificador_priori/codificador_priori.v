module codificador_priori(teclado, enablen, dado_valido, BCD);
  
  	input wire [9:0]teclado;
  	input wire enablen;
  	output reg [3:0]BCD;
  	output reg dado_valido;
  
    initial dado_valido = 1'b0;
	

  always@(teclado or enablen)
    if (enablen == 1'b0)
      begin
        if (teclado[9:0] == 10'b1000000000)
          begin
        	  BCD = 4'b1111; //15
        	  dado_valido = 1'b1;
          end
        else if (teclado[9:0] == 10'b0100000000)
          begin
        	  BCD = 4'b0110; //6
            dado_valido = 1'b1;
          end
        else if (teclado[9:0] == 10'b0010000000)
          begin
			      BCD = 4'b1110; // 14
        	  dado_valido = 1'b1;
          end
        else if (teclado[9:0] == 10'b0001000000)
          begin
            BCD = 4'b0001; //1
            dado_valido = 1'b1;
          end 
        else if (teclado[9:0] == 10'b0000100000)
          begin 
			      BCD = 4'b1001; //9
            dado_valido = 1'b1;
          end 
        else if (teclado[9:0] == 10'b0000010000)
          begin
			      BCD = 4'b0101; // 5
            dado_valido = 1'b1;
          end 
        else if (teclado[9:0] == 10'b0000001000)
          begin
			      BCD = 4'b1101; //13
            dado_valido = 1'b1;
          end 
        else if (teclado[9:0] == 10'b0000000100)
          begin 
			      BCD = 4'b0011; // 3
            dado_valido = 1'b1;
          end 
        else if (teclado[9:0] == 10'b0000000010)
          begin 
			      BCD = 4'b1011; //11
            dado_valido = 1'b1;
          end 
        else if (teclado[9:0] == 10'b0000000001)
          begin
			      BCD = 4'b0111; // 7
            dado_valido = 1'b1;
          end
        else
          dado_valido = 1'b0;

  	end
endmodule