#include <iostream>

using namespace std;

class Route {
public:
    string GetSource() {return source;}
    string GetDestination() {return destination;}
    int GetLength() {return length;}
    void SetSourse (const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination (const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }
private:
    string source;
    string destination;
    int length;
    void UpdateLength() {
        length = ComputeDistance(source, destination);
    }
};

int ComputeDistance(const string& source, const string& destination);



int main () {
    Route route;
    route.SetSourse("Moscow");
    route.SetDestination("Dubna");
    cout << "Rout from" <<
    route.GetSource() << " to " << route.GetDestination() <<" is "
    << route.GetLength() << "meters long";

    return 0;
}