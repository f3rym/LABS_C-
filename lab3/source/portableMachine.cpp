#include "../header.h"
#include "../header/portableMachine.h"


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