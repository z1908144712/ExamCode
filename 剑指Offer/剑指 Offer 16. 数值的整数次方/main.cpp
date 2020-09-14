#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        map<long long, double> mp;
        double r = 1.0;
        long long i = 0;
        long long nt = n;
        bool change = false;
        if (nt < 0) {
            nt = abs(nt);
            change = true;
        }
        while (i < nt) {
            if (mp.empty()) {
                r *= x;
                mp[++i] = r;
            } else {
                for (auto it = mp.rbegin(); it != mp.rend(); it++) {
                    if (it->first <= nt - i) {
                        r *= it->second;
                        i += it->first;
                        mp[i] = r;
                        break;
                    }
                }
            }
        }
        return change ? 1.0 / r : r;
    }
};

int main() {
    cout << Solution().myPow(1.00000, -2147483648) << endl;
    return 0;
}