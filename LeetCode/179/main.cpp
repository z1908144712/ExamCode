#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string r = "";
        vector<string> snums;
        for (int n : nums) {
            snums.push_back(to_string(n));
        }
        sort(snums.begin(), snums.end(), compare);
        for (string s : snums) {
            if (r.size() > 0 && s.compare("0") == 0 && r[0] == '0') {
                continue;
            }
            r += s;
        }
        return r;
    }

    static bool compare(string& a, string& b) {
        int pos = 0, len;
        if (a.size() > b.size()) {
            len = a.size();
            while (len > 0) {
                if (len > b.size()) {
                    if (a.compare(pos, b.size(), b) == 0) {
                        pos += b.size();
                        len -= b.size();
                    } else {
                        break;
                    }
                } else {
                    if (a.compare(pos, len, b, 0, len) == 0) {
                        return b.compare(len, b.size() - len, a) < 0;
                    } else {
                        break;
                    }
                }
            }
            return a.compare(pos, len, b) > 0;
        }
        if (a.size() < b.size()) {
            len = b.size();
            while (len > 0) {
                if (len >= a.size()) {
                    if (b.compare(pos, a.size(), a) == 0) {
                        pos += a.size();
                        len -= a.size();
                    } else {
                        break;
                    }
                } else {
                    if (b.compare(pos, len, a, 0, len) == 0) {
                        return a.compare(len, a.size() - len, b) > 0;
                    } else {
                        break;
                    }
                }
            }
            return b.compare(pos, len, a) < 0;
        }
        return a.compare(b) > 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519 };
    cout << sol.largestNumber(nums) << endl;
    /*string a = "8308", b = "830";
    cout << sol.compare(a, b) << endl;*/
    return 0;
}