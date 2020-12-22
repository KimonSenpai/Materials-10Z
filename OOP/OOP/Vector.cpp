#include "Vector.h"
Vec Vec::operator+(Vec v) {
    return { x + v.x, y + v.y };
}

Vec::Vec(initializer_list<int> a) {
    if (a.size() > 2 || a.size() < 2)
        throw 1;
    x = *a.begin();
    y = *(a.begin() + 1);
}