#include "../header.h"
#include "../header/portableMachine.h"

PortableMachine &PortableMachine::operator=(const PortableMachine &other)
{
    if (this != &other)
    {
        Computer::operator=(other);
        batteryHealth = other.batteryHealth;
        sizeDisplay = other.sizeDisplay;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, PortableMachine &pm)
{
    Computer &com = pm;
    os << com;
    os << "Объем батареи: " << pm.batteryHealth << std::endl;
    os << "Размер дисплея: " << pm.sizeDisplay << " дюймов." << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, PortableMachine &pm)
{
    Computer &com = pm;
    is >> com;
    std::cout << "Введите ёмкость батареи: ";
    is >> pm.batteryHealth;
    std::cout << "Введите размер дисплея: ";
    is >> pm.sizeDisplay;
    return is;
}

void PortableMachine::info()
{
    Computer::info();
    std::cout << "- Портативная";
}

int PortableMachine::getBatteryHealth() const {return batteryHealth;}
int PortableMachine::getSizeDisplay() const { return sizeDisplay;}
void PortableMachine::setBatteryHealth(int batteryHealth) 
{
    this->batteryHealth = batteryHealth;
}
void PortableMachine::setSizeDisplay(int sizeDisplay)
{
    this->sizeDisplay = sizeDisplay;
}