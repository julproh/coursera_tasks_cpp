#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void Print (const vector<string> & names, const vector<double>& values, int Q) {
    for (const auto& n : names) {
        cout <<setw(Q) << n << ' ';
    }
    cout << endl;
    cout << fixed << setprecision(2); // точность

    for (const auto& n : values) {
        cout << setw(Q) << n << ' ';
    }
    cout << endl;
}
int main() {
    vector <string> names ={"a", "b", "c"};
    vector <double> values = {5, 0.01, 0.0000005};
    for (const auto& n : names) {
        cout <<setw(10) << n << ' ';
    }
    cout << endl;
    cout << fixed << setprecision(2);

    for (const auto& n : values) {
        cout << setw(10) << n << ' '; // определяем ширину колонок
    }
    cout << endl;
    cout << setfill('.');// заполняет пропуски
    cout << left; // вывод слева
    Print(names, values, 10);
    return 0;
}