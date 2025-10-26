#include "../header.h"
#include "../header/Commercial.h"

char *Commercial::getCondition() { return condition; }
char *Commercial::getMetro() { return metro; }
bool Commercial::getHasParking() { return hasParking; }
bool Commercial::getSecureSystem() { return secureSystem; }

void Commercial::setCondition(char *cond) { strcpy_s(condition, cond); }
void Commercial::setMetro(char *m) { strcpy_s(metro, m); }
void Commercial::setHasParking(bool parking) { hasParking = parking; }
void Commercial::setSecureSystem(bool secure) { secureSystem = secure; }

std::ostream &operator<<(std::ostream &os, Commercial &com)
{
    Property &pr = com;
    os << pr;
    os << std::left;
    os << std::setw(10) << com.condition;
    os << std::setw(10) << com.metro;
    os << std::setw(3) << (com.hasParking ? "+" : "-");
    os << std::setw(3) << (com.secureSystem ? "+" : "-");
    return os;
}
void Commercial::info()
{
    Property::info();

    std::cout << std::left;
    std::cout << " | " << std::setw(10) << "Состояние"
              << " | " << std::setw(10) << "Метро"
              << " | " << std::setw(3) << "Парк"
              << " | " << std::setw(3) << "СБ";
}

std::istream &operator>>(std::istream &is, Commercial &com)
{
    Property &pr = com;
    is >> pr;
    std::cout << "Введите состояние: ";
    is.getline(com.condition, MAX_STR);
    std::cout << "Введите станцию метро: ";
    is.getline(com.metro, MAX_STR);
    std::cout << "Есть парковка (1-да/0-нет): ";
    is >> com.hasParking;
    std::cout << "Есть система безопасности (1-да/0-нет): ";
    is >> com.secureSystem;
    return is;
}