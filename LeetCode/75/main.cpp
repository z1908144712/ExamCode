#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, tmp;
		for (int i = 0; i <= right; i++) {
			switch (nums[i]) {
			case 0:
				if (left != i) {
					if (nums[left] != 0) {
						tmp = nums[i];
						nums[i] = nums[left];
						nums[left] = tmp;
					}
					left++;
					i--;
				}
				break;
			case 2:
				if (right != i) {
					if (nums[right] != 2) {
						tmp = nums[i];
						nums[i] = nums[right];
						nums[right] = tmp;
					}
					right--;
					i--;
				}
				break;
			default:
				break;
			}
		}
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2,0,2,1,1,0, 1,0, 1,2, 1 };
	s.sortColors(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}