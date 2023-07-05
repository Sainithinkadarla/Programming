module enco(in,y);

input [7:0]in;
output [2:0]y;

assign 

//y[0]= in[1] + in[3] + in[5] + in[7],
//y[1]= in[2] + in[3] + in[6] + in[7],
//y[2]= in[4] + in[5] + in[6] + in[7];

y[0]=(in[6]&((~in[4]&~in[2]&in[1])|(~in[4]&in[3])|in[5]))|in[7],
y[1]=((~in[5]&~in[4])&(in[2]|in[3]))| (in[6]|in[4]),
y[2]= in[4] + in[5] + in[6] + in[7];


endmodule

module enco_tb;

reg [7:0]tin;
wire [2:0]ty;

enco func(.in(tin), .y(ty));

initial begin


$monitor("%b        %b",tin,ty);

tin=8'b00011000;

#110

tin=8'b0000011;

end
endmodule


