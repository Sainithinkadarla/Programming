/*
 * This example from textbook
 * This program reads each character from given line input
 * prints the each character from the input
 * we uses the read() which returns the integer so we typecast it too
 */

import java.io.*;

public class ReadChar {
    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char c;
        do 
        {
            c= (char) br.read();
            System.out.println(c);
        }while(c!='q');

    }
}