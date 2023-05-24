/* 
 * This is example from textbook
 * Creating the thread by implementing the Runnable interface
*/
class NewThread implements Runnable
{
    static int j =0;

    Thread t;
    NewThread(String msg)
    {
        t= new Thread(this, msg);
        t.start();
    }
    public void run()
    {
        for(int i=0; i<=10; i++)
        {
            System.out.println("Thread is running "+ t.getName());
        }
    }
}

public class ThreadDemo {
    public static void main(String[] args)
    {
        new NewThread("Thread 1");
        new NewThread("Thread 2");
        new NewThread("Thread 3");
        new NewThread("Thread 4");
    }
    
}
