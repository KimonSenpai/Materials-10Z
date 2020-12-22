#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insert_heap(int* begin, int* end){
    int n = end - begin;
    begin--;
    for(int i = n; i > 0; i = i/2){
        if(begin[i] < begin[i/2])
            break;
        swap(begin[i], begin[i/2]);
    }
}

void heapify(int* begin, int* end){
    int n = end - begin;
    begin--;
    int i = 1;
    while(true){
        if(2*i > n || begin[2*i] < begin[i] && 2*i + 1 > n || begin[i] > max(begin[2*i], begin[2*i + 1]))
            break;
        if(2*i + 1 > n || begin[2*i] > begin[2*i+1]){
            swap(begin[2*i], begin[i]);
            i = 2*i;
        }
        else{
            swap(begin[2*i + 1], begin[i]);
            i = 2*i + 1;
        }
    }
}

void sort(int* begin, int* end){
    for(int* p = begin + 1; p <= end; p++)
        insert_heap(begin, p);
    //cout << "--------\n";
    for(int* p = end-1; p > begin+1; p--){
        swap(*p, *begin);
        heapify(begin, p);
    }
}

const int n = 20;

int main(){
    int* mas = new int[n];
    srand(time(nullptr));
    for(int i = 0; i < n; i++){
        mas[i] = rand()%200;
        cout << mas[i] << '\t';
    }
    sort(mas, mas + n);
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << mas[i] << '\t';
    }
}