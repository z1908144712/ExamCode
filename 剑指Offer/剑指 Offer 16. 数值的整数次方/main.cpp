#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // map<long long, double> mp;
        // double r = 1.0;
        // long long i = 0;
        // long long nt = n;
        // bool change = false;
        // if (nt < 0) {
        //     nt = abs(nt);
        //     change = true;
        // }
        // while (i < nt) {
        //     if (mp.empty()) {
        //         r *= x;
        //         mp[++i] = r;
        //     } else {
        //         for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        //             if (it->first <= nt - i) {
        //                 r *= it->second;
        //                 i += it->first;
        //                 mp[i] = r;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return change ? 1.0 / r : r;
        if (x == 0) {
            return 0;
        }
        long b = n;
        double res = 1.0;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        while (b > 0) {
            if (b & 1) {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    cout << Solution().myPow(1.00000, -2147483648) << endl;
    return 0;
}