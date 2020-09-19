#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[0][0] = 0;
    	dp[0][1] = INT_MIN;
    	for (int i = 1; i <= n; i++) {
    		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
    		dp[i][1] = max(dp[i - 1][1], (i - 2 < 0 ? 0 : dp[i - 2][0]) - prices[i - 1]);
    	}
    	return dp[n][0];
    }
};

int main() {
    vector<int> prices{1,2,3,0,2};
	cout << Solution().maxProfit(prices)<< endl;
	return 0;
}