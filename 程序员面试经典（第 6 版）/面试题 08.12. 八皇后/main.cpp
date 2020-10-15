#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> nums(n, -1);
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int n) {
        if (n == nums.size()) {
            res.push_back(helper(nums));
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[n] = i;
            if (check(nums, n)) {
                dfs(nums, n + 1);
            }
            nums[n] = -1;
        }
    }

    vector<string> helper(vector<int>& nums) {
        vector<string> r;
        for (auto &num : nums) {
            string s;
            for (int i = 0; i < nums.size(); i++) {
                if (i == num) {
                    s.push_back('Q');
                } else {
                    s.push_back('.');
                }
            }
            r.push_back(s);
        }
        return r;
    }

    bool check(vector<int>& nums, int& n) {
        for (int i = 1; i <= n; i++) {
            if (nums[n] == nums[n - i]) {
                return false;
            }
            if (nums[n] - i >= 0 && nums[n - i] == nums[n] - i) {
                return false;
            }
            if (nums[n] + i < nums.size() && nums[n - i] == nums[n] + i) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    for(auto &row : Solution().solveNQueens(8)) {
        for (auto &col : row) {
            cout << col << endl;
        }
        cout << endl;
    }
    
	return 0;
}