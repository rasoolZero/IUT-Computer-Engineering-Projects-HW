module FA4bit(input [0:3] A,input [0:3] B,input cin,output cout,output [0:3] Sum);

wire cout1,cout2,cout3;
FA FA1(A[3],B[3],cin,cout1,Sum[3]);
FA FA2(A[2],B[2],cout1,cout2,Sum[2]);
FA FA3(A[1],B[1],cout2,cout3,Sum[1]);
FA FA4(A[0],B[0],cout3,cout,Sum[0]);

endmodule