module reg_32bit(clk, reset, pdata, qdata, load, shift_right, shift_left, serial_in, serial_out);
	input clk, reset, load, serial_in, shift_right, shift_left;
	input [31:0] pdata;
	output wire [31:0] qdata;
	output wire serial_out;
	wire [3:0] serial_ins;
	wire [3:0] serial_outs;
	assign serial_ins[3] = shift_right ? serial_in		: qdata[23];
	assign serial_ins[2] = shift_right ? qdata[24]	: qdata[15];
	assign serial_ins[1] = shift_right ? qdata[16]	: qdata[7];
	assign serial_ins[0] = shift_right ? qdata[8] 		: serial_in;
	assign serial_out = shift_right ? serial_outs[0] 		: serial_outs[3];
	myReg r1(clk,reset,pdata[31:24]	,qdata[31:24]	,load,shift_right,shift_left,serial_ins[3],serial_outs[3]);
	myReg r2(clk,reset,pdata[23:16]	,qdata[23:16]	,load,shift_right,shift_left,serial_ins[2],serial_outs[2]);
	myReg r3(clk,reset,pdata[15:8]	,qdata[15:8]	,load,shift_right,shift_left,serial_ins[1],serial_outs[1]);
	myReg r4(clk,reset,pdata[7:0]	,qdata[7:0]		,load,shift_right,shift_left,serial_ins[0],serial_outs[0]);
endmodule	
	
	
	
	
module RegisterBank(clk,reset,load,shift_right,shift_left,flush,output_enable, reg_select,serial_in, data_in,serial_out,data_out);
	input clk,reset,load,shift_left,shift_right,flush,output_enable,serial_in;
	input [5:0] reg_select;
	input [31:0] data_in;
	output serial_out;
	output [31:0] data_out;
	
	wire [63:0] reset_all;
	wire [63:0] load_all;
	wire [63:0] shift_right_all;
	wire [63:0] shift_left_all;
	wire [63:0] serial_in_all;
	
	
	reg [63:0] decoder;
	always @(reg_select) begin
		decoder = 64'h0;
		decoder[reg_select] = 1'b1;
	end
	
	wire [31:0] data_out_all [63:0];
	wire [63:0] serial_out_all;
	
	wire serial_out_reg;
	assign serial_out_reg = serial_out_all[reg_select];
	wire [31:0] data_out_reg;
	assign data_out_reg = data_out_all[reg_select];
	
	
	
	assign reset_all = flush ? 64'hffffffffffffffff : (reset ? decoder : 0 );
	assign load_all = load ? decoder : 0;
	assign shift_right_all = shift_right ? decoder : 0;
	assign shift_left_all = shift_left ? decoder : 0;
	assign serial_in_all = serial_in ? decoder : 0;
	
	// always @(serial_out_all or data_out_all) begin
		// serial_out_reg=serial_out_all[reg_select];
		// data_out_reg=data_out_all[reg_select];
	// end
	
	genvar i;
	generate
		for (i=0;i<64;i=i+1) begin
			reg_32bit reg32(clk,reset_all[i],data_in,data_out_all[i],load_all[i],shift_right_all[i],shift_left_all[i],serial_in_all[i],serial_out_all[i]);
		end
		for (i=0;i<32;i=i+1) begin
			bufif1  buf_(data_out[i],data_out_reg[i],output_enable);
		end
	endgenerate
	bufif1  buf_(serial_out,serial_out_reg,output_enable);

endmodule