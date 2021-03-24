#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main () {
    int n, t;
    cin >> n;
    map <set<string>, int> m;
    for (n; n > 0; n--) {
        int k;
        string s;
        cin >> k;
        set<string> stops;
        t = m.size();
        for (k; k > 0; k--) {
            cin >> s;
            stops.insert(s);
        }
        if (m.count(stops)) {
            cout << "Already exists for " << m[stops] << endl;
        } else{
        m[stops] = t+1;
        cout << "New bus " << m[stops] << endl;
        }
    }
    return 0;
}