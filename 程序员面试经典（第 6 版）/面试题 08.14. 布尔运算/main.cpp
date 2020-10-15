#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<char> st{'&', '|', '^'};

    int cnt = 0;

    void helper(string s, int& result) {
        if (s.size() == 1) {
            if (s[0] == result + '0') {
                cnt++;
            }
            cout << s << endl;
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (st.count(s[i])) {
                string t = s;
                switch (t[i]) {
                case '&':
                    t[i - 1] = ((t[i - 1] - '0') & (t[i + 1] - '0')) + '0';
                    break;
                case '|':
                    t[i - 1] = ((t[i - 1] - '0') | (t[i + 1] - '0')) + '0';
                    break;
                case '^':
                    t[i - 1] = ((t[i - 1] - '0') ^ (t[i + 1] - '0')) + '0';
                    break;
                }
                t.erase(i, 2);
                helper(t, result);
            }
        }
    }

    int countEval(string s, int result) {
        helper(s, result);
        return cnt;
    }
};

int main() {
    cout << Solution().countEval("1^0|0|1", 0) << endl;
	return 0;
}