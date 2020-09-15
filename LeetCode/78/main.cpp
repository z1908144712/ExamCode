#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0) {
			return { {} };
		}
		if (nums.size() == 1) {
			return { {}, nums };
		}
		vector<vector<int>> ans;
		ans.push_back({});
		ans.push_back(nums);
		for (size_t i = 0; i < nums.size(); i++) {
			ans.push_back({nums[i]});
		}
		if (nums.size() == 2) {
			return ans;
		}
		vector<int> stack;
		for (size_t k = 2; k < nums.size(); k++) {
			for (size_t i = 0; i < k; i++) {
				stack.push_back(i);
			}
			while (stack.size() > 0) {
				if (stack.size() == k && stack.back() < nums.size()) {
					vector<int> data;
					for (unsigned int j = 0; j < stack.size(); j++) {
						data.push_back(nums[stack[j]]);
					}
					ans.push_back(data);
					stack.back()++;
				} else {
					while (stack.size() > 0 && stack.back() >= nums.size() - k + stack.size()) {
						stack.pop_back();
					}
					if (stack.size() > 0) {
						stack.back()++;
						while (stack.size() < k) {
							stack.push_back(stack.back() + 1);
						}
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1};
	vector<vector<int>> ans = s.subsets(nums);
	for (size_t i = 0; i < ans.size(); i++) {
		cout << "{" << " ";
		for (size_t j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "}" << endl;
	}
}