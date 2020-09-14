#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, vector<int>*> ms, mt;
        vector<char> vcs, vct;
        for (int i = 0; i < s.size(); i++) {
            vector<int>* sv;
            if (ms.count(s[i])) {
                sv = ms[s[i]];
            } else {
                sv = new vector<int>();
                ms[s[i]] = sv;
                vcs.push_back(s[i]);
            }
            sv->push_back(i);
        }
        for (int i = 0; i < t.size(); i++) {
            vector<int>* tv;
            if (mt.count(t[i])) {
                tv = mt[t[i]];
            } else {
                tv = new vector<int>();
                mt[t[i]] = tv;
                vct.push_back(t[i]);
            }
            tv->push_back(i);
        }
        if (ms.size() != mt.size()) {
            return false;
        }
        for (int i = 0; i < vcs.size(); i++) {
            if (*ms[vcs[i]] != *mt[vct[i]]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "a";
    string t = "a";
    cout << sol.isIsomorphic(s, t) << endl;
    return 0;
}