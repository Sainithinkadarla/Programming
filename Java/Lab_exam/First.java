class App
{
    int a;
    char b;

    App()
    {
        a = 10;
        b='h';
    }

    App(int x, char c)
    {
        a=x;
        b=c;
    }

    App(App obj)
    {
        obj.a=a;
        obj.b=b;
    }

    void display(App obj)
    {
        System.out.println(obj.a+""+obj.b);
        System.out.println(obj.b);
        System.out.println("-----------------------");
    }

    void display(int p, char r)
    {
        System.out.println(p);
        System.out.println(r);
        System.out.println("-----------------------");
    }

    static void method()
    {
        System.out.println("This is a static methos");

    }
}

class First
{
    public static void main(String [] args)
    {
        App app = new App();
        App app1 = new App(32,'c');
        App app2 = new App(32,'d');
        App app3 = new App(app2);

        App.method();

        app.display(app);
        app1.display(app1.a,app1.b);
        app2.display(app);
        app3.display(app1.a,app1.b);
        

    }
}