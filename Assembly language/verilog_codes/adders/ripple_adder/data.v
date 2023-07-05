module rpa_tb;

reg [3:0]ta, tb;
reg tcin;
wire [3:0]ts,tc;

rpa op1 (.a(ta), .b(tb), .cin(tcin), .s(ts), .cout(tc));

initial begin


$monitor("a= %b b= %b  ----> cout= %b  sum= %b",ta,tb, tc[3], ts);
tcin = 1'b0;
ta= 4'b1010;
tb=4'b1111;
end
endmodule
