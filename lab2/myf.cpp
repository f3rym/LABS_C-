#include "Str.h"

String::String()
{
    str = nullptr;
    size = 0;
}

String::String(int size)
{
    str = new char[size + 1];
    this->size = size;
}

String::String(const String &other)
{
    str = new char[other.size + 1];
    size = other.size;
    for (int i = 0; i < other.size; i++)
    {
        str[i] = other.str[i];
    }
}

String::~String()
{
    delete[] str;
}

std::ostream &operator<<(std::ostream &os, String &s)
{
    // for (int i = 0; i < s.size; i++)
    //     os << s.str[i];
    os << s.str;
    return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
    
    char temp[MAX_STR];
    is >> temp;
    delete[] s.str;
    s.size = std::strlen(temp);
    s.str = new char[s.size + 1];
    std::strcpy(s.str, temp);
    return is;
}
String String::operator+(const String &other)
{
    int newSize;
    newSize = size + other.size;
    String res(newSize);
    if (size > 0)
        std::strcpy(res.str, str);
    if (other.size > 0)
        std::strcat(res.str, other.str);
    return res;
}
String String::operator=(const String &other)
{
    if (this == &other)
        return *this;
    delete[] this->str;
    this->size = other.size;
    this->str = new char[size];
    std::strcpy(str, other.str);
    return *this;
}

String String::operator+=(const String &other)
{
    *this = *this + other;
    // this->size += other.size;
    // delete[] str;
    // str = new char[size];
    // if (size > 0)
    //     std::strcat(str, other.str);
    return *this;
}

bool String::operator==(const String &other)
{
    return std::strcmp(this->str, other.str) == 0;
}
bool String::operator!=(const String &other)
{
    return std::strcmp(this->str, other.str) != 0;
}
bool String::operator<(const String &other)
{
    return std::strcmp(this->str, other.str) < 0;
}
bool String::operator>(const String &other)
{
    return std::strcmp(this->str, other.str) > 0;
}
bool String::operator<=(const String &other)
{
    return std::strcmp(this->str, other.str) <= 0;
}
bool String::operator>=(const String &other)
{
    return std::strcmp(this->str, other.str) >= 0;
}
char String::operator[](int num)
{
    char res;
    if (num >= 1 && num <= size)
    {
        res = this->str[num - 1];
        return res;
    }
    return -1;
}
String String::operator()(int start, int length)
{
    String res(length);
    int pos = 0;
    if ((start <= size) && start > 0 && length <= (size - start))
    {
        for (int i = (start - 1); i < (length + start - 1); i++)
        {
            res.str[pos] = str[i];
            pos++;
        }
    }
    return res;
}

void menu()
{
    int var;
    char r;
    String s1, s2, s3;
    std::cout << "Ввод первой строки: ";
    std::cin >> s1;
    std::cout << "Ввод второй строки: ";
    std::cin >> s2;
    std::cout << "Ввод третьей строки: ";
    std::cin >> s3;
    bool result = (s3 += s1 + s2) == s3 && s1 != s2 && s3 > s2 && s1 <= s3 && s2[1] == 'a' && (s1(1, 3) + s2) == s3;
    if(result)
        std::cout << "Верно" << std::endl;
    else
        std::cout << "Неверно" << std::endl;

    // while (true)
    // {
    //     std::cout << "\n=== МЕНЮ КЛАССА STRING ===" << std::endl;
    //     std::cout << "1.  Создать первую строку" << std::endl;
    //     std::cout << "2.  Создать вторую строку" << std::endl;
    //     std::cout << "3.  Вывести первую строку" << std::endl;
    //     std::cout << "4.  Вывести вторую строку" << std::endl;
    //     std::cout << "5.  Сложение строк (s1 + s2)" << std::endl;
    //     std::cout << "6.  Присваивание (s1 = s2)" << std::endl;
    //     std::cout << "7.  Добавление строки (s1 += s2)" << std::endl;
    //     std::cout << "8.  Сравнение на равенство (s1 == s2)" << std::endl;
    //     std::cout << "9.  Сравнение на неравенство (s1 != s2)" << std::endl;
    //     std::cout << "10. Сравнение больше (s1 > s2)" << std::endl;
    //     std::cout << "11. Сравнение меньше (s1 < s2)" << std::endl;
    //     std::cout << "12. Сравнение больше или равно (s1 >= s2)" << std::endl;
    //     std::cout << "13. Сравнение меньше или равно (s1 <= s2)" << std::endl;
    //     std::cout << "14. Получить символ по индексу (s1[i])" << std::endl;
    //     std::cout << "15. Получить подстроку (s1(start, length))" << std::endl;
    //     std::cout << "16. Выйти" << std::endl;
    //     std::cout << "Выберите операцию: ";
    //     std::cin >> var;

    //     switch (var)
    //     {
    //     case 1:
    //     {
    //         std::cout << "Введите первую строку: ";
    //         std::cin >> s1;
    //         std::cout << "Строка создана: " << s1 << std::endl;
    //         break;
    //     }
    //     case 2:
    //     {
    //         std::cout << "Введите вторую строку: ";
    //         std::cin >> s2;
    //         std::cout << "Строка создана: " << s2 << std::endl;
    //         break;
    //     }
    //     case 3:
    //     {
    //         std::cout << "Первая строка: " << s1 << std::endl;
    //         break;
    //     }
    //     case 4:
    //     {
    //         std::cout << "Вторая строка: " << s2 << std::endl;
    //         break;
    //     }
    //     case 5:
    //     {
    //         s3 = s1 + s2;
    //         std::cout << "Результат сложения: " << s3 << std::endl;
    //         break;
    //     }
    //     case 6:
    //     {
    //         s1 = s2;
    //         std::cout << "Присваивание выполнено. s1 = " << s1 << std::endl;
    //         break;
    //     }
    //     case 7:
    //     {
    //         s1 += s2;
    //         std::cout << "Добавление выполнено. s1 = " << s1 << std::endl;
    //         break;
    //     }
    //     case 8:
    //     {
    //         if (s1 == s2)
    //         {
    //             std::cout << "Строки РАВНЫ" << std::endl;
    //         }
    //         else
    //         {
    //             std::cout << "Строки НЕ РАВНЫ" << std::endl;
    //         }
    //         break;
    //     }
    //     case 9:
    //     {
    //         if (s1 != s2)
    //             std::cout << "Строки НЕ РАВНЫ" << std::endl;
    //         else
    //             std::cout << "Строки РАВНЫ" << std::endl;
    //         break;
    //     }
    //     case 10:
    //     {
    //         if (s1 > s2)
    //             std::cout << "s1 БОЛЬШЕ s2" << std::endl;
    //         else
    //             std::cout << "s1 НЕ БОЛЬШЕ s2" << std::endl;
    //         break;
    //     }
    //     case 11:
    //     {
    //         if (s1 < s2)
    //             std::cout << "s1 МЕНЬШЕ s2" << std::endl;
    //         else
    //             std::cout << "s1 НЕ МЕНЬШЕ s2" << std::endl;
    //         break;
    //     }
    //     case 12:
    //     {
    //         if (s1 >= s2)
    //             std::cout << "s1 БОЛЬШЕ ИЛИ РАВНО s2" << std::endl;
    //         else
    //             std::cout << "s1 МЕНЬШЕ s2" << std::endl;
    //         break;
    //     }
    //     case 13:
    //     {
    //         if (s1 <= s2)
    //             std::cout << "s1 МЕНЬШЕ ИЛИ РАВНО s2" << std::endl;
    //         else
    //             std::cout << "s1 БОЛЬШЕ s2" << std::endl;
    //         break;
    //     }
    //     case 14:
    //     {
    //         int index;
    //         std::cout << "Введите номер элемента строки: ";
    //         std::cin >> index;
    //         char ch = s1[index];
    //         if (ch != -1)
    //             std::cout << "Символ с индексом " << index << ": '" << ch << "'" << std::endl;
    //         else
    //             std::cout << "Неверный индекс!" << std::endl;
    //         break;
    //     }
    //     case 15:
    //     {
    //         int start, length;
    //         std::cout << "Введите начальную позицию: ";
    //         std::cin >> start;
    //         std::cout << "Введите длину подстроки: ";
    //         std::cin >> length;
    //         String substring = s1(start, length);
    //         std::cout << "Подстрока: " << substring << std::endl;
    //         break;
    //     }
    //     case 16:
    //     {
    //         std::cout << "Выход из программы." << std::endl;
    //         return;
    //     }
    //     default:
    //     {
    //         std::cout << "Неверная команда!" << std::endl;
    //         break;
    //     }
    //     }
    // }
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