#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums.size();*/
        //¶þ·Ö
        int l = 0,r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    vector<int> nums = { 0,1,2,3,4,5,6,7,8,10 };
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}