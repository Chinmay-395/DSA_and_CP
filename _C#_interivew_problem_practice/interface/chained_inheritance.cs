using System;
interface ICustomer1
{
	void Print1();
}
interface ICustomer2:ICustomer1
{
	void Print2();
}
/*
    ICustomer2 inherits from ICustomer1
    and Customer(class) inherits from ICustomer2
    thus Customer(class) can inherit from ICustomer1
    cause of inheritance chaining
*/
public class Customer:ICustomer2
{
	public void Print2()
	{
		Console.WriteLine("PRINT2");
	}
	
	public void Print1()
	{
		Console.WriteLine("PRINT1");
	}
}

public class Person
{
	public static void Main()
	{
        /* here we defined "Cust" as the object of Customer class of the type ICustomer1 interface 
            Thus we cannot access the ICustomer2 implementation even though it inherits ICustomer2
        */
		ICustomer1 Cust = new Customer();
		Cust.Print1();
        /* here we defined "Cust2" as the object of Customer class of the type ICustomer2 interface;
            Since ICustomer2 inherits from ICustomer1 
            thus, we can access all the chained interface inheritance implementation.
        */
		ICustomer2 Cust2 = new Customer();
		Cust2.Print1();
		Cust2.Print2();
	}
	
}
