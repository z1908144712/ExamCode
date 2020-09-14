#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = INT_MAX;
				for (int x = i; x <= j; x++) {
					dp[i][j] = min(dp[i][j], max(dp[i][x - 1], dp[x + 1][j]) + 1);
				}
			}
		}
	}
	cout << dp[1][n] - k << endl;
	return 0;
}