#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end());
        vector<int> dp(box.size() + 1);
        int r = 0;
        for (int i = 0; i < box.size(); i++) {
            dp[i] = box[i][2];
            r = max(r, dp[i]);
            for (int j = 0; j < i; j++) {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                    r = max(r, dp[i]);
                }
            }
        }
        return r;
    }
};

int main() {
    vector<vector<int>> box{ {1, 1, 1} ,{2, 3, 4},{2, 6, 7},{3, 4, 5} };
    cout << Solution().pileBox(box) << endl;
	return 0;
}