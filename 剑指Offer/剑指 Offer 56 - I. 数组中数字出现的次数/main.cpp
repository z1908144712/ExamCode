#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int r = 0, a = 0;
        for (int &n : nums) {
            r ^= n;
        }
        int div = 1;
        while ((div & r) == 0) {
            div <<= 1;
        }
        for (int &n : nums) {
            if (div & n) {
                a ^= n;
            }
        }
        return {a, a^r};
    }
};

int main() {
    vector<int> nums = { 1,2,10,4,1,4,3,3 };
    vector<int> r = Solution().singleNumbers(nums);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}