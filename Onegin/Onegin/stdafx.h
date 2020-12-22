#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "Header.h"
using namespace std;

#define G 9.81
#define MUL(a, b) (a)*(b)
#define swap(T, a, b) \
    T tmp = a;\
    a = b;\
    b = tmp;

typedef int (*Func)(const void* , const void* );

//макроподстановка (макрос)
#define _DEBUG_
//#undef _DEBUG_

int cmp(const void* a, const void* b);

#if defined(_DEBUG_)


#else

#endif // _DEBUG_

//#include "Header.h"