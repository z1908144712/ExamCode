#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &arr, vector<int> &tmp, int start, int end) {
    if (start >= end) {
		return;
    }
	int start1 = start, mid = (start + end) / 2, end1 = mid, start2 = mid + 1, end2 = end;
	merge_sort(arr, tmp, start1, end1);
	merge_sort(arr, tmp, start2, end2);
	int k = start;
    while (start1 <= end1 && start2 <= end2) {
		tmp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	}
	while (start1 <= end1) {
		tmp[k++] = arr[start1++];
	}
	while (start2 <= end2) {
		tmp[k++] = arr[start2++];
	}
	for (k = start; k <= end; k++) {
		arr[k] = tmp[k];
	}
}

int main() {
	vector<int> arr = { -100, 4, 6, -10, 9, 46, -4, 3, 6, 5, 8, 44, 20 };
	vector<int> tmp(arr.size());
	merge_sort(arr, tmp, 0, arr.size() - 1);
	for (auto& i : arr) {
		cout << i << " ";
	}
	return 0;
}