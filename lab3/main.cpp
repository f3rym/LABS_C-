#include "header.h"
#include "header/computer.h"
#include "header/laptop.h"
#include "header/mono.h"
#include "header/portableMachine.h"
#include "header/stationaryMachine.h"




int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int again = 1;
    while (again)
    {
           
        again = againProg();
    }
}