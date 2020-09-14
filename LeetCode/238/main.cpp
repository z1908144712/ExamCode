#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int R = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= R;
            R *= nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> nums = { 1,2,3,4 };
    for (auto&i : Solution().productExceptSelf(nums)) {
        cout << i << " ";
    }
    return 0;
}