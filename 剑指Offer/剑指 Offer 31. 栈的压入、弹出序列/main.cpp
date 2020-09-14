#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0 || popped.size() == 0) {
            return pushed.size() == popped.size();
        }
        stack<int> st;
        int pushedi = 0, poppedi = 0;
        while (poppedi < popped.size()) {
            if (st.empty()) {
                if (pushedi < pushed.size()) {
                    st.push(pushed[pushedi++]);
                } else {
                    return false;
                }
            }
            if (st.top() == popped[poppedi]) {
                poppedi++;
                st.pop();
            } else {
                if (pushedi < pushed.size()) {
                    st.push(pushed[pushedi++]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,5,3,1,2 };
    cout << Solution().validateStackSequences(pushed, popped) << endl;
    return 0;
}