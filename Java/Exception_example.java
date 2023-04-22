import java.util.Scanner;
class Exception_example
{
    public static void main(String [] args)
    {
        int a = 10, b,c;
        Scanner sc = new Scanner(System.in);
        try 
        {
            b = sc.nextInt();
            c = a/b;
            System.out.println(c);
        }
        catch(Exception e)
        {
            System.out.println(e);
            System.out.println("Please enter the non-zero");
            b = sc.nextInt();
            c=a/b;
            System.out.println(c);
        }
        finally
        {
            System.out.println("End of the program");
        }

    }
}