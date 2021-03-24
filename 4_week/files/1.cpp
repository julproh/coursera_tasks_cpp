#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    ifstream file("input.txt");
    if (file) {
       string s;
       while (getline(file, s)){
       cout << s << endl; }
    }
    return 0;
}