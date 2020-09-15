#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) {
			return { 1 };
		}
		if (rowIndex == 1) {
			return { 1, 1 };
		}
		vector<int> ans(rowIndex + 1);
		ans[0] = ans[1] = 1;
		for (int i = 2; i <= rowIndex; i++) {
			int pre = 1, tmp = 1;
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) {
					ans[j] = 1;
				} else {
					tmp = ans[j];
					ans[j] += pre;
				}
				pre = tmp;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> ans = s.getRow(10);
	for (size_t i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}