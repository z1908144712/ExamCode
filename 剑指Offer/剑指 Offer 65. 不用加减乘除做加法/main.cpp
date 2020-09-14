#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int c = (unsigned int)(a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};

int main() {
    cout << Solution().add(1, 2) << endl;
	return 0;
}