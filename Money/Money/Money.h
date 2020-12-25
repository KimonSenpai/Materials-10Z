#pragma once
#include <iostream>
#include "Currency.h"
class Currency;
class Money
{
private:
    int coins;
    int banknotes;
    Currency* cur;
public:
    Money(int banknotes, int coins, Currency* cur);

    Money operator+(const Money&) const;

    friend std::ostream& operator<<(std::ostream& out, const Money& money);

    int GetBanknotes() const;
    int GetCoins() const;
};

