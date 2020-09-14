#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> r;
        vector<int> dp(6*n + 1, 0);
        for (int i = 1; i <= 6; i++) {
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 6 * i; j >= i; j--) {
                dp[j] = 0;
                for (int k = 1; k <= 6; k++) {
                    if (j - k < i - 1) {
                        break;
                    }
                    dp[j] += dp[j - k];
                }
            }
        }
        double t = pow(1.0/6, n);
        for (int i = n; i <= 6 * n; i++) {
            r.push_back(dp[i] * t);
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