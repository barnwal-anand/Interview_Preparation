#include <iostream>
using namespace std;

class Stack {
private:
      int *arr;
      int top;
      int size;

public:
      Stack(int n) {
            size = n;
            top = -1;
            arr = new int[size];
      }
      bool push(int);
      int pop();
};

bool Stack::push(int num) {
      if(top == size-1) {
            cout << "Stack overflow" << endl;
            return false;
      }
      arr[++top] = num;
      return true;
}

int Stack::pop() {
      if(top == -1) {
            cout << "Stack empty" << endl;
            return -1;
      }
      return arr[top--];
}

int main() {
      Stack s1(2);
      s1.push(12);
      s1.push(15);
      s1.push(20);
      cout << s1.pop() << endl;
      cout << s1.pop() << endl;
      return 0;
}
