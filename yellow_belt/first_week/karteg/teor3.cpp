#include <iostream>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

int main() {

    tuple<int, string, bool> t(7, "C++", true);
    //tuple p(7, "C++", true); - в новом компиляторе
    auto m = make_tuple(7, "C++", true);
    cout << get<1>(m) << endl;
    ////////
    pair<int, string> p(7, "C++");
    auto q = make_pair(7, "C++");
    cout << p.first << " " << p.second << endl;
    ////////////
    map<int, string> digits = {{1, "one"}};
    for (const pair<int, string>& item : digits) {
        cout << item.first << " " << item.second << endl;
    }// item == [key, value]
    return 0;
}