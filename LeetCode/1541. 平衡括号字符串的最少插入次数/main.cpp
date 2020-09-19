#include <iostream>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0;
    	for (auto &i : s) {
    		if (i == '(') {
    			right += 2;
    			if (right & 1) {
    				left++;
    				right--;
    			}
    		}
    		if (i == ')') {
    			right--;
    			if (right == -1) {
    				right = 1;
    				left++;
    			}
    		}
    	}
    	return left + right;
    }
};

int main() {
    string s = "))())(";
	cout << Solution().minInsertions(s) << endl;
	return 0;
}