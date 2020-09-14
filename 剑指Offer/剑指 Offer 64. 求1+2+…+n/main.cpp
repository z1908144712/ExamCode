#include <iostream>

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        n > 1 && (n += sumNums(n - 1));
        return n;
    }
};

int main() {
    cout << Solution().sumNums(9) << endl;
	return 0;
}