import java.io.*;


public class FileIn {
    public static void main(String[] args)
    {
        FileInputStream fin;
        int i;
        if(args.length !=1)
        {
            System.out.println("Please give the file name");
            return ;
        }

        try 
        {
            fin = new FileInputStream(args[0]);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Cannot open this file");
            return ;
        }

        try
        {
           do
           {
            i = fin.read();
            if(i !=-1) System.out.print((char)i);
           }while(i!=-1);

        }
        catch(IOException e)
        {
            System.out.println("Cannot read this file");
            return;
        }
        finally
        {
            try
            {
                fin.close();
            }
            catch(IOException e)
            {
                System.out.println("Cannot close this file");
            }
        }
    }
    
}
