#include <iostream>
#include <exception>
#include <string>

using namespace std;


class TimeServer {
public:
    string GetCurrentTime() {
        try {
            LastFetchedTime = AskTimeServer();
            return LastFetchedTime;
        } catch (system_error& se) {
            return LastFetchedTime;
        }
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}