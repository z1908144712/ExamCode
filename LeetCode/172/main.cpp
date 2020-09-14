#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int r = 0;
        while (n > 0) {
            n /= 5;
            r += n;
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.trailingZeroes(2147483647) << endl;
    //cout << sol.trailingZeroes(100) << endl;
    return 0;
}