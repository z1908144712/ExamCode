#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        long num = -1, e = 1;
        for (int i = input.size() - 1; i >= 0; i--) {
            if (input[i] >= '0' && input[i] <= '9') {
                if (num == -1) {
                    num = input[i] - '0';
                } else {
                    num += (input[i] - '0') * e;
                }
                e *= 10;
            } else {
                if (num != -1) {
                    nums.push_back(num);
                    num = -1;
                    e = 1;
                }
                ops.push_back(input[i]);
            }
        }
        if (num != -1) {
            nums.push_back(num);
        }
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>()));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i].push_back(nums[i]);
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                int s = j + i;
                if (s >= nums.size()) {
                    break;
                }
                vector<int> res;
                for (int k = j; k < s; k++) {
                    vector<int> res_right = dp[j][k];
                    vector<int> res_left = dp[k + 1][s];
                    for (int m = 0; m < res_left.size(); m++) {
                        for (int n = 0; n < res_right.size(); n++) {
                            if (ops[k] == '+') {
                                dp[j][s].push_back(res_left[m] + res_right[n]);
                            }
                            if (ops[k] == '-') {
                                dp[j][s].push_back(res_left[m] - res_right[n]);
                            }
                            if (ops[k] == '*') {
                                dp[j][s].push_back(res_left[m] * res_right[n]);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][nums.size() - 1];
        //return backtrace(nums, ops);
    }

    /*vector<int> backtrace(vector<int> &nums, vector<char> &ops) {
        vector<int> res;
        if (ops.size() == 0) {
            res.push_back(nums.back());
            return res;
        }
        for (int i = 0; i < ops.size(); i++) {
            vector<int> nums_right = vector<int>(nums.begin(), nums.begin() + i + 1);
            vector<int> nums_left = vector<int>(nums.begin() + i + 1, nums.end());
            vector<char> ops_right = vector<char>(ops.begin(), ops.begin() + i);
            vector<char> ops_left = vector<char>(ops.begin() + i + 1, ops.end());
            vector<int> res_left = backtrace(nums_left, ops_left);
            vector<int> res_right = backtrace(nums_right, ops_right);
            for (int j = 0; j < res_left.size(); j++) {
                for (int k = 0; k < res_right.size(); k++) {
                    if (ops[i] == '+') {
                        res.push_back(res_left[j] + res_right[k]);
                    }
                    if (ops[i] == '-') {
                        res.push_back(res_left[j] - res_right[k]);
                    }
                    if (ops[i] == '*') {
                        res.push_back(res_left[j] * res_right[k]);
                    }
                }
            }
        }
        return res;
    }*/
};

int main() {
    string input = "2*3-4*5";
    vector<int> res = Solution().diffWaysToCompute(input);
    for (auto &r : res) {
        cout << r << " ";
    }
    return 0;
}