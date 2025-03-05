module Correlation_32(
    input [31:0] Num_1,
    input [31:0] Num_2,
    input [31:0] Num_3,
    input [31:0] Num_4,
    input [31:0] Num_5,
    input [31:0] Num_6,
    input [31:0] Num_7,
    input [31:0] Num_8,
    input [31:0] Num_9,
    input [31:0] Num_10,
    input [31:0] Num_11,
    input [31:0] Num_12,
    input [31:0] Num_13,
    input [31:0] Num_14,
    input [31:0] Num_15,
    input [31:0] Num_16,
    input [31:0] Target_Num,
    input Clock,
    input Reset,
    output reg [3:0] Out_4
    );
	 reg [5:0] corr_memory[14:0];
	 reg [5:0] max;
	 integer i;
	 always @(posedge Clock or posedge Reset) begin
		if(Reset) begin
			Out_4<=0;
		end
		else begin
			corr_memory[0] = Correlation_Func(Num_1,Target_Num);
			corr_memory[1] = Correlation_Func(Num_2,Target_Num);
			corr_memory[2] = Correlation_Func(Num_3,Target_Num);
			corr_memory[3] = Correlation_Func(Num_4,Target_Num);
			corr_memory[4] = Correlation_Func(Num_5,Target_Num);
			corr_memory[5] = Correlation_Func(Num_6,Target_Num);
			corr_memory[6] = Correlation_Func(Num_7,Target_Num);
			corr_memory[7] = Correlation_Func(Num_8,Target_Num);
			corr_memory[8] = Correlation_Func(Num_9,Target_Num);
			corr_memory[9] = Correlation_Func(Num_10,Target_Num);
			corr_memory[10] = Correlation_Func(Num_11,Target_Num);
			corr_memory[11] = Correlation_Func(Num_12,Target_Num);
			corr_memory[12] = Correlation_Func(Num_13,Target_Num);
			corr_memory[13] = Correlation_Func(Num_14,Target_Num);
			corr_memory[14] = Correlation_Func(Num_15,Target_Num);
			max = Correlation_Func(Num_16,Target_Num);
			Out_4<=15;
			for(i=14;i>=0;i=i-1) begin
				if(corr_memory[i]>=max) begin
					max = corr_memory[i];
					Out_4 <= i;
				end
			end
		end
	 end
	 
	 function [5:0] Correlation_Func;
		input [31:0] Num;		
		input [31:0] Target;
		reg [5:0] i;
		begin
			Correlation_Func=0;
			for (i=0;i<32;i=i+1)
				Correlation_Func=Correlation_Func+(Num[i]==Target[i]);
		end
	endfunction

endmodule
