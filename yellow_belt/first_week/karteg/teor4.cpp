#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Cities
{
private:
    map <string, string> city_to_country;
    set <string> ambiguous_cities;
public:
    Cities(/* args */){};
    ~Cities(){};
    tuple<bool, string> FindCountry(const string& city){
        if (city_to_country.count(city) == 1) {
            return {true, city_to_country.at(city)};
        }
        else if (ambiguous_cities.count(city) == 1) {
            return make_tuple(false, "Ambiguous");
        } else
        {
            return {false, "Not exist"};
        }
        
    };
};



int main() {
    Cities cities;
    auto t = cities.FindCountry("Volgograd");    
    cout << get<1>(t) << endl;
    //////////////

    //bool success;
    //string message;
    //tie(success, message) = cities.FindCountry("Volgograd"); 
    //    cout << success << " " << message << endl;

    ///////////////////
    auto [success, message] = cities.FindCountry("Volgograd");
    cout << success << " " << message << endl;

    map <string, pair<double,  double>> citiy;
    for (const auto& item : citiy)  {
        cout << item.second.first << endl;// так делать плохо 
    }

    return 0;
}