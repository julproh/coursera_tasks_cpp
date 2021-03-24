#include <iostream>
#include <vector>

using namespace std;

int main () {

    int n;
    long long sum = 0;
    cin >> n;
    vector <int> v(n);
    for (int i=0; i < n; i++ ) {
        int x;
        cin >> x;
        v[i] = x;
        sum += x;
    }
    int avg = sum/ n;
    int k = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] > avg) k++; 
    }
    cout << k << endl;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] > avg) 
            cout << i << " ";
    }
    cout << endl;
    return 0;
}