#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int key, val;
    ListNode* pre, *nxt;
    ListNode(int _key, int _val) : key(_key), val(_val), pre(nullptr), nxt(nullptr) {};
};

class LRUCache {
private:
    ListNode* head, * tail;
    int cap, size;
    unordered_map<int, ListNode*> m;

    void remove_node_from_list(ListNode* node) {
        if (node == head || node == tail) {
            if (head == node) {
                head = head->nxt;
                if (head) {
                    head->pre = nullptr;
                }
            }
            if (tail == node) {
                tail = tail->pre;
                if (tail) {
                    tail->nxt = nullptr;
                }
            }
        } else {
            node->pre->nxt = node->nxt;
            node->nxt->pre = node->pre;
        }
    }

    void push_node_to_front(ListNode* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            node->nxt = head;
            head->pre = node;
            node->pre = head->pre;
            head = node;
        }
    }

    ListNode* pop_node_from_back() {
        ListNode* p = tail;
        tail = tail->pre;
        tail->nxt = nullptr;
        return p;
    }

public:
    LRUCache(int _cap) :cap(_cap), size(0), head(nullptr), tail(nullptr) {};

    ~LRUCache() {
        while (head) {
            ListNode* p = head->nxt;
            delete head;
            head = p;
        }
        head = tail = nullptr;
    }

    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }
        ListNode* node = m[key];
        remove_node_from_list(node);
        push_node_to_front(node);
        return node->val;
    }

    void push(int key, int val) {
        ListNode* node = new ListNode(key, val);
        if (m.count(key)) {
            size--;
            ListNode*p = m[key];
            remove_node_from_list(p);
            delete p;
        } else {
            if (cap == size) {
                size--;
                ListNode* p = pop_node_from_back();
                m.erase(p->key);
                delete p;
            }
        }
        push_node_to_front(node);
        m[key] = node;
        size++;
    }
};

int main() {
    LRUCache cache(2);
    cache.push(1, 2);
    cache.push(1, 3);
    cache.push(2, 1);
    cache.push(3, 2);
    cache.push(3, 3);
    cout << cache.get(3) << endl;
	return 0;
}