Compile time polymorphism:
--------------------------
Achieved by function overloading or operator overloading.

>>> Function Overloading:

Multiple functions with same name but different parameters(number and/or type) then these functions are said to be overloaded.
class FuncOverloaded
{
    public:
    void foo(int x) {}

    void foo(double x) {}

    void foo(int x, int y) {}

};

>>> Operator Overloading:

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}

    // This is automatically called when '+' is used with between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print(); // 12 + i9
}


Run Time Polymorphism in a function:
------------------------------------
We can make a function polymorphic by passing objects as reference (or pointer) to it.
print() calls the base class function show() if base class object is passed, and derived class function show() if derived class object is passed.
If reference is not used, then If we pass an object of subclass to a function that expects an object of superclass
then the passed object is sliced if it is pass by value.
class base {
public:
    virtual void show() {  // Note the virtual keyword here
        cout<<"In base \n";
    }
};


class derived: public base {
public:
    void show() {
        cout<<"In derived \n";
    }
};

// Since we pass b as reference, we achieve run time polymorphism here.
void print(base &b) {
    b.show();
}

int main(void) {
    base b;
    derived d;
    print(b);
    print(d); // if pass by value used then it will print "In base" becoz of object slicing
    return 0;
}
Output:
In base
In derived

Another example:
class base
{
public:
    virtual void print () { cout<< "print base class" <<endl; }

    void show () { cout<< "show base class" <<endl; }
};

class derived:public base
{
public:
    void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
    { cout<< "print derived class" <<endl; }

    void show () { cout<< "show derived class" <<endl; }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;
    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print();  // print derived class

    // Non-virtual function, binded at compile time
    bptr->show(); // show base class

    return 0;
}
