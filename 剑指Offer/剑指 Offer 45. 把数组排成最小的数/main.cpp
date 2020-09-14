#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, cmp<string>> pr;
        for (auto &num : nums) {
            pr.push(to_string(num));
        }
        string r = "";
        while (!pr.empty()) {
            r += pr.top();
            pr.pop();
        }
        return r;
    }

    template <typename T>
    struct cmp{
        bool operator() (const T& s1, const T& s2) {
            return (s1 + s2) > (s2 + s1);
        }
    };
};

int main() {
    vector<int> nums = { 3,30,34,5,9 };
    cout << Solution().minNumber(nums) << endl;
    return 0;
}