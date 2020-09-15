#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		size_t m = matrix.size();
		if (m == 0) {
			return 0;
		}
		size_t n = matrix[0].size();
		if (n == 0) {
			return 0;
		}
		vector<int> heights(n);
		vector<int> stack = { -1 };
		int maxArea = 0;
		for (size_t i = 0; i < m; i++) {
			for (size_t j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					heights[j] += 1;
				} else {
					heights[j] = 0;
				}
			}
			for (size_t j = 0; j < n; j++) {
				while (stack.size() > 1 && heights[j] < heights[stack.back()]) {
					int top = stack.size() - 1;
					int area = (j - stack[top - 1] - 1) * heights[stack[top]];
					maxArea = maxArea > area ? maxArea : area;
					stack.pop_back();
				}
				stack.push_back(j);
			}
			if (stack.size() > 1) {
				int right = stack.back();
				while (stack.size() > 1) {
					int top = stack.size() - 1;
					int area = (right - stack[top - 1]) * heights[stack[top]];
					maxArea = maxArea > area ? maxArea : area;
					stack.pop_back();
				}
			}
		}
		return maxArea;
	}
};

int main() {
	Solution s;
	vector<vector<char>> matrix = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	cout << s.maximalRectangle(matrix) << endl;
}