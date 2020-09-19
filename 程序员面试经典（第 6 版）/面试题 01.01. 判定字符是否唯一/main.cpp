#include <iostream>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int mask = 0;
    	for (auto &s :astr) {
    		int bit = s - 'a';
    		if (mask & (1 << bit)) {
    			return false;
    		} else {
    			mask |= (1 << bit);
    		}
    	}
    	return true;
    }
};

int main() {
    string astr  = "leetcode";
	cout << Solution().isUnique(astr) << endl;
	return 0;
}