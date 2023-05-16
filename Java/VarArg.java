class VarArg {
    void test(int... v)
    {
        System.out.println("Number of arguments passed: "+v.length);

        for(int x:v)
        {
            System.out.println(x);

        }
    }
    public static void main(String[] args)
    {
        VarArg obj = new VarArg();

        obj.test(10);
        obj.test(10,12,767);
        obj.test(10,324,24,4);

        
    }
}
