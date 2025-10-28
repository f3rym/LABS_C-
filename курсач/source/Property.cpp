#include "../header.h"
#include "../header/Property.h"
#include "../header/Apartment.h"
#include "../header/Garage.h"
#include "../header/House.h"
#include "../header/Land.h"
#include "../header/Storage.h"
#include "../header/Office.h"

double Property::getTotalArea() { return totalArea; }
int Property::getPrice() { return price; }
char *Property::getCity() { return city; }
char *Property::getRegion() { return region; }
char *Property::getStreet() { return street; }

void Property::setTotalArea(double area) { totalArea = area; }
void Property::setPrice(int pr) { price = pr; }
void Property::setCity(char *c) { strcpy_s(city, c); }
void Property::setRegion(char *r) { strcpy_s(region, r); }
void Property::setStreet(char *s) { strcpy_s(street, s); }

std::ostream &operator<<(std::ostream &os, Property &pr)
{
    os << std::left;
    os << std::setw(7) << pr.totalArea;
    os  << std::setw(8) << pr.price;
    os << std::setw(11) << pr.city;
    os << std::setw(11) << pr.region;
    os << std::setw(14) << pr.street;
    return os;
}

void Property::info()
{
    std::cout << std::left;
    std::cout << std::setw(5) << "S(м²)"
              << " | " << std::setw(8) << "Цена"
              << " | " << std::setw(12) << "Город"
              << " | " << std::setw(12) << "Область"
              << " | " << std::setw(15) << "Улица"
              << " |";
}

std::istream &operator>>(std::istream &is, Property &pr)
{
    std::cout << "Введите общую жилую площадь: ";
    is >> pr.totalArea;
    std::cout << "Введите цену: ";
    is >> pr.price;
    std::cout << "Введите город: ";
    is.ignore();
    is.getline(pr.city, MAX_STR);
    std::cout << "Введите область: ";
    is.getline(pr.region, MAX_STR);
    std::cout << "Введите улицу: ";
    is.getline(pr.street, MAX_STR);
    return is;
}

bool Property::writeToFile(std::ofstream &file)
{
    file << isActive << " " << ownerId << " " << totalArea << " " << price << " " << region << " " << city << " " << this->street;
    return true;
}

Property Property::readFromFile(std::ifstream &file)
{
    Property result;
    file >> result.isActive >>  result.ownerId >> result.totalArea >> result.price >> result.region >> result.city >> result.street;
    return result;
}
