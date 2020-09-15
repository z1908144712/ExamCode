#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	string s;
	cin >> s;
	int left = 0, right = 0;
	int cnt = 0;
	unordered_map<char, int> window;
	while (right < s.size()) {
		char c = s[right];
		right++;
		window[c]++;
		while (window[c] > 1) {
			window[s[left++]]--;
		}
		cnt = max(cnt, right - left);
	}
	cout << cnt << endl;
	return 0;
}