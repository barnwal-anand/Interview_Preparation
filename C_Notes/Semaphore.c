>> Semaphore is simply a variable which is non-negative and shared between threads to achieve process synchronization.
>> It works like a signaling mechanism and a thread that is waiting on a semaphore can be signaled by another thread.

This is different than a mutex as mutex can be signaled only by the thread that called the wait function.
Mutex:
------
So a mutex is a locking mechanism used to synchronize access to a resource.
Only one task (can be a thread or process based on OS abstraction) can acquire the mutex.
It means there is ownership associated with mutex, and only the owner can release the lock (mutex).

Semaphore:
----------
Semaphore is signaling mechanism (“I am done, you can carry on” kind of signal).
For example, if you are listening songs on your mobile phone and at the same time your friend calls you,
an interrupt is triggered upon which an interrupt service routine (ISR) signals the call processing task to wakeup.

>> A semaphore uses two atomic operations, wait and signal for process synchronization.

Binary Semaphore:
-----------------
It can have only two values – 0 and 1. Its value is initialized to 1.
It is used to implement the solution of critical section problem with multiple processes.

Counting Semaphore:
-------------------
Its value can range over an unrestricted domain.
It is used to control access to a resource that has multiple instances.

Basic implementation of wait(P) and signal(V) can be like below:
struct Semaphore {
	int value;
	Queue<process> q;

};
P(Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0) {
            //p is a process which is currently executing
	      q.push(p); //add process to the waiting queue
		block();
	}
	else
		return;
}

V(Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0) {
	      Process p = q.pop(); //release process from queue
		wakeup(p);
	}
	else
		return;
}
