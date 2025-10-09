#include "../header.h"
#include "../header/tablet.h"
// #include "../header/portableMachine.h"



std::ostream &operator<<(std::ostream &os, Tablet &tablet)
{
    PortableMachine &pm = tablet;
    os << pm;
    os << "Операционная система: " << tablet.OS << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Tablet &tablet)
{
    PortableMachine &pm = tablet;
    is >> pm;
    std::cout << "Введите операционную систему: ";
    is.getline(tablet.OS, MAX_STR);
    return is;
}

void Tablet::info()
{
    PortableMachine::info();
    std::cout << "- Планшет";
}