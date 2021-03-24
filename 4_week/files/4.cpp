#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main () {
    int a,b, c;
    ifstream input ("input.txt");
    if (input) {
        input >> a >> b;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                input >> c;
                input.ignore(1);
            if (j == 0) {cout << setw(10) << c;}
            else {cout << ' '<< setw(10) << c;}
            }
            cout << endl;
        }
    }
    return 0;
}