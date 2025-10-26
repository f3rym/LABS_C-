#include "../header.h"
#include "../header/House.h"

int House::getNumHouse() { return numHouse; }
int House::getCountRoom() { return countRoom; }
int House::getFloorCount() { return floorCount; }
char *House::getWaterSupply() { return waterSupply; }
bool House::getTypeHeating() { return typeHeating; }
char *House::getWallMaterial() { return wallMaterial; }

void House::setNumHouse(int numH) { numHouse = numH; }
void House::setCountRoom(int rooms) { countRoom = rooms; }

void House::setFloorCount(int floors) { floorCount = floors; }
void House::setWaterSupply(char *water) { strcpy_s(waterSupply, water); }
void House::setTypeHeating(bool heating) { typeHeating = heating;}
void House::setWallMaterial(char *material) { strcpy_s(wallMaterial, material); }

std::ostream &operator<<(std::ostream &os, House &h)
{
    PrivateSector &ps = h;
    os << ps;
    os << std::left;
    os << std::setw(6) << h.numHouse;
    os << std::setw(6) << h.countRoom;
    os << std::setw(6) << h.floorCount;
    os << std::setw(10) << h.waterSupply;
    if (h.typeHeating)
        os << std::setw(3) << "+";
    else
        os << std::setw(3) << "-";
    os << std::setw(10) << h.wallMaterial;
    return os;
}
void House::info()
{
    PrivateSector::info();

    std::cout << std::left;
    std::cout << " | " << std::setw(6) << "Дом"
              << " | " << std::setw(6) << "Комн."
              << " | " << std::setw(6) << "Этажи"
              << " | " << std::setw(10) << "Водоснабж."
              << " | " << std::setw(3) << "Отопл."
              << " | " << std::setw(10) << "Материал"
              << " |\n";
}
std::istream &operator>>(std::istream &is, House &h)
{
    PrivateSector &ps = h;
    is >> ps;
    std::cout << "Введите номер дома: ";
    is >> h.numHouse;
    std::cout << "Введите количество комнат: ";
    is >> h.countRoom;
    std::cout << "Введите количество этажей: ";
    is >> h.floorCount;
    is.ignore();
    std::cout << "Введите водоснабжение: ";
    is.getline(h.waterSupply, MAX_STR);
    std::cout << "Имеется ли отопление( 1 - да, 0 - нет ): ";
    is >> h.typeHeating;
    std::cout << "Введите материал стен: ";
    is.getline(h.wallMaterial, MAX_STR);
    return is;
}