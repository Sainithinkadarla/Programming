class Demo implements Runnable
{
    static int j=0;
    public void run()
    {
        ++j;
        System.out.println("Thread is executing"+j);
    }
}
class Thread_demo
{
    public static void main(String[] args)
    {
        Demo d = new Demo();
        Demo dd = new Demo();
        Thread t1 = new Thread(d,"Demo 1");
        Thread t2 = new Thread(dd,"Demo 2");
        t1.start();
        t2.start();
        
    }
}