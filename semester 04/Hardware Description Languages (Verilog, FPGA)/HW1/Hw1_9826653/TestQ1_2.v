module TestQ1_2;
	reg A,B,Cin;
	wire Sum,Carry;
	FA ha(A,B,Cin,Carry,Sum);
	initial begin
		$monitor("A=%b , B=%b , Cin=%b , Sum=%b , Cout=%b",A,B,Cin,Sum,Carry);
		A=1'b0;
		B=1'b0;
		Cin=1'b0;
		#20
		A=1'b1;
		B=1'b0;
		Cin=1'b0;
		#20
		A=1'b0;
		B=1'b1;
		Cin=1'b0;
		#20
		A=1'b1;
		B=1'b1;
		Cin=1'b0;
		#20



		A=1'b0;
		B=1'b0;
		Cin=1'b1;
		#20
		A=1'b1;
		B=1'b0;
		Cin=1'b1;
		#20
		A=1'b0;
		B=1'b1;
		Cin=1'b1;
		#20
		A=1'b1;
		B=1'b1;
		Cin=1'b1;
	end
	

endmodule
