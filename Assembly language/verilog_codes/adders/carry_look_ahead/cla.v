module cla(
	input [3:0]a,b,
	input ci,
	output [3:0]s,
	output [4:1]c);
	wire [3:0]p,g;
	genvar i;
	for(i=0;i<4;i=i+1)
	begin
	assign g[i]=a[i]&b[i];
	assign p[i]=a[i]|b[i];
	assign c[i+1]= g[i]|(p[i]&c[i]);
	end
	assign s[0] = a[0] ^ b[0] ^ ci;
	for (i=1 ; i<4; i=i+1)
	begin
	assign s[i] = a[i] ^ b[i] ^ c[i];
	end
endmodule

module cla_tb;

wire [3:0]s;
wire [4:1]c;
reg [3:0]a,b;
reg ci;

cla z(.a(a), .b(b), .ci(ci), .s(s), .c(c));

initial
begin
$monitor ("%b %b   %b %b",a,b,c[4], s);

a=4'b1001;
b=4'b0001;
ci= 1'b0;

end
endmodule

