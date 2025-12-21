#include "../header.h"
#include "../header/Tablet.h"
#include "../header/portableMachine.h"
#include "../header/ExpInput.h"

Tablet &Tablet::operator=(const Tablet &other)
{
    if (this != &other)
    {
        portableMachine::operator=(other);
        strcpy_s(OS, MAX_STR, other.OS);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Tablet &Tablet)
{
    const portableMachine &pm = Tablet;
    os << pm;

    os << std::setw(20) << Tablet.getOS();
    return os;
}

void Tablet::sortList(std::vector<ComputingMachine *> &list)
{
    // Сначала вызываем сортировку базового класса
    portableMachine::sortList(list);

    int choice;
    std::cout << "\n=== Сортировка параметров планшета ===" << std::endl;
    std::cout << "1. Сортировка по операционной системе (OS)" << std::endl;
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
        std::vector<Tablet *> tabletList;
        for (auto *ptr : list)
        {
            if (auto *tablet = dynamic_cast<Tablet *>(ptr))
            {
                tabletList.push_back(tablet);
            }
        }

        if (tabletList.empty())
        {
            std::cout << "Нет планшетов для сортировки!" << std::endl;
            return;
        }

        std::sort(tabletList.begin(), tabletList.end(),
                  [](Tablet *a, Tablet *b)
                  {
                      return strcmp(a->OS, b->OS) > 0;
                  });

        int tabletIndex = 0;
        for (int i = 0; i < list.size(); ++i)
        {
            if (dynamic_cast<Tablet *>(list[i]))
            {
                list[i] = tabletList[tabletIndex++];
            }
        }

        std::cout << "Сортировка по OS завершена!" << std::endl;
    }
    else
    {
        std::cout << "Неверный выбор!" << std::endl;
    }
}

void Tablet::writeToStream(std::ostream &os) const
{
    portableMachine::writeToStream(os);
    os << ';' << getOS() << '\n';
}

void Tablet::readFromStream(std::istream &is)
{
    portableMachine::readFromStream(is);
    std::string osStr;
    if (!std::getline(is, osStr))
        return;
    char buf[MAX_STR];
    strcpy_s(buf, MAX_STR, osStr.c_str());
    setOS(buf);
}

std::istream &operator>>(std::istream &is, Tablet &Tablet)
{
    ExpInput exp;

    portableMachine &pm = Tablet;
    is >> pm;
    std::cout << "Введите операционную систему: ";
    strcpy_s(Tablet.OS, exp.isString(std::cin).c_str());
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
            strcpy_s(buffer, exp.isString(std::cin).c_str());
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