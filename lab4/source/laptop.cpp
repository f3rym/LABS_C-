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
void Laptop::sortList(LinkedList<ComputingMachine*> &list)
{
    portableMachine::sortList(list);

    int choice;

    if (choice != 0)
    {
        std::cout << "\n=== Сортировка параметров ноутбука ===" << std::endl;
        std::cout << "1. Сортировка по подсветке клавиатуры" << std::endl;
        std::cout << "0. Пропустить" << std::endl;
        std::cout << "Выберите параметр: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < list.getSize() - 1; ++i)
            {
                for (int j = 0; j < list.getSize() - i - 1; ++j)
                {
                    Laptop *a = dynamic_cast<Laptop *>(list[j]);
                    Laptop *b = dynamic_cast<Laptop *>(list[j + 1]);
                    if (a && b && !a->hasBacklitKeyboard && b->hasBacklitKeyboard)
                    {
                        std::swap(list[j], list[j + 1]);
                    }
                }
            }
            std::cout << "Сортировка по подсветке клавиатуры завершена!" << std::endl;
            break;

        case 0:
            std::cout << "Сортировка пропущена!" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } 
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