#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> r(a.size(), 1);
        for (auto i = 1; i < a.size(); i++) {
            r[i] = r[i - 1] * a[i - 1];
        }
        auto t = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            r[i] *= t;
            t *= a[i];
        }
        return r;
    }
};

int main() {
    vector<int> a = { 1,2,3,4,5 };
    vector<int> r = Solution().constructArr(a);
	
    for (auto & i : r) {
        cout << i << " ";
    }
	return 0;
}