/*
LeetCode: 1115 Print FooBar Alternately

The instance of FooBar will be passed to two different threads.
Thread A will call foo() while thread B will call bar().
Modify the given program to output "foobar" n times.

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/

#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t sem_foo;
    sem_t sem_bar;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&sem_foo, 0, 1);
        sem_init(&sem_bar, 0, 0);
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            sem_wait(&sem_foo);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&sem_bar);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            sem_wait(&sem_bar);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&sem_foo);
        }
    }
};
