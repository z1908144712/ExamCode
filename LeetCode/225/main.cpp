#include <iostream>
#include <list>
using namespace std;

class MyStack {
public:
    list<int> queue;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = queue.back();
        queue.pop_back();
        return r;
    }

    /** Get the top element. */
    int top() {
        return queue.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.empty();
    }
};

int main() {
    MyStack* stack = new MyStack();
    stack->push(1);
    stack->push(2);
    cout << stack->top() << endl;
    cout << stack->pop() << endl;
    cout << stack->empty() << endl;
    return 0;
}