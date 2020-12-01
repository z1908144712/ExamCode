#include <iostream>
#include <vector>

using namespace std;

int countPrime(int n) {
	vector<bool> primes(n + 1, true);
	for (int i = 2; i <= n; i++) {
	    if (primes[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				primes[j] = false;
	        }
	    }
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
	    if (primes[i]) {
			//cout << i << endl;
			cnt++;
	    }
	}
	return cnt;
}

int main() {
	cout << countPrime(1000) << endl;
	return 0;
}