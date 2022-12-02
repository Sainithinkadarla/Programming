import java.util.Scanner;
public class Play_with_OOPs
{
    int x,y;
    Play_with_OOPs()
    {
        x=1;
        y=2;
    }

    Play_with_OOPs(int a, int b)
    {
        x=a;
        y=b;
    }
    void display()
    {
        System.out.println("x="+x+" y="+y);
    }
    void min_or_max()
    {
        if(x>y)
        {
            System.out.println("x is maximum");
            System.out.println("y is minimum");
        }
        else
        {
            System.out.println("x is minimum");
            System.out.println("y is maximum");
        }
    }
    public static void main(String[] args)
    {
        int p,q;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter x");
        p=sc.nextInt();
        System.out.println("Enter y");
        q=sc.nextInt();
        Play_with_OOPs obj1 = new Play_with_OOPs();
        Play_with_OOPs obj2 = new Play_with_OOPs(100,20);
        Play_with_OOPs obj3 = new Play_with_OOPs(p,q);
        
        System.out.println("Executing object1 methods");
        obj1.display();
        obj1.min_or_max();
        System.out.println("Executing object2 methods");
        obj2.display();
        obj2.min_or_max();
        System.out.println("Executing object3 methods");
        obj3.display();
        obj3.min_or_max();
    }
}