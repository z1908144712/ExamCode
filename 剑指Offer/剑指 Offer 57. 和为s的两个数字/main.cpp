#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            if (nums[L] == target - nums[R]) {
                return {nums[L], nums[R]};
            } else if (nums[L] < target - nums[R]) {
                L++;
            } else {
                R--;
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums = { 10,26,30,31,47,60 };
    int target = 56;
    vector<int> r = Solution().twoSum(nums, target);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}