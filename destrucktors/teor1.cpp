#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Route {
public:
    Route () {
        source = "Moscow";
        destination = "Ivanovo";
        UpdateLength;
    }
    Route (
    const string& new_source, 
    const string& new_destination) {
        source = new_source;
        destination = new_destination;
        UpdateLength();
    }
    ~Route () {
        for (const string& entry : compute_distance_log) {
            cout << entry << endl;
        }
    }
    string GetSource() const {return source;}
    string GetDestination() const {return destination;}
    int GetLength()const {return length;}
    void SetSource (const string& new_source) {
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
    vector <string> compute_distance_log;
    void UpdateLength() {
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(
            source + " - " + destination
        );
    }
};

int ComputeDistance(const string& source, const string& destination);

Route BuildRoute (
    const string& source, 
    const string& destination) {
        Route route (source, destination);
        route.SetSource(source);
        route.SetDestination(destination);
        return route;
    } //вместо этого есь конструкторы


int main () {
    Route route ("Zvenigorod", "Istra");
    route.SetSource("Moscow");
    route.SetDestination("Dubna");
    cout << "Rout from" <<
    route.GetSource() << " to " << route.GetDestination() <<" is "
    << route.GetLength() << "meters long";
    
    return 0;
}