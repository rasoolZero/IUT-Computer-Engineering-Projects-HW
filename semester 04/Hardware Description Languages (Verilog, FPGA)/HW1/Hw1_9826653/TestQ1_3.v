module TestQ1_3;
	reg [0:6] Data_in;
	wire [0:2] Data_out;
	BitCounter bc(Data_in,Data_out);
	initial begin
		for (Data_in = 0 ; Data_in != 7'b1111111 ; Data_in = Data_in + 1'b1) begin
			#20
			$monitor("Data in=%b , Data out=%d  %b",Data_in,Data_out,Data_out);
		end
	end
	

endmodule