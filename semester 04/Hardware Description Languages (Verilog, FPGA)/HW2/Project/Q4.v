module Binary_Divisibility_By_7(String,Clock,Reset,Remainder,Divisible);
input String,Clock,Reset;
output reg [2:0] Remainder=0;
output Divisible;
assign Divisible = Remainder==3'b000;
always @(posedge Clock) begin
	if (Reset==1'b1) 
		Remainder<=3'b000;
	else 
		Remainder <= ((Remainder * 2) + String) >=7 ? ((Remainder * 2) + String)-7 : ((Remainder * 2) + String) ;
end

endmodule
