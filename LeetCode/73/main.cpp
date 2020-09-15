#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int max = m > n ? m : n;
		vector<int> status;
		for (int i = 0; i < max; i++) {
			status.push_back(0);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					switch (status[i]) {
					case 0:
						status[i] = 1;
						break;
					case 2:
						status[i] += 1;
					default:
						break;
					}
					switch (status[j]) {
					case 0:
						status[j] = 2;
						break;
					case 1:
						status[j] += 2;
					default:
						break;
					}
				}
			}
		}
		for (int i = 0; i < status.size(); i++) {
			switch (status[i]) {
			case 1:
				for (int j = 0; j < n; j++) {
					matrix[i][j] = 0;
				}
				break;
			case 2:
				for (int j = 0; j < m; j++) {
					matrix[j][i] = 0;
				}
				break;
			case 3:
				for (int j = 0; j < n; j++) {
					matrix[i][j] = 0;
				}
				for (int j = 0; j < m; j++) {
					matrix[j][i] = 0;
				}
				break;
			default:
				break;
			}
		}
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix = { 
	{0,1,2,0},
  {3,4,5,2 },
  {1,3,1,5 } };
	s.setZeroes(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}