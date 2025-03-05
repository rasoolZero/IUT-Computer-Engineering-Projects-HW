module TestQ2_2;

	// Inputs
	reg Bit_stream=0;
	reg Clock=0;
	reg Reset=0;
	reg passed=0;
	wire [3:0] Out_str;

	RFCorrelator uut (
		.Bit_stream(Bit_stream), 
		.Clock(Clock), 
		.Reset(Reset), 
		.Out_str(Out_str)
	);
	always forever #7 Clock = ~Clock;
	always forever #13 Bit_stream = passed?$random():1;
	initial begin
	#5;
	Reset=1;
	#10;
	Reset=0;
	#500
	passed=1;
   end
endmodule

