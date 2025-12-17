#include "../header.h"
#include "../header/mono.h"
#include "../header/stationaryMachine.h"
#include "../header/ExpInput.h"

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

std::ostream &operator<<(std::ostream &os, const MonoBlock &mb)
{
    const StationaryMachine &sm = mb;
    os << sm;
    os << std::setw(20) << mb.getSizeDisplay();
    if (mb.getTouchScreen() == true)
        os << std::setw(20) << "+";
    else
        os << std::setw(20) << "-";
    return os;
}

void MonoBlock::writeToStream(std::ostream &os) const
{
    StationaryMachine::writeToStream(os);
    os << ';' << getSizeDisplay() << ';' << (getTouchScreen() ? 1 : 0) << '\n';
}

void MonoBlock::readFromStream(std::istream &is)
{
    StationaryMachine::readFromStream(is);
    char delimiter = ';';
    int sz = 0;
    int ts = 0;
    if (!(is >> sz))
        return;
    if (!(is >> delimiter))
        return;
    if (!(is >>  ts))
        return;
    is.ignore();
    setTouchScreen(ts);
    setSizeDisplay(sz);
}


std::istream &operator>>(std::istream &is, MonoBlock &mb)
{
    ExpInput exp;
    StationaryMachine &sm = mb;
    is >> sm;
    std::cout << "Введите размер дисплея(дюйм): ";

    mb.sizeDisplay = exp.isNumber(std::cin, 0, INT_MAX);
    std::cout << "Имеется Сенсорный экран? (1 - ДА, 0 - НЕТ): ";
    mb.touchScreen = exp.isBool(std::cin);
    return is;
}

void MonoBlock::info()
{
    StationaryMachine::info();
    std::cout << std::setw(20) << "Size Display" << std::setw(20) << "Touchscreen";
}

int MonoBlock::getSizeDisplay() const { return sizeDisplay; }
bool MonoBlock::getTouchScreen() const { return touchScreen; }
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
        ExpInput exp;

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
            intValue = exp.isNumber(std::cin, 0, INT_MAX);
            setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 2:
            std::cout << "Сенсорный экран (1 - Есть, 0 - Нет): ";
            boolValue = exp.isBool(std::cin);
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