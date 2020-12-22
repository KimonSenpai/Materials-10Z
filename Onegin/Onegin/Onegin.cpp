// Onegin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"



int main()
{
    clock_t f1, f2, s1, s2;

    ifstream in;
    f1 = clock();
    in.open("Onegin.txt");
    in.seekg(0, ios_base::end);
    size_t n = (size_t)in.tellg() + 2;
    in.seekg(0, ios_base::beg);
    char* buf = new char[n];
    in.read(buf, n);
    buf[n - 1] = '\0';
    f2 = clock();
    in.close();



    in.open("Onegin.txt");
    s1 = clock();
    while (!in.eof()) {
        in >> buf;
    }
    s2 = clock();
    in.close();

    cout << f2 - f1 << '\t' << s2 - s1 << '\n';

    Func p = cmp;
#pragma region MyRegion



    //int mas[5] = { 1, 3, 2, 4 };
    //void* p = mas;

    //int (*f)(const void*, const void*);

    //f = cmp;
    //cout << MUL(5 + 3, 5 + 3) << '\n';//5+3*5+3
    //cout << f(mas, mas + 1) << '\n';
    //qsort(mas, 5, sizeof(int), cmp);

    //for (auto x : mas) {
    //    cout << x << ' ';
    //}
    //cout << '\n';
    //std::cout << "Hello World!\n";
#pragma endregion
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
