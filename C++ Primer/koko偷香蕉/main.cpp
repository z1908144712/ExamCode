#include <iostream>
#include <vector>

using namespace std;

int getSum(vector<int>& piles) {
	int sum = 0;
	for (auto& pile : piles) {
		sum += pile;
	}
	return sum;
}

int getMax(vector<int>& piles) {
	int maxx = INT_MIN;
	for (auto& pile : piles) {
		maxx = max(maxx, pile);
	}
	return maxx;
}

bool canFinish(vector<int>& piles, int H, int speed) {
	int cnt = 0;
	for (auto& pile : piles) {
		cnt += pile / speed + (pile % speed ? 1 : 0);
	}
	return cnt <= H;
}

int minEatingSpeed(vector<int>& piles, int H) {
	int lo = getMax(piles), hi = getSum(piles);
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (canFinish(piles, H, mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	vector<int> piles{30, 11, 23, 4, 20};
	int H = 5;
	cout << minEatingSpeed(piles, H) << endl;
	return 0;
}