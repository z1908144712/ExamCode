#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int i : nums) {
            diff ^= i;
        }
        int _diff = diff, r = 0;
        diff &= -diff;
        for (int i : nums) {
            if ((diff & i) == 0) {
                r ^= i;
            }
        }
        return {r, r ^ _diff};
    }
};

int main() {
    vector<int> nums = { 1,2,4,1,4,3,2,5 };
    for (int i : Solution().singleNumber(nums)) {
        cout << i << " ";
    }
    return 0;
}