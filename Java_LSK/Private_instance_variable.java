/*a class definition. 
To write this class you will need to demonstrate knowledge of and ability to apply the following skills:
Declare a private instance variable in a Java class
Initialize a private instance variable in a Java class
Implement an attribute as a private instance variable in a Java class*/
public class Private_instance_variable
{
    private int data=10; // declaring and initializing the private instance variable
    public static void main(String[] args)
    {
        char c = 'c';
        Private_instance_variable obj = new Private_instance_variable();//creating the object 
        System.out.println(obj.data);//accessing the private instance variable 
        System.out.println(c);//accessing the private instance variable 

    }
}