#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		for (int i = 0; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int j = 0; j <= n; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i-1] == word2[j-1]) {
					dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] - 1);
				} else {
					dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
				}
			}
		}
		return dp[m][n];
	}

	int min(int a, int b, int c) {
		b = b < c ? b : c;
		return a < b ? a : b;
	}
};

int main() {
	Solution s;
	cout << s.minDistance("intention", "execution") << endl;
}