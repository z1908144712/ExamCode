#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> sub;
		size_t n = 1 << nums.size();
		bool flag;
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < n; i++) {
			sub.clear();
			flag = false;
			for (size_t j = 0; j < nums.size(); j++) {
				if ((i >> j)& 1) {
					if (j > 0 && nums[j-1] == nums[j] && !((i>>(j-1))&1)) {
						flag = true;
						break;
					} else {
						sub.push_back(nums[j]);
					}
				}
			}
			if (!flag) {
				ans.push_back(sub);
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> nums = {1, 2, 2,2,2};
	vector<vector<int>> ans = s.subsetsWithDup(nums);
	for (size_t i = 0; i < ans.size(); i++) {
		cout << "{ " ;
		for (size_t j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "}" <<endl;
	}
}