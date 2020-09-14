#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid, cnt = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                cnt++;
                int i = mid - 1;
                while (i >= l) {
                    if (nums[i--] == target) {
                        cnt++;
                    } else {
                        break;
                    }
                }
                i = mid + 1;
                while (i <= r) {
                    if (nums[i++] == target) {
                        cnt++;
                    } else {
                        break;
                    }
                }
                break;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> nums = { 5,7,7,8,8,10 };
    int target = 0;
    cout << Solution().search(nums, target) << endl;
    return 0;
}