#include <iostream>

using namespace std;

class Solution {
public:
    int convertInteger(int A, int B) {
        uint32_t s = A ^ B;
        int cnt = 0;
        while (s) {
            if (s & 1) {
                cnt++;
            }
            s >>= 1;
        }
        return cnt;
    }
};

int main() {
    cout << Solution().convertInteger(826966453, -729934991) << endl;
	return 0;
}