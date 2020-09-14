#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target) {
                if (backtrace(matrix[i], target, 0, matrix[i].size() - 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrace(vector<int>& matrix, int target, int begin, int end) {
        int middle = (begin + end) / 2;
        if (matrix[middle] > target) {
            if (middle - 1 >= begin && backtrace(matrix, target, begin, middle - 1)) {
                return true;
            }
        } else if (matrix[middle] < target) {
            if (middle + 1 <= end && backtrace(matrix, target, middle + 1, end)) {
                return true;
            }
        } else {
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
  {1,   4,  7, 11, 15} ,
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
    };
    int target = 20;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}