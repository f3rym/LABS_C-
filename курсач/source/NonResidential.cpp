#include "../header.h"
#include "../header/NonResidential.h"

char *NonResidential::getPurpose() { return purpose; }
bool NonResidential::getHasVentilation() { return hasVentilation; }
bool NonResidential::getHasFireSafety() { return hasFireSafety; }

void NonResidential::setPurpose(char *purp) { strcpy_s(purpose, purp); }
void NonResidential::setHasVentilation(bool vent) { hasVentilation = vent; }
void NonResidential::setHasFireSafety(bool fire) { hasFireSafety = fire; }

std::ostream &operator<<(std::ostream &os, NonResidential &nr)
{
    Property &pr = nr;
    os << pr;
    os << std::left;
    os << std::setw(10) << nr.purpose;
    if (nr.hasVentilation)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    if (nr.hasFireSafety)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    return os;
}
void NonResidential::info()
{
    Property::info();

    std::cout << std::left;
    std::cout << " | " << std::setw(10) << "Назначение"
              << " | " << std::setw(3) << "Вент"
              << " | " << std::setw(3) << "ПБ"
              << " |\n";
}
std::istream &operator>>(std::istream &is, NonResidential &nr)
{
    Property &pr = nr;
    is >> pr;
    std::cout << "Введите назначение: ";
    is.getline(nr.purpose, MAX_STR);
    std::cout << "Есть вентиляция (1-да/0-нет): ";
    is >> nr.hasVentilation;
    std::cout << "Есть пожарная безопасность (1-да/0-нет): ";
    is >> nr.hasFireSafety;
    return is;
}