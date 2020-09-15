#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		double ans = 1.0, check;
		 do
		 {
			ans = (x / ans + ans) / 2.0;
			check = ans * ans - x;
		 } while ((check >= 0 ? check : -check) > 0.1);
		return (int)ans;
	}
};

int main() {
	Solution s;
	cout << s.mySqrt(2147483647) << endl;
}