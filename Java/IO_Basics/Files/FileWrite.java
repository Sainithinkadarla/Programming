import java.io.*;

public class FileWrite {
    public static void main(String[] args)
    {
        int i;
        FileInputStream fin =null;
        FileOutputStream fout= null;
        if(args.length!=2)
        {
            System.out.println("Please give valid arguments \n take look at java command");
            return ;
        }
        try
        {
            fin = new FileInputStream(args[0]);
            fout = new FileOutputStream(args[1]);

            do 
            {
                i = fin.read();
                if(i!=-1)
                {
                    fout.write(i);
                }
            }while(i!=-1);
        }
        catch(IOException e)
        {
            System.out.println("IO Error: "+e);
        }
        finally
        {
            try 
            {
                fin.close();
                fout.close();
            }
            catch(IOException e)
            {
                System.out.println("Error at closing a file");
            }
        }
    }
}
