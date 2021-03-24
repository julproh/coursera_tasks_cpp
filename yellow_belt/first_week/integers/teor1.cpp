#include <iostream>
#include <vector>
#include <limits>

using namespace std;
// целочисленные типы
int main () {

    // vector <int> t = {-8, -7, 3};
    // int sum  =0;
    // for (int x : t) {
    //     sum += x;
    // }
    // int avg = sum / t.size();
    // cout << avg << endl;
    ///////////////////////////
    int x = 2'000'000'000;
    cout << x << " ";
    x *= 2;
    cout << x << endl;
    ///////////////////////////
    auto X =1; //  x -> int
    //usingned int // unsinged
    // size_t - тип для представления размеров
    // int8_t, uint8_t - 8 бит
    cout << sizeof(int16_t) << endl; // размер в байтах для этого типа
    cout << sizeof(int) << endl;
    ////////////
    cout << numeric_limits<int>::min()
    << " " << numeric_limits<int>::max() << endl;
    ////////////
    
    return 0;
}