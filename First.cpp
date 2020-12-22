#include <iostream>
using std::cout;
//using namespace std;
namespace My{
    int a = 8;
}
int b = 0;
int main(int argc, char* argv[]){
    int b = 3;
    cout << "Hello world!\n";
    cout << ::b << '\n';
    cout << b;
    return 0;
}

