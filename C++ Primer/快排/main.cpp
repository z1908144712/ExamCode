#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int l = left, r = right;
	int tmp = arr[left];
	while (left < right) {
		while (left < right && arr[right] > tmp)
			right--;
		arr[left] = arr[right];
		while (left < right && arr[left] <= tmp) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = tmp;
	quick_sort(arr, l, left - 1);
	quick_sort(arr, left + 1, r);
}

int main() {
	vector<int> arr = { -100, 4, 6, -10, 9, 46, -4, 3, 6, 5, 8, 44, 20 };
	quick_sort(arr, 0, arr.size() - 1);
	for (auto &i : arr) {
		cout << i << " ";
	}
	return 0;
}