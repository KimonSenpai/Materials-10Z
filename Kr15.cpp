#include <iostream>
using namespace std;

int main(){
    int k1, k3, k5, k15;
    k1 = k3 = k5 = k15 = 0;
    int count = 0;
    
    //break - Выход из ближайшего цикла
    //continue - переход к следующей итерации

    while(true){
        int a;
        cin >> a;
        /*if(a == 0)
            break;*/
        if(a == 0)
            goto END;
        if(a%15 == 0){
            count += k1 + k3 + k5 + k15;
            k15++;
        } else if(a%5 == 0) {
            count += k3 + k15;
            k5++;
        } else if(a%3 == 0) {
            count += k5 + k15;
            k3++;
        } else {
            count += k15;
            k1++;
        }
    }
END:
    //cout << k3*k5 + k15*k1 + k15*k3 + k15*k5 + k15*(k15-1)/2;
    cout << count << '\n';
}