using System;

interface IA
{
    void AMethod();
}
class A : IA
{
    public void AMethod()
    {
        Console.WriteLine("AMethod");
    }
}

interface IB
{
    void BMethod();
}
class B : IB
{
    public void BMethod()
    {
        Console.WriteLine("BMethod");
    }
}

class AB : IA, IB
{
    A a = new A();
    B b = new B();

    public void AMethod()
    {
        a.AMethod();
    }
    public void BMethod()
    {
        b.BMethod();
    }
}

class Program
{
    public static void Main()
    {
        AB abObj = new AB();
        ABObj.AMethod();
        ABObj.BMethod();
    }
}