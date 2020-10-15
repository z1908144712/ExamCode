#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
	string node_name;
	string node_value;
};

struct Item {
	string item_name;
	vector<Node> nodes;
};

struct Conf {
	string conf_name;
	vector<Item> items;
};

Conf readINIFile(string path) {
	FILE * fp = fopen(path.c_str(), "r");
	if (!fp) {
		return {};
	}
	char *buff = new char[1024 * 1024];
	int len = 0, l = 0;
	while((l = fread(buff + len, 1024, 1, fp)) != EOF) {
		len += l;
	}
	Conf Conf();
	conf->conf_name = path;
	if (len == 0) {
		
		return conf;
	}
	stringstream ss(buff);
	string s;
	while (getline(ss, s, '\n')) {
		if () {
			
		}
	}
	delete 
}

int main() {

	return 0;
}