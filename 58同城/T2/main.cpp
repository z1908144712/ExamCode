#include <iostream>
#include <ctime>

using namespace std;

int main() {
	string t = "2020-06-20 10:10:10";
	string format = "%Y-%m-%d %H:%M:%s";
	struct tm tma;
	strftime(const_cast<char*>(t.c_str()), t.size(),format.c_str(), &tma);
	try {
		
	} catch (...) {
		
	} 
	return 0;
}