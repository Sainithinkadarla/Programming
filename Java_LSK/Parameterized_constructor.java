public class Parameterized_constructor
{
    public int data;
    Parameterized_constructor(int x)
    {
        data=x;
    }
    public static void main(String[] args)
    {
        Parameterized_constructor obj = new Parameterized_constructor(10);
        System.out.println(obj.data);
    }
}