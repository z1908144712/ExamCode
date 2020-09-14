#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return backtrace(nums, 0, nums.size() - 1);
    }

    int backtrace(vector<int>& nums, int left, int right) {
        int middle = left + (right - left + 1) / 2;
        if (middle - 1 < 0 && middle + 1 >= nums.size()) {
            return middle;
        }
        if (middle - 1 < 0 && nums[middle] > nums[middle + 1]) {
            return middle;
        }
        if (middle + 1 >= nums.size() && nums[middle] > nums[middle - 1]) {
            return middle;
        }
        if (middle - 1 >= 0 && middle + 1 < nums.size() && nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]) {
            return middle;
        } 
        int r;
        if (middle - 1 >= left) {
            r = backtrace(nums, left, middle - 1);
            if (r >= 0) {
                return r;
            }
        }
        if (middle + 1 <= right) {
            r = backtrace(nums, middle + 1, right);
            if (r >= 0) {
                return r;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    //vector<int> nums = { 1,2,1,3,5,6,4 };
    //vector<int> nums = { 1,2,3,1 };
    //vector<int> nums = { 1 };
    //vector<int> nums = { 2, 1 };
    vector<int> nums = { 1,2,3 };
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}