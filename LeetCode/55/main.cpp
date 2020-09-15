#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() <= 1) {
			return true;
		}
		int index = 0, len = 0;
		while (index < nums.size() && nums[index] != 0) {
			int maxIndex = index + 1;
			for (int i = index + 2; i < nums.size() && i <= index + nums[index]; i++) {
				if ((i - index + nums[i]) >= (maxIndex - index + nums[maxIndex])) {
					maxIndex = i;
				}
			}
			//cout << nums[index] << nums[maxIndex] << endl;
			if (nums[maxIndex] == 0) {
				len += nums[index];
				index += nums[index];
			}
			else {
				len += maxIndex - index;
				index = maxIndex;
			}
			if (len + nums[maxIndex] >= nums.size() - 1) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2,0 };
	cout << s.canJump(nums) << endl;
	return 0;
}