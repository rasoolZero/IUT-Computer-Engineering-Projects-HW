module Decoder3to8(input [2:0]Data_in,input Enable,output [7:0]Data_out);

wire E1,E2;
assign E1=Data_in[2] & Enable;   //MSB
assign E2=!Data_in[2] & Enable;  //LSB
Decoder2to4 d1(Data_in[1:0],E1,Data_out[7:4]);
Decoder2to4 d2(Data_in[1:0],E2,Data_out[3:0]);


endmodule