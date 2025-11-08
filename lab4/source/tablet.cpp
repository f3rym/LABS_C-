#include "../header.h"
#include "../header/Tablet.h"
#include "../header/portableMachine.h"

Tablet &Tablet::operator=(const Tablet &other)
{
    if (this != &other)
    {
        portableMachine::operator=(other);
        strncpy_s(OS, other.OS, MAX_STR);
    }
    return *this;
}
void Tablet::sortList(LinkedList<ComputingMachine*> &list)
{
    portableMachine::sortList(list);

    int choice;

    do
    {
        std::cout << "\n=== Сортировка параметров планшета ===" << std::endl;
        std::cout << "1. Сортировка по операционной системе (OS)" << std::endl;
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
                    Tablet *a = dynamic_cast<Tablet *>(list[j]);
                    Tablet *b = dynamic_cast<Tablet *>(list[j + 1]);
                    if (strcmp(a->OS, b->OS) < 0)
                    {
                        std::swap(list[j], list[j + 1]);
                    }
                }
            }
            std::cout << "Сортировка по OS завершена!" << std::endl;
            break;

        case 0:
            std::cout << "Сортировка пропущена!" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
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
    portableMachine &pm = Tablet;
    is >> pm;
    std::cout << "Введите операционную систему: ";
    is.ignore();
    is.getline(Tablet.OS, MAX_STR);
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

    int choice;
    char buffer[MAX_STR];

    if(choice != 0)
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
            std::cin.getline(buffer, MAX_STR);
            setOS(buffer);
            std::cout << "Операционная система изменена!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } 
}

const char *Tablet::getOS() const { return OS; }
void Tablet::setOS(const char *OS)
{
    strcpy_s(this->OS, OS);
}