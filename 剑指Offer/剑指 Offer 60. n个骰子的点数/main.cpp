#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> r;
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= i * 6; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j - k <= 0) {
                        break;
                    }
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        double t = pow(6, n);
        for (int i = n; i <= 6 * n; i++) {
            r.push_back(dp[n][i] / t);
        }
        return r;
    }
};

int main() {
    vector<double> r = Solution().twoSum(11);
    for (auto &i : r) {
        cout << i << " ";
    }
	return 0;
}