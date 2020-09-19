#include <iostream>
#include <vector>

using namespace std;



void matrix(vector<vector<int>>& dp, vector<vector<int>>&s, vector<int>& p, int &n) {
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) {
		for (int i = 1; i <= n-r+1; i++) {
			int j = r + i - 1;
			dp[i][j] = dp[i][i] + dp[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i+ 1; k < j; k++) {
				int tmp = dp[i][k] + dp[k + 1][j] + p[i-1] * p[k] * p[j];
				if (dp[i][j] > tmp) {
					dp[i][j] = tmp;
					s[i][j] = k;
				}
	        }
	    }
	}
}

void printmatrix(vector<vector<int>>&s, int left, int right) {
    if (left == right) {
		cout << "M" << left;
    } else {
		cout << "(";
		printmatrix(s, left, s[left][right]);
		printmatrix(s, s[left][right] + 1, right);
		cout << ")";
    }
}

int main() {
	vector<int> p = {10, 20, 50, 6, 80};
	int n = p.size() - 1;
	vector<vector<int>> dp(p.size(), vector<int>(n+ 1, 0));
	vector<vector<int>> s(p.size(), vector<int>(n+ 1, 0));
    matrix(dp, s, p, n);
	cout << dp[1][n] << endl;
	printmatrix(s, 1, n);
	return 0;
}