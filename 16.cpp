#include <iostream>

int F(int n) {
    if(n <= 3)
        return 3;
    if(n%2 == 1)
        return F(n-1) - F(n-2);
    return F(n/2) + 5;
}


int main() {
    std::cout << F(20) << '\n';
}