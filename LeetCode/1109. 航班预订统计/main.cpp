#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for (auto & booking : bookings) {
            int i = booking[0] - 1;
            int j = booking[1];
            diff[i] += booking[2];
            if (j < n) {
                diff[j] -= booking[2];
            }
        }
        vector<int> r(n);
        r[0] = diff[0];
        for (int i = 1; i < n; i++) {
            r[i] = r[i - 1] + diff[i];
        }
        return r;
    }
};

int main() {
    vector<vector<int>> bookings = { {1,2,10 }, { 2,3,20 }, { 2,5,25 }};
    int n = 5;
    for (auto &i : Solution().corpFlightBookings(bookings, n)) {
        cout << i << " ";
    }
	return 0;
}