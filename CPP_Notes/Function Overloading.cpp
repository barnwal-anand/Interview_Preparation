>> C++ allows member methods to be overloaded on the basis of const type.
class Test
{
protected:
    int x;
public:
    Test (int i):x(i) { }
    void fun() const
    {
        cout << "fun() const called " << endl;
    }
    void fun()
    {
        cout << "fun() called " << endl;
    }
};

int main()
{
    Test t1 (10);
    const Test t2 (20);
    t1.fun();           // fun() called
    t2.fun();           // fun() const called
    return 0;
}

>> C++ allows functions to be overloaded on the basis of const-ness of parameters only if
the const parameter is a reference or a pointer.
That is why the program 1 failed in compilation, but the program 2 worked fine.
1.
void fun(const int i)
{
    cout << "fun(const int) called ";
}
void fun(int i)
{
    cout << "fun(int ) called " ;
}
int main()
{
    const int i = 10;
    fun(i);
    return 0;
}

2.
void fun(char *a)
{
  cout << "non-const fun() " << a;
}

void fun(const char *a)
{
  cout << "const fun() " << a;
}

int main()
{
  const char *ptr = "GeeksforGeeks";
  fun(ptr); // const fun() GeeksforGeeks
  return 0;
}
In program 1, the parameter ‘i’ is passed by value, so ‘i’ in fun() is a copy of ‘i’ in main().
Hence fun() cannot modify ‘i’ of main(). Therefore, it doesn’t matter whether ‘i’ is received
as a const parameter or normal parameter.

3.
void fun(const int &i)
{
    cout << "fun(const int &) called ";
}
void fun(int &i)
{
    cout << "fun(int &) called " ;
}
int main()
{
    const int i = 10;
    fun(i);       // fun(const int &) called
    return 0;
}

>> In C++, there is no overloading across scopes.
There is no overload resolution between Base and Derived class.
