#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main () {
    ifstream stream("input.txt");
int kg, pw;
vector <int> massa;
vector <int> sila;
while (stream >> kg) {
    stream >> pw;
    massa.push_back(kg);
    sila.push_back(pw);
}
vector <int> massa_s = massa;
vector <int> sila_s = sila;

sort(sila_s.begin(), sila_s.end());
sort(massa_s.begin(), massa_s.end());


int mass = massa_s[0];
int h = 1;
for (int i = 1; i < massa.size(); i++) {
    if (sila_s[i] >= mass) {
        mass = mass+massa_s[i];
        h++;
    }
}
    cout << h << endl;
    return 0;
}
