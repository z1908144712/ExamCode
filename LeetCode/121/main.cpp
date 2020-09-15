#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int minPrice = INT_MAX, maxProfit = 0;
		for (int i = 0; i < n; i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			} else if (prices[i] - minPrice > maxProfit) {
				maxProfit = prices[i] - minPrice;
			}
		}
		return maxProfit;
	}
};

int main() {
	Solution s;
	vector<int> prices = {1,2,4,2,5,7,2,4,9,0,9};
	cout << s.maxProfit(prices) << endl;
	return 0;
}