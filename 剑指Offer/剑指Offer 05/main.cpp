#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        stringstream ss(s);
        vector<string> strs;
        string str;
        while (getline(ss, str, ' ')) {
            strs.push_back(str);
        }
        str = "";
        for (int i = 0; i < strs.size(); i++) {
            str += strs[i];
            if (i == strs.size() - 1 && s[s.size() - 1] != ' ') {
                continue;
            }
            str += "%20";
        }
        return str;
    }
};

int main() {
    string s = "    We a re  happy.  ";
    cout << Solution().replaceSpace(s) << endl;
    return 0;
}