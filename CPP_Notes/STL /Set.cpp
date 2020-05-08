Sets are a type of associative containers in which each element has to be unique. Implemented as BST.
The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.

begin() – Returns an iterator to the first element in the set.
end() – Returns an iterator to the theoretical element that follows last element in the set.
size() – Returns the number of elements in the set.
max_size() – Returns the maximum number of elements that the set can hold.
empty() – Returns whether the set is empty.
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)– Removes the key value ‘g’ from the set
clear() – Removes all the elements from the set

#include <set>

set <int, greater <int>> gquiz1;
gquiz1.insert(40);
gquiz1.insert(30);
gquiz1.insert(60);
gquiz1.insert(20);
gquiz1.insert(50);
gquiz1.insert(50); // only one 50 will be added to the set
gquiz1.insert(10);

set <int, greater <int> > :: iterator itr;
for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
{
    cout << *itr; // 60 50 40 30 20 10
}
gquiz1.lower_bound(40); // returns iterator of 40
gquiz1.upper_bound(40); // returns iterator of 30

set <int> gquiz2(gquiz1.begin(), gquiz1.end()); // assigning the elements from gquiz1 to gquiz2

Multiset:
----------
Stores elements in sorted order.
It allows storage of multiple elements.
Note:- All other properties similar to set.

    multiset<int> s;
    s.insert(12);
    s.insert(10);
    s.insert(2);
    s.insert(10); // duplicate added
    s.insert(90);
    s.insert(85);
    s.insert(45);
    // 2 10 10 12 45 85 90

Unordered_set:
---------------
Elements can be stored in any order.
Stores only unique values.
Hash-table used to store elements.
Note:- All other properties similar to set.
    unordered_set<int> s;
    s.insert(12);
    s.insert(10);
    s.insert(2);
    s.insert(10); // duplicate not added
    s.insert(90);
    s.insert(85);
    s.insert(45);
    s.insert(12);
    s.insert(70);
    // 70 85 45 12 10 2 90

Unordered_multiset:
--------------------
Elements can be stored in any order.
Duplicate elements can be stored.
Hash-table used to store elements.
Note:- All other properties similar to set.
