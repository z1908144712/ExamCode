#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> dp(s.size());
	for (int i = 0; i < n; i += 2) {
		int x = 0, y = 0;
		if (s[i] >= 'A' && s[i] <= 'Z') {
			x++;
		} else {
			y++;
		}
		if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
			x++;
		} else {
			y++;
		}
		if (x != y) {
			x = 1;
		} else {
			x = 0;
		}
		if (i - 2 < 0) {
			dp[i] = x;
		} else {
			dp[i] = dp[i - 2] + x;
		}
	}
	cout << dp[n - 2] << endl;
	return 0;
}