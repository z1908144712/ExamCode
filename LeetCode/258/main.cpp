#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main() {
    int num = 38;
    cout << Solution().addDigits(num) << endl;
    return 0;
}