#include <iostream>

using namespace std;

class Solution {
public:
    int multiply(int A, int B) {
        if (B == 1) {
            return A;
        }
        if (A < B) {
            return multiply(B, A);
        }
        if (B & 1) {
            return A + multiply(A, B - 1);
        } else {
            return multiply(A, B >> 1) << 1;
        }
    }
};

int main() {
    cout << Solution().multiply(5, 5) << endl;
	return 0;
}