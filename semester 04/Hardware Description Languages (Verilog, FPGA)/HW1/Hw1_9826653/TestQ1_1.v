module TestQ1_1;
	reg A,B;
	wire Sum,Carry;
	HA ha(A,B,Sum,Carry);
	initial begin
		$monitor("A=%b , B=%b , Sum=%b , Carry=%b",A,B,Sum,Carry);
		A=1'b0;
		B=1'b0;
		#20
		A=1'b0;
		B=1'b1;
		#20
		A=1'b1;
		B=1'b0;
		#20
		A=1'b1;
		B=1'b1;
	end
	

endmodule