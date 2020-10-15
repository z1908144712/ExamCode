#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> stackA, stackB;
    CQueue() {

    }

    void appendTail(int value) {
        stackA.push(value);
    }

    int deleteHead() {
        if (stackB.empty()) {
            while (!stackA.empty()) {
                stackB.push(stackA.top());
                stackA.pop();
            }
        }
        if (stackB.empty()) {
            return -1;
        }
        int r = stackB.top();
        stackB.pop();
        return r;
    }
};

int main() {

	return 0;
}