#include <iostream>
#include <string>
#include <set>

using namespace std;

int main () {
    int n, k;
    cin >> n;
    k = n;
    string s;
    set <string> words;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if(words.count(s)) {
            k--;
        } 
        words.insert(s);
    }
    cout << k;
    return 0;
}