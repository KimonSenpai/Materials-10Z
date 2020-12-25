#pragma once
#include "Currency.h"
class Dollar :
    public Currency
{
public:
    std::string Name();
    double InRubles();
};

