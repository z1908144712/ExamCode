#include <iostream>
#include <mutex>

using namespace std;

//����ģʽ
class CSingleton {
private:
	CSingleton(){};
	CSingleton(CSingleton &c_singleton);
	CSingleton& operator=(const CSingleton &c_singleton);
	static mutex mutex_t;
	static CSingleton* instance;
public:
	static CSingleton *getInstance() {
		if (instance == nullptr) {
			mutex_t.lock();
			if (instance == nullptr) {
				instance = new CSingleton();
			}
			mutex_t.unlock();
		}
		return instance;
	}
};

//����ģʽ
class CSingleton1 {
private:
	CSingleton1(){};
	CSingleton1(CSingleton1 &c_singleton);
	CSingleton1& operator=(const CSingleton1 &c_singleton);
public:
	static CSingleton1 &getInstance() {
		static CSingleton1 instance;
		return instance;
	}
};

int main() {
	CSingleton* instance1 = CSingleton::getInstance();
	CSingleton1& instance2 = CSingleton1::getInstance();
	return 0;
}
