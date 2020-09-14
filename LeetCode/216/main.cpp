#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> r;
        for (int i = 1; i < 512; i++) {
            pair<int, int> p = countBit(i);
            if (p.first == k && p.second == n) {
                r.push_back(calcBits(i));
            }
        }
        return r;
    }

    pair<int, int> countBit(int value) {
        int r = 0, count = 0, sum = 0;
        while (value) {
            count++;
            if (value & 1) {
                sum += count;
                r++;
            }
            value >>= 1;
        }
        return {r, sum};
    }

    vector<int> calcBits(int value) {
        vector<int> r;
        for (int i = 0; i < 9; i++) {
            if ((value >> i) & 1) {
                r.push_back(i + 1);
            }
        }
        return r;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> r = sol.combinationSum3(3, 9);
    for (vector<int> i : r) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}