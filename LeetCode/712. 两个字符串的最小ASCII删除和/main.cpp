#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(s1, 0, s2, 0);
    }

    int dp(string& s1, int i, string& s2, int j) {
        int res = 0;
        if (i == s1.size()) {
            for (; j < s2.size(); j++) {
                res += s2[j];
            }
            return res;
        }
        if (j == s2.size()) {
            for (; i < s1.size(); i++) {
                res += s1[i];
            }
            return res;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s1[i] == s2[j]) {
            memo[i][j] = dp(s1, i + 1, s2, j + 1);
        } else {
            memo[i][j] = min(s1[i] + dp(s1, i + 1, s2, j), s2[j] + dp(s1, i, s2, j + 1));
        }
        return memo[i][j];
    }
};

int main() {
    cout << Solution().minimumDeleteSum("delete", "leet") << endl;
	return 0;
}