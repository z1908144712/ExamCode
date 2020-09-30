#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int mod = 1000000007;
    int waysToStep(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2])%mod + dp[i - 3])%mod;
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().waysToStep(5) << endl;
	return 0;
}