#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() < 2) {
            return 0;
        }
        int n = prices.size();
        if (k > n / 2) {
            vector<vector<int>> dp(n + 1, vector<int>(2));
            for (int i = 0; i <= n; i++) {
                if (i == 0) {
                    dp[i][0] = 0;
                    dp[i][1] = INT_MIN;
                } else {
                    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
                    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
                }
            }
            return dp[n][0];
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = INT_MIN;
                } else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
                }
            }
        }
        return dp[n][k][0];
    }
};

int main() {
    Solution sol;
    //vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    //vector<int> prices = { 1,3,5,4,3,7,6,9,2,4 };
    //vector<int> prices = { 3,3,5,0,0,3,1,4};
    //vector<int> prices = {2,6,8,7,8,7,9,4,1,2,4,5,8};
    //vector<int> prices = { 0,8,5,7,4,7 };
    //vector<int> prices = { 5,2,3,2,6,6,2,9,1,0,7,4,5,0 };
    //vector<int> prices = { 9,9,0,3,0,7,7,7,4,1,5,0,1,7 };
    //vector<int> prices = { 3,5,3,4,1,4,5,0,7,8,5,6,9,4,1 };
    //vector<int> prices = { 8,6,4,3,3,2,3,5,8,3,8,2,6};
    //vector<int> prices = { 1,2,4,2,5,7,2,4,9,0,9};
    //vector<int> prices = {3,4,6,0,3,7,5,8,2,9,1,6,6,2};
    //vector<int> prices = { 4,7,2,6,4,3,8,2,7,5};
    vector<int> prices = { 48,12,60,93,97,42,25,64,17,56,85,93,9,48,52,42,58,85,81,84,69,36,1,54,23,15,72,15,11,94};
    //vector<int> prices = { 2, 4, 1 };
    cout << sol.maxProfit(7, prices) << endl;
    return 0;
}