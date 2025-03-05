module TestQ1_4;
	reg [0:3] A;
	reg [0:3] B;
	wire [0:3] Sum;
	reg cin;
	wire cout;
	FA4bit fa(A,B,cin,cout,Sum);
	initial begin
		for (A = 4'b0000 ; A != 4'b1111 ; A = A + 1'b1) begin
		for (B = 4'b0000 ; B != 4'b1111 ; B = B + 1'b1) begin
			#10
			cin=1'b0;
			$monitor("A=%d , B=%d , Cin=%b -- Sum=%d , Cout=%b",A,B,cin,Sum,cout);
			#10
			cin=1'b1;			
			$monitor("A=%d , B=%d , Cin=%b -- Sum=%d , Cout=%b",A,B,cin,Sum,cout);
		end		
		end	
	end
	

endmodule
