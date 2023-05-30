class Resource
{
    int data;
    boolean flag=false;

    synchronized int get()
    {
        while(!flag)
        {
            try
            {
                wait();
                Thread.sleep(1000);
            }
            catch(InterruptedException e)
            {
                System.out.println(e);
            }
        }
        flag=false;
        System.out.println("got: "+data);
        notify();
        return data;
    }
    synchronized void put(int data)
    {
        while(flag)
        {
            try
            {
                wait();
                Thread.sleep(1000);
            }
            catch(InterruptedException e)
            {
                System.out.println(e);
            }
        }
        this.data=data;
        flag=true;
        System.out.println("put: "+data);
        notify();
    }
}

class Writer implements Runnable
{
    Resource r;
    Writer(Resource r)
    {
        this.r=r;
        new Thread(this,"Sender Thread").start();
    }
    public void run()
    {
        int i =0 ;
        while(i<7)
        {
            r.put(i++);
        }
    }
}

class Reader implements Runnable
{
    Resource r;
    Reader(Resource r)
    {
        this.r =r;
        new Thread(this, "Receiver Thread").start();
    }
    public void run()
    {
        int i=0;
        while (i<7) {
            r.get();
        }
    }
}

public class InterTC {
    public static void main(String[] args)
    {
        Resource r = new Resource();

        new Reader(r);
        new Writer(r);
    }
    
}
