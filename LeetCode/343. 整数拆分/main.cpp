#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        int ThreeTimes = n / 3;
        if (n % 3 == 1) {
            ThreeTimes--;
        }
        int TwoTimes = (n - ThreeTimes * 3) / 2;
        int r = 1;
        while (ThreeTimes) {
            r *= 3;
            ThreeTimes--;
        }
        while (TwoTimes) {
            r *= 2;
            TwoTimes--;
        }
        return r;
    }
};

int main() {
    cout << Solution().integerBreak(10) << endl;
	return 0;
}