#include <iostream>

using namespace std;


class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        long left = (long)N & ((1 << i) - 1);
        long right = (long)N >> (j + 1);
        return ((right << (j + 1)) | (M << i) | left);
    }
};

int main() {
    cout << Solution().insertBits(1024,19,2,6) << endl;
	return 0;
}