#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int flag = 0;
        while (flag < nums.size()) {
            if (flag == nums[flag]) {
                return flag;
            } else if (flag < nums[flag]) {
                flag = nums[flag];
            } else if (flag > nums[flag]) {
                flag++;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums{ 0, 0, 2 };
    cout << Solution().findMagicIndex(nums) << endl;
	return 0;
}