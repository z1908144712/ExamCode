#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder,0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }
        TreeNode* p = new TreeNode(preorder[preStart]);
        int idx = inStart;
        for (idx = inStart; idx <= inEnd; idx++) {
            if (inorder[idx] == preorder[preStart]) {
                break;
            }
        }
        int len = idx - inStart;
        p->left = buildHelper(preorder, preStart + 1, preStart + len, inorder, inStart, idx - 1);
        p->right = buildHelper(preorder, preStart + len + 1, preEnd, inorder, idx + 1, inEnd);
        return p;
    }
};

int main() {
    vector<int> preorder{ 3,9,20,15,7 };
    vector<int> inorder{ 9,3,15,20,7 };
    TreeNode* root = Solution().buildTree(preorder, inorder);
    queue<TreeNode*> qu;
    qu.push(root);
    while (!qu.empty()) {
        int len = qu.size();
        for (int i = 0; i < len; i++) {
            TreeNode* p = qu.front();
            qu.pop();
            cout << p->val << " ";
            if (p->left) {
                qu.push(p->left);
            }
            if (p->right) {
                qu.push(p->right);
            }
        }
        cout << endl;
    }
	return 0;
}