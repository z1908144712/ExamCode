#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        stringstream ss(str);
        string s;
        while (getline(ss, s, ' ')) {
            strs.push_back(s);
        }
        if (pattern.size() == strs.size()) {
            map<char, set<int>> pattern_m;
            map<string, set<int>> str_m;
            for (int i = 0; i < pattern.size(); i++) {
                if (pattern_m.count(pattern[i])) {
                    pattern_m[pattern[i]].insert(i);
                } else {
                    pattern_m[pattern[i]] = {i};
                }
                if (str_m.count(strs[i])) {
                    str_m[strs[i]].insert(i);
                } else {
                    str_m[strs[i]] = { i };
                }
            }
            if (pattern_m.size() == str_m.size()) {
                int count = 0;
                for (auto pattern_it : pattern_m) {
                    for (auto str_it : str_m) {
                        if (pattern_it.second == str_it.second) {
                            count++;
                            break;
                        }
                    }
                }
                return count == pattern_m.size();
            }
            return false;
        }
        return false;
    }
};

int main() {
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << Solution().wordPattern(pattern, str) << endl;
    return 0;
}