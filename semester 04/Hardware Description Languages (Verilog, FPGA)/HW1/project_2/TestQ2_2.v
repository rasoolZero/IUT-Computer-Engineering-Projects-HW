module TestQ2_2;
reg [1:0]I;
wire [3:0]O;
reg E = 1'b1;
Decoder2to4 d(I,E,O);
initial begin

E = 1'b1;
for (I=2'b00 ; I!=2'b11 ; I = I+1'b1) begin
	#10
	$monitor("I=%b , E=%b -- O=%b",I,E,O);
end
#10
$monitor("I=%b , E=%b -- O=%b",I,E,O);
E = 1'b0;
for (I=2'b00 ; I!=2'b11 ; I = I+1'b1) begin
	#10
	$monitor("I=%b , E=%b -- O=%b",I,E,O);
end

end
endmodule
