// Program to create instance Method and to retrieve data from the file

// creating a class
// Note: class is a collection of instance variables and instance methods
public class Instance
{
    // creating an instance variable
    int data=10;

    // creating an instance method
    void method()
    {
        System.out.println(data);
    }

    // static keyword is used to in main function which allows it to run main function without creating an object
    public static void main(String[] args)
    {
        Instance obj = new Instance();
        obj.method();
    }
}