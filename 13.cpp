#include <iostream>
#include <string>
#include <map>
using namespace std;
struct FullName { 
    string Name;
    string Soname;
};
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Soname = "";
        YearNameSoname[year].Name = first_name; 
    }
    void ChangeLastName(int year, const string& last_name) {
        if (YearNameSoname.count(year) == 0) YearNameSoname[year].Name = ""; 
        YearNameSoname[year].Soname = last_name; 
    }
    string GetFullName(int year) {
        if (YearNameSoname.size() == 0) {
            return "Incognito"; 
        }
        else { 
            for (const auto& i : YearNameSoname) {
                if (year < i.first) return "Incognito"; 
                break; 
            }
        }
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname) { 
            if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
            if (i.first <= year && i.second.Name != "") nm = i.second.Name;
        }
        if(nm == "") return sn + " with unknown first name"; 
        else if(sn == "") return nm + " with unknown last name";
        else return nm + " " + sn; 
    }
private: 
    map<int, FullName> YearNameSoname; 
};