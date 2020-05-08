>>> Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
with their storage being handled automatically by the container.
>>> Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.

vector<int> g1;
for (int i = 1; i <= 5; i++)
      g1.push_back(i);

for (auto i = g1.begin(); i != g1.end(); ++i)  // 1 2 3 4 5
      cout << *i << " ";

for (auto i = g1.rbegin(); i != g1.rend(); ++i)  // 5 4 3 2 1
      cout << *i << " ";

cout << g1.size(); // 5 - Returns the number of elements in vector
cout << g1.capacity(); // 8 - Returns the size of the storage space currently allocated to the vector
cout << g1.max_size(); // 46116860184273 - Return the max number of elements vector can hold.

g1.resize(4); // Resizes the vector size to 4
g1.empty(); // Returns whether container is empty

g1.shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.

2D vector create:
-----------------

vector<vector<int> > vec(row);

for (int i = 0; i < row; i++) {
    vec[i] = vector<int>(col);
    for (int j = 0; j < col; j++)
        vec[i][j] = j + 1;
}

//create from an array
int arr[5] = {1, 2, 3, 4, 5};
vector<int> vect(arr, arr + 5);

Element Access:
---------------

vector<int> v;
v.assign(5, 10); // fill the array with 10 five times i.e 10, 10, 10, 10, 10

cout << v[i]; // can be accessed like arrays
v.pop_back(); // removes last element and the destructor of the stored object is called, and length of the vector is dec by 1
v.insert(v.begin(), 5); // inserts 5 at the beginning

erase(iterator): Remove elements from a container from the specified position or range
v.erase(v.begin()); // removes the first element
Or
vector<int>::iterator it;
it = v.begin();
v.erase(it);         // removes the first element
v.erase(it1, it2);   // removes elements from it1 to it2 both inclusive

v.clear(); // erases the vector. Size becomes 0

Copying of Vector:
------------------

vector<int> vect1{1, 2, 3, 4};
vector<int> vect2;
vect2 = vect1;       // assigning the new container to old one, copies the vector. In array this makes shallow copy
or
vector<int> vect2(vect1); // Also deep copy
vect2.assign(vect1.begin(), vect1.end()); // Copying container by assign function


Sort Vector of pairs:
---------------------

vector< pair <int,int> > vect;
int arr1[] = {5, 20, 10, 40 };
int arr2[] = {30, 60, 20, 50};
int n = sizeof(arr)/sizeof(arr[0]);
for (int i=0; i<n; i++)
      vect.push_back( make_pair(arr1[i],arr2[i]) );

sort(vect.begin(), vect.end(), SortByFirstAsc);

/*
bool SortByFirstAsc(const pair<int, int> &a,
                    const pair<int, int> &b)
{
      return a.first < b.first;
}
*/
