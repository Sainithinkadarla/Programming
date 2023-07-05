module deco(in,d);
input [2:0]in;
output [7:0]d;

assign  d[0] = (~in[0]&~in[1]&~in[2]),
	d[1]= (~in[0]&~in[1]&in[2]),
	d[2]= (~in[0]&~in[1]&in[2]),
	d[3]= (~in[0]&in[1]&in[2]),
	d[4]= (in[0]&~in[1]&~in[2]),
	d[5]= (in[0]&~in[1]&in[2]),
	d[6]= (in[0]&in[1]&~in[2]),
	d[7]= (in[0]&in[1]&in[2]);
endmodule

module deco_tb;

reg [2:0]tin;

wire [7:0]td;

deco func( .in(tin), .d(td));

initial begin

$monitor("%b        %b",tin,td);
//tin[0] = 0;
//tin[1] = 0;
//tin[2] = 0;

tin=3'b000;

#110

tin = 3'b101;
//tin[0] = 1;
//tin[1] = 0;
//tin[2] = 1;

end
endmodule
