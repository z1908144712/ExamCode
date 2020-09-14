#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Ä¦¶ûÍ¶Æ±·¨
        int votes = 0, x = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (votes == 0) {
                votes = 1;
                x = nums[i];
            } else {
                if (x == nums[i]) {
                    votes++;
                } else {
                    votes--;
                }
            }
        }
        return x;
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}