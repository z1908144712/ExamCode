#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long count = 9, start = 1;
        while (n > count) {
            n -= count;
            digit += 1;
            start *= 10;
            count = 9 * digit * start;
        }
        int num = start + (n - 1) / digit;
        int c = (n - 1) % digit;
        return to_string(num)[c] - '0';
    }
};

int main() {
    cout << Solution().findNthDigit(0) << endl;
    return 0;
}