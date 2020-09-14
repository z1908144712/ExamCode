#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*int r = 0;
        if (matrix.size() == 0) {
            return r;
        }
        vector<__int128> nums(matrix.size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                nums[i] += (__int128)(matrix[i][j] - '0') << (matrix[i].size() - j - 1);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            __int128 sum = INT_MIN;
            for (int j = i; j < nums.size(); j++) {
                if (j == i) {
                    sum = nums[j];
                } else {
                    sum &= nums[j];
                }
                int64_t t = sum;
                int c = 0, maxc = 0;
                while (t) {
                    if (t&1) {
                        c++;
                        maxc = max(c, maxc);
                    } else {
                        c = 0;
                    }
                    t >>= 1;
                }
                int s = min(maxc, j - i + 1);
                r = max(s*s, r);
            }
        }
        return r;*/
        if (matrix.size() == 0) {
            return 0;
        }
        int r = 0;
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[i - 1].size(); j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                } else {
                    dp[i][j] = 0;
                }
                r = max(r, dp[i][j]);
            }
        }
        return r * r;
    }
};

int main() {
    Solution sol;
    /*vector<vector<char>> matrix = { 
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };*/
    //vector<vector<char>> matrix = { {'1'} };
    /*vector<vector<char>> matrix = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}
    };*/
    vector<vector<char>> matrix = {{'1','0','1','1','0','1'},{'1','1','1','1','1','1'},{'0','1','1','0','1','1'},{'1','1','1','0','1','0'},{'0','1','1','1','1','1'},{'1','1','0','1','1','1'}};
    cout << sol.maximalSquare(matrix) << endl;
    return 0;
}