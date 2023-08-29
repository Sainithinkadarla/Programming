
public class Prim {

    public static void main(String[] args) throws NumberFormatException
    {
        int i =32;
        Long it = new Long("234124");
        Integer itt = new Integer(i);
        Float fl = new Float("4.231");

        System.out.println(it.toOctalString(it));
        System.out.println(Integer.toBinaryString(i));
        System.out.println(Integer.toOctalString(i));
        System.out.println(Integer.toHexString(i));

        char ch = 'c';
        Character c = new Character(ch);
        System.out.println(c.isUpperCase(c));

    }
}