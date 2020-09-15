#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int num, count = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (count == 0 || num != nums[i]) {
				num = nums[i];
				count = 1;
			} else if (count == 2 && num == nums[i]) {
				nums.erase(nums.begin() + i--);
			} else {
				count++;
			}
		}
		return nums.size();
	}
};

int main() {
	Solution s;
	vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
	cout << s.removeDuplicates(nums) << endl;
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}