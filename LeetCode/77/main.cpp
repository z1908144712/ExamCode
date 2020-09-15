#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		if (n == 0 || k == 0) {
			return ans;
		}
		vector<int> stack;
		if (n <= k) {
			for (int i = 1; i <= n; i++) {
				stack.push_back(i);
			}
			ans.push_back(stack);
			return ans;
		}
		for (int i = 0; i < k; i++) {
			stack.push_back(i + 1);
		}
		while (stack.size() > 0) {
			if (stack.size() == k && stack.back() <= n) {
				ans.push_back(stack);
				stack.back()++;
			} else {
				while (stack.size() > 0 && stack.back() > n - k + stack.size()) {
					stack.pop_back();
				}
				if (stack.size() > 0 && stack.size() < k) {
					stack.back()++;
					while (stack.size() < k) {
						stack.push_back(stack.back() + 1);
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> ans = s.combine(10, 10);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}