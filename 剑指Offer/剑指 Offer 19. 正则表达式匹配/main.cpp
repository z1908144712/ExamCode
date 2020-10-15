#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    dp[i][j] = i == 0;
                } else {
                    if (p[j - 1] == '*') {
                        if (j >= 2) {
                            dp[i][j] = dp[i][j] | dp[i][j - 2];
                        }
                        if (i > 0 && j > 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                            dp[i][j] = dp[i][j] | dp[i - 1][j];
                        }
                    } else {
                        if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    }
                }
            }
        }
        return dp[m][n];
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