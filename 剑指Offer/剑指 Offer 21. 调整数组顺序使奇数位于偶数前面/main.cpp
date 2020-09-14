#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] % 2) {
                left++;
            }
            while (left < right && nums[right] % 2 == 0) {
                right--;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        return nums;
    }
};

int main() {
    vector<int> nums = { 1,1,3, 5 };
    vector<int> r = Solution().exchange(nums);
    for (auto &i : r) {
        cout << i << " ";
    }
    return 0;
}