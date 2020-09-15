#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.size() == 0) {
			return ans;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		int mi = 0, ni = 0;
		int i = mi, j = ni, iv = 1, jv = 1, flag = 1;
		while (i >= 0 && i < m && mi < m && j >= 0 && j < n && ni < n) {
			cout << i << " " << j << " " << mi << " " << m << " " << ni << " " << n << endl;
			ans.push_back(matrix[i][j]);
			if (flag) {
				j += jv;
			}
			else {
				i += iv;
			}
			if (jv == 1 && j == n) {
				j--;
				jv = -1;
				mi++;
				i = mi;
				flag = 0;
			}
			if (jv == -1 && j == ni - 1) {
				j++;
				jv = 1;
				m--;
				i--;
				flag = 0;
			}
			if (iv == 1 && i == m) {
				i--;
				iv = -1;
				n--;
				j--;
				flag = 1;
			}
			if (iv == -1 && i == mi - 1) {
				i++;
				iv = 1;
				ni++;
				j = ni;
				flag = 1;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix = { {2,3,4},{5,6,7},{8,9,10},{11,12,13} };
	vector<int> ans = s.spiralOrder(matrix);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}