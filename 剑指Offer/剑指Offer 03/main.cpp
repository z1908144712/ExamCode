#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        /*set<int> sets;
        for (int i = 0; i < n; i++) {
            if (sets.count(nums[i])) {
                return nums[i];
            }
            sets.insert(nums[i]);
        }*/
        for (int i = 0; i < n; i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = { 2, 3, 1, 0, 2, 5, 3};
    cout << Solution().findRepeatNumber(nums) << endl;
    return 0;
}