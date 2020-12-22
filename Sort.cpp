#include <iostream>
#include <queue>
using namespace std;

void SelectSort(int* beg, int* end){
    for(int* i = beg; i < end - 1; i++)//O(1 + 2 + ... + n) = O(n(n-1)/2) = O(n^2)
        for(int* j = i + 1; j < end; j++)//(n-i)O(1) = O(n - i)
            if(*i > *j)//O(1)
                swap(*i, *j);//O(1)
}
queue<int> Merge(int* beg, int* end){
    if(end - beg == 1){
        return queue<int>({*beg});
    }

    int* mid = beg + (end - beg)/2;
    queue<int>
        left = Merge(beg, mid),
        right = Merge(mid, end);

    queue<int> res;
    while(!left.empty() && !right.empty()) {
        if(left.front() < right.front()){
            res.push(left.front());
            left.pop();
        } else {
            res.push(right.front());
            right.pop();
        }
    }
    while(!left.empty()){
        res.push(left.front());
        left.pop();
    }
    while(!right.empty()){
        res.push(right.front());
        right.pop();
    }
    return res;
}

void MergeSort(int* beg, int* end){
    queue<int> res = Merge(beg, end);
    for(int* v = beg; v < end; v++){
        *v = res.front();
        res.pop();
    }
}


int main(){
    int mas[10] = {5, 3, 7, 1, 9, 8, 4, 0, 2, 6};
    SelectSort(mas, mas + 10);
    for(auto v: mas)
        cout << v << ' ';
    cout << '\n';

    int mas2[10] = {5, 3, 7, 1, 9, 8, 4, 0, 2, 6};
    MergeSort(mas2, mas2 + 10);
    for(auto v: mas2)
        cout << v << ' ';
    cout << '\n';
}

