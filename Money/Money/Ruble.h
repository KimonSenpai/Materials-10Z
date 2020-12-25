#pragma once
#include "Currency.h"
class Ruble :
    public Currency
{
public:
    std::string Name();
    double InRubles();
};

