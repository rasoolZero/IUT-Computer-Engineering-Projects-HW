
module TestQ2_3;


reg [2:0]I;
wire [7:0]O;
reg E;
Decoder3to8 d(I,E,O);
initial begin

E = 1'b1;
for (I=3'b000 ; I!=3'b111 ; I = I+1'b1) begin
	#20;
end
#20
E = 1'b0;
for (I=3'b000 ; I!=3'b111 ; I = I+1'b1) begin
	#20;
end

end
endmodule