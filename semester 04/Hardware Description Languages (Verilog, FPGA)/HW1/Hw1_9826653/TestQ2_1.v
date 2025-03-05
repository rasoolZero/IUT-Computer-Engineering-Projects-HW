module TestQ2_1;
reg I,E;
wire O0,O1;
Decoder1to2 d(I,E,O0,O1);
initial begin
	I=0;
	E=0;
	$monitor("I=%b , E=%b -- O0=%b , O1=%b",I,E,O0,O1);
	#20
	I=1;
	E=0;
	$monitor("I=%b , E=%b -- O0=%b , O1=%b",I,E,O0,O1);
	#20
	I=0;
	E=1;
	$monitor("I=%b , E=%b -- O0=%b , O1=%b",I,E,O0,O1);
	#20
	I=1;
	E=1;
	$monitor("I=%b , E=%b -- O0=%b , O1=%b",I,E,O0,O1);

end

endmodule