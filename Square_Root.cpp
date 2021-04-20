#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n==1){
        cout << 1 << '\n';
        return 0;
    }

    int l = 1,
        r = n;
    while(r - l > 1) {
        int mid = (l + r)/2;
        if(mid*mid <= n) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}