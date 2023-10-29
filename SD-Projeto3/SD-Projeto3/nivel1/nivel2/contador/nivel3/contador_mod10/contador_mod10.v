module contador_mod10 (data, clk, loadn, en, clrn, count, tc, zero);
  input wire [3:0] data;
  input wire clk, loadn, en, clrn;
  output reg [3:0] count;
  output wire tc; 
  output wire zero;

  always @ (negedge clrn)
  begin
    count = 4'b0000;
  end

  assign zero = (count == 4'b0000) ? 1'b1 : 1'b0;
  assign tc = en & zero;

  always @ (posedge clk)
  begin
    if (en) 
      case (count) // testar necessidade das duas primeiras condições
        4'b1001: begin
          count <= 4'b1000;
        end
        4'b0001: begin 
          count <= 4'b0000;
        end
        4'b0000: begin
          count <= 4'b1001;
        end
        default: count <= count - 4'b0001;
      endcase

    else begin
      if(!loadn)
        count <= data;
    end
  end
endmodule