#pragma once
#include "Currency.h"
class Euro :
    public Currency
{
public:
    std::string Name();
    double InRubles();
};

