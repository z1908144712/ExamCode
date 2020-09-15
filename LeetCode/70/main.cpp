#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 2) {
			return n;
		}
		int x1 = 1, x2 = 2, x3;
		for (int i = 2; i < n; i++) {
			x3 = x1 + x2;
			x1 = x2;
			x2 = x3;
		}
		return x3;
	}
};

int main() {
	Solution s;
	cout << s.climbStairs(10) << endl;
	return 0;
}