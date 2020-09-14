#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) {
            return {};
        }
        vector<int> r;
        deque<int> d;
        for (int i = 0; i < k; i++) {
            while (!d.empty() && d.back() < nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
        }
        r.push_back(d.front());
        for (int i = k; i < nums.size(); i++) {
            if (!d.empty() && d.front() == nums[i - k]) {
                d.pop_front();
            }
            while (!d.empty() && d.back() < nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
            r.push_back(d.front());
        }
        return r;
    }
};

int main() {
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    vector<int> r = Solution().maxSlidingWindow(nums, k);
    for (auto &i : r) {
        cout << i << " ";
    }
	return 0;
}