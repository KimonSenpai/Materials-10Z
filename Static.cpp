#include <string>
#include <iostream>
using std::cout;
using std::string;

class Animal {
public:
    Animal(){
        Planet = "";
    }
    static string Planet;
    //static int N;
};

string Animal::Planet("Earth");
int main() {
    Animal a, b;
    //a.N = 4;
    cout << Animal::Planet << "--------\n";
    a.Planet = "Earth";
    b.Planet = "Mars";
    cout << a.Planet << ' ' << b.Planet << '\n';
}