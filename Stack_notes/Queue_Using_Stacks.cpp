#include <iostream>
using namespace std;

class Queue {
private:
      stack<int> s1, s2;

public:
      void enqueue(int data);
      int dequeue();
};

// enqueue operation costly
void Queue::enqueue(int data) {
      // Move all from s1 to s2
      while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
      }
      s1.push(data);
      //move all back from s2 to s1
      while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
      }
}

int Queue::dequeue() {
      if (s1.empty())
            return -1;
      else {
            int tmp = s1.top();
            s1.pop();
            return tmp;
      }
}

int main() {
      Queue q;
      q.enqueue(1);
      q.enqueue(2);
      q.enqueue(3);

      cout << q.dequeue() << endl;
      cout << q.dequeue() << endl;
      q.enqueue(4);
      cout << q.dequeue() << endl;
      return 0;
}
