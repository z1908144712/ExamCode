#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while (n) {
            if (n & 1) {
                c++;
            }
            n >>= 1;
        }
        return c;
    }
};

int main() {
    cout << Solution().hammingWeight(9) << endl;
    return 0;
}