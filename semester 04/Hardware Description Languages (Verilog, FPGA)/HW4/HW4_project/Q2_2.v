module RFCorrelator(
    input Bit_stream,
    input Clock,
    input Reset,
    output reg [3:0] Out_str
    );
	 reg [31:0] serial_to_parallel;
	wire [31:0] inputs[15:0];
	reg [4:0] counter;
	wire [3:0] Out_4;
	always @(posedge Clock or posedge Reset) begin
		if(Reset) begin
			serial_to_parallel<=0;
			counter<=0;
			Out_str<=0;
		end
		else begin
			counter<=counter+1;
			serial_to_parallel<={serial_to_parallel[30:0],Bit_stream};
			if(counter==5'b11111) begin
				Out_str<=Out_4;
			end
		end
	end
	 
	 Correlation_32 corr_32 (
		.Num_1({serial_to_parallel[30:0],Bit_stream}), 
		.Num_2(inputs[0]), 
		.Num_3(inputs[1]), 
		.Num_4(inputs[2]), 
		.Num_5(inputs[3]), 
		.Num_6(inputs[4]), 
		.Num_7(inputs[5]), 
		.Num_8(inputs[6]), 
		.Num_9(inputs[7]), 
		.Num_10(inputs[8]), 
		.Num_11(inputs[9]), 
		.Num_12(inputs[10]), 
		.Num_13(inputs[11]), 
		.Num_14(inputs[12]), 
		.Num_15(inputs[13]), 
		.Num_16(inputs[14]), 
		.Target_Num(inputs[15]), 
		.Clock(Clock), 
		.Reset(Reset), 
		.Out_4(Out_4)
	);
	genvar i;
	generate
		for(i=0;i<16;i=i+1) begin : assigning
			assign inputs[i] = i==15?0:i==0? 4225597151 : 32'hFFFF_FFFF;
		end
	endgenerate

endmodule
