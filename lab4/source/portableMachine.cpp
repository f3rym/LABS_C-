#include "../header.h"
#include "../header/portableMachine.h"

PortableMachine &PortableMachine::operator=(const PortableMachine &other)
{
    if (this != &other)
    {
        ComputingMachine::operator=(other);
        batteryHealth = other.batteryHealth;
        sizeDisplay = other.sizeDisplay;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, PortableMachine &pm)
{
    ComputingMachine &com = pm;
    os << com;
    os << std::setw(20) << pm.batteryHealth;
    os << std::setw(20) << pm.sizeDisplay;
    return os;
}

std::istream &operator>>(std::istream &is, PortableMachine &pm)
{
    ComputingMachine &com = pm;
    is >> com;
    std::cout << "Введите ёмкость батареи(mAh): ";
    is >> pm.batteryHealth;
    std::cout << "Введите размер дисплея(дюйм): ";
    is >> pm.sizeDisplay;
    return is;
}

void PortableMachine::info()
{
    ComputingMachine::info();
    std::cout << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display";
}

int PortableMachine::getBatteryHealth() const { return batteryHealth; }
int PortableMachine::getSizeDisplay() const { return sizeDisplay; }
void PortableMachine::setBatteryHealth(int batteryHealth)
{
    this->batteryHealth = batteryHealth;
}
void PortableMachine::setSizeDisplay(int sizeDisplay)
{
    this->sizeDisplay = sizeDisplay;
}