#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> res;

    void helper(int& n, int left, int right, string s) {
        if (left == n && left == right) {
            res.push_back(s);
            return;
        }
        if (left + 1 <= n) {
            helper(n, left + 1, right, s + "(");
        }
        if (right + 1 <= left) {
            helper(n, left, right + 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        helper(n, 0, 0, "");
        return res;
    }
};

int main() {
    for (auto &s : Solution().generateParenthesis(3)) {
        cout << s << endl;
    }
	return 0;
}