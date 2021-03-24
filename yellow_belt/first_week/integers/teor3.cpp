#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

    vector <int> x = {4, 5};
    for (size_t i = 0; i < x.size(); i++) {
        cout << i << " " << x[i] << endl;
    }
    // for (int i = 0; i < static_cast<int>(x.size()); i++) {
    //     cout << i << " " << x[i] << endl;
    // }

    vector <int> v = {1, 4, 6};
    for (size_t i = 0; i < v.size() - 1; i++) {
        cout << v[i] << endl;
    }

    vector <int> v1;
    // for (size_t i = 0; i < v1.size() - 1; i++) { // плохо выйдем за тип
    //     cout << v[i] << endl;
    // }
    for (size_t i = 0; i+1 < v1.size(); i++) { // хорошо
        cout << v[i] << endl;
    }

    for (size_t i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << endl;
    }

    for (size_t k = v.size(); k > 0; k--) {
        size_t i = k -1;
        cout << v[i] << endl;
    }

    return 0;
}