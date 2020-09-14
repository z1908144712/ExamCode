#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> st;
        int ma = 0, mi = 14;
        for (auto &num : nums) {
            if (num == 0) {
                continue;
            }
            if (st.count(num)) {
                return false;
            }
            ma = max(ma, num);
            mi = min(mi, num);
            st.insert(num);
        }
        return ma - mi < 5;
    }
};

int main() {
    vector<int> nums = { 0,0,1,2,5 };
    cout << Solution().isStraight(nums) << endl;
	return 0;
}