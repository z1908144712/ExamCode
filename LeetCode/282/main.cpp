#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> addOperators(string num, int target) {
        string path = "";
        addOperatorsHepler(num, target, path, 0, 0, 0);
        return res;
    }

    void addOperatorsHepler(string &num, int &target, string &path, int start, long eval, long pre) {
        if (start == num.size()) {
            if (eval == target) {
                res.push_back(path);
            }
            return;
        }
        int len = path.size();
        for (int i = 0; i < num.size() - start; i++) {
            if (num[start] == '0' && i > 0) {
                return;
            }
            string cur_str = num.substr(start, i + 1);
            long cur = atol(cur_str.c_str());
            if (start == 0) {
                path = cur_str;
                addOperatorsHepler(num, target, path, start + i + 1, cur, cur);
                path.resize(len);
            } else {
                path += "+" + cur_str;
                addOperatorsHepler(num, target, path, start + i + 1, eval + cur, cur);
                path.resize(len);
                path += "-" + cur_str;
                addOperatorsHepler(num, target, path, start + i + 1, eval - cur, -cur);
                path.resize(len);
                path += "*" + cur_str;
                addOperatorsHepler(num, target, path, start + i + 1, eval - pre + pre * cur, pre * cur);
                path.resize(len);
            }
        }
    }
};

int main() {
    string num = "2147483648";
    int target = -2147483648;
    vector<string> res = Solution().addOperators(num, target);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}