#include <iostream>

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        uint32_t t = num;
        int pre = 0, cur = 0, k = 0, maxx = 0;
        while (t) {
            if (t & 1) {
                cur++;
            } else {
                maxx = max(maxx, pre + cur + 1);
                pre = cur;
                cur = 0;
            }
            t >>= 1;
        }
        maxx = cur == 32 ? cur : max(maxx, pre + cur + 1);
        return maxx;
    }
};

int main() {
    cout << Solution().reverseBits(-2) << endl;
	return 0;
}