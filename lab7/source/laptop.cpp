#include "../header.h"
#include "../header/portableMachine.h"
#include "../header/Laptop.h"
#include "../header/ExpInput.h"

Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        portableMachine::operator=(other);
        hasBacklitKeyboard = other.hasBacklitKeyboard;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Laptop &Laptop)
{
    const portableMachine &pm = Laptop;
    os << pm;
    os << std::setw(20) << (Laptop.getHasBacklitKeyboard() ? "+" : "-");
    return os;
}

void Laptop::sortList(std::vector<ComputingMachine *> &list)
{
    portableMachine::sortList(list);

    int choice;
    std::cout << "\n=== Сортировка параметров ноутбука ===" << std::endl;
    std::cout << "1. Сортировка по наличию подсветки клавиатуры" << std::endl;
    std::cout << "0. Пропустить" << std::endl;
    std::cout << "Выберите параметр: ";
    std::cin >> choice;

    if (choice == 0)
    {
        std::cout << "Сортировка пропущена!" << std::endl;
        return;
    }

    if (choice == 1)
    {
        std::vector<Laptop *> laptopList;
        for (auto *ptr : list)
        {
            if (auto *laptop = dynamic_cast<Laptop *>(ptr))
            {
                laptopList.push_back(laptop);
            }
        }

        if (laptopList.empty())
        {
            std::cout << "Нет ноутбуков для сортировки!" << std::endl;
            return;
        }

        std::sort(laptopList.begin(), laptopList.end(),
                  [](Laptop *a, Laptop *b)
                  {
                      return a->hasBacklitKeyboard > b->hasBacklitKeyboard;
                  });

        int laptopIndex = 0;
        for (int i = 0; i < list.size(); ++i)
        {
            if (dynamic_cast<Laptop *>(list[i]))
            {
                list[i] = laptopList[laptopIndex++];
            }
        }

        std::cout << "Сортировка по подсветке клавиатуры завершена!" << std::endl;
    }
    else
    {
        std::cout << "Неверный выбор!" << std::endl;
    }
}

void Laptop::writeToStream(std::ostream &os) const
{
    portableMachine::writeToStream(os);
    os << ';' << (getHasBacklitKeyboard() ? 1 : 0) << '\n';
}

void Laptop::readFromStream(std::istream &is)
{
    portableMachine::readFromStream(is);
    char delimiter = ';';
    int v = 0;
    if (!(is >> v))
        return;
    is.ignore();
    setHasBacklitKeyboard(v);
}

std::istream &operator>>(std::istream &is, Laptop &Laptop)
{
    ExpInput exp;
    portableMachine &pm = Laptop;
    is >> pm;
    std::cout << "Есть подсветка клавиатуры? (1-да, 0-нет): ";
    Laptop.hasBacklitKeyboard = exp.isBool(std::cin);
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
        ExpInput exp;
        std::cout << "\n=== Редактирование параметров ноутбука ===" << std::endl;
        std::cout << "1. Изменить подсветку клавиатуры (" << (hasBacklitKeyboard ? "Есть" : "Нет") << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Подсветка клавиатуры (1 - Есть, 0 - Нет): ";
            boolValue = exp.isBool(std::cin);
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