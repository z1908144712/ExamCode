#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
        int actul_area = 0;
        set<pair<int, int>> st;
        for (auto& rectangle : rectangles) {
            x1 = min(x1, rectangle[0]);
            y1 = min(y1, rectangle[1]);
            x2 = max(x2, rectangle[2]);
            y2 = max(y2, rectangle[3]);
            actul_area += (rectangle[3] - rectangle[1]) * (rectangle[2] - rectangle[0]);
            for (auto& p : vector<pair<int, int>>{
                {rectangle[0], rectangle[1]},
                {rectangle[0], rectangle[3]},
                {rectangle[2], rectangle[1]},
                {rectangle[2], rectangle[3]},
            }) {
                if (st.count(p)) {
                    st.erase(p);
                } else {
                    st.insert(p);
                }
            }
        }
        int expacted_area = (y2 - y1) * (x2 - x1);
        if (actul_area != expacted_area || st.size() != 4) {
            return false;
        }
        if (st.count({x1, y1}) && st.count({x1, y2}) && st.count({x2, y1}) && st.count({x2, y2})) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> rectangles{
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {3, 2, 4, 4},
        {1, 3, 2, 4},
        {2, 3, 3, 4}
    };
    cout << Solution().isRectangleCover(rectangles) << endl;
	return 0;
}