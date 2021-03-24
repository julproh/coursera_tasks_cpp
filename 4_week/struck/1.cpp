#include <iostream>

using namespace std;
struct Day
{
    int value;
    explicit Day (int new_value) {
        value  = new_value;
    }
};

struct Month
{
    int value;
    explicit Month(int new_month) {
        value = new_month;
    }
};

struct Year
{
    int value;
    explicit Year(int new_year) {
        value = new_year;
    }
};

struct date
{
    int day;
    int month;
    int year;
    date( Day new_day, Month new_month, Year new_year) {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;

    }
};

void printDate (const date& Date) {
    cout << Date.day << '.' << Date.month << '.' << Date.year << endl;

}

int main () {
    date Date = {Day{1}, Month{1}, Year{2017}};
    printDate(Date);
    return 0;
}