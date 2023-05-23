/*
 * This is written by referncing the textbook example converted to convienent
 * 
 * Creating the threads by extending the Thread class
 */

class NewThread extends Thread
{
    String name;
    NewThread(String name)
    {
        super(name); // Call to the Thread class constructor
        this.name= name;
        start();
    }
    public void run()
    {
        for(int i=0; i<=5; i++)
        {
            System.out.println("Thread is running "+ name);
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class ThreadDemo_TC 
{
    public static void main (String[] args)
    {
        new NewThread("Thread 1");
        new NewThread("Thread 2");
        new NewThread("Thread 3");
        new NewThread("Thread 4");
    }
}
