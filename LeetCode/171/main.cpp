#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int r = 0;
        long e = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            r += (s[i] - 'A' + 1) * e;
            e *= 26;
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.titleToNumber("CFDGSXM") << endl;
    return 0;
}