#include "../header/computingMachine.h"

ComputingMachine &ComputingMachine::operator=(const ComputingMachine &other)
{
    if (this != &other)
    {
        strncpy_s(name, other.name, MAX_STR);
        strncpy_s(processor, other.processor, MAX_STR);
        ram = other.ram;
    }
    return *this;
}

std::istream &operator>>(std::istream &is, ComputingMachine &s)
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

std::ostream &operator<<(std::ostream &os, ComputingMachine &s)
{
    os << std::setw(20) << std::setw(20) << s.name;
    os << std::setw(20) << std::setw(20) << s.processor;
    os << std::setw(20) << std::setw(20) << s.ram;

    return os;
}

void ComputingMachine::info()
{
    std::cout << "Тип: Вычислительная машина";
}

const char *ComputingMachine::getName() const { return name; }
const char *ComputingMachine::getProcessor() const { return processor; }
int ComputingMachine::getRam() const { return ram; }

void ComputingMachine::setName(char *name)
{
    std::strcpy(this->name, name);
}
void ComputingMachine::setProcessor(char *processor)
{
    std::strcpy(this->processor, processor);
}
void ComputingMachine::setRam(int ram)
{
    this->ram = ram;
}
