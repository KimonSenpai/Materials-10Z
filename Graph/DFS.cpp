#include <iostream>
#include <vector>
#include <set>
using namespace std;

void DFS(const vector<set<int>>& gr, int v, vector<bool>& mark) {
    if(mark[v]) return;

    mark[v] = true;

    for(int w: gr[v])
        DFS(gr, w, mark);
}

int main() {
    int n, e;
    vector<set<int>> gr(n + 1);
    vector<bool> mark(n+1);
    for(int i = 0; i < e; i++) {
        int f, t;
        cin >> f >> t;
        gr[f].insert(t);
        gr[t].insert(f);
    }
    int v;
    cin >> v;
    DFS(gr, v, mark);
    int count = 0;
    for(bool val: mark) if(val) count++;
    count--;
    cout << count << '\n';
}