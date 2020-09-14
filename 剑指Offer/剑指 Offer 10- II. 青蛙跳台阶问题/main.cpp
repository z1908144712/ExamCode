#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n < 2) {
            return 1;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            if (dp[i] >= 1000000007) {
                dp[i] %= 1000000007;
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().numWays(2) << endl;
    return 0;
}