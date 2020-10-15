#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        for (auto& num : pushed) {
            st.push(num);
            while (!st.empty() && st.top() == popped[i]) {
                i++;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,5,3,1,2 };
    cout << Solution().validateStackSequences(pushed, popped) << endl;
    return 0;
}