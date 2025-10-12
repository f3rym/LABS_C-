#include "../header/computer.h"

Computer &Computer::operator=(const Computer &other)
{
    if (this != &other)
    {
        strncpy_s(name, other.name, MAX_STR);
        strncpy_s(processor, other.processor, MAX_STR);
        ram = other.ram;
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Computer &s)
{
    std::cout << "Введите модель: ";
    std::cin.ignore();
    is.getline(s.name, MAX_STR);
    std::cout << "Введите процессор: ";
    is.getline(s.processor, MAX_STR);
    std::cout << "Введите кол-во ОЗУ: ";
    is >> s.ram;

    return is;
}

std::ostream &operator<<(std::ostream &os, Computer &s)
{
    os << std::setw(20) << std::setw(20) << s.name ;
    os << std::setw(20) << std::setw(20) << s.processor;
    os << std::setw(20) << std::setw(20) << s.ram ;

    return os;
}

void Computer::info()
{
    std::cout << "Тип: Вычислительная машина";
}

const char *Computer::getName() const { return name; }
const char *Computer::getProcessor() const { return processor; }
int Computer::getRam() const { return ram; }

void Computer::setName(char *name)
{
   std::strcpy(this->name, name);
}
void Computer::setProcessor(char *processor)
{
    std::strcpy(this->processor, processor);
}
void Computer::setRam(int ram)
{
    this->ram = ram;
}
