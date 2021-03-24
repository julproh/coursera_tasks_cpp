#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main()
{
    set<set<string>> vocabulary;
    map<string, int> counter;
    string word1, word2;
 
    int q;
    cin >> q;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            cin >> word1 >> word2;
            if (auto [iterator, succeeded] = vocabulary.insert({ word1, word2 }); succeeded) {
                ++counter[word1];
                ++counter[word2];
            }
        } else if (cmd == "COUNT") {
            cin >> word1;
            cout << (counter.count(word1) ? counter[word1] : 0) << endl;
        } else if (cmd == "CHECK") {
            cin >> word1 >> word2;
            if (vocabulary.count({ word1, word2 })) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
 
    return 0;
}