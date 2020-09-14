#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) {
            return 0;
        }
        vector<char> ops;
        vector<int> nums;
        long num = -1, e = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                continue;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                if (num == -1) {
                    num = (s[i] - '0');
                } else {
                    num += (s[i] - '0') * e;
                }
                e *= 10;
                continue;
            } else if (num != -1) {
                nums.push_back(num);
                num = -1;
                e = 1;
            }
            if (s[i] == '(') {
                for (int i = ops.size() - 1; ops[i] != ')'; i--) {
                    int a, b;
                    a = nums.back();
                    nums.pop_back();
                    b = nums.back();
                    nums.pop_back();
                    if (ops[i] == '+') {
                        nums.push_back(a + b);
                    }
                    if (ops[i] == '-') {
                        nums.push_back(a - b);
                    }
                    ops.pop_back();
                }
                ops.pop_back();
            } else {
                ops.push_back(s[i]);
            }
        }
        if (num != -1) {
            nums.push_back(num);
        }
        for (int i = ops.size() - 1; i >= 0; i--) {
            int a, b;
            a = nums.back();
            nums.pop_back();
            b = nums.back();
            nums.pop_back();
            if (ops[i] == '+') {
                nums.push_back(a + b);
            }
            if (ops[i] == '-') {
                nums.push_back(a - b);
            }
            ops.pop_back();
        }
        return nums.back();
    }
};

int main() {
    Solution sol;
    string s = "2147483647";
    //string s = " 2-1 + 2 ";
    //string s = "1 + 1";
    //string s = "(1+(4+5+2)-3)+(6+8)";
    cout << sol.calculate(s) << endl;
    return 0;
}