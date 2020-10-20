#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = n * 2 - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;
    }
};

int main() {
    vector<int> nums{ 1,2,1 };
    for (auto& num : Solution().nextGreaterElements(nums)) {
        cout << num << " ";
    }
	return 0;
}