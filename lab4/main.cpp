#include "header.h"
#include "header/ComputingMachine.h"
#include "header/laptop.h"
#include "header/mono.h"
#include "header/portableMachine.h"
#include "header/stationaryMachine.h"
#include "header/Tablet.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int again = 1;
    while (again)
    {
        system("cls");
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
                mn_menu();
                waitForAnyKey();
                break;
            case 2:
                lap_menu();
                waitForAnyKey();
                break;
            case 3:
                tab_menu();
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