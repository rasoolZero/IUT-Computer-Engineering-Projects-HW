module TestQ3;
	reg clk=1,reset=0,input_seq=0;
	reg [1:0] lookfor_seq=0;
	wire [15:0] seq_count;
	wire seq_detected;
	wire [0:4] seq [3:0];
	assign seq [0] = 5'b10111;
	assign seq [1] = 5'b01010;
	assign seq [2] = 5'b10101;
	assign seq [3] = 5'b10100;
	integer i=0;
	sequence_detector seq_det(clk,reset,input_seq,lookfor_seq,seq_detected,seq_count);
	
	always forever #7 clk=~clk;
	always @(posedge clk) begin
		input_seq = seq[lookfor_seq][i%5];
		i=i+1;
		if( i==14)
			reset=1;
		if( i==16)
			reset=0;
			
			
			
		if( i==23)
			lookfor_seq=2'b01;
		if( i==36)
			lookfor_seq=2'b10;
		if( i==49)
			lookfor_seq=2'b11;
	end
endmodule