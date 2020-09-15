#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;
		if (intervals.size() == 0) {
			return { newInterval };
		}
		int index = 0;
		while (index < intervals.size() && newInterval[0] >= intervals[index][0]) {
			index++;
		}
		//cout << index << endl;
		int x, y;
		if (index == 0) {
			x = newInterval[0];
			y = newInterval[1];
		}
		else {
			x = intervals[0][0];
			y = intervals[0][1];
		}
		bool flag = true;
		int x1, y1;
		for (int i = index == 0 ? 0 : 1; i < intervals.size(); i++) {
			x1 = intervals[i][0];
			y1 = intervals[i][1];
			if (index > 0 && index == i && flag) {
				x1 = newInterval[0];
				y1 = newInterval[1];
				i--;
				flag = false;
			}
			if (x1 >= x && x1 <= y) {
				if (y1 > y) {
					y = y1;
				}
			}
			else if (x >= x1 && x <= y1) {
				x = x1;
				if (y1 > y) {
					y = y1;
				}
			}
			else {
				ans.push_back({ x, y });
				x = x1;
				y = y1;
			}
		}
		if (index == intervals.size()) {
			x1 = newInterval[0];
			y1 = newInterval[1];
			if (x1 >= x && x1 <= y) {
				if (y1 > y) {
					y = y1;
				}
			}
			else if (x >= x1 && x <= y1) {
				x = x1;
				if (y1 > y) {
					y = y1;
				}
			}
			else {
				ans.push_back({ x, y });
				x = x1;
				y = y1;
			}
		}
		ans.push_back({ x, y });
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> intervals = { {1,2},{3,5},{6,7},{8,10},{12,16} };
	vector<int> newInterval = { 16,17 };
	vector<vector<int>> ans = s.insert(intervals, newInterval);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	return 0;
}