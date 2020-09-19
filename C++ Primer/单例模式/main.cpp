#include <iostream>
#include <mutex>

using namespace std;

//����ģʽ
class CSingleton {
private:
	CSingleton();
	CSingleton(CSingleton &c_singleton) = delete;
	void operator=(const CSingleton &c_singleton) = delete;
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
	static mutex mutex_t;
	static CSingleton *instance;
};

//����ģʽ
class CSingleton1 {
private:
	CSingleton1();
	CSingleton1(CSingleton1 &c_singleton) = delete;
	void operator=(const CSingleton1 &c_singleton) = delete;
public:
	static CSingleton1 &getInstance() {
		static CSingleton1 instance;
		return instance;
	}
};

int main() {

	return 0;
}
