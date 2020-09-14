#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> st = {n};
        while (n != 1) {
            int t = 0;
            while (n) {
                t += pow(n % 10, 2);
                n /= 10;
            }
            if (t == 1) {
                return true;
            }
            if (st.count(t)) {
                return false;
            }
            st.insert(t);
            n = t;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(2) << endl;
    return 0;
}