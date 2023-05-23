class NewThread implements Runnable
{
    static int j =0;

    Thread t;
    NewThread()
    {
        t= new Thread(this, "Thread "+ (++j));
        t.start();
    }
    public void run()
    {
        for(int i=0; i<=10; i++)
        {
            System.out.println("Thread is running"+ t.getName());
        }
    }
}

public class ThreadDemo {
    public static void main(String[] args)
    {
        new NewThread();
        new NewThread();
        new NewThread();
        new NewThread();
    }
    
}
