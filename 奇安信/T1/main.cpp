#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 0 || n > 36) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i - 1 == 0) {
			dp[i] = 1;
			continue;
		}
		if (i - 2 == 0) {
			dp[i] = 2;
			continue;
		}
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
	return 0;
}