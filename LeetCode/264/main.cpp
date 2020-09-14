#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n);
        nums[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0, factor2, factor3, factor5, m;
        for (int i = 1; i < n; i++) {
            factor2 = 2 * nums[index2];
            factor3 = 3 * nums[index3];
            factor5 = 5 * nums[index5];
            m = min(min(factor2, factor3), factor5);
            nums[i] = m;
            if (m == factor2) {
                index2++;
            }
            if (m == factor3) {
                index3++;
            }
            if (m == factor5) {
                index5++;
            }
        }
        return nums[n - 1];
    }
};

int main() {
    cout << Solution().nthUglyNumber(10) << endl;
}