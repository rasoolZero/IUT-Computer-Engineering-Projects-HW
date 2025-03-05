module FA(A,B,Cin,Cout,Sum);
input A,B,Cin;
output Cout,Sum;
wire Cout1,Cout2,Sum1;

HA ha1(A,B,Sum1,Cout1);
HA ha2(Cin,Sum1,Sum,Cout2);

assign Cout=Cout1 | Cout2;


endmodule