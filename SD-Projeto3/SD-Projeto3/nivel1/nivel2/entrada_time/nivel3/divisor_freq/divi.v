module divi(input  clk,
            output reg [9:0] clk100);
  reg [5:0] a = 6'b000000;
  initial clk100 = 10'b0000000000;
  
  always@(posedge clk)
    begin
      a = a + 1'b1;
      
      if(a >= 50)
        begin
          a = 6'b000000;
          clk100 = ~clk100;
        end
    end
endmodule