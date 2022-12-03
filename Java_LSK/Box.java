public class Box
{
    private double height;
    private double width;
    private double length;    

    Box(double h, double w, double l)
    {
        height=h;
        width=w;
        length=l;
    }     

    public Boolean isTall()
    {
        if (height > width && height > length)
            return true;
        else 
            return false;
    }
        
    public static void main(String[] args)
    {   
        double height = 5.5;
        double width = 3.5;
        double length = 2.5;
    
        Box myBox = new Box(height, width, length);
        if (myBox.isTall())
            System.out.println("Box is taller than it is wide or long");
        else
            System.out.println("Box is not taller than it is wide and long");
    }
    
}