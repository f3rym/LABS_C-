#include "../header.h"
#include "../header/ExpInput.h"

int ExpInput::isNumber(std::istream &input)
{
    while (true)
    {
        try
        {
            int num;
            std::cout << "(ожидается число): ";

            if (input >> num)
            {
                if (input.peek() != '\n' && input.peek() != EOF)
                {
                    input.clear();
                    input.ignore(INT_MAX, '\n');
                    throw ExpInput(", число введено не корректно", 3);
                }
                input.ignore(INT_MAX, '\n');
                if (num > INT_MAX || num < INT_MIN)
                {
                    throw ExpInput(", значение вышло за границы", 2);
                }

                return num;
            }
            else
            {
                input.clear();
                input.ignore(INT_MAX, '\n');

                throw ExpInput(", введено не число", 1);
            }
        }
        catch (const ExpInput &e)
        {
            std::cout << e.message << e.err << " [ code: " << e.code << " ]" << std::endl;
        }
    }
}

int ExpInput::isNumber(std::istream &input, int minInt, int maxInt)
{
    while (true)
    {
        try
        {
            int num;
            std::cout << "(ожидается число): ";

            if (input >> num)
            {
                if (input.peek() != '\n' && input.peek() != EOF)
                {
                    input.clear();
                    input.ignore(INT_MAX, '\n');
                    throw ExpInput(", число введено не корректно", 3);
                }
                input.ignore(INT_MAX, '\n');
                if (num >= maxInt || num <= minInt)
                {
                    throw ExpInput(", значение вышло за заданные границы", 12);
                }

                return num;
            }
            else
            {
                input.clear();
                input.ignore(INT_MAX, '\n');

                throw ExpInput(", введено не число", 1);
            }
        }
        catch (const ExpInput &e)
        {
            std::cout << e.message << e.err << " [ code: " << e.code << " ]" << std::endl;
        }
    }
}

bool ExpInput::isBool(std::istream &input)
{
    while (true)
    {
        try
        {
            bool var;
            std::cout << "(ожидается 0 или 1): ";

            if (input >> var)
            {
                input.ignore(INT_MAX, '\n');
                return var;
            }
            else
            {
                input.clear();
                input.ignore(INT_MAX, '\n');
                throw ExpInput(", введено не bool", 4);
            }
        }
        catch (const ExpInput &e)
        {
            std::cout << e.message << e.err << " [ code: " << e.code << " ]" << std::endl;
        }
    }
}

std::string ExpInput::isString(std::istream &input)
{
    while (true)
    {
        try
        {
            char str[MAX_STR];
            std::cout << "(ожидается строка): ";
            input.getline(str, MAX_STR);
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
            input.clear();
        }
    }
}

std::string ExpInput::isStringWithNumbers(std::istream &input)
{
    while (true)
    {
        try
        {
            char str[MAX_STR];
            std::cout << "(ожидается строка с использ. цифр): ";
            input.getline(str, MAX_STR);

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
                        !(c >= '0' && c <= '9') &&
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
            input.clear();
        }
    }
}