#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, y;
    cin >> x >> y;
    if(abs(y) >= x*x && x*x + y*y <= 25)
        cout << "In\n";
    else
        cout << "Out\n";
    
    
