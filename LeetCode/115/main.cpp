#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int m = t.size() + 1, n = s.size() + 1;
		vector<long> dp(n);
		for (size_t i = 0; i < n; i++) {
			dp[i] = 1;
		}
		for (size_t i = 1; i < m; i++) {
			long pre = dp[0];
			dp[0] = 0;
			for (size_t j = 1; j < n; j++) {
				long tmp = dp[j];
				if (t[i - 1] == s[j - 1]) {
					dp[j] = dp[j - 1] + pre;
				} else {
					dp[j] = dp[j - 1];
				}
				pre = tmp;
			}
		}
		return dp[n-1];
	}
};

int main() {
	Solution s;
	cout << s.numDistinct("babgbag", "bag") << endl;
	return 0;
}