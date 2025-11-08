#include "../header.h"
#include "../header/mono.h"
#include "../header/stationaryMachine.h"

MonoBlock &MonoBlock::operator=(const MonoBlock &other)
{
    if (this != &other)
    {
        StationaryMachine::operator=(other);
        touchScreen = other.touchScreen;
        sizeDisplay = other.sizeDisplay;    
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, MonoBlock &mb)
{
    StationaryMachine& sm = mb;
    os << sm;
    os << std::setw(20) << mb.sizeDisplay;
    if (mb.touchScreen == true)
        os << std::setw(20) << "+";
    else 
        os << std::setw(20) << "-";
    return os;
}

std::istream &operator>>(std::istream &is, MonoBlock &mb)
{
    StationaryMachine &sm = mb;
    is >> sm;
    std::cout << "Введите размер дисплея(дюйм): ";
    is >> mb.sizeDisplay;
    std::cout << "Имеется Сенсорный экран? (1 - ДА, 0 - НЕТ): ";
    is >> mb.touchScreen;
    return is;
}

void MonoBlock::info()
{
    StationaryMachine::info();
    std::cout << std::setw(20) << "Size Display" << std::setw(20) << "Touchscreen";
}

int MonoBlock::getSizeDisplay() const {return sizeDisplay;}
bool MonoBlock::getTouchScreen() const {return touchScreen;}
void MonoBlock::setTouchScreen(bool touchScreen)
{
    this->touchScreen = touchScreen;
}
void MonoBlock::setSizeDisplay(int sizeDisplay)
{
    this->sizeDisplay = sizeDisplay;
}

void MonoBlock::setMenu()
{
    StationaryMachine::setMenu(); 

    int choice;
    int intValue;
    bool boolValue;

    do
    {
        std::cout << "\n=== Редактирование параметров моноблока ===" << std::endl;
        std::cout << "1. Изменить размер дисплея (" << sizeDisplay << "\")" << std::endl;
        std::cout << "2. Изменить сенсорный экран (" << (touchScreen ? "Есть" : "Нет") << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            std::cin >> intValue;
            setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 2:
            std::cout << "Сенсорный экран (1 - Есть, 0 - Нет): ";
            std::cin >> boolValue;
            setTouchScreen(boolValue);
            std::cout << "Параметр сенсорного экрана изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void MonoBlock::sortList(LinkedList<ComputingMachine*> &list)
{
    StationaryMachine::sortList(list);

    int choice;

    if (choice != 0)
    {
        std::cout << "\n=== Сортировка параметров моноблока ===" << std::endl;
        std::cout << "1. Сортировка по размеру дисплея" << std::endl;
        std::cout << "2. Сортировка по наличию сенсорного экрана" << std::endl;
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
                    MonoBlock *a = dynamic_cast<MonoBlock *>(list[j]);
                    MonoBlock *b = dynamic_cast<MonoBlock *>(list[j + 1]);
                    if (a->sizeDisplay < b->sizeDisplay)
                    {
                        std::swap(list[j], list[j + 1]);
                    }
                }
            }
            std::cout << "Сортировка по размеру дисплея завершена!" << std::endl;
            break;

        case 2:
            for (int i = 0; i < list.getSize() - 1; ++i)
            {
                for (int j = 0; j < list.getSize() - i - 1; ++j)
                {
                    MonoBlock *a = dynamic_cast<MonoBlock *>(list[j]);
                    MonoBlock *b = dynamic_cast<MonoBlock *>(list[j + 1]);
                    if (a->touchScreen < b->touchScreen)
                    {
                        std::swap(list[j], list[j + 1]);
                    }
                }
            }
            std::cout << "Сортировка по сенсорному экрану завершена!" << std::endl;
            break;

        case 0:
            std::cout << "Сортировка пропущена!" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    }
}
