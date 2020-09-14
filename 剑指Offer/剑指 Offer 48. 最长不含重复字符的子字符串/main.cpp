#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCnt = 0;
        map<char, int> mp;
        int i = -1;
        for (int j = 0; j < s.size(); j++) {
            if (mp.count(s[j])) {
                i = mp[s[j]];
            } else {
                mp[s[j]] = j;
            }
            if (maxCnt < j - i) {
                maxCnt = j - i;
            }
        }
        return maxCnt;
    }
};

int main() {
    string s = " ";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}