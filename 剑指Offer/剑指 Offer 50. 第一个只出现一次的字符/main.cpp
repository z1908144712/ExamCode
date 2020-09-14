#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> vt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            vt[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (vt[s[i] - 'a'] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};

int main() {
    string s = "abaccdeff";
    cout << Solution().firstUniqChar(s) << endl;
    return 0;
}