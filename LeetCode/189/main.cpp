#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2) {
            return;
        }
        k = k % len;
        for (int i = 0; i < len - k; i++) {
            nums.push_back(*nums.begin());
            nums.erase(nums.begin());
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,4,5,6,7 };
    int k = 7;
    sol.rotate(nums, k);
    for (int n : nums) {
        cout << n << " ";
    }
    return 0;
}