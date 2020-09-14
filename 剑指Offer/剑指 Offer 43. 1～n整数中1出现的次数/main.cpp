#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int r = 0, high = n / 10, cur = n % 10, low = 0;
        long digit = 1;
        while (high || cur) {
            if (cur == 0) {
                r += high * digit;
            } else if (cur == 1) {
                r += high * digit + low + 1;
            } else {
                r += (high + 1) * digit;
            }
            low += cur * digit;
            digit *= 10;
            cur = high % 10;
            high /= 10;
        }
        return r;
    }
};

int main() {
    cout << Solution().countDigitOne(12) << endl;
    return 0;
}