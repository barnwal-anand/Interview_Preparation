/*
LeetCode: 1195 Fizz Buzz Multithreaded

You are given an instance of the class FizzBuzz that has four functions:
fizz, buzz, fizzbuzz and number.
The same instance of FizzBuzz will be passed to four different threads:

Thread A: calls fizz() that should output the word "Fizz".
Thread B: calls buzz() that should output the word "Buzz".
Thread C: calls fizzbuzz() that should output the word "FizzBuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "Fizz", 4, "Buzz", ...]

Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
*/

#include <semaphore.h>

class FizzBuzz {
private:
    int n;
    int count;
    sem_t sem_fizz;
    sem_t sem_buzz;
    sem_t sem_fizzbuzz;
    sem_t sem_number;

public:
    FizzBuzz(int n) {
        this->n = n;
        count = 1;
        sem_init(&sem_fizz, 0, 0);
        sem_init(&sem_buzz, 0, 0);
        sem_init(&sem_fizzbuzz, 0, 0);
        sem_init(&sem_number, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            sem_wait(&sem_fizz);
            if (count > n)
                return;
            printFizz();
            notify_next();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            sem_wait(&sem_buzz);
            if (count > n)
                return;
            printBuzz();
            notify_next();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            sem_wait(&sem_fizzbuzz);
            if (count > n)
                return;
            printFizzBuzz();
            notify_next();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            sem_wait(&sem_number);
            if (count > n)
                return;
            printNumber(count);
            notify_next();
        }
    }

    void notify_next() {
        count++;

        if (count > n) {
            sem_post(&sem_fizz);
            sem_post(&sem_buzz);
            sem_post(&sem_fizzbuzz);
            sem_post(&sem_number);
            return;
        }

        if (count % 15 == 0) {
            sem_post(&sem_fizzbuzz);
        }
        else if (count % 3 == 0) {
            sem_post(&sem_fizz);
        }
        else if (count % 5 == 0) {
            sem_post(&sem_buzz);
        }
        else {
            sem_post(&sem_number);
        }
    }
};
