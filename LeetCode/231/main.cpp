#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        while (n != 0) {
            if (n & 1) {
                if (count == 1) {
                    return false;
                }
                count++;
            }
            n >>= 1;
        }
        if (count == 1) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.isPowerOfTwo(21) << endl;
    return 0;
}