module fa (x,y,cin,s,c);
input x,y,cin;
output s,c;
assign s=x^y^cin;
assign c=(x&y)|(cin&(x|y));
endmodule


module rpa(
			input [3:0]a,b,
			input cin,
			output [3:0]s, cout);
fa op(a[0], b[0], cin, s[0], cout[0]);

genvar i;


generate 
	for(i=1; i<4; i=i+1) begin
		 fa op(a[i], b[i], cout[i-1], s[i], cout[i]);
end

endgenerate 
endmodule


