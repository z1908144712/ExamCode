#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int exchangeBits(int num) {
        bitset<32> n(num);
        for (int i = 1; i < 32; i += 2) {
            if (n[i - 1] != n[i]) {
                n.flip(i - 1);
                n.flip(i);
            }
        }
        return n.to_ulong();
    }
};

int main() {
    cout << Solution().exchangeBits(3) << endl;
	return 0;
}