#include "../header.h"
#include "../header/Garage.h"

bool Garage::getHasElectricity() { return hasElectricity; }
bool Garage::getHasHeating() { return hasHeating; }

void Garage::setHasElectricity(bool electricity) { hasElectricity = electricity; }
void Garage::setHasHeating(bool heating) { hasHeating = heating; }

std::ostream &operator<<(std::ostream &os, Garage &gar)
{
    NonResidential &nr = gar;
    os << nr;
    os << std::left;
    if (gar.hasElectricity)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    if (gar.hasHeating)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    return os;
}

void Garage::info()
{
    std::cout << std::left;
    std::cout << std::setw(6) << "N"
              << std::setw(6) << "Площадь(м²)"
              << std::setw(3) << "Электричество"
              << std::setw(3) << "Отопление";
            }

std::istream &operator>>(std::istream &is, Garage &gar)
{
    NonResidential &nr = gar;
    is >> nr;
    std::cout << "Есть электричество (1-да/0-нет): ";
    is >> gar.hasElectricity;
    std::cout << "Есть отопление (1-да/0-нет): ";
    is >> gar.hasHeating;
    return is;
}