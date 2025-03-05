module reg32bitTest;
wire [31:0] output_data;
wire serial_out;

reg clk=0,reset=0,serial_in=0,shift_left=0,shift_right=0,load=0;
reg [31:0] input_data = 1;

reg_32bit register(clk, reset, input_data, output_data, load, shift_right, shift_left, serial_in, serial_out);



always forever #7 clk=~clk;
initial begin
	// input_data = 32'h0f0f0f0f;
	input_data = 32'b10101010101010101010101010101010;
	#22;
	// reset=1;
	// #30;
	// reset=0;
	load=1;
	#30;
	load=0;
	shift_left=1;
	#30;
	serial_in=1;
	// #30;
	shift_right=1;
	#30;
	// serial_in=0;
	// #30
	// input_data = $random();
	// load=1;
	// #30;
	// load=0;
	// shift_right=0;
	// shift_left=1;
	// #30;
	// serial_in=1;
	// #30;
	// shift_right=1;
	// #30;
	// serial_in=0;
	// #30;


end

endmodule