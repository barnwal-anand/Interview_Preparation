>> Critical Secction
--------------------
When multiple processes/threads tries to access same code section, that section is known as critical section.
Critical section contains shared variables or resources
which are needed to be synchronized to maintain consistency.

>> Thread synchronization
--------------------------
When one thread starts executing the critical section, other thread/s should wait until the first thread finishes.
If proper synchronization technique is not applied, it may cause a race condition,
where the values of variables may be unpredictable and vary
depending on the timings of context switches of the processes or threads.

Thread Synchronization Problem
------------------------------
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;

void* trythis(void* arg)
{
	counter += 1;
	printf("\n Job %d has started\n", counter);
	sleep(5);
	printf("\n Job %d has finished\n", counter);
}

int main(void)
{
	int i = 0;
	int error;

	while (i++ < 2) {
		error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		if (error != 0)
			printf("\nThread can't be created : [%s]", strerror(error));
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
Output :
Job 1 has started
Job 2 has started
Job 2 has finished
Job 2 has finished

>> How to solve it ?
-----------------------
Mutex - lock that we set before using a shared resource and release after using it.
Mutex lock can only be released by the thread who locked it.
So this ensures synchronized access of shared resources.

>> int pthread_mutex_init(pthread_mutex_t *restrict mutex,
                          const pthread_mutexattr_t *restrict attr)
Creates a mutex, referenced by mutex, with attributes specified by attr.
If attr is NULL, the default mutex attribute (NONRECURSIVE) is used.

>> int pthread_mutex_lock(pthread_mutex_t *mutex)
Locks a mutex object, which identifies a mutex.
If the mutex is already locked by another thread, the thread waits for the mutex to become available.

>> int pthread_mutex_unlock(pthread_mutex_t *mutex)
Releases a mutex object. If one or more threads are waiting to lock the mutex,
pthread_mutex_unlock() causes one of those threads to return from pthread_mutex_lock() with the mutex object acquired.
If no threads are waiting for the mutex, the mutex unlocks with no current owner.

>> int pthread_mutex_destroy(pthread_mutex_t *mutex)
Deletes a mutex object.

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* trythis(void* arg)
{
    pthread_mutex_lock(&lock);
	counter += 1;
	printf("\n Job %d has started\n", counter);
	sleep(5);
	printf("\n Job %d has finished\n", counter);
    pthread_mutex_unlock(&lock);
}

int main(void)
{
	int i = 0;
	int error;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return;
    }
	while (i++ < 2) {
		error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		if (error != 0)
			printf("\nThread can't be created : [%s]", strerror(error));
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
	return 0;
}
o/p:
Job 1 started
Job 1 finished
Job 2 started
Job 2 finished

What happens if a non-recursive mutex is locked more than once?
>> A mutex is a lock. Only one state (locked/unlocked) is associated with it.
If a thread which had already locked a mutex, tries to lock the mutex again,
it will enter into the waiting list of that mutex i.e. sleep and so there is no way to unlock the mutex,
which results in deadlock.

Is it necessary that a thread must block always when resource is not available?
>> Not necessary. If the design is sure ‘what has to be done when resource is not available‘,
the thread can take up that work (a different code branch).
For example POSIX pthread_mutex_trylock() API,
When mutex is not available the function returns immediately
whereas the API pthread_mutex_lock() blocks the thread till resource is available.
