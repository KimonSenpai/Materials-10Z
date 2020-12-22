#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int aa = 7;
    int* b = &a;

    cout << b << '\n';
    cout << sizeof(b) << '\n';
    cout << *b  << '\n' << &aa<< '\n';
    cout << *(b-1) << '\n';
    b = NULL;
    b = nullptr;

    //Arrays
    const int N = 20;
    int mas[N];

    int n;
    cin >> n;
    int * mas2 = new int[n + 3];
    mas2 += 3;
    delete[] mas2;

    int matr[N][M];

    int ** matr2 = new int*[N];
    
}