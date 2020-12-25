#pragma once
#include <string>
#include "Money.h"
class Money;
class Currency
{
public:
    virtual std::string Name() = 0;
    static Money Convert(Currency* from, Currency* to, const Money& amount);
    virtual double InRubles() = 0;
};

