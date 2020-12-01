#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct AdItem {
	string   ad_id;
	int     weight;
};

set<AdItem> ad_get(const vector<AdItem>& ad_items) {
	int sum = 0;
	map<int, set<AdItem>> m;
    for (auto& item : ad_items) {
		sum += item.weight;
		m[item.weight].insert(item);
	}
	time_t t;
	srand((unsigned)time(&t));
	int r = rand() % sum + 1;
	set<AdItem> st;
	for (auto it = m.begin(); it != m.end(); ++it) {
	    if (it->first >= r) {
			st.insert(it->second.begin(), it->second.end());
            break;
        }
    }
	return st;
}


int main() {
	vector<AdItem> items{{"s1", 1}, {"s2", 9}};
	for (auto& item : items) {
		cout << item.ad_id << endl;
	}
	return 0;
}