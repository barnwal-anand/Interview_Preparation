>> Thread create and join
-------------------------------
>> int pthread_create(pthread_t * thread,
                      const pthread_attr_t * attr,
                      void * (*start_routine)(void *),
                      void *arg);
thread: pointer to an unsigned integer value that returns the thread id of the thread created.
attr: pointer to a structure that is used to define thread attributes like detached state,
scheduling policy, stack address, etc. Set to NULL for default thread attributes.
start_routine: pointer to a subroutine that is executed by the thread.
arg: pointer to void that contains the arguments

>> int pthread_join(pthread_t thread, void **thread_return);
thread_return: pointer to the location where the exit status of the thread mentioned in thead is stored
If successful, it returns 0.
If unsuccessful, it returns -1 and sets errno

A C program to show multiple threads with global and static variables
Global and static variables are stored in data segment.
Therefore, they are shared by all threads.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0;

void *myThreadFun(void *vargp)
{
    sleep(1);
    // Store the value argument passed to this thread
    int *myid = (int *)vargp;

    // Let us create a static variable to observe its changes
    static int s = 0;

    // Change static and global variables
    ++s; ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, s, g);

    //check return value
    return 10;
}

int main()
{
    // void *num;
    int i;
    pthread_t tid[3];

    for (i = 0; i < 3; i++)
        pthread_create(&tid[i], NULL, myThreadFun, (void *)&tid[i]);

    // check return value pthread_join(tid[0], &num);
    
    pthread_exit(NULL); // or pthread_join(tid[0], NULL)
    // Both methods ensure that your process doesn't end before all of your threads have ended.

    return 0;
}
ubuntu:~/$ gcc multithread.c -pthread
ubuntu:~/$ ./a.out
Thread ID: 139106048, Static: 1, Global: 1
Thread ID: 137004800, Static: 2, Global: 2
Thread ID: 134903552, Static: 3, Global: 3

pthread_exit() will exit the thread that calls it.
-----------------
In this case since the main calls it, main thread will terminate
whereas spawned threads will continue to execute.
This is mostly used in cases where the main thread is only required to spawn threads
and leave the threads to do their job.

pthread_join() will suspend execution of the thread that has called it unless the target thread terminates.
This is useful in cases when you want to wait for thread to terminate before further processing in main thread.
