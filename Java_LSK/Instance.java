public class Instance
{
    int data=10;
    void method()
    {
        System.out.println(data);
    }
    public static void main(String[] args)
    {
        Instance obj = new Instance();
        obj.method();
    }
}