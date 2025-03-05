module Correlation  (input clk, reset, [SIZE-1:0]First_Num, [SIZE-1:0]Second_Num, [SIZE-1:0]Target_Num, output reg [1:0]Correct_guess, reg [SIZE+2:0]out_1, reg [SIZE+2:0]out_2);
    
    parameter SIZE = 16;
    reg [SIZE+2:0]correlate_first;
    reg [SIZE+2:0]correlate_sec;

    always @(posedge clk, posedge reset) begin
        if(reset == 1)begin
            Correct_guess <= 0;
            out_1 <= 0;
            out_2 <= 0;
        end
        else begin
            
            if ((First_Num == Target_Num) && (Second_Num == Target_Num)) begin
                Correct_guess <= 2'b11;
            end
                
            else if (First_Num == Target_Num) Correct_guess <= 2'b01;

            else if (Second_Num == Target_Num) Correct_guess <= 2'b10;

            else begin
                Correct_guess <= 2'b00;
                out_1 <= out_1 + corre_calc(Target_Num, First_Num);
                out_2 <= out_2 + corre_calc(Target_Num, Second_Num);
            end

        end
    end

    function [SIZE+2:0]corre_calc;
        input [SIZE-1:0]target;
        input [SIZE-1:0]guess;
        integer i;
        begin
            for(i = 0; i<SIZE; i=i+1)begin
                if(target[i] == guess[i]) corre_calc = corre_calc+1; 
            end
        end
        
    endfunction

endmodule


module Winner (input [SIZE+2:0]out_1, [SIZE+2:0]out_2, output reg [1:0]out_wr);

    parameter SIZE = 16;
    always @(out_1, out_2) begin
        if(out_1 == out_2) out_wr = 2'b11;
        else if (out_1 > out_2) out_wr = 2'b01;
        else if(out_1 < out_2) out_wr = 2'b10;
        else out_wr = 2'b00; 
    end

endmodule


module decision (input clk, reset, [1:0] Correct_guess, [1:0] out_wr, output reg [1:0]Result);
    integer i;
    always @(posedge clk, posedge reset) begin
        if(reset) begin
            i=0;
            Result <= 0;
        end 

        else begin
            i = i+1;

            if(Correct_guess == 2'b00 && i <= 10) begin 
                Result <= 0;
                i = 0; 
            end
            else begin
                i = 0;

                if(Correct_guess == 2'b00)
                    Result <= out_wr;
                else
                    Result <= Correct_guess;
                
            end 
        end
        
    end
        
endmodule


module Q1_1  (input clk, reset, [SIZE-1:0]First_Num, [SIZE-1:0]Second_Num, [SIZE-1:0]Target_Num, output [1:0]Result);

    wire [SIZE+2:0] out_1;
    wire [SIZE+2:0] out_2;
    wire [1:0]Correct_guess;
    wire [1:0]out_wr;
    parameter SIZE = 16;
	 
    Correlation #(SIZE) C  (clk, reset, First_Num, Second_Num, Target_Num, Correct_guess, out_1, out_2);
    
    Winner  #(SIZE) W (out_1, out_2, out_wr);

    decision D  (clk, reset, Correct_guess, out_wr, Result);

endmodule
