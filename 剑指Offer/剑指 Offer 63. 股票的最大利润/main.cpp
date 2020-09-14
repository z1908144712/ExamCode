#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> dp(prices.size());
        dp[0] = 0;
        int mi = INT_MAX;
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(dp[i - 1], prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return dp[prices.size() - 1];
    }
};

int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << Solution().maxProfit(prices) << endl;
	return 0;
}