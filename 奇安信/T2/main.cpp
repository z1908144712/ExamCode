#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> datas{1, 1, 1,1,1};
	vector<int> dp(datas.size(), 1);
	for (int i = 1; i < dp.size(); i++) {
		if (datas[i] > datas[i - 1]) {
			dp[i] = dp[i - 1] + 1;
		}
	}
	int sum = 0;
	for (int i = dp.size() - 1; i >= 0; i--) {
		if (i - 1 >= 0 && datas[i - 1] > datas[i]) {
			dp[i - 1] = dp[i] + 1;
		}
		sum += dp[i];
	}
	cout << sum << endl;
	return 0;
}