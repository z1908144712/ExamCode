#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        /*for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target) {
                if (findOn2(matrix, i, target)) {
                    return true;
                }
            }
        }*/
        return false;
    }

    bool findOn2(vector<vector<int>>& matrix, int i, int target) {
        int begin = 0, end = matrix[i].size() - 1, medd;
        while (begin <= end) {
            medd = begin + (end - begin) / 2;
            if (matrix[i][medd] == target) {
                return true;
            } else if (matrix[i][medd] > target) {
                end = medd - 1;
            } else {
                begin = medd + 1;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 30;
    cout << Solution().findNumberIn2DArray(matrix, target) << endl;
    return 0;
}