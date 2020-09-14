#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int gap = 0;
        for (int i = 0; i < nums.size(); i++) {
            int min = nums[i], minIndex = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (min > nums[j]) {
                    min = nums[j];
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                int tmp = nums[i];
                nums[i] = nums[minIndex];
                nums[minIndex] = tmp;
            }
            if (i > 0) {
                int _gap = nums[i] - nums[i - 1];
                gap = gap < _gap ? _gap : gap;
            }
        }
        return gap;
    }
};

int main() {
    Solution sol;
    //vector<int> nums = { 3,6,9,1 };
    vector<int> nums = {1, 10000000};
    cout << sol.maximumGap(nums) << endl;
    return 0;
}