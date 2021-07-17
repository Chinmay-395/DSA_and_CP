using System;
interface IEquatable<T>
{
    bool Equals(T obj);
}
public class Car : IEquatable<Car>
{
    public string Make {get; set;}
    public string Model { get; set; }
    public string Year { get; set; }

    // Implementation of IEquatable<T> interface
    public bool Equals(Car car)
    {
        return (this.Make, this.Model, this.Year) ==
            (car.Make, car.Model, car.Year);
    }
}

public class Person
{
	public static void Main()
	{
		Car ACar = new Car();
		ACar.Make = "maker";
		ACar.Model = "modeller";
		ACar.Year = "1999";
		Car BCar = new Car();
		BCar.Make = "maker";
		BCar.Model = "modeller";
		BCar.Year = "1999";
		var x = ACar.Equals(BCar);
		Console.WriteLine("THE WORKING");
		Console.WriteLine(x);
	}
	
}
