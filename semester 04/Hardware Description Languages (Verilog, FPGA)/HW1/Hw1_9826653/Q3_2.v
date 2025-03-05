module Mux4to1_16bit( I0, I1, I2, I3,S, O);
input [15:0] I0,I1,I2,I3;
input [1:0] S;
output [15:0] O;
Mux4to1_1bit MUX0(I0[0],I1[0],I2[0],I3[0],S,O[0]);
Mux4to1_1bit MUX1(I0[1],I1[1],I2[1],I3[1],S,O[1]);
Mux4to1_1bit MUX2(I0[2],I1[2],I2[2],I3[2],S,O[2]);
Mux4to1_1bit MUX3(I0[3],I1[3],I2[3],I3[3],S,O[3]);
Mux4to1_1bit MUX4(I0[4],I1[4],I2[4],I3[4],S,O[4]);
Mux4to1_1bit MUX5(I0[5],I1[5],I2[5],I3[5],S,O[5]);
Mux4to1_1bit MUX6(I0[6],I1[6],I2[6],I3[6],S,O[6]);
Mux4to1_1bit MUX7(I0[7],I1[7],I2[7],I3[7],S,O[7]);
Mux4to1_1bit MUX8(I0[8],I1[8],I2[8],I3[8],S,O[8]);
Mux4to1_1bit MUX9(I0[9],I1[9],I2[9],I3[9],S,O[9]);
Mux4to1_1bit MUX10(I0[10],I1[10],I2[10],I3[10],S,O[10]);
Mux4to1_1bit MUX11(I0[11],I1[11],I2[11],I3[11],S,O[11]);
Mux4to1_1bit MUX12(I0[12],I1[12],I2[12],I3[12],S,O[12]);
Mux4to1_1bit MUX13(I0[13],I1[13],I2[13],I3[13],S,O[13]);
Mux4to1_1bit MUX14(I0[14],I1[14],I2[14],I3[14],S,O[14]);
Mux4to1_1bit MUX15(I0[15],I1[15],I2[15],I3[15],S,O[15]);

endmodule
