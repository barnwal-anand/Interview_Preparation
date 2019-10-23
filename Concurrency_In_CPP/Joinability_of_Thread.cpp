/* - Properly constructed thread are joinable as it represent an active thread of execution.
 * - We must call join or detach for any joinable thread.
 * - Once join / detach is called, the thread will become non-joinable.
 * - If join/detach is not called then at the time of destructor call to that thread object std::terminate will be called
 * and program becomes unsafe.
 */

#include <iostream>
#include <thread>
using namespace std;

void test()
{
    cout << "Hello from test" << endl;
}

void run()
{
    thread thread1(test); // callable object is passed as argument, so thread is properly constructed

    if (thread1.joinable())
        cout << "before join call: thread1 is joinable" << endl;
    else
        cout << "before join call: thread1 is not joinable" << endl;

    thread1.join();

    if (thread1.joinable())
        cout << "after join call: thread1 is joinable" << endl;
    else
        cout << "after join call: thread1 is not joinable" << endl;

    thread thread2; // no active thread of execution
    if (thread2.joinable())
        cout << "thread1 is joinable" << endl;
    else
        cout << "thread1 is not joinable" << endl;
}

int main()
{
    run();
    return 0;
}

o/p:
before join call: thread1 is joinable
Hello from test
after join call: thread1 is not joinable
thread1 is not joinable


