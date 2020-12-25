#include "Currency.h"

Money Currency::Convert(Currency* from, Currency* to, const Money& amount)
{
    int coins = amount.GetBanknotes() * 100 + amount.GetCoins();
    coins = static_cast<int>(coins * from->InRubles() / to->InRubles());
    return Money(coins / 100, coins % 100, to);
}
