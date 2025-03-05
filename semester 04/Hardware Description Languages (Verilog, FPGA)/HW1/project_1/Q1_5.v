module AddSub16bit(input [0:15] A,input [0:15] B,input flag,output carry,output [0:15]result);
wire cin;
wire cout1,cout2,cout3;
assign cin = !flag;
reg [0:15] B2;
FA4bit FA1(A[12:15],B2[12:15],cin,cout1,result[12:15]);
FA4bit FA2(A[8:11],B2[8:11],cout1,cout2,result[8:11]);
FA4bit FA3(A[4:7],B2[4:7],cout2,cout3,result[4:7]);
FA4bit FA4(A[0:3],B2[0:3],cout3,carry,result[0:3]);
always @(flag) begin
	if (flag == 1'b0)begin
	B2=~B;
	end
	else begin
	B2=B;
	end
end

endmodule