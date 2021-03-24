#include <iostream> //
// #include <istream> // сin
// #include <ostream> // cout
#include <fstream> // для файлов
using namespace std;
// getline - читать из потока построчно

void ReadAll (const string& path) {
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
}

int main () {
    ifstream input ("hello2.txt");
    string line;
    if (input.is_open()){ 
    while(getline(input, line)){
        cout << line << endl;
    } 
     cout << "done!" << endl;
    } else {
        cout << "error!" << endl;
    }
    string year;
    string month, day;
    ifstream input2("date.txt");
    if (input2) {
        getline(input2, year, '-');
        getline(input2, month, '-');
        getline(input2, day, '-');

    }
    cout << year << ' ' << month << ' ' << day << endl;
    int year1 = 0;
    int month1 = 0;
    int day1 = 0;
    if (input2) {
        input >> year;
        input.ignore(1);
        input >> month;
        input.ignore(1);
        input >> day;
    }
    cout << year << ' ' << month << ' ' << day << endl;
// __________________
const string path = "output.txt";
 ofstream output(path);
 output << "hello" << endl;
 ifstream input3(path);
    if (input3) {
        while (getline(input3, line)) {
            cout << line << endl;
        }
    }
    ofstream output2(path, ios::app);
    output2 << " world!" << endl;
    ReadAll(path);


 return 0;
}