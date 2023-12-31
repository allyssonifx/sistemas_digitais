module contador_mod10 (data, clk, load, reset, count, tc, stop);
  
  input [3:0] data;
  input clk, load, reset, stop;
  output [3:0] count;
  output tc;
  
  wire reset_comb;
  reg [3:0] reg_count;
  reg tc;
  
  assign count = reg_count;
  assign reset_comb = (reset & ((reg_count == 4'b0000)? 1'b0 : 1'b1));
  assign tc = (reg_count == 4'b0000)? 1'b1 : 1'b0;
  
  always @ (posedge clk) begin
    
    if (load)
      reg_count <= data;
    else
      if (!stop)
        reg_count <= reg_count;
      else
        if (!reset_comb)
            reg_count <= 4'b1001;
        else
            reg_count <= reg_count - 1'b1;

  end
  
endmodule