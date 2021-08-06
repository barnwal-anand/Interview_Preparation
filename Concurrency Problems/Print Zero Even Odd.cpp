/*
LeetCode: 1116 Print Zero Even Odd
You have a function printNumber that can be called with an integer parameter and prints it to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd.
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Input: n = 5
Output: "0102030405"
*/

#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    int count;
    sem_t sem_zero;
    sem_t sem_even;
    sem_t sem_odd;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        count = 1;
        sem_init(&sem_zero, 0, 1);
        sem_init(&sem_even, 0, 0);
        sem_init(&sem_odd, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int it = 0; it < n; it ++) {
            sem_wait(&sem_zero);

            printNumber(0);

            if (it % 2 == 0) {
                sem_post(&sem_odd);
            }
            else {
                sem_post(&sem_even);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int it = 2; it <= n; it += 2) {
            sem_wait(&sem_even);

            printNumber(it);

            sem_post(&sem_zero);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int it = 1; it <= n; it += 2) {
            sem_wait(&sem_odd);

            printNumber(it);

            sem_post(&sem_zero);
        }
    }
};
