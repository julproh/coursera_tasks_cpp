#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct  Student
{
    string name;
    string lastname;
    int day;
    int month;
    int year;
};


int main () {
    int n, k;
    cin >> n;
    vector <Student> students;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.name >> s.lastname 
        >> s.day >> s.month >> s.year;
        students.push_back(s);
    }
    cin >> k;
    string command;
    for (int i = 0; i < k; i++) {
        int t;
        cin >>  command >> t;
        t--;
        if (command == "name" && t>=0 && t < n) {
            cout << students[t].name 
            << ' ' << students[t].lastname << endl;
        } else if (command == "date" && t>=0 && t < n) {
            cout << students[t].day << '.' 
            << students[t].month << '.' 
            << students[t].year << endl;
        }  else { cout << "bad request" << endl;}
    }
    return 0;
}