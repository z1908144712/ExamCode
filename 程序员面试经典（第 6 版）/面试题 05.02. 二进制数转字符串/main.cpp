#include <iostream>

using namespace std;

class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        int cnt = 31;
        while (num > 0 && --cnt) {
            num *= 2;
            if (num >= 1) {
                res.push_back('1');
                num--;
            } else {
                res.push_back('0');
            }
        }
        return num != 0 ? "ERROR" : res;
    }
};

int main() {
    cout << Solution().printBin(0.625) << endl;
	return 0;
}