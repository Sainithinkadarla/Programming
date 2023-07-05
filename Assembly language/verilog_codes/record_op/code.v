module fs(a, b, c, borrow, difference);
input a;
input b;
input c;
output borrow;
output different;
wire d,e,f;
xor(difference,a,b,c);
and(d,~a,b);
and(e,b,c);
and(f,~a,c);
or(borrow,d,e,f);
endmodule




