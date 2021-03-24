#include <iostream>
#include <vector>

using namespace std;

int main() {

    long long N;
    long long R;
    uint64_t massa = 0;
    cin >> N >> R;
    for (int i = 0; i < N; i++)
    {   
        int width, hight, deep;
        cin >> width >> hight >> deep;
        massa+=static_cast<uint64_t>(width)*static_cast<uint64_t>(hight)*static_cast<uint64_t>(deep)*static_cast<uint64_t>(R);
    }
    cout << massa << endl;
    return 0;
}