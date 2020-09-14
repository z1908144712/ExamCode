#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long _numerator = numerator, _denominator = denominator;
        if (_numerator % _denominator == 0) {
            return to_string(_numerator / _denominator);
        }
        string flag = "";
        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) {
            flag = "-";
        }
        _numerator = abs(_numerator);
        _denominator = abs(_denominator);
        string res = to_string(_numerator / _denominator) + ".";
        long long a = _numerator % _denominator;
        string e = "";
        map<long, string> m;
        vector<long> v;
        while (a > 0) {
            long long b = a;
            a *= 10;
            string c = to_string(a / _denominator);
            a = a % _denominator;
            v.push_back(b);
            m.insert(make_pair(b, c));
            if (m.count(a)) {
                string _e = "";
                int i = 0;
                for (; i < v.size(); i++) {
                    if (v[i] != a) {
                        e += m[v[i]];
                    } else {
                        break;
                    }
                }
                if (i >= v.size()) {
                    break;
                }
                e += "(";
                for (; i < v.size(); i++) {
                    e += m[v[i]];
                }
                e += ")";
                break;
            }
        }
        if (a == 0) {
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != a) {
                    e += m[v[i]];
                } else {
                    break;
                }
            }
        }
        return flag + res + e;
    }
};

int main() {
    Solution sol;
    cout << sol.fractionToDecimal(-2147483648, 1) << endl;
    return 0;
}