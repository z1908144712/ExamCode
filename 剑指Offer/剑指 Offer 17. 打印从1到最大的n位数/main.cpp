#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> output;
    vector<int> printNumbers(int n) {
        string s(n, '0');
        helper(s, 0, n);
        return output;
    }

    void helper(string& s, int pos, int n) {
        if (pos == n) {
            strToInt(s);
            return;
        }
        for (char c = '0'; c <= '9'; c++) {
            s[pos] = c;
            helper(s, pos + 1, n);
        }
    }

    void strToInt(string& s) {
        int r = stoi(s);
        if (r == 0) {
            return;
        }
        output.push_back(stoi(s));
    }
};

int main() {
    vector<int> r = Solution().printNumbers(2);
    for (auto & i : r) {
        cout << i << " ";
    }
    return 0;
}