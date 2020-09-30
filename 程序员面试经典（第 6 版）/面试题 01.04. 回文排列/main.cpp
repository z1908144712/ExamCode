#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> bits;
        for (auto &i : s) {
            bits.flip(i);
        }
        return bits.none() || bits.count() == 1;
    }
};

int main() {
    cout << Solution().canPermutePalindrome("abdg") << endl;
	return 0;
}