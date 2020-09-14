#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        for (int i = 0; i < size; i++) {
            if (gas[i] < cost[i]) {
                continue;
            }
            int last = 0;
            bool flag = true, state = true;
            for (int j = i; state || j != i ; j = (j+1) % size) {
                if (state) {
                    state = false;
                }
                last += gas[j] - cost[j];
                if (last < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> gas = { 1, 2,3,4,5};
    vector<int> cost = { 3,4,5, 1,2 };
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}