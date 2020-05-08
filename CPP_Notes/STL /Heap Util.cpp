make_heap() :- This function is used to convert a range in a container to a heap.
front() :- This function displays the first element of heap which is the maximum number.
push_heap() :- This function is used to insert elements into heap.
pop_heap() :- This function is used to delete the maximum element of the heap.
is_heap() :- This function is used to check whether the container is heap or not. // returns true if heap else false

#include <algorithm>

vector<int> v1 = {20, 30, 40, 25, 15};

// Converting vector into a heap using make_heap()
make_heap(v1.begin(), v1.end());
cout << v1.front() << endl; // 40

v1.push_back(50);
// using push_heap() to reorder elements
push_heap(v1.begin(), v1.end());
cout << v1.front() << endl; // 50

// using pop_heap() to delete maximum element
pop_heap(v1.begin(), v1.end());
v1.pop_back();
cout << v1.front() << endl; // 40
