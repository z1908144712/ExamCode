#include <iostream>
#include <vector>

using namespace std;

int cnt = INT_MAX;

void bactrace(vector<int>& arr, vector<int>&idx) {
	int maxx = arr[idx[0]];
    for (int i = 1; i < idx.size(); i++) {
		maxx = max(maxx, arr[idx[i]] - arr[idx[i - 1]]);
	}
	cnt = min(cnt, maxx);
	for (int i = 1; i < idx.size(); i++) {
		if (i + 1 < idx.size() && idx[i + 1] - idx[i] == 1) {
			continue;
		}
	    if (idx[i] == arr.size() - 1) {
		    continue;
		}
		idx[i]++;
		bactrace(arr, idx);
		idx[i]--;
    }
}

int main() {
	vector<int> nums = {4, 3, 5, 10, 12};
	vector<int> arr(nums.size() + 1, 0);
	for (int i = 1; i < arr.size(); i++) {
		arr[i] += nums[i - 1] + arr[i - 1];
	}
	int n = 3;
	vector<int> idx(n + 1);
	for (int i = 0; i < n; i++) {
		idx[i] = i;
	}
	idx[n] = arr.size() - 1;
	bactrace(arr, idx);
	cout << cnt << endl;
	return 0;
}