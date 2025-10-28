#include "../header.h"
#include "../header/ExpInput.h"
#include <limits>

int ExpInput::isNumber()
{
    while (true)
    {
        try
        {
            int num;
            std::cout << "(ожидается число): ";

            if (std::cin >> num ) //ДОДЕЛАЙ МАКС ИНТ МИН ИНТ И ЧТОБЫ ПРОВЕРЯЛОСЬ ЧТО ЧИСЛО БЕЗ МУСОРА
            {
                std::cin.ignore(INT_MAX, '\n');
                return num;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');

                throw ExpInput(", введено не число", 1);
            }
        }
        catch (const ExpInput &e)
        {
            std::cout << e.message << e.err << " [ code: " << e.code << " ]" << std::endl;
        }
    }
}
bool ExpInput::isBool()
{
    while (true)
    {
        try
        {
            bool var;
            std::cout << "(ожидается 0 или 1): ";

            if (std::cin >> var)
            {
                std::cin.ignore(INT_MAX, '\n');
                return var;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                throw ExpInput(", введено не bool", 2);
            }
        }
        catch (const ExpInput &e)
        {
            std::cout << e.message << e.err << " [ code: " << e.code << " ]" << std::endl;
        }
    }
}

std::string ExpInput::isString()
{
    while (true)
    {
        try
        {
            char str[MAX_STR];
            std::cout << "(ожидается строка): ";
            std::cin.getline(str, MAX_STR);
            if (str[0] == '\0')
            {
                throw ExpInput(", строка пуста", 3);
            }
            else
            {
                return str;
            }
        }
        catch (const ExpInput &e)
        {
            std::cout << e.message << e.err << " [ code: " << e.code << " ]" << std::endl;
            std::cin.clear();
        }
    }
}
