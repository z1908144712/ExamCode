#include <iostream>
using namespace std;

class Solution {
public:
    bool scanInt(string& s, int& idx) {
        if (s[idx] == '-' || s[idx] == '+') {
            idx++;
        }
        return scanUnsignedInt(s, idx);
    }

    bool scanUnsignedInt(string& s, int& idx) {
        int pre = idx;
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            idx++;
        }
        return idx > pre;
    }

    bool isNumber(string s) {
        if (s.size() == 0) {
            return false;
        }
        int idx = 0;
        while (idx < s.size() && s[idx] == ' ') {
            idx++;
        }
        bool isnumber = scanInt(s, idx);
        if (s[idx] == '.') {
            idx++;
            isnumber = scanUnsignedInt(s, idx) || isnumber;
        }
        if (s[idx] == 'e' || s[idx] == 'E') {
            idx++;
            isnumber = scanInt(s, idx) && isnumber;
        }
        while (idx < s.size() && s[idx] == ' ') {
            idx++;
        }
        return isnumber && idx == s.size();
        // if (s.empty()) {
        //     return false;
        // }
        // int first = s.find_first_not_of(' ');
        // if (first > 0) {
        //     s = s.substr(first);
        // }
        // int last = s.find_last_not_of(' ') + 1;
        // if (last < s.size()) {
        //     s = s.substr(0, last);
        // }
        // if (s.empty()) {
        //     return false;
        // }
        // bool num_sign = false, 
        //     num_before_point = false, 
        //     num_point = false, 
        //     num_after_point = false, 
        //     num_e = false, 
        //     num_e_sign = false, 
        //     num_e_num = false;
        //
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '+' || s[i] == '-') {
        //         if (num_e) {
        //             if (num_e_num) {
        //                 return false;
        //             }
        //             if (num_e_sign) {
        //                 return false;
        //             }
        //             num_e_sign = true;
        //             continue;
        //         }
        //         if (num_before_point || num_after_point) {
        //             return false;
        //         }
        //         if (num_sign) {
        //             return false;
        //         }
        //         num_sign = true;
        //     } else if (s[i] >= '0' && s[i] <= '9') {
        //         if (num_e) {
        //             if (!num_e_sign) {
        //                 num_e_sign = true;
        //             }
        //             if (!num_e_num) {
        //                 num_e_num = true;
        //             }
        //             continue;
        //         }
        //         if (!num_sign) {
        //             num_sign = true;
        //         }
        //         if (num_point) {
        //             if (!num_after_point) {
        //                 num_after_point = true;
        //             }
        //         } else {
        //             if (!num_before_point) {
        //                 num_before_point = true;
        //             }
        //         }
        //     } else if (s[i] == 'e' || s[i] == 'E') {
        //         if (num_e) {
        //             return false;
        //         }
        //         num_e = true;
        //     } else if (s[i] == '.') {
        //         if (num_e) {
        //             return false;
        //         }
        //         if (!num_sign) {
        //             num_sign = true;
        //         }
        //         if (num_point) {
        //             return false;
        //         }
        //         num_point = true;
        //     } else {
        //         return false;
        //     }
        // }
        // bool num_check = num_point ? num_before_point || num_after_point : num_before_point && !num_after_point;
        // bool num_e_check = num_e ? num_e_num : true;
        // return num_check && num_e_check;
    }
};

int main() {
    cout << Solution().isNumber("   0    ") << endl;
    return 0;
}