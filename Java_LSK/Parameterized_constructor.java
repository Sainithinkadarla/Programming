// Program to demonstrate Parameterized constructor
public class Parameterized_constructor
{
    public int data;//instance variable
    Parameterized_constructor(int x)//parameterized constructor 
    {
        data=x;//assigning data 
    }
    public static void main(String[] args)
    {
        Parameterized_constructor obj = new Parameterized_constructor(10);// calling constructor and passing value to assign in instance variable
        System.out.println(obj.data); //printing data
    }
}
