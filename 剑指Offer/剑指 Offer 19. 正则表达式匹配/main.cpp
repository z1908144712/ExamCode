#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, 0, p, 0);
    }

    bool isMatchHelper(string &s, int si, string &p, int pi) {
        if (si >= s.size()) {
            if ((p.size() - pi) % 2) {
                return false;
            }
            int i = pi + 1;
            while (i < p.size()) {
                if (p[i] != '*') {
                    return false;
                }
                i += 2;
            }
            return true;
        }
        if (pi >= p.size()) {
            return false;
        }
        char flag = 'a';
        if (pi + 1 < p.size()) {
            flag = p[pi + 1];
        }
        if (flag != '*') {
            if (s[si] == p[pi] || p[pi] == '.') {
                return isMatchHelper(s, si + 1, p, pi + 1);
            } else {
                return false;
            }
        } else {
            if (s[si] == p[pi] || p[pi] == '.') {
                return isMatchHelper(s, si + 1, p, pi) || isMatchHelper(s, si, p, pi + 2);
            } else {
                return isMatchHelper(s, si, p, pi + 2);
            }
        }
    }
};

int main() {
    string s = "aa";
    string p = "a*";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}