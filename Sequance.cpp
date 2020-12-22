#include <iostream>
using namespace std;

main(){
    int a, sum = 0, n = 0;
    
    while(cin >> a, a){
        sum += a;
        n++;
    }
    n++;
    int s = n*(n+1)/2;
    cout << s - sum << '\n';
}
