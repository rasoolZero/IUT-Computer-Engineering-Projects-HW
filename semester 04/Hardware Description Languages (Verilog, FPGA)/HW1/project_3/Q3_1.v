module Mux4to1_1bit(input I0,input I1,input I2,input I3,input [1:0]S,output O);

//assign O = (!S[0]&!S[1]&I0) | (S[0]&!S[1]&I1) | (!S[0]&S[1]&I2) | (S[0]&S[1]&I3);
wire andGatesOutput[3:0];
wire notS[1:0];

not not1(notS[0],S[0]),
 	not2(notS[1],S[1]);

and 	and1(andGatesOutput[0],notS[0],notS[1],I0),
 	and2(andGatesOutput[1],S[0],notS[1],I1),
 	and3(andGatesOutput[2],notS[0],S[1],I2),
 	and4(andGatesOutput[3],S[0],S[1],I3);

or orGate(O,andGatesOutput[0],andGatesOutput[1],andGatesOutput[2],andGatesOutput[3]);

endmodule