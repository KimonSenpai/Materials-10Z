#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

class C;

class A {
protected:
    int a;

public:
    virtual void print() {
        cout << "A\n";
    }
    A() {
        cout << "Constuct A\n";
    }
    ~A() {
        cout << "Destruct A\n";
    }
};

class B: public A {
protected:
    int b;

public:
    static C obj;
    void print() {
        cout << "B\n";
    }

    B() {
        cout << "Constuct B\n";
    }
    ~B() {
        cout << "Destruct B\n";
    }
};


class C {
protected:
    int c;

public: 
    
    C() {
        cout << "Constuct C\n";
    }
    ~C() {
        cout << "Destruct C\n";
    }
};

class D: public B, public C {
public:
    int d;
    A obj;
    static B obj2;
    int g() {
        a = 7;
        return a; 
    }

    D(): obj(), d(3) {
        d = 3;
        cout << "Constuct D\n";
    }
    ~D() {
        cout << "Destruct D\n";
    }
};

B D::obj2;
C B::obj;

class Func_t {
public:
    double operator()(double x) {
        return x*x;
    }
};

int main() {
    D d;
    //d.print();
#pragma region Commented

/*
    A* a = new A;// a->print(); ~ (*a).print()
    B* b = new B;
    A* ab = new B;

    a->print();
    b->print();
    ab->print();
    */
#pragma endregion

    Func_t f;
    double a = f(5);

    function<int(int, int)> g = [d, &a](int x, int y){return x*y;};
    cout << g(6, 3) << '\n';

    int* mas = new int[20];
    for(int i = 0; i < 20; i++)
        mas[i] = i*i;
    
    bool flag = false;
    sort(mas, mas + 20, [flag](int a, int b){ return (flag ? a%10 < b%10 : a%10 > b%10); });

    for(int i = 0; i < 20; i++)
        cout << mas[i] << ' ';

    cout << '\n';


    //int b = (d.d = 5)?5:3;
}