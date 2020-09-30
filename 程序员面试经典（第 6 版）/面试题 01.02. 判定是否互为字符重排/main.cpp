#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto &c : s1) {
            mp[c]++;
        }
        int cnt = mp.size();
        for (auto &c : s2) {
            mp[c]--;
            if (mp[c] == -1) {
                return false;
            }
            if (mp[c] == 0) {
                cnt--;
            }
        }
        return cnt == 0;
    }
};

int main() {
    cout << Solution().CheckPermutation("abc", "bcb") << endl;
	return 0;
}