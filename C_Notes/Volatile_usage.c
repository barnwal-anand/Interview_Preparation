>> Volatile prevents the compiler optimisation (when compiler optimization is on).
compiler optimisation is needed to make your code run more efficient.
In clang, we can use -o2 flag to enable moderate level of optimization which enables most optimizations.
e.g "clang -o2 temp.c"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

bool done = false;

void* func(void *temp)
{
      sleep(1);
      done = true;
      return NULL;
}

int main()
{
      pthread_t thread1;
      pthread_create(&thread1, NULL, func, NULL);

      printf("waiting...\n");
      while (!done) {}

      printf("Completed..\n");

      return 0;
}

If you run above program without compilation optimization then it would print
waiting...
Completed..

But when you run with compiler optimisation like "clang -o2 temp.c", then it would print
waiting...
and then it will keep on waiting

Reason:
The compiler sees variable "done" is not getting updated in while loop. So it will replace it like:
while(true){}, and this loop will run forever.

To prevent this:
We need to declare the variable "done" as volatile so as to prevent compiler optimisation.
volatile bool done = false;
