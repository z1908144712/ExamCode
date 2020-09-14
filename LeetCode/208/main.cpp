#include <iostream>
#include <vector>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
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
    Trie() {
        root = new Item();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Item* p = root;
        vector<Item*>* items;
        for (int i = 0; i < word.size(); i++) {
            items = p->nexts;
            if (items == nullptr) {
                return false;
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
                return false;
            }
        }
        return p->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Item* p = root;
        vector<Item*>* items;
        for (int i = 0; i < prefix.size(); i++) {
            items = p->nexts;
            if (items == nullptr) {
                return false;
            }
            bool has = false;
            for (int j = 0; j < items->size(); j++) {
                if (prefix[i] == items->at(j)->val) {
                    p = items->at(j);
                    has = true;
                    break;
                }
            }
            if (!has) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("app");
    obj->insert("apple");
    obj->insert("beer");
    obj->insert("add");
    obj->insert("jam");
    obj->insert("retal");
    cout << obj->search("apps") << endl;
    cout << obj->startsWith("ja") << endl;
    /*cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;*/
    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);  
 */