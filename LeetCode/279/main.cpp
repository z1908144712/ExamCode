#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int minCount = INT_MAX;
        int e = (int)sqrt(n);
        for (int i = e; i >= 1; i--) {
            int k = i * i;
            if (n % k == 0) {
                minCount = min(minCount, n / k);
                break;
            } else {
                minCount = min(minCount, n / k + numSquares(n % k));
            }
        }
        return minCount;
    }

};

int main() {
    cout << Solution().numSquares(12) << endl;
    return 0;
}