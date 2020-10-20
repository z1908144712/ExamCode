#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* revse(ListNode* head) {
	if (!head) {
		return nullptr;
	}
	ListNode* re_head = nullptr, *p = head, *pre;
	while (p) {
		pre = p->next;
		p->next = re_head;
		re_head = p;
		p = pre;
	}
	return re_head;
}

int main() {

	return 0;
}