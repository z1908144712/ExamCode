#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int l = left, r = right;
	int t = arr[left];
	while (left < right) {
		while (left < right && arr[right] > t) {
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] <= t) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = t;
	quick_sort(arr, l, left - 1);
	quick_sort(arr, left + 1, r);
}

int main() {
	vector<int> arr{4, 3, 7, 5, 3, 9};
	quick_sort(arr, 0, arr.size() - 1);
	for (auto &num : arr) {
		cout << num << " ";
	}
	return 0;
}