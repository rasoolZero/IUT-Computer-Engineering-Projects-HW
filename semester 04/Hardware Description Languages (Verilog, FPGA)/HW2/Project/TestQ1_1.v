module TestQ1_1;
wire [7:0] output_data;
wire serial_out;

reg clk=0,reset=0,serial_in=0,shift_left=0,shift_right=0,load=0;
reg [7:0] input_data = 1;

myReg register(clk, reset, input_data, output_data, load, shift_right, shift_left, serial_in, serial_out);



always forever #7 clk=~clk;
always forever #10 load=~load;
always forever #30 reset=~reset;
always forever #40 shift_left=~shift_left;
always forever #50 shift_right=~shift_right;
always forever #100 {serial_in,input_data} = $random();

initial  $monitor("data = %b -- serial_out = %b",output_data,serial_out);

endmodule