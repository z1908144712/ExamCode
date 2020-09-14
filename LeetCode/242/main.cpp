#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i])) {
                mp[s[i]]++;
            } else {
                mp[s[i]] = 1;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (mp.count(t[i])) {
                mp[t[i]]--;
                if (mp[t[i]] == 0) {
                    mp.erase(t[i]);
                }
            } else {
                return false;
            }
        }
        return mp.empty();
    }
};

int main() {
    string s = "";
    string t = "";
    cout << Solution().isAnagram(s, t) << endl;
    return 0;
}