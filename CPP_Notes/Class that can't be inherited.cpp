// Design a class that can't be inherited.
Java has built-in fetaure and it can be achieved using final keyword.

In c++ we can achieve this using private constructor, virtual inheritance and friend class.

class Final;  // The class to be made final

class MakeFinal // used to make the Final class final
{
private:
    MakeFinal() { cout << "MakFinal constructor" << endl; }
friend class Final;
};

class Final : virtual MakeFinal
{
public:
    Final() { cout << "Final constructor" << endl; }
};

class Derived : public Final
{
public:
    Derived() { cout << "Derived constructor" << endl; }
};

int main(int argc, char *argv[])
{
    Derived d;
    return 0;
}

Here, Derived‘s constructor directly invokes MakeFinal’s constructor (due to virtual inheritance), and
the constructor of MakeFinal is private, therefore we get the compilation error.

Without Derived class, we can create of Final class as it is friend class of MakeFinal
