#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	int lmax = nums[l], rmax = nums[r];
	int ans = 0;
	while (l <= r) {
		lmax = max(lmax, nums[l]);
		rmax = max(rmax, nums[r]);
		if (lmax < rmax) {
			ans += lmax - nums[l++];
		} else {
			ans += rmax - nums[r--];
		}
	}
	return ans;
}

int main() {
	vector<int> nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trap(nums) << endl;
	return 0;
}