#include <iostream>
#include <vector>
using namespace std;

int once_quick_sort(vector<int>& data, int left, int right) {
	int key = data[left];
	while (left < right) {
		while (left < right && key <= data[right]) {
			right--;
		}
		if (left < right) {
			data[left++] = data[right];
		}
		while (left < right && key > data[left]) {
			left++;
		}
		if (left < right) {
			data[right--] = data[left];
		}
	}
	data[left] = key;
	return left;
}
void quick_sort(vector<int>& data, int left, int right) {
	if (left >= right) {
		return;
	}
	int middle = 0;
	middle = once_quick_sort(data, left, right);
	quick_sort(data, left, middle - 1);
	quick_sort(data, middle + 1, right);
}

int main() {
	vector<int> nums{ 23,45,17,11,13,89,72,26,3,17,11,13 };
	quick_sort(nums, 0, nums.size() - 1);
	for (auto &num : nums) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}