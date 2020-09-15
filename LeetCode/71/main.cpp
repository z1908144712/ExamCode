#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		int points = 0;
		string file = "";
		vector<string> files;
		for (int i = 0; i < path.size(); i++) {
			switch (path[i]) {
			case '/':
				if (points == 2 && file.size() > 0 && files.size() > 0) {
					files.pop_back();
				} else if ((file.size() == 1 && points != 1) || (file.size() > 1 && points != 2) || (file.size() > 2 && points == 2)) {
					files.push_back(file);
				}
				file.clear();
				points = 0;
				break;
			case '.':
				points++;
			default:
				file += path[i];
				break;
			}
		}
		if (points == 2 && file.size() > 0 && files.size() > 0) {
			files.pop_back();
		} else if ((file.size() == 1 && points != 1) || (file.size() > 1 && points != 2) || (file.size() > 2 && points == 2)) {
			files.push_back(file);
		}
		file = "/";
		for (int i = 0; i < files.size(); i++) {
			file += files[i];
			if (i < files.size()-1) {
				file += "/";
			}
		}
		return file;
	}
};

int main() {
	Solution s;
	cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
	return 0;
}