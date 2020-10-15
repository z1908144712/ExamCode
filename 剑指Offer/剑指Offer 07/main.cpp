#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> fb(n + 1);
        int mod = 1000000007;
        fb[0] = 0;
        if (n > 0) {
            fb[1] = 1;
            for (int i = 2; i <= n; i++) {
                fb[i] = (fb[i - 1] + fb[i - 2]) % mod;
            }
        }
        return fb[n];
    }
};

int main() {
    cout << Solution().fib(100) << endl;
    return 0;
}