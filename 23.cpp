#include <iostream>

int f(int n) {
    if(n == 1) return 1;
    int res = f(n-1);
    if(n%2 == 0 && !(n/2 < 12 && n > 12))
        res += f(n/2);
    
    return res;
}

int main() {
    std::cout << f(30) << '\n';
}