module TestQ3_2;
wire [15:0] O;
reg [15:0] in [3:0];
reg [1:0] Select;

Mux4to1_16bit mux(in[0],in[1],in[2],in[3],Select,O);

initial begin
	for (Select = 2'b00;Select != 2'b11; Select = Select + 1'b1) begin
	in[0]=$random;
	in[1]=$random;
	in[2]=$random;
	in[3]=$random;
	#20;
	end
#20;
end



endmodule
