module myReg(clk, reset, pdata, qdata, load, shift_right, shift_left, serial_in, serial_out);

	input clk, reset, load, serial_in, shift_right, shift_left;
	input [7:0] pdata;
	output reg [7:0] qdata;
	output reg serial_out;
	
	always @(posedge clk) begin
		serial_out <= 0;
		if (reset) begin
			qdata <= 8'h00;
		end
		else if (load) begin
			qdata <= pdata;
		end
		else if (shift_right) begin
			qdata[7:0] <= {serial_in,qdata[7:1]};
			serial_out <= qdata[0];
		end
		else if (shift_left) begin
			qdata[7:0] <= {qdata[6:0],serial_in};
			serial_out <= qdata[7];
		end
	
	end
endmodule