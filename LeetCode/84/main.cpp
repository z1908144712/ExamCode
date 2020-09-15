#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		vector<int> stack = { -1 };
		int maxArea = 0;
		for (size_t i = 0; i < heights.size(); i++) {
			while (stack.size() > 1 && heights[i] < heights[stack.back()]) {
				int top = stack.size() - 1;
				int area = (i - stack[top - 1] - 1) * heights[stack[top]];
				maxArea = maxArea > area ? maxArea : area;
				stack.pop_back();
			}
			stack.push_back(i);
		}
		int height = stack.back();
		while (stack.size() > 1) {
			int top = stack.size() - 1;
			int area = (height - stack[top - 1]) * heights[stack[top]];
			maxArea = maxArea > area ? maxArea : area;
			stack.pop_back();
		}
		return maxArea;
	}
};

int main() {
	Solution s;
	vector<int> heights = { 6, 7, 5, 2, 4, 5, 9, 3 };
	cout << s.largestRectangleArea(heights) << endl;
	return 0;
}