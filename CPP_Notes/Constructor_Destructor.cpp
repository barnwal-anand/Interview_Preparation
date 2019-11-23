>> we need to write copy constructor only when we have pointers or run time allocation of resource
like file handle, a network connection, etc.
>> When we create our own copy constructor, we pass an object by reference and we generally pass it as a const reference.

class Test
{
   /* Class data members */
public:
   Test(const Test &t) { /* Copy data members from t*/}
   Test()        { /* Initialize data members */ }
};

Test fun()
{
    cout << "fun() Called\n";
    Test t;
    return t;
}

int main()
{
    Test t1;
    Test t2 = fun();
    return 0;
}
The function fun() returns by value.
So the compiler creates a temporary object which is copied to t2 using copy constructor
(The temporary object is passed as an argument to copy constructor).
The reason for compiler error(if const not used) is, compiler created temporary objects cannot be
bound to non-const references.

What is the use of private destructor?
>> Whenever we want to control destruction of objects of a class, we make the destructor private.
when a class has private destructur, only dynamic objects of that class can be created.

// CPP program to illustrate Private Destructor
class Test {
private:
    ~Test() {}
    friend void destructTest(Test*);
};

void destructTest(Test* ptr) {
    delete ptr;
}

int main() {
    Test* ptr = new Test;
    destructTest(ptr);
    return 0;
}


>> Copy elision (or Copy omission) is a compiler optimization technique that avoids unnecessary copying of objects.
Now a days, almost every compiler uses it.
class B
{
public:
    B(const char* str = "\0") //default constructor
    {
        cout << "Constructor called" << endl;
    }

    B(const B &b)  //copy constructor
    {
        cout << "Copy constructor called" << endl;
    }
};

int main()
{
    B ob = "copy me";  // o/p: Constructor called
    return 0;
}
B ob = "copy me"; should be broken down by the compiler as
B ob = B("copy me"); // Create temporary object and then call copy constructor

However, most of the C++ compilers avoid such overheads of creating a temporary object & then copying it.
The modern compilers break down the statement
as B ob("copy me"); //direct initialization
and thus eliding call to copy constructor.

>> Explicit call to constructor and Destructor

class Test
{
public:
    Test()  { cout << "Constructor is executed\n"; }
    ~Test() { cout << "Destructor is executed\n";  }
};

int main()
{
    Test();  // Explicit call to constructor
    Test t; // local object
    t.~Test(); // Explicit call to destructor
    return 0;
}
Output:
Constructor is executed
Destructor is executed
Constructor is executed
Destructor is executed
Destructor is executed

When the constructor is called explicitly the compiler creates a nameless temporary object
and it is immediately destroyed. That’s why 2nd line in the output is call to destructor.

>> When to use Initializer list
1) For initialization of non-static const data members:
class Test {
    const int t;
public:
    Test(int t):t(t) {}  //Initializer list must be used
};

2) For initialization of reference members:
class Test {
    int &t;
public:
    Test(int &t):t(t) {}  //Initializer list must be used
    int getT() { return t; }
};

3) For initialization of member objects which do not have default constructor:
class A {
    int i;
public:
    A(int );
};

A::A(int arg) {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}

// Class B contains object of A
class B {
    A a;
public:
    B(int );
};

B::B(int x):a(x) {  //Initializer list must be used
    cout << "B's Constructor called";
}

int main() {
    B obj(10);
    return 0;
}
>> static object
1) local static object:
class Test
{
public:
    Test()
    {
        std::cout << "Constructor is executed\n";
    }
    ~Test()
    {
        std::cout << "Destructor is executed\n";
    }
};
void myfunc()
{
    static Test obj;
} // Object obj is still not destroyed because it is static

int main()
{
    std::cout << "main() starts\n";
    myfunc();    // Destructor will not be called here
    std::cout << "main() terminates\n";
    return 0;
}

Output:
main() starts
Constructor is executed
main() terminates
Destructor is executed

2) global static object:
class Test
{
public:
    int a;
    Test()
    {
        a = 10;
        std::cout << "Constructor is executed\n";
    }
    ~Test()
    {
        std::cout << "Destructor is executed\n";
    }
};
static Test obj;
int main()
{
    std::cout << "main() starts\n";
    std::cout << obj.a;
    std::cout << "\nmain() terminates\n";
    return 0;
}
Output:
Constructor is executed
main() starts
10
main() terminates
Destructor is executed
