#include "Student.h"

Student::Student(const Student& s)
{
    name = s.name;
    grade = s.grade;
    //....//
}

bool Student::SetMath(int mark) {
    if (mark > 5 || mark < 1)
        return false;
    math = mark;
    return true;
}

int Student::GetMath() const {
    return math;
}

int Student::operator[](string subj)
{
    if (subj == "math")
        return math;
    if (subj == "phys")
        return phys;
    if (subj == "inf")
        return inf;
    return 0;
}

ostream& operator<<(ostream& out, const Student& student) {
    out << student.name << '(' << student.grade << student.letter << ")\nM: " << student.math << "\tP: " << student.phys << "\tI: " << student.inf;
    return out;
}

int Student::co = 0;