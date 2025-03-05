module Decoder1to2(input I,input E,output O0,output O1);

assign O0 = E & !I;
assign O1 = E &  I;

endmodule