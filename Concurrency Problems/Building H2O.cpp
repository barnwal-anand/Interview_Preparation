/*
LeetCode: 1117 Building H2O
There are two kinds of threads, oxygen and hydrogen.
Your goal is to group these threads to form water molecules.
There is a barrier where each thread has to wait until a complete molecule can be formed.
Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively,
which will allow them to pass the barrier.

These threads should pass the barrier in groups of three, and
they must be able to immediately bond with each other to form a water molecule.

Input: "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
*/

#include <semaphore.h>

class H2O {
private:
    sem_t sem_o;
    sem_t sem_h;
    int h_count;

public:
    H2O() {
        h_count = 0;
        sem_init(&sem_h, 0, 2);
        sem_init(&sem_o, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&sem_h);
        h_count++;

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        if(h_count % 2 == 0) {
            sem_post(&sem_o);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&sem_o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&sem_h);
        sem_post(&sem_h);
    }
};
