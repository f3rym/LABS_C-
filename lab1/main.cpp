#include "intersectionArrays.h"
#include <locale>
#include <codecvt>
int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int again = 1;
    while (again)
    {
        menu();
        again = againProg();
    }
}