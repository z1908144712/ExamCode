#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> subs1 = split(version1);
        vector<string> subs2 = split(version2);
        int len = subs1.size() > subs2.size() ? subs1.size() : subs2.size();
        for (int i = 0; i < len; i++) {
            int a, b;
            if (i < subs1.size()) {
                a = stoi(subs1[i]);
            } else {
                a = 0;
            }
            if (i < subs2.size()) {
                b = stoi(subs2[i]);
            } else {
                b = 0;
            }
            if (a > b) {
                return 1;
            }
            if (a < b) {
                return -1;
            }
        }
        return 0;
    }

    vector<string> split(string s) {
        vector<string> subs;
        if (s.empty()) {
            return subs;
        }
        stringstream ss(s);
        string tmp;
        while (getline(ss, tmp, '.')) {
            subs.push_back(tmp);
        }
        return subs;
    }
};

int main() {
    Solution sol;
    string version1 = "1.01";
    string version2 = "1.0000.0";
    cout << sol.compareVersion(version1, version2) << endl;
    return 0;
}