#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return false;
		}
		size_t maxIndex, left = 0, right = nums.size()-1, middle;
		if (nums[left] == target || nums[right] == target) {
			return true;
		}
		maxIndex = left;
		while (maxIndex < right && nums[maxIndex] <= nums[maxIndex+1]) {
			maxIndex++;
		}
		if (nums[maxIndex] == target || (maxIndex < right && nums[maxIndex+1] == target)) {
			return true;
		} else if (target > nums[left] && target < nums[maxIndex]) {
			right = maxIndex;
		} else if (maxIndex < right && target > nums[maxIndex+1] && target < nums[right]) {
			left = maxIndex + 1;
		} else {
			return false;
		}
		while (left < right) {
			middle = (left + right) / 2;
			if (nums[middle] == target) {
				return true;
			} else if (nums[middle] < target) {
				left = middle+1;
			} else {
				right = middle-1;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1, 1, 3, 1 };
	int target = 3;
	cout << s.search(nums, target) << endl;
	return 0;
}