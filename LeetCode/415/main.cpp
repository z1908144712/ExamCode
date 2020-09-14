#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret = "";
        int i = 0, num1Index = num1.size() - 1, num2Index = num2.size() - 1;
        while (num1Index >= 0 && num2Index >= 0) {
            int sum = num1[num1Index] - '0' + num2[num2Index] - '0' + i;
            i = sum / 10;
            ret.push_back(sum % 10 + '0');
            num1Index--;
            num2Index--;
        }
        while (num1Index >= 0) {
            int sum = num1[num1Index] - '0' + i;
            i = sum / 10;
            ret.push_back(sum % 10 + '0');
            num1Index--;
        }
        while (num2Index >= 0) {
            int sum = num2[num2Index] - '0' + i;
            i = sum / 10;
            ret.push_back(sum % 10 + '0');
            num2Index--;
        }
        if (i > 0) {
            ret.push_back(i + '0');
        }
        return string(ret.rbegin(), ret.rend());
    }
};

int main() {
    string num1 = "1235";
    string num2 = "123";
    cout << Solution().addStrings(num1, num2) << endl;
    return 0;
}