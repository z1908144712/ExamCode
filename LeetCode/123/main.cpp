#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0) {
			return 0;
		}
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
		for (int i = 0; i < n; i++) {
			for (int j = 2; j >= 1; j--) {
				if (i == 0) {
					dp[i][j][0] = 0;
					dp[i][j][1] = -prices[i];
					continue;
				}
				dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
			}
		}
		return dp[n-1][2][0];
	}
};

int main() {
	Solution s;
	vector<int> prices = { 3,3,5,0,0,3,1,4 };
	cout << s.maxProfit(prices) << endl;
	return 0;
}