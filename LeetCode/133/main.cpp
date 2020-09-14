#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        vector<Node*> nodes = { node };
        map<int, Node*> m;
        Node *clone = NULL, *q = NULL, *neighbor = NULL;
        while (nodes.size() > 0) {
            Node* p = nodes.back();
            nodes.pop_back();
            if (m.count(p->val)) {
                q = m.find(p->val)->second;
                if (q->neighbors.size())
                    continue;
            } else {
                q = new Node();
                if (clone == NULL) {
                    clone = q;
                }
                q->val = p->val;
                m.insert(make_pair(q->val, q));
            }
            for (int i = 0; i < p->neighbors.size(); i++) {
                if (!m.count(p->neighbors[i]->val)) {
                    neighbor = new Node();
                    neighbor->val = p->neighbors[i]->val;
                    m.insert(make_pair(neighbor->val, neighbor));
                } else {
                    neighbor = m.find(p->neighbors[i]->val)->second;
                }
                if (!m.find(p->neighbors[i]->val)->second->neighbors.size())
                    nodes.push_back(p->neighbors[i]);
                q->neighbors.push_back(neighbor);
            }
        }
        return clone;
    }
};

int main() {
    Solution s;
    Node* p1 = new Node(1);
    Node* p2 = new Node(2);
    Node* p3 = new Node(3);
    Node* p4 = new Node(4);
    p1->neighbors.push_back(p2);
    p1->neighbors.push_back(p4);
    p2->neighbors.push_back(p1);
    p2->neighbors.push_back(p3);
    p3->neighbors.push_back(p2);
    p3->neighbors.push_back(p4);
    p4->neighbors.push_back(p1);
    p4->neighbors.push_back(p3);
    s.cloneGraph(p1);
    return 0;
}