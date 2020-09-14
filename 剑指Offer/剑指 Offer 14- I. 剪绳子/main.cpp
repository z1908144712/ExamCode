#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        //动态规划
        if (n < 2) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        /*
        vector<int> dp{0, 1, 2, 3};
        for (int i = 4; i <= n; i++) {
            int max = -1;
            for (int j = 1; j < i; j++) {
                int tmp = dp[j] * dp[i - j];
                if (max < tmp) {
                    max = tmp;
                }
            }
            dp.push_back(max);
        }
        return dp[n];*/
        //贪心算法
        int Threetimes = n / 3;
        if (n % 3 == 1) {
            Threetimes--;
        }
        int TwoTimes = (n - Threetimes * 3) / 2;
        return (int)pow(3, Threetimes) * (int)pow(2, TwoTimes);
    }
};

int main() {
    cout << Solution().cuttingRope(58) << endl;
    return 0;
}