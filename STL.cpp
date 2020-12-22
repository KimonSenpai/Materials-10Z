//STL -- standart template libraries

template<typename T, typename TT>
struct Pair{
    T first;
    TT second;
};

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <array>
using namespace std;

int main(){
    array<int, 10> arr; //int arr[10];
    auto b = arr.begin();
    array<int, 10>::iterator e = arr.end();
    
    for(int i = 0; i < arr.size(); i++)
        arr[i] = i;
    
    for(auto p = arr.begin(); p < arr.end(); p++){
        *p = 0;
    }

    //int* mas = new int[20];

    for(int v: arr){
        cout << v << '\n';
    }

    for(int& v: arr){
        v = 9;
    }

    stack<int> s;
    s.push(6);
    s.pop();
    //s.top();
    s.size();

    queue<int> q;
    q.push(6);
    q.pop();
    //q.front();


    vector<int> mas(20, 0);
    mas.push_back(5);
    mas.resize(20, 0);
    
    mas.erase(mas.begin() + 5, mas.begin() + 10);
    mas.insert(mas.begin() + 5, arr.begin(), arr.end());

    mas.at(5);//mas[5];

    set<int> s1;
    s1.lower_bound(4);
    s1.count(2);

    map<char, int> m;
    m['a'] = 7;
    m['b'] = m['c'];
    auto p = m.begin();
    for(; p != m.end(); p++ )
        cout << (*p).first << ' ' << p->second << '\n';
    list<int> l;
    
}
/*
Stack<int> a;

push(a, 5);

pop(a);//с возвратом значения
*/