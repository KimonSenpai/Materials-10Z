#include <iostream>
#include <cmath>
using namespace std;

void old_swap(int*, int*);//definition
//int Add(int a, int b, int c );
int fact(int n){
    if(n < 2)
        return 1;
    return n*fact(n-1);
}
int* search(int* begin, int* end, int elem){
    if(end - begin < 2)
        return (*begin == elem ? begin : nullptr);//a if a != 0 else b
    int* mid = begin + (end - begin)/2;
    if(*mid > elem)
        return search(begin, mid, elem);
    return search(mid, end, elem);
}

void print(int n ...){
    int* mas = &n + 2;
    for(int i = 0; i < n; i++)
        cout << mas[i*2] << ' ';
    cout << '\n';

}

template<typename T, typename T2 = int>
void new_swap(T& a, T& b){
    T t = a;
    a = b;
    b = t;
}

double my_sin(double alpha, int n);

int main(){
    double x = 2;
    double y = 5;
    new_swap(x, y);
    new_swap<double>(x, y);
    for(int i = 2; i < 10; i++){
        cout << i << '\t' << my_sin(x, i) << '\t' << sin(x) << '\n';
    }

    int mas[10]{1,2,4,5,7,8,9,12,13,16};

    auto p = search(mas, mas + 10, 6);
    if(p)
        cout << p - mas << '\n';
    else
        cout << "Not found\n";
    
    print(5, 1, 2, 3, 4, 5);
    
}

double my_sin(double alpha, int n){//sin(x) = x - x^3/3! + x^5/5! - ...
    double x = alpha, factor = 1, sign = 1;
    double res = x;
    for(int i = 3;i < 2*n; i += 2){
        x *= alpha*alpha;
        factor *= i*(i-1);
        sign = -sign;
        res += sign*x/factor;
    }
    return res;
}

/*int Add(int a, int b = 1, int c = 0){
    return a + b + c;
}*/



void f(int b){

    return;
}

void f(double b){

}

long f(long){
    return 0;
}
/*
int f(int a){

}
*/
void swap(int a, int b){
    int t = a;
    a = b;
    b = t;
}

void old_swap(int* a, int* b){//declaration
    int t = *a;
    *a = *b;
    *b = t;
}

