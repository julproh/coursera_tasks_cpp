#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void Printset(const set<string>& s) {
    for (auto x : s) {
        cout << x << endl;
    }
}
int main() {
    set <string> famous;
    famous.insert("Stroustrup");
    Printset(famous);
    famous.insert("Anthon");
    famous.erase("Anthon");
    set <string> months = {"March", "January", "February","March"};
    Printset(months);

    cout << months.count("January");

    vector<string> v = {"a", "b", "a"};
    set<string> s(begin(v), end(v));
    Printset(s); 
    return 0;
}