module data;
wire ts,tc;
reg tx, ty, tcin;
half_adder fun( .x(tx), .y(ty), .cin(tcin) ,  .s(ts), .c(tc));

initial 
begin
 $monitor(tx, ty,tcin,"    ",ts," ",tc);

tx=1'b0;
ty=1'b0;
tcin=1'b0;
#5

tx=1'b0;
ty=1'b0;
tcin=1'b1;

#5

tx=1'b1;
ty=1'b0;
tcin=1'b0;
#5

tx=1'b1;
ty=1'b0;
tcin=1'b1;

#5

tx=1'b0;
ty=1'b1;
tcin=1'b0;
#5

tx=1'b0;
ty=1'b1;
tcin=1'b1;

#5
tx=1'b1;
ty=1'b1;
tcin=1'b0;
#5

tx=1'b1;
ty=1'b1;
tcin=1'b1;


end
endmodule
