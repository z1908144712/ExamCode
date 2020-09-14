#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    map<string, set<string>*> m;
    set<string> wordSet, failSet;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0 || wordDict.empty()) {
            return {};
        }
        /*int i = 0;
        while (i < wordDict.size()) {
            if (backtrace(wordDict[i], wordDict, "", 0, i)) {
                m.find(wordDict[i])->second->insert(wordDict[i]);
                wordDict.erase(wordDict.begin() + i);
                continue;
            }
            i++;
        }*/
        backtrace(s, wordDict, "", 0, -1);
        return vector<string>(wordSet.begin(), wordSet.end());
    }

    bool backtrace(string &s, vector<string>& wordDict, string parent, int pos, int exclude) {
        if (pos == s.length()) {
            if (exclude < 0) {
                wordSet.insert(parent);
            }
            return true;
        }
        bool has = false;
        for (map<string, set<string>*>::reverse_iterator i = m.rbegin(); i != m.rend(); i++) {
            string a = i->first;
            int len = i->first.length();
            if (len >= s.length() || pos + len > s.length()) {
                continue;
            }
            int p = pos + len;
            string d = s.substr(0, pos) + a;
            if (!failSet.count(d)) {
                if (s.compare(pos, len, a) == 0) {
                    set<string>* se = i->second;
                    for (set<string>::iterator it = se->begin(); it != se->end(); it++) {
                        string b = parent;
                        if (b.empty()) {
                            b = *it;
                        } else {
                            b += " " + *it;
                        }
                        set<string>* c;
                        if (m.count(d)) {
                            c = m.find(d)->second;
                            c->insert(b);
                        } else {
                            c = new set<string>();
                            c->insert(b);
                            m.insert(make_pair(d, c));
                        }
                        if (backtrace(s, wordDict, b, p, exclude) && !has) {
                            has = true;
                        }
                    }
                    if (!has) {
                        failSet.insert(d);
                    }
                } else {
                    if (!parent.empty()) {
                        failSet.insert(d);
                    }
                }
            }
        }
        for (int i = 0; i < wordDict.size(); i++) {
            if (exclude == i) {
                continue;
            }
            int len = wordDict[i].length();
            if (pos + len > s.length() || failSet.count(s.substr(0, pos + len))) {
                continue;
            }
            if (s.compare(pos, len, wordDict[i]) == 0) {
                string a = s.substr(0, pos + len);
                string b = parent;
                if (b.empty()) {
                    b = wordDict[i];
                } else {
                    b += " " + wordDict[i];
                }
                if (!parent.empty()) {
                    set<string>* c;
                    if (m.count(a)) {
                        c = m.find(a)->second;
                        c->insert(b);
                    } else {
                        c = new set<string>();
                        c->insert(b);
                        m.insert(make_pair(a, c));
                    }
                }
                if (backtrace(s, wordDict, b, pos + len, exclude) && !has) {
                    has = true;
                }
            }
        }
        if (!has) {
            failSet.insert(s.substr(0, pos));
        }
        return has;
    }

};

int main() {
    Solution sol;
    //string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //vector<string> wordDict = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    //string s = "aaaaaaa";
    //vector<string> wordDict = {"aaaa","aa","a"};
    string s = "pineapplepenapple";
    vector<string> wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
    vector<string> wordList = sol.wordBreak(s, wordDict);
    for (string str : wordList) {
        cout << "\"" << str << "\"" <<endl;
    }
    return 0;
}