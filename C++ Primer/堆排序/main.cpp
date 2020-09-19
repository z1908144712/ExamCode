#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int>& arr, int start, int end) {
	int parent = start;
	int child = parent * 2 + 1;
	while (child <= end) {
	    if (child + 1 <= end && arr[child] < arr[child + 1]) {
			child++;
	    }
		if (arr[parent] > arr[child]) {
		    break;
		} else {
			swap(arr[parent], arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}

void heap_sort(vector<int>& arr) {
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i, arr.size() - 1);
    }
	for (int i = arr.size() - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

int main() {
	vector<int> arr = { -100, 4, 6, -10, 9, 46, -4, 3, 6, 5, 8, 44, 20 };
	heap_sort(arr);
	for (auto& i : arr) {
		cout << i << " ";
	}
	return 0;
}