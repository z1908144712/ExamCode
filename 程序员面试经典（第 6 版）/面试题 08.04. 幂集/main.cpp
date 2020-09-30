#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtrace(vector<int>& nums, vector<int>& trace, int i) {
        if (i > nums.size()) {
            return;
        }
        res.push_back(trace);
        for (int k = i; k < nums.size(); k++) {
            trace.push_back(nums[k]);
            backtrace(nums, trace, k + 1);
            trace.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> trace;
        backtrace(nums, trace, 0);
        return res;
    }
};

int main() {
    vector<int> nums{ 1,2,3 };
    for (auto &num : Solution().subsets(nums)) {
        for (auto & n : num) {
            cout << n << " ";
        }
        cout << endl;
    }
	return 0;
}