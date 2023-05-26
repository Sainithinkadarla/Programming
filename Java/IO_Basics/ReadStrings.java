/*
 * This example from textbook
 * This program uses readLine() which takes the string returns the string and prints it 
 */

 import java.io.*;

public class ReadStrings {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s;
        do 
        {
            s = br.readLine();
            System.out.println(s);
        }while(!s.equals("stop") && !s.equals("stop ") );
    }
}
