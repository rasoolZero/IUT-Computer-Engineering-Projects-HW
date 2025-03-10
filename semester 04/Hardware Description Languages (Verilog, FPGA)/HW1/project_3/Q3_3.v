module Mux32to1_16bit(I0,I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,I11,I12,I13,I14,I15,I16,I17,I18,I19,I20,I21,I22,I23,I24,I25,I26,I27,I28,I29,I30,I31,S,O);
input [15:0] I0,I1,I2,I3,I4,I5,I6,I7,I8,I9,I10,I11,I12,I13,I14,I15,I16,I17,I18,I19,I20,I21,I22,I23,I24,I25,I26,I27,I28,I29,I30,I31;
output [15:0] O;
input [4:0] S;
wire [15:0] outputs1[7:0];
Mux4to1_16bit MUX0(I0,I1,I2,I3,S[1:0],outputs1[7]);
Mux4to1_16bit MUX1(I4,I5,I6,I7,S[1:0],outputs1[6]);
Mux4to1_16bit MUX2(I8,I9,I10,I11,S[1:0],outputs1[5]);
Mux4to1_16bit MUX3(I12,I13,I14,I15,S[1:0],outputs1[4]);
Mux4to1_16bit MUX4(I16,I17,I18,I19,S[1:0],outputs1[3]);
Mux4to1_16bit MUX5(I20,I21,I22,I23,S[1:0],outputs1[2]);
Mux4to1_16bit MUX6(I24,I25,I26,I27,S[1:0],outputs1[1]);
Mux4to1_16bit MUX7(I28,I29,I30,I31,S[1:0],outputs1[0]);

wire [15:0] outputs2[3:0];

Mux4to1_16bit MUX8(outputs1[7],outputs1[6],outputs1[5],outputs1[4],S[3:2],outputs2[3]);
Mux4to1_16bit MUX9(outputs1[3],outputs1[2],outputs1[1],outputs1[0],S[3:2],outputs2[2]);

wire [1:0] Select;
assign Select[0] = S[4];
assign Select[1] = 1'b0;
assign outputs2[1] = 0;
assign outputs2[0] = 0;
Mux4to1_16bit MUX10(outputs2[3],outputs2[2],outputs2[1],outputs2[0],Select,O);


endmodule