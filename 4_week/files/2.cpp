#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    ifstream file("input.txt");
    ofstream file2 ("output.txt");
    string s;
    if (file) {
       while (getline(file, s)) {
       file2 << s << endl; }
    }
    return 0;
}
