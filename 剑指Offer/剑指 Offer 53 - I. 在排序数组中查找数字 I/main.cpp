#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target) - helper(nums, target - 1);
    }

	int helper(vector<int>& nums, int target) {
	    int l = 0, r = nums.size() - 1;
    	while (l <= r) {
    		int m = (l + r) / 2;
    		if (nums[m] <= target) {
    			l = m + 1;
    		} else {
    			r = m - 1;
    		}
    	}
    	return l;
    }
};

int main() {
    vector<int> nums = { 5,7,7,8,8,8 };
    int target = 8;
    cout << Solution().search(nums, target) << endl;
    return 0;
}