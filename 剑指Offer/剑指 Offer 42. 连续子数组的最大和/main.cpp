#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}