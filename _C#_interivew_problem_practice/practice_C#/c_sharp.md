# OOP

## Abstraction

🟠 Data abstraction is the process of hiding certain details and showing only essential information to the user.
🟠 _Abstraction can be achieved with either abstract classes or interfaces_

🟠 Difference between Abstract Class and Interface
[note](https://www.geeksforgeeks.org/difference-between-abstract-class-and-interface-in-c-sharp/)

##### Should I use an abstract class or an interface?

Abstract classes provide you the flexibility to have certain concrete methods and some other methods that the derived classes should implement. By contrast, if you use interfaces, you would need to implement all the methods in the class that extends the interface. An abstract class is a good choice if you have plans for future expansion – i.e. if a future expansion is likely in the class hierarchy. If you would like to provide support for future expansion when using interfaces, you’ll need to extend the interface and create a new one.

On a different note, it is easy to add a new interface to the hierarchy if need be. However, if you already have an abstract class in your hierarchy, you can’t add another—i.e., you can add an abstract class only if none are available. You should use an interface if you want a contract on some behavior or functionality. You should not use an interface if you need to write the same code for the interface methods. In this case, you should use an abstract class, define the method once, and reuse it as needed. Do use interfaces to decouple your application’s code from specific implementations of it, or to restrict access to members of a certain type.

## Inheritance

## Encapsulation

## Polymorphism

#### Generic Interview Question

What is derived class object?
What is reference variable?
_different between objects and reference_
[Answer to the above questions](https://www.youtube.com/watch?v=N8IeMYsdgAY&list=PLEH2kL-crMGErJOCjwLtrbH8pQ-K11ZAr&index=1)
What is parent class reference variable?
