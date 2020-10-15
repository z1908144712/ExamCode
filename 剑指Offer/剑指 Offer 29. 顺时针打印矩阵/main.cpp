#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return res;
        }
        int l = 0, r = n - 1, t = 0, b = m - 1;
        while (true) {
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[t][i]);
            }
            if (++t > b) {
                break;
            }
            for (int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }
            for (int i = r; i >= l; i--) {
                res.push_back(matrix[b][i]);
            }
            if (--b < t) {
                break;
            }
            for (int i = b; i >= t; i--) {
                res.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = { {1,2,3,4} ,{5,6,7,8},{9,10,11,12} };
    vector<int> r = Solution().spiralOrder(matrix);
    for (auto& i : r) {
        cout << i << " ";
    }
    return 0;
}