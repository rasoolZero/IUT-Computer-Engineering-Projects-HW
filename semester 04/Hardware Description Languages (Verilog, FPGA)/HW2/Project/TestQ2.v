module TestQ2;
	wire [8:0]c_1000;
	wire [7:0]c_2000;
	wire [6:0]c_5000;
	wire out;
	
	reg pulse1000=0,pulse2000=0,pulse5000=0;
	reg clk=0;
	reg rst=1;
	reg [18:0] count_m = 19'd170584;
	
	m_counter m(clk,rst,count_m,pulse1000,pulse2000,pulse5000,out,c_1000,c_2000,c_5000);
	
	always forever #3 clk=~clk;
	always begin
		rst=0;
		#14;
		rst=1;
		#1500
		rst=0;
		count_m = 19'd200000;
		#100;
		rst=1;
	end
	
	always forever #7 pulse1000=~pulse1000;
	always forever #13 pulse2000=~pulse2000;
	always forever #20 pulse5000=~pulse5000;

endmodule