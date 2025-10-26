#include "../header.h"
#include "../header/Land.h"

char *Land::getLandType() { return landType; }

void Land::setLandType(char *type) { strcpy_s(landType, type); }

std::ostream &operator<<(std::ostream &os, Land &l)
{
    PrivateSector &ps = l;
    os << ps;
    os << std::left;
    os << std::setw(10) << l.landType;
    return os;
}
void Land::info()
{
    PrivateSector::info();

    std::cout << std::left;
    std::cout << std::setw(10) << "Тип участка"
              << "\n";
}
std::istream &operator>>(std::istream &is, Land &l)
{
    PrivateSector &ps = l;
    is >> ps;
    is.ignore();
    std::cout << "Введите тип участка: ";
    is.getline(l.landType, MAX_STR);
    return is;
}