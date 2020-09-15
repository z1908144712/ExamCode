#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) {
			return false;
		}
		int n = matrix[0].size();
		if (n == 0) {
			return false;
		}
		int t = -1;
		for (int i = 0; i < m; i++) {
			if (target >= matrix[i][0]) {
				if (target == matrix[i][0] || target == matrix[i][n-1]) {
					return true;
				} else if (target < matrix[i][n-1]) {
					t = i;
					break;
				}
			} else {
				return false;
			}
		}
		if (t == -1) {
			return false;
		}
		int left = 1, right = n - 2, middle;
		while (left <= right) {
			middle = (left + right) / 2;
			if (matrix[t][middle] == target) {
				return true;
			} else if (matrix[t][middle] > target) {
				right = middle-1;
			} else {
				left = middle+1;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix = {
		{{-8,-8,-6},{-3,-2,0}}
	};
	int target = 3;
	cout << s.searchMatrix(matrix, target) << endl;
}