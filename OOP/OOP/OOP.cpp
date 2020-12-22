// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "Student.h"
using std::cout;

//int c = 0;
int count() {
    static int c = 0;
    return ++c;
}

int main()
{
    /*
    Student s("Ivanov", 5, 'E');
    const Student s2("Petrov", 7, 'G');
    Student s3 = s2;
    s.SetMath(4);
    cout << s["math"] << '\n';
    cout << s << '\n';
    */
    int mas[1000000000];
    Vec a{ 1,3 }, b{ 5,7 };
    //Vec d;
    Vec c = a + b;
    cout << c.x << ' ' << c.y << '\n';

   /* cout << count();
    cout << ' ' << count();
    cout << ' ' << count() << '\n';*/
    switch (count()) {
        int d;
        c.x = 7;
    case 1:
        d = 2;
        cout << 1 << ' ' << d << '\n';
        break;
    case 2:
        cout << 2;
        break;
    default:
        cout << "Many";
        break;
    case 4:
        cout << 4;
        break;
    }
    cout << c.x << ' ' << c.y << '\n';
    cout << Student::Count() << '\n';
    Student* obj = new Student("Kim", 11, 'I');
    cout << Student::Count() << '\n';
    delete obj;
    cout << Student::Count() << '\n';

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
