#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
public:
    vector<int> stack, tmp;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (stack.size() > 1) {
            tmp.push_back(stack.back());
            stack.pop_back();
        }
        int r = stack.back();
        stack.pop_back();
        while (tmp.size() > 0) {
            stack.push_back(tmp.back());
            tmp.pop_back();
        }
        return r;
    }

    /** Get the front element. */
    int peek() {
        return *stack.begin();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    return 0;
}