#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<vector<int>> dp1(n + 1, vector<int>(2)), dp2(n + 1, vector<int>(2));
        dp1[0][0] = dp1[0][1] = dp2[1][0] = dp2[1][1] = 0;
        for (int i = 1; i <= n; i++) {
            if (i < n) {
                dp1[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]);
                dp1[i][1] = dp1[i - 1][0] + nums[i - 1];
            }
            if (i > 1) {
                dp2[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]);
                dp2[i][1] = dp2[i - 1][0] + nums[i - 1];
            }
        }
        return max(max(dp1[n - 1][0], dp1[n - 1][1]), max(dp2[n][0], dp2[n][1]));
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1 };
    cout << sol.rob(nums) << endl;
    return 0;
}