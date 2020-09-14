#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxLen = 0;
        for (int d : dp) {
            if (maxLen < d) {
                maxLen = d;
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> nums = { 10,9,2,5,3,4 };
    cout << Solution().lengthOfLIS(nums) << endl;
    return 0;
}