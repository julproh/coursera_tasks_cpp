#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*int min (int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int max (int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
*/
bool gt2 (int x) {
    if ( x > 2) {
        return true;
    }
    return false;
}

bool lt2 (int x) {
    if (x < 2) {
        return true;
    }
    return false;
}

void Print (const vector<int>& v, const string& title) {
    cout << title << ": ";
    for (const auto& i : v) {
        cout << i << ' ';
    }
    cout << endl;
}
int main () {
string s1 = "abc";
string s2 = "bca";
cout << min (s1, s2) << endl; //заложенные алгоритмы
cout << max (2, 3) << endl;

//сортиовка
vector<int> v {1, 3, 2, 5, 4};
    Print(v , "init");
    sort (begin(v), end(v));
    Print (v, "sort");
   /* int cnt =0;
    for (auto item : v) {
        if (item == 2) {
            ++cnt;
        }
    }*/
    cout << count(begin(v), end(v), 2) << endl;
    cout << count_if(begin(v), end(v), gt2) << endl;
    cout << count_if(begin(v), end(v), lt2) << endl;
    int thr;
    cin >> thr;
    cout << count_if(begin(v), end(v), [thr](int x) {
    if ( x > thr) {
        return true;
    }
    return false;
} ) << endl;

    /*for (int i = 0; i < v.size(); ++i) {
        ++v[i];
    } */
    for (auto& i : v) {
        ++i;
    }

    cout << endl;
    Print(v, "inc");
    return 0;
}