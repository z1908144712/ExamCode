#include <iostream>
#include <vector>
using namespace std;

class WordDictionary {
public:
    class Item {
    public:
        char val;
        vector<Item*>* nexts;
        bool end;

        Item() {
            this->val = NULL;
            this->nexts = nullptr;
            this->end = false;
        }

        Item(char val) {
            this->val = val;
            this->nexts = nullptr;
            this->end = false;
        }
    };

    Item* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Item();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Item* p = root, * t;
        vector<Item*>* items;
        for (int i = 0; i < word.size(); i++) {
            items = p->nexts;
            if (items == nullptr) {
                items = new vector<Item*>();
                t = new Item(word[i]);
                items->push_back(t);
                p->nexts = items;
                p = t;
                continue;
            }
            bool has = false;
            for (int j = 0; j < items->size(); j++) {
                if (word[i] == items->at(j)->val) {
                    p = items->at(j);
                    has = true;
                    break;
                }
            }
            if (!has) {
                t = new Item(word[i]);
                items->push_back(t);
                p = t;
            }
        }
        p->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchSub(word, 0, root);
    }
    
    bool searchSub(string word, int n, Item* root) {
        if (root == nullptr) {
            return false;
        }
        if (n >= word.size()) {
            return root->end;
        }
        vector<Item*>* items = root->nexts;
        if (items == nullptr) {
            return false;
        }
        if (word[n] == '.') {
            for (int i = 0; i < items->size(); i++) {
                if (searchSub(word, n + 1, items->at(i))) {
                    return true;
                }
            }
            return false;
        }
        Item* p = nullptr;
        for (int i = 0; i < items->size(); i++) {
            if (word[n] == items->at(i)->val) {
                p = items->at(i);
                break;
            }
        }
        if (p) {
            return searchSub(word, n + 1, p);
        }
        return false;
    }
};

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b.") << endl;
    return 0;
}