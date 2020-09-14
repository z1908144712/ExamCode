#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<int, int> mp;
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        if (mp.count(n)) {
            return mp[n];
        }
        int tmp = fib(n - 1) + fib(n - 2);
        if (tmp >= 1000000007) {
            tmp %= 1000000007;
        }
        mp[n] = tmp;
        return tmp;
    }
};

int main() {
    cout << Solution().fib(100) << endl;
    return 0;
}