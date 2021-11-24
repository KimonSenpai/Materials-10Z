#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<int> mas;
    ifstream in("17.txt");
    while(!in.eof()) {
        int n;
        in >> n;
        mas.push_back(n);
    }

    int count = 0, minDif = 20001;

    for(int i = 1; i < mas.size() - 1; i++) {
        if(mas[i-1] < mas[i] && mas[i] < mas[i+1]) {
            count++;
            minDif = min(minDif, mas[i+1] - mas[i-1]);
        }
    }

    cout << count << ' ' << minDif << '\n';
}