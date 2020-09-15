#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sum = 0;
		int left = 0, right = 0;
		while (left < prices.size()) {
			if (right+1 < prices.size() && prices[right] <= prices[right+1]) {
				right++;
			} else {
				sum += prices[right] - prices[left];
				right++;
				left = right;
			}
		}
		return sum;
	}
};

int main() {
	Solution s;
	vector<int> prices = { 7,1,5,3,6,4 };
	cout << s.maxProfit(prices) << endl;
	return 0;
}