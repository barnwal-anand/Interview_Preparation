>> Valgrind Memcheck is a tool that detects memory leaks and memory errors in c/c++.
>> Some of the most difficult C bugs come from mismanagement of memory:
   allocating the wrong size, using an uninitialized pointer, accessing memory after it was freed,
   overrunning a buffer, and so on.
>> Valgrind doesn't perform bounds checking on stack arrays (allocated on the stack)

Memory Errors Vs. Memory Leaks:
-------------------------------
Valgrind reports two types of issues: memory errors and memory leaks.
When a program dynamically allocates memory and forgets to later free it, it creates a leak.
A memory leak generally won't cause a program to misbehave, crash, or give wrong answers, and is not an urgent situation.
A memory error, on the other hand, is a red alert. Reading uninitialized memory,
writing past the end of a piece of memory, accessing freed memory...

>> To run Valgrind, pass the executable as an argument (along with any parameters to the program).
>> If you have a memory leak, then the number of allocs and the number of frees will differ

e.g:
----
#include <stdlib.h>
int main()
{
    char *x = malloc(100); /* or, in C++, "char *x = new char[100] */
    return 0;
} //example.c

>> % valgrind --tool=memcheck --leak-check=yes example
This will result in some information, a list of calls to malloc that did not have subsequent calls to free:
==2116== 100 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2116==    at 0x1B900DD0: malloc (vg_replace_malloc.c:131)
==2116==    by 0x804840F: main (in /home/cprogram/example)

>> Valgrind can also find the use of invalid heap memory using the memcheck tool.
For instance, if you allocate an array with malloc or new and then try to access a location past the end of the array:
char *x = malloc(10);
x[10] = 'a';
Valgrind will detect it. For instance, running the following program, example, through Valgrind
#include <stdlib.h>

int main()
{
    char *x = malloc(10);
    x[10] = 'a';
    return 0;
}

>> valgrind --tool=memcheck --leak-check=yes example
results in the following warning
==9814==  Invalid write of size 1
==9814==    at 0x804841E: main (example.c:6)
==9814==  Address 0x1BA3607A is 0 bytes after a block of size 10 alloc'd
==9814==    at 0x1B900DD0: malloc (vg_replace_malloc.c:131)
==9814==    by 0x804840F: main (example.c:5)
