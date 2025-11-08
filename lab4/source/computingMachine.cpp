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
    is.ignore();
    is.getline(s.name, MAX_STR);
    std::cout << "Введите процессор: ";
    is.getline(s.processor, MAX_STR);
    std::cout << "Введите кол-во ОЗУ(Gb): ";
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

void ComputingMachine::setMenu()

{
    int choice;
    char buffer[MAX_STR];
    int intValue;

    while (choice != 0)
    {
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
            std::cin.getline(buffer, MAX_STR);
            setName(buffer);
            std::cout << "Название изменено!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый процессор: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            setProcessor(buffer);
            std::cout << "Процессор изменен!" << std::endl;
            break;
        case 3:
            std::cout << "Введите новый объем RAM (GB): ";
            std::cin >> intValue;
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
void ComputingMachine::sortList(LinkedList<ComputingMachine*> &list)
{
    if (list.getSize() == 0)
    {
        std::cout << "Нет машин для сортировки!" << std::endl;
        return;
    }

    int choice;
    std::cout << "\n=== Сортировка базовых параметров машин ===" << std::endl;
    std::cout << "1. По названию" << std::endl;
    std::cout << "2. По процессору" << std::endl;
    std::cout << "3. По RAM" << std::endl;
    std::cout << "0. Пропустить" << std::endl;
    std::cout << "Выберите параметр для сортировки: ";
    std::cin >> choice;
    for (int i = 0; i < list.getSize() - 1; ++i)
    {
        for (int j = 0; j < list.getSize() - i - 1; ++j)
        {
            bool swapFlag = false;

            switch (choice)
            {
            case 1:
                if (strcmp(list[j]->name, list[j + 1]->name) < 0)
                    swapFlag = true;
                break;
            case 2:
                if (strcmp(list[j]->processor, list[j + 1]->processor) < 0)
                    swapFlag = true;
                break;
            case 3:
                if (list[j]->ram < list[j + 1]->ram)
                    swapFlag = true;
                break;
            case 0:
                std::cout << "Сортировка пропущена" << std::endl;
                return;
            default:
                std::cout << "Неверный выбор!" << std::endl;
                return;
            }
            if (swapFlag)
            {
                std::swap(list[j], list[j + 1]);
            }
        }
    }

    std::cout << "Сортировка завершена!" << std::endl;
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
