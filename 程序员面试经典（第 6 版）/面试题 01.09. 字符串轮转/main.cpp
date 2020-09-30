#include <iostream>

using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int idx_s1 = 0, idx_s2 = 0, cnt = 0, t;
        bool flag = false;
        while (idx_s2 < s2.size()) {
            if (s1[idx_s1] == s2[idx_s2]) {
                cnt++;
                idx_s2++;
            }
            idx_s1++;
            if (idx_s1 == s1.size()) {
                idx_s1 = 0;
                flag = true;
                t = s2.size() - idx_s2;
            }
            if (flag && idx_s1 >= t) {
                break;
            }
        }
        return cnt == s1.size();
    }
};

int main() {
    cout << Solution().isFlipedString("aba", "bab") << endl;
	return 0;
}