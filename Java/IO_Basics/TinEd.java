import java.io.*;

public class TinEd {
    public static void main(String[] args) throws IOException
    {
        String[] data = new String[100];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the data");
        for(int i=0; i<100; i++)
        {
            data[i] = br.readLine();
        }
    }
    
}
