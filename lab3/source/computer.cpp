#include "../header/computer.h"


Computer::Computer()
{
    ram = 0;
    name[0] = '\0';
    processor[0] = '\0';
}
Computer::Computer(char *name, char *processor, int ram)
{
    std::strcpy(this->name, name);
    std::strcpy(this->processor, processor);
    this->ram = ram;
}
Computer::Computer(const Computer &other)
{
    std::strcpy(this->name, other.name);
    std::strcpy(this->processor, other.processor);
    this->ram = other.ram;
}
void Computer::print()
{
    std::cout << "Модель: " << name << std::endl;
    std::cout << "Процессор: " << processor << std::endl;
    std::cout << "Оперативная память: " << ram << " GB" << std::endl;
}

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






