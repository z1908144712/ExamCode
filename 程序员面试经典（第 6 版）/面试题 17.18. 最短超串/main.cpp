#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        map<int, int> mp;
        for (auto& sm : small) {
            mp[sm] = 0;
        }
        int left = 0, right = 0;
        int count = small.size();
        vector<int> ans{0, (int)big.size() - 1};
        bool flag = true;
        while (left < big.size()) {
            if (right < big.size() && mp.count(big[right])) {
                if (mp[big[right]] == 0) {
                    count--;
                }
                mp[big[right]]++;
            }
            while (left < big.size() && count == 0) {
                flag = false;
                if (right - left < ans[1] - ans[0]) {
                    ans[0] = left;
                    ans[1] = right;
                }
                if (mp.count(big[left])) {
                    if (mp[big[left]] == 1) {
                        count++;
                    }
                    mp[big[left++]]--;
                } else {
                    left++;
                }
            }
            if (right >= big.size()) {
                break;
            } else {
                right++;
            }
        }
        if (flag) {
            return {};
        }
        return ans;
    }
};

int main() {
    vector<int> big{ 1 };
    vector<int> small{ 1, 2 };
    vector<int> r = Solution().shortestSeq(big, small);
    for (auto &i : r) {
        cout << i << " ";
    }
	return 0;
}