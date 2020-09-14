#include <iostream>
#include <string>
#include <stack>

using namespace std;

int longestValidParenthe(string s) {
    if (s.size() == 0) {
	    return 0;
    }
	stack<int> st;
	int cnt = 0;
	st.push(-1);
	for (auto i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		} else {
			st.pop();
			if (st.empty()) {
				st.push(i);
			} else {
				cnt = max(cnt, i - st.top());
			}
		}
	}
	return cnt;
}
/******************************½áÊøÐ´´úÂë******************************/


int main() {
    int res;

    string _s;
    getline(cin, _s);
    
    res = longestValidParenthe(_s);
    cout << res << endl;
    
    return 0;

}