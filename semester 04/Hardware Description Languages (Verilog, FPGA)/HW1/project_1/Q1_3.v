module BitCounter(input [0:6] Data_in,output [0:2] Data_out);

wire cout1,cout2,cout3,sum1,sum2;

FA fa1(Data_in[0],Data_in[1],Data_in[2],cout1,sum1);
FA fa2(Data_in[3],Data_in[4],Data_in[5],cout2,sum2);


FA fa3(sum1,sum2,Data_in[6],cout3,Data_out[2]);
FA fa4(cout1,cout2,cout3,Data_out[0],Data_out[1]);

endmodule