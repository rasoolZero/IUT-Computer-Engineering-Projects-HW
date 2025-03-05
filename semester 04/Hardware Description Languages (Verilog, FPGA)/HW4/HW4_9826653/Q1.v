module Correlation(
    First_Num,
    Second_Num,
    Target_Num,
    Clock,
    Reset,
	 Correct_guess,
	 Out_1,
	 Out_2
	);
	parameter N=32;
	input [N-1:0] First_Num; 
	input [N-1:0] Second_Num; 
	input [N-1:0] Target_Num; 
	input Clock,Reset;
	output [1:0] Correct_guess;
	output reg [N+2:0] Out_1;
	output reg [N+2:0] Out_2;
	
	assign Correct_guess = Reset? 2'b00 : {Second_Num==Target_Num,First_Num==Target_Num};
	
	function [N+2:0] Correlation_Func;
		input [N-1:0] Num;		
		input [N-1:0] Target;
		reg [N+2:0] total;
		integer i;
		begin
			total=0;
			for (i=0;i<N;i=i+1)
				total=total+(Num[i]==Target[i]);
			Correlation_Func=total;
		end
	endfunction
	always @(posedge Clock or posedge Reset) begin
		if(Reset) begin
			Out_1<=0;
			Out_2<=0;
		end
		else begin
			Out_1<=Out_1+Correlation_Func(First_Num,Target_Num);
			Out_2<=Out_2+Correlation_Func(Second_Num,Target_Num);
		end
	end
endmodule 

module  Winner(
	 Out_1,
	 Out_2,
	 Out_wr
	);
	parameter N=32;
	input [N+2:0] Out_1;
	input [N+2:0] Out_2;
	output [1:0] Out_wr;
	assign Out_wr = {Out_2>=Out_1,Out_1>=Out_2};
endmodule 

module Decision(
	Clock,
	Reset,
	Correct_guess,
	Out_wr,
	Result
	);
	input Clock,Reset;
	input [1:0] Correct_guess;
	input [1:0] Out_wr;
	output reg [1:0] Result;
	reg [3:0]counter;
	always @(posedge Clock or posedge Reset) begin
		if(Reset) begin
			Result<=0;
			counter<=0;
		end
		else begin
			if(Result==2'b00) begin
				if(Correct_guess!=2'b00) begin
					Result<=Correct_guess;
				end
				else begin
					counter<=counter+1;
					if(counter==9) begin
						Result<=Out_wr;
					end
				end
			end
		end
	end
	
	
endmodule

module Top_module(
    First_Num,
    Second_Num,
    Target_Num,
    Clock,
    Reset,
    Result
    );
	parameter N=32;
	input [N-1:0] First_Num; 
	input [N-1:0] Second_Num; 
	input [N-1:0] Target_Num; 
	input Clock,Reset;
	output [1:0] Result;
	
	wire [1:0] Correct_guess;
	wire [N+2:0] Out_1;
	wire [N+2:0] Out_2;
	wire [1:0] Out_wr;
	Correlation #(N) correlation(First_Num,Second_Num,Target_Num,Clock,Reset,Correct_guess,Out_1,Out_2);
	Winner #(N) winner(Out_1,Out_2,Out_wr);
	Decision decision(Clock,Reset,Correct_guess,Out_wr,Result);
	
	
	
endmodule

