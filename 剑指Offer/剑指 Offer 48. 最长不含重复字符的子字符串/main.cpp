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
                i = max(mp[s[j]], i);
            }
            mp[s[j]] = j;
            maxCnt = max(maxCnt,  j - i);
        }
        return maxCnt;
    }
};

int main() {
    string s = "baab";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}