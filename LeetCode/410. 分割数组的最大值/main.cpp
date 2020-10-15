#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        while (lo < hi) {
            int mid = (hi + lo) / 2;
            if (split(nums, mid) <= m) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    int split(vector<int>& nums, int max) {
        int cnt = 1, sum = 0;
        for (auto& num : nums) {
            if (sum + num > max) {
                cnt++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> nums{ 7,2,5,10,8 };
    int m = 2;
    cout << Solution().splitArray(nums, m) << endl;
	return 0;
}