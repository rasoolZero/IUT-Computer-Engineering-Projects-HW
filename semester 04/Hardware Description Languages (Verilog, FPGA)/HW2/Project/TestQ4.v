module TestQ4;

reg Clock=0,String=0,Reset=0;
wire Divisible;
wire [2:0]Remainer;

Binary_Divisibility_By_7 divisible(String,Clock,Reset,Remainer,Divisible);

always forever #7 Clock=~Clock;
initial begin
	#500
	Reset=1;
	#100;
	Reset=0;
end
always forever begin
	#12 String = $random();
end
endmodule
