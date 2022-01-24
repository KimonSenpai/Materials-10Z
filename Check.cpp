#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isS(char c){
    return c == '+'||c == '-'||c == '*'||c == '/';
}

bool check(char* str) {
    char* p = str;
q_0:
    if(*p == '+' || *p == '-') {
        p++;
        goto q_1;
    }
    if(isdigit(*p)) {
        p++;
        goto q_2;
    }
    return false;

q_1:
    if(isdigit(*p)) {
        p++;
        goto q_2;
    }
    return false;
q_2:
    if(isdigit(*p)) {
        p++;
        goto q_2;
    }
    if(isS(*p)) {
        p++;
        goto q_0;
    }
    if(*p == '.') {
        p++;
        goto q_3;
    }
    if(*p == '\0'){
        return true;
    }
    return false;
q_3:
    if(isdigit(*p)) {
        p++;
        goto q_4;
    }
    return false;
q_4:
    if(isdigit(*p)) {
        p++;
        goto q_4;
    }
    if(isS(*p)) {
        p++;
        goto q_0;
    }
    if(*p == '\0') {
        return true;
    }
    return false;
}


int main() {
    char str[256];

    cin >> str;

    cout << check(str) << '\n';
}