#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                if (i - mp[nums[i]] <= k) {
                    return true;
                } else {
                    mp[nums[i]] = i;
                }
            } else {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,1,2,3 };
    int k = 2;
    cout << sol.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}