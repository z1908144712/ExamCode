#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<long> nums;
        vector<char> ops;
        long num = -1, e = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                if (num == -1) {
                    num = s[i] - '0';
                } else {
                    num += (s[i] - '0') * e;
                }
                e *= 10;
            } else {
                if (num != -1) {
                    nums.push_back(num);
                    num = -1;
                    e = 1;
                }
                ops.push_back(s[i]);
            }
        }
        if (num != -1) {
            nums.push_back(num);
        }
        for (int i = ops.size() - 1; i >= 0; i--) {
            if (ops[i] == '*' || ops[i] == '/') {
                long a = nums[i + 1], b = nums[i];
                if (ops[i] == '*') {
                    nums[i] = a * b;
                }
                if (ops[i] == '/') {
                    nums[i] = a / b;
                }
                nums.erase(nums.begin() + i + 1);
                ops.erase(ops.begin() + i);
            }
        }
        while (!ops.empty()) {
            int a = nums.back();
            nums.pop_back();
            int b = nums.back();
            nums.pop_back();
            if (ops.back() == '+') {
                nums.push_back(a + b);
            }
            if (ops.back() == '-') {
                nums.push_back(a - b);
            }
            ops.pop_back();
        }
        return nums.back();
    }
};

int main() {
    Solution sol;
    string s = " 3+2*2";
    cout << sol.calculate(s) << endl;
    return 0;
}