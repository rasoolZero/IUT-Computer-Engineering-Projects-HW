module TestQ3_1;
wire O;
reg [3:0] in;
reg [1:0] Select;

Mux4to1_1bit mux(in[0],in[1],in[2],in[3],Select,O);

initial begin
	for (in = 4'b0000;in != 4'b1111; in = in + 1'b1) begin
		for (Select = 4'b00;Select != 4'b11; Select = Select + 1'b1) begin
		#10;
		end
	#10;
	end
	for (Select = 2'b00;Select != 2'b11; Select = Select + 1'b1) begin
	#10;
	end
#10;
end



endmodule
