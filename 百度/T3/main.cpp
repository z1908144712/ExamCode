#include <iostream>
#include <vector>

using namespace std;

int main() {
	string n;
	while (cin.peek() != EOF) {
		cin >> n;
		cout << n << endl;
	}
	/*int n, m;
	cin >> n >> m;
	int mod = 1e9 + 7;
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i < j) {
				break;
			}
			for (int k = 0; k <= m; k++) {
				if (k == j) {
					continue;
				}
				if (i == j && k == 0) {
					dp[i][j][k] = 1;
					continue;
				}
				for (int l = 0; l <= m; l++) {
					if (l == j || i == j) {
						continue;
					}
					dp[i][j][k] = (dp[i][j][k] + dp[i - j][k][l]) % mod;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			sum = (sum + dp[n][i][j]) % mod;
		}
	}
	cout << sum << endl;
	return 0;*/
}