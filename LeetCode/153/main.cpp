#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        int max = 0;
        while (max < nums.size() - 1 && nums[max] < nums[max + 1]) {
            max++;
        }
        if (max < nums.size() - 1) {
            return nums[max + 1];
        } else {
            return nums[0];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 4,5,6,7,0,1,2 };
    cout << sol.findMin(nums) << endl;
    return 0;
}