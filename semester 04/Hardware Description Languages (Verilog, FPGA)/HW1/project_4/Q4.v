
module Switch(A,B,sel,C,D);

input [0:7] A;
input [0:7] B;
input sel;
output reg [0:7] C;
output reg [0:7] D;

always @(sel) begin
	if (sel == 1'b0) begin
	C=A;
	D=B;
	end

	if (sel == 1'b1) begin
	C=B;
	D=A;
	end
end

endmodule