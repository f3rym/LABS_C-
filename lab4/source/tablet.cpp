#include "../header.h"
#include "../header/tablet.h"
#include "../header/portableMachine.h"

Tablet &Tablet::operator=(const Tablet &other)
{
    if (this != &other)
    {
        PortableMachine::operator=(other);
        strncpy_s(OS,  other.OS, MAX_STR);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Tablet &tablet)
{
    PortableMachine &pm = tablet;
    os << pm;
    
    os << std::setw(20) << tablet.OS;
    return os;
}

std::istream &operator>>(std::istream &is, Tablet &tablet)
{
    PortableMachine &pm = tablet;
    is >> pm;
    std::cout << "Введите операционную систему: ";
    rewind(stdin);
    is.getline(tablet.OS, MAX_STR);
    return is;
}

void Tablet::info()
{
    PortableMachine::info();
    std::cout << std::setw(20) << "OS";
}

const char *Tablet::getOS() const { return OS; }
void Tablet::setOS(const char *OS)
{
    strcpy_s(this->OS, OS);
}