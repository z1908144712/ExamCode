#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> tmp;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            tmp[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = tmp[nums1[i]];
        }
        return res;
    }
};

int main() {
    vector<int> nums1{ 4,1,2}, nums2{ 1,3,4,2 };
    for (auto& num : Solution().nextGreaterElement(nums1, nums2)) {
        cout << num << " ";
    }
	return 0;
}