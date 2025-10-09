#include "../header.h"
#include "../header/mono.h"
// #include "../header/stationaryMachine.h"

std::ostream &operator<<(std::ostream &os, MonoBlock &mb)
{
    StationaryMachine& sm = mb;
    os << sm;
    os << "Размер дисплея: " << mb.sizeDisplay << " дюймов" << std::endl;
    if (mb.touchScreen == true)
        os << "Имеется Сенсорный экран." << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, MonoBlock &mb)
{
    StationaryMachine &sm = mb;
    is >> sm;
    std::cout << "Введите размер дисплея: ";
    is >> mb.sizeDisplay;
    std::cout << "Имеется Сенсорный экран? (1 - ДА, 0 - НЕТ): ";
    is >> mb.touchScreen;
    return is;
}

void MonoBlock::info()
{
    StationaryMachine::info();
    std::cout << "- Моноблок";
}