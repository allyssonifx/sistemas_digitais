module control_mag(input wire startn, stopn, clearn, door_closed, timer_done,
                output reg set, reset);
  
  always@*
    begin
      if(stopn == 1 | clearn == 1 | timer_done == 1)
        begin
          reset <= 1;
        end
      
      else if(startn == 1 & door_closed == 1)
        begin
          set <= 1;
          reset <= 0;
        end
      
      else if(door_closed == 0)
        begin
          reset <= 1;
        end
    end
endmodule