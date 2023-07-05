

class Five
{
    
    public static void main(String[] args)
    {
        int i=0, j=3;
        int a[] ={1,34,4};


        try
        {
            a[3]=0;
            int k= j/i;

        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e.getMessage());
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }

        finally
        {
            System.out.println("Finally");
        }
    
    }
}