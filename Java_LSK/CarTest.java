class Car
{
    String brand, model, year;

    Car(String brand, String model, String year)
    {
        this.brand = brand;
        this.model = model;
        this.year  = year;
    }

    void displayDetails()
    {
        System.out.println("Brand: "+brand);
        System.out.println("Model: "+model);
        System.out.println("Year: "+year);
    }
}

class CarTest
{
    public static void main(String[] args)
    {
        Car c1 = new Car("BWM","GT220", "2020");
        Car c2 = new Car("Mercedes","CLA", "2021");

        System.out.println("\nFirst car\n------------------");
        c1.displayDetails();
        System.out.println("\n\nSecond car\n------------------");
        c2.displayDetails();
    }
}