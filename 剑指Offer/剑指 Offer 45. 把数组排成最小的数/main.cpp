#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strnums;
        for (auto &num : nums) {
            strnums.push_back(to_string(num));
        }
        sort(strnums.begin(), strnums.end(), mycmp);
        string r = "";
        for (auto& s: strnums) {
            r += s;
        }
        return r;
    }

    static bool mycmp(const string& s1, const string& s2) {
        return (s1 + s2) > (s2 + s1);
    }
};

int main() {
    vector<int> nums = { 3,30,34,5,9 };
    cout << Solution().minNumber(nums) << endl;
    return 0;
}