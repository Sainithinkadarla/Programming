abstract class app1
{
    abstract void show();

    void method()
    {
        System.out.println("COncrete method of abstract classes");
    }
}


interface Executable
{
    void method_i();
    void method_j();
}



class ForInterface implements Executable
{
    public void method_i()
    {
        System.out.println("Interfacemethod i");
    }

    public void method_j()
    {
        System.out.println("interface method j");
    }
}

class ForAClass extends app1
{
    void show()
    {
        System.out.println("abstract method show");
    }
}

public class Four {
    public static void main(String[] args)
    {

        ForInterface i = new ForInterface();
        ForAClass a = new ForAClass();

        i.method_i();
        i.method_j();

        a.show();
        a.method();
    }
    
}
