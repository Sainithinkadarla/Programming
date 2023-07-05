module half_adder (x,y,cin,s,c);
input x,y,cin;
output s,c;
assign s=x^y^cin;
assign c=(x&y)|(cin&(x|y));
endmodule
