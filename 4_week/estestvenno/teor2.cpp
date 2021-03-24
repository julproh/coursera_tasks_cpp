#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void Ensure (stringstream& stream) {
        if (stream.peek() != '/') {
                stringstream sss;
               sss << "expected / , but has:" << char(stream.peek()); 
        throw runtime_error(sss.str());
       // throw exception();
    }
    stream.ignore(1);
}


Date ParseDate (const string& s) {
    stringstream stream(s);
    Date date;
    stream.peek();
    stream >> date.year;
    Ensure (stream);
    stream >> date.month;
    Ensure (stream);
    stream.ignore(1);
    stream >> date.day;
    return date;

}

/*try {
    ...
} catch (exeption& ) {
    ...
} */

int main () {
    string date_str ="2017e01/25";
    try {
    Date date = ParseDate(date_str);
    cout << setw(2) << setfill('0') << date.day << '.'
    <<setw(2) << setfill('0') << date.month << '.'
    <<  date.year << endl; } catch (exception& ex) {
        cout << "exeption happens:" << ex.what();
    }
    return 0;
}