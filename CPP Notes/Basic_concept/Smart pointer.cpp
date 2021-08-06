>> A smart pointer is a class designed to manage dynamically allocated memory and
to ensure that the memory gets deleted when the smart pointer object goes out of scope.
So it prevents memory leak.

>> Smart pointers are just classes that wrap the raw pointer and overload the -> and * operators.
This allows them to offer the same syntax as a raw pointer.
e.g:
class MyInt {
    int *data;
public:
    explicit MyInt(int *ptr = nullptr) {
        data = ptr;
    }
    ~MyInt() {
        delete ptr;
    }
    int& operator *() {
        return *ptr;
    }
};
int main() {
    int *ptr = new int(10);
    // we can create a wrapper which takes care to delete ptr otherwise if we forget, it will cause memory leak
    MyInt myIntPtr = MyInt(ptr);
    cout << *myIntPtr << endl; // 10
    *myIntPtr = 20;
    cout << *myIntPtr << endl; // 20
    return 0;
}

C++11 has three types of smart pointers that are defined in the <memory> header of the Standard Library:
1. std::unique_ptr
2. std::shared_ptr
3. std::weak_ptr

unique_ptr:
-----------
>> Allows only one owner of the underlying pointer
>> We can also create array of objects of unique_ptr

class Foo {
private:
    int data;
public:
    explicit Foo(int data) : data(data){ }
    ~Foo() {
        cout << "Destructor called" << endl;
    }
    int getData() {
        return data;
    }
};
int main() {
    Foo *ptr = new Foo(10);
    unique_ptr<Foo> u_ptr1(ptr); // this will call Destructor when it goes out of scope
    unique_ptr<Foo> u_ptr2(new Foo(20)); // another way to create unique_ptr
    unique_ptr<Foo> u_ptr_3 = make_unique<Foo>(30); // another way to create unique_ptr
    cout << u_ptr1->getData() << " " << (*u_ptr2).getData() << endl; // overloaded -> and * operator

    //unique_ptr<Foo> u_ptr3 = u_ptr2; // this will fail as only one owner is allowed
    // moving ownership from one unique_ptr to another is allowed
    unique_ptr<Foo> u_ptr4 = move(u_ptr2); // u_ptr4->getData() = 20 and u_ptr2 will become null

    return 0;
}

shared_ptr:
-----------
>> Allows multiple owner of the same pointer (reference count is maintained)
>> Several shared_ptr can point to same object
>> Thread safe and not thread safe ?
    a. control block is thread safe
    b. managed object is not
>> shared_ptr will destroy managed object in following case:
    a. last shared_ptr goes out of scope i.e. reference count becomes 0
    b. reseet shared_ptr
    c. initialized shared_ptr with other shared_ptr

class Foo {
private:
    int data;
public:
    explicit Foo(int data) : data(data){ }
    void setData(int data) {
        this->data = data;
    }
    int getData() {
        return data;
    }
    ~Foo() {
        cout << "Destructor called" << endl;
    }
};
int main() {
    shared_ptr<Foo> s_ptr1(new Foo(10));
    //shared_ptr<Foo> s_ptr = make_shared<Foo>(30); // another way to create unique_ptr
    cout << s_ptr1->getData() << " " << s_ptr1.use_count() << endl; // 10, 1

    shared_ptr<Foo> s_ptr2 = s_ptr1;
    s_ptr2->setData(100);
    cout << s_ptr1->getData() << " " << s_ptr1.use_count() << endl; // 100, 2
    cout << s_ptr2->getData() << " " << s_ptr2.use_count() << endl; // 100, 2
    return 0;

}
o/p:
10 1
100 2
100 2
Destructor called

weak_ptr:
---------
>> Special kind of shared_ptr which does not keep reference count
>> Used to remove cyclic dependency between shared_ptr
