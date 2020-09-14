#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
        int n = 1;
        for (int num : numSet) {
            if (numSet.count(num - 1) != 0)
                continue;
            int len = 1;
            while (numSet.count(num + 1) != 0) {
                num++;
                len++;
            }
            n = n >= len ? n : len;
        }
        return n;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}