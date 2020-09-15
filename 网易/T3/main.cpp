#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	int v;
	vector<int> dp(7, INT_MIN);
	dp[0] = 0;
	while (cin >> v) {
		vector<int> newdp(7);
		int k = v % 7;
		for (int i = 0; i < 7; i++) {
			newdp[(i + v) % 7] = max(dp[i] + v, dp[(i + v) % 7]);
		}
		dp = newdp;
	}
	cout << (dp[0] == 0 ? -1 : dp[0]) << endl;
	return 0;
}
/*
7 3 1 4
6 5
10 20 2 29
*/