class app1
{

    void show1()
    {
        System.out.println("app1");
    }
}

class app2 extends app1
{
    void show2()
    {
        System.out.println("app2");
    }
}

class app3 extends app2
{
    void show2()
    {
        System.out.println("app3");
    }
}

class app4 extends app2
{
     void show4()
    {
        System.out.println("app4");
    }
}



public class Second {

public static void main(String[] args)
{
app4 a1 = new app4();    
app3 a2 = new app3();    
a2.show1();
a2.show2();
a2.show2();


a1.show1();
a1.show2();
a1.show4();


}
    
}
