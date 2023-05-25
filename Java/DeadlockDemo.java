class Resources
{
    String msg;

    Resources(String msg)
    {
        this.msg = msg;
        System.out.println(msg +" created");
    }

}

public class DeadlockDemo {
    public static void main(String[] args)
    {
    
    Resources resource1 = new Resources("Resource 1");
    Resources resource2 = new Resources("Resource 2");


    Thread thread1 = new Thread(() -> {
        synchronized(resource1)
        {
            System.out.println(resource1.msg+" is locked by Thread 1");

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }

            synchronized(resource2)
            {
                System.out.println(resource2.msg+"is locked by thread 1");
            }

        }
    });
    Thread thread2 = new Thread(() -> {
        synchronized(resource1)
        {
            System.out.println(resource1.msg+" is locked by Thread 2");

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }

            synchronized(resource2)
            {
                System.out.println(resource2.msg+"is locked by thread 2");
            }

        }
    });

    thread1.start();
    thread2.start();
        
    }
    
}
