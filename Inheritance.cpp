#include <iostream>

class A {
public:
    int pub;

    void f() {
        //pub, prot, priv
    }
protected:
    int prot;
private:
    int priv;
};

class B: public A {
public:
    void g(){
        //pub, prot
        //dynamic_cast<A*>(this)->priv = 2;
    }
};


int main() {
    //pub
}