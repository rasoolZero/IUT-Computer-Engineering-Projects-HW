
module TestQ2_1;

	// Inputs
	reg [31:0] Num_1;
	reg [31:0] Num_2;
	reg [31:0] Num_3;
	reg [31:0] Num_4;
	reg [31:0] Num_5;
	reg [31:0] Num_6;
	reg [31:0] Num_7;
	reg [31:0] Num_8;
	reg [31:0] Num_9;
	reg [31:0] Num_10;
	reg [31:0] Num_11;
	reg [31:0] Num_12;
	reg [31:0] Num_13;
	reg [31:0] Num_14;
	reg [31:0] Num_15;
	reg [31:0] Num_16;
	reg [31:0] Target_Num;
	reg Clock=0;
	reg Reset;

	// Outputs
	wire [3:0] Out_4;
	// Instantiate the Unit Under Test (UUT)
	Correlation_32 uut (
		.Num_1(Num_1), 
		.Num_2(Num_2), 
		.Num_3(Num_3), 
		.Num_4(Num_4), 
		.Num_5(Num_5), 
		.Num_6(Num_6), 
		.Num_7(Num_7), 
		.Num_8(Num_8), 
		.Num_9(Num_9), 
		.Num_10(Num_10), 
		.Num_11(Num_11), 
		.Num_12(Num_12), 
		.Num_13(Num_13), 
		.Num_14(Num_14), 
		.Num_15(Num_15), 
		.Num_16(Num_16), 
		.Target_Num(Target_Num), 
		.Clock(Clock), 
		.Reset(Reset), 
		.Out_4(Out_4)
	);
	always forever begin
		#7 Clock = ~Clock;
	end
	
	initial begin
		Reset = 0;
		#5;
		Reset=1;
		#5;
		Reset=0;
		repeat(3) begin
		Num_1 = $random();
		Num_2 = $random();
		Num_3 = $random();
		Num_4 = $random();
		Num_5 = $random();
		Num_6 = $random();
		Num_7 = $random();
		Num_8 = $random();
		Num_9 = $random();
		Num_10 = $random();
		Num_11 = $random();
		Num_12 = $random();
		Num_13 = $random();
		Num_14 = $random();
		Num_15 = $random();
		Num_16 = $random();
		Target_Num = $random();
		#7;
	end
	
		Num_1 = 1;
		Num_2 = 1;
		Num_3 = 0;
		Num_4 = 1;
		Num_5 = 1;
		Num_6 = 1;
		Num_7 = 1;
		Num_8 = 1;
		Num_9 = 0;
		Num_10 = 1;
		Num_11 = 1;
		Num_12 = 1;
		Num_13 = 1;
		Num_14 = 1;
		Num_15 = 1;
		Num_16 = 1;
		Target_Num = 0;

	end
      
endmodule

