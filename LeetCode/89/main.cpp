#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		for (int i = 0; i < (1 << n); i++) {
			ans.push_back(i ^ (i >> 1));
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> ans = s.grayCode(10);
	for (size_t i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}