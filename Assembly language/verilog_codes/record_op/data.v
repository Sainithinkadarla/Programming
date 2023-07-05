module fullsubt_b;
reg a;
reg b;
reg c;
wire borrow;
wire difference;
fs uut (.a(a), .b(b),.c(c),.borrow(borrow),.difference(difference) );
initial begin
#10 a=1’b0;b=1’b0;c=1’b0;
#10 a=1’b0;b=1’b0;c=1’b1;
#10 a=1’b0;b=1’b1;c=1’b0;
#10 a=1’b0;b=1’b1;c=1’b1;
#10 a=1’b1;b=1’b0;c=1’b0;
#10 a=1’b1;b=1’b0;c=1’b1;
#10 a=1’b1;b=1’b1;c=1’b0;
#10 a=1’b1;b=1’b1;c=1’b1;
#10
$stop;
end
