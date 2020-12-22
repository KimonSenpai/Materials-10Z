#include <iostream>
using namespace std;

struct S{
    char a;
    int b;
    int c;
    int e;
    long long d;
};

int main(){
    S val;
    cout << sizeof(val) << '\n';
    cout << sizeof(val.a) + sizeof(val.b) 
            + sizeof(val.c) + sizeof(val.d) + sizeof(val.e) << '\n';
}