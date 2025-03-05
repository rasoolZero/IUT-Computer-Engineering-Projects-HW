
module TestQ1;

	// Inputs
	reg [15:0] First_Num;
	reg [15:0] Second_Num;
	reg [15:0] Target_Num;
	reg Clock=0;
	reg Reset;

	// Outputs
	wire [1:0] Result;

	// Instantiate the Unit Under Test (UUT)
	Top_module #(16) uut (
		.First_Num(First_Num), 
		.Second_Num(Second_Num), 
		.Target_Num(Target_Num), 
		.Clock(Clock), 
		.Reset(Reset), 
		.Result(Result)
	);
	always forever #7 Clock<=~Clock;

	initial begin
		Reset = 0;
		#5
		Target_Num=$random();
		Reset=1;
		#15;
		Reset=0;
		repeat(20) begin
			First_Num=$random();
			Second_Num=$random();
			#7;
		end
		#5;
		Reset=1;
		Target_Num=$random();
		#15;
		Reset=0;
		repeat(2) begin
			First_Num=$random();
			Second_Num=$random();
			#7;
		end
		First_Num=$random();
		Second_Num=Target_Num;
		#25;
		Reset=1;
		Target_Num=$random();
		#15;
		Reset=0;
		repeat(2) begin
			First_Num=$random();
			Second_Num=$random();
			#7;
		end
		First_Num=Target_Num;
		Second_Num=Target_Num;
		#25;
	end
      
endmodule

