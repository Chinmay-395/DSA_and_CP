using System;
interface I1
{
	void InterfaceMethod();
}
interface I2
{
	void InterfaceMethod();
}
public class Program:I1,I2
{
	void I1.InterfaceMethod()
	{
	Console.WriteLine("I1 interface");
	}
	void I2.InterfaceMethod()
	{
		Console.WriteLine("I2 interface");
	}
	public void InterfaceMethod()
	{
		Console.WriteLine("THE interface method which isn't explicitly defined");
	}
	/**
        If you dont explicitly 
    */
	public static void Main()
	{
        // Here "P" is not an object it is object reference variable which is pointing to an "Program" object in the memory
		Program P = new Program();
		P.InterfaceMethod();
		// interface reference variable
		((I1)P).InterfaceMethod();
		((I2)P).InterfaceMethod();
		
	}
	
}
