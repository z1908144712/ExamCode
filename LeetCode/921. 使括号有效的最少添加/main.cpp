#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, right = 0;
    	for (auto &s : S) {
    		if (s == '(') {
    			right++;
    		}
    		if (s == ')') {
    			right--;
    			if (right == -1) {
                    right = 0;
    				left++;
    			}
    		}
    	}
    	return left + right;
    }
};

int main() {
    string S = "()))((";
	cout << Solution().minAddToMakeValid(S) << endl;
	return 0;
}