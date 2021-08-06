Association:
------------
Association is a simple structural connection between classes and is a relationship
where all objects have their own lifecycle and there is no owner.
Example:
Multiple students can associate with a single Department and single student can associate with multiple Departments,
but there is no ownership between the objects and both have their own lifecycle.

Or relationship between Driver and Car. Driver can drive car1 and can also drive car2.

class Driver {
public:
    void drive(Car &c) { }
};

int main() {
    Driver d1, d2, d3;
    Car c1, c2, c3;

    d1.drive(c1);
    d1.drive(c2);
}

Composition:
------------
Accessing other classes objects in your class and owner class owns the object and is responsible for its lifetime.
 >> In composition, the lifetime of the owned object depends on the lifetime of the owner.

Example:
A car is composed of an engine and tyres.
In this case, a Car owned these objects. So a Car is an Owner class and tyres and engine classes are Owned classes.

class Engine {
  int capacity;

  public:
  Engine(){ capacity = 0; }

  Engine(int cap) { capacity = cap; }

  void Engine_details() {
    cout << "Engine details: " << capacity << endl;
  }
};

class Tyres{
  int No_of_tyres;

  public:
  Tyres(){ No_of_tyres = 0; }

  Tyres(int nt) { No_of_tyres = nt; }

  void Tyre_details() {
    cout << "Number of tyres: " << No_of_tyres << endl;
  }
};

class Car {
  Engine Eobj;
  Tyres Tobj;
  string color;

  public:
  Car(Engine eng, Tyres tr, string col) : Eobj(eng), Tobj(tr) {
    color = col;
  }

  void Car_detail(){
    Eobj.Engine_details();
    Tobj.Tyre_details();
    cout << "Car color: " << color << endl;
  }
};

int main(){
  Engine Eobj(1600);
  Tyres Tobj(4);
  Car Cobj(Eobj, Tobj, "Black");
  Cobj.Car_detail();
}
Here when Car dies, so does tyre, engine inside it.

Aggregation:
------------
Aggregation is very similar to composition. It also follows the Has-A model.
There is a ownership like parent and child. Child object can not belong to another parent object at the same time.
>> In aggregation, the lifetime of the owned object does not depend on the lifetime of the owner.

The owner object could get deleted but the owned object can continue to exist in the program.
In composition, the parent contains a child object. This bounds the child to its parent.
In aggregation, the parent only contains a reference to the child, which removes the child’s dependency.

class Country {
  string name;
  int population;

  public:
  Country(string n, int p) { name = n; population = p; }
  string getName() { return name; }
};

class Person { // Each person is bound to Country and Country can exist without Person
  string name;
  Country* country; // A pointer to a Country object

  public:
  Person(string n, Country* c){
    name = n;
    country = c;
  }

  void printDetails(){
    cout << "Name: " << name << endl;
    cout << "Country: " << country->getName() << endl;
  }
};

int main() {
  Country* country = new Country("Utopia", 1);
  {
    Person user("Darth Vader", country);
    user.printDetails();
  }
  // The user object's lifetime is over

  cout << country->getName() << endl; // The country object still exists!
}

Here, The country object lives on even after the user goes out of scope.
This creates a looser relationship than composition.
