
class Stack 
{
    int[] stack; 
    int size;
    int top=-1;
    
    Stack(int size)
    {
        stack = new int[size];
    }
    
    
    void push(int x) throws overflow
    {
        if(top==size-1)
        {
            throw new overflow();
        }
        stack[++top] = x;
        
    }
    
    void pop() throws Underflow
    {
        if(top==-1) throw new Underflow();
        
        int del = stack[top--];
        System.out.println(del);
    }
}


 class overflow extends Exception
{
    overflow()
    {
        super("Cannot push");

    }
}
 class Underflow extends Exception
{
    Underflow()
    {
        super("Cannot pop because it is empty");

    }
}
public class Six {
    public static void main(String[] args)
    {
        Stack s  = new Stack(4);
        try
        {
            s.push(10);
            s.push(10);
            s.push(10);
            s.push(10);
            s.push(10);
            
        }
        catch(overflow e)
        {
            System.out.println(e.getMessage());
        }

        try
        {
            s.pop();
            s.pop();
            s.pop();
            s.pop();
            s.pop();
            s.pop();
            s.pop();
        }
        catch(Underflow e)
        {
            System.out.println(e.getMessage());
        }
        
    }
    
}
