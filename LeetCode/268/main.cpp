#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int r = 0, i;
        for (i = 0; i < nums.size(); i++) {
            r ^= i ^ nums[i];
        }
        return r ^ i;
    }
};

int main() {
    vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}