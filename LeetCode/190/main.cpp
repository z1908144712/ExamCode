#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<bool> bits(32);
        for (int i = 0; i < 32; i++) {
            bits[31 - i] = n & 1;
            n >>= 1;
        }
        uint32_t r = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i])
                r += bits[i] * (1 << i);
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseBits(4294967293) << endl;
    return 0;
}