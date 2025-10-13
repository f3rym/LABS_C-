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