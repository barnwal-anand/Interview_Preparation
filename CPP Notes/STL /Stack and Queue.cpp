Queue:
-------
Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement.
Elements are inserted at the back (end) and are deleted from the front.

#include <queue>

queue<int> my_queue;
my_queue.push(10);
my_queue.push(20);

push(val) - adds the element ‘val’ at the end of the queue
pop() – deletes the first element of the queue
empty() – Returns whether the queue is empty
size() – Returns the size of the queue
queue::swap() -  Exchange the contents of two queues but the queues must be of same type, although sizes may differ
queue::front() - Returns a reference to the first element of the queue
queue::back() -  Returns a reference to the last element of the queue


Stack:
-------
Stacks are a type of container adaptors with LIFO property, where a new element is added at one end and (top) an element is removed from that end only.

#include <stack>

empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)

Priority Queue:
---------------
Priority queues are a type of container adapters, specifically designed such that
the first element of the queue is the greatest of all elements in the queue and elements are in non decreasing order.

#include <queue>

priority_queue <int> gquiz;
gquiz.push(10);
gquiz.push(30);
gquiz.push(20);
gquiz.push(5);
gquiz.push(1);

The priority queue gquiz is : 30 20 10 5 1
gquiz.size() : 5
gquiz.top() : 30
gquiz.pop(); // gquiz now contains 20 10 5 1

empty() function returns whether the queue is empty.
size() function returns the size of the queue.
top() – Returns a reference to the top most element of the queue
push(g) function adds the element ‘g’ at the end of the queue.
pop() function deletes the first element of the queue.
swap() – This function is used to swap the contents of one priority queue with another priority queue of same type and size.
