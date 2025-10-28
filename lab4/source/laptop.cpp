#include "../header.h"
#include "../header/portableMachine.h"
#include "../header/Laptop.h"

Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        portableMachine::operator=(other);
        hasBacklitKeyboard = other.hasBacklitKeyboard;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Laptop &Laptop)
{
    portableMachine &pm = Laptop;
    os << pm;
    os << std::setw(20) << (Laptop.hasBacklitKeyboard ? "+" : "-");
    return os;
}
std::istream &operator>>(std::istream &is, Laptop &Laptop)
{
    portableMachine &pm = Laptop;
    is >> pm;
    std::cout << "Есть подсветка клавиатуры? (1-да, 0-нет): ";
    is >> Laptop.hasBacklitKeyboard;
    return is;
}

void Laptop::info()
{
    portableMachine::info();
    std::cout << std::setw(20) << "Backlit";
}

bool Laptop::getHasBacklitKeyboard() const { return hasBacklitKeyboard; }
void Laptop::setHasBacklitKeyboard(bool hasBacklitKeyboard)
{
    this->hasBacklitKeyboard = hasBacklitKeyboard;
}

void Laptop::setMenu()
{
    portableMachine::setMenu();

    int choice;
    bool boolValue;

    do
    {
        std::cout << "\n=== Редактирование параметров ноутбука ===" << std::endl;
        std::cout << "1. Изменить подсветку клавиатуры (" << (hasBacklitKeyboard ? "Есть" : "Нет") << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Подсветка клавиатуры (1 - Есть, 0 - Нет): ";
            std::cin >> boolValue;
            setHasBacklitKeyboard(boolValue);
            std::cout << "Параметр подсветки клавиатуры изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}