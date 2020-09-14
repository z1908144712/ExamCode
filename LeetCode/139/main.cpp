#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<string> se;
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0 || wordDict.empty()) {
            return false;
        }
        int i = 0;
        while (i < wordDict.size()) {
            if (backtrace(wordDict[i], wordDict, 0, i)) {
                wordDict.erase(wordDict.begin() + i);
                continue;
            }
            i++;
        }
        return backtrace(s, wordDict, 0, -1);
    }

    bool backtrace(string s, vector<string>& wordDict, int pos, int exclude) {
        int max = 0;
        for (int i = 1; i <= s.length() - pos; i++) {
            if (se.count(s.substr(pos, i))) {
                if (max < i) {
                    max = i;
                }
            }
        }
        pos += max;
        if (pos == s.length()) {
            return true;
        }
        for (int i = 0; i < wordDict.size(); i++) {
            if (exclude == i) {
                continue;
            }
            int len = wordDict[i].length();
            if (s.compare(pos, len, wordDict[i]) == 0) {
                if (exclude < 0) {
                    se.insert(s.substr(0, pos + len));
                    cout << s.substr(0, pos + len) << endl;
                }  
                //cout << wordDict[i] << endl;
                if (backtrace(s, wordDict, pos + len, exclude)) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main() {
    Solution sol;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> wordDict = { "aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba" };
    cout << sol.wordBreak(s, wordDict) << endl;
    return 0;
}