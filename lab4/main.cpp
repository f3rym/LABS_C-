#include "header.h"
#include "header/ComputingMachine.h"
#include "header/laptop.h"
#include "header/mono.h"
#include "header/portableMachine.h"
#include "header/stationaryMachine.h"
#include "header/Tablet.h"
#include "header/interface.h"

#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Interface app;
    int again = 1;
    int m;
    while (again)
    {
        int choice;
        while (choice != 0)
        {
            std::cout << "=========================================" << std::endl;
            std::cout << "1. Работа с моноблоками" << std::endl;
            std::cout << "2. Работа с ноутбуками" << std::endl;
            std::cout << "3. Работа с планшетами" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "=========================================" << std::endl;
            std::cin >> choice;
            switch (choice)
            {
            case 0:
                break;
            case 1:
                app.mn_menu();
                waitForAnyKey();
                break;
            case 2:
                app.laptops_menu();
                waitForAnyKey();
                break;
            case 3:
                app.tablets_menu();
                waitForAnyKey();
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
            }
        }
        again = againProg();
    }
}