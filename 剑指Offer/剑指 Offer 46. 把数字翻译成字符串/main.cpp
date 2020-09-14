#include <iostream>
using namespace std;

class Solution {
public:
    int cnt = 0;
    int translateNum(int num) {
        translateNumHelper(num);
        return cnt;
    }

    void translateNumHelper(int num) {
        if (num < 10) {
            cnt++;
            return;
        }
        translateNumHelper(num / 10);
        int a = num % 100;
        if (a >= 10 && a <= 25) {
            translateNumHelper(num / 100);
        }
    }
};

int main() {
    cout << Solution().translateNum(2005) << endl;
    return 0;
}