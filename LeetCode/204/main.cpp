#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        int r = 0;
        vector<bool> mark(n);
        for (int i = 2; i * i < n; i++) {
            if (!mark[i]) {
                for (int j = 2; i * j < n; j++) {
                    mark[i * j] = true;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (!mark[i]) {
                r++;
            }
        }
        return r;
    }
};

int main() {
    Solution sol;
    cout << sol.countPrimes(499979) << endl;
    return 0;
}