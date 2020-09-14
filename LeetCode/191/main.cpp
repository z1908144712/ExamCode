#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r = 0;
        for (int i = 0; i < 32 && n > 0; i++) {
            if (n & 1) {
                r++;
            }
            n >>= 1;
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.hammingWeight(11) << endl;
    return 0;
}