# Interface

What is an interface?

```
🟢 an interface is a way to achieve abstraction in C#
🟢 An interface is a completely "abstract class", which
   can only contain abstract methods and properties (with empty bodies)
        Just like classes interfaces also contains properties, methods, delegates or events,
        but only declarations and no implementation.
        doesn't allow to create an instance of an interface
        Interface in C# is a blueprint of a class.
[practice_interface.cs covers the above 2 points]
🟢 Interfaces can contain instance methods, properties, events, indexers, or any combination of those four member types. Interfaces may contain static constructors, fields, constants, or operators.
    👉 _An interface can't contain instance fields, instance constructors, or finalizers._
    👉 Interface members are public by default, and you can explicitly specify accessibility modifiers, such as public, protected, internal, private, protected internal, or private protected. A private member must have a default implementation.
🚩NOTE:
    🟩 If a class or a struct inherits from an interface, it must provide implmentation
       for all interface members. Otherwise, we get a compiler error.
    🟩 Interfaces can inherit from other interfaces. A class that inherits this interface must provide
        implementation for all interface members in the entire interface inheritance chain.
    🟩 we cannot create an instance of an Interface, but an interface refernce variable can point
        to a derived class object.
    [chained_inheritance.cs covers the above 3 points]
```

Explicit interfaces implementation

```
If there are two interfaces with the same signature, same properties, same methods
and a class is inheriting those two interfaces then, which interface should be invoked becomes uncertain.
Solution-1:
    Typecast the object that is being declared to the desired interface.
Solution-2:
    Explicit interface implementation

```
