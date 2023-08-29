module adderbit(a,b,cin,sum,cout); 
input [3:0]a,b;
input cin;
output [3:0]sum;
output cout;
assign {cout,sum}=a-b-cin;
endmodule

module test;
reg [3:0]a,b;
reg cin;
wire [3:0]sum;
wire cout;

adderbit func(.a(a), .b(b), .cin(cin), .sum(sum), .cout(cout));

initial begin

$monitor(sum);

a=0;
b=0;
cin=0;
#5
a=6;
b=2;
cin=1;

end
endmodule