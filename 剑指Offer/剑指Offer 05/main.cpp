#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // stringstream ss(s);
        // vector<string> strs;
        // string str;
        // while (getline(ss, str, ' ')) {
        //     strs.push_back(str);
        // }
        // str = "";
        // for (int i = 0; i < strs.size(); i++) {
        //     str += strs[i];
        //     if (i == strs.size() - 1 && s[s.size() - 1] != ' ') {
        //         continue;
        //     }
        //     str += "%20";
        // }
        // return str;
        int cnt = 0, len = s.size();
        for (auto& c : s) {
            if (c == ' ') {
                cnt++;
            }
        }
        s.resize(len + 2 * cnt);
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            } else {
                s[j] = s[i];
            }
        }
        return s;
    }
};

int main() {
    string s = "    We a re  happy.  ";
    cout << Solution().replaceSpace(s) << endl;
    return 0;
}