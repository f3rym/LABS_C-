#include "../header/computer.h"

std::istream &operator>>(std::istream &is, Computer &s)
{
    std::cout << "Введите модель: ";
    is.getline(s.name, MAX_STR);
    std::cout << "Введите процессор: ";
    is.getline(s.processor, MAX_STR);
    std::cout << "Введите кол-во ОЗУ: ";
    is >> s.ram;

    return is;
}

std::ostream &operator<<(std::ostream &os, Computer &s)
{
    os << "Модель: " << s.name << std::endl;
    os << "Процессор: " << s.processor << std::endl;
    os << "Оперативная память: " << s.ram << " GB" << std::endl;
    return os;
}

void Computer::info()
{
    std::cout << "Тип: Вычислительная машина";
}
// int Computer::getPowerConsumption() 
// {
//     return
// }
