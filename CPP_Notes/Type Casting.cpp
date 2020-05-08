C++ supports following 4 types of casting operators:
1. const_cast
2. static_cast
3. dynamic_cast
4. reinterpret_cast

1. const_cast: const_cast is used to cast away the constness of variables.

>>> const_cast can be used to pass const data to a function that doesn’t receive const.
int fun(int* ptr)
{
    return (*ptr + 10);
}

int main(void)
{
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    cout << fun(ptr1);
    return 0;
}

>>> const_cast can be used to change non-const class members inside a const member function.
‘this’ is a constant pointer to a constant object, thus compiler doesn’t allow to change the data members through ‘this’ pointer.
const_cast changes the type of ‘this’ pointer to ‘student* const this’.
class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}

    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        ( const_cast <student*> (this) )->roll = 5;
    }

    int getRoll()  { return roll; }
};

2. static_cast: It is a compile time cast.It does things like implicit conversions between types (such as int to float, or pointer to void*).
float f = 3.5;
int a = static_cast<int>(f);

int a = 10;
char c = 'a';
int* q = (int*)&c;
int* p = static_cast<int*>(&c); // pass at compile time, may fail at run time

class Base {
};
class Derived : private Base { // Inherited private/protected not public
};
int main()
{
    Derived d1;
    Base* b1 = (Base*)(&d1); // allowed
    Base* b2 = static_cast<Base*>(&d1); //[Error] 'Base' is an inaccessible base of 'Derived' due to private Inherited. Will work for only public Inherited
    return 0;
}

3. dynamic_cast:
