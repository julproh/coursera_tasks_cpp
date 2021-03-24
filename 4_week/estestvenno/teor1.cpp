#include <iostream>
#include <vector>
#include <algorithm>

#include <sstream>
#include <iomanip>

using namespace std;

struct Duration
{
    Duration (int h = 0, int m = 0) {
      int total = h*60 +m;
       hour = total/60;
       min = total%60; 
    }
    int hour;
    int min;
};

bool operator <(const Duration& lhs, const Duration& rhs ) {
    if (lhs.hour==rhs.hour) {
    return lhs.min < rhs.min; }
    return lhs.hour < rhs.hour;
}
Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration {h, m};
}

/*void PrintDuration (ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
    << setw(2) << duration.min;
} */

ostream& operator <<  (ostream& stream, const Duration& duration)
{
       stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
    << setw(2) << duration.min;
    return  stream;
}

istream& operator >> (istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}
void Printvector (const vector<Duration>& duration) {
    for (const auto& d : duration) {
        cout << d << ' ';
    }
    cout << endl;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour+rhs.hour, lhs.min+rhs.min);
}
int main () {
    stringstream dur_ss("01:50");
   // Duration dur1 = ReadDuration(dur_ss);
    // PrintDuration(cout, dur1);
    //cout << dur1 << endl ;
    //operator << (operator << (cout, "hello"), "world");
    Duration dur2 {0,0}; 
    dur_ss >> dur2;
    Duration  dur1 = {0, 35};
    Duration dur3 = dur1+dur2;
    vector<Duration> v {
        dur3, dur2, dur1
    };
    cout << dur2 + dur1 << endl;
    Printvector(v);
    sort(begin(v), end(v));
    Printvector(v);
    return 0;
}