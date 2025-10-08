#include <iostream>
#include <locale>
#include <cstring>
#define MAX_STR 150

class String 
{
    char* str;
    int size;
public:
    String();
    String(int size);
    String(const String &other);
    ~String();
    friend std::ostream &operator<<(std::ostream &os, String &s);
    friend std::istream &operator>>(std::istream &os, String &s);
    String operator+(const String &other);
    String operator=(const String &other);
    String operator+=(const String &other);
    bool operator==(const String &other);
    bool operator!=(const String &other);
    bool operator>(const String &other);
    bool operator>=(const String &other);
    bool operator<(const String &other);
    bool operator<=(const String &other);
    String operator()(int start, int length);
    char operator[](int num);
};
void menu();
int againProg();
