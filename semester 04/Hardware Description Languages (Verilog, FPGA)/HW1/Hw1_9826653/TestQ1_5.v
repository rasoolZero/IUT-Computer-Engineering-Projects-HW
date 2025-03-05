module TestQ1_5;
reg [0:15] A;
reg [0:15] B;
reg flag;
wire signed [0:15] result;
wire carry;
AddSub16bit as(A,B,flag,carry,result);
initial begin
	A=1200;
	B=5103;
	flag=1'b1;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);
	#20
	flag=1'b0;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);
	#20
	A=3251;
	B=2489;
	flag=1'b1;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);	
	#20
	flag=1'b0;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);



	#20
	A=32512;
	B=24894;
	flag=1'b1;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);	
	#20
	flag=1'b0;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);
	#20
	B=32512;
	A=24894;
	flag=1'b1;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);	
	#20
	flag=1'b0;
	$monitor("A=%d , B=%d , flag=%b -- result=%d , carry/sign=%b",A,B,flag,result,carry);
end


endmodule