#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int  m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<long>> dp(m, vector<long>(n));
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (obstacleGrid[0][i]) {
				flag = true;
			}
			dp[0][i] = flag ? 0 : 1;
		}
		flag = false;
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0]) {
				flag = true;
			}
			dp[i][0] = flag ? 0 : 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j]) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = dp[i][j - 1] + dp[i-1][j];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
	Solution s;
	vector<vector<int>> obstacleGrid = { {0}, {1} };
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}