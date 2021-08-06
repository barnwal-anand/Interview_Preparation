>> Namespace is nothing but a group of declarations. It is not a class.

namespace mySpace {
//declarations
} // no semicolon

It  puts the names of its members in a distinct space so that they do not conflict with names in other namespaces.
Namespace definition must be done at global scope, or nested inside another namespace.

Alias name can be used for namespace.
namespace ms = mySpace;

Namespaces can be unnamed.
namespace { 
//declarations
}

A namespace definition can be continued and extended over multiple files. It is not redefined and overriden.

e.g consider two files
file1.h
namespace  mySpace {
int a, b;
void f1();
}

file2.h
namespace  mySpace {
int x, y;
void f2();
}

Now if both files are included in a program, then there would be no conflict and no two namespaces would be there.
Instead of that a single namespace mySpace will be considered by compiler containing declarations of both namespaces.

// A C++ code to demonstrate that we can define methods outside namespace.
#include <iostream>
using namespace std;

// Creating a namespace
namespace ns {
    void display();
    class geek
    {
    public:
       void display();
    };
}

// Defining methods of namespace
void ns::geek::display() {
    cout << "ns::geek::display()\n";
}

void ns::display() {
    cout << "ns::display()\n";
}

int main() {
    ns::geek obj;
    ns::display();
    obj.display();
    return 0;
}

Output:
ns::display()
ns::geek::display()
