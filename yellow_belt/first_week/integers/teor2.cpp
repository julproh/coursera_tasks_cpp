#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

    cout << numeric_limits<int>::max() + 1 << endl;
    cout << numeric_limits<int>::min() - 1 << endl;// переполнение
    //////////////
    int x = 2'000'000'000;
    int y = 1'000'000'000;
    cout << (x+y)/2 << endl;

    int x_ = -2'000'000'000;
    unsigned int y_ = x_;
    cout << x_ << " " << y_ << endl;
    ////////////////////
    vector <int> t = {-8, -7, 3};
    int sum  =0;
    for (int x : t) {
        sum += x;
    }
    // int avg = sum / t.size() + vector<int>{}; // вызываем ошибку компиляции
    int avg = sum / static_cast<int>(t.size());
    cout << avg << endl;

    // int / size_t -> size_t
    // int32_t + int8_t -> int32_t
    // int8_t * uint8_t -> int
    // int32_t < uint32_t -> uint32_t

    /////////////////////
    int a = -1;
    unsigned b = 1;
    cout << (a < b) << endl;   
    cout << (-1 < 1u) << endl;

    return 0;
}