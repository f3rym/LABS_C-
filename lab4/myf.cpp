#include "header.h"

void waitForAnyKey()
{
    std::cout << "\nНажмите любую клавишу для продолжения...";
    _getch();
    system("cls");
}

int againProg()
{
    int again;
    std::cout << "\nСнова? \033[32mДа - 1\033[0m. \033[31mНет - 0 \033[0m:\t";
    while (1)
    {
        std::cin >> again;
        if ((again != 0 && again != 1))
        {
            std::cout << "\033[31mОшибка. Переход к завершению...\033[0m";
            rewind(stdin);
            again = 0;
            return again;
        }
        else
            break;
    }
    return again;
}