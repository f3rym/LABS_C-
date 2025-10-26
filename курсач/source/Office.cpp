#include "../header.h"
#include "../header/Office.h"

int Office::getTotalWorkplaces() { return totalWorkplaces; }
int Office::getNumHouse() { return numHouse; }
int Office::getCountPremises() { return countPremises; }
int Office::getNumFloor() { return numFloor; }

void Office::setTotalWorkplaces(int workplaces) { totalWorkplaces = workplaces; }
void Office::setNumHouse(int numH) { numHouse = numH; }
void Office::setCountPremises(int premises) { countPremises = premises; }
void Office::setNumFloor(int floor) { numFloor = floor; }

std::ostream &operator<<(std::ostream &os, Office &off)
{
    Commercial &com = off;
    os << com;
    os << std::left;
    os << std::setw(6) << off.totalWorkplaces;
    os << std::setw(6) << off.numHouse;
    os << std::setw(6) << off.countPremises;
    os << std::setw(6) << off.numFloor;
    return os;
}
void Office::info()
{
    Commercial::info();

    std::cout << std::left;
    std::cout << " | " << std::setw(6) << "Места"
              << " | " << std::setw(6) << "Дом"
              << " | " << std::setw(6) << "Помещ."
              << " | " << std::setw(6) << "Этаж"
              << " |\n";
}

std::istream &operator>>(std::istream &is, Office &off)
{
    Commercial &com = off;
    is >> com;
    std::cout << "Введите количество рабочих мест: ";
    is >> off.totalWorkplaces;
    std::cout << "Введите номер дома: ";
    is >> off.numHouse;
    std::cout << "Введите количество помещений: ";
    is >> off.countPremises;
    std::cout << "Введите этаж: ";
    is >> off.numFloor;
    return is;
}