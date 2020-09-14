#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for (int i : nums) {
            if (st.count(i)) {
                return true;
            }
            st.insert(i);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
    cout << sol.containsDuplicate(nums) << endl;
    return 0;
}