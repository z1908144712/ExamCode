#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        set<string> words;
        for (size_t i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }
        set<string> beginWordSet, endWordSet;
        beginWordSet.insert(beginWord);
        endWordSet.insert(endWord);
        int n = 1;
        while (beginWordSet.size() > 0) {
            set<string> nextBeginWordSet;
            for (set<string>::iterator it = beginWordSet.begin(); it != beginWordSet.end(); it++) {
                for (size_t i = 0; i < (*it).size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != (*it)[i]) {
                            string newWord = *it;
                            newWord[i] = c;
                            if (endWordSet.find(newWord) != endWordSet.end()) {
                                return n + 1;
                            }
                            if (words.find(newWord) != words.end()) {
                                nextBeginWordSet.insert(newWord);
                                words.erase(newWord);
                            }
                        }
                    }
                }
            }
            beginWordSet = nextBeginWordSet;
            n++;
            if (beginWordSet.size() > endWordSet.size()) {
                set<string> tmp = endWordSet;
                endWordSet = beginWordSet;
                beginWordSet = tmp;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    string beginWord = "qa";
    string endWord = "sq";
    vector<string> wordList = { "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye" };
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}