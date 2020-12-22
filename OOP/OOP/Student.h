#pragma once

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Student {
private:
    string name;
    int grade;
    char letter;
    int math, phys, inf;
    static int co;

public:
    Student(string name, int grade, char letter): phys(1), inf(1), letter(letter) {
        this->name = name;
        this->grade = grade;
        math = 1;
        co++;
    }

    static int Count() {
        return co;
    }

    Student(const Student& s);

    bool SetMath(int mark);
    int GetMath() const;

    friend ostream& operator<<(ostream& out, const Student& student);

    int operator[](string subj);

    ~Student() {
        co--;
    }
};

