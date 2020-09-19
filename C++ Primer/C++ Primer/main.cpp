#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define ADD(a, b) (a)*(b)

class A {
private:
	static int a;
public:
	void func() {
		cout << this->a << endl;
	}
};

int A::a = 10;

int main() {
	//int i = 42;
	//int& r1 = i;
	//const int& r2 = i * 2;
	//vector<string> r8{10, "123"};
	///*cout << r2 << endl;
	//cout << i << " " << i++ << endl;
	//cout << sizeof i << endl;
	//cout << sizeof(int) << endl;*/
	//string r4 = "3333333333";
	//string&& r3 = std::move(r4);
	//r3 += "4";
	//cout << r3 << endl;
	//cout << r4 << endl;
	/*A a1;
	a1.a = 20;
	a1.func();
	cout << A::a << endl;*/
	// shared_ptr<int> p1(new int(3));
	// cout << p1.use_count() << endl;
	// stack<shared_ptr<int>> st;
	// st.push(p1);
	// cout << p1.use_count() << endl;
	cout << ADD(1 + 2, 3) << endl;
	return 0;
}