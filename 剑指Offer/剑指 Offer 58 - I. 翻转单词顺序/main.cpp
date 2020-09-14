#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string sub, r;
        while (getline(iss, sub, ' ')) {
            if (sub.size()) {
                if (r.size()) {
                    r = sub + " " + r;
                } else {
                    r = sub;
                }
            }
        }
        return r;
    }
};

int main() {
    string s = "a good   example";
    cout << Solution().reverseWords(s) << endl;
	return 0;
}