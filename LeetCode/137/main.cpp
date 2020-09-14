#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for (int i = 0; i < nums.size(); i++) {
            seen_once = ~seen_twice & (seen_once ^ nums[i]);
            seen_twice = ~seen_once & (seen_twice ^ nums[i]);
        }
        return seen_once;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2, 2,  3, 2 };
    cout << sol.singleNumber(nums) << endl;
    return 0;
}