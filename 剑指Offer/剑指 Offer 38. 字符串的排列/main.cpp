#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> r;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return r;
    }

    void dfs(string& s, int x) {
        if (x == s.size() - 1) {
            r.push_back(s);
            return;
        }
        set<char> st;
        for (int i = x; i < s.size(); i++) {
            if (st.count(s[i])) {
                continue;
            }
            st.insert(s[i]);
            swap(s[i], s[x]);
            dfs(s, x + 1);
            swap(s[i], s[x]);
        }
    }
};

int main() {
    string s = "aabc";
    vector<string> r = Solution().permutation(s);
    for (auto &i : r) {
        cout << i << endl;
    }
    return 0;
}