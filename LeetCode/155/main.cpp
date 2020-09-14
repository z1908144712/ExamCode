#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> nums;
    int minIndex;
    /** initialize your data structure here. */
    MinStack() {
        minIndex = -1;
    }

    void push(int x) {
        if (minIndex == -1) {
            minIndex = 0;
        } else {
            if (nums[minIndex] > x) {
                minIndex = nums.size();
            }
        }
        nums.push_back(x);
    }

    void pop() {
        nums.pop_back();
        if (minIndex == nums.size()) {
            minIndex = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[minIndex] > nums[i]) {
                    minIndex = i;
                }
            }
        }
    }

    int top() {
        return nums.back();
    }

    int getMin() {
        return nums[minIndex];
    }
};

int main() {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;   //-- > ·µ»Ø - 3.
    minStack->pop();
    cout << minStack->top() << endl;     // -- > ·µ»Ø 0.
    cout << minStack->getMin() << endl;  // -- > ·µ»Ø - 2.
}