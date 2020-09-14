#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int &n : nums) {
            ones = ones ^ n & ~twos;
            twos = twos ^ n & ~ones;
        }
        return ones;
    }
};

int main() {
    vector<int> nums = { 9,1,7,9,7,9,7 };
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}