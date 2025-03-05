module sequence_detector(clk,reset,input_seq,lookfor_seq,seq_detected,seq_count);
	
	input clk,reset,input_seq;
	input [1:0] lookfor_seq;
	output reg [15:0] seq_count=0;
	output reg seq_detected=0;
	reg [3:0] counter=0;
	reg [1:0] lfs_temp;
		
	reg [4:0] seq;
	always @(negedge clk) begin
		seq<={seq[3:0],input_seq};    //from left
		seq_detected<=0;
		
			
		if (reset) begin
			counter=0;
			seq_count<=0;
		end
		else begin
			if(counter>=4)
				case (lookfor_seq)
					2'b00: 
						if({seq[3:0],input_seq} == 5'b10111) begin
							seq_detected<=1;
							seq_count<=seq_count+1;
						end
					2'b01: 
						if({seq[3:0],input_seq} == 5'b01010) begin
							seq_detected<=1;
							seq_count<=seq_count+1;
						end
					2'b10: 
						if({seq[3:0],input_seq} == 5'b10101) begin
							seq_detected<=1;
							seq_count<=seq_count+1;
						end
					2'b11: 
						if({seq[3:0],input_seq} == 5'b10100) begin
							seq_detected<=1;
							seq_count<=seq_count+1;
						end
				endcase
			else
				counter=counter+1;
		end
		lfs_temp<=lookfor_seq;
		if(lfs_temp != lookfor_seq)
			seq_count<=0;
	end
	
	
endmodule