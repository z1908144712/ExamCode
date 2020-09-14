#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (right + 1 < nums.size() && nums[right] + 1 == nums[right + 1]) {
                right++;
                continue;
            } else {
                if (left == right) {
                    res.push_back(to_string(nums[left]));
                } else {
                    res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }
            }
            right++;
            left = right;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 0,2,3,4,6,8,9 };
    vector<string> r = sol.summaryRanges(nums);
    for (string &s : r) {
        cout << s << endl;
    }
    return 0;
}