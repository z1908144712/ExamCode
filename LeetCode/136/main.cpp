#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i])) {
                it = m.find(nums[i]);
                it->second++;
                if (it->second == 2) {
                    m.erase(it);
                }
            } else {
                m.insert(make_pair(nums[i], 1));
            }
        }
        return m.begin()->first;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 4,1,2,1,2 };
    cout << sol.singleNumber(nums) << endl;
	return 0;
}