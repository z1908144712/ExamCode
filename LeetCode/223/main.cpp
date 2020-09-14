#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A == E && B == F && C == G && D == H) {
            return ((long)C - A) * (D - B);
        }
        long l = (long)min(G, C) - max(A, E);
        long m = (long)min(H, D) - max(B, F);
        if (l < 0 || m < 0) {
            return ((long)C - A) * (D - B) + (G - E) * (H - F);
        }
        return ((long)C - A) * (D - B) + (G - E) * (H - F) - l * m;
    }
};

int main() {
    Solution sol;
    cout << sol.computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000) << endl;
    return 0;
}