#include <iostream>
#include <map>
#include <chrono>
using namespace std;

class LRUCache {
public:
    map<int, int> *v;
    map<int, int64_t>* m;
    int capacity, n;
    LRUCache(int capacity) {
        this->capacity = capacity;
        n = 0;
        v = new map<int, int>();
        m = new map<int, int64_t>();
    }

    int get(int key) {
        if (v->count(key)) {
            m->find(key)->second = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
            return v->find(key)->second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (v->count(key)) {
            v->find(key)->second = value;
            m->find(key)->second = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
            return;
        }
        if (this->n >= this->capacity) {
            int min_index = m->begin()->first;
            int64_t min = m->begin()->second;
            for (map<int, int64_t>::iterator it = ++m->begin(); it != m->end(); it++) {
                if (it->second < min) {
                    min_index = it->first;
                    min = it->second;
                }
            }
            m->erase(min_index);
            v->erase(min_index);
            this->n--;
        }
        v->insert(make_pair(key, value));
        m->insert(make_pair(key, chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count()));
        this->n++;
    }
};

int main() {
    LRUCache* cache = new LRUCache(2 /* �������� */);
    cache->put(2, 1);
    cache->put(2, 2);
    cout << cache->get(2) << endl;       // ����  1
    cache->put(1, 1);    // �ò�����ʹ�ùؼ��� 2 ����
    cache->put(4, 1);    // �ò�����ʹ�ùؼ��� 1 ����
    cout << cache->get(2) << endl;       // ���� -1 (δ�ҵ�)

    return 0;
}