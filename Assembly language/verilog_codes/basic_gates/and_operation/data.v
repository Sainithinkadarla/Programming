module data;
wire tf;
reg tx, ty;
andop fun( .x(tx), .y(ty), .f(tf));

initial 
begin
 $monitor(tx, ty," ",tf);

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
