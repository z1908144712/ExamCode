#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (left != i) {
                    nums[left] = nums[i];
                }
                left++;
            }
            if (nums[i] == 0) {
                count++;
            }
        }
        for (int i = nums.size() - count; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    vector<int> nums = { 2,1};
    Solution().moveZeroes(nums);
    for (int n : nums) {
        cout << n << " ";
    }
    return 0;
}