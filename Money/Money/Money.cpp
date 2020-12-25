#include "Money.h"

Money::Money(int banknotes, int coins, Currency* cur) : banknotes(banknotes), coins(coins), cur(cur)
{
}

Money Money::operator+(const Money& amount) const
{
    Money m = Currency::Convert(amount.cur, cur, amount);
    m.coins += coins;
    m.banknotes += banknotes;
    m.banknotes += m.coins / 100;
    m.coins %= 100;
    return m;

}

int Money::GetBanknotes() const
{
    return banknotes;
}

int Money::GetCoins() const
{
    return coins;
}

std::ostream& operator<<(std::ostream& out, const Money& money)
{
    out << money.banknotes << '.' << money.coins << ' ' << money.cur->Name();
    return out;
}