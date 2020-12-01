#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                dup = idx + 1;
            } else {
                nums[idx] *= -1;
            }
        }
        int missing = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }
        return {dup, missing};
    }
};

int main() {
    vector<int> nums{ 1,2,2,4 };
    for (auto&r : Solution().findErrorNums(nums)) {
        cout << r << " ";
    }
	return 0;
}