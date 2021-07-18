/**
- The abstract keyword is used to create abstract classes
- An abstract class is incomplete and hence cannot be instantiated
- An abstract class only be used as base class
- An abstract class cannot be sealed("sealed" is a type of access-modifer)
- An abstract class may contain abstract members(methods,properties,indexers and events), but not mandatory
🟢 A non-abstract class derived from an abstract class must provide implementations for all inherited abstract memebers
🚩 NOTE:
- If a class inherits an abstract class, there are 2 options available for that class
    🟩 Option-1:
        Provide implementation for all the members inherited from the base abstract
    🟩 Option-2:
        If the class does not wish to provide implmentation for all the abstract members inherited from
        the abstract class, then the class has to be marked as abstract.
    🟩 you cannot create an instance of a abstract class but an abstract class reference variable 
        can point to a derived class object.
*/

using System;
public abstract class Customer
{
    public abstract void Print();
}

public class Program : Customer
{
    public override void Print()
    {
        Console.WriteLine("PRINT METHOD");
    }
    public static void Main()
    {
        Program P = new Program();
        P.Print();
    }
}