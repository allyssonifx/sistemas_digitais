module mux(input wire sel, Q, Hz,
          output reg  pgt_1Hz);
  
  always@*
  if (sel == 0)
    begin
      pgt_1Hz = Q;
    end
  else
      pgt_1Hz = Hz;
  
endmodule