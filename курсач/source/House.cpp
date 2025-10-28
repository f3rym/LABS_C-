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
void House::setTypeHeating(bool heating) { typeHeating = heating; }
void House::setWallMaterial(char *material) { strcpy_s(wallMaterial, material); }

std::ostream &operator<<(std::ostream &os, House &h)
{
    PrivateSector &ps = h;
    os << ps;
    os << std::left;
    os << std::setw(8) << h.numHouse;
    os << std::setw(8) << h.countRoom;
    os << std::setw(8) << h.floorCount;
    os << std::setw(10) << h.waterSupply;
    if (h.typeHeating)
        os << std::setw(6) << "+";
    else
        os << std::setw(6) << "-";
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
              << " | " << std::setw(6) << "Отопл."
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
    is.ignore();
    is.getline(h.wallMaterial, MAX_STR);
    return is;
}

bool House::writeToFile(const char *filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла для записи\n";
        return false;
    }
    file << "house" << " ";
    PrivateSector::writeToFile(file);
    file << " " << this->numHouse << " " << this->countRoom << " " << this->floorCount << " " << this->waterSupply << " " << this->typeHeating << " " << this->wallMaterial << std::endl;
    return true;
}

LinkedList<House> House::readFromFile(const char *filename)
{
    LinkedList<House> house;
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Ошибка открытия файла для чтения\n";
        return house;
    }
    char type[MAX_STR];
    House temp;
    while (file >> type)
    {
        if (strcmp(type, "house") == 0)
        {
            PrivateSector &pr = temp;
            pr = PrivateSector::readFromFile(file);
            file >> temp.numHouse >> temp.countRoom >> temp.floorCount >> temp.waterSupply >> temp.typeHeating >> temp.wallMaterial;
            house.addToEnd(temp);
        }
        else
        {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return house;
}