#pragma once
#include <initializer_list>
using std::initializer_list;
class Vec {
public:
    int x, y;

    Vec operator+(Vec v);
    Vec(initializer_list<int> a);
};

