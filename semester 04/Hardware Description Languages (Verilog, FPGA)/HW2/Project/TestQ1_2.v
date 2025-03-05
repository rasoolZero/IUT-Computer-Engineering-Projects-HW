module TestQ1_2;

reg clk=0,reset=0,load=0,shift_right=0,shift_left=0,flush=0,output_enable=1,serial_in=0;
reg [31:0] data_in;
reg [5:0] reg_select=0;
wire [31:0] data_out;
wire serial_out;

RegisterBank reg_bank(clk,reset,load,shift_right,shift_left,flush,output_enable,reg_select,serial_in, data_in, serial_out, data_out);

always forever #7 clk<=~clk;
initial begin
	data_in = $random();
	#13;
	flush=1;
	#21;
	flush=0;
	reg_select=0;
	load=1;
	#30;
	load=0;
	shift_left=1;
	#30;
	serial_in=1;
	#30;
	shift_right=1;
	#30;
	serial_in=0;
	#30
	data_in = $random();
	reg_select=24;
	load=1;
	#30;
	load=0;
	shift_right=0;
	shift_left=1;
	#30;
	serial_in=1;
	#30;
	shift_right=1;
	#30;
	serial_in=0;
	#30;
	shift_right=0;
	shift_left=0;
	output_enable=0;
	#30;
	output_enable=1;
	#30;
	reg_select=0;
	#40;
	shift_left=1;
	#40
	shift_right=1;
	#40;
	serial_in=1;
end
endmodule
