#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
      stack<int> mainStack, auxStack;

public:
      void push(int data);
      int pop();
      int getMin();
};

void Stack::push(int data) {
      mainStack.push(data);
      if (auxStack.empty()) {
            auxStack.push(data);
            return;
      }
      if(data < auxStack.top()) {
            auxStack.push(data);
      }
}

int Stack::pop() {
      if (auxStack.top() == mainStack.top()) {
            auxStack.pop();
      }
      mainStack.pop();
}

int Stack::getMin() {
      return auxStack.top();
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.getMin()<<endl;
    s.push(5);
    cout<<s.getMin();
    return 0;
}
