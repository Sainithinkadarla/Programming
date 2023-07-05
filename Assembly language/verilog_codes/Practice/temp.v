//and operation 
module add (x,y,f);
input x,y;
output f;
assign f= x&y;
endmodule


//or operation 
module orop(x,y,f);
input x,y;
output f;
assign f  = x|y;
endmodule 


// not operation
module notop(x,y);
input x;
output y;
assign y=~x; 
endmodule

//nand operation
module nandop(x,y,f);
input x,y;
output f;
assign f=~(x&y);
endmodule

//nor operation

module norop(x,y,f);
input x,y;
output f;
assign f=~(x|y);
endmodule


//exor operation
module exorop (x,y,f);
input x,y;
output f;
assign f=x^y;
endmodule


module exnorop (x,y,f);
input x,y;
output f;
assign f=~(x^y);
endmodule



//testbench 
module texorop;
reg tx,ty;
wire tf;
exnorop func(.x(tx), .y(ty), .f(tf));

initial
begin
    $monitor(tx,ty,"->",tf);


    tx=1'b0;
    ty=1'b0;
    #5
    tx=1'b0;
    ty=1'b1;
    #5
    tx=1'b1;
    ty=1'b0;
    #5
    tx=1'b1;
    ty=1'b1;

end

endmodule
//testbench
module test;
reg tx, ty;
wire tf;

norop func(.x(tx), .y(ty), .f(tf));


initial     
begin
    $monitor (tx, ty,"->",tf);


    tx=1'b0;
    ty=1'b0;
    #5

    tx=1'b0;
    ty=1'b0;
    #5
    tx=1'b0;
    ty=1'b0;

    #5
    tx=1'b0;
    ty=1'b0;
end

endmodule

/*
//testbench for 1 variable
module notopt;
reg tx;
wire ty;

notop func(.x(tx), .y(ty));

initial
begin
$monitor(tx, "->",ty);
#5
tx=1'b0;
#5
tx=1'b1;

end
endmodule



//test bench for 2 variables
module data;
wire tf;
reg tx,ty;

norop func(.x(tx), .y(ty), .f(tf));

initial
begin 
    $monitor(tx, ty,"->" ,tf);
    tx=1'b0;
    ty=1'b0;
    #5
    
    tx=1'b0;
    ty=1'b1;
    #5
    
    tx=1'b1;
    ty=1'b0;
    #5
    
    tx=1'b1;
    ty=1'b1;
    
end
endmodule

*/