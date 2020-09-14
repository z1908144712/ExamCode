#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int c = 0;
        vector<vector<bool>> tp(m, vector<bool>(n, false));
        walk(0, 0, k, tp, c);
        return c;
    }

    void walk(int i, int j, int& k, vector<vector<bool>> &tp, int &c) {
        if (i < tp.size() && j < tp[0].size() && !tp[i][j] && movingCountHelper(i) + movingCountHelper(j) <= k) {
            c++;
            tp[i][j] = true;
            walk(i + 1, j, k, tp, c);
            walk(i - 1, j, k, tp, c);
            walk(i, j + 1, k, tp, c);
            walk(i, j - 1, k, tp, c);
        }
    }

    int movingCountHelper(int n) {
        int c = 0;
        while (n) {
            c += n % 10;
            n /= 10;
        }
        return c;
    }
};

int main() {
    cout << Solution().movingCount(100, 100, 20) << endl;
    return 0;
}