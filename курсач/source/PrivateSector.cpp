#include "../header.h"
#include "../header/PrivateSector.h"

double PrivateSector::getSizeRegion() { return sizeRegion; }
double PrivateSector::getDistanceToMKAD() { return distanceToMKAD; }
char *PrivateSector::getRelief() { return relief; }
bool PrivateSector::getHasUtilities() { return hasUtilities; }

void PrivateSector::setSizeRegion(double sizeReg) { sizeRegion = sizeReg; }
void PrivateSector::setDistanceToMKAD(double distMKAD) { distanceToMKAD = distMKAD; }
void PrivateSector::setRelief(char *rel) { strcpy_s(relief, rel); }
void PrivateSector::setHasUtilities(bool utils) { hasUtilities = utils; }

std::ostream &operator<<(std::ostream &os, PrivateSector &ps)
{
    Property &pr = ps;
    os << pr;
    os << std::left;
    os << std::setw(3) << ps.sizeRegion;
    os << std::setw(9) << ps.distanceToMKAD;
    os << std::setw(12) << ps.relief;
    if (ps.hasUtilities)
        os << std::setw(9) << "+";
    else
        os << std::setw(9) << "-";
    return os;
}
void PrivateSector::info()
{
    Property::info();
    std::cout << std::setw(6) << "Размер"
              << " | " << std::setw(6) << "Дист.МКАД"
              << " | " << std::setw(10) << "Рельеф"
              << " | " << std::setw(3) << "Комм.";
}


std::istream &operator>>(std::istream &is, PrivateSector &ps)
{
    Property &pr = ps;
    is >> pr;
    std::cout << "Введите площадь участка(улицы): ";
    is >> ps.sizeRegion;
    std::cout << "Введите расстояние до МКАД: ";
    is >> ps.distanceToMKAD;
    is.ignore();
    std::cout << "Введите рельеф: ";
    is.getline(ps.relief, MAX_STR);
    std::cout << "Есть коммуникации (1-да/0-нет): ";
    is >> ps.hasUtilities;
    return is;
}

bool PrivateSector::writeToFile(std::ofstream &file)
{
    Property::writeToFile(file);
    file << " " << this->sizeRegion << " " << this->distanceToMKAD << " " << this->relief << " " << this->hasUtilities;
    return true;
}

PrivateSector PrivateSector::readFromFile(std::ifstream &file)
{
    PrivateSector result;
    Property &pr = result; 
    pr = Property::readFromFile(file);
    file >> result.sizeRegion >> result.distanceToMKAD >> result.relief >> result.hasUtilities;
    return result;
}
