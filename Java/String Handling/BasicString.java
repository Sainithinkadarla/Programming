class Test
{
    public String toString()
    {
        return "This is a testing class to demonstrate the toString()";
    }
}

class BasicString
{
    public static void main(String[] args)
    {
        //Character array to create String
        char chars[] = {'S','a','i','N','i','t','h','i','n'};  
        String Schars = new String(chars);

        String Srange = new String(chars, 3,6);

        String Scopy = new String(Srange);

        //Byte array to create a String

        byte ascii_values[] ={65,66,67,68,69,70};

        String Sbytes = new String(ascii_values);
        String SBrange = new String(ascii_values,2,4);

        //String literal
        String s = "This is String literal";

        //String concatenation
        String Joint = "Hi "+ "Bro" +" How "+"are "+"you ?";

        //Demonstration of toString() method
        Test t = new Test();
        String to_string_demo = "Calling the toString() of Test class implicitly: "+t;


        System.out.println(Schars);
        System.out.println(Srange);
        System.out.println(Scopy);
        System.out.println(Sbytes);
        System.out.println(SBrange);

        //To get length of the String
        System.out.println(SBrange.length());


        System.out.println(s);
        System.out.println(Joint);

        System.out.println("toString() demo\n\n\n");
        System.out.println(to_string_demo);
        System.out.println(t);
    }
}