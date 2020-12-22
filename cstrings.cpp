#include <iostream>
#include <cstring>//https://www.cplusplus.com/reference/cstring/
#include <cctype>//C char type
#include <fstream>
using namespace std;

int main(){
    char str[256] = "Hello wor";
    strcpy;//string copy
    strcat;//конкатенация строк
    strlen;
    strcmp;//|str1|-|str2|
    cout << "1\t2\n" << "100\t200\n";
    cout << strlen(str) << '\n';
    strcat(str, "ld");
    cout << str << '\n';
    cout << strcmp("123", "1235") << '\n';
    //cin >> str;
    //cin.getline(str, 256);
    //cout << str;
    /*islower;
    isupper;
    isalpha;
    isdigit;
    isspace;
    tolower;
    toupper;*/
    isalpha(str[1]);


    ifstream fin;
    fin.open("in.txt", ios::in|ios::binary);
    int a, b;
    //fin >> a >> b;
    //cout << a << '\t' << b << '\n';

    fin.eof();//end of file. true -- мы в конце файла.
    cout << fin.eof() << '\n';
    fin.seekg(0, ios_base::end);
    fin.get();
    cout << fin.eof() << '\n';
    fin.tellg();


    fin.seekg(0, ios_base::end);
    int n = (int)fin.tellg() + 1;
    fin.seekg(0, ios_base::beg);
    char* buf = new char[n+1];
    fin.read(buf, n);
    buf[n] = '\0';
    

    fin.close();

}