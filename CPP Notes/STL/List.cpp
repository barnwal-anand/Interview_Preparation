>>> Lists are sequence containers that allow non-contiguous memory allocation.
>>> As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick.
>>> Normally, when we say a List, we talk about doubly linked list. For implementing a singly linked list, we use forward list.

#include <list>

list <int> gqlist1, gqlist2;
for (int i = 0; i < 10; ++i)
{
    gqlist1.push_back(i * 2);
    gqlist2.push_front(i * 3);
}
showlist(gqlist1); // prints - 0 2 4 6 8 10 12 14 16 18
showlist(gqlist2); // prints - 27 24 21 18 15 12 9 6 3 0

gqlist1.pop_front();
gqlist1.pop_back(); // Now 2 4 6 8 10 12 14 16
gqlist1.reverse();  // Now 16 14 12 10 8 6 4 2
gqlist1.sort();     // Sort in inc order Now 2 4 6 8 10 12 14 16
gqlist1.front();    // 2 Returns the value of the first element in the list.
gqlist1.back();     // 16 Returns the value of the last element in the list.

// Same as vector
size() – Returns the number of elements in the list.
empty() – Returns whether the list is empty(1) or not(0).
insert() – Inserts new elements in the list before the element at a specified position.
erase() – Removes a single element or a range of elements from the list.
assign() – Assigns new elements to list by replacing current elements and resizes the list.
begin() and end() - begin function returns an iterator pointing to the first element of the list
reverse() - Reverse a list. Also take 2 args begin and end iterator to reverse part of List
remove(val) - Removes all occurrences of val

list<int> gqlist1 = {1, 2, 3};
list<int> gqlist2 = {2, 4, 6};
// using merge() to merge list1 with list2
gqlist1.merge(gqlist2);  // gqlist1 becomes 1 2 2 3 4 6  If both the lists are in sorted order, then the resulting list is also sorted.
// using unique() to remove repeating elements
gqlist1.unique();  // gqlist1 becomes 1 2 3 4 6
gqlist1.swap(gqlist2); // swap gqlist1 and gqlist2

list<int> mylist{ 1, 2, 2, 2, 5, 6, 7 };
mylist.remove_if(even);   // becomes 1 5 7
bool even(const int& value) { return (value % 2) == 0; }

Forward List:
--------------
All above list functions supported except showlist() and insert()
#include<forward_list>

forward_list<int> flist1;
//Same as list and Vector
flist1.assign({1, 2, 3});   // flist1 now contains 1 2 3
flist1.assign(5, 10);       // flist1 now contains 10 10 10 10 10

forward_list<int> flist = {10, 20, 30};       // Initializing
flist.insert_after(flist.begin(), {1, 2, 3}); // 10 1 2 3 20 30
flist.insert_after(flist.begin(), 20);        // 10 20 1 2 3 20 30
flist.remove(20);                           // removes all occurrences of 20. Now 10 1 2 3 30
