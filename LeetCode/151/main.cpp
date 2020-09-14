#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        trim(s);
        if (s.empty()) {
            return s;
        }
        vector<string> strs = split(s);
        string rs = "";
        for (int i = strs.size() - 1; i >= 0; i--) {
            if (!rs.empty()) {
                rs += " ";
            }
            rs += strs[i];
        }
        return rs;
    }

    vector<string> split(string &s) {
        if (s.empty()) {
            return {};
        }
        vector<string> strs;
        stringstream ss(s);
        string sub;
        while (getline(ss, sub, ' ')) {
            trim(sub);
            if (!sub.empty()) {
                strs.push_back(sub);
            }
        }
        return strs;
    }

    void trim(string &s) {
        if (s.empty()) {
            return;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
};

int main() {
    Solution sol;
    //string s = "  hello world!  ";
    //string s = "a good   example";
    string s = "the sky is blue";
    cout << sol.reverseWords(s) << endl;
    return 0;
}