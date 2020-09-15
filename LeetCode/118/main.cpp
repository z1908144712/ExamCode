#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0) {
			return {};
		} else if (numRows == 1) {
			return { {1} };
		} else if (numRows == 2) {
			return { {1}, {1, 1} };
		} else {
			vector<vector<int>> ans = { {1}, {1, 1} };
			for (int i = 3; i <= numRows; i++) {
				vector<int> sub = { 1 };
				for (size_t j = 0; j < ans.back().size() - 1; j++) {
					sub.push_back(ans.back()[j] + ans.back()[j + 1]);
				}
				sub.push_back(1);
				ans.push_back(sub);
			}
			return ans;
		}
	}
};

int main() {
	Solution s;
	vector<vector<int>> ans = s.generate(10);
	for (size_t i = 0; i < ans.size(); i++) {
		for (size_t j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}