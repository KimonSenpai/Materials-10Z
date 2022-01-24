#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* mas = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int* Sqrt = new int[(int)ceil(sqrt(n))]{};
    int L = sqrt(n);
    for(int i = 0; i < n; i++){
        Sqrt[i/L] += mas[i];
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        int res = 0;
        while(l%L != 0 && l < r) {
            res += mas[l];
            l++;
        }
        while((r)%L != 0 && l < r) {
            res += mas[r-1];
            r--;
        }
        for(int j = l/L; j < r/L; j++) {
            res += Sqrt[j];
        }
        cout << res << '\n';
    }
}