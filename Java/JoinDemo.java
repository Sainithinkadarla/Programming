/*
 * This is written by referencing textbook \
 * Here we are running a thread in constructor itself
 *      run() method is also defined in a seperate class
 *      In main class,
 *              * we are creating the object for the class 
 *                where its constructor creating the thread
 *              * using the join method to first obj to wait for it to execute
 *              * Same like that to second object 
 */
class NewThread implements Runnable
{
    Thread t;
    String name;
    NewThread(String name)
    {
        this.name= name;
        t= new Thread(this, name);
        System.out.println("New thread: " + t);
        t.start();

    }
    public void run()
    {
        for(int i=0; i<=5; i++)
        {
            System.out.println("Thread is running "+ name);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}
class JoinDemo
{
    public static void main(String[] args)
    {
        // Creating the thread in its constructor and waits for it to execute as we used the join() method
        NewThread t1 =new NewThread("Thread 1");
        try {
            t1.t.join(); // It indicates other thread to wait and execute other threads after it
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        NewThread t2 =new NewThread("Thread 2");
        try {
            t2.t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        NewThread t3 =new NewThread("Thread 3");
        NewThread t4 =new NewThread("Thread 4");
        
        System.out.println(t1.t.isAlive());//it gets false as O/P because finished the execution earlier 
        System.out.println(t2.t.isAlive());//
        System.out.println(t3.t.isAlive());
        System.out.println(t4.t.isAlive());
        
    }
}
