class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}

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
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();           // 12 + i9
}

>> Global operator function
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
    void print() { cout << real << " + i" << imag << endl; }

// The operator function is made friend of this class so
// that it can access private members
friend Complex operator + (Complex const &, Complex const &);
};

Complex operator + (Complex const &c1, Complex const &c2)
{
     return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

>> Conversion Operator: Overloaded conversion operators must be a member method.
class Fraction
{
    int num, den;
public:
    Fraction(int n,  int d) { num = n; den = d; }

    // conversion operator: return float value of fraction
    operator float() const {
        return float(num) / float(den);
    }
};

int main() {
    Fraction f(2, 5);
    float val = f;
    cout << val; // o.4
    return 0;
}

>> The compiler created copy constructor and assignment operator may not be sufficient
when we have pointers or any run time allocation of resource like file handle, a network connection.
class Test
{
    int *ptr;
public:
    Test (int i = 0)      { ptr = new int(i); }
    void setValue (int i) { *ptr = i; }
    void print()          { cout << *ptr << endl; }
    Test & operator = (const Test &t);
};

Test & Test::operator = (const Test &t)
{
   // Check for self assignment
   if(this != &t)
     *ptr = *(t.ptr);

   return *this;
}

int main()
{
    Test t1(5);
    Test t2;
    t2 = t1;
    t1.setValue(10);
    t2.print();      // 5
    return 0;
}

>> Compiler doesn’t creates default assignment operator in following cases:
1. Class has a nonstatic data member of a const type or a reference type
2. Class has a nonstatic data member of a type which has an inaccessible copy assignment operator
3. Class is derived from a base class with an inaccessible copy assignment operator
e.g.
class Test
{
    int x;
    int &ref;
public:
    Test (int i):x(i), ref(x) {}
    void print() { cout << ref; }
    void setX(int i) { x = i; }
    // Test &operator = (const Test &t) { x = t.x; return *this; }
};

int main()
{
    Test t1(10);
    Test t2(20);
    t2 = t1;
    t1.setX(40);
    t2.print();
    return 0;
}
Compiler Error
User must define assignment operator in above cases.

>> Overloading stream insertion (<>) operators
These operators must be overloaded as a global function.
In operator overloading, if an operator is overloaded as member, then it must be
a member of the object on left side of the operator.
For example, consider the statement “ob1 + ob2” (let ob1 and ob2 be objects of two different classes).
To make this statement compile, we must overload ‘+’ in class of ‘ob1’ or make ‘+’ a global function.
The operators ‘<<' and '>>' are called like 'cout << ob1' and 'cin >> ob1'.
So if we want to make them a member method, then they must be made members of ostream and istream classes,
which is not a good option most of the time. Therefore, these operators are overloaded as global functions
with two parameters, cout and object of user defined class.

class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0) {  real = r;   imag = i; }
     
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag << endl;
    return out;
}

istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imagenory Part ";
    in >> c.imag;
    return in;
}

int main()
{
   Complex c1;
   cin >> c1;
   cout << "The complex object is ";
   cout << c1;
   return 0;
}
