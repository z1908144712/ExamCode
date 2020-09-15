#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		size_t n = triangle.size();
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return triangle[0][0];
		}
		vector<int> dp(n, 0);
		dp[0] = triangle[0][0];
		int pre = dp[0];
		int minDP;
		for (size_t i = 1; i < n; i++) {
			for (size_t j = 0; j <= i; j++) {
				int tmp = dp[j];
				if (j == 0) {
					dp[j] += triangle[i][j];
				} else if (j == i) {
					dp[j] = pre + triangle[i][j];
				} else {
					dp[j] = min(pre, dp[j]) + triangle[i][j];
				}
				pre = tmp;
				if (i == n - 1) {
					if (j == 0) {
						minDP = dp[j];
					} else {
						minDP = min(minDP, dp[j]);
					}
				}
			}
		}
		return minDP;
	}
};

int main() {
	Solution s;
	vector<vector<int>> triangle = {{2},{3, 4},{6, 5, 7},{4, 1, 8, 3}};
	cout << s.minimumTotal(triangle) << endl;
	return 0;
}