#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Date
{
    int year;
    string month;
    int day;
};

 bool operator < (const Date& lhs, const Date& rhs) {
    tuple <const int&, const string&, const int&> lhs_key =  tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(rhs.year, rhs.month, rhs.day);
    return lhs_key <rhs_key;

 }


int main() {

    cout << (Date{2017, "June", 8} < Date{2017, "January", 26}) << endl;

    return 0;
}