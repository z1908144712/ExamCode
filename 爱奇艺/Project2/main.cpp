#include <iostream>
#include <vector>

using namespace std;

int main() { 
	vector<int> arr;
	int x;
	while (cin >> x) {
		arr.push_back(x);
	}
	int cnt = 0;
	int vote = 0;
	for (auto &x : arr) {
	    if (cnt == 0) {
			cnt++;
			vote = x;
	    } else {
	        if (vote == x) {
				cnt++;
	        } else {
				cnt--;
	        }
	    }
	}
	cout << vote << endl;
	return 0;
}

/*

3 2 3
 */