#include <iostream>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int idx = 0;
        while (idx < str.size() && str[idx] == ' ') {
            idx++;
        }
        int sign = 1;
        int res = 0;
        int border = INT_MAX / 10;
        if (idx < str.size()) {
            if (str[idx] == '-') {
                sign = -1;
                idx++;
            } else if (str[idx] == '+') {
                sign = 1;
                idx++;
            }
        }
        while (idx < str.size()) {
            if (str[idx] < '0' || str[idx] > '9') {
                break;
            }
            if (res > border || (res == border && str[idx] > '7')) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (str[idx++] - '0');
        }
        return res * sign;
    }
};

int main() {
    string str = "-42";
    cout << Solution().strToInt(str) << endl;
	return 0;
}