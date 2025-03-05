module TestQ3_3;
wire [15:0] O;
reg [15:0] in [31:0];
reg [4:0] Select;

Mux32to1_16bit mux(in[0],in[1],in[2],in[3],in[4],in[5],in[6],in[7],in[8],in[9],in[10],in[11],in[12],in[13],in[14],in[15],in[16],in[17],in[18]
,in[19],in[20],in[21],in[22],in[23],in[24],in[25],in[26],in[27],in[28],in[29],in[30],in[31],Select,O);
integer i;
initial begin
	for (i=0;i<32;i=i+1) begin
	in[i]=$random;
	end

	for (Select = 5'b00000;Select != 5'b11111; Select = Select + 1'b1) begin
	#20;
	end
#20;
end



endmodule