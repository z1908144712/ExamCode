#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
	int val;
    Node* left, *right;
	Node(int _val) :val(_val), left(nullptr), right(nullptr) {};
};

Node* buildBinTree(vector<int>& arr) {
	Node* root = nullptr;
	int idx = 0;
	stack<Node*> st;
	Node* p;
	while (idx < arr.size()) {
		if (arr[idx] != -1) {
			p = new Node(arr[idx]);
			if (!st.empty()) {
				if (st.top()->left == nullptr) {
					st.top()->left = p;
				} else if (st.top()->right == nullptr) {
					st.top()->right = p;
				}
				if (st.top()->left && st.top()->right) {
					st.pop();
				}
			} else {
				root = p;
			}
			st.push(p);
		} else {
			p = new Node(-1);
			if (st.top()->left == nullptr) {
				st.top()->left = p;
			} else if (st.top()->right == nullptr) {
				st.top()->right = p;
			}
			if (st.top()->left && st.top()->right) {
				st.pop();
			}
		}
		idx++;
	}
	return root;
}

int findNearParent(Node *root, int& a, int& b) {
    if (root == nullptr || root->val == -1) {
		return -1;
    }
	if (root->val == a || root->val == b) {
		return root->val;
	}
	int left = findNearParent(root->left, a, b);
	int right = findNearParent(root->right, a, b);
	if (left != -1 && right != -1) {
		return root->val;
	} else if (left == -1 && right != -1){
		return right;
	} else if (left != -1 && right == -1) {
		return left;
	} else {
		return -1;
	}
}

int main() {
	vector<int> arr;
	int x;
	while (cin >> x) {
		arr.push_back(x);
	}
	int a = arr.back();
	arr.pop_back();
	int b = arr.back();
	arr.pop_back();
	Node* root = buildBinTree(arr);
	cout << findNearParent(root, a, b) << endl;
	return 0;
}

/*
3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 9 -1 -1 8 -1 -1
5 1
 */