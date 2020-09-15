#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n, vector<int>(n));
		if (n == 0) {
			return ans;
		}
		int num = 1, i = 0, j = 0, vi = 1, vj = 1, head = 0, tail = n - 1;
		bool flag = true;
		while (num <= n * n) {
			if (flag) {
				if (j <= tail && j >= head) {
					//cout << i << " " << j << " " << num << endl;
					ans[i][j] = num++;
					j += vj;
				}
				else {
					flag = false;
					vj *= -1;
					j += vj;
					i += vi;
					if (vj == 1) {
						head++;
					}
				}
			}
			else {
				if (i <= tail && i >= head) {
					//cout << i << " " << j << " " << num << endl;
					ans[i][j] = num++;
					i += vi;
				}
				else {
					flag = true;
					vi *= -1;
					i += vi;
					j += vj;
					if (vi == 1) {
						tail--;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> ans = s.generateMatrix(5);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}