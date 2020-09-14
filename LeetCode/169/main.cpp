#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int r;
        for (int i = 0; i < nums.size(); i++) {
            r = nums[i];
            if (m.count(r)) {
                m[r]++;
                if (m[r] > nums.size() / 2) {
                    break;
                }
            } else {
                m[r] = 1;
            }
        }
        return r;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1 };
    cout << sol.majorityElement(nums) << endl;
    return 0;
}