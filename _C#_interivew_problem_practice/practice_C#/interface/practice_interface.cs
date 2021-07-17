/*
What is an interface?
🟢 an interface is a way to achieve abstraction in C#
🟢 An interface is a completely "abstract class", which 
   can only contain abstract methods and properties (with empty bodies)
        Just like classes interfaces also contains properties, methods, delegates or events, 
        but only declarations and no implementation.
        doesn't allow to create an instance of an interface
        Interface in C# is a blueprint of a class.

🚩NOTE:
    🟩 If a class or a struct inherits from an interface, it must provide implmentation 
       for all interface members. Otherwise, we get a compiler error.
    🟩 Interfaces can inherit from other interfaces. A class that inherits this interface must provide
        implementation for all interface members in the entire interface inheritance chain.       
    🟩 we cannot create an instance of an Interface, but an interface refernce variable can point
        to a derived class object.


*/ 
using System;  
public interface IDrawable  
{  
    void draw();  
}  
public class Rectangle : IDrawable  
{  
    public void draw()  
    {  
        Console.WriteLine("drawing rectangle...");  
    }  
}  
public class Circle : IDrawable  
{  
    public void draw()  
    {  
        Console.WriteLine("drawing circle...");  
    }  
}  
public class TestInterface  
{  
    public void RunIt()
    {
        IDrawable d;  
        d = new Rectangle();  
        d.draw();  
        d = new Circle();  
        d.draw();  
    }
    public static void Main()  
    {  
        TestInterface d = new TestInterface();
        d.RunIt();
        /**OUTPUT
        - drawing rectangles
        - drawing circles
        */
    }  
}  
