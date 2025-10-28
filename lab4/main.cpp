#include "header.h"
#include "header/ComputingMachine.h"
#include "header/interface.h"

#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Interface<ComputingMachine> app;
    int again = 1;
    int m;
    while (again)
    {
        app.menu();
        again = againProg();
    }
}