#include <iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int r = 0;
        for (int i = 2; i <= n; i++) {
            r = (r + m) % i;
        }
        return r;
    }
};

int main() {
    cout << Solution().lastRemaining(10, 17) << endl;
	return 0;
}