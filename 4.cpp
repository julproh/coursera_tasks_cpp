#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    string command;
    map <string, string> v;
    map <string, int> count;
    set <string> a;
    for (n; n > 0; n--) {
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
             int h = 0;
            cin >> word1 >> word2;
            for (auto i : v) {
            if ((v[word1]==word2)||(v[word2]==word1)) {
                   h++;
                }

            }
            if (h == 0) {
                count[word1]++;
                count[word2]++;
            }
            v[word1] = word2;
            for (const auto& z : v) {
                a.insert(z.first);
                a.insert(z.second);
                
                
            }
        }else if (command == "COUNT") {
            string word;
            cin >> word;
            int r = count[word];
            cout << r << endl;
 
        } 
         else if (command == "CHECK") {
            string word3, word4;
            cin >> word3 >> word4;
            if (a.count(word3) == 0 || a.count(word4) == 0) {
                        cout << "NO" << endl;
                        break;
            } else {
            for (auto i : v) {
                int s = 0;
                if ((i.first == word3 && i.second == word4) || (i.first == word4 && i.second == word3)) {
                    ++s;
                    cout << "YES" << endl;
                } else if ((i.first != word3 && i.second == word4)||(i.first != word4 && i.second == word3 )&& (s != 0)){
                    cout << "NO" << endl;
                }
            }
            }
        }
    }
    return 0;
}

/*
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java
*/