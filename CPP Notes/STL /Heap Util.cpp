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


>> priority_queue can be directly used to implement Heap.

#include <queue>

priority_queue <int> gquiz; // Max Heap
gquiz.push(10);
gquiz.push(30);
gquiz.push(20);
gquiz.push(5);
gquiz.push(1);

The priority queue gquiz is : 30 20 10 5 1
gquiz.size() : 5
gquiz.top() : 30
gquiz.pop(); // gquiz now contains 20 10 5 1


// Min heap using priority_queue
priority_queue <int, vector<int>, greater<int>> pq;
pq.push(5);
pq.push(1);
pq.push(10);
pq.push(30);
pq.push(20);  // pq now contains 1 5 10 20 30

// min-heap on user-defined class
class Point
{
   int x;
   int y;
public:
   Point(int _x, int _y)
   {
      x = _x;
      y = _y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};

class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};

int main ()
{
    // Creates a Min heap of points (order by x coordinate)
    priority_queue <Point, vector<Point>, myComparator> pq;

    // Insert points into the min heap
    pq.push(Point(10, 2));
    pq.push(Point(2, 1));
    pq.push(Point(1, 5));

    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        Point p = pq.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << endl;
        pq.pop();
    }

    return 0;
}
Output :
(1, 5)
(2, 1)
(10, 2)


//init from vector
vector<int> array {10, 30, 20};
priority_queue<int> pq(begin(array), end(array));
