#include <iostream>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = abs((int)(first.size() - second.size()));
        if (n >= 2) {
            return false;
        } else if (n == 1) {
            if (first.size() < second.size()) {
                bool flag = false;
                for (int i = 0, j = 0; i < first.size(); i++, j++) {
                    if (first[i] != second[j]) {
                        if (flag) {
                            return false;
                        }
                        flag = true;
                        i--;
                    }
                }
            } else {
                bool flag = false;
                for (int i = 0, j = 0; j < second.size(); i++, j++) {
                    if (first[i] != second[j]) {
                        if (flag) {
                            return false;
                        }
                        flag = true;
                        j--;
                    }
                }
            }
        } else if (n == 0) {
            int cnt = 0;
            for (int i = 0; i < first.size(); i++) {
                if (first[i] != second[i]) {
                    cnt++;
                    if (cnt >= 2) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().oneEditAway("teacher", "taches") << endl;
	return 0;
}