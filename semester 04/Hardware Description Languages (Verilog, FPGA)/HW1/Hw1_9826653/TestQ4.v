module TestQ4;

reg [0:7]A;
reg [0:7]B;
reg select;
wire [0:7]C;
wire [0:7]D;
Switch sw(A,B,select,C,D);

initial begin
	A=200;
	B=100;
	select=0;
	#10
	select=1;
	#10
	A=150;
	B=250;
	select=0;
	#10
	select=1;
	#10;
end
endmodule