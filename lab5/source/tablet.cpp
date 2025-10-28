#include "../header.h"
#include "../header/Tablet.h"
#include "../header/portableMachine.h"
#include "../header/ExpInput.h"

Tablet &Tablet::operator=(const Tablet &other)
{
    if (this != &other)
    {
        portableMachine::operator=(other);
        strncpy_s(OS, other.OS, MAX_STR);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Tablet &Tablet)
{
    portableMachine &pm = Tablet;
    os << pm;

    os << std::setw(20) << Tablet.OS;
    return os;
}

std::istream &operator>>(std::istream &is, Tablet &Tablet)
{
    ExpInput exp;

    portableMachine &pm = Tablet;
    is >> pm;
    std::cout << "Введите операционную систему: ";
    is.ignore();
    strcpy_s(Tablet.OS, exp.isString().c_str());
    return is;
}

void Tablet::info()
{
    portableMachine::info();
    std::cout << std::setw(20) << "OS";
}

void Tablet::setMenu()
{
    portableMachine::setMenu();
    ExpInput exp;
    int choice;
    char buffer[MAX_STR];

    do
    {
        std::cout << "\n=== Редактирование параметров планшета ===" << std::endl;
        std::cout << "1. Изменить операционную систему (" << OS << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новую операционную систему: ";
            std::cin.ignore();
            strcpy_s(buffer, exp.isString().c_str());
            setOS(buffer);
            std::cout << "Операционная система изменена!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

const char *Tablet::getOS() const { return OS; }
void Tablet::setOS(const char *OS)
{
    strcpy_s(this->OS, OS);
}