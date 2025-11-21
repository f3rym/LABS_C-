#include "../header/computingMachine.h"
#include "../header/ExpInput.h"

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
    ExpInput exp;
    std::cout << "Введите модель: ";
    is.ignore();
    strcpy_s(s.name, exp.isStringWithNumbers(std::cin).c_str());
    std::cout << "Введите процессор: ";
    strcpy_s(s.processor, exp.isStringWithNumbers(std::cin).c_str());
    std::cout << "Введите кол-во ОЗУ(Gb): ";
    s.ram = exp.isNumber(std::cin, 0, INT_MAX);

    return is;
}

std::ostream &operator<<(std::ostream &os, ComputingMachine &s)
{
    os << std::setw(20) << std::setw(20) << s.name;
    os << std::setw(20) << std::setw(20) << s.processor;
    os << std::setw(20) << std::setw(20) << s.ram;

    return os;
}

void ComputingMachine::setMenu()

{
    int choice;
    char buffer[MAX_STR];
    int intValue;

    while (choice != 0)
    {
        ExpInput exp;

        std::cout << "\n=== Редактирование базовых параметров ===" << std::endl;
        std::cout << "1. Изменить название (" << name << ")" << std::endl;
        std::cout << "2. Изменить процессор (" << processor << ")" << std::endl;
        std::cout << "3. Изменить RAM (" << ram << " GB)" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новое название: ";
            std::cin.ignore();
            strcpy_s(buffer, exp.isString(std::cin).c_str());
            setName(buffer);
            std::cout << "Название изменено!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый процессор: ";
            std::cin.ignore();
            strcpy_s(buffer, exp.isStringWithNumbers(std::cin).c_str());
            setProcessor(buffer);
            std::cout << "Процессор изменен!" << std::endl;
            break;
        case 3:
            std::cout << "Введите новый объем RAM (GB): ";
            intValue = exp.isNumber(std::cin);
            setRam(intValue);
            std::cout << "RAM изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    }
}

void ComputingMachine::info()
{
    std::cout << std::left;
    std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
              << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)";
}

const char *ComputingMachine::getName() const { return name; }
const char *ComputingMachine::getProcessor() const { return processor; }
int ComputingMachine::getRam() const { return ram; }

void ComputingMachine::setName(char *name)
{
    strcpy_s(this->name, name);
}
void ComputingMachine::setProcessor(char *processor)
{
    strcpy_s(this->processor, processor);
}
void ComputingMachine::setRam(int ram)
{
    this->ram = ram;
}
