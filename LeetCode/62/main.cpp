#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> cur(n);
		for (int i = 0; i < n; i++)
			cur[i] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				cur[j] += cur[j-1];
			}
		}
		return cur[n-1];
	}
};

int main() {
	Solution s;
	cout << s.uniquePaths(99, 99) << endl;
}