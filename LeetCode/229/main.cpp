#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        int cand1 = nums[0], cand2 = nums[0], count1 = 0, count2 = 0;
        for (auto &num : nums) {
            if (cand1 == num) {
                count1++;
                continue;
            }
            if (cand2 == num) {
                count2++;
                continue;
            }
            if (count1 == 0) {
                cand1 = num;
                count1 = 1;
                continue;
            }
            if (count2 == 0) {
                cand2 = num;
                count2 = 1;
                continue;
            }
            count1--;
            count2--;
        }
        count1 = count2 = 0;
        for (auto &num : nums) {
            if (cand1 == num) {
                count1++;
            }
            if (cand1 != cand2 && cand2 == num) {
                count2++;
            }
        }
        if (count1 > nums.size() / 3) {
            res.push_back(cand1);
        }
        if (cand1 != cand2 && count2 > nums.size() / 3) {
            res.push_back(cand2);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,1,1,3,3,2,2,2 };
    vector<int> r = sol.majorityElement(nums);
    for (auto &num : r) {
        cout << num << " ";
    }
    return 0;
}