Maps are associative containers that store elements in a mapped fashion.
Each element has a key value and a mapped value. No two mapped values can have same key values.
Map is implemented as balanced tree. Time complexity of map operations is O(Log n).

begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
max_size() – Returns the maximum number of elements that the map can hold
empty() – Returns whether the map is empty
pair insert(keyvalue, mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)– Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map
find(key) - If key not found in map iterator to end is returned

#include <map>

map<int, int> gquiz1;
gquiz1.insert(pair<int, int>(1, 40));
gquiz1.insert(pair<int, int>(2, 30));
// assigning the elements from gquiz1 to gquiz2
map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());

int num;
num = gquiz2.erase(4); // remove all elements with key = 4 and return count

gquiz1.lower_bound(1)->first // returns 1
gquiz1.upper_bound(1)->first // returns 2

unordered_map:
---------------
Internally implemented using Hash Table.
The key provided to map are hashed into indices of hash table that is why performance of data structure depends on hash function a lot
but on an average the cost of search, insert and delete from hash table is O(1).
Note: All other Properties are same as Map.

#include <unordered_map>

unordered_map<string, int> umap;
// inserting values by using [] operator
umap["GeeksforGeeks"] = 10;
umap["Practice"] = 20;
for (auto x : umap)
      cout << x.first << " " << x.second << endl;

if (umap.find(key) == umap.end())
      cout << key << " not found";

unordered_map<string, double>:: iterator itr;
for (itr = umap.begin(); itr != umap.end(); itr++)
{
    // itr works as a pointer to pair<string, double> type
    //itr->first stores the key part  and itr->second stroes the value part
    cout << itr->first << "  " << itr->second << endl;
 }

 
