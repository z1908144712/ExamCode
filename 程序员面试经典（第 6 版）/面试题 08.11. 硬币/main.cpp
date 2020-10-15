#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        vector<int> fees{1, 5, 10, 25};
        vector<int> dp(n + 1, 0);
        int mod = 1000000007;
        dp[0] = 1;
        for (auto &fee : fees) {
            for (int i = fee; i <= n; i++) {
                dp[i] = (dp[i] + dp[i - fee]) % mod;
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().waysToChange(10) << endl;
	return 0;
}