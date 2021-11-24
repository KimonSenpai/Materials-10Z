#include <iostream>
using namespace std;

int main() {
    int count = 0;
    for(long long val = 1 << 30; val < 1ll<<32; val++)
        if(val%10 == 5)
            count++;
    cout << count << '\n';
}