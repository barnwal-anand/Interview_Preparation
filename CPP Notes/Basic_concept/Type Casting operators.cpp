A Cast operator is an unary operator which forces one data type to be converted into another data type.
C++ supports four types of casting:

1. Static Cast
2. Dynamic Cast
3. Const Cast
4. Reinterpret Cast

1. Static Case:
----------------
>> It is a compile time cast.
>> It does things like implicit conversions between types (such as int to float, or pointer to void*),
and it can also call explicit conversion functions (or implicit ones).

eg:
int main()
{
    float f = 3.5;
    int a = f; // this is how you do in C
    int b = static_cast<int>(f); // using static_cast in c++
    cout << b;
}

// static_cast to cast ‘to and from’ void pointer.
int main()
{
    int i = 10;
    void* v = static_cast<void*>(&i);
    int* ip = static_cast<int*>(v);
    return 0;
}

// static_cast has more restrictions
int main()
{
    int a = 10;
    char c = 'a';

    int* q = (int*)&c; // this will pass at compile time, may fail at run time
    int* p = static_cast<int*>(&c); // this will fail at compile time - invalid static_cast from type 'char*' to type 'int*'
    return 0;
}

// use static_cast when conversion between types is provided by conversion operators or conversion constructor
class Int {
	int x;

public:
	Int(int x_in = 0) : x(x_in) {
		cout << "Conversion Ctor called - " << x << endl;
	}
	operator string() {
		cout << "Conversion Operator" << endl;
		return to_string(x);
	}
};
int main()
{
	Int obj(3);
	string str = obj;
	obj = 20;
	string str2 = static_cast<string>(obj);
	obj = static_cast<Int>(30);
	return 0;
}
o/p:
Conversion Ctor called - 3
Conversion Operator
Conversion Ctor called - 20
Conversion Operator
Conversion Ctor called - 30

// static_cast avoid cast from derived to private base classes
class Base {
};
class Derived : private Base { // Inherited private/protected not public
};
int main()
{
    Derived d1;
    Base* b1 = (Base*)(&d1); // allowed
    Base* b2 = static_cast<Base*>(&d1);
    return 0;
}
The above code will not compile even if you inherit as protected. So to use static_cast, inherit it as public.

2. Dynamic Cast:
----------------
>> Mainly used for safe downcasting at run time.
>> A dynamic_cast works only on polymorphic base class because it uses this information to decide safe downcasting.
>> To work on dynamic_cast there must be one virtual function in the base class.
>> If we do not use the virtual function, then compiler generates an error - Source type is not polymorphic.
>> If the cast fails and new_type is a reference type, it throws an exception that
matches a handler of type std::bad_cast and gives a
warning: dynamic_cast of “Derived d1” to “class  Derived2&” can never succeed.

class Base {
    public:
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived1 : public Base {
    public:
    void print() {
        cout << "Derived1" << endl;
    }
};

class Derived2 : public Base {
    public:
    void print() {
        cout << "Derived2" << endl;
    }
};

int main()
{
    Derived1 d1;
    Base* baseObj = dynamic_cast<Base*>(&d1);
    baseObj->print();

    Derived1* dp1 = dynamic_cast<Derived1*>(baseObj);
    if (dp1 == nullptr)
        cout << "null" << endl;
    else
        dp1->print();

    Derived2* dp2 = dynamic_cast<Derived2*>(baseObj);
    if (dp2 == nullptr)
        cout << "null" << endl;
    else
        dp2->print();

    try {
        Derived2 &r2 = dynamic_cast<Derived2 &>(d1);
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
o/p:
Derived1
Derived1
null // If the cast fails and new_type is a pointer type, it returns a null pointer
std::bad_cast


3. Const Cast:
--------------
>> const_cast is used to cast away the constness of variables.

// const_cast can be used to change non-const class members inside a const member function.
class student {
private:
    int roll;
public:
    student(int r):roll(r) {}

    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        (const_cast<student*>(this))->roll = 5;
    }

    int getRoll()  { return roll; }
};

int main(void)
{
    student s(3);
    cout << s.getRoll() << endl; // prints 3
    s.fun(); // changes roll to 5
    cout << "New roll number: " << s.getRoll() << endl; // prints 5
    return 0;
}
Here, Inside const member function fun(), ‘this’ is treated by the compiler as ‘const student* const this’,
i.e. ‘this’ is a constant pointer to a constant object,
thus compiler doesn’t allow to change the data members through ‘this’ pointer.
const_cast changes the type of ‘this’ pointer to ‘student* const this’.

// It is undefined behavior to modify a value which is initially declared as const.
int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

int main(void)
{
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast<int *>(ptr);
    fun(ptr1);
    cout << val;
    return 0;
}
The output of the program is undefined.
The variable ‘val’ is a const variable and the call ‘fun(ptr1)’ tries to modify ‘val’ using const_cast.
If we remove const from declaration of val, the program will produce 20 as output.

4. Reinterpret Cast:
--------------------
>> It is used to convert one pointer of another pointer of any type,
no matter either the class is related to each other or not.
>> It does not check if the pointer type and data pointed by the pointer is same or not.
So dangerous type of casting operator.

int main()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << endl; // 65
    cout << *ch << endl; // A
    cout << p << endl; // 0x35435
    cout << ch << endl; // A
    return 0;
}

class A {
public:
    void fun_a() {
        cout << " In class A\n";
    }
};

class B {
public:
    void fun_b() {
        cout << " In class B\n";
    }
};

int main()
{
    B* x = new B();
    // converting the pointer to object referenced of class B to class A
    A* new_a = reinterpret_cast<A*>(x);
    // accessing the function of class A
    new_a->fun_a(); // In class A
    return 0;
}
