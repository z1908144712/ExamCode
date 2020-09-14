#include <iostream>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) {
            return 0;
        }
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
        long r = 1;
        while (ThreeTimes) {
            r *= 3;
            r %= 1000000007;
            ThreeTimes--;
        }
        while (TwoTimes) {
            r *= 2;
            r %= 1000000007;
            TwoTimes--;
        }
        return r;
    }
};

int main() {
    cout << Solution().cuttingRope(1000) << endl;
    return 0;
}