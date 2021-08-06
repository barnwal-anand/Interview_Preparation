>> It creates object for you rather you initiating object directly
>> In simple term, you create one function(factory) and tell him what king of object you want.

Advantages:
1. Less code changes if we want to change logic in object creation
2. We create object without exposing object creation logic to client
3. We get benefits of virtual constructor

class Toy {
protected:
	string name;
	int price;
public:
	virtual void combineParts() = 0;
	virtual void applyLabel() = 0;
	virtual void showProduct() = 0;
};

class Car : public Toy {
	// make all constructor private or protected
public:
	void combineParts() {
		cout << "Combine Car parts" << endl;
	}
	void applyLabel() {
		name = "mini car";
		price = 120;
	}
	void showProduct() {
		cout << "Name: " << name << " Price: " << price << endl;
	}
};

class Truck : public Toy {
public:
	void combineParts() {
		cout << "Combine Truck parts" << endl;
	}
	void applyLabel() {
		name = "mini truck";
		price = 230;
	}
	void showProduct() {
		cout << "Name: " << name << " Price: " << price << endl;
	}
};

class ToyFactory {
public:
	static Toy* createToy(int type) {
		Toy *toy = NULL;
		if (type == 1) {
			toy = new Car;
		}
		else if (type == 2) {
			toy = new Truck;
		}

		if (toy) {
			toy->combineParts();
			toy->applyLabel();
		}
		return toy;
	}
};

int main() {
	Toy *toy = ToyFactory::createToy(1);
	if (toy) {
		toy->showProduct();
	}
	delete toy;
	toy = ToyFactory::createToy(2);
	if (toy) {
		toy->showProduct();
	}

	delete toy;
	return 0;
}

o/p:
Combine Car parts
Name: mini car Price: 120
Combine Truck parts
Name: mini truck Price: 230
