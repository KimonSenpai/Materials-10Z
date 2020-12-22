#pragma once
#include <string>
using namespace std;

class Animal {
public:
    static string Planet;
    double Height;
    virtual string Voice() = 0;
};

