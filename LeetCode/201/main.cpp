#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) {
            return m;
        }
        int a = 0, b = 0;
        vector<bool> am, bn;
        while (m > 0) {
            am.push_back(m & 1);
            a++;
            m >>= 1;
        }
        while (n > 0) {
            bn.push_back(n & 1);
            b++;
            n >>= 1;
        }
        if (a != b) {
            return 0;
        }
        int r = 0;
        for (int i = a - 1; i >= 0; i--) {
            if (am[i] == bn[i]) {
                if (am[i]) {
                    r += 1 << i;
                }
            } else {
                break;
            }
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.rangeBitwiseAnd(11, 12) << endl;
    return 0;
}