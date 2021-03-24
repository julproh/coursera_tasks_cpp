#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

string Transform(string& s) {
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        temp += tolower(s[i]);
    }
    return temp;
}

int main () {
    int n;
    cin >> n;
    vector <string> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    sort(begin(v), end(v), [](string s, string t) {
        return Transform(s) < Transform(t);
    });

    for (auto x : v) {
        cout << x << ' ';
    }
    return 0;
}