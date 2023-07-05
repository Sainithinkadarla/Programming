module data;
wire tf;
reg tx, ty;
not_op fun( .x(tx), .f(tf));

initial 
begin
 $monitor(tx," ",tf);

tx=1'b0;

#5

tx=1'b1;


end
endmodule
