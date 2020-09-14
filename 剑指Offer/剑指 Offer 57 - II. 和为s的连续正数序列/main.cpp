#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> r;
        int L = 1, R = 1, sum = 0;
        while (L <= (target >> 1)) {
            if (sum == target) {
                vector<int> v;
                for (int i = L; i < R; i++) {
                    v.push_back(i);
                }
                r.push_back(v);
                sum -= L;
                L++;
            } else if (sum < target) {
                sum += R;
                R++;
            } else {
                sum -= L;
                L++;
            }
        }
        return r;
    }
};

int main() {
    vector<vector<int>> r = Solution().findContinuousSequence(100);
    for (auto &rv : r) {
        for (auto &rt : rv) {
            cout << rt << " ";
        }
        cout << endl;
    }
    return 0;
}