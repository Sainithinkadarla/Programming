module data;
wire ts,tc;
reg tx, ty;
half_adder fun( .x(tx), .y(ty), .s(ts), .c(tc));

initial 
begin
 $monitor(tx, ty,"    ",ts," ",tc);

tx=1'b0;
ty=1'b0;

#5

tx=1'b1;
ty=1'b0;

#5

tx=1'b0;
ty=1'b1;

#5

tx=1'b1;
ty=1'b1;


end
endmodule
