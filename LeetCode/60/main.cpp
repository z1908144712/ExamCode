#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string data = "", ans = "";
		for (int i = 1; i <= n; i++) {
			data += '0' + i;
		}
		int cur = 0, x = n;
		while (cur++ < n) {
			int i = (k - 1) / factorial(--x);
			ans += data.at(i);
			data.erase(data.begin() + i);
			k -= i * factorial(x);
		}
		/*int cur = 1, left, right;
		while (cur++ < k) {
			left = n - 2;
			while (left >= 0 && ans[left] > ans[left + 1])
				left--;
			if (left >= 0) {
				right = n - 1;
				while (right >= 0 && ans[right] < ans[left])
					right--;
				char tmp = ans[right];
				ans[right] = ans[left];
				ans[left] = tmp;
			}
			for (int i = left + 1, j = n - 1; i < j; i++, j--) {
				char tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}*/
		return ans;
	}

	int factorial(int n) {
		int sum = 1;
		for (int i = 2; i <= n; i++) {
			sum *= i;
		}
		return sum;
	}
};

int main() {
	Solution s;
	cout << s.getPermutation(4, 9) << endl;
}
