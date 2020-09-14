#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        char c[2] = {0};
        if (n % 26 == 0) {
            c[0] = 'Z';
            n -= 26;
        } else {
            c[0] = 'A' + n % 26 - 1;
        }
        string r = c;
        while (n / 26 >= 26) {
            n /= 26;
            if (n % 26 == 0) {
                c[0] = 'Z';
                n -= 26;
            } else {
                c[0] = 'A' + n % 26 - 1;
            }
            r = c + r;
        }
        if (n / 26 > 0) {
            c[0] = 'A' + n / 26 - 1;
            r = c + r;
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.convertToTitle(28) << endl;
    return 0;
}