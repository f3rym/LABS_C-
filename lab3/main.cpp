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
            std::cout << "      СИСТЕМА УПРАВЛЕНИЯ КОМПЬЮТЕРАМИ" << std::endl;
            std::cout << "=========================================" << std::endl;
            std::cout << "1. Работа с базовыми компьютерами" << std::endl;
            std::cout << "2. Работа с портативной машиной" << std::endl;
            std::cout << "3. Работа с стационарными машинами" << std::endl;
            std::cout << "4. Работа с моноблоками" << std::endl;
            std::cout << "5. Работа с ноутбуками" << std::endl;
            std::cout << "6. Работа с планшетами" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "=========================================" << std::endl;
            std::cin >> choice;
            switch (choice)
            {
            case 0:
                break;
            case 1:
                comp_menu();
                break;
            case 2:
                pm_menu();
                break;
            case 3:
                sm_menu();
                break;
            case 4:
                mn_menu();
                break;
            case 5:
                lap_menu();
                break;
            case 6:
                tab_menu();
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
            }
        }

        again = againProg();
    }
}