#include <iostream>
#include <vector>

using namespace std;

class KMP {
private:
	vector<vector<int>> dp;
	string pat;

public:
	KMP(string pat) {
		this->pat = pat;
		int M = pat.size();
		dp = vector<vector<int>>(M, vector<int>(256));
		dp[0][pat[0]] = 1;
		int X = 0;
		for (int j = 1; j < M; j++) {
			for (int c = 0; c < 256; c++) {
				dp[j][c] = dp[X][c];
		    }
			dp[j][pat[j]] = j + 1;
			X = dp[X][pat[j]];
		}
	}

	int search(string txt) {
		int M = pat.size();
		int N = txt.size();
		int j = 0;
		for (int i = 0; i < N; i++) {
			j = dp[j][txt[i]];
			if (j == M) {
				return i - M + 1;
			}
		}
		return -1;
	}
};

int main() {
	string txt = "aaacaaab";
	string pat = "aab";
	KMP kmp(pat);
	cout << kmp.search(txt) << endl;
	return 0;
}