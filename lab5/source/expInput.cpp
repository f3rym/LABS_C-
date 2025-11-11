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

            if (std::cin >> num) 
            {
                std::cin.ignore(INT_MAX, '\n');
                if (num > INT_MAX || num < INT_MIN)
                {
                    throw ExpInput(", значение вышло за границы", 2);
                }

                return num;
            }
            else if (std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');

                throw ExpInput(", число введено не корректно", 3);
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
                throw ExpInput(", введено не bool", 4);
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
                throw ExpInput(", строка пуста", 5);
            }
            else
            {
                for (int i = 0; str[i] != '\0'; i++)
                {
                    unsigned char c = str[i];
                    if (!(c >= 'a' && c <= 'z') &&
                        !(c >= 'A' && c <= 'Z') &&
                        c != ' ' && c != '\'' && c != '-')
                    {
                        if (c > 127)
                        {
                            throw ExpInput(", строка имеет не-ASCII символы", 6);
                        }
                        else
                        {
                            throw ExpInput(", строка содержит запрещенные символы", 8);
                        }
                    }
                }
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
