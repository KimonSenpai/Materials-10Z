// Money.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Money.h"
#include "Dollar.h"
#include "Euro.h"
#include "Ruble.h"

int main()
{
    std::cout << sizeof(Dollar) << '\n';
    Money a(12, 25, new Dollar), b(15, 20, new Euro), c(100, 0, new Ruble);
    std::cout << a + b + c;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


