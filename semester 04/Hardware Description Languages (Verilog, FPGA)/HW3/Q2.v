
module m_counter(Clock,Reset,Count_m,Pulse1000,Pulse2000,Pulse5000,Out,c_1000,c_2000,c_5000);
	output Out;
	output reg [8:0]c_1000;
	output reg [7:0]c_2000;
	output reg [6:0]c_5000;
	
	reg t1,t2,t3;
	
	input Clock,Reset,Pulse1000,Pulse2000,Pulse5000;
	input [18:0] Count_m;
	
	assign	Out = ((c_1000*1000 + c_2000*2000 + c_5000*5000) >= Count_m);
		
		
	always @(posedge Clock or negedge Reset) begin
		if (Reset == 0) begin
			c_1000 <= 0;
			c_2000 <= 0;
			c_5000 <= 0;
			t1 <= 0;
			t2 <= 0;
			t3 <= 0;
		end
		else begin
			t1 <= Pulse1000;
			t2 <= Pulse2000;
			t3 <= Pulse5000;
			if(t1==0 && Pulse1000==1)
				c_1000<=(c_1000+Pulse1000);
			if(t2==0 && Pulse2000==1)
				c_2000<=(c_2000+Pulse2000);
			if(t3==0 && Pulse5000==1)
				c_5000<=(c_5000+Pulse5000);
		end
	end


endmodule