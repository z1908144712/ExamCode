#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> nums;
        if (n <= 0) {
            return nums;
        }
        for (int i = 1; i < static_cast<int>(pow(10, n)); i++) {
            nums.push_back(i);
        }
        return nums;
    }
};

int main() {
    vector<int> r = Solution().printNumbers(4);
    for (auto & i : r) {
        cout << i << " ";
    }
    return 0;
}