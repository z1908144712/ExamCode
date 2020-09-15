#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        if (text.size() == 0) {
            return text;
        }
        vector<int> count(256, 0);
        for (auto& c : text) {
            count[c]++;
        }
        stack<int> st;
        vector<bool> visited(256, false);
        for (auto& c : text) {
            count[c]--;
            if (visited[c]) {
                continue;
            }
            while (!st.empty() && st.top() > c) {
                if (count[st.top()] == 0) {
                    break;
                }
                visited[st.top()] = false;
                st.pop();
            }
            visited[c] = true;
            st.push(c);
        }
        string r;
        while (!st.empty()) {
            r = (char)st.top() + r;
            st.pop();
        }
        return r;
    }
};

int main() {
    string s = "leetcode";
    cout << Solution().smallestSubsequence(s) << endl;
	return 0;
}