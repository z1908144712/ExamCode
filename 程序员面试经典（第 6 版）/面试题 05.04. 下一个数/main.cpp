#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        bitset<32> small(num);
        bitset<32> big(num);
        int s = -1;
        int b = -1;
        for (int i = 1; i < 32; i++) {
            if (small[i] == 1 && small[i - 1] == 0) {
                small.flip(i);
                small.flip(i - 1);
                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && small[left] == 0) {
                        left++;
                    }
                    while (left < right && small[right] == 1) {
                        right--;
                    }
                    small.flip(left);
                    small.flip(right);
                }
                s = small.to_ulong();
                break;
            }
        }

        for (int i = 1; i < 32; i++) {
            if (big[i] == 0 && big[i - 1] == 1) {
                big.flip(i);
                big.flip(i - 1);
                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && big[left] == 1) {
                        left++;
                    }
                    while (left < right && big[right] == 0) {
                        right--;
                    }
                    big.flip(left);
                    big.flip(right);
                }
                b = big.to_ulong();
                break;
            }
        }
        return {b, s};
    }
};

int main() {
    for (auto &i : Solution().findClosedNumbers(2)) {
        cout << i << " ";
    }
	return 0;
}